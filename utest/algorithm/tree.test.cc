#include <gtest/gtest.h>
#include <sail/algorithm.h>

TEST(SAIL_ALGORITHM_TEST, TREE_NODE_CREATION)
{
    sail::TreeNode<int> n1(1);
    sail::TreeNode<int> n2(2);
    sail::TreeNode<int> n3(3);

    n1.setFirstChild(n2);
    n2.setNextSibling(n3);
    EXPECT_EQ(n1.firstChild().content(), 2);
    EXPECT_EQ(n1.firstChild().nextSibling().content(), 3);
}

TEST(SAIL_ALGORITHM_TEST, TREE_CREATION)
{
    sail::TreeNode<int> n1(1);
    sail::TreeNode<int> n2(2);
    sail::TreeNode<int> n3(3);

    n1.setFirstChild(n2);
    n2.setNextSibling(n3);

    sail::Tree<int> tr1(n1);
    sail::Tree<int> tr2;
    tr2.root() = n1;

    EXPECT_EQ(tr1.root().content(), 1);
    EXPECT_EQ(tr2.root().content(), 1);
    EXPECT_EQ(tr1.root().firstChild().content(), 2);
    n2.setContent(4);
    EXPECT_EQ(tr2.root().firstChild().content(), 4);
}