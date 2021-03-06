// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _UXR_AGENT_SCHEDULER_FCFS_SCHEDULER_HPP_
#define _UXR_AGENT_SCHEDULER_FCFS_SCHEDULER_HPP_

#include <uxr/agent/scheduler/Scheduler.hpp>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace eprosima {
namespace uxr {

template<class T>
class FCFSScheduler : public Scheduler<T>
{
public:
    FCFSScheduler() : queue_(), mtx_(), cond_var_(), running_cond_(false) {}

    virtual void init() override;
    virtual void deinit() override;
    virtual void push(T&& element, uint8_t priority) override;
    virtual bool pop(T& element) override;

private:
    std::queue<T> queue_;
    std::mutex mtx_;
    std::condition_variable cond_var_;
    std::atomic<bool> running_cond_;
};

template<class T>
inline void FCFSScheduler<T>::init()
{
    running_cond_ = true;
}

template<class T>
inline void FCFSScheduler<T>::deinit()
{
    running_cond_ = false;
    cond_var_.notify_one();
}

template<class T>
inline void FCFSScheduler<T>::push(T&& element, uint8_t priority)
{
    (void) priority;
    std::lock_guard<std::mutex> lock(mtx_);
    queue_.push(std::move(element));
    cond_var_.notify_one();
}

template<class T>
inline bool FCFSScheduler<T>::pop(T& element)
{
    bool rv = false;
    std::unique_lock<std::mutex> lock(mtx_);
    cond_var_.wait(lock, [this] { return (!queue_.empty() || !running_cond_); });
    if (running_cond_)
    {
        element = std::move(queue_.front());
        queue_.pop();
        rv = true;
        cond_var_.notify_one();
    }
    return rv;
}

} // namespace uxr
} // namespace eprosima

#endif //_UXR_AGENT_SCHEDULER_FCFS_SCHEDULER_HPP_
