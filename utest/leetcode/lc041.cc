#include <gtest/gtest.h>
#include <vector>
#include <iostream>

// 这道题边界情况特别多，高血压慎入

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    if (nums.size() <= 1 ) {
        if (nums[0] == 1) {
            return 2;
        }
        return 1;
    }
    for (auto i = 0; i < nums.size(); i++) {
        while (nums[i] >= 1 && nums[i] < nums.size()+1 && nums[nums[i]-1] != nums[i]) {
            // cout << "swaping: " << i << " " << nums[i]-1 << ";" << endl; 
            int temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = temp;
        }
    }
    int res = 1;
    while (res-1 < nums.size() && nums[res-1] == res) {
        res = res + 1;
    }
    return res;
}

TEST(SAIL_LEETCODE_TEST, LC041_HARD_FIRST_MISSING_POSITIVE)
{
    vector<int> s1{3,4,-1,1};
    EXPECT_EQ(firstMissingPositive(s1), 2);
    vector<int> s2{2,1};
    EXPECT_EQ(firstMissingPositive(s2), 3);
    vector<int> s3{1,2,2,1,3,1,0,4,0};
    EXPECT_EQ(firstMissingPositive(s3), 5);
    vector<int> s4{2147483647,2147483646,2147483645,3,2,1,-1,0,-2147483648};
    EXPECT_EQ(firstMissingPositive(s4), 4);
}