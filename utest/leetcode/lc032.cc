#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int longestValidateParenthesis(string s)
{
    int len = s.length();
    int i = 0;
    int currMax = 0;
    int currStart = 0;
    int currEnd = 0;
    int signal_left = 0;
    int signal_right = 0;
    while (2 * i < len - 1)
    {
        if (s[i] == '(' && signal_left == 0) {
            currStart = i;
            signal_left++;
        }
        if (s[len-i-1] == ')' && signal_right == 0) {
            currEnd = len-i-1;
            signal_right++;
        }
        i++;
        if (signal_left > 0 && signal_right > 0) {
            currMax = currEnd - currStart;
            break;
        }
    }
    return currMax;
} 

TEST(SAIL_TEST_LEETCODE, LC032_HARD_FIND_LONGEST_VALID_PAR)
{
    string s0 = "()";
    EXPECT_EQ(longestValidateParenthesis(s0), 2); // TODO: I dont understand
    string s1 = "(())";
    EXPECT_EQ(longestValidateParenthesis(s1), 3);
    string s2 = "(()";
    EXPECT_EQ(longestValidateParenthesis(s2), 2);
    string s3 = ")()())";
    EXPECT_EQ(longestValidateParenthesis(s3), 4);
}