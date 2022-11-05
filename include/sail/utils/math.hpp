#pragma once 
/**
 * @file: include/utils/math.hpp
 * @author: sailing-innocent
 * @create: 2022-11-05
 * @desp: the math utility functions
*/

#ifndef SAIL_UTILS_MATH_H_
#define SAIL_UTILS_MATH_H_

#include <sail/common.h>
#include <cmath>
#include <random>

SAIL_NAMESPACE_BEGIN

const double PI = 3.14159265359;

template<typename T>
T clamp(T _x, T _min, T _max) {
    if ( _x < _min ) {
        return _min;
    } else if ( _x > _max ) {
        return _max;
    }
    return _x;
}

SAIL_NAMESPACE_END

#endif // SAIL_UTILS_MATH_H_
