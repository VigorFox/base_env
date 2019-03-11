// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4056)
#pragma warning(disable:4065)
#pragma warning(disable:4756)
#endif

#include "net/interfaces/host_resolver_service.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "net/dns/mojo_host_struct_traits.h"
#include "net/proxy/mojo_proxy_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace net {
namespace interfaces {// static
HostResolverRequestInfoPtr HostResolverRequestInfo::New() {
  HostResolverRequestInfoPtr rv;
  mojo::internal::StructHelper<HostResolverRequestInfo>::Initialize(&rv);
  return rv;
}

HostResolverRequestInfo::HostResolverRequestInfo()
    : host(),
      port(),
      address_family(),
      is_my_ip_address() {
}

HostResolverRequestInfo::~HostResolverRequestInfo() {
}// static
IPEndPointPtr IPEndPoint::New() {
  IPEndPointPtr rv;
  mojo::internal::StructHelper<IPEndPoint>::Initialize(&rv);
  return rv;
}

IPEndPoint::IPEndPoint()
    : address(),
      port() {
}

IPEndPoint::~IPEndPoint() {
}// static
AddressListPtr AddressList::New() {
  AddressListPtr rv;
  mojo::internal::StructHelper<AddressList>::Initialize(&rv);
  return rv;
}

AddressList::AddressList()
    : addresses() {
}

AddressList::~AddressList() {
}
const char HostResolverRequestClient::Name_[] = "net::interfaces::HostResolverRequestClient";

HostResolverRequestClientProxy::HostResolverRequestClientProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void HostResolverRequestClientProxy::ReportResult(
    int32_t in_error, const net::AddressList& in_result) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::HostResolverRequestClient_ReportResult_Params_Data);
  size += mojo::internal::PrepareToSerialize<::net::interfaces::AddressListDataView>(
      in_result, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kHostResolverRequestClient_ReportResult_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::HostResolverRequestClient_ReportResult_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  params->error = in_error;
  typename decltype(params->result)::BaseType* result_ptr;
  mojo::internal::Serialize<::net::interfaces::AddressListDataView>(
      in_result, builder.buffer(), &result_ptr, &serialization_context);
  params->result.Set(result_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->result.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null result in HostResolverRequestClient.ReportResult request");
  (&serialization_context)->handles.Swap(
      builder.message()->mutable_handles());
  (&serialization_context)->associated_endpoint_handles.swap(
      *builder.message()->mutable_associated_endpoint_handles());
  bool ok = receiver_->Accept(builder.message());
  // This return value may be ignored as !ok implies the Connector has
  // encountered an error, which will be visible through other means.
  ALLOW_UNUSED_LOCAL(ok);
}

// static
bool HostResolverRequestClientStubDispatch::Accept(
    HostResolverRequestClient* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kHostResolverRequestClient_ReportResult_Name: {
      internal::HostResolverRequestClient_ReportResult_Params_Data* params =
          reinterpret_cast<internal::HostResolverRequestClient_ReportResult_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      int32_t p_error{};
      net::AddressList p_result{};
      HostResolverRequestClient_ReportResult_ParamsDataView input_data_view(params, &serialization_context);
      
      p_error = input_data_view.error();
      if (!input_data_view.ReadResult(&p_result))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "HostResolverRequestClient::ReportResult deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "HostResolverRequestClient::ReportResult");
      mojo::internal::MessageDispatchContext context(message);
      impl->ReportResult(
std::move(p_error), 
std::move(p_result));
      return true;
    }
  }
  return false;
}

// static
bool HostResolverRequestClientStubDispatch::AcceptWithResponder(
    HostResolverRequestClient* impl,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder) {
  switch (message->header()->name) {
    case internal::kHostResolverRequestClient_ReportResult_Name: {
      break;
    }
  }
  return false;
}

bool HostResolverRequestClientRequestValidator::Accept(mojo::Message* message) {
  if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
    return true;

  mojo::internal::ValidationContext validation_context(
    message->payload(), message->payload_num_bytes(),
    message->handles()->size(), message->payload_num_interface_ids(), message,
    "HostResolverRequestClient RequestValidator");

  switch (message->header()->name) {
    case internal::kHostResolverRequestClient_ReportResult_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::HostResolverRequestClient_ReportResult_Params_Data>(
                  message, &validation_context)) {
        return false;
      }
      return true;
    }
    default:
      break;
  }

  // Unrecognized message.
  ReportValidationError(
      &validation_context,
      mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
  return false;
}

}  // namespace interfaces
}  // namespace net

namespace mojo {


// static
bool StructTraits<::net::interfaces::HostResolverRequestInfo::DataView, ::net::interfaces::HostResolverRequestInfoPtr>::Read(
    ::net::interfaces::HostResolverRequestInfo::DataView input,
    ::net::interfaces::HostResolverRequestInfoPtr* output) {
  bool success = true;
  ::net::interfaces::HostResolverRequestInfoPtr result(::net::interfaces::HostResolverRequestInfo::New());
  
      if (!input.ReadHost(&result->host))
        success = false;
      result->port = input.port();
      if (!input.ReadAddressFamily(&result->address_family))
        success = false;
      result->is_my_ip_address = input.is_my_ip_address();
  *output = std::move(result);
  return success;
}


// static
bool StructTraits<::net::interfaces::IPEndPoint::DataView, ::net::interfaces::IPEndPointPtr>::Read(
    ::net::interfaces::IPEndPoint::DataView input,
    ::net::interfaces::IPEndPointPtr* output) {
  bool success = true;
  ::net::interfaces::IPEndPointPtr result(::net::interfaces::IPEndPoint::New());
  
      if (!input.ReadAddress(&result->address))
        success = false;
      result->port = input.port();
  *output = std::move(result);
  return success;
}


// static
bool StructTraits<::net::interfaces::AddressList::DataView, ::net::interfaces::AddressListPtr>::Read(
    ::net::interfaces::AddressList::DataView input,
    ::net::interfaces::AddressListPtr* output) {
  bool success = true;
  ::net::interfaces::AddressListPtr result(::net::interfaces::AddressList::New());
  
      if (!input.ReadAddresses(&result->addresses))
        success = false;
  *output = std::move(result);
  return success;
}

}  // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif