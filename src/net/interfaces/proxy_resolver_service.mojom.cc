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

#include "net/interfaces/proxy_resolver_service.mojom.h"

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
ProxyServerPtr ProxyServer::New() {
  ProxyServerPtr rv;
  mojo::internal::StructHelper<ProxyServer>::Initialize(&rv);
  return rv;
}

ProxyServer::ProxyServer()
    : scheme(),
      host(),
      port() {
}

ProxyServer::~ProxyServer() {
}// static
ProxyInfoPtr ProxyInfo::New() {
  ProxyInfoPtr rv;
  mojo::internal::StructHelper<ProxyInfo>::Initialize(&rv);
  return rv;
}

ProxyInfo::ProxyInfo()
    : proxy_servers() {
}

ProxyInfo::~ProxyInfo() {
}
const char ProxyResolver::Name_[] = "net::interfaces::ProxyResolver";

ProxyResolverProxy::ProxyResolverProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void ProxyResolverProxy::GetProxyForUrl(
    const GURL& in_url, ProxyResolverRequestClientPtr in_client) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolver_GetProxyForUrl_Params_Data);
  size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
      in_url, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolver_GetProxyForUrl_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolver_GetProxyForUrl_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  typename decltype(params->url)::BaseType* url_ptr;
  mojo::internal::Serialize<::url::mojom::UrlDataView>(
      in_url, builder.buffer(), &url_ptr, &serialization_context);
  params->url.Set(url_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->url.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null url in ProxyResolver.GetProxyForUrl request");
  mojo::internal::Serialize<::net::interfaces::ProxyResolverRequestClientPtrDataView>(
      in_client, &params->client, &serialization_context);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      !mojo::internal::IsHandleOrInterfaceValid(params->client),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
      "invalid client in ProxyResolver.GetProxyForUrl request");
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
bool ProxyResolverStubDispatch::Accept(
    ProxyResolver* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kProxyResolver_GetProxyForUrl_Name: {
      internal::ProxyResolver_GetProxyForUrl_Params_Data* params =
          reinterpret_cast<internal::ProxyResolver_GetProxyForUrl_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      GURL p_url{};
      ProxyResolverRequestClientPtr p_client{};
      ProxyResolver_GetProxyForUrl_ParamsDataView input_data_view(params, &serialization_context);
      
      if (!input_data_view.ReadUrl(&p_url))
        success = false;
      p_client =
          input_data_view.TakeClient<decltype(p_client)>();
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolver::GetProxyForUrl deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolver::GetProxyForUrl");
      mojo::internal::MessageDispatchContext context(message);
      impl->GetProxyForUrl(
std::move(p_url), 
std::move(p_client));
      return true;
    }
  }
  return false;
}

// static
bool ProxyResolverStubDispatch::AcceptWithResponder(
    ProxyResolver* impl,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder) {
  switch (message->header()->name) {
    case internal::kProxyResolver_GetProxyForUrl_Name: {
      break;
    }
  }
  return false;
}

bool ProxyResolverRequestValidator::Accept(mojo::Message* message) {
  if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
    return true;

  mojo::internal::ValidationContext validation_context(
    message->payload(), message->payload_num_bytes(),
    message->handles()->size(), message->payload_num_interface_ids(), message,
    "ProxyResolver RequestValidator");

  switch (message->header()->name) {
    case internal::kProxyResolver_GetProxyForUrl_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolver_GetProxyForUrl_Params_Data>(
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

const char ProxyResolverRequestClient::Name_[] = "net::interfaces::ProxyResolverRequestClient";

ProxyResolverRequestClientProxy::ProxyResolverRequestClientProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void ProxyResolverRequestClientProxy::ReportResult(
    int32_t in_error, const net::ProxyInfo& in_proxy_info) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverRequestClient_ReportResult_Params_Data);
  size += mojo::internal::PrepareToSerialize<::net::interfaces::ProxyInfoDataView>(
      in_proxy_info, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverRequestClient_ReportResult_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverRequestClient_ReportResult_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  params->error = in_error;
  typename decltype(params->proxy_info)::BaseType* proxy_info_ptr;
  mojo::internal::Serialize<::net::interfaces::ProxyInfoDataView>(
      in_proxy_info, builder.buffer(), &proxy_info_ptr, &serialization_context);
  params->proxy_info.Set(proxy_info_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->proxy_info.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null proxy_info in ProxyResolverRequestClient.ReportResult request");
  (&serialization_context)->handles.Swap(
      builder.message()->mutable_handles());
  (&serialization_context)->associated_endpoint_handles.swap(
      *builder.message()->mutable_associated_endpoint_handles());
  bool ok = receiver_->Accept(builder.message());
  // This return value may be ignored as !ok implies the Connector has
  // encountered an error, which will be visible through other means.
  ALLOW_UNUSED_LOCAL(ok);
}

void ProxyResolverRequestClientProxy::Alert(
    const std::string& in_error) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverRequestClient_Alert_Params_Data);
  size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
      in_error, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverRequestClient_Alert_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverRequestClient_Alert_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  typename decltype(params->error)::BaseType* error_ptr;
  mojo::internal::Serialize<mojo::StringDataView>(
      in_error, builder.buffer(), &error_ptr, &serialization_context);
  params->error.Set(error_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->error.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null error in ProxyResolverRequestClient.Alert request");
  (&serialization_context)->handles.Swap(
      builder.message()->mutable_handles());
  (&serialization_context)->associated_endpoint_handles.swap(
      *builder.message()->mutable_associated_endpoint_handles());
  bool ok = receiver_->Accept(builder.message());
  // This return value may be ignored as !ok implies the Connector has
  // encountered an error, which will be visible through other means.
  ALLOW_UNUSED_LOCAL(ok);
}

void ProxyResolverRequestClientProxy::OnError(
    int32_t in_line_number, const std::string& in_error) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverRequestClient_OnError_Params_Data);
  size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
      in_error, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverRequestClient_OnError_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverRequestClient_OnError_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  params->line_number = in_line_number;
  typename decltype(params->error)::BaseType* error_ptr;
  mojo::internal::Serialize<mojo::StringDataView>(
      in_error, builder.buffer(), &error_ptr, &serialization_context);
  params->error.Set(error_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->error.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null error in ProxyResolverRequestClient.OnError request");
  (&serialization_context)->handles.Swap(
      builder.message()->mutable_handles());
  (&serialization_context)->associated_endpoint_handles.swap(
      *builder.message()->mutable_associated_endpoint_handles());
  bool ok = receiver_->Accept(builder.message());
  // This return value may be ignored as !ok implies the Connector has
  // encountered an error, which will be visible through other means.
  ALLOW_UNUSED_LOCAL(ok);
}

void ProxyResolverRequestClientProxy::ResolveDns(
    std::unique_ptr<net::HostResolver::RequestInfo> in_request_info, ::net::interfaces::HostResolverRequestClientPtr in_client) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverRequestClient_ResolveDns_Params_Data);
  size += mojo::internal::PrepareToSerialize<::net::interfaces::HostResolverRequestInfoDataView>(
      in_request_info, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverRequestClient_ResolveDns_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverRequestClient_ResolveDns_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  typename decltype(params->request_info)::BaseType* request_info_ptr;
  mojo::internal::Serialize<::net::interfaces::HostResolverRequestInfoDataView>(
      in_request_info, builder.buffer(), &request_info_ptr, &serialization_context);
  params->request_info.Set(request_info_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->request_info.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null request_info in ProxyResolverRequestClient.ResolveDns request");
  mojo::internal::Serialize<::net::interfaces::HostResolverRequestClientPtrDataView>(
      in_client, &params->client, &serialization_context);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      !mojo::internal::IsHandleOrInterfaceValid(params->client),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
      "invalid client in ProxyResolverRequestClient.ResolveDns request");
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
bool ProxyResolverRequestClientStubDispatch::Accept(
    ProxyResolverRequestClient* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kProxyResolverRequestClient_ReportResult_Name: {
      internal::ProxyResolverRequestClient_ReportResult_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverRequestClient_ReportResult_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      int32_t p_error{};
      net::ProxyInfo p_proxy_info{};
      ProxyResolverRequestClient_ReportResult_ParamsDataView input_data_view(params, &serialization_context);
      
      p_error = input_data_view.error();
      if (!input_data_view.ReadProxyInfo(&p_proxy_info))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverRequestClient::ReportResult deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverRequestClient::ReportResult");
      mojo::internal::MessageDispatchContext context(message);
      impl->ReportResult(
std::move(p_error), 
std::move(p_proxy_info));
      return true;
    }
    case internal::kProxyResolverRequestClient_Alert_Name: {
      internal::ProxyResolverRequestClient_Alert_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverRequestClient_Alert_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      std::string p_error{};
      ProxyResolverRequestClient_Alert_ParamsDataView input_data_view(params, &serialization_context);
      
      if (!input_data_view.ReadError(&p_error))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverRequestClient::Alert deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverRequestClient::Alert");
      mojo::internal::MessageDispatchContext context(message);
      impl->Alert(
std::move(p_error));
      return true;
    }
    case internal::kProxyResolverRequestClient_OnError_Name: {
      internal::ProxyResolverRequestClient_OnError_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverRequestClient_OnError_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      int32_t p_line_number{};
      std::string p_error{};
      ProxyResolverRequestClient_OnError_ParamsDataView input_data_view(params, &serialization_context);
      
      p_line_number = input_data_view.line_number();
      if (!input_data_view.ReadError(&p_error))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverRequestClient::OnError deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverRequestClient::OnError");
      mojo::internal::MessageDispatchContext context(message);
      impl->OnError(
std::move(p_line_number), 
std::move(p_error));
      return true;
    }
    case internal::kProxyResolverRequestClient_ResolveDns_Name: {
      internal::ProxyResolverRequestClient_ResolveDns_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverRequestClient_ResolveDns_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      std::unique_ptr<net::HostResolver::RequestInfo> p_request_info{};
      ::net::interfaces::HostResolverRequestClientPtr p_client{};
      ProxyResolverRequestClient_ResolveDns_ParamsDataView input_data_view(params, &serialization_context);
      
      if (!input_data_view.ReadRequestInfo(&p_request_info))
        success = false;
      p_client =
          input_data_view.TakeClient<decltype(p_client)>();
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverRequestClient::ResolveDns deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverRequestClient::ResolveDns");
      mojo::internal::MessageDispatchContext context(message);
      impl->ResolveDns(
std::move(p_request_info), 
std::move(p_client));
      return true;
    }
  }
  return false;
}

// static
bool ProxyResolverRequestClientStubDispatch::AcceptWithResponder(
    ProxyResolverRequestClient* impl,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder) {
  switch (message->header()->name) {
    case internal::kProxyResolverRequestClient_ReportResult_Name: {
      break;
    }
    case internal::kProxyResolverRequestClient_Alert_Name: {
      break;
    }
    case internal::kProxyResolverRequestClient_OnError_Name: {
      break;
    }
    case internal::kProxyResolverRequestClient_ResolveDns_Name: {
      break;
    }
  }
  return false;
}

bool ProxyResolverRequestClientRequestValidator::Accept(mojo::Message* message) {
  if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
    return true;

  mojo::internal::ValidationContext validation_context(
    message->payload(), message->payload_num_bytes(),
    message->handles()->size(), message->payload_num_interface_ids(), message,
    "ProxyResolverRequestClient RequestValidator");

  switch (message->header()->name) {
    case internal::kProxyResolverRequestClient_ReportResult_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverRequestClient_ReportResult_Params_Data>(
                  message, &validation_context)) {
        return false;
      }
      return true;
    }
    case internal::kProxyResolverRequestClient_Alert_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverRequestClient_Alert_Params_Data>(
                  message, &validation_context)) {
        return false;
      }
      return true;
    }
    case internal::kProxyResolverRequestClient_OnError_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverRequestClient_OnError_Params_Data>(
                  message, &validation_context)) {
        return false;
      }
      return true;
    }
    case internal::kProxyResolverRequestClient_ResolveDns_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverRequestClient_ResolveDns_Params_Data>(
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

const char ProxyResolverFactory::Name_[] = "net::interfaces::ProxyResolverFactory";

ProxyResolverFactoryProxy::ProxyResolverFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void ProxyResolverFactoryProxy::CreateResolver(
    const std::string& in_pac_script, ProxyResolverRequest in_resolver, ProxyResolverFactoryRequestClientPtr in_client) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverFactory_CreateResolver_Params_Data);
  size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
      in_pac_script, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverFactory_CreateResolver_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverFactory_CreateResolver_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  typename decltype(params->pac_script)::BaseType* pac_script_ptr;
  mojo::internal::Serialize<mojo::StringDataView>(
      in_pac_script, builder.buffer(), &pac_script_ptr, &serialization_context);
  params->pac_script.Set(pac_script_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->pac_script.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null pac_script in ProxyResolverFactory.CreateResolver request");
  mojo::internal::Serialize<::net::interfaces::ProxyResolverRequestDataView>(
      in_resolver, &params->resolver, &serialization_context);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      !mojo::internal::IsHandleOrInterfaceValid(params->resolver),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
      "invalid resolver in ProxyResolverFactory.CreateResolver request");
  mojo::internal::Serialize<::net::interfaces::ProxyResolverFactoryRequestClientPtrDataView>(
      in_client, &params->client, &serialization_context);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      !mojo::internal::IsHandleOrInterfaceValid(params->client),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
      "invalid client in ProxyResolverFactory.CreateResolver request");
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
bool ProxyResolverFactoryStubDispatch::Accept(
    ProxyResolverFactory* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kProxyResolverFactory_CreateResolver_Name: {
      internal::ProxyResolverFactory_CreateResolver_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverFactory_CreateResolver_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      std::string p_pac_script{};
      ProxyResolverRequest p_resolver{};
      ProxyResolverFactoryRequestClientPtr p_client{};
      ProxyResolverFactory_CreateResolver_ParamsDataView input_data_view(params, &serialization_context);
      
      if (!input_data_view.ReadPacScript(&p_pac_script))
        success = false;
      p_resolver =
          input_data_view.TakeResolver<decltype(p_resolver)>();
      p_client =
          input_data_view.TakeClient<decltype(p_client)>();
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverFactory::CreateResolver deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverFactory::CreateResolver");
      mojo::internal::MessageDispatchContext context(message);
      impl->CreateResolver(
std::move(p_pac_script), 
std::move(p_resolver), 
std::move(p_client));
      return true;
    }
  }
  return false;
}

// static
bool ProxyResolverFactoryStubDispatch::AcceptWithResponder(
    ProxyResolverFactory* impl,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder) {
  switch (message->header()->name) {
    case internal::kProxyResolverFactory_CreateResolver_Name: {
      break;
    }
  }
  return false;
}

bool ProxyResolverFactoryRequestValidator::Accept(mojo::Message* message) {
  if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
    return true;

  mojo::internal::ValidationContext validation_context(
    message->payload(), message->payload_num_bytes(),
    message->handles()->size(), message->payload_num_interface_ids(), message,
    "ProxyResolverFactory RequestValidator");

  switch (message->header()->name) {
    case internal::kProxyResolverFactory_CreateResolver_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverFactory_CreateResolver_Params_Data>(
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

const char ProxyResolverFactoryRequestClient::Name_[] = "net::interfaces::ProxyResolverFactoryRequestClient";

ProxyResolverFactoryRequestClientProxy::ProxyResolverFactoryRequestClientProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver) {
}

void ProxyResolverFactoryRequestClientProxy::ReportResult(
    int32_t in_error) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverFactoryRequestClient_ReportResult_Params_Data);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverFactoryRequestClient_ReportResult_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverFactoryRequestClient_ReportResult_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  params->error = in_error;
  (&serialization_context)->handles.Swap(
      builder.message()->mutable_handles());
  (&serialization_context)->associated_endpoint_handles.swap(
      *builder.message()->mutable_associated_endpoint_handles());
  bool ok = receiver_->Accept(builder.message());
  // This return value may be ignored as !ok implies the Connector has
  // encountered an error, which will be visible through other means.
  ALLOW_UNUSED_LOCAL(ok);
}

void ProxyResolverFactoryRequestClientProxy::Alert(
    const std::string& in_error) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverFactoryRequestClient_Alert_Params_Data);
  size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
      in_error, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverFactoryRequestClient_Alert_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverFactoryRequestClient_Alert_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  typename decltype(params->error)::BaseType* error_ptr;
  mojo::internal::Serialize<mojo::StringDataView>(
      in_error, builder.buffer(), &error_ptr, &serialization_context);
  params->error.Set(error_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->error.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null error in ProxyResolverFactoryRequestClient.Alert request");
  (&serialization_context)->handles.Swap(
      builder.message()->mutable_handles());
  (&serialization_context)->associated_endpoint_handles.swap(
      *builder.message()->mutable_associated_endpoint_handles());
  bool ok = receiver_->Accept(builder.message());
  // This return value may be ignored as !ok implies the Connector has
  // encountered an error, which will be visible through other means.
  ALLOW_UNUSED_LOCAL(ok);
}

void ProxyResolverFactoryRequestClientProxy::OnError(
    int32_t in_line_number, const std::string& in_error) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverFactoryRequestClient_OnError_Params_Data);
  size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
      in_error, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverFactoryRequestClient_OnError_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverFactoryRequestClient_OnError_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  params->line_number = in_line_number;
  typename decltype(params->error)::BaseType* error_ptr;
  mojo::internal::Serialize<mojo::StringDataView>(
      in_error, builder.buffer(), &error_ptr, &serialization_context);
  params->error.Set(error_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->error.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null error in ProxyResolverFactoryRequestClient.OnError request");
  (&serialization_context)->handles.Swap(
      builder.message()->mutable_handles());
  (&serialization_context)->associated_endpoint_handles.swap(
      *builder.message()->mutable_associated_endpoint_handles());
  bool ok = receiver_->Accept(builder.message());
  // This return value may be ignored as !ok implies the Connector has
  // encountered an error, which will be visible through other means.
  ALLOW_UNUSED_LOCAL(ok);
}

void ProxyResolverFactoryRequestClientProxy::ResolveDns(
    std::unique_ptr<net::HostResolver::RequestInfo> in_request_info, ::net::interfaces::HostResolverRequestClientPtr in_client) {
  mojo::internal::SerializationContext serialization_context;
  size_t size = sizeof(::net::interfaces::internal::ProxyResolverFactoryRequestClient_ResolveDns_Params_Data);
  size += mojo::internal::PrepareToSerialize<::net::interfaces::HostResolverRequestInfoDataView>(
      in_request_info, &serialization_context);
  constexpr uint32_t kFlags = 0;
  mojo::internal::MessageBuilder builder(
      internal::kProxyResolverFactoryRequestClient_ResolveDns_Name, kFlags, size,
      serialization_context.associated_endpoint_count);

  auto params =
      ::net::interfaces::internal::ProxyResolverFactoryRequestClient_ResolveDns_Params_Data::New(builder.buffer());
  ALLOW_UNUSED_LOCAL(params);
  typename decltype(params->request_info)::BaseType* request_info_ptr;
  mojo::internal::Serialize<::net::interfaces::HostResolverRequestInfoDataView>(
      in_request_info, builder.buffer(), &request_info_ptr, &serialization_context);
  params->request_info.Set(request_info_ptr);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      params->request_info.is_null(),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
      "null request_info in ProxyResolverFactoryRequestClient.ResolveDns request");
  mojo::internal::Serialize<::net::interfaces::HostResolverRequestClientPtrDataView>(
      in_client, &params->client, &serialization_context);
  MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
      !mojo::internal::IsHandleOrInterfaceValid(params->client),
      mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
      "invalid client in ProxyResolverFactoryRequestClient.ResolveDns request");
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
bool ProxyResolverFactoryRequestClientStubDispatch::Accept(
    ProxyResolverFactoryRequestClient* impl,
    mojo::Message* message) {
  switch (message->header()->name) {
    case internal::kProxyResolverFactoryRequestClient_ReportResult_Name: {
      internal::ProxyResolverFactoryRequestClient_ReportResult_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverFactoryRequestClient_ReportResult_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      int32_t p_error{};
      ProxyResolverFactoryRequestClient_ReportResult_ParamsDataView input_data_view(params, &serialization_context);
      
      p_error = input_data_view.error();
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverFactoryRequestClient::ReportResult deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverFactoryRequestClient::ReportResult");
      mojo::internal::MessageDispatchContext context(message);
      impl->ReportResult(
std::move(p_error));
      return true;
    }
    case internal::kProxyResolverFactoryRequestClient_Alert_Name: {
      internal::ProxyResolverFactoryRequestClient_Alert_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverFactoryRequestClient_Alert_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      std::string p_error{};
      ProxyResolverFactoryRequestClient_Alert_ParamsDataView input_data_view(params, &serialization_context);
      
      if (!input_data_view.ReadError(&p_error))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverFactoryRequestClient::Alert deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverFactoryRequestClient::Alert");
      mojo::internal::MessageDispatchContext context(message);
      impl->Alert(
std::move(p_error));
      return true;
    }
    case internal::kProxyResolverFactoryRequestClient_OnError_Name: {
      internal::ProxyResolverFactoryRequestClient_OnError_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverFactoryRequestClient_OnError_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      int32_t p_line_number{};
      std::string p_error{};
      ProxyResolverFactoryRequestClient_OnError_ParamsDataView input_data_view(params, &serialization_context);
      
      p_line_number = input_data_view.line_number();
      if (!input_data_view.ReadError(&p_error))
        success = false;
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverFactoryRequestClient::OnError deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverFactoryRequestClient::OnError");
      mojo::internal::MessageDispatchContext context(message);
      impl->OnError(
std::move(p_line_number), 
std::move(p_error));
      return true;
    }
    case internal::kProxyResolverFactoryRequestClient_ResolveDns_Name: {
      internal::ProxyResolverFactoryRequestClient_ResolveDns_Params_Data* params =
          reinterpret_cast<internal::ProxyResolverFactoryRequestClient_ResolveDns_Params_Data*>(
              message->mutable_payload());
      
      mojo::internal::SerializationContext serialization_context;
      serialization_context.handles.Swap((message)->mutable_handles());
      serialization_context.associated_endpoint_handles.swap(
          *(message)->mutable_associated_endpoint_handles());
      bool success = true;
      std::unique_ptr<net::HostResolver::RequestInfo> p_request_info{};
      ::net::interfaces::HostResolverRequestClientPtr p_client{};
      ProxyResolverFactoryRequestClient_ResolveDns_ParamsDataView input_data_view(params, &serialization_context);
      
      if (!input_data_view.ReadRequestInfo(&p_request_info))
        success = false;
      p_client =
          input_data_view.TakeClient<decltype(p_client)>();
      if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "ProxyResolverFactoryRequestClient::ResolveDns deserializer");
        return false;
      }
      // A null |impl| means no implementation was bound.
      assert(impl);
      TRACE_EVENT0("mojom", "ProxyResolverFactoryRequestClient::ResolveDns");
      mojo::internal::MessageDispatchContext context(message);
      impl->ResolveDns(
std::move(p_request_info), 
std::move(p_client));
      return true;
    }
  }
  return false;
}

// static
bool ProxyResolverFactoryRequestClientStubDispatch::AcceptWithResponder(
    ProxyResolverFactoryRequestClient* impl,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder) {
  switch (message->header()->name) {
    case internal::kProxyResolverFactoryRequestClient_ReportResult_Name: {
      break;
    }
    case internal::kProxyResolverFactoryRequestClient_Alert_Name: {
      break;
    }
    case internal::kProxyResolverFactoryRequestClient_OnError_Name: {
      break;
    }
    case internal::kProxyResolverFactoryRequestClient_ResolveDns_Name: {
      break;
    }
  }
  return false;
}

bool ProxyResolverFactoryRequestClientRequestValidator::Accept(mojo::Message* message) {
  if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
    return true;

  mojo::internal::ValidationContext validation_context(
    message->payload(), message->payload_num_bytes(),
    message->handles()->size(), message->payload_num_interface_ids(), message,
    "ProxyResolverFactoryRequestClient RequestValidator");

  switch (message->header()->name) {
    case internal::kProxyResolverFactoryRequestClient_ReportResult_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverFactoryRequestClient_ReportResult_Params_Data>(
                  message, &validation_context)) {
        return false;
      }
      return true;
    }
    case internal::kProxyResolverFactoryRequestClient_Alert_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverFactoryRequestClient_Alert_Params_Data>(
                  message, &validation_context)) {
        return false;
      }
      return true;
    }
    case internal::kProxyResolverFactoryRequestClient_OnError_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverFactoryRequestClient_OnError_Params_Data>(
                  message, &validation_context)) {
        return false;
      }
      return true;
    }
    case internal::kProxyResolverFactoryRequestClient_ResolveDns_Name: {
      if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
              message, &validation_context)) {
        return false;
      }
      if (!mojo::internal::ValidateMessagePayload<
               internal::ProxyResolverFactoryRequestClient_ResolveDns_Params_Data>(
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
bool StructTraits<::net::interfaces::ProxyServer::DataView, ::net::interfaces::ProxyServerPtr>::Read(
    ::net::interfaces::ProxyServer::DataView input,
    ::net::interfaces::ProxyServerPtr* output) {
  bool success = true;
  ::net::interfaces::ProxyServerPtr result(::net::interfaces::ProxyServer::New());
  
      if (!input.ReadScheme(&result->scheme))
        success = false;
      if (!input.ReadHost(&result->host))
        success = false;
      result->port = input.port();
  *output = std::move(result);
  return success;
}


// static
bool StructTraits<::net::interfaces::ProxyInfo::DataView, ::net::interfaces::ProxyInfoPtr>::Read(
    ::net::interfaces::ProxyInfo::DataView input,
    ::net::interfaces::ProxyInfoPtr* output) {
  bool success = true;
  ::net::interfaces::ProxyInfoPtr result(::net::interfaces::ProxyInfo::New());
  
      if (!input.ReadProxyServers(&result->proxy_servers))
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