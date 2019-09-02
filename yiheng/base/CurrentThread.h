//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_CURRENTTHREAD_H
#define YIHENG_CURRENTTHREAD_H

#include "yiheng/base/Types.h"

namespace yiheng
{

    namespace CurrentThread
    {
        extern __thread int t_cachedTid; //  __thread是GCC内置的线程局部存储设施。
                                         // __thread变量每一个线程有一份独立实体，
                                         // 各个线程的值互不干扰。
        extern __thread char t_tidString[32];
        extern __thread int t_tidStringLength;
        extern __thread const char* t_threadName;
        void cacheTid();

        inline int tid() {
            if( __builtin_expect(t_cachedTid == 0, 0) ) {
                cacheTid();
            }
            return t_cachedTid;
        }

        inline const char* tidString() {
            return t_tidString;
        }

        inline int tidStringLength() {
            return t_tidStringLength;
        }

        inline const char* name() {
            return t_threadName;
        }

        bool isMainThread();

        void sleepUsec(int64_t usec);

        string trackTrace(bool demangle);
    } // namespace CurrentThread

} //namespace yiheng




#endif //YIHENG_CURRENTTHREAD_H
