/**
 * @file: utest/core/stl_vector.test.cc
 * @author: sailing-innocent
 * @create: 2022-10-25
 * @desp: testing vector
 * @done: TODO
*/

#include <gtest/gtest.h>
#include <vector>

TEST(SAIL_TEST_CORE, STL_VECTOR_BASIC)
{
    std::vector<int> vi(3);
    EXPECT_EQ(vi.size(), 3);
    vi[0] = 1;
    vi[1] = 2;
    vi[2] = 3;
    EXPECT_EQ(vi[0], 1);
    EXPECT_EQ(vi.size(), 3);
    EXPECT_EQ(sizeof(vi), 32);
    vi.push_back(4);
    vi.push_back(5);
    EXPECT_EQ(vi.size(), 5);
    int* pvi = vi.data();
    EXPECT_EQ(*(pvi+2),3);
    EXPECT_EQ(sizeof(vi), 32);
    vi.push_back(4);
    vi.push_back(5);
    vi.push_back(4);
    vi.push_back(5);
    EXPECT_EQ(sizeof(vi.data()), 8);
    EXPECT_EQ(sizeof(int*), 8);
}

TEST(SAIL_TEST_CORE, STL_VECTOR_METHOD)
{
    std::vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    EXPECT_EQ(vi[2], 3);
    vi.resize(2);
    EXPECT_EQ(vi.size(), 2);
    EXPECT_EQ(vi[0],1);
    EXPECT_EQ(vi[1],2);
}

TEST(SAIL_TEST_CORE, STL_VECTOR_SWAP)
{
    std::vector<int> vi{1,2,3,4,5,6,7,8,9};
    size_t stride= 3;
    size_t swapI = 0;
    size_t swapJ = 2;
    // make sure swapI < swapJ
    int temp;
    for (auto i = 0; i < stride; i++) {
        temp = vi[swapI*stride+i];
        vi[swapI*stride+i] = vi[swapJ*stride+i];
        vi[swapJ*stride+i] = temp;
    }
    EXPECT_EQ(vi.size(), 9);
    EXPECT_EQ(vi[0], 7);
    EXPECT_EQ(vi[6], 1);
    EXPECT_EQ(vi[8], 3);
}