#include <gtest/gtest.h>
#include <sail/visualize.h>

using namespace sail;

TEST(SAIL_TEST_VIS, CREATE_VNODE)
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