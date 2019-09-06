//
// Author : He Liu

#ifndef YIHENG_THREAD_H
#define YIHENG_THREAD_H

#include "Atomic.h"
#include "Types.h"

#include <functional>
#include "noncopyable.h"
#include <pthread.h>

namespace yiheng
{
class Thread : noncopyable
{
public:
    typedef std::function<void()> ThreadFunc;
    
    explicit Thread(const ThreadFunc &, const string& name = string());
    ~Thread();

    void start();
    int join(); // return pthread_join()
    
    bool started() const
    {
        return started_;
    }

    // pthread_t pthreadId() const { return prhreadId_; }

    pid_t tid() const { return tid_; }

    const string& name() const { return name_; }

    static int numCreated() { return numCreated_.get(); }


private:
    static void* startThread(void* thread);

    void runInThread();

    bool started_;
    pthread_t pthreadId_;
    pid_t tid_;
    ThreadFunc func_;
    string name_;
    
    static AtomicInt32 numCreated_;
};

} // namespace yiheng

#endif