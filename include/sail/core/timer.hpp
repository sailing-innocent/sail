#pragma once

/**
 * FILE: include/sail/core/timer.hpp
 * AUTHOR: sailing-innocent
 * CREATE: 2022-10-15
 * DESP: The Sail Timer Class Definitions
*/

#ifndef SAIL_CORE_TIMER_H_
#define SAIL_CORE_TIMER_H_

#include <chrono>
#include <iostream>
#include <string>
#include <type_traits>

#include <sail/core/types.hpp>

SAIL_NAMESPACE_BEGIN

/**
 * @class: Timer
 * A timer class for timing code execution
*/
template<typename TimeUnit = std::chrono::milliseconds>
class Timer {
public:
    // ----------------------Typedefs-------------------------
    using ChronoClock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<ChronoClock>;
    // =======================================================
    // Method Description: Constructor
    Timer(): 
        mStartTime(ChronoClock::now())
    { setUnits(); }
    
    // =======================================================
    // Method Description: Constructor
    /// @param inName
    explicit Timer(const std::string& _name): 
        mTimerName(_name + " "),
        mStartTime(ChronoClock::now())
    { setUnits(); }

    // =======================================================
    // Sets the timer name
    void setName(const std::string& _name) { mTimerName = _name + " "; }

    uint64 durationU64(TimePoint p1, TimePoint p2) {
        return static_cast<uint64>(std::chrono::duration_cast<TimeUnit>(p1 - p2).count());
    }
    void tic() noexcept
    {
        mStartTime = ChronoClock::now();
    }
    uint64 toc() {
        const auto duration = durationU64(ChronoClock::now(), mStartTime);
        std::cout << mTimerName << "Elapsed Time = " << duration << mUnit << std::endl;
        return duration;
    }
private:
    void setUnits()
    {
        if (std::is_same<TimeUnit, std::chrono::hours>::value)
        {
            mUnit = " hour(s)";
        }
        else if (std::is_same<TimeUnit, std::chrono::minutes>::value)
        {
            mUnit = " minute(s)";
        }
        else if (std::is_same<TimeUnit, std::chrono::seconds>::value)
        {
            mUnit = " seconde(s)";
        }
        else if (std::is_same<TimeUnit, std::chrono::milliseconds>::value)
        {
            mUnit = " millisecond(s)";
        }
        else if (std::is_same<TimeUnit, std::chrono::nanoseconds>::value)
        {
            mUnit = " nanosecond(s)";
        }
        else {
            mUnit = " TIMEUNIT(S)";
        }
    }

private:
    std::string mTimerName{""};
    std::string mUnit{""};

    TimePoint mStartTime{};
};

SAIL_NAMESPACE_END

#endif // SAIL_CORE_TIMER_H_
