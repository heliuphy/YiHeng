//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_TYPES_H
#define YIHENG_TYPES_H

#include <stdint.h>
#include <string.h> // for memset();
#include <string>

#ifndef DEBUG

#include <assert.h>

#endif

namespace yiheng
{

using std::string;
inline void memZero(void* p, size_t n)
{
    memset(p, 0, n);
}

// implicit_cast from google protobuf
template <typename To, typename From>
inline To implicit_cast(From const &f)
{
    return f;
}

// use like this: down_cast<T*>(foo);
// so only accept pointers

template <typename To, typename From>
inline To down_cast(From* f)
{
    // copile-time checking
    // it will be optimized when compiling
    if(false)
    {
        implicit_cast<From*, To>(0);
    }

#if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
    assert(f == NULL || dynamic_cast<To>(f) != NULL);
#endif
    return static_cast<To>(f);
}

}

#endif //YIHENG_TYPES_H
