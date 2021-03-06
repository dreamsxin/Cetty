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

#include "cetty/channel/Channel.h"
#include "cetty/channel/ChannelFuture.h"
#include "cetty/channel/ChannelFutureListener.h"

namespace cetty { namespace channel {

class CloseChannelListener : public ChannelFutureListener {
public:
    void operationComplete(const ChannelFuturePtr& future) {
        future->getChannel().close();
    }

    std::string toString() const { return "CloseChannelListener"; }
};

class CloseOnFailureChannelListener : public ChannelFutureListener {
public:
    void operationComplete(const ChannelFuturePtr& future) {
		if (future && !future->isSuccess()) {
			future->getChannel().close();
		}
	}

    std::string toString() const { return "CloseOnFailureChannelListener"; }
};

ChannelFutureListener* ChannelFutureListener::CLOSE = new CloseChannelListener;
ChannelFutureListener* ChannelFutureListener::CLOSE_ON_FAILURE = new CloseOnFailureChannelListener;

}}