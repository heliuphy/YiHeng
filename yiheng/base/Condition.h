//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_CONDITION_H
#define YIHENG_CONDITION_H


#include <pthread.h>
#include "Mutex.h"

namespace yiheng
{
    class Condition {
    public:
        explicit Condition(MutexLock& mutex) : mutex_(mutex) {
            MCHECK(pthread_cond_init(&cond_, NULL));
        }

        ~Condition() {
            MCHECK(pthread_cond_destroy(&cond_));
        }

        void wait() {
            MutexLock::UnassignGuard unassignGuard(mutex_); // Something like MutexLockGuard. RAII
            MCHECK(pthread_cond_wait(&cond_, mutex_.getMutexLockPointer()));
        }

        void notify() {
            MCHECK(pthread_cond_signal(&cond_));
        }

        void notifyAll() {
            MCHECK(pthread_cond_broadcast(&cond_));
        }
    private:
        MutexLock& mutex_;
        pthread_cond_t cond_;
    }
} // namespace yiheng

#endif