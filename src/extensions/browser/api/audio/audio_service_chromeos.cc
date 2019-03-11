// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "extensions/browser/api/audio/audio_service.h"

#include <stddef.h>
#include <stdint.h>

#include "base/callback.h"
#include "base/macros.h"
#include "base/memory/weak_ptr.h"
#include "base/strings/string_number_conversions.h"
#include "chromeos/audio/audio_device.h"
#include "chromeos/audio/cras_audio_handler.h"
#include "content/public/browser/browser_thread.h"

using content::BrowserThread;

namespace extensions {

using api::audio::OutputDeviceInfo;
using api::audio::InputDeviceInfo;
using api::audio::AudioDeviceInfo;

class AudioServiceImpl : public AudioService,
                         public chromeos::CrasAudioHandler::AudioObserver {
 public:
  AudioServiceImpl();
  ~AudioServiceImpl() override;

  // Called by listeners to this service to add/remove themselves as observers.
  void AddObserver(AudioService::Observer* observer) override;
  void RemoveObserver(AudioService::Observer* observer) override;

  // Start to query audio device information.
  bool GetInfo(OutputInfo* output_info_out, InputInfo* input_info_out) override;
  void SetActiveDevices(const DeviceIdList& device_list) override;
  bool SetActiveDeviceLists(
      const std::unique_ptr<DeviceIdList>& input_devices,
      const std::unique_ptr<DeviceIdList>& output_devives) override;
  bool SetDeviceSoundLevel(const std::string& device_id,
                           int volume,
                           int gain) override;
  bool SetMuteForDevice(const std::string& device_id, bool value) override;
  bool SetMute(bool is_input, bool value) override;
  bool GetMute(bool is_input, bool* value) override;

 protected:
  // chromeos::CrasAudioHandler::AudioObserver overrides.
  void OnOutputNodeVolumeChanged(uint64_t id, int volume) override;
  void OnInputNodeGainChanged(uint64_t id, int gain) override;
  void OnOutputMuteChanged(bool mute_on, bool system_adjust) override;
  void OnInputMuteChanged(bool mute_on) override;
  void OnAudioNodesChanged() override;
  void OnActiveOutputNodeChanged() override;
  void OnActiveInputNodeChanged() override;

 private:
  void NotifyDeviceChanged();
  void NotifyLevelChanged(uint64_t id, int level);
  void NotifyMuteChanged(bool is_input, bool is_muted);
  void NotifyDevicesChanged();

  uint64_t GetIdFromStr(const std::string& id_str);
  bool GetAudioNodeIdList(const DeviceIdList& ids,
                          bool is_input,
                          chromeos::CrasAudioHandler::NodeIdList* node_ids);

  // List of observers.
  base::ObserverList<AudioService::Observer> observer_list_;

  chromeos::CrasAudioHandler* cras_audio_handler_;

  // Note: This should remain the last member so it'll be destroyed and
  // invalidate the weak pointers before any other members are destroyed.
  base::WeakPtrFactory<AudioServiceImpl> weak_ptr_factory_;

  DISALLOW_COPY_AND_ASSIGN(AudioServiceImpl);
};

AudioServiceImpl::AudioServiceImpl()
    : cras_audio_handler_(NULL),
      weak_ptr_factory_(this) {
  if (chromeos::CrasAudioHandler::IsInitialized()) {
    cras_audio_handler_ = chromeos::CrasAudioHandler::Get();
    cras_audio_handler_->AddAudioObserver(this);
  }
}

AudioServiceImpl::~AudioServiceImpl() {
  if (cras_audio_handler_ && chromeos::CrasAudioHandler::IsInitialized()) {
    cras_audio_handler_->RemoveAudioObserver(this);
  }
}

void AudioServiceImpl::AddObserver(AudioService::Observer* observer) {
  observer_list_.AddObserver(observer);
}

void AudioServiceImpl::RemoveObserver(AudioService::Observer* observer) {
  observer_list_.RemoveObserver(observer);
}

bool AudioServiceImpl::GetInfo(OutputInfo* output_info_out,
                               InputInfo* input_info_out) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);
  DCHECK(cras_audio_handler_);
  DCHECK(output_info_out);
  DCHECK(input_info_out);

  if (!cras_audio_handler_)
    return false;

  chromeos::AudioDeviceList devices;
  cras_audio_handler_->GetAudioDevices(&devices);
  for (size_t i = 0; i < devices.size(); ++i) {
    if (!devices[i].is_input) {
      OutputDeviceInfo info;
      info.id = base::Uint64ToString(devices[i].id);
      info.name = devices[i].device_name + ": " + devices[i].display_name;
      info.is_active = devices[i].active;
      info.volume =
          cras_audio_handler_->GetOutputVolumePercentForDevice(devices[i].id);
      info.is_muted =
          cras_audio_handler_->IsOutputMutedForDevice(devices[i].id);
      output_info_out->push_back(std::move(info));
    } else {
      InputDeviceInfo info;
      info.id = base::Uint64ToString(devices[i].id);
      info.name = devices[i].device_name + ": " + devices[i].display_name;
      info.is_active = devices[i].active;
      info.gain =
          cras_audio_handler_->GetInputGainPercentForDevice(devices[i].id);
      info.is_muted = cras_audio_handler_->IsInputMutedForDevice(devices[i].id);
      input_info_out->push_back(std::move(info));
    }
  }
  return true;
}

void AudioServiceImpl::SetActiveDevices(const DeviceIdList& device_list) {
  DCHECK(cras_audio_handler_);
  if (!cras_audio_handler_)
    return;

  chromeos::CrasAudioHandler::NodeIdList id_list;
  for (const auto& id : device_list) {
    const chromeos::AudioDevice* device =
        cras_audio_handler_->GetDeviceFromId(GetIdFromStr(id));
    if (device)
      id_list.push_back(device->id);
  }
  cras_audio_handler_->ChangeActiveNodes(id_list);
}

bool AudioServiceImpl::SetActiveDeviceLists(
    const std::unique_ptr<DeviceIdList>& input_ids,
    const std::unique_ptr<DeviceIdList>& output_ids) {
  DCHECK(cras_audio_handler_);
  if (!cras_audio_handler_)
    return false;

  chromeos::CrasAudioHandler::NodeIdList input_nodes;
  if (input_ids.get() && !GetAudioNodeIdList(*input_ids, true, &input_nodes))
    return false;

  chromeos::CrasAudioHandler::NodeIdList output_nodes;
  if (output_ids.get() &&
      !GetAudioNodeIdList(*output_ids, false, &output_nodes)) {
    return false;
  }

  bool success = true;
  if (output_ids.get()) {
    success = cras_audio_handler_->SetActiveOutputNodes(output_nodes);
    DCHECK(success);
  }

  if (input_ids.get()) {
    success = success && cras_audio_handler_->SetActiveInputNodes(input_nodes);
    DCHECK(success);
  }
  return success;
}

bool AudioServiceImpl::SetDeviceSoundLevel(const std::string& device_id,
                                           int volume,
                                           int gain) {
  DCHECK(cras_audio_handler_);
  if (!cras_audio_handler_)
    return false;

  const chromeos::AudioDevice* device =
      cras_audio_handler_->GetDeviceFromId(GetIdFromStr(device_id));
  if (!device)
    return false;

  if (!device->is_input && volume != -1) {
    cras_audio_handler_->SetVolumeGainPercentForDevice(device->id, volume);
    return true;
  } else if (device->is_input && gain != -1) {
    cras_audio_handler_->SetVolumeGainPercentForDevice(device->id, gain);
    return true;
  }

  return false;
}

bool AudioServiceImpl::SetMuteForDevice(const std::string& device_id,
                                        bool value) {
  DCHECK(cras_audio_handler_);
  if (!cras_audio_handler_)
    return false;

  const chromeos::AudioDevice* device =
      cras_audio_handler_->GetDeviceFromId(GetIdFromStr(device_id));
  if (!device)
    return false;

  cras_audio_handler_->SetMuteForDevice(device->id, value);
  return true;
}

bool AudioServiceImpl::SetMute(bool is_input, bool value) {
  DCHECK(cras_audio_handler_);
  if (!cras_audio_handler_)
    return false;

  if (is_input)
    cras_audio_handler_->SetInputMute(value);
  else
    cras_audio_handler_->SetOutputMute(value);
  return true;
}

bool AudioServiceImpl::GetMute(bool is_input, bool* value) {
  DCHECK(cras_audio_handler_);
  if (!cras_audio_handler_)
    return false;

  if (is_input)
    *value = cras_audio_handler_->IsInputMuted();
  else
    *value = cras_audio_handler_->IsOutputMuted();
  return true;
}

uint64_t AudioServiceImpl::GetIdFromStr(const std::string& id_str) {
  uint64_t device_id;
  if (!base::StringToUint64(id_str, &device_id))
    return 0;
  else
    return device_id;
}

bool AudioServiceImpl::GetAudioNodeIdList(
    const DeviceIdList& ids,
    bool is_input,
    chromeos::CrasAudioHandler::NodeIdList* node_ids) {
  for (const auto& device_id : ids) {
    const chromeos::AudioDevice* device =
        cras_audio_handler_->GetDeviceFromId(GetIdFromStr(device_id));
    if (!device)
      return false;
    if (device->is_input != is_input)
      return false;
    node_ids->push_back(device->id);
  }
  return true;
}

void AudioServiceImpl::OnOutputNodeVolumeChanged(uint64_t id, int volume) {
  NotifyLevelChanged(id, volume);
}

void AudioServiceImpl::OnOutputMuteChanged(bool mute_on, bool system_adjust) {
  NotifyMuteChanged(false, mute_on);
}

void AudioServiceImpl::OnInputNodeGainChanged(uint64_t id, int gain) {
  NotifyLevelChanged(id, gain);
}

void AudioServiceImpl::OnInputMuteChanged(bool mute_on) {
  NotifyMuteChanged(true, mute_on);
}

void AudioServiceImpl::OnAudioNodesChanged() {
  NotifyDevicesChanged();
}

void AudioServiceImpl::OnActiveOutputNodeChanged() {
  NotifyDeviceChanged();
}

void AudioServiceImpl::OnActiveInputNodeChanged() {
  NotifyDeviceChanged();
}

void AudioServiceImpl::NotifyDeviceChanged() {
  for (auto& observer : observer_list_)
    observer.OnDeviceChanged();
}

void AudioServiceImpl::NotifyLevelChanged(uint64_t id, int level) {
  for (auto& observer : observer_list_)
    observer.OnLevelChanged(base::Uint64ToString(id), level);

  // Notify DeviceChanged event for backward compatibility.
  // TODO(jennyz): remove this code when the old version of hotrod retires.
  NotifyDeviceChanged();
}

void AudioServiceImpl::NotifyMuteChanged(bool is_input, bool is_muted) {
  for (auto& observer : observer_list_)
    observer.OnMuteChanged(is_input, is_muted);

  // Notify DeviceChanged event for backward compatibility.
  // TODO(jennyz): remove this code when the old version of hotrod retires.
  NotifyDeviceChanged();
}

void AudioServiceImpl::NotifyDevicesChanged() {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);
  DCHECK(cras_audio_handler_);

  DeviceInfoList devices_info_list;
  chromeos::AudioDeviceList devices;
  cras_audio_handler_->GetAudioDevices(&devices);
  for (size_t i = 0; i < devices.size(); ++i) {
    AudioDeviceInfo info;
    info.id = base::Uint64ToString(devices[i].id);
    info.stream_type = devices[i].is_input
                           ? extensions::api::audio::STREAM_TYPE_INPUT
                           : extensions::api::audio::STREAM_TYPE_OUTPUT;
    info.is_input = devices[i].is_input;
    info.device_type = chromeos::AudioDevice::GetTypeString(devices[i].type);
    info.display_name = devices[i].display_name;
    info.device_name = devices[i].device_name;
    info.is_active = devices[i].active;
    info.is_muted =
        devices[i].is_input
            ? cras_audio_handler_->IsInputMutedForDevice(devices[i].id)
            : cras_audio_handler_->IsOutputMutedForDevice(devices[i].id);
    info.level =
        devices[i].is_input
            ? cras_audio_handler_->GetOutputVolumePercentForDevice(
                  devices[i].id)
            : cras_audio_handler_->GetInputGainPercentForDevice(devices[i].id);
    info.stable_device_id.reset(
        new std::string(base::Uint64ToString(devices[i].stable_device_id)));

    devices_info_list.push_back(std::move(info));
  }

  for (auto& observer : observer_list_)
    observer.OnDevicesChanged(devices_info_list);

  // Notify DeviceChanged event for backward compatibility.
  // TODO(jennyz): remove this code when the old version of hotrod retires.
  NotifyDeviceChanged();
}

AudioService* AudioService::CreateInstance() {
  return new AudioServiceImpl;
}

}  // namespace extensions