#pragma once

/**
 * @file: include/sail/math/arithmetic/vec2i.hpp
 * @author: sailing-innocent
 * @create: 2022-11-04
 * @desp: The vec2i 
*/

#ifndef SAIL_MATH_ARITHMETIC_VEC2I_H_
#define SAIL_MATH_ARITHMETIC_VEC2I_H_

#include <sail/math/arithmetic/vec.hpp>

SAIL_NAMESPACE_BEGIN

class vec2i: public Vector<int,2>
{
public:
    vec2i(int _x = 0, int _y = 0) { mData(0, 0) = _x; mData(1, 0) = _y; }
    vec2i(const vec2i& rhs): Vector<int,2>(rhs) {}
    vec2i(const Vector<int,2>& rhs): Vector<int,2>(rhs) {}
    ~vec2i() {}
    int& x() { return mData(0, 0); }
    int& y() { return mData(1, 0); }
    const int x() const { return mData(0, 0); }
    const int y() const { return mData(1, 0); }
};

SAIL_NAMESPACE_END

#endif // SAIL_MATH_ARITHMETIC_VEC2I_H_