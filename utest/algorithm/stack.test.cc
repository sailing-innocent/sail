#include <gtest/gtest.h>
#include <sail/algorithm.h>

TEST(SAIL_ALGORITHM_TEST, STACK_FUNCTION)
{
    sail::Node<int> n1(1);
    sail::Node<int> n2(2);
    sail::Stack<int> st;
    EXPECT_EQ(st.isEmpty(), true);
    EXPECT_EQ(st.size(), 0);
    st.push(n1);
    st.push(n2);
    EXPECT_EQ(st.size(), 2);
    sail::Node<int> n2_ = st.pop();
    EXPECT_EQ(n2_.content(), 2);
    EXPECT_EQ(st.isEmpty(), false);
    EXPECT_EQ(st.size(), 1);
}

TEST(SAIL_ALGORITHM_TEST, STACK_ADVANCED)
{
    sail::Node<int> n1(1);
    sail::Stack<int> st;
    st.push(n1);
    int nt2 = 2;
    st.push(nt2);
    EXPECT_EQ(st.size(), 2);
    int out = st.pop().content();
    EXPECT_EQ(out, 2);
}