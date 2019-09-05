//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_MUTEX_H
#define YIHENG_MUTEX_H

#include <assert.h>
#include <pthread.h>

#include "noncopyable.h"

#include "CurrentThread.h"

// typeof 用在头文件，需要用__typeof__
#define MCHECK(ret) ({__typeof__(ret)  errnum = (ret); \
                        assert(errnum==0); \
                        (void)errnum; \
                    })

namespace yiheng {
    class MutexLock : noncopyable {
    public:
        MutexLock() :holder_(0) {
            MCHECK(pthread_mutex_init(&mutex_, NULL));
        }

        ~MutexLock() {
            pthread_mutex_destroy(&mutex_);
        }

        void lock() {
            MCHECK(pthread_mutex_lock(&mutex_));
            assignHolder();
        }

        void unlock() {
            unassignHolder();
            MCHECK(pthread_mutex_unlock(&mutex));
        }

        void unassignHolder() {
            holder_ = 0;
        }

        void assignHolder() {
            holder_ = static_cast<pid_t>(CurrentThread::tid());
        }

        pthread_mutex_t* getMutexLockPointer() {
            return &mutex_;
        }

    private:
        friend class Condition;

        class UnassignGuard : noncopyable {
        public:
            UnassignGuard(MutexLock &owner) : owner_(owner) {
                owner_.unassignHolder();
            }

            ~UnassignGuard() {
                owner_.assignHolder();
            }

        private:
            MutexLock &owner_;
        };

        pthread_mutex_t mutex_;
        pid_t holder_;

    };

    class MutexLockGuard {
    public:
        MutexLockGuard(MutexLock &mutex) : mutex_(mutex) {
            mutex_.lock();
        }

        ~MutexLockGuard() {
            mutex_.unlock();
        }

    private:
        MutexLock &mutex_;
    };

#define MutexLockGuard(x) error "Missing MutexLockGuard Object name."
}


#endif //YIHENG_MUTEX_H
