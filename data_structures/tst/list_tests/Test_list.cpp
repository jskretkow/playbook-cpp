#include <gtest/gtest.h>
#include <list/single_linked_list.hpp>


TEST(SingleList, initalConditions)
{
    SingleLinkedList <int> list;
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
    EXPECT_EQ(list.size(), 0);
}

TEST(SingleList, fillAndRemoveNodes)
{
    SingleLinkedList <int> list;

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
}

TEST(SingleList, removeNotFound)
{
    SingleLinkedList <int> list;
    //on empty list
    list.removeNode(0);

    //single element
    list.append(1);
    list.removeNode(0);

    //multi
    list.append(2);
    list.removeNode(0);
}

TEST(SingleList, removeNodes)
{
    SingleLinkedList <int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    //front
    list.removeNode(1);
    //middle
    list.removeNode(3);
    //back
    list.removeNode(4);

    EXPECT_EQ(list.getHead()->value_, 2);
    EXPECT_EQ(list.getTail()->value_, 2);
}
