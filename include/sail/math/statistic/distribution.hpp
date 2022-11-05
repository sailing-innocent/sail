#pragma once
/**
 * @file: include/sail/math/statistic/distribution
 * @author: sailing-innocent
 * @create: 2022-11-05
 * @desp: Various Statistical Distribution
*/

#ifndef SAIL_MATH_STATISTIC_DISTRIBUTION_H_
#define SAIL_MATH_STATISTIC_DISTRIBUTION_H_

#include <sail/common.h>
#include <sail/utils/math.hpp>

SAIL_NAMESPACE_BEGIN

template<typename T>
class Distribution 
{
public: 
    Distribution() = default;
    virtual ~Distribution() {};
protected:
    std::vector<T> mParams;
};

class ContinuousDistribution: public Distribution<double> 
{
public:
    ContinuousDistribution() = default;
    virtual ~ContinuousDistribution() {}
    virtual double operator()(double _from, double _to) = 0;
protected:
    std::vector<double> mParams;
};

class UniformDistribution1D: public ContinuousDistribution {
public:
    UniformDistribution1D(double _min = 0.0, double _max = 1.0): mParams({_min,_max}) {}
    ~UniformDistribution1D() override;
    double operator()(double _from, double _to) override;
protected:
    std::vector<double> mParams = {0.0, 1.0};
};

class GaussianDistribution1D: public ContinuousDistribution {
public:
    GaussianDistribution1D(double _mu = 0.0, double _sigma = 1.0): mParams({_mu, _sigma}) {}
    ~GaussianDistribution1D() override;
    double operator()(double _from, double _to) override;
protected:
    std::vector<double> mParams = {0.0, 1.0};
};

SAIL_NAMESPACE_END

#endif // SAIL_MATH_STATISTIC_DISTRIBUTION_H_