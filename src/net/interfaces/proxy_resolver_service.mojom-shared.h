// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_SHARED_H_
#define NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_SHARED_H_

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
#include "net/interfaces/proxy_resolver_service.mojom-shared-internal.h"
#include "net/interfaces/host_resolver_service.mojom-shared.h"
#include "url/mojo/url.mojom-shared.h"


namespace net {
namespace interfaces {
class ProxyServerDataView;

class ProxyInfoDataView;



}  // namespace interfaces
}  // namespace net

namespace mojo {
namespace internal {

template <>
struct MojomTypeTraits<::net::interfaces::ProxyServerDataView> {
  using Data = ::net::interfaces::internal::ProxyServer_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
};

template <>
struct MojomTypeTraits<::net::interfaces::ProxyInfoDataView> {
  using Data = ::net::interfaces::internal::ProxyInfo_Data;
  using DataAsArrayElement = Pointer<Data>;
  static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
};

}  // namespace internal
}  // namespace mojo


namespace net {
namespace interfaces {

enum class ProxyScheme : int32_t {
  INVALID,
  DIRECT,
  HTTP,
  SOCKS4,
  SOCKS5,
  HTTPS,
  QUIC,
};

inline std::ostream& operator<<(std::ostream& os, ProxyScheme value) {
  switch(value) {
    case ProxyScheme::INVALID:
      return os << "ProxyScheme::INVALID";
    case ProxyScheme::DIRECT:
      return os << "ProxyScheme::DIRECT";
    case ProxyScheme::HTTP:
      return os << "ProxyScheme::HTTP";
    case ProxyScheme::SOCKS4:
      return os << "ProxyScheme::SOCKS4";
    case ProxyScheme::SOCKS5:
      return os << "ProxyScheme::SOCKS5";
    case ProxyScheme::HTTPS:
      return os << "ProxyScheme::HTTPS";
    case ProxyScheme::QUIC:
      return os << "ProxyScheme::QUIC";
    default:
      return os << "Unknown ProxyScheme value: " << static_cast<int32_t>(value);
  }
}
inline bool IsKnownEnumValue(ProxyScheme value) {
  return internal::ProxyScheme_Data::IsKnownValue(
      static_cast<int32_t>(value));
}
// Interface base classes. They are used for type safety check.
class ProxyResolverInterfaceBase {};

using ProxyResolverPtrDataView =
    mojo::InterfacePtrDataView<ProxyResolverInterfaceBase>;
using ProxyResolverRequestDataView =
    mojo::InterfaceRequestDataView<ProxyResolverInterfaceBase>;
using ProxyResolverAssociatedPtrInfoDataView =
    mojo::AssociatedInterfacePtrInfoDataView<ProxyResolverInterfaceBase>;
using ProxyResolverAssociatedRequestDataView =
    mojo::AssociatedInterfaceRequestDataView<ProxyResolverInterfaceBase>;
class ProxyResolverRequestClientInterfaceBase {};

using ProxyResolverRequestClientPtrDataView =
    mojo::InterfacePtrDataView<ProxyResolverRequestClientInterfaceBase>;
using ProxyResolverRequestClientRequestDataView =
    mojo::InterfaceRequestDataView<ProxyResolverRequestClientInterfaceBase>;
using ProxyResolverRequestClientAssociatedPtrInfoDataView =
    mojo::AssociatedInterfacePtrInfoDataView<ProxyResolverRequestClientInterfaceBase>;
using ProxyResolverRequestClientAssociatedRequestDataView =
    mojo::AssociatedInterfaceRequestDataView<ProxyResolverRequestClientInterfaceBase>;
class ProxyResolverFactoryInterfaceBase {};

using ProxyResolverFactoryPtrDataView =
    mojo::InterfacePtrDataView<ProxyResolverFactoryInterfaceBase>;
using ProxyResolverFactoryRequestDataView =
    mojo::InterfaceRequestDataView<ProxyResolverFactoryInterfaceBase>;
using ProxyResolverFactoryAssociatedPtrInfoDataView =
    mojo::AssociatedInterfacePtrInfoDataView<ProxyResolverFactoryInterfaceBase>;
using ProxyResolverFactoryAssociatedRequestDataView =
    mojo::AssociatedInterfaceRequestDataView<ProxyResolverFactoryInterfaceBase>;
class ProxyResolverFactoryRequestClientInterfaceBase {};

using ProxyResolverFactoryRequestClientPtrDataView =
    mojo::InterfacePtrDataView<ProxyResolverFactoryRequestClientInterfaceBase>;
using ProxyResolverFactoryRequestClientRequestDataView =
    mojo::InterfaceRequestDataView<ProxyResolverFactoryRequestClientInterfaceBase>;
using ProxyResolverFactoryRequestClientAssociatedPtrInfoDataView =
    mojo::AssociatedInterfacePtrInfoDataView<ProxyResolverFactoryRequestClientInterfaceBase>;
using ProxyResolverFactoryRequestClientAssociatedRequestDataView =
    mojo::AssociatedInterfaceRequestDataView<ProxyResolverFactoryRequestClientInterfaceBase>;
class ProxyServerDataView {
 public:
  ProxyServerDataView() {}

  ProxyServerDataView(
      internal::ProxyServer_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadScheme(UserType* output) const {
    auto data_value = data_->scheme;
    return mojo::internal::Deserialize<::net::interfaces::ProxyScheme>(
        data_value, output);
  }

  ProxyScheme scheme() const {
    return static_cast<ProxyScheme>(data_->scheme);
  }
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
 private:
  internal::ProxyServer_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyInfoDataView {
 public:
  ProxyInfoDataView() {}

  ProxyInfoDataView(
      internal::ProxyInfo_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetProxyServersDataView(
      mojo::ArrayDataView<ProxyServerDataView>* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadProxyServers(UserType* output) {
    auto* pointer = data_->proxy_servers.Get();
    return mojo::internal::Deserialize<mojo::ArrayDataView<::net::interfaces::ProxyServerDataView>>(
        pointer, output, context_);
  }
 private:
  internal::ProxyInfo_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolver_GetProxyForUrl_ParamsDataView {
 public:
  ProxyResolver_GetProxyForUrl_ParamsDataView() {}

  ProxyResolver_GetProxyForUrl_ParamsDataView(
      internal::ProxyResolver_GetProxyForUrl_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetUrlDataView(
      ::url::mojom::UrlDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadUrl(UserType* output) {
    auto* pointer = data_->url.Get();
    return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
        pointer, output, context_);
  }
  template <typename UserType>
  UserType TakeClient() {
    UserType result;
    bool ret =
        mojo::internal::Deserialize<::net::interfaces::ProxyResolverRequestClientPtrDataView>(
            &data_->client, &result, context_);
    DCHECK(ret);
    return result;
  }
 private:
  internal::ProxyResolver_GetProxyForUrl_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverRequestClient_ReportResult_ParamsDataView {
 public:
  ProxyResolverRequestClient_ReportResult_ParamsDataView() {}

  ProxyResolverRequestClient_ReportResult_ParamsDataView(
      internal::ProxyResolverRequestClient_ReportResult_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  int32_t error() const {
    return data_->error;
  }
  inline void GetProxyInfoDataView(
      ProxyInfoDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadProxyInfo(UserType* output) {
    auto* pointer = data_->proxy_info.Get();
    return mojo::internal::Deserialize<::net::interfaces::ProxyInfoDataView>(
        pointer, output, context_);
  }
 private:
  internal::ProxyResolverRequestClient_ReportResult_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverRequestClient_Alert_ParamsDataView {
 public:
  ProxyResolverRequestClient_Alert_ParamsDataView() {}

  ProxyResolverRequestClient_Alert_ParamsDataView(
      internal::ProxyResolverRequestClient_Alert_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetErrorDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadError(UserType* output) {
    auto* pointer = data_->error.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
 private:
  internal::ProxyResolverRequestClient_Alert_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverRequestClient_OnError_ParamsDataView {
 public:
  ProxyResolverRequestClient_OnError_ParamsDataView() {}

  ProxyResolverRequestClient_OnError_ParamsDataView(
      internal::ProxyResolverRequestClient_OnError_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  int32_t line_number() const {
    return data_->line_number;
  }
  inline void GetErrorDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadError(UserType* output) {
    auto* pointer = data_->error.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
 private:
  internal::ProxyResolverRequestClient_OnError_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverRequestClient_ResolveDns_ParamsDataView {
 public:
  ProxyResolverRequestClient_ResolveDns_ParamsDataView() {}

  ProxyResolverRequestClient_ResolveDns_ParamsDataView(
      internal::ProxyResolverRequestClient_ResolveDns_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetRequestInfoDataView(
      ::net::interfaces::HostResolverRequestInfoDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadRequestInfo(UserType* output) {
    auto* pointer = data_->request_info.Get();
    return mojo::internal::Deserialize<::net::interfaces::HostResolverRequestInfoDataView>(
        pointer, output, context_);
  }
  template <typename UserType>
  UserType TakeClient() {
    UserType result;
    bool ret =
        mojo::internal::Deserialize<::net::interfaces::HostResolverRequestClientPtrDataView>(
            &data_->client, &result, context_);
    DCHECK(ret);
    return result;
  }
 private:
  internal::ProxyResolverRequestClient_ResolveDns_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverFactory_CreateResolver_ParamsDataView {
 public:
  ProxyResolverFactory_CreateResolver_ParamsDataView() {}

  ProxyResolverFactory_CreateResolver_ParamsDataView(
      internal::ProxyResolverFactory_CreateResolver_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetPacScriptDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadPacScript(UserType* output) {
    auto* pointer = data_->pac_script.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
  template <typename UserType>
  UserType TakeResolver() {
    UserType result;
    bool ret =
        mojo::internal::Deserialize<::net::interfaces::ProxyResolverRequestDataView>(
            &data_->resolver, &result, context_);
    DCHECK(ret);
    return result;
  }
  template <typename UserType>
  UserType TakeClient() {
    UserType result;
    bool ret =
        mojo::internal::Deserialize<::net::interfaces::ProxyResolverFactoryRequestClientPtrDataView>(
            &data_->client, &result, context_);
    DCHECK(ret);
    return result;
  }
 private:
  internal::ProxyResolverFactory_CreateResolver_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverFactoryRequestClient_ReportResult_ParamsDataView {
 public:
  ProxyResolverFactoryRequestClient_ReportResult_ParamsDataView() {}

  ProxyResolverFactoryRequestClient_ReportResult_ParamsDataView(
      internal::ProxyResolverFactoryRequestClient_ReportResult_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data) {}

  bool is_null() const { return !data_; }
  int32_t error() const {
    return data_->error;
  }
 private:
  internal::ProxyResolverFactoryRequestClient_ReportResult_Params_Data* data_ = nullptr;
};

class ProxyResolverFactoryRequestClient_Alert_ParamsDataView {
 public:
  ProxyResolverFactoryRequestClient_Alert_ParamsDataView() {}

  ProxyResolverFactoryRequestClient_Alert_ParamsDataView(
      internal::ProxyResolverFactoryRequestClient_Alert_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetErrorDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadError(UserType* output) {
    auto* pointer = data_->error.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
 private:
  internal::ProxyResolverFactoryRequestClient_Alert_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverFactoryRequestClient_OnError_ParamsDataView {
 public:
  ProxyResolverFactoryRequestClient_OnError_ParamsDataView() {}

  ProxyResolverFactoryRequestClient_OnError_ParamsDataView(
      internal::ProxyResolverFactoryRequestClient_OnError_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  int32_t line_number() const {
    return data_->line_number;
  }
  inline void GetErrorDataView(
      mojo::StringDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadError(UserType* output) {
    auto* pointer = data_->error.Get();
    return mojo::internal::Deserialize<mojo::StringDataView>(
        pointer, output, context_);
  }
 private:
  internal::ProxyResolverFactoryRequestClient_OnError_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};

class ProxyResolverFactoryRequestClient_ResolveDns_ParamsDataView {
 public:
  ProxyResolverFactoryRequestClient_ResolveDns_ParamsDataView() {}

  ProxyResolverFactoryRequestClient_ResolveDns_ParamsDataView(
      internal::ProxyResolverFactoryRequestClient_ResolveDns_Params_Data* data,
      mojo::internal::SerializationContext* context)
      : data_(data), context_(context) {}

  bool is_null() const { return !data_; }
  inline void GetRequestInfoDataView(
      ::net::interfaces::HostResolverRequestInfoDataView* output);

  template <typename UserType>
  WARN_UNUSED_RESULT bool ReadRequestInfo(UserType* output) {
    auto* pointer = data_->request_info.Get();
    return mojo::internal::Deserialize<::net::interfaces::HostResolverRequestInfoDataView>(
        pointer, output, context_);
  }
  template <typename UserType>
  UserType TakeClient() {
    UserType result;
    bool ret =
        mojo::internal::Deserialize<::net::interfaces::HostResolverRequestClientPtrDataView>(
            &data_->client, &result, context_);
    DCHECK(ret);
    return result;
  }
 private:
  internal::ProxyResolverFactoryRequestClient_ResolveDns_Params_Data* data_ = nullptr;
  mojo::internal::SerializationContext* context_ = nullptr;
};



}  // namespace interfaces
}  // namespace net

namespace std {

template <>
struct hash<::net::interfaces::ProxyScheme>
    : public mojo::internal::EnumHashImpl<::net::interfaces::ProxyScheme> {};

}  // namespace std

namespace mojo {


template <>
struct EnumTraits<::net::interfaces::ProxyScheme, ::net::interfaces::ProxyScheme> {
  static ::net::interfaces::ProxyScheme ToMojom(::net::interfaces::ProxyScheme input) { return input; }
  static bool FromMojom(::net::interfaces::ProxyScheme input, ::net::interfaces::ProxyScheme* output) {
    *output = input;
    return true;
  }
};

namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::net::interfaces::ProxyScheme, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = EnumTraits<::net::interfaces::ProxyScheme, UserType>;

  static void Serialize(UserType input, int32_t* output) {
    *output = static_cast<int32_t>(Traits::ToMojom(input));
  }

  static bool Deserialize(int32_t input, UserType* output) {
    return Traits::FromMojom(static_cast<::net::interfaces::ProxyScheme>(input), output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::net::interfaces::ProxyServerDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::net::interfaces::ProxyServerDataView, UserType>;

  static size_t PrepareToSerialize(MaybeConstUserType& input,
                                   SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return 0;

    void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
    ALLOW_UNUSED_LOCAL(custom_context);

    size_t size = sizeof(::net::interfaces::internal::ProxyServer_Data);
    decltype(CallWithContext(Traits::host, input, custom_context)) in_host = CallWithContext(Traits::host, input, custom_context);
    size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
        in_host, context);
    return size;
  }

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::net::interfaces::internal::ProxyServer_Data** output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input)) {
      *output = nullptr;
      return;
    }

    void* custom_context = CustomContextHelper<Traits>::GetNext(context);

    auto result =
        ::net::interfaces::internal::ProxyServer_Data::New(buffer);
    ALLOW_UNUSED_LOCAL(result);
    mojo::internal::Serialize<::net::interfaces::ProxyScheme>(
        CallWithContext(Traits::scheme, input, custom_context), &result->scheme);
    decltype(CallWithContext(Traits::host, input, custom_context)) in_host = CallWithContext(Traits::host, input, custom_context);
    typename decltype(result->host)::BaseType* host_ptr;
    mojo::internal::Serialize<mojo::StringDataView>(
        in_host, buffer, &host_ptr, context);
    result->host.Set(host_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        result->host.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null host in ProxyServer struct");
    result->port = CallWithContext(Traits::port, input, custom_context);
    *output = result;

    CustomContextHelper<Traits>::TearDown(input, custom_context);
  }

  static bool Deserialize(::net::interfaces::internal::ProxyServer_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::net::interfaces::ProxyServerDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal


namespace internal {

template <typename MaybeConstUserType>
struct Serializer<::net::interfaces::ProxyInfoDataView, MaybeConstUserType> {
  using UserType = typename std::remove_const<MaybeConstUserType>::type;
  using Traits = StructTraits<::net::interfaces::ProxyInfoDataView, UserType>;

  static size_t PrepareToSerialize(MaybeConstUserType& input,
                                   SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input))
      return 0;

    void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
    ALLOW_UNUSED_LOCAL(custom_context);

    size_t size = sizeof(::net::interfaces::internal::ProxyInfo_Data);
    decltype(CallWithContext(Traits::proxy_servers, input, custom_context)) in_proxy_servers = CallWithContext(Traits::proxy_servers, input, custom_context);
    size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::net::interfaces::ProxyServerDataView>>(
        in_proxy_servers, context);
    return size;
  }

  static void Serialize(MaybeConstUserType& input,
                        Buffer* buffer,
                        ::net::interfaces::internal::ProxyInfo_Data** output,
                        SerializationContext* context) {
    if (CallIsNullIfExists<Traits>(input)) {
      *output = nullptr;
      return;
    }

    void* custom_context = CustomContextHelper<Traits>::GetNext(context);

    auto result =
        ::net::interfaces::internal::ProxyInfo_Data::New(buffer);
    ALLOW_UNUSED_LOCAL(result);
    decltype(CallWithContext(Traits::proxy_servers, input, custom_context)) in_proxy_servers = CallWithContext(Traits::proxy_servers, input, custom_context);
    typename decltype(result->proxy_servers)::BaseType* proxy_servers_ptr;
    const mojo::internal::ContainerValidateParams proxy_servers_validate_params(
        0, false, nullptr);
    mojo::internal::Serialize<mojo::ArrayDataView<::net::interfaces::ProxyServerDataView>>(
        in_proxy_servers, buffer, &proxy_servers_ptr, &proxy_servers_validate_params,
        context);
    result->proxy_servers.Set(proxy_servers_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        result->proxy_servers.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null proxy_servers in ProxyInfo struct");
    *output = result;

    CustomContextHelper<Traits>::TearDown(input, custom_context);
  }

  static bool Deserialize(::net::interfaces::internal::ProxyInfo_Data* input,
                          UserType* output,
                          SerializationContext* context) {
    if (!input)
      return CallSetToNullIfExists<Traits>(output);

    ::net::interfaces::ProxyInfoDataView data_view(input, context);
    return Traits::Read(data_view, output);
  }
};

}  // namespace internal

}  // namespace mojo


namespace net {
namespace interfaces {

inline void ProxyServerDataView::GetHostDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->host.Get();
  *output = mojo::StringDataView(pointer, context_);
}


inline void ProxyInfoDataView::GetProxyServersDataView(
    mojo::ArrayDataView<ProxyServerDataView>* output) {
  auto pointer = data_->proxy_servers.Get();
  *output = mojo::ArrayDataView<ProxyServerDataView>(pointer, context_);
}


inline void ProxyResolver_GetProxyForUrl_ParamsDataView::GetUrlDataView(
    ::url::mojom::UrlDataView* output) {
  auto pointer = data_->url.Get();
  *output = ::url::mojom::UrlDataView(pointer, context_);
}


inline void ProxyResolverRequestClient_ReportResult_ParamsDataView::GetProxyInfoDataView(
    ProxyInfoDataView* output) {
  auto pointer = data_->proxy_info.Get();
  *output = ProxyInfoDataView(pointer, context_);
}


inline void ProxyResolverRequestClient_Alert_ParamsDataView::GetErrorDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->error.Get();
  *output = mojo::StringDataView(pointer, context_);
}


inline void ProxyResolverRequestClient_OnError_ParamsDataView::GetErrorDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->error.Get();
  *output = mojo::StringDataView(pointer, context_);
}


inline void ProxyResolverRequestClient_ResolveDns_ParamsDataView::GetRequestInfoDataView(
    ::net::interfaces::HostResolverRequestInfoDataView* output) {
  auto pointer = data_->request_info.Get();
  *output = ::net::interfaces::HostResolverRequestInfoDataView(pointer, context_);
}


inline void ProxyResolverFactory_CreateResolver_ParamsDataView::GetPacScriptDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->pac_script.Get();
  *output = mojo::StringDataView(pointer, context_);
}




inline void ProxyResolverFactoryRequestClient_Alert_ParamsDataView::GetErrorDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->error.Get();
  *output = mojo::StringDataView(pointer, context_);
}


inline void ProxyResolverFactoryRequestClient_OnError_ParamsDataView::GetErrorDataView(
    mojo::StringDataView* output) {
  auto pointer = data_->error.Get();
  *output = mojo::StringDataView(pointer, context_);
}


inline void ProxyResolverFactoryRequestClient_ResolveDns_ParamsDataView::GetRequestInfoDataView(
    ::net::interfaces::HostResolverRequestInfoDataView* output) {
  auto pointer = data_->request_info.Get();
  *output = ::net::interfaces::HostResolverRequestInfoDataView(pointer, context_);
}



}  // namespace interfaces
}  // namespace net

#endif  // NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_SHARED_H_
