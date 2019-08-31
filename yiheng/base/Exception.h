//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_EXCEPTION_H
#define YIHENG_EXCEPTION_H

#include "yiheng/base/Types.h"
#include <exception>

namespace yiheng
{

class Exception: public std::exception
{
public:
    Exception(string what);
    ~Exception() noexcept override = default; // noexcept 不会抛出异常
                                              // override 必须重载基类函数( 用以检查函数参数等是否一致 )
                                              // 让编译器提供一份默认析构函数
    const char* what() const noexcept override {
        return message_.c_str();
    }

    const char* stackTrace() const noexcept {
        return stack_.c_str();
    }
private:
    string message_;
    string stack_;
};

} //namespace yiheng

#endif //YIHENG_EXCEPTION_H
