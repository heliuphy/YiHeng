//  
// Author: He Liu (heliu.cpp@gmail.com) 


#ifndef YIHENG_CURRENTTHREAD_H
#define YIHENG_CURRENTTHREAD_H

namespace yiheng
{
    namespace CurrentThread
    {
        extern __thread int t_cachedTid;

        void cacheTid();

        inline int tid() {
            if(t_cachedTid == 0) {
                cacheTid();
            }
            return t_cachedTid;
        }

        bool isMainThread();
    } // namespace CurrentThread
    
} // namespace yiheng


#endif
