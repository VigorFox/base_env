// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "extensions/renderer/lazy_background_page_native_handler.h"

#include "base/bind.h"
#include "content/public/renderer/render_frame.h"
#include "extensions/common/extension_messages.h"
#include "extensions/renderer/extension_frame_helper.h"
#include "extensions/renderer/script_context.h"

namespace extensions {

LazyBackgroundPageNativeHandler::LazyBackgroundPageNativeHandler(
    ScriptContext* context)
    : ObjectBackedNativeHandler(context) {
  RouteFunction(
      "IncrementKeepaliveCount", "tts",
      base::Bind(&LazyBackgroundPageNativeHandler::IncrementKeepaliveCount,
                 base::Unretained(this)));
  RouteFunction(
      "DecrementKeepaliveCount", "tts",
      base::Bind(&LazyBackgroundPageNativeHandler::DecrementKeepaliveCount,
                 base::Unretained(this)));
}

void LazyBackgroundPageNativeHandler::IncrementKeepaliveCount(
    const v8::FunctionCallbackInfo<v8::Value>& args) {
  if (context() && ExtensionFrameHelper::IsContextForEventPage(context())) {
    content::RenderFrame* render_frame = context()->GetRenderFrame();
    render_frame->Send(new ExtensionHostMsg_IncrementLazyKeepaliveCount(
        render_frame->GetRoutingID()));
  }
}

void LazyBackgroundPageNativeHandler::DecrementKeepaliveCount(
    const v8::FunctionCallbackInfo<v8::Value>& args) {
  if (context() && ExtensionFrameHelper::IsContextForEventPage(context())) {
    content::RenderFrame* render_frame = context()->GetRenderFrame();
    render_frame->Send(new ExtensionHostMsg_DecrementLazyKeepaliveCount(
        render_frame->GetRoutingID()));
  }
}

}  // namespace extensions
