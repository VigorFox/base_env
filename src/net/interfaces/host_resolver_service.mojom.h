// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_H_
#define NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "net/interfaces/host_resolver_service.mojom-shared.h"
#include <string>
#include <vector>
#include "url/gurl.h"
#include "net/proxy/proxy_info.h"
#include "net/dns/host_resolver.h"
#include "net/proxy/proxy_server.h"


namespace net {
namespace interfaces {
class HostResolverRequestClient;
using HostResolverRequestClientPtr = mojo::InterfacePtr<HostResolverRequestClient>;
using HostResolverRequestClientPtrInfo = mojo::InterfacePtrInfo<HostResolverRequestClient>;
using ThreadSafeHostResolverRequestClientPtr =
    mojo::ThreadSafeInterfacePtr<HostResolverRequestClient>;
using HostResolverRequestClientRequest = mojo::InterfaceRequest<HostResolverRequestClient>;
using HostResolverRequestClientAssociatedPtr =
    mojo::AssociatedInterfacePtr<HostResolverRequestClient>;
using ThreadSafeHostResolverRequestClientAssociatedPtr =
    mojo::ThreadSafeAssociatedInterfacePtr<HostResolverRequestClient>;
using HostResolverRequestClientAssociatedPtrInfo =
    mojo::AssociatedInterfacePtrInfo<HostResolverRequestClient>;
using HostResolverRequestClientAssociatedRequest =
    mojo::AssociatedInterfaceRequest<HostResolverRequestClient>;

class HostResolverRequestInfo;
using HostResolverRequestInfoPtr = mojo::InlinedStructPtr<HostResolverRequestInfo>;

class IPEndPoint;
using IPEndPointPtr = mojo::StructPtr<IPEndPoint>;

class AddressList;
using AddressListPtr = mojo::StructPtr<AddressList>;


class HostResolverRequestClientProxy;

template <typename ImplRefTraits>
class HostResolverRequestClientStub;

class HostResolverRequestClientRequestValidator;

class  HostResolverRequestClient
    : public HostResolverRequestClientInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasSyncMethods_ = false;

  using Proxy_ = HostResolverRequestClientProxy;

  template <typename ImplRefTraits>
  using Stub_ = HostResolverRequestClientStub<ImplRefTraits>;

  using RequestValidator_ = HostResolverRequestClientRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kReportResultMinVersion = 0,
  };
  virtual ~HostResolverRequestClient() {}

  virtual void ReportResult(int32_t error, const net::AddressList& result) = 0;
};

class  HostResolverRequestClientProxy
    : public HostResolverRequestClient {
 public:
  explicit HostResolverRequestClientProxy(mojo::MessageReceiverWithResponder* receiver);
  void ReportResult(int32_t error, const net::AddressList& result) override;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};
class  HostResolverRequestClientStubDispatch {
 public:
  static bool Accept(HostResolverRequestClient* impl, mojo::Message* message);
  static bool AcceptWithResponder(HostResolverRequestClient* impl,
                                  mojo::Message* message,
                                  mojo::MessageReceiverWithStatus* responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<HostResolverRequestClient>>
class HostResolverRequestClientStub
    : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  HostResolverRequestClientStub() {}
  ~HostResolverRequestClientStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return HostResolverRequestClientStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      mojo::MessageReceiverWithStatus* responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return HostResolverRequestClientStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, responder);
  }

 private:
  ImplPointerType sink_;
};
class  HostResolverRequestClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
 public:
  bool Accept(mojo::Message* message) override;
};


class  HostResolverRequestInfo {
 public:
  using DataView = HostResolverRequestInfoDataView;
  using Data_ = internal::HostResolverRequestInfo_Data;

  static HostResolverRequestInfoPtr New();

  template <typename U>
  static HostResolverRequestInfoPtr From(const U& u) {
    return mojo::TypeConverter<HostResolverRequestInfoPtr, U>::Convert(u);
  }

  template <typename U>
  U To() const {
    return mojo::TypeConverter<U, HostResolverRequestInfo>::Convert(*this);
  }

  HostResolverRequestInfo();
  ~HostResolverRequestInfo();

  // Clone() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Clone() or copy
  // constructor/assignment are available for members.
  template <typename StructPtrType = HostResolverRequestInfoPtr>
  HostResolverRequestInfoPtr Clone() const;

  // Equals() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Equals() or == operator
  // are available for members.
  template <typename T,
            typename std::enable_if<std::is_same<
                T, HostResolverRequestInfo>::value>::type* = nullptr>
  bool Equals(const T& other) const;

  template <typename UserType>
  static std::vector<uint8_t> Serialize(UserType* input) {
    return mojo::internal::StructSerializeImpl<
        HostResolverRequestInfo::DataView, std::vector<uint8_t>>(input);
  }

  template <typename UserType>
  static bool Deserialize(const std::vector<uint8_t>& input,
                          UserType* output) {
    return mojo::internal::StructDeserializeImpl<
        HostResolverRequestInfo::DataView, std::vector<uint8_t>>(
            input, output);
  }

  std::string host;
  uint16_t port;
  net::AddressFamily address_family;
  bool is_my_ip_address;
};








class  IPEndPoint {
 public:
  using DataView = IPEndPointDataView;
  using Data_ = internal::IPEndPoint_Data;

  static IPEndPointPtr New();

  template <typename U>
  static IPEndPointPtr From(const U& u) {
    return mojo::TypeConverter<IPEndPointPtr, U>::Convert(u);
  }

  template <typename U>
  U To() const {
    return mojo::TypeConverter<U, IPEndPoint>::Convert(*this);
  }

  IPEndPoint();
  ~IPEndPoint();

  // Clone() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Clone() or copy
  // constructor/assignment are available for members.
  template <typename StructPtrType = IPEndPointPtr>
  IPEndPointPtr Clone() const;

  // Equals() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Equals() or == operator
  // are available for members.
  template <typename T,
            typename std::enable_if<std::is_same<
                T, IPEndPoint>::value>::type* = nullptr>
  bool Equals(const T& other) const;

  template <typename UserType>
  static std::vector<uint8_t> Serialize(UserType* input) {
    return mojo::internal::StructSerializeImpl<
        IPEndPoint::DataView, std::vector<uint8_t>>(input);
  }

  template <typename UserType>
  static bool Deserialize(const std::vector<uint8_t>& input,
                          UserType* output) {
    return mojo::internal::StructDeserializeImpl<
        IPEndPoint::DataView, std::vector<uint8_t>>(
            input, output);
  }

  std::vector<uint8_t> address;
  uint16_t port;
};



class  AddressList {
 public:
  using DataView = AddressListDataView;
  using Data_ = internal::AddressList_Data;

  static AddressListPtr New();

  template <typename U>
  static AddressListPtr From(const U& u) {
    return mojo::TypeConverter<AddressListPtr, U>::Convert(u);
  }

  template <typename U>
  U To() const {
    return mojo::TypeConverter<U, AddressList>::Convert(*this);
  }

  AddressList();
  ~AddressList();

  // Clone() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Clone() or copy
  // constructor/assignment are available for members.
  template <typename StructPtrType = AddressListPtr>
  AddressListPtr Clone() const;

  // Equals() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Equals() or == operator
  // are available for members.
  template <typename T,
            typename std::enable_if<std::is_same<
                T, AddressList>::value>::type* = nullptr>
  bool Equals(const T& other) const;

  template <typename UserType>
  static std::vector<uint8_t> Serialize(UserType* input) {
    return mojo::internal::StructSerializeImpl<
        AddressList::DataView, std::vector<uint8_t>>(input);
  }

  template <typename UserType>
  static bool Deserialize(const std::vector<uint8_t>& input,
                          UserType* output) {
    return mojo::internal::StructDeserializeImpl<
        AddressList::DataView, std::vector<uint8_t>>(
            input, output);
  }

  std::vector<IPEndPointPtr> addresses;
 private:
  DISALLOW_COPY_AND_ASSIGN(AddressList);
};


template <typename StructPtrType>
HostResolverRequestInfoPtr HostResolverRequestInfo::Clone() const {
  // Use StructPtrType to prevent the compiler from trying to compile this
  // without being asked.
  StructPtrType rv(New());
  rv->host = mojo::internal::Clone(host);
  rv->port = mojo::internal::Clone(port);
  rv->address_family = mojo::internal::Clone(address_family);
  rv->is_my_ip_address = mojo::internal::Clone(is_my_ip_address);
  return rv;
}

template <typename T,
          typename std::enable_if<std::is_same<
              T, HostResolverRequestInfo>::value>::type*>
bool HostResolverRequestInfo::Equals(const T& other) const {
  if (!mojo::internal::Equals(this->host, other.host))
    return false;
  if (!mojo::internal::Equals(this->port, other.port))
    return false;
  if (!mojo::internal::Equals(this->address_family, other.address_family))
    return false;
  if (!mojo::internal::Equals(this->is_my_ip_address, other.is_my_ip_address))
    return false;
  return true;
}
template <typename StructPtrType>
IPEndPointPtr IPEndPoint::Clone() const {
  // Use StructPtrType to prevent the compiler from trying to compile this
  // without being asked.
  StructPtrType rv(New());
  rv->address = mojo::internal::Clone(address);
  rv->port = mojo::internal::Clone(port);
  return rv;
}

template <typename T,
          typename std::enable_if<std::is_same<
              T, IPEndPoint>::value>::type*>
bool IPEndPoint::Equals(const T& other) const {
  if (!mojo::internal::Equals(this->address, other.address))
    return false;
  if (!mojo::internal::Equals(this->port, other.port))
    return false;
  return true;
}
template <typename StructPtrType>
AddressListPtr AddressList::Clone() const {
  // Use StructPtrType to prevent the compiler from trying to compile this
  // without being asked.
  StructPtrType rv(New());
  rv->addresses = mojo::internal::Clone(addresses);
  return rv;
}

template <typename T,
          typename std::enable_if<std::is_same<
              T, AddressList>::value>::type*>
bool AddressList::Equals(const T& other) const {
  if (!mojo::internal::Equals(this->addresses, other.addresses))
    return false;
  return true;
}


}  // namespace interfaces
}  // namespace net

namespace mojo {


template <>
struct  StructTraits<::net::interfaces::HostResolverRequestInfo::DataView,
                                         ::net::interfaces::HostResolverRequestInfoPtr> {
  static bool IsNull(const ::net::interfaces::HostResolverRequestInfoPtr& input) { return !input; }
  static void SetToNull(::net::interfaces::HostResolverRequestInfoPtr* output) { output->reset(); }

  static const decltype(::net::interfaces::HostResolverRequestInfo::host)& host(
      const ::net::interfaces::HostResolverRequestInfoPtr& input) {
    return input->host;
  }

  static decltype(::net::interfaces::HostResolverRequestInfo::port) port(
      const ::net::interfaces::HostResolverRequestInfoPtr& input) {
    return input->port;
  }

  static decltype(::net::interfaces::HostResolverRequestInfo::address_family) address_family(
      const ::net::interfaces::HostResolverRequestInfoPtr& input) {
    return input->address_family;
  }

  static decltype(::net::interfaces::HostResolverRequestInfo::is_my_ip_address) is_my_ip_address(
      const ::net::interfaces::HostResolverRequestInfoPtr& input) {
    return input->is_my_ip_address;
  }

  static bool Read(::net::interfaces::HostResolverRequestInfo::DataView input, ::net::interfaces::HostResolverRequestInfoPtr* output);
};


template <>
struct  StructTraits<::net::interfaces::IPEndPoint::DataView,
                                         ::net::interfaces::IPEndPointPtr> {
  static bool IsNull(const ::net::interfaces::IPEndPointPtr& input) { return !input; }
  static void SetToNull(::net::interfaces::IPEndPointPtr* output) { output->reset(); }

  static const decltype(::net::interfaces::IPEndPoint::address)& address(
      const ::net::interfaces::IPEndPointPtr& input) {
    return input->address;
  }

  static decltype(::net::interfaces::IPEndPoint::port) port(
      const ::net::interfaces::IPEndPointPtr& input) {
    return input->port;
  }

  static bool Read(::net::interfaces::IPEndPoint::DataView input, ::net::interfaces::IPEndPointPtr* output);
};


template <>
struct  StructTraits<::net::interfaces::AddressList::DataView,
                                         ::net::interfaces::AddressListPtr> {
  static bool IsNull(const ::net::interfaces::AddressListPtr& input) { return !input; }
  static void SetToNull(::net::interfaces::AddressListPtr* output) { output->reset(); }

  static const decltype(::net::interfaces::AddressList::addresses)& addresses(
      const ::net::interfaces::AddressListPtr& input) {
    return input->addresses;
  }

  static bool Read(::net::interfaces::AddressList::DataView input, ::net::interfaces::AddressListPtr* output);
};

}  // namespace mojo

#endif  // NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_H_