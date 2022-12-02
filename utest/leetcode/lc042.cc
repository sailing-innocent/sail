#include <gtest/gtest.h>
#include <vector>
#include <iostream>

// So many details
// 5.85% for time and 99.6% for space
// space for time, consider opetimization

// use dynamic programing, max_left[i] to store the highest wall on the left of i th column
// and max_right[i] to store the right
// after building this information, we can sum up the accepted drops directy iterated by columns


using namespace std;

int trap(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int nexti = i;
    int nextj = j;
    int res = 0;
    int prevf = 0;
    while (i < j) {
        // cout << "CURRENT ITER: " << i << " " << j << endl;
        int f = height[i] < height[j] ? height[i] : height[j];
        for (auto n = 1; n < j-i; n++) {
            if (height[n+i] > f && height[i] <= height[j]) {
                nexti = n+i;
                break;
            }
            if (height[j-n] > f && height[i] >= height[j]) {
                nextj = j-n;
                break;
            }
        }
        for (auto n = i+1; n < j; n++) {
            if (height[n] < f) {
                if (height[n] < prevf) {
                    res = res + f - prevf;
                }
                else {
                    res = res + f - height[n];
                }
            }
        }
        if (i == nexti && j == nextj ) { 
            break; 
        }
        i = nexti;
        j = nextj;
        prevf = f;
    }
    return res;
}

TEST(SAIL_TEST_LEETCODE, LC042_HARD_TRAPPING_RAIN_WATER)
{
    vector<int> s1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    EXPECT_EQ(trap(s1), 6);
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    vector<int> s2 = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
    EXPECT_EQ(trap(s2), 83);
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    vector<int> s3 = {4,3,3,9,3,0,9,2,8,3};
    EXPECT_EQ(trap(s3), 23);
}