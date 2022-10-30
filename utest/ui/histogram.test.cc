#include <gtest/gtest.h>
#include <sail/ui/figure.h>

using namespace sail;

TEST(TEST_LIB_SAIL, HISTOGRAM_CREATE)
{
    std::vector<float> test{1.0f, 2.0f}; // , 3.0f, 2.0f, 4.0f, 1.0f};
    Histogram2D his(test, 5.0f, 0.0f);
    VisNode vn;
    his.draw(vn);
    std::vector<float> vf;
    std::vector<uint16_t> iu;
    vn.genING(vf, iu);
    std::cout << "iu: ["; 
    for (auto i: iu) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    std::cout << "vf: ["; 
    for (auto i: vf) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
}
