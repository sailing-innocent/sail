/**
 * @file: include/sail/math/sail.hpp
 * @author: sailing-innocent
 * @create: 2022-10-17
 * @desp: a specific vec4 header
*/
#pragma once
#ifndef SAIL_MATH_VEC4_H_
#define SAIL_MATH_VEC4_H_

#include <sail/math.h>

SAIL_NAMESPACE_BEGIN

class vec4f {
public:
    vec4f(float x=0.0, float y=0.0, float z=0.0, float w=0.0): mData({x,y,z,w}) {}
    vec4f(const vec4f& rhs): mData({rhs[0], rhs[1], rhs[2], rhs[3]}) {}
    virtual ~vec4f() {}
    const float operator[](const size_t index) const { return mData[index]; }
    float& operator[](const size_t index) { return mData[index]; }
    void out(std::vector<float>& outv) const {
        for (auto i = 0; i < 4; i++) {
            outv.push_back(mData[i]);
        }
    }
protected:
    std::array<float,4> mData;
};

typedef vec4f point;
typedef vec4f color;

SAIL_NAMESPACE_END

#endif // SAIL_MATH_VEC4_H_

