//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_COPYABLE_H
#define YIHENG_COPYABLE_H

namespace yiheng
{

// A tag class that can be copied
class copyable
{
protected:
    copyable() = default;
    ~copyable() = default;
};

}

#endif //YIHENG_COPYABLE_H
