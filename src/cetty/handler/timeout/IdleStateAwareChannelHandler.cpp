/*
 * Copyright (c) 2010-2011 frankee zhou (frankee.zhou at gmail dot com)
 *
 * Distributed under under the Apache License, version 2.0 (the "License").
 * you may not use this file except in compliance with the License.  
 * You may obtain a copy of the License at:
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#include "cetty/handler/timeout/IdleStateAwareChannelHandler.h"
#include "cetty/handler/timeout/IdleStateEvent.h"

#include "cetty/channel/ChannelHandlerContext.h"

namespace cetty { namespace handler { namespace timeout { 

using namespace cetty::channel;

void IdleStateAwareChannelHandler::handleUpstream(ChannelHandlerContext& ctx,
                                                  const ChannelEvent& e) {
    const IdleStateEvent* evt = dynamic_cast<const IdleStateEvent*>(&e);
    if (evt) {
        channelIdle(ctx, *evt);
    }
    else {
        SimpleChannelHandler::handleUpstream(ctx, e);
    }
}

void IdleStateAwareChannelHandler::channelIdle(ChannelHandlerContext& ctx,
                                               const IdleStateEvent& e) {
    ctx.sendUpstream(e);
}

}}}