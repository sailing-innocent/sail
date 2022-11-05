#include <sail/math/statistic/distribution.hpp>

SAIL_NAMESPACE_BEGIN

UniformDistribution1D::~UniformDistribution1D() {}

double UniformDistribution1D::operator()(double _from, double _to) {
    double from = clamp(_from, mParams[0], mParams[1]);
    double to = clamp(_to, mParams[0], mParams[1]);
    return ( to - from ) / ( mParams[1] - mParams[0] ); 
}

double normal_int(double nfrom, double nto) {
    // std::cout << "from: " << nfrom << " to: " << nto;
    const double dx = 0.01;
    const int steps = std::floor((nto - nfrom)/dx);
    double sum = 0;
    double x = nfrom;
    for (auto i = 0; i < steps; i++) {
        x = nfrom + i * dx;
        sum = sum + 1 / std::sqrt(2 * PI) * std::exp(-x*x/2) * dx;
    }
    // std::cout << "SUM: " << sum << std::endl;
    return sum;
}

GaussianDistribution1D::~GaussianDistribution1D() {}

double GaussianDistribution1D::operator()(double _from, double _to) {
    // normalize
    double from = (_from - mParams[0]) / mParams[1];
    double to = (_to - mParams[0]) / mParams[1];
    double res = normal_int(from, to);
    return res;
}

SAIL_NAMESPACE_END
