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

TEST(SAIL_TEST_MATH_VEC4, VEC4F_ARITH)
{
    vec4f v1;
    vec4f v2(1.0f, 0.0f, 0.0f, 0.0f);
    vec4f v3 = 2.0 * v2;
    EXPECT_EQ(v3[0], 2.0f);
    vec4f v4(1.0f, 3.0f, 2.0f, 1.0f);
    vec4f v5(2.0f, 2.0f, 0.0f, 1.0f);
    float res = v4 * v5;
    EXPECT_EQ(res, 9);
    vec4f v6 = v5 - v4;
    EXPECT_EQ(v6[0], 1.0f);
    EXPECT_EQ(v5.norm(), 3);
}

TEST(SAIL_TEST_MATH_VEC4, POINT_ARITH)
{
    point p1(1.0f, 2.0f, 3.0f, 1.0f);
    point p2(2.0f, 3.0f, 1.0f, 1.0f);
    std::cout << p1 << std::endl;
    vec4f p12 = p2 - p1;
    std::cout << p12 << std::endl;
    EXPECT_EQ(p12[3], 0.0);

    point p3 = p1 + p12;
    EXPECT_EQ(p3[2], 1.0);
    point p4 = p1 - p12;
    EXPECT_EQ(p3[0], 2.0f);
    EXPECT_EQ(p3[2], 1.0f);
}

TEST(SAIL_TEST_MATH_VEC4, LINE_DET)
{
    point p1(0.0f, 0.0f, 0.0f, 1.0f);
    point p2(0.0f, 1.0f, 0.0f, 1.0f);
    point p(0.5f, 1.0f, 0.0f, 1.0f);
    vec4f p1p2 = p2 - p1;
    vec4f p1p = p - p1;
    float det = (p1p - (p1p2 * p1p)/(p1p2 * p1p2) * p1p2).norm();
    EXPECT_EQ(det, 0.5f);
}