#include <gtest/gtest.h>
#include <sail/algorithm.h>

TEST(SAIL_ALGORITHM_TEST, BASIC_TEST)
{
    sail::Node<int> n1(1);
    sail::Node<int> n2(2);
    sail::Queue<int> q;
    EXPECT_EQ(q.isEnpty(), true);
    EXPECT_EQ(q.size(), 0);

    q.enqueue(n1);
    q.enqueue(n2);
    EXPECT_EQ(q.isEnpty(), false);
    EXPECT_EQ(q.size(), 2);

    int nt1 = q.dequeue().content();
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(nt1, 1);
}