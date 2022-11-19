#pragma once 
#ifndef SAILCU_VECTOR_H
#define SAILCU_VECTOR_H

#include <sail/math.h>

SAIL_NAMESPACE_BEGIN

class Vector4dCu: public VectorBase<double, 4>
{
public:
    Vector4dCu() = default;
    explicit Vector4dCu(double _data[4]) {
        for (auto i = 0; i < 4; i++) {
            mData[i] = _data[i];
        }
    }
    Vector4dCu(const Vector4dCu& rhs) {
        for (auto i = 0; i < 4; i++) {
            mData[i] = rhs[i];
        }
    }
    ~Vector4dCu() {}
    const double operator[](const size_t index) const override { return mData[index]; }
    double& operator[] (const size_t index) override { return mData[index]; }
    virtual Vector4dCu operator+(const Vector4dCu& rhs);
private:
    double mData[4] = {0.0, 0.0, 0.0, 0.0};
};

SAIL_NAMESPACE_END

#endif // SAILCU_VECTOR_H