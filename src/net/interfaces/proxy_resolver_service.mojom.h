// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_H_
#define NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_H_

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
#include "net/interfaces/proxy_resolver_service.mojom-shared.h"
#include "net/interfaces/host_resolver_service.mojom.h"
#include "url/mojo/url.mojom.h"
#include <string>
#include <vector>
#include "url/gurl.h"
#include "net/proxy/proxy_info.h"
#include "net/dns/host_resolver.h"
#include "net/proxy/proxy_server.h"


namespace net {
namespace interfaces {
class ProxyResolver;
using ProxyResolverPtr = mojo::InterfacePtr<ProxyResolver>;
using ProxyResolverPtrInfo = mojo::InterfacePtrInfo<ProxyResolver>;
using ThreadSafeProxyResolverPtr =
    mojo::ThreadSafeInterfacePtr<ProxyResolver>;
using ProxyResolverRequest = mojo::InterfaceRequest<ProxyResolver>;
using ProxyResolverAssociatedPtr =
    mojo::AssociatedInterfacePtr<ProxyResolver>;
using ThreadSafeProxyResolverAssociatedPtr =
    mojo::ThreadSafeAssociatedInterfacePtr<ProxyResolver>;
using ProxyResolverAssociatedPtrInfo =
    mojo::AssociatedInterfacePtrInfo<ProxyResolver>;
using ProxyResolverAssociatedRequest =
    mojo::AssociatedInterfaceRequest<ProxyResolver>;

class ProxyResolverRequestClient;
using ProxyResolverRequestClientPtr = mojo::InterfacePtr<ProxyResolverRequestClient>;
using ProxyResolverRequestClientPtrInfo = mojo::InterfacePtrInfo<ProxyResolverRequestClient>;
using ThreadSafeProxyResolverRequestClientPtr =
    mojo::ThreadSafeInterfacePtr<ProxyResolverRequestClient>;
using ProxyResolverRequestClientRequest = mojo::InterfaceRequest<ProxyResolverRequestClient>;
using ProxyResolverRequestClientAssociatedPtr =
    mojo::AssociatedInterfacePtr<ProxyResolverRequestClient>;
using ThreadSafeProxyResolverRequestClientAssociatedPtr =
    mojo::ThreadSafeAssociatedInterfacePtr<ProxyResolverRequestClient>;
using ProxyResolverRequestClientAssociatedPtrInfo =
    mojo::AssociatedInterfacePtrInfo<ProxyResolverRequestClient>;
using ProxyResolverRequestClientAssociatedRequest =
    mojo::AssociatedInterfaceRequest<ProxyResolverRequestClient>;

class ProxyResolverFactory;
using ProxyResolverFactoryPtr = mojo::InterfacePtr<ProxyResolverFactory>;
using ProxyResolverFactoryPtrInfo = mojo::InterfacePtrInfo<ProxyResolverFactory>;
using ThreadSafeProxyResolverFactoryPtr =
    mojo::ThreadSafeInterfacePtr<ProxyResolverFactory>;
using ProxyResolverFactoryRequest = mojo::InterfaceRequest<ProxyResolverFactory>;
using ProxyResolverFactoryAssociatedPtr =
    mojo::AssociatedInterfacePtr<ProxyResolverFactory>;
using ThreadSafeProxyResolverFactoryAssociatedPtr =
    mojo::ThreadSafeAssociatedInterfacePtr<ProxyResolverFactory>;
using ProxyResolverFactoryAssociatedPtrInfo =
    mojo::AssociatedInterfacePtrInfo<ProxyResolverFactory>;
using ProxyResolverFactoryAssociatedRequest =
    mojo::AssociatedInterfaceRequest<ProxyResolverFactory>;

class ProxyResolverFactoryRequestClient;
using ProxyResolverFactoryRequestClientPtr = mojo::InterfacePtr<ProxyResolverFactoryRequestClient>;
using ProxyResolverFactoryRequestClientPtrInfo = mojo::InterfacePtrInfo<ProxyResolverFactoryRequestClient>;
using ThreadSafeProxyResolverFactoryRequestClientPtr =
    mojo::ThreadSafeInterfacePtr<ProxyResolverFactoryRequestClient>;
using ProxyResolverFactoryRequestClientRequest = mojo::InterfaceRequest<ProxyResolverFactoryRequestClient>;
using ProxyResolverFactoryRequestClientAssociatedPtr =
    mojo::AssociatedInterfacePtr<ProxyResolverFactoryRequestClient>;
using ThreadSafeProxyResolverFactoryRequestClientAssociatedPtr =
    mojo::ThreadSafeAssociatedInterfacePtr<ProxyResolverFactoryRequestClient>;
using ProxyResolverFactoryRequestClientAssociatedPtrInfo =
    mojo::AssociatedInterfacePtrInfo<ProxyResolverFactoryRequestClient>;
using ProxyResolverFactoryRequestClientAssociatedRequest =
    mojo::AssociatedInterfaceRequest<ProxyResolverFactoryRequestClient>;

class ProxyServer;
using ProxyServerPtr = mojo::InlinedStructPtr<ProxyServer>;

class ProxyInfo;
using ProxyInfoPtr = mojo::StructPtr<ProxyInfo>;


class ProxyResolverProxy;

template <typename ImplRefTraits>
class ProxyResolverStub;

class ProxyResolverRequestValidator;

class  ProxyResolver
    : public ProxyResolverInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasSyncMethods_ = false;

  using Proxy_ = ProxyResolverProxy;

  template <typename ImplRefTraits>
  using Stub_ = ProxyResolverStub<ImplRefTraits>;

  using RequestValidator_ = ProxyResolverRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kGetProxyForUrlMinVersion = 0,
  };
  virtual ~ProxyResolver() {}

  virtual void GetProxyForUrl(const GURL& url, ProxyResolverRequestClientPtr client) = 0;
};

class ProxyResolverRequestClientProxy;

template <typename ImplRefTraits>
class ProxyResolverRequestClientStub;

class ProxyResolverRequestClientRequestValidator;

class  ProxyResolverRequestClient
    : public ProxyResolverRequestClientInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasSyncMethods_ = false;

  using Proxy_ = ProxyResolverRequestClientProxy;

  template <typename ImplRefTraits>
  using Stub_ = ProxyResolverRequestClientStub<ImplRefTraits>;

  using RequestValidator_ = ProxyResolverRequestClientRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kReportResultMinVersion = 0,
    kAlertMinVersion = 0,
    kOnErrorMinVersion = 0,
    kResolveDnsMinVersion = 0,
  };
  virtual ~ProxyResolverRequestClient() {}

  virtual void ReportResult(int32_t error, const net::ProxyInfo& proxy_info) = 0;

  virtual void Alert(const std::string& error) = 0;

  virtual void OnError(int32_t line_number, const std::string& error) = 0;

  virtual void ResolveDns(std::unique_ptr<net::HostResolver::RequestInfo> request_info, ::net::interfaces::HostResolverRequestClientPtr client) = 0;
};

class ProxyResolverFactoryProxy;

template <typename ImplRefTraits>
class ProxyResolverFactoryStub;

class ProxyResolverFactoryRequestValidator;

class  ProxyResolverFactory
    : public ProxyResolverFactoryInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasSyncMethods_ = false;

  using Proxy_ = ProxyResolverFactoryProxy;

  template <typename ImplRefTraits>
  using Stub_ = ProxyResolverFactoryStub<ImplRefTraits>;

  using RequestValidator_ = ProxyResolverFactoryRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kCreateResolverMinVersion = 0,
  };
  virtual ~ProxyResolverFactory() {}

  virtual void CreateResolver(const std::string& pac_script, ProxyResolverRequest resolver, ProxyResolverFactoryRequestClientPtr client) = 0;
};

class ProxyResolverFactoryRequestClientProxy;

template <typename ImplRefTraits>
class ProxyResolverFactoryRequestClientStub;

class ProxyResolverFactoryRequestClientRequestValidator;

class  ProxyResolverFactoryRequestClient
    : public ProxyResolverFactoryRequestClientInterfaceBase {
 public:
  static const char Name_[];
  static constexpr uint32_t Version_ = 0;
  static constexpr bool PassesAssociatedKinds_ = false;
  static constexpr bool HasSyncMethods_ = false;

  using Proxy_ = ProxyResolverFactoryRequestClientProxy;

  template <typename ImplRefTraits>
  using Stub_ = ProxyResolverFactoryRequestClientStub<ImplRefTraits>;

  using RequestValidator_ = ProxyResolverFactoryRequestClientRequestValidator;
  using ResponseValidator_ = mojo::PassThroughFilter;
  enum MethodMinVersions : uint32_t {
    kReportResultMinVersion = 0,
    kAlertMinVersion = 0,
    kOnErrorMinVersion = 0,
    kResolveDnsMinVersion = 0,
  };
  virtual ~ProxyResolverFactoryRequestClient() {}

  virtual void ReportResult(int32_t error) = 0;

  virtual void Alert(const std::string& error) = 0;

  virtual void OnError(int32_t line_number, const std::string& error) = 0;

  virtual void ResolveDns(std::unique_ptr<net::HostResolver::RequestInfo> request_info, ::net::interfaces::HostResolverRequestClientPtr client) = 0;
};

class  ProxyResolverProxy
    : public ProxyResolver {
 public:
  explicit ProxyResolverProxy(mojo::MessageReceiverWithResponder* receiver);
  void GetProxyForUrl(const GURL& url, ProxyResolverRequestClientPtr client) override;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};

class  ProxyResolverRequestClientProxy
    : public ProxyResolverRequestClient {
 public:
  explicit ProxyResolverRequestClientProxy(mojo::MessageReceiverWithResponder* receiver);
  void ReportResult(int32_t error, const net::ProxyInfo& proxy_info) override;
  void Alert(const std::string& error) override;
  void OnError(int32_t line_number, const std::string& error) override;
  void ResolveDns(std::unique_ptr<net::HostResolver::RequestInfo> request_info, ::net::interfaces::HostResolverRequestClientPtr client) override;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};

class  ProxyResolverFactoryProxy
    : public ProxyResolverFactory {
 public:
  explicit ProxyResolverFactoryProxy(mojo::MessageReceiverWithResponder* receiver);
  void CreateResolver(const std::string& pac_script, ProxyResolverRequest resolver, ProxyResolverFactoryRequestClientPtr client) override;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};

class  ProxyResolverFactoryRequestClientProxy
    : public ProxyResolverFactoryRequestClient {
 public:
  explicit ProxyResolverFactoryRequestClientProxy(mojo::MessageReceiverWithResponder* receiver);
  void ReportResult(int32_t error) override;
  void Alert(const std::string& error) override;
  void OnError(int32_t line_number, const std::string& error) override;
  void ResolveDns(std::unique_ptr<net::HostResolver::RequestInfo> request_info, ::net::interfaces::HostResolverRequestClientPtr client) override;

 private:
  mojo::MessageReceiverWithResponder* receiver_;
};
class  ProxyResolverStubDispatch {
 public:
  static bool Accept(ProxyResolver* impl, mojo::Message* message);
  static bool AcceptWithResponder(ProxyResolver* impl,
                                  mojo::Message* message,
                                  mojo::MessageReceiverWithStatus* responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<ProxyResolver>>
class ProxyResolverStub
    : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  ProxyResolverStub() {}
  ~ProxyResolverStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      mojo::MessageReceiverWithStatus* responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, responder);
  }

 private:
  ImplPointerType sink_;
};
class  ProxyResolverRequestClientStubDispatch {
 public:
  static bool Accept(ProxyResolverRequestClient* impl, mojo::Message* message);
  static bool AcceptWithResponder(ProxyResolverRequestClient* impl,
                                  mojo::Message* message,
                                  mojo::MessageReceiverWithStatus* responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<ProxyResolverRequestClient>>
class ProxyResolverRequestClientStub
    : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  ProxyResolverRequestClientStub() {}
  ~ProxyResolverRequestClientStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverRequestClientStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      mojo::MessageReceiverWithStatus* responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverRequestClientStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, responder);
  }

 private:
  ImplPointerType sink_;
};
class  ProxyResolverFactoryStubDispatch {
 public:
  static bool Accept(ProxyResolverFactory* impl, mojo::Message* message);
  static bool AcceptWithResponder(ProxyResolverFactory* impl,
                                  mojo::Message* message,
                                  mojo::MessageReceiverWithStatus* responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<ProxyResolverFactory>>
class ProxyResolverFactoryStub
    : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  ProxyResolverFactoryStub() {}
  ~ProxyResolverFactoryStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverFactoryStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      mojo::MessageReceiverWithStatus* responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverFactoryStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, responder);
  }

 private:
  ImplPointerType sink_;
};
class  ProxyResolverFactoryRequestClientStubDispatch {
 public:
  static bool Accept(ProxyResolverFactoryRequestClient* impl, mojo::Message* message);
  static bool AcceptWithResponder(ProxyResolverFactoryRequestClient* impl,
                                  mojo::Message* message,
                                  mojo::MessageReceiverWithStatus* responder);
};

template <typename ImplRefTraits =
              mojo::RawPtrImplRefTraits<ProxyResolverFactoryRequestClient>>
class ProxyResolverFactoryRequestClientStub
    : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
 public:
  using ImplPointerType = typename ImplRefTraits::PointerType;

  ProxyResolverFactoryRequestClientStub() {}
  ~ProxyResolverFactoryRequestClientStub() override {}

  void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
  ImplPointerType& sink() { return sink_; }

  bool Accept(mojo::Message* message) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverFactoryRequestClientStubDispatch::Accept(
        ImplRefTraits::GetRawPointer(&sink_), message);
  }

  bool AcceptWithResponder(
      mojo::Message* message,
      mojo::MessageReceiverWithStatus* responder) override {
    if (ImplRefTraits::IsNull(sink_))
      return false;
    return ProxyResolverFactoryRequestClientStubDispatch::AcceptWithResponder(
        ImplRefTraits::GetRawPointer(&sink_), message, responder);
  }

 private:
  ImplPointerType sink_;
};
class  ProxyResolverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
 public:
  bool Accept(mojo::Message* message) override;
};
class  ProxyResolverRequestClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
 public:
  bool Accept(mojo::Message* message) override;
};
class  ProxyResolverFactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
 public:
  bool Accept(mojo::Message* message) override;
};
class  ProxyResolverFactoryRequestClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
 public:
  bool Accept(mojo::Message* message) override;
};


class  ProxyServer {
 public:
  using DataView = ProxyServerDataView;
  using Data_ = internal::ProxyServer_Data;

  static ProxyServerPtr New();

  template <typename U>
  static ProxyServerPtr From(const U& u) {
    return mojo::TypeConverter<ProxyServerPtr, U>::Convert(u);
  }

  template <typename U>
  U To() const {
    return mojo::TypeConverter<U, ProxyServer>::Convert(*this);
  }

  ProxyServer();
  ~ProxyServer();

  // Clone() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Clone() or copy
  // constructor/assignment are available for members.
  template <typename StructPtrType = ProxyServerPtr>
  ProxyServerPtr Clone() const;

  // Equals() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Equals() or == operator
  // are available for members.
  template <typename T,
            typename std::enable_if<std::is_same<
                T, ProxyServer>::value>::type* = nullptr>
  bool Equals(const T& other) const;

  template <typename UserType>
  static std::vector<uint8_t> Serialize(UserType* input) {
    return mojo::internal::StructSerializeImpl<
        ProxyServer::DataView, std::vector<uint8_t>>(input);
  }

  template <typename UserType>
  static bool Deserialize(const std::vector<uint8_t>& input,
                          UserType* output) {
    return mojo::internal::StructDeserializeImpl<
        ProxyServer::DataView, std::vector<uint8_t>>(
            input, output);
  }

  ProxyScheme scheme;
  std::string host;
  uint16_t port;
};







class  ProxyInfo {
 public:
  using DataView = ProxyInfoDataView;
  using Data_ = internal::ProxyInfo_Data;

  static ProxyInfoPtr New();

  template <typename U>
  static ProxyInfoPtr From(const U& u) {
    return mojo::TypeConverter<ProxyInfoPtr, U>::Convert(u);
  }

  template <typename U>
  U To() const {
    return mojo::TypeConverter<U, ProxyInfo>::Convert(*this);
  }

  ProxyInfo();
  ~ProxyInfo();

  // Clone() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Clone() or copy
  // constructor/assignment are available for members.
  template <typename StructPtrType = ProxyInfoPtr>
  ProxyInfoPtr Clone() const;

  // Equals() is a template so it is only instantiated if it is used. Thus, the
  // bindings generator does not need to know whether Equals() or == operator
  // are available for members.
  template <typename T,
            typename std::enable_if<std::is_same<
                T, ProxyInfo>::value>::type* = nullptr>
  bool Equals(const T& other) const;

  template <typename UserType>
  static std::vector<uint8_t> Serialize(UserType* input) {
    return mojo::internal::StructSerializeImpl<
        ProxyInfo::DataView, std::vector<uint8_t>>(input);
  }

  template <typename UserType>
  static bool Deserialize(const std::vector<uint8_t>& input,
                          UserType* output) {
    return mojo::internal::StructDeserializeImpl<
        ProxyInfo::DataView, std::vector<uint8_t>>(
            input, output);
  }

  std::vector<net::ProxyServer> proxy_servers;
};


template <typename StructPtrType>
ProxyServerPtr ProxyServer::Clone() const {
  // Use StructPtrType to prevent the compiler from trying to compile this
  // without being asked.
  StructPtrType rv(New());
  rv->scheme = mojo::internal::Clone(scheme);
  rv->host = mojo::internal::Clone(host);
  rv->port = mojo::internal::Clone(port);
  return rv;
}

template <typename T,
          typename std::enable_if<std::is_same<
              T, ProxyServer>::value>::type*>
bool ProxyServer::Equals(const T& other) const {
  if (!mojo::internal::Equals(this->scheme, other.scheme))
    return false;
  if (!mojo::internal::Equals(this->host, other.host))
    return false;
  if (!mojo::internal::Equals(this->port, other.port))
    return false;
  return true;
}
template <typename StructPtrType>
ProxyInfoPtr ProxyInfo::Clone() const {
  // Use StructPtrType to prevent the compiler from trying to compile this
  // without being asked.
  StructPtrType rv(New());
  rv->proxy_servers = mojo::internal::Clone(proxy_servers);
  return rv;
}

template <typename T,
          typename std::enable_if<std::is_same<
              T, ProxyInfo>::value>::type*>
bool ProxyInfo::Equals(const T& other) const {
  if (!mojo::internal::Equals(this->proxy_servers, other.proxy_servers))
    return false;
  return true;
}


}  // namespace interfaces
}  // namespace net

namespace mojo {


template <>
struct  StructTraits<::net::interfaces::ProxyServer::DataView,
                                         ::net::interfaces::ProxyServerPtr> {
  static bool IsNull(const ::net::interfaces::ProxyServerPtr& input) { return !input; }
  static void SetToNull(::net::interfaces::ProxyServerPtr* output) { output->reset(); }

  static decltype(::net::interfaces::ProxyServer::scheme) scheme(
      const ::net::interfaces::ProxyServerPtr& input) {
    return input->scheme;
  }

  static const decltype(::net::interfaces::ProxyServer::host)& host(
      const ::net::interfaces::ProxyServerPtr& input) {
    return input->host;
  }

  static decltype(::net::interfaces::ProxyServer::port) port(
      const ::net::interfaces::ProxyServerPtr& input) {
    return input->port;
  }

  static bool Read(::net::interfaces::ProxyServer::DataView input, ::net::interfaces::ProxyServerPtr* output);
};


template <>
struct  StructTraits<::net::interfaces::ProxyInfo::DataView,
                                         ::net::interfaces::ProxyInfoPtr> {
  static bool IsNull(const ::net::interfaces::ProxyInfoPtr& input) { return !input; }
  static void SetToNull(::net::interfaces::ProxyInfoPtr* output) { output->reset(); }

  static const decltype(::net::interfaces::ProxyInfo::proxy_servers)& proxy_servers(
      const ::net::interfaces::ProxyInfoPtr& input) {
    return input->proxy_servers;
  }

  static bool Read(::net::interfaces::ProxyInfo::DataView input, ::net::interfaces::ProxyInfoPtr* output);
};

}  // namespace mojo

#endif  // NET_INTERFACES_PROXY_RESOLVER_SERVICE_MOJOM_H_