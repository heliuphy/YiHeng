//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_NONCOPYABLE_H
#define YIHENG_NONCOPYABLE_H

namespace yiheng
{
    class noncopyable {
    public:
        noncopyable(const noncopyable&) = delete;
        void operator=(const noncopyable&) = delete;
    protected:
        noncopyable() = default;
        ~noncopyable() = default;
    };





}




#endif //YIHENG_NONCOPYABLE_H
