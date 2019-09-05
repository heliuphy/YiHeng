//
// Author : He Liu

#ifndef YIHENG_THREAD_H
#define YIHENG_THREAD_H

#include <functional>

#include "noncopyable.h"

namespace yiheng
{
class Thread : noncopyable
{
public:
    typedef std::function<void()> ThreadFunc;
    
    explicit Thread(const ThreadFunc &threadFunc);
    ~Thread();

    void join();
    bool started() const
    {
        return started_;
    }


private:
    bool started_;
    bool joined_;
    ThreadFunc threadFunc_;
    pthread_t pthread;
    pid_t tid_;
};

} // namespace yiheng

#endif