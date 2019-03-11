// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

define("net/interfaces/proxy_resolver_service.mojom", [
    "mojo/public/js/bindings",
    "mojo/public/js/codec",
    "mojo/public/js/core",
    "mojo/public/js/validator",
    "net/interfaces/host_resolver_service.mojom",
    "url/mojo/url.mojom",
], function(bindings, codec, core, validator, host_resolver_service$, url$) {
  var ProxyScheme = {};
  ProxyScheme.INVALID = 0;
  ProxyScheme.DIRECT = ProxyScheme.INVALID + 1;
  ProxyScheme.HTTP = ProxyScheme.DIRECT + 1;
  ProxyScheme.SOCKS4 = ProxyScheme.HTTP + 1;
  ProxyScheme.SOCKS5 = ProxyScheme.SOCKS4 + 1;
  ProxyScheme.HTTPS = ProxyScheme.SOCKS5 + 1;
  ProxyScheme.QUIC = ProxyScheme.HTTPS + 1;

  ProxyScheme.isKnownEnumValue = function(value) {
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
  };

  ProxyScheme.validate = function(enumValue) {
    var isExtensible = false;
    if (isExtensible || this.isKnownEnumValue(enumValue))
      return validator.validationError.NONE;

    return validator.validationError.UNKNOWN_ENUM_VALUE;
  };

  function ProxyServer(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyServer.prototype.initDefaults_ = function() {
    this.scheme = 0;
    this.port = 0;
    this.host = null;
  };
  ProxyServer.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyServer.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyServer.scheme
    err = messageValidator.validateEnum(offset + codec.kStructHeaderSize + 0, ProxyScheme);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyServer.host
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  ProxyServer.encodedSize = codec.kStructHeaderSize + 16;

  ProxyServer.decode = function(decoder) {
    var packed;
    var val = new ProxyServer();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.scheme = decoder.decodeStruct(codec.Int32);
    val.port = decoder.decodeStruct(codec.Uint16);
    decoder.skip(1);
    decoder.skip(1);
    val.host = decoder.decodeStruct(codec.String);
    return val;
  };

  ProxyServer.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyServer.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.scheme);
    encoder.encodeStruct(codec.Uint16, val.port);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.host);
  };
  function ProxyInfo(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyInfo.prototype.initDefaults_ = function() {
    this.proxy_servers = null;
  };
  ProxyInfo.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyInfo.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 16}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyInfo.proxy_servers
    err = messageValidator.validateArrayPointer(offset + codec.kStructHeaderSize + 0, 8, new codec.PointerTo(ProxyServer), false, [0], 0);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyInfo.encodedSize = codec.kStructHeaderSize + 8;

  ProxyInfo.decode = function(decoder) {
    var packed;
    var val = new ProxyInfo();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.proxy_servers = decoder.decodeArrayPointer(new codec.PointerTo(ProxyServer));
    return val;
  };

  ProxyInfo.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyInfo.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeArrayPointer(new codec.PointerTo(ProxyServer), val.proxy_servers);
  };
  function ProxyResolver_GetProxyForUrl_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolver_GetProxyForUrl_Params.prototype.initDefaults_ = function() {
    this.url = null;
    this.client = new ProxyResolverRequestClientPtr();
  };
  ProxyResolver_GetProxyForUrl_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolver_GetProxyForUrl_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolver_GetProxyForUrl_Params.url
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, url$.Url, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolver_GetProxyForUrl_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolver_GetProxyForUrl_Params.encodedSize = codec.kStructHeaderSize + 16;

  ProxyResolver_GetProxyForUrl_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolver_GetProxyForUrl_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.url = decoder.decodeStructPointer(url$.Url);
    val.client = decoder.decodeStruct(new codec.Interface(ProxyResolverRequestClientPtr));
    return val;
  };

  ProxyResolver_GetProxyForUrl_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolver_GetProxyForUrl_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(url$.Url, val.url);
    encoder.encodeStruct(new codec.Interface(ProxyResolverRequestClientPtr), val.client);
  };
  function ProxyResolverRequestClient_ReportResult_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverRequestClient_ReportResult_Params.prototype.initDefaults_ = function() {
    this.error = 0;
    this.proxy_info = null;
  };
  ProxyResolverRequestClient_ReportResult_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverRequestClient_ReportResult_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate ProxyResolverRequestClient_ReportResult_Params.proxy_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 8, ProxyInfo, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverRequestClient_ReportResult_Params.encodedSize = codec.kStructHeaderSize + 16;

  ProxyResolverRequestClient_ReportResult_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverRequestClient_ReportResult_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.proxy_info = decoder.decodeStructPointer(ProxyInfo);
    return val;
  };

  ProxyResolverRequestClient_ReportResult_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverRequestClient_ReportResult_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStructPointer(ProxyInfo, val.proxy_info);
  };
  function ProxyResolverRequestClient_Alert_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverRequestClient_Alert_Params.prototype.initDefaults_ = function() {
    this.error = null;
  };
  ProxyResolverRequestClient_Alert_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverRequestClient_Alert_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 16}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverRequestClient_Alert_Params.error
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverRequestClient_Alert_Params.encodedSize = codec.kStructHeaderSize + 8;

  ProxyResolverRequestClient_Alert_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverRequestClient_Alert_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.String);
    return val;
  };

  ProxyResolverRequestClient_Alert_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverRequestClient_Alert_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.error);
  };
  function ProxyResolverRequestClient_OnError_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverRequestClient_OnError_Params.prototype.initDefaults_ = function() {
    this.line_number = 0;
    this.error = null;
  };
  ProxyResolverRequestClient_OnError_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverRequestClient_OnError_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate ProxyResolverRequestClient_OnError_Params.error
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverRequestClient_OnError_Params.encodedSize = codec.kStructHeaderSize + 16;

  ProxyResolverRequestClient_OnError_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverRequestClient_OnError_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.line_number = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.error = decoder.decodeStruct(codec.String);
    return val;
  };

  ProxyResolverRequestClient_OnError_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverRequestClient_OnError_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.line_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.error);
  };
  function ProxyResolverRequestClient_ResolveDns_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverRequestClient_ResolveDns_Params.prototype.initDefaults_ = function() {
    this.request_info = null;
    this.client = new host_resolver_service$.HostResolverRequestClientPtr();
  };
  ProxyResolverRequestClient_ResolveDns_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverRequestClient_ResolveDns_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverRequestClient_ResolveDns_Params.request_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, host_resolver_service$.HostResolverRequestInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverRequestClient_ResolveDns_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverRequestClient_ResolveDns_Params.encodedSize = codec.kStructHeaderSize + 16;

  ProxyResolverRequestClient_ResolveDns_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverRequestClient_ResolveDns_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.request_info = decoder.decodeStructPointer(host_resolver_service$.HostResolverRequestInfo);
    val.client = decoder.decodeStruct(new codec.Interface(host_resolver_service$.HostResolverRequestClientPtr));
    return val;
  };

  ProxyResolverRequestClient_ResolveDns_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverRequestClient_ResolveDns_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(host_resolver_service$.HostResolverRequestInfo, val.request_info);
    encoder.encodeStruct(new codec.Interface(host_resolver_service$.HostResolverRequestClientPtr), val.client);
  };
  function ProxyResolverFactory_CreateResolver_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverFactory_CreateResolver_Params.prototype.initDefaults_ = function() {
    this.pac_script = null;
    this.resolver = new bindings.InterfaceRequest();
    this.client = new ProxyResolverFactoryRequestClientPtr();
  };
  ProxyResolverFactory_CreateResolver_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverFactory_CreateResolver_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 32}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverFactory_CreateResolver_Params.pac_script
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverFactory_CreateResolver_Params.resolver
    err = messageValidator.validateInterfaceRequest(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverFactory_CreateResolver_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 12, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverFactory_CreateResolver_Params.encodedSize = codec.kStructHeaderSize + 24;

  ProxyResolverFactory_CreateResolver_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverFactory_CreateResolver_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.pac_script = decoder.decodeStruct(codec.String);
    val.resolver = decoder.decodeStruct(codec.InterfaceRequest);
    val.client = decoder.decodeStruct(new codec.Interface(ProxyResolverFactoryRequestClientPtr));
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  ProxyResolverFactory_CreateResolver_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverFactory_CreateResolver_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.pac_script);
    encoder.encodeStruct(codec.InterfaceRequest, val.resolver);
    encoder.encodeStruct(new codec.Interface(ProxyResolverFactoryRequestClientPtr), val.client);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function ProxyResolverFactoryRequestClient_ReportResult_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverFactoryRequestClient_ReportResult_Params.prototype.initDefaults_ = function() {
    this.error = 0;
  };
  ProxyResolverFactoryRequestClient_ReportResult_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverFactoryRequestClient_ReportResult_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 16}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    return validator.validationError.NONE;
  };

  ProxyResolverFactoryRequestClient_ReportResult_Params.encodedSize = codec.kStructHeaderSize + 8;

  ProxyResolverFactoryRequestClient_ReportResult_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverFactoryRequestClient_ReportResult_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    return val;
  };

  ProxyResolverFactoryRequestClient_ReportResult_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverFactoryRequestClient_ReportResult_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.error);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
  };
  function ProxyResolverFactoryRequestClient_Alert_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverFactoryRequestClient_Alert_Params.prototype.initDefaults_ = function() {
    this.error = null;
  };
  ProxyResolverFactoryRequestClient_Alert_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverFactoryRequestClient_Alert_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 16}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverFactoryRequestClient_Alert_Params.error
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 0, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverFactoryRequestClient_Alert_Params.encodedSize = codec.kStructHeaderSize + 8;

  ProxyResolverFactoryRequestClient_Alert_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverFactoryRequestClient_Alert_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.error = decoder.decodeStruct(codec.String);
    return val;
  };

  ProxyResolverFactoryRequestClient_Alert_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverFactoryRequestClient_Alert_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.String, val.error);
  };
  function ProxyResolverFactoryRequestClient_OnError_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverFactoryRequestClient_OnError_Params.prototype.initDefaults_ = function() {
    this.line_number = 0;
    this.error = null;
  };
  ProxyResolverFactoryRequestClient_OnError_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverFactoryRequestClient_OnError_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;



    
    // validate ProxyResolverFactoryRequestClient_OnError_Params.error
    err = messageValidator.validateStringPointer(offset + codec.kStructHeaderSize + 8, false)
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverFactoryRequestClient_OnError_Params.encodedSize = codec.kStructHeaderSize + 16;

  ProxyResolverFactoryRequestClient_OnError_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverFactoryRequestClient_OnError_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.line_number = decoder.decodeStruct(codec.Int32);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    decoder.skip(1);
    val.error = decoder.decodeStruct(codec.String);
    return val;
  };

  ProxyResolverFactoryRequestClient_OnError_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverFactoryRequestClient_OnError_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStruct(codec.Int32, val.line_number);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.skip(1);
    encoder.encodeStruct(codec.String, val.error);
  };
  function ProxyResolverFactoryRequestClient_ResolveDns_Params(values) {
    this.initDefaults_();
    this.initFields_(values);
  }


  ProxyResolverFactoryRequestClient_ResolveDns_Params.prototype.initDefaults_ = function() {
    this.request_info = null;
    this.client = new host_resolver_service$.HostResolverRequestClientPtr();
  };
  ProxyResolverFactoryRequestClient_ResolveDns_Params.prototype.initFields_ = function(fields) {
    for(var field in fields) {
        if (this.hasOwnProperty(field))
          this[field] = fields[field];
    }
  };

  ProxyResolverFactoryRequestClient_ResolveDns_Params.validate = function(messageValidator, offset) {
    var err;
    err = messageValidator.validateStructHeader(offset, codec.kStructHeaderSize);
    if (err !== validator.validationError.NONE)
        return err;

    var kVersionSizes = [
      {version: 0, numBytes: 24}
    ];
    err = messageValidator.validateStructVersion(offset, kVersionSizes);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverFactoryRequestClient_ResolveDns_Params.request_info
    err = messageValidator.validateStructPointer(offset + codec.kStructHeaderSize + 0, host_resolver_service$.HostResolverRequestInfo, false);
    if (err !== validator.validationError.NONE)
        return err;


    
    // validate ProxyResolverFactoryRequestClient_ResolveDns_Params.client
    err = messageValidator.validateInterface(offset + codec.kStructHeaderSize + 8, false);
    if (err !== validator.validationError.NONE)
        return err;

    return validator.validationError.NONE;
  };

  ProxyResolverFactoryRequestClient_ResolveDns_Params.encodedSize = codec.kStructHeaderSize + 16;

  ProxyResolverFactoryRequestClient_ResolveDns_Params.decode = function(decoder) {
    var packed;
    var val = new ProxyResolverFactoryRequestClient_ResolveDns_Params();
    var numberOfBytes = decoder.readUint32();
    var version = decoder.readUint32();
    val.request_info = decoder.decodeStructPointer(host_resolver_service$.HostResolverRequestInfo);
    val.client = decoder.decodeStruct(new codec.Interface(host_resolver_service$.HostResolverRequestClientPtr));
    return val;
  };

  ProxyResolverFactoryRequestClient_ResolveDns_Params.encode = function(encoder, val) {
    var packed;
    encoder.writeUint32(ProxyResolverFactoryRequestClient_ResolveDns_Params.encodedSize);
    encoder.writeUint32(0);
    encoder.encodeStructPointer(host_resolver_service$.HostResolverRequestInfo, val.request_info);
    encoder.encodeStruct(new codec.Interface(host_resolver_service$.HostResolverRequestClientPtr), val.client);
  };
  var kProxyResolver_GetProxyForUrl_Name = 0;

  function ProxyResolverPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ProxyResolver,
                                                   handleOrPtrInfo);
  }

  function ProxyResolverProxy(receiver) {
    this.receiver_ = receiver;
  }
  ProxyResolverPtr.prototype.getProxyForUrl = function() {
    return ProxyResolverProxy.prototype.getProxyForUrl
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverProxy.prototype.getProxyForUrl = function(url, client) {
    var params = new ProxyResolver_GetProxyForUrl_Params();
    params.url = url;
    params.client = client;
    var builder = new codec.MessageBuilder(
        kProxyResolver_GetProxyForUrl_Name,
        codec.align(ProxyResolver_GetProxyForUrl_Params.encodedSize));
    builder.encodeStruct(ProxyResolver_GetProxyForUrl_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ProxyResolverStub(delegate) {
    this.delegate_ = delegate;
  }
  ProxyResolverStub.prototype.getProxyForUrl = function(url, client) {
    return this.delegate_ && this.delegate_.getProxyForUrl && this.delegate_.getProxyForUrl(url, client);
  }

  ProxyResolverStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kProxyResolver_GetProxyForUrl_Name:
      var params = reader.decodeStruct(ProxyResolver_GetProxyForUrl_Params);
      this.getProxyForUrl(params.url, params.client);
      return true;
    default:
      return false;
    }
  };

  ProxyResolverStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateProxyResolverRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kProxyResolver_GetProxyForUrl_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolver_GetProxyForUrl_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateProxyResolverResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var ProxyResolver = {
    name: 'net::interfaces::ProxyResolver',
    ptrClass: ProxyResolverPtr,
    proxyClass: ProxyResolverProxy,
    stubClass: ProxyResolverStub,
    validateRequest: validateProxyResolverRequest,
    validateResponse: null,
  };
  ProxyResolverStub.prototype.validator = validateProxyResolverRequest;
  ProxyResolverProxy.prototype.validator = null;
  var kProxyResolverRequestClient_ReportResult_Name = 0;
  var kProxyResolverRequestClient_Alert_Name = 1;
  var kProxyResolverRequestClient_OnError_Name = 2;
  var kProxyResolverRequestClient_ResolveDns_Name = 3;

  function ProxyResolverRequestClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ProxyResolverRequestClient,
                                                   handleOrPtrInfo);
  }

  function ProxyResolverRequestClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  ProxyResolverRequestClientPtr.prototype.reportResult = function() {
    return ProxyResolverRequestClientProxy.prototype.reportResult
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverRequestClientProxy.prototype.reportResult = function(error, proxy_info) {
    var params = new ProxyResolverRequestClient_ReportResult_Params();
    params.error = error;
    params.proxy_info = proxy_info;
    var builder = new codec.MessageBuilder(
        kProxyResolverRequestClient_ReportResult_Name,
        codec.align(ProxyResolverRequestClient_ReportResult_Params.encodedSize));
    builder.encodeStruct(ProxyResolverRequestClient_ReportResult_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ProxyResolverRequestClientPtr.prototype.alert = function() {
    return ProxyResolverRequestClientProxy.prototype.alert
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverRequestClientProxy.prototype.alert = function(error) {
    var params = new ProxyResolverRequestClient_Alert_Params();
    params.error = error;
    var builder = new codec.MessageBuilder(
        kProxyResolverRequestClient_Alert_Name,
        codec.align(ProxyResolverRequestClient_Alert_Params.encodedSize));
    builder.encodeStruct(ProxyResolverRequestClient_Alert_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ProxyResolverRequestClientPtr.prototype.onError = function() {
    return ProxyResolverRequestClientProxy.prototype.onError
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverRequestClientProxy.prototype.onError = function(line_number, error) {
    var params = new ProxyResolverRequestClient_OnError_Params();
    params.line_number = line_number;
    params.error = error;
    var builder = new codec.MessageBuilder(
        kProxyResolverRequestClient_OnError_Name,
        codec.align(ProxyResolverRequestClient_OnError_Params.encodedSize));
    builder.encodeStruct(ProxyResolverRequestClient_OnError_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ProxyResolverRequestClientPtr.prototype.resolveDns = function() {
    return ProxyResolverRequestClientProxy.prototype.resolveDns
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverRequestClientProxy.prototype.resolveDns = function(request_info, client) {
    var params = new ProxyResolverRequestClient_ResolveDns_Params();
    params.request_info = request_info;
    params.client = client;
    var builder = new codec.MessageBuilder(
        kProxyResolverRequestClient_ResolveDns_Name,
        codec.align(ProxyResolverRequestClient_ResolveDns_Params.encodedSize));
    builder.encodeStruct(ProxyResolverRequestClient_ResolveDns_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ProxyResolverRequestClientStub(delegate) {
    this.delegate_ = delegate;
  }
  ProxyResolverRequestClientStub.prototype.reportResult = function(error, proxy_info) {
    return this.delegate_ && this.delegate_.reportResult && this.delegate_.reportResult(error, proxy_info);
  }
  ProxyResolverRequestClientStub.prototype.alert = function(error) {
    return this.delegate_ && this.delegate_.alert && this.delegate_.alert(error);
  }
  ProxyResolverRequestClientStub.prototype.onError = function(line_number, error) {
    return this.delegate_ && this.delegate_.onError && this.delegate_.onError(line_number, error);
  }
  ProxyResolverRequestClientStub.prototype.resolveDns = function(request_info, client) {
    return this.delegate_ && this.delegate_.resolveDns && this.delegate_.resolveDns(request_info, client);
  }

  ProxyResolverRequestClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kProxyResolverRequestClient_ReportResult_Name:
      var params = reader.decodeStruct(ProxyResolverRequestClient_ReportResult_Params);
      this.reportResult(params.error, params.proxy_info);
      return true;
    case kProxyResolverRequestClient_Alert_Name:
      var params = reader.decodeStruct(ProxyResolverRequestClient_Alert_Params);
      this.alert(params.error);
      return true;
    case kProxyResolverRequestClient_OnError_Name:
      var params = reader.decodeStruct(ProxyResolverRequestClient_OnError_Params);
      this.onError(params.line_number, params.error);
      return true;
    case kProxyResolverRequestClient_ResolveDns_Name:
      var params = reader.decodeStruct(ProxyResolverRequestClient_ResolveDns_Params);
      this.resolveDns(params.request_info, params.client);
      return true;
    default:
      return false;
    }
  };

  ProxyResolverRequestClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateProxyResolverRequestClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kProxyResolverRequestClient_ReportResult_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverRequestClient_ReportResult_Params;
      break;
      case kProxyResolverRequestClient_Alert_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverRequestClient_Alert_Params;
      break;
      case kProxyResolverRequestClient_OnError_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverRequestClient_OnError_Params;
      break;
      case kProxyResolverRequestClient_ResolveDns_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverRequestClient_ResolveDns_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateProxyResolverRequestClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var ProxyResolverRequestClient = {
    name: 'net::interfaces::ProxyResolverRequestClient',
    ptrClass: ProxyResolverRequestClientPtr,
    proxyClass: ProxyResolverRequestClientProxy,
    stubClass: ProxyResolverRequestClientStub,
    validateRequest: validateProxyResolverRequestClientRequest,
    validateResponse: null,
  };
  ProxyResolverRequestClientStub.prototype.validator = validateProxyResolverRequestClientRequest;
  ProxyResolverRequestClientProxy.prototype.validator = null;
  var kProxyResolverFactory_CreateResolver_Name = 0;

  function ProxyResolverFactoryPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ProxyResolverFactory,
                                                   handleOrPtrInfo);
  }

  function ProxyResolverFactoryProxy(receiver) {
    this.receiver_ = receiver;
  }
  ProxyResolverFactoryPtr.prototype.createResolver = function() {
    return ProxyResolverFactoryProxy.prototype.createResolver
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverFactoryProxy.prototype.createResolver = function(pac_script, resolver, client) {
    var params = new ProxyResolverFactory_CreateResolver_Params();
    params.pac_script = pac_script;
    params.resolver = resolver;
    params.client = client;
    var builder = new codec.MessageBuilder(
        kProxyResolverFactory_CreateResolver_Name,
        codec.align(ProxyResolverFactory_CreateResolver_Params.encodedSize));
    builder.encodeStruct(ProxyResolverFactory_CreateResolver_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ProxyResolverFactoryStub(delegate) {
    this.delegate_ = delegate;
  }
  ProxyResolverFactoryStub.prototype.createResolver = function(pac_script, resolver, client) {
    return this.delegate_ && this.delegate_.createResolver && this.delegate_.createResolver(pac_script, resolver, client);
  }

  ProxyResolverFactoryStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kProxyResolverFactory_CreateResolver_Name:
      var params = reader.decodeStruct(ProxyResolverFactory_CreateResolver_Params);
      this.createResolver(params.pac_script, params.resolver, params.client);
      return true;
    default:
      return false;
    }
  };

  ProxyResolverFactoryStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateProxyResolverFactoryRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kProxyResolverFactory_CreateResolver_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverFactory_CreateResolver_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateProxyResolverFactoryResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var ProxyResolverFactory = {
    name: 'net::interfaces::ProxyResolverFactory',
    ptrClass: ProxyResolverFactoryPtr,
    proxyClass: ProxyResolverFactoryProxy,
    stubClass: ProxyResolverFactoryStub,
    validateRequest: validateProxyResolverFactoryRequest,
    validateResponse: null,
  };
  ProxyResolverFactoryStub.prototype.validator = validateProxyResolverFactoryRequest;
  ProxyResolverFactoryProxy.prototype.validator = null;
  var kProxyResolverFactoryRequestClient_ReportResult_Name = 0;
  var kProxyResolverFactoryRequestClient_Alert_Name = 1;
  var kProxyResolverFactoryRequestClient_OnError_Name = 2;
  var kProxyResolverFactoryRequestClient_ResolveDns_Name = 3;

  function ProxyResolverFactoryRequestClientPtr(handleOrPtrInfo) {
    this.ptr = new bindings.InterfacePtrController(ProxyResolverFactoryRequestClient,
                                                   handleOrPtrInfo);
  }

  function ProxyResolverFactoryRequestClientProxy(receiver) {
    this.receiver_ = receiver;
  }
  ProxyResolverFactoryRequestClientPtr.prototype.reportResult = function() {
    return ProxyResolverFactoryRequestClientProxy.prototype.reportResult
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverFactoryRequestClientProxy.prototype.reportResult = function(error) {
    var params = new ProxyResolverFactoryRequestClient_ReportResult_Params();
    params.error = error;
    var builder = new codec.MessageBuilder(
        kProxyResolverFactoryRequestClient_ReportResult_Name,
        codec.align(ProxyResolverFactoryRequestClient_ReportResult_Params.encodedSize));
    builder.encodeStruct(ProxyResolverFactoryRequestClient_ReportResult_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ProxyResolverFactoryRequestClientPtr.prototype.alert = function() {
    return ProxyResolverFactoryRequestClientProxy.prototype.alert
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverFactoryRequestClientProxy.prototype.alert = function(error) {
    var params = new ProxyResolverFactoryRequestClient_Alert_Params();
    params.error = error;
    var builder = new codec.MessageBuilder(
        kProxyResolverFactoryRequestClient_Alert_Name,
        codec.align(ProxyResolverFactoryRequestClient_Alert_Params.encodedSize));
    builder.encodeStruct(ProxyResolverFactoryRequestClient_Alert_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ProxyResolverFactoryRequestClientPtr.prototype.onError = function() {
    return ProxyResolverFactoryRequestClientProxy.prototype.onError
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverFactoryRequestClientProxy.prototype.onError = function(line_number, error) {
    var params = new ProxyResolverFactoryRequestClient_OnError_Params();
    params.line_number = line_number;
    params.error = error;
    var builder = new codec.MessageBuilder(
        kProxyResolverFactoryRequestClient_OnError_Name,
        codec.align(ProxyResolverFactoryRequestClient_OnError_Params.encodedSize));
    builder.encodeStruct(ProxyResolverFactoryRequestClient_OnError_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };
  ProxyResolverFactoryRequestClientPtr.prototype.resolveDns = function() {
    return ProxyResolverFactoryRequestClientProxy.prototype.resolveDns
        .apply(this.ptr.getProxy(), arguments);
  };

  ProxyResolverFactoryRequestClientProxy.prototype.resolveDns = function(request_info, client) {
    var params = new ProxyResolverFactoryRequestClient_ResolveDns_Params();
    params.request_info = request_info;
    params.client = client;
    var builder = new codec.MessageBuilder(
        kProxyResolverFactoryRequestClient_ResolveDns_Name,
        codec.align(ProxyResolverFactoryRequestClient_ResolveDns_Params.encodedSize));
    builder.encodeStruct(ProxyResolverFactoryRequestClient_ResolveDns_Params, params);
    var message = builder.finish();
    this.receiver_.accept(message);
  };

  function ProxyResolverFactoryRequestClientStub(delegate) {
    this.delegate_ = delegate;
  }
  ProxyResolverFactoryRequestClientStub.prototype.reportResult = function(error) {
    return this.delegate_ && this.delegate_.reportResult && this.delegate_.reportResult(error);
  }
  ProxyResolverFactoryRequestClientStub.prototype.alert = function(error) {
    return this.delegate_ && this.delegate_.alert && this.delegate_.alert(error);
  }
  ProxyResolverFactoryRequestClientStub.prototype.onError = function(line_number, error) {
    return this.delegate_ && this.delegate_.onError && this.delegate_.onError(line_number, error);
  }
  ProxyResolverFactoryRequestClientStub.prototype.resolveDns = function(request_info, client) {
    return this.delegate_ && this.delegate_.resolveDns && this.delegate_.resolveDns(request_info, client);
  }

  ProxyResolverFactoryRequestClientStub.prototype.accept = function(message) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    case kProxyResolverFactoryRequestClient_ReportResult_Name:
      var params = reader.decodeStruct(ProxyResolverFactoryRequestClient_ReportResult_Params);
      this.reportResult(params.error);
      return true;
    case kProxyResolverFactoryRequestClient_Alert_Name:
      var params = reader.decodeStruct(ProxyResolverFactoryRequestClient_Alert_Params);
      this.alert(params.error);
      return true;
    case kProxyResolverFactoryRequestClient_OnError_Name:
      var params = reader.decodeStruct(ProxyResolverFactoryRequestClient_OnError_Params);
      this.onError(params.line_number, params.error);
      return true;
    case kProxyResolverFactoryRequestClient_ResolveDns_Name:
      var params = reader.decodeStruct(ProxyResolverFactoryRequestClient_ResolveDns_Params);
      this.resolveDns(params.request_info, params.client);
      return true;
    default:
      return false;
    }
  };

  ProxyResolverFactoryRequestClientStub.prototype.acceptWithResponder =
      function(message, responder) {
    var reader = new codec.MessageReader(message);
    switch (reader.messageName) {
    default:
      return Promise.reject(Error("Unhandled message: " + reader.messageName));
    }
  };

  function validateProxyResolverFactoryRequestClientRequest(messageValidator) {
    var message = messageValidator.message;
    var paramsClass = null;
    switch (message.getName()) {
      case kProxyResolverFactoryRequestClient_ReportResult_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverFactoryRequestClient_ReportResult_Params;
      break;
      case kProxyResolverFactoryRequestClient_Alert_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverFactoryRequestClient_Alert_Params;
      break;
      case kProxyResolverFactoryRequestClient_OnError_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverFactoryRequestClient_OnError_Params;
      break;
      case kProxyResolverFactoryRequestClient_ResolveDns_Name:
        if (!message.expectsResponse() && !message.isResponse())
          paramsClass = ProxyResolverFactoryRequestClient_ResolveDns_Params;
      break;
    }
    if (paramsClass === null)
      return validator.validationError.NONE;
    return paramsClass.validate(messageValidator, messageValidator.message.getHeaderNumBytes());
  }

  function validateProxyResolverFactoryRequestClientResponse(messageValidator) {
    return validator.validationError.NONE;
  }

  var ProxyResolverFactoryRequestClient = {
    name: 'net::interfaces::ProxyResolverFactoryRequestClient',
    ptrClass: ProxyResolverFactoryRequestClientPtr,
    proxyClass: ProxyResolverFactoryRequestClientProxy,
    stubClass: ProxyResolverFactoryRequestClientStub,
    validateRequest: validateProxyResolverFactoryRequestClientRequest,
    validateResponse: null,
  };
  ProxyResolverFactoryRequestClientStub.prototype.validator = validateProxyResolverFactoryRequestClientRequest;
  ProxyResolverFactoryRequestClientProxy.prototype.validator = null;

  var exports = {};
  exports.ProxyScheme = ProxyScheme;
  exports.ProxyServer = ProxyServer;
  exports.ProxyInfo = ProxyInfo;
  exports.ProxyResolver = ProxyResolver;
  exports.ProxyResolverPtr = ProxyResolverPtr;
  exports.ProxyResolverRequestClient = ProxyResolverRequestClient;
  exports.ProxyResolverRequestClientPtr = ProxyResolverRequestClientPtr;
  exports.ProxyResolverFactory = ProxyResolverFactory;
  exports.ProxyResolverFactoryPtr = ProxyResolverFactoryPtr;
  exports.ProxyResolverFactoryRequestClient = ProxyResolverFactoryRequestClient;
  exports.ProxyResolverFactoryRequestClientPtr = ProxyResolverFactoryRequestClientPtr;

  return exports;
});