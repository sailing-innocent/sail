#include <gtest/gtest.h>
#include <sail/algorithm.h>

using namespace sail;

TEST(SAIL_TEST_NODE, INT_NODE_INIT) {
    Node<int> n1(1);
    const int n1_content = n1.content();
    EXPECT_EQ(n1_content, 1);

    // copy construct
    Node<int> n2(n1);
    EXPECT_EQ(n1.content(), 1);

    // copy operator = 
    Node<int> n3;
    n3 = n1;
    EXPECT_EQ(n3.content(), 1);

    n2.setContent(2);
    EXPECT_EQ(n2.content(), 2);

    Node<int> n4 = n2;
    EXPECT_TRUE(n4 == n2);
}

TEST(SAIL_TEST_NODE, STRUCT_NODE_INIT)
{
    struct mystruct {
        int index;
        char* name;
    };
    mystruct ms1;
    ms1.index = 1;
    ms1.name = "hello";
    EXPECT_EQ(ms1.index, 1);
    EXPECT_STREQ(ms1.name, "hello");

    Node<mystruct> nm1(ms1);
    EXPECT_EQ(nm1.content().index, 1);
    EXPECT_STREQ(nm1.content().name, "hello");
    Node<mystruct> nm2 = nm1;
    EXPECT_EQ(nm2.content().index, 1);
    EXPECT_STREQ(nm2.content().name, "hello");
}

TEST(SAIL_TEST_NODE, STRUCT_NODE) {}