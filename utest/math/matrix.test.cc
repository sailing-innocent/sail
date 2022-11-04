#include <gtest/gtest.h>
#include <sail/math/arithmetic/mat.hpp>
#include <sail/math/arithmetic/vec.hpp>
#include <iostream>

TEST(SAIL_TEST, MATRIX_CREATE)
{
    sail::Matrix<double, 3, 2> mat1{};
    EXPECT_EQ(mat1(0,1), 1);
}

TEST(SAIL_TEST, VECTOR_CREATE)
{
    sail::Vector<double, 2> vec1{};
    vec1[0] = 1;
    vec1[1] = 2;
    EXPECT_EQ(vec1[0], 1);
    std::cout << vec1 << std::endl;
    sail::Vector<double, 2> vec2(vec1.data());
    sail::Vector<double, 2> vec3 = vec1 + vec2;
    EXPECT_EQ(vec3[1], 4);
    vec3[1] = 1;
    sail::Vector<double, 2> vec4 = 2 * vec3 + vec1;
    sail::Vector<double, 2> vec5 = vec4 - vec2;
    EXPECT_EQ(vec5[1], 2);
    double norm1s = vec1 * vec1;
    EXPECT_EQ(norm1s, 5);
}