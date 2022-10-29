#include <gtest/gtest.h>
#include <sail/math/geometry.h>

using namespace sail;

TEST(SAIL_TEST_GEOMETRY, TRIAGNLE_TEST)
{
    point p1(0.5, 0.0, 0.0, 1.0);
    point p2(-0.5, 0.0, 0.0, 1.0);
    point p3(0.0, 0.5, 0.0, 1.0);
    Triangle tri(p1, p2, p3);
    VisNode vtri;
    tri.visualize(vtri);
    std::vector<float> vf;
    std::vector<uint16_t> iu;
    vtri.genING(vf, iu);
    EXPECT_EQ(vf.size(), 24);
    EXPECT_EQ(iu.size(), 3);
    EXPECT_EQ(vf[0], 0.5);
}

TEST(SAIL_TEST_GEOMETRY, RECT2D_TEST)
{
    point lb(-0.5f, -0.5f, 0.0f, 1.0f);
    float width = 1.0f;
    float height = 1.0f;
    Rect2D rec(lb, width, height);
    VisNode vn;
    rec.visualize(vn);
    std::vector<float> vf;
    std::vector<uint16_t> iu;
    vn.genING(vf, iu);
    EXPECT_EQ(vf.size(), 48);
    EXPECT_EQ(iu.size(), 6);
    EXPECT_EQ(vf[8], 0.5f);
}