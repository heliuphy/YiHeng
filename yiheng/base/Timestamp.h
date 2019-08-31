//
// Author: He Liu (heliu.cpp@gmail.com)

#ifndef YIHENG_TIMESTAMP_H
#define YIHENG_TIMESTAMP_H

#include "yiheng/base/copyable.h"
#include "yiheng/base/Types.h"

#include <boost/operators.hpp>

namespace yiheng
{

// Time Stamp , in ms resolution
class Timestamp: public yiheng::copyable,
                 public boost::equality_comparable<Timestamp>,
                 public boost::less_than_comparable<Timestamp>
{
public:
    Timestamp()
    : microSecondsSinceEpoch_(0)
    {

    }

    explicit Timestamp(int64_t microSecondsSinceEpochArg)
    : microSecondsSinceEpoch_(microSecondsSinceEpochArg)
    {

    }

    void swap(Timestamp& that)
    {
        std::swap(microSecondsSinceEpoch_, that.microSecondsSinceEpoch_);
    }

    string toString() const;
    string toFormattedString(bool showMicrosecondes = true) const;

    bool valid() const { return microSecondsSinceEpoch_ > 0;}

    int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }
    time_t secondsSinceEpoch() const
    {
        return static_cast<time_t>(microSecondsSinceEpoch_ / kMicroSecondsPerSecond);
    }

    static Timestamp now();
    static Timestamp invalid()
    {
        return Timestamp();
    }

    static Timestamp fromUnixTime(time_t t)
    {
        return fromUnixTime(t, 0);
    }

    static Timestamp fromUnixTime(time_t t, int microseconds)
    {
        return Timestamp(static_cast<int64_t >(t) * kMicroSecondsPerSecond + microseconds);
    }

//    void changeTimezone(int timezone) {
//        microSecondsSinceEpoch_ += timezone * 60 * 60 * kMicroSecondsPerSecond;
//    }

    static const int kMicroSecondsPerSecond = 1000 * 1000; // k means const
private:
    int64_t microSecondsSinceEpoch_;
};

inline bool operator<(Timestamp lhs, Timestamp rhs)
{
    return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();
}

inline bool operator==(Timestamp lhs, Timestamp rhs)
{
    return lhs.microSecondsSinceEpoch() == rhs.microSecondsSinceEpoch();
}

// results in seconds
inline double timeDifference(Timestamp high, Timestamp low)
{
    int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
    return static_cast<double>(diff) / Timestamp::kMicroSecondsPerSecond;
}

// add seconds to a given timestamp, and returns a new timestamp
inline Timestamp addTime(Timestamp timestamp, double seconds)
{
    int64_t delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecondsPerSecond);
    return Timestamp(timestamp.microSecondsSinceEpoch() + delta);
}

}

#endif //YIHENG_TIMESTAMP_H

