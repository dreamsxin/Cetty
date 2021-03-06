#if !defined(CETTY_CHANNEL_SOCKET_DEFAULTSERVERSOCKETCHANNELCONFIG_H)
#define CETTY_CHANNEL_SOCKET_DEFAULTSERVERSOCKETCHANNELCONFIG_H

/*
 * Copyright 2009 Red Hat, Inc.
 *
 * Red Hat licenses this file to you under the Apache License, version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at:
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */
/*
 * Copyright (c) 2010-2011 frankee zhou (frankee.zhou at gmail dot com)
 * Distributed under under the Apache License, version 2.0 (the "License").
 */

#include "cetty/channel/DefaultServerChannelConfig.h"
#include "cetty/channel/socket/ServerSocketChannelConfig.h"

namespace cetty { namespace channel  { namespace socket {


/**
 * A {@link ChannelConfig} for a {@link ServerSocketChannel}.
 *
 */

class DefaultServerSocketChannelConfig
    : public ::cetty::channel::DefaultServerChannelConfig,
      public ::cetty::channel::socket::ServerSocketChannelConfig {
public:
    DefaultServerSocketChannelConfig() {}
    virtual ~DefaultServerSocketChannelConfig() {}
};

}}}

#endif //#if !defined(CETTY_CHANNEL_SOCKET_DEFAULTSERVERSOCKETCHANNELCONFIG_H)
