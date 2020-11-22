#include <gtest/gtest.h>
#include <queue/queue.hpp>


TEST(Queue, initPop)
{
    Queue<int> queue{};
    auto element = queue.pop();
    EXPECT_EQ(element.has_value(), false);
}

TEST(Queue, pushAndPops)
{
    Queue<int> queue{};
    std::vector<int> comparison{1, 2, 3, 4, 5};
    for (auto i = 1; i <= 5; ++i)
    {
        queue.push(i);
    }

    for (auto i = 1; i <= 5; ++i)
    {
        EXPECT_EQ(comparison.at(i - 1), queue.pop());
    }
}
