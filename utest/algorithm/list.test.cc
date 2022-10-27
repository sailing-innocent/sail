#include <gtest/gtest.h>
#include <sail/algorithm.h>

using namespace sail;

TEST(SAIL_TEST_LIST, CREATE_LIST_NODE) {
    ListNode<int> ln1(1);
    EXPECT_EQ(ln1.content(), 1);
    ListNode<int> ln2(2);
    EXPECT_EQ(ln2.content(), 2);
    ln1.setNext(ln2);
    ln2.setPrev(ln1);
    EXPECT_EQ(ln1.next().content(), 2);
    EXPECT_EQ(ln2.prev().content(), 1);
}

TEST(SAIL_TEST_LIST, CREATE_LIST)
{
    std::vector<ListNode<int>> vec;
    ListNode<int> ln1(1);
    ListNode<int> ln2(2);
    vec.push_back(ln1);
    vec.push_back(ln2);
    LinkList<int> l(vec);
    EXPECT_EQ(l.content()[0].content(), 1);
    EXPECT_EQ(l.content()[1].content(), 2);
    EXPECT_EQ(l.content()[0].next().content(), 2);
    vec[0] = ln2;
    // NOW l is not independent from vec
    EXPECT_EQ(l.content()[0].content(), 1);
}

TEST(SAIL_TEST_LIST, LIST_APPEND)
{
    LinkList<int> li;
    li.append(1);
    EXPECT_EQ(li.size(), 1);
    EXPECT_EQ(li.content()[0].content(), 1);
    li.append(2);
    EXPECT_EQ(li.size(), 2);
    EXPECT_EQ(li.content()[1].content(), 2);
    EXPECT_EQ(li.content()[0].next().content(), 2);
}

TEST(SAIL_TEST_LIST, LIST_NODE_FETCH)
{
    LinkList<int> li;
    li.append(1);
    li.append(2);
    ListNode<int>& ln1 = li[0];
    EXPECT_EQ(ln1.content(), 1);
    ln1.setContent(2);
    ListNode<int> ln2 = li[0];
    EXPECT_EQ(ln2.content(), 2);
}

TEST(SAIL_TEST_LIST, LIST_INSERT)
{
    LinkList<int> li;
    li.append(1);
    li.append(2);
    li.insert(0, 0);
    EXPECT_EQ(li.size(), 3);
    EXPECT_EQ(li.content()[2].content(), 2);
}

TEST(SAIL_TEST_LIST, LIST_DEL)
{
    LinkList<int> li;
    li.append(1);
    li.append(2);
    li.insert(0, 0);
    li.del(1);
    EXPECT_EQ(li.size(), 2);
    EXPECT_EQ(li.content()[1].content(), 2);
}

TEST(SAIL_TEST_LIST, LIST_SWAP)
{
    LinkList<int> li;
    li.append(1);
    li.append(2);
    li.append(3);
    li.append(4);
    li.swap(1,2);
    EXPECT_EQ(li[3].prev().content(), 2);
}

TEST(SAIL_TEST_LIST, LIST_BUBBLE_SORT)
{
    LinkList<int> li;
    li.append(1);
    li.append(3);
    li.append(2);
    li.append(4);
    li.sort();
    EXPECT_EQ(li[3].content(), 4);
    EXPECT_EQ(li[3].prev().content(), 3);
}

TEST(SAIL_TEST_LIST, LIST_SELECT_SORT)
{
    LinkList<int> li;
    li.append(1);
    li.append(3);
    li.append(2);
    li.append(4);
    li.sort(1);
    EXPECT_EQ(li[3].content(), 4);
    EXPECT_EQ(li[3].prev().content(), 3);
}