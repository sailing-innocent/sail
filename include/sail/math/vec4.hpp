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
    friend std::ostream& operator<<(std::ostream& os, const vec4f& v) {
        os << "[" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << std::endl;
        return os;
    }
    // Arithmetic Operations
    friend vec4f operator*(const float& k, const vec4f& v) {
        // vec4f vec(k * mData[0], k * mData[1], k * mData[2], k * mData[3]);
        vec4f vec(k * v[0], k * v[1], k * v[2], k * v[3]);
        return vec;
    }
    friend float operator*(const vec4f& v1, const vec4f& v2) {
        float sum = 0.0f;
        for (auto i = 0; i < 4; i++) {
            sum += v1[i] * v2[i];
        }
        return sum;
    }
    friend vec4f operator-(const vec4f& v1, const vec4f& v2) {
        vec4f vec(v1[0]-v2[0],v1[1]-v2[1], v1[2]-v2[2], v1[3]-v2[3]);
        return vec;
    }
    float norm() { return sqrt(*this * (*this)); }
    vec4f& normalize() {
        float k = 1/this->norm();
        for (auto d: mData) {
            d*=k;
        }
        return *this;
    }
protected:
    std::array<float,4> mData;
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

#endif // SAIL_MATH_VEC4_H_

