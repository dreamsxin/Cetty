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

#include "cetty/util/internal/asio/AsioDeadlineTimeout.h"
#include "cetty/util/internal/asio/AsioDeadlineTimer.h"

namespace cetty { namespace util { namespace internal { namespace asio {

using namespace cetty::util;


AsioDeadlineTimeout::AsioDeadlineTimeout(AsioDeadlineTimer& timer,
                                         boost::asio::io_service& ioService,
                                         TimerTask* task,
                                         boost::int64_t delay)
    : state(TIMER_ACTIVE), timer(timer), deadlineTimer(ioService) {
    BOOST_ASSERT(task);
    deadlineTimer.expires_from_now(boost::posix_time::milliseconds(delay));
    deadlineTimer.async_wait(boost::bind(&AsioDeadlineTimeout::TimerTaskHandler,
                                         this,
                                         boost::asio::placeholders::error,
                                         boost::ref(*task)));
}

AsioDeadlineTimeout::AsioDeadlineTimeout(AsioDeadlineTimer& timer,
                                         boost::asio::io_service& ioService,
                                         const TaskType& task,
                                         boost::int64_t delay)
    : state(TIMER_ACTIVE), timer(timer), deadlineTimer(ioService) {
    deadlineTimer.expires_from_now(boost::posix_time::milliseconds(delay));
    deadlineTimer.async_wait(boost::bind(&AsioDeadlineTimeout::TimerFunctionHandler,
                                         this,
                                         boost::asio::placeholders::error,
                                         task));
}

Timer& AsioDeadlineTimeout::getTimer() const {
    return timer;
}

}}}}
