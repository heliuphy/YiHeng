//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_ATOMIC_H
#define YIHENG_ATOMIC_H

#include "noncopyable.h"

#include <stdint.h>

namespace yiheng {
    namespace detail {
        template <typename T>
        class AtomicIntT:noncopyable {
        public:
            AtomicIntT() : value_(0) { }

            T get() {
                return __sync_val_compare_and_swap(&value_, 0, 0);
            }

            T getAddAdd(T x) {
                return __sync_fetch_and_add(&value_, x);
            }

            T addAndGet(T x) {
                return getAddAdd(x) + x;
            }

            T incrementAndGet() {
                return addAndGet(1);
            }

            T decrementAndGet() {
                return addAndGet(-1);
            }

            void add(T x) {
                getAddAdd(x);
            }

            void increment() {
                incrementAndGet();
            }

            void decrement() {
                decrementAndGet();
            }

            T getAndSet(T newVal) {
                return __sync_lock_test_and_set(&value, newVal);
            }
        private:
            volatile T value_;
        }; // class AtomicIntT
    } // namespace yiheng::detail

    typedef detail::AtomicIntT<int32_t> AtomicInt32;
    typedef detail::AtomicIntT<int64_t> AtomicInt64;

} // namespace yiheng


#endif //YIHENG_ATOMIC_H
