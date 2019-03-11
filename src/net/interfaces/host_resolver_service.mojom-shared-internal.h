// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"

namespace mojo {
namespace internal {
class ValidationContext;
}
}
namespace net {
namespace interfaces {
namespace internal {
class HostResolverRequestInfo_Data;
class IPEndPoint_Data;
class AddressList_Data;

struct AddressFamily_Data {
 public:
  static bool constexpr kIsExtensible = false;

  static bool IsKnownValue(int32_t value) {
    switch (value) {
      case 0:
      case 1:
      case 2:
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
class HostResolverRequestInfo_Data {
 public:
  static HostResolverRequestInfo_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(HostResolverRequestInfo_Data))) HostResolverRequestInfo_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<mojo::internal::String_Data> host;
  uint16_t port;
  uint8_t is_my_ip_address : 1;
  uint8_t pad2_[1];
  int32_t address_family;

 private:
  HostResolverRequestInfo_Data() : header_({sizeof(*this), 0}) {
  }
  ~HostResolverRequestInfo_Data() = delete;
};
static_assert(sizeof(HostResolverRequestInfo_Data) == 24,
              "Bad sizeof(HostResolverRequestInfo_Data)");
class IPEndPoint_Data {
 public:
  static IPEndPoint_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(IPEndPoint_Data))) IPEndPoint_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> address;
  uint16_t port;
  uint8_t padfinal_[6];

 private:
  IPEndPoint_Data() : header_({sizeof(*this), 0}) {
  }
  ~IPEndPoint_Data() = delete;
};
static_assert(sizeof(IPEndPoint_Data) == 24,
              "Bad sizeof(IPEndPoint_Data)");
class AddressList_Data {
 public:
  static AddressList_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(AddressList_Data))) AddressList_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::IPEndPoint_Data>>> addresses;

 private:
  AddressList_Data() : header_({sizeof(*this), 0}) {
  }
  ~AddressList_Data() = delete;
};
static_assert(sizeof(AddressList_Data) == 16,
              "Bad sizeof(AddressList_Data)");
constexpr uint32_t kHostResolverRequestClient_ReportResult_Name = 0;
class HostResolverRequestClient_ReportResult_Params_Data {
 public:
  static HostResolverRequestClient_ReportResult_Params_Data* New(mojo::internal::Buffer* buf) {
    return new (buf->Allocate(sizeof(HostResolverRequestClient_ReportResult_Params_Data))) HostResolverRequestClient_ReportResult_Params_Data();
  }

  static bool Validate(const void* data,
                       mojo::internal::ValidationContext* validation_context);

  mojo::internal::StructHeader header_;
  int32_t error;
  uint8_t pad0_[4];
  mojo::internal::Pointer<internal::AddressList_Data> result;

 private:
  HostResolverRequestClient_ReportResult_Params_Data() : header_({sizeof(*this), 0}) {
  }
  ~HostResolverRequestClient_ReportResult_Params_Data() = delete;
};
static_assert(sizeof(HostResolverRequestClient_ReportResult_Params_Data) == 24,
              "Bad sizeof(HostResolverRequestClient_ReportResult_Params_Data)");

#pragma pack(pop)

}  // namespace internal
}  // namespace interfaces
}  // namespace net

#endif  // NET_INTERFACES_HOST_RESOLVER_SERVICE_MOJOM_SHARED_INTERNAL_H_