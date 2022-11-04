#include <gtest/gtest.h>
#include <sail/math/statistic.h>

TEST(SAIL_TEST_MATH, LINEAR_MODEL)
{
    sail::LinearModel lm{};
    const size_t inputDim = lm.inputDim();
    EXPECT_EQ(inputDim, 1);
}