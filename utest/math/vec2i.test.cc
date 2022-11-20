#include <gtest/gtest.h>
#include <sail/math/arithmetic/vec2i.hpp>

using namespace sail;

TEST(SAIL_TEST_MATH_ARITH_VEC2I, CREATE_VEC2I)
{
    vec2i v1;
    EXPECT_EQ(v1[0], 0);
    EXPECT_EQ(v1[1], 0);
    EXPECT_EQ(v1.x(), 0);
    EXPECT_EQ(v1.y(), 0);
    v1[0] = 2;
    EXPECT_EQ(v1.x(), 2);
    v1.y() = 3;
    EXPECT_EQ(v1[1], 3);
}