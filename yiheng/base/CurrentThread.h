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



    } // namespace CurrentThread



} //namespace yiheng




#endif //YIHENG_CURRENTTHREAD_H
