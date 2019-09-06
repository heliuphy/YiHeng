// count down latch
// 倒计时锁定

// Author: Heliu

#ifndef YIHENG_COUNTDOWNLATCH
#define YIHENG_COUNTDOWNLATCH

#include "Mutex.h"
#include "Condition.h"

namespace yiheng
{
    class CountDownLatch
    {
    public:
        explicit CountDownLatch(int count) : 
                                mutex_(), 
                                cond_(mutex_), 
                                count_(count) 
                                {}

    void wait();

    void countDown();

    int getCount() const;



    private:
        mutable MutexLock mutex_;
        Condition cond_;
        int count_;
    };
} // namespace yiheng



#endif