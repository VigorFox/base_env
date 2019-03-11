// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "net/interfaces/host_resolver_service.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
class ValidationContext;
}
}
namespace net {
namespace interfaces {
namespace internal {
class ProxyServer_Data;
class ProxyInfo_Data;

struct ProxyScheme_Data {
 public:
  static bool constexpr kIsExtensible = false;

  static bool IsKnownValue(int32_t value) {
    switch (value) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        return true;
    }
    return false;
  }

  static bool Validate(int32_t value,
                       mojo::internal::ValidationContext* validation_context) {
    if (kIsExtensible || IsKnownValue(value))
      return true;

    ReportValidationError(validation_context,
                          mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
    return false;
  }
};

#pragma pack(push, 1)
class ProxyServer_Data {
 public:
  static ProxyServer_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyServer_Data))) ProxyServer_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  int32_t scheme;
  uint16_t port;
  uint8_t pad1_[2];
  mojo::internal::Pointer<mojo::internal::String_Data> host;

 private:
  ProxyServer_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyServer_Data() = delete;
};
static_assert(sizeof(ProxyServer_Data) == 24,
              "Bad sizeof(ProxyServer_Data)");
class ProxyInfo_Data {
 public:
  static ProxyInfo_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyInfo_Data))) ProxyInfo_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::ProxyServer_Data>>> proxy_servers;

 private:
  ProxyInfo_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyInfo_Data() = delete;
};
static_assert(sizeof(ProxyInfo_Data) == 16,
              "Bad sizeof(ProxyInfo_Data)");
constexpr uint32_t kProxyResolver_GetProxyForUrl_Name = 0;
class ProxyResolver_GetProxyForUrl_Params_Data {
 public:
  static ProxyResolver_GetProxyForUrl_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolver_GetProxyForUrl_Params_Data))) ProxyResolver_GetProxyForUrl_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
  mojo::internal::Interface_Data client;

 private:
  ProxyResolver_GetProxyForUrl_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolver_GetProxyForUrl_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolver_GetProxyForUrl_Params_Data) == 24,
              "Bad sizeof(ProxyResolver_GetProxyForUrl_Params_Data)");
constexpr uint32_t kProxyResolverRequestClient_ReportResult_Name = 0;
class ProxyResolverRequestClient_ReportResult_Params_Data {
 public:
  static ProxyResolverRequestClient_ReportResult_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverRequestClient_ReportResult_Params_Data))) ProxyResolverRequestClient_ReportResult_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  int32_t error;
  uint8_t pad0_[4];
  mojo::internal::Pointer<internal::ProxyInfo_Data> proxy_info;

 private:
  ProxyResolverRequestClient_ReportResult_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverRequestClient_ReportResult_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverRequestClient_ReportResult_Params_Data) == 24,
              "Bad sizeof(ProxyResolverRequestClient_ReportResult_Params_Data)");
constexpr uint32_t kProxyResolverRequestClient_Alert_Name = 1;
class ProxyResolverRequestClient_Alert_Params_Data {
 public:
  static ProxyResolverRequestClient_Alert_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverRequestClient_Alert_Params_Data))) ProxyResolverRequestClient_Alert_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<mojo::internal::String_Data> error;

 private:
  ProxyResolverRequestClient_Alert_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverRequestClient_Alert_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverRequestClient_Alert_Params_Data) == 16,
              "Bad sizeof(ProxyResolverRequestClient_Alert_Params_Data)");
constexpr uint32_t kProxyResolverRequestClient_OnError_Name = 2;
class ProxyResolverRequestClient_OnError_Params_Data {
 public:
  static ProxyResolverRequestClient_OnError_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverRequestClient_OnError_Params_Data))) ProxyResolverRequestClient_OnError_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  int32_t line_number;
  uint8_t pad0_[4];
  mojo::internal::Pointer<mojo::internal::String_Data> error;

 private:
  ProxyResolverRequestClient_OnError_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverRequestClient_OnError_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverRequestClient_OnError_Params_Data) == 24,
              "Bad sizeof(ProxyResolverRequestClient_OnError_Params_Data)");
constexpr uint32_t kProxyResolverRequestClient_ResolveDns_Name = 3;
class ProxyResolverRequestClient_ResolveDns_Params_Data {
 public:
  static ProxyResolverRequestClient_ResolveDns_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverRequestClient_ResolveDns_Params_Data))) ProxyResolverRequestClient_ResolveDns_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<::net::interfaces::internal::HostResolverRequestInfo_Data> request_info;
  mojo::internal::Interface_Data client;

 private:
  ProxyResolverRequestClient_ResolveDns_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverRequestClient_ResolveDns_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverRequestClient_ResolveDns_Params_Data) == 24,
              "Bad sizeof(ProxyResolverRequestClient_ResolveDns_Params_Data)");
constexpr uint32_t kProxyResolverFactory_CreateResolver_Name = 0;
class ProxyResolverFactory_CreateResolver_Params_Data {
 public:
  static ProxyResolverFactory_CreateResolver_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverFactory_CreateResolver_Params_Data))) ProxyResolverFactory_CreateResolver_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<mojo::internal::String_Data> pac_script;
  mojo::internal::Handle_Data resolver;
  mojo::internal::Interface_Data client;
  uint8_t padfinal_[4];

 private:
  ProxyResolverFactory_CreateResolver_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverFactory_CreateResolver_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverFactory_CreateResolver_Params_Data) == 32,
              "Bad sizeof(ProxyResolverFactory_CreateResolver_Params_Data)");
constexpr uint32_t kProxyResolverFactoryRequestClient_ReportResult_Name = 0;
class ProxyResolverFactoryRequestClient_ReportResult_Params_Data {
 public:
  static ProxyResolverFactoryRequestClient_ReportResult_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverFactoryRequestClient_ReportResult_Params_Data))) ProxyResolverFactoryRequestClient_ReportResult_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  int32_t error;
  uint8_t padfinal_[4];

 private:
  ProxyResolverFactoryRequestClient_ReportResult_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverFactoryRequestClient_ReportResult_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverFactoryRequestClient_ReportResult_Params_Data) == 16,
              "Bad sizeof(ProxyResolverFactoryRequestClient_ReportResult_Params_Data)");
constexpr uint32_t kProxyResolverFactoryRequestClient_Alert_Name = 1;
class ProxyResolverFactoryRequestClient_Alert_Params_Data {
 public:
  static ProxyResolverFactoryRequestClient_Alert_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverFactoryRequestClient_Alert_Params_Data))) ProxyResolverFactoryRequestClient_Alert_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<mojo::internal::String_Data> error;

 private:
  ProxyResolverFactoryRequestClient_Alert_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverFactoryRequestClient_Alert_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverFactoryRequestClient_Alert_Params_Data) == 16,
              "Bad sizeof(ProxyResolverFactoryRequestClient_Alert_Params_Data)");
constexpr uint32_t kProxyResolverFactoryRequestClient_OnError_Name = 2;
class ProxyResolverFactoryRequestClient_OnError_Params_Data {
 public:
  static ProxyResolverFactoryRequestClient_OnError_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverFactoryRequestClient_OnError_Params_Data))) ProxyResolverFactoryRequestClient_OnError_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  int32_t line_number;
  uint8_t pad0_[4];
  mojo::internal::Pointer<mojo::internal::String_Data> error;

 private:
  ProxyResolverFactoryRequestClient_OnError_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverFactoryRequestClient_OnError_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverFactoryRequestClient_OnError_Params_Data) == 24,
              "Bad sizeof(ProxyResolverFactoryRequestClient_OnError_Params_Data)");
constexpr uint32_t kProxyResolverFactoryRequestClient_ResolveDns_Name = 3;
class ProxyResolverFactoryRequestClient_ResolveDns_Params_Data {
 public:
  static ProxyResolverFactoryRequestClient_ResolveDns_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(ProxyResolverFactoryRequestClient_ResolveDns_Params_Data))) ProxyResolverFactoryRequestClient_ResolveDns_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<::net::interfaces::internal::HostResolverRequestInfo_Data> request_info;
  mojo::internal::Interface_Data client;

 private:
  ProxyResolverFactoryRequestClient_ResolveDns_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~ProxyResolverFactoryRequestClient_ResolveDns_Params_Data() = delete;
};
static_assert(sizeof(ProxyResolverFactoryRequestClient_ResolveDns_Params_Data) == 24,
              "Bad sizeof(ProxyResolverFactoryRequestClient_ResolveDns_Params_Data)");

#pragma pack(pop)

}  // namespace internal
}  // namespace interfaces
}  // namespace net

#endif  // NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_SHARED_INTERNAL_H_