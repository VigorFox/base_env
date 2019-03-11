// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_SHARED_H_
#define NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "net/interfaces/host_resolver_service.mojom-shared-internal.h"


namespace net {
namespace interfaces {
class HostResolverRequestInfoDataView;

class IPEndPointDataView;

class AddressListDataView;



}  // namespace interfaces
}  // namespace net

namespace mojo {
namespace internal {

template <>
struct MojomTypeTraits<::net::interfaces::HostResolverRequestInfoDataView> {
  using Data = ::net::interfaces::internal::HostResolverRequestInfo_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
};

template <>
struct MojomTypeTraits<::net::interfaces::IPEndPointDataView> {
  using Data = ::net::interfaces::internal::IPEndPoint_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
};

template <>
struct MojomTypeTraits<::net::interfaces::AddressListDataView> {
  using Data = ::net::interfaces::internal::AddressList_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
};

}  // namespace internal
}  // namespace mojo


namespace net {
namespace interfaces {

enum class AddressFamily : int32_t {
  UNSPECIFIED,
  IPV4,
  IPV6,
};

inline std::ostream& operator<<(std::ostream& os, AddressFamily value) {
  switch(value) {
    case AddressFamily::UNSPECIFIED:
      return os << "AddressFamily::UNSPECIFIED";
    case AddressFamily::IPV4:
      return os << "AddressFamily::IPV4";
    case AddressFamily::IPV6:
      return os << "AddressFamily::IPV6";
    default:
      return os << "Unknown AddressFamily value: " << static_cast<int32_t>(value);
  }
}
inline bool IsKnownEnumValue(AddressFamily value) {
  return internal::AddressFamily_Data::IsKnownValue(
      static_cast<int32_t>(value));
}
// Interface base classes. They are used for type safety check.
class HostResolverRequestClientInterfaceBase {};

using HostResolverRequestClientPtrDataView =
    mojo::InterfacePtrDataView<HostResolverRequestClientInterfaceBase>;
using HostResolverRequestClientRequestDataView =
    mojo::InterfaceRequestDataView<HostResolverRequestClientInterfaceBase>;
using HostResolverRequestClientAssociatedPtrInfoDataView =
    mojo::AssociatedInterfacePtrInfoDataView<HostResolverRequestClientInterfaceBase>;
using HostResolverRequestClientAssociatedRequestDataView =
    mojo::AssociatedInterfaceRequestDataView<HostResolverRequestClientInterfaceBase>;
class HostResolverRequestInfoDataView {
 public:
  HostResolverRequestInfoDataView() {}

  HostResolverRequestInfoDataView(
      internal::HostResolverRequestInfo_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetHostDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadHost(UserType* output) {
    auto* pointer = data_->host.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  uint16_t port() const {
    return data_->port;
  }
  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadAddressFamily(UserType* output) const {
    auto data_value = data_->address_family;
    return mojo::internal::Deserialize<::net::interfaces::AddressFamily>(
        data_value, output);
  }

  AddressFamily address_family() const {
    return static_cast<AddressFamily>(data_->address_family);
  }
  bool is_my_ip_address() const {
    return data_->is_my_ip_address;
  }
 private:
  internal::HostResolverRequestInfo_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class IPEndPointDataView {
 public:
  IPEndPointDataView() {}

  IPEndPointDataView(
      internal::IPEndPoint_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetAddressDataView(
      mojo::ArrayDataView<uint8_t>* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadAddress(UserType* output) {
    auto* pointer = data_->address.Get();
    return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
        pointer, output, context_);
  }
  uint16_t port() const {
    return data_->port;
  }
 private:
  internal::IPEndPoint_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class AddressListDataView {
 public:
  AddressListDataView() {}

  AddressListDataView(
      internal::AddressList_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetAddressesDataView(
      mojo::ArrayDataView<IPEndPointDataView>* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadAddresses(UserType* output) {
    auto* pointer = data_->addresses.Get();
    return mojo::internal::Deserialize<mojo::ArrayDataView<::net::interfaces::IPEndPointDataView>>(
        pointer, output, context_);
  }
 private:
  internal::AddressList_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class HostResolverRequestClient_ReportResult_ParamsDataView {
 public:
  HostResolverRequestClient_ReportResult_ParamsDataView() {}

  HostResolverRequestClient_ReportResult_ParamsDataView(
      internal::HostResolverRequestClient_ReportResult_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  int32_t error() const {
    return data_->error;
  }
  inline void GetResultDataView(
      AddressListDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadResult(UserType* output) {
    auto* pointer = data_->result.Get();
    return mojo::internal::Deserialize<::net::interfaces::AddressListDataView>(
        pointer, output, context_);
  }
 private:
  internal::HostResolverRequestClient_ReportResult_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};



}  // namespace interfaces
}  // namespace net

namespace std {

template <>
struct hash<::net::interfaces::AddressFamily>
    : public mojo::internal::EnumHashImpl<::net::interfaces::AddressFamily> {};

}  // namespace std

namespace mojo {


template <>
struct EnumTraits<::net::interfaces::AddressFamily, ::net::interfaces::AddressFamily> {
  static ::net::interfaces::AddressFamily ToMojom(::net::interfaces::AddressFamily input) { return input; }
  static bool FromMojom(::net::interfaces::AddressFamily input, ::net::interfaces::AddressFamily* output) {
    *output = input;
    return true;
  }
};

namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::net::interfaces::AddressFamily, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = EnumTraits<::net::interfaces::AddressFamily, UserType>;

  static void Serialize(UserType input, int32_t* output) {
    *output = static_cast<int32_t>(Traits::ToMojom(input));
  }

  static bool Deserialize(int32_t input, UserType* output) {
    return Traits::FromMojom(static_cast<::net::interfaces::AddressFamily>(input), output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::net::interfaces::HostResolverRequestInfoDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::net::interfaces::HostResolverRequestInfoDataView, UserType>;

  static size_t PrepareToSerialize(MaybeConstUserType& input,
                                   SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return 0;

    void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
    ALLOW_UNUSED_LOCAL(custom_context);

    size_t size = sizeof(::net::interfaces::internal::HostResolverRequestInfo_Data);
    decltype(CallWithContext(Traits::host, input, custom_context)) in_host = CallWithContext(Traits::host, input, custom_context);
    size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
        in_host, context);
    return size;
  }

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::net::interfaces::internal::HostResolverRequestInfo_Data** output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input)) {
      *output = nullptr;
      return;
    }

    void* custom_context = CustomContextHelper<Traits>::GetNext(context);

    auto result =
        ::net::interfaces::internal::HostResolverRequestInfo_Data::New(buffer);
    ALLOW_UNUSED_LOCAL(result);
    decltype(CallWithContext(Traits::host, input, custom_context)) in_host = CallWithContext(Traits::host, input, custom_context);
    typename decltype(result->host)::BaseType* host_ptr;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_host, buffer, &host_ptr, context);
    result->host.Set(host_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        result->host.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null host in HostResolverRequestInfo struct");
    result->port = CallWithContext(Traits::port, input, custom_context);
    mojo::internal::Serialize<::net::interfaces::AddressFamily>(
        CallWithContext(Traits::address_family, input, custom_context), &result->address_family);
    result->is_my_ip_address = CallWithContext(Traits::is_my_ip_address, input, custom_context);
    *output = result;

    CustomContextHelper<Traits>::TearDown(input, custom_context);
  }

  static bool Deserialize(::net::interfaces::internal::HostResolverRequestInfo_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::net::interfaces::HostResolverRequestInfoDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::net::interfaces::IPEndPointDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::net::interfaces::IPEndPointDataView, UserType>;

  static size_t PrepareToSerialize(MaybeConstUserType& input,
                                   SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return 0;

    void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
    ALLOW_UNUSED_LOCAL(custom_context);

    size_t size = sizeof(::net::interfaces::internal::IPEndPoint_Data);
    decltype(CallWithContext(Traits::address, input, custom_context)) in_address = CallWithContext(Traits::address, input, custom_context);
    size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
        in_address, context);
    return size;
  }

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::net::interfaces::internal::IPEndPoint_Data** output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input)) {
      *output = nullptr;
      return;
    }

    void* custom_context = CustomContextHelper<Traits>::GetNext(context);

    auto result =
        ::net::interfaces::internal::IPEndPoint_Data::New(buffer);
    ALLOW_UNUSED_LOCAL(result);
    decltype(CallWithContext(Traits::address, input, custom_context)) in_address = CallWithContext(Traits::address, input, custom_context);
    typename decltype(result->address)::BaseType* address_ptr;
    const mojo::internal::ContainerValidateParams address_validate_params(
        0, false, nullptr);
    mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
        in_address, buffer, &address_ptr, &address_validate_params,
        context);
    result->address.Set(address_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        result->address.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null address in IPEndPoint struct");
    result->port = CallWithContext(Traits::port, input, custom_context);
    *output = result;

    CustomContextHelper<Traits>::TearDown(input, custom_context);
  }

  static bool Deserialize(::net::interfaces::internal::IPEndPoint_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::net::interfaces::IPEndPointDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::net::interfaces::AddressListDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::net::interfaces::AddressListDataView, UserType>;

  static size_t PrepareToSerialize(MaybeConstUserType& input,
                                   SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return 0;

    void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
    ALLOW_UNUSED_LOCAL(custom_context);

    size_t size = sizeof(::net::interfaces::internal::AddressList_Data);
    decltype(CallWithContext(Traits::addresses, input, custom_context)) in_addresses = CallWithContext(Traits::addresses, input, custom_context);
    size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::net::interfaces::IPEndPointDataView>>(
        in_addresses, context);
    return size;
  }

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::net::interfaces::internal::AddressList_Data** output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input)) {
      *output = nullptr;
      return;
    }

    void* custom_context = CustomContextHelper<Traits>::GetNext(context);

    auto result =
        ::net::interfaces::internal::AddressList_Data::New(buffer);
    ALLOW_UNUSED_LOCAL(result);
    decltype(CallWithContext(Traits::addresses, input, custom_context)) in_addresses = CallWithContext(Traits::addresses, input, custom_context);
    typename decltype(result->addresses)::BaseType* addresses_ptr;
    const mojo::internal::ContainerValidateParams addresses_validate_params(
        0, false, nullptr);
    mojo::internal::Serialize<mojo::ArrayDataView<::net::interfaces::IPEndPointDataView>>(
        in_addresses, buffer, &addresses_ptr, &addresses_validate_params,
        context);
    result->addresses.Set(addresses_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        result->addresses.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null addresses in AddressList struct");
    *output = result;

    CustomContextHelper<Traits>::TearDown(input, custom_context);
  }

  static bool Deserialize(::net::interfaces::internal::AddressList_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::net::interfaces::AddressListDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal

}  // namespace mojo


namespace net {
namespace interfaces {

inline void HostResolverRequestInfoDataView::GetHostDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->host.Get();
  *output = mojo::StringDataView(pointer, context_);
}


inline void IPEndPointDataView::GetAddressDataView(
    mojo::ArrayDataView<uint8_t>* output) {
  auto pointer = data_->address.Get();
  *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
}


inline void AddressListDataView::GetAddressesDataView(
    mojo::ArrayDataView<IPEndPointDataView>* output) {
  auto pointer = data_->addresses.Get();
  *output = mojo::ArrayDataView<IPEndPointDataView>(pointer, context_);
}


inline void HostResolverRequestClient_ReportResult_ParamsDataView::GetResultDataView(
    AddressListDataView* output) {
  auto pointer = data_->result.Get();
  *output = AddressListDataView(pointer, context_);
}



}  // namespace interfaces
}  // namespace net

#endif  // NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_SHARED_H_
