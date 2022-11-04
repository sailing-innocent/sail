#pragma once

/**
 * @file: include/sail/math/arithmetic/vec.hpp
 * @author: sailing-innocent
 * @create: 2022-11-04
 * @desp: An Abstract Vector Class
*/
#include <Eigen/Dense>
#include <Eigen/Core>
#include <sail/common.h>
#include <iostream>

SAIL_NAMESPACE_BEGIN

template<typename DType_, int Size_>
class Vector 
{
public:
    Vector() = default;
    Vector(const std::vector<DType_> _data) {
        for (auto i = 0; i < Size_; i++) {
            mData(i, 0) = _data[i];
        }
    }
    Vector(const Eigen::Matrix<DType_,Size_,1> _data) { mData = _data; }
    Vector(const Vector& rhs) { mData = rhs.data(); }
    const Vector& operator=(const Vector& rhs) {
        mData = rhs.data();
    }
    virtual ~Vector() {}
    const DType_ operator[](const size_t index) const { return mData(index, 0); }
    DType_& operator[](const size_t index) { return mData(index,0); }
    const Eigen::Matrix<DType_, Size_,1>& data() const { return mData; }
    friend std::ostream& operator<<(std::ostream& os, const Vector<DType_,Size_>& v) {
        os << "[";
        for (auto i = 0; i < Size_; i++) {
            os << v[i] << ",";
        }   
        os << "]";
        return os;
    }
    friend Vector operator*(const DType_& k, const Vector& v) {
        return Vector(k * v.data());
    }
    virtual DType_ operator*(const Vector<DType_,Size_>& rhs) {
        return mData.transpose() * rhs.data();
    }
    virtual Vector<DType_, Size_> operator+(const Vector<DType_,Size_>& rhs) {
        return Vector(mData + rhs.data());
    }
    virtual Vector<DType_, Size_> operator-(const Vector<DType_,Size_>& rhs) {
        return Vector(mData - rhs.data());
    }
    virtual DType_ norm() { return sqrt(*this * (*this)); }
    virtual Vector<DType_,Size_>& normalize() {
        float k = 1/this->norm();
        for (auto d: mData) {
            d*=k;
        }
        return *this;
    }
    virtual void out(std::vector<DType_>& outv) const {
        for (auto i = 0; i < Size_; i++) {
            outv.push_back(mData(i, 0));
        }
    }
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
protected:
    Eigen::Matrix<DType_,Size_, 1> mData;
};

SAIL_NAMESPACE_END