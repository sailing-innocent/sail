// input n = 3
// output ["((()))","(()())","(())()","()(())","()()()"]
// equivalent with different routes from (0,0) to (n,n)
// *
// * *
// * * *

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> getWay(int x, int y, int n)
{
    std::vector<std::string> res{};
    if ( n == x && x == y) {
        res.push_back("");
    }
    if (n > x) {
        std::vector<std::string> downRes = getWay(x+1, y, n);
        for (auto item: downRes) {
            item = "(" + item;
            res.push_back(item);
        }
    }
    if (x > y) {
        std::vector<std::string> rightRes = getWay(x, y+1, n);
        for (auto item: rightRes) {
            item = ")" + item;
            res.push_back(item);
        }
    }
    return res;
}

std::vector<std::string> genPair(int n)
{
    return getWay(0, 0, n);   
}

TEST(SAIL_TEST_LC22, GEN_PAIRS)
{
    std::vector<std::string> res = genPair(3);
    for (auto item: res) {
        std::cout << item.c_str() << ",";
    }
    std::cout << std::endl;
}