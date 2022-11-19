#include <gtest/gtest.h>
#include <sailcu/vector.h>

TEST(SAILCU_VECTOR_TEST, CREATE_VECTOR)
{
    sail::Vector4dCu vec1;
    EXPECT_DOUBLE_EQ(vec1[0], 0.0);
    EXPECT_DOUBLE_EQ(vec1[1], 0.0);
    EXPECT_DOUBLE_EQ(vec1[2], 0.0);
    EXPECT_DOUBLE_EQ(vec1[3], 0.0);
    double s[4] = {1.0, 2.0, 3.0, 4.0};
    sail::Vector4dCu vec2(s);
    EXPECT_DOUBLE_EQ(vec2[0], 1.0);
    sail::Vector4dCu vec3(vec2);
    EXPECT_DOUBLE_EQ(vec3[1], 2.0);
    double& ref = vec3[2];
    EXPECT_DOUBLE_EQ(ref, 3.0);
    ref = 5.0;
    EXPECT_DOUBLE_EQ(vec3[2], 5.0);
    EXPECT_DOUBLE_EQ(vec2[2], 3.0);
}

TEST(SAILCU_VECTOR_TEST, VECTOR_PARALLEL_ADD)
{
    double s[4] = {1.0, 2.0, 3.0, 4.0};
    sail::Vector4dCu vec1(s);
    sail::Vector4dCu vec2(s);
    sail::Vector4dCu vec3 = vec1 + vec2;
    EXPECT_EQ(vec3[3], 8.0);
}