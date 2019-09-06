//
// Author: He Liu (heliu.cpp@gmail.com)

#include "CountDownLatch.h"

using namespace yiheng;

void CountDownLatch::wait() {
    MutexLockGuard mutex(mutex_);
    while (count_ > 0)
    {
        cond_.wait();
    }
    
}

void CountDownLatch::countDown() {
    MutexLockGuard mutex(mutex_);
    -- count_;
    if (count_ == 0)
    {
        cond_.notifyAll();
    }
    
}

int CountDownLatch::getCount() const {
    MutexLockGuard mutex(mutex_);
    return count_;
}