/**
 * @file: include/sail/math/arithmetic/mat
 * @author: sailing-innocent
 * @create: 2022-11-04
 * @desp: My Matrices
 * @notes:
 *  - At the begining we can encrypt eigen for usage, step by step substitude later
*/

#pragma once
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

#include <sail/common.h>


SAIL_NAMESPACE_BEGIN

using MatrixXd = Eigen::MatrixXd;

template<typename DType_, int Rows_, int Cols_>
class Matrix
{
public:
    Matrix() {
        for (auto i = 0; i < Rows_; i++) {
            for (auto j = 0; j < Cols_; j++) {
                mData(i,j) = 1;
            }
        }
    };
    ~Matrix() {}
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    DType_& operator()(size_t i, size_t j) { return mData(i,j); }
protected:
    Eigen::Matrix<DType_, Rows_, Cols_> mData;
};

SAIL_NAMESPACE_END
