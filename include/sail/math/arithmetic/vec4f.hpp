#pragma once

/**
 * @file: include/sail/math/arithmetic/vec4f.hpp
 * @author: sailing-innocent
 * @create: 2022-11-04
 * @desp: Refact the vec4f
*/

#ifndef SAIL_MATH_ARITHMETIC_VEC4F_H_
#define SAIL_MATH_ARITHMETIC_VEC4F_H_

#include <sail/math/arithmetic/vec.hpp>

SAIL_NAMESPACE_BEGIN

class vec4f: public Vector<float,4>
{
public:
    vec4f(float x=0.0, float y=0.0, float z=0.0, float w=0.0) {
        mData(0, 0) = x;
        mData(1, 0) = y;
        mData(2, 0) = z;
        mData(3, 0) = w;
    }
    vec4f(const vec4f& rhs): Vector<float,4>(rhs) {}
    vec4f(const Vector<float,4>& rhs): Vector<float,4>(rhs) {}
    const vec4f& operator=(const vec4f& rhs) {
        mData = rhs.data();
    }
    ~vec4f() {}
};

class point: public vec4f {
public:
    point(float x=0.0, float y=0.0, float z=0.0, float w=1.0): vec4f(x/w,y/w,z/w,1.0) {}
    point(const vec4f& rhs): vec4f(rhs) {}
    ~point() {}
    friend point operator+(const point& p, const vec4f& v) {
        point np(p[0]+v[0], p[1]+v[1],p[2]+v[2], 1.0f);
        return np;
    }
};

typedef vec4f color;


SAIL_NAMESPACE_END

#endif // SAIL_MATH_ARITHMETIC_VEC4F_H_