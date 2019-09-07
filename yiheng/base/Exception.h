//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_EXCEPTION_H
#define YIHENG_EXCEPTION_H

#include "Types.h"
#include <exception>

namespace yiheng
{
    
class Exception : public std::exception
{
public:
    explicit Exception(const char* what);
    explicit Exception(const string& what);
    virtual ~Exception() throw();
    
private:
    /* data */
};




} // namespace yiheng





#endif