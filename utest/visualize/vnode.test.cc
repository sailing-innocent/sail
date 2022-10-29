#include <gtest/gtest.h>
#include <sail/visualize.h>

using namespace sail;

TEST(SAIL_TEST_VIS, CREATE_VTRIANGLE)
{
    point p1(0.5, 0.0, 0.0, 1.0);
    point p2(-0.5, 0.0, 0.0, 1.0);
    point p3(0.0, 0.5, 0.0, 1.0);
    VTriangle vtr(p1, p2, p3);
    EXPECT_EQ(p1[0], 0.5);
    std::vector<float> vf;
    std::vector<uint16_t> iu;
    vtr.genING(vf, iu);
    EXPECT_EQ(vf.size(), 24);
    EXPECT_EQ(iu.size(), 3);
    EXPECT_EQ(vf[0], 0.5);
}

TEST(TEST_SAIL_VIS, CREATE_VNODE)
{
    std::cout << "Constuct Parent" << std::endl;
    VisNode v;
    EXPECT_EQ(v.subNodeCount(), 0);
    point p1(-0.5, 0.0, 0.0, 1.0);
    point p2(0.5, 0.0, 0.0, 1.0);
    point p3(0.0, 0.5, 0.0, 1.0);
    std::cout << "Constuct Triangle" << std::endl;
    VTriangle vtr1(p1, p2, p3);

    v.append(vtr1);
    EXPECT_EQ(v.subNodeCount(), 1);

    std::cout << "Constuct Triangle" << std::endl;
    VTriangle vtr2(p1, p2, p3);
    v.append(vtr2);
    EXPECT_EQ(v.subNodeCount(), 2);

    std::vector<float> vf;
    std::vector<uint16_t> iu;
    v.genING(vf, iu);
    EXPECT_EQ(vf.size(), 48);
    EXPECT_EQ(iu.size(), 6);
    EXPECT_EQ(vf[0],-0.5);
    EXPECT_EQ(vf[24], -0.5);
    EXPECT_EQ(iu[3], 3);
}