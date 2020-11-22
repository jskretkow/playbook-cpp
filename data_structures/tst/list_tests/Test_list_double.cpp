#include <gtest/gtest.h>
#include <list/double_linked_list.hpp>

TEST(DoubleList, initalConditions)
{
    DoubleLinkedList <int> list;
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
    EXPECT_EQ(list.size(), 0);
}

TEST(DoubleList, fillAndRemoveNodes)
{
    DoubleLinkedList <int> list;

    //push back
    for (auto i = 1; i <= 10; ++i)
    {
        list.append(i);
        EXPECT_EQ(list.size(), i);
    }

    for (auto i = 1; i <= 10; ++i)
    {
        list.removeBack();
        EXPECT_EQ(list.size(), 10 - i);
    }

    // push front
    for (auto i = 10; i >= 1; --i)
    {
        list.prepend(i);
        EXPECT_EQ(list.size(), 10 - i + 1);
    }

    for (auto i = 10; i >= 1; --i)
    {
        list.removeFront();
        EXPECT_EQ(list.size(), i - 1);
    }
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
    EXPECT_EQ(list.size(), 0);
}


TEST(DoubleList, removeNotFound)
{
    DoubleLinkedList <int> list;
    //on empty list
    list.removeNode(nullptr);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
    EXPECT_EQ(list.size(), 0);
}

TEST(DoubleList, removeNodes)
{
    DoubleLinkedList<int> list;

    auto node1 = list.append(1);
    auto node2 = list.append(2);
    auto node3 = list.append(3);
    auto node4 = list.append(4);

    //front
    list.removeNode(node1);
    //middle
    list.removeNode(node3);
    //back
    list.removeNode(node4);

    EXPECT_EQ(list.getHead()->value_, 2);
    EXPECT_EQ(list.getTail()->value_, 2);
}
