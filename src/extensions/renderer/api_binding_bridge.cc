// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "extensions/renderer/api_binding_bridge.h"

#include "gin/converter.h"
#include "gin/object_template_builder.h"

namespace extensions {

namespace {

const char kApiObjectKey[] = "extensions::bridge::api_object";
const char kHookInterfaceKey[] = "extensions::bridge::hook_object";

v8::Local<v8::Private> GetPrivatePropertyName(v8::Isolate* isolate,
                                              const char* key) {
  return v8::Private::ForApi(isolate, gin::StringToSymbol(isolate, key));
}

}  // namespace

gin::WrapperInfo APIBindingBridge::kWrapperInfo = {gin::kEmbedderNativeGin};

APIBindingBridge::APIBindingBridge(v8::Local<v8::Context> context,
                                   v8::Local<v8::Value> api_object,
                                   v8::Local<v8::Value> js_hook_interface,
                                   const std::string& extension_id,
                                   const std::string& context_type,
                                   const binding::RunJSFunction& run_js)
    : extension_id_(extension_id),
      context_type_(context_type),
      run_js_(run_js) {
  v8::Isolate* isolate = context->GetIsolate();
  v8::Local<v8::Object> wrapper = GetWrapper(isolate);
  v8::Maybe<bool> result = wrapper->SetPrivate(
      context, GetPrivatePropertyName(isolate, kApiObjectKey), api_object);
  if (!result.IsJust() || !result.FromJust()) {
    NOTREACHED();
    return;
  }
  result = wrapper->SetPrivate(context,
                               GetPrivatePropertyName(isolate,
                                                      kHookInterfaceKey),
                               js_hook_interface);
  DCHECK(result.IsJust() && result.FromJust());
}

APIBindingBridge::~APIBindingBridge() {}

gin::ObjectTemplateBuilder APIBindingBridge::GetObjectTemplateBuilder(
    v8::Isolate* isolate) {
  return Wrappable<APIBindingBridge>::GetObjectTemplateBuilder(isolate)
      .SetMethod("registerCustomHook", &APIBindingBridge::RegisterCustomHook);
}

void APIBindingBridge::RegisterCustomHook(v8::Isolate* isolate,
                                          v8::Local<v8::Function> function) {
  // The object and arguments here are meant to match those passed to the hook
  // functions in binding.js.
  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  v8::Local<v8::Object> hook_object = v8::Object::New(isolate);
  v8::Local<v8::Object> wrapper = GetWrapper(isolate);
  v8::Local<v8::Value> hook_interface =
      wrapper->GetPrivate(
          context, GetPrivatePropertyName(isolate, kHookInterfaceKey))
              .ToLocalChecked();
  v8::Maybe<bool> result = hook_object->CreateDataProperty(
      context, gin::StringToSymbol(isolate, "apiFunctions"), hook_interface);
  if (!result.IsJust() || !result.FromJust())
    return;

  v8::Local<v8::Value> api_object =
      wrapper
           ->GetPrivate(context, GetPrivatePropertyName(isolate, kApiObjectKey))
           .ToLocalChecked();
  result = hook_object->CreateDataProperty(
      context, gin::StringToSymbol(isolate, "compiledApi"), api_object);
  if (!result.IsJust() || !result.FromJust())
    return;

  // TODO(devlin): The binding.js version of these hooks also has a 'schema'
  // property. I wonder if we can factor that out? If not, we'll need to add it
  // here.

  result = hook_object->SetPrototype(context, v8::Null(isolate));
  if (!result.IsJust() || !result.FromJust())
    return;

  v8::Local<v8::String> extension_id =
      gin::StringToSymbol(isolate, extension_id_);
  v8::Local<v8::String> context_type =
      gin::StringToSymbol(isolate, context_type_);
  v8::Local<v8::Value> args[] = {hook_object, extension_id, context_type};
  run_js_.Run(function, context, arraysize(args), args);
}

}  // namespace extensions
