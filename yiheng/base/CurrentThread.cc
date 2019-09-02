//
// Author: He Liu (heliu.cpp@gmail.com)

#include "yiheng/base/CurrentThread.h"

#include <cxxabi.h>
#include <execinfo.h>
#include <stdlib.h>

namespace yiheng {

    namespace CurrentThread {
    __thread int t_cachedTid = 0;
    __thread char t_tidString[32];
    __thread int t_tidStringLength = 6;
    __thread const char* t_threadName = "unknown";
    static_assert(std::is_same<int, pid_t>::value, "pid_t should be int");

    string stackTrace(bool demangle) {
        string stack;
        const int max_frames = 200;
        void* frame[max_frames];
        int nptrs = ::backtrace(frame, max_frames);
        char** strings = ::backtrace_symbols(frame, nptrs);
        if (strings) {
            size_t len = 256;
            char* demangled = demangle ? static_cast<char*>(::malloc(len)) : nullptr;
            for (int i = 1; i < nptrs; ++i) {
                if ()
            }
        }

        return stack;
    }

    } // namespace CurrentThread

} //namespace yiheng