#include <gtest/gtest.h>
#include <sail/math.h>

using namespace sail;

TEST(SAIL_TEST_MATH_VEC4, CREATE_VEC4F)
{
    vec4f v1;
    EXPECT_EQ(v1[0], 0.0);
    v1[2] = 1.0;
    EXPECT_EQ(v1[2], 1.0);
    const float d = v1[3];
    float& dd = v1[3];
    dd = 3.0;
    EXPECT_EQ(v1[3], 3.0);
    EXPECT_EQ(d, 0.0);
    vec4f v2(v1);
    std::cout << v2 << std::endl;
    EXPECT_EQ(v2[3], 3.0);
}
