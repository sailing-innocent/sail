#include <gtest/gtest.h>
#include <sail/math/statistic.h>

TEST(SAIL_TEST_MATH_STATISTIC, LINEAR_MODEL)
{
    sail::LinearModel lm{};
    const size_t inputDim = lm.inputDim();
    EXPECT_EQ(inputDim, 1);
}

TEST(SAIL_TEST_MATH_STATISTIC, DISTRIBUTION_UNIFORM)
{
    sail::UniformDistribution1D ud;
    EXPECT_DOUBLE_EQ(ud(0.0,0.5), 0.5);
    EXPECT_DOUBLE_EQ(ud(-100.0, 200.0), 1.0);
    EXPECT_DOUBLE_EQ(ud(-1,0.2), 0.2);
    EXPECT_DOUBLE_EQ(ud(0.7, 1.2), 0.3);
}

TEST(SAIL_TEST_MATH_STATISTIC, DISTRIBUTION_GAUSSIAN)
{
    sail::GaussianDistribution1D gd;
    EXPECT_DOUBLE_EQ(gd(-1.0, 1.0), 0.68268545927821156);
    sail::GaussianDistribution1D gd2(3.0, 4.0);
    EXPECT_DOUBLE_EQ(gd2(-1.0, 7.0), 0.68268545927821156);
}