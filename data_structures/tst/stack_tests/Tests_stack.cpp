#include <gtest/gtest.h>
#include <stack/stack.hpp>
#include <stack/stack_list.hpp>

typedef ::testing::Types<StackArray<int>, StackList<int>> TestingTypes;

template <typename T>
class Stacks : public ::testing::Test{};

TYPED_TEST_CASE(Stacks,  TestingTypes);

TYPED_TEST(Stacks, initPop)
{
    TypeParam stack{};
    auto element = stack.pop();
    EXPECT_EQ(element.has_value(), false);
}

TYPED_TEST(Stacks, pushTillMaxAndThenPop)
{
    TypeParam stackInt{};
    std::vector<int> comparison;
    for (auto i = 1; i <= TypeParam::CAPACITY; ++i)
    {
        EXPECT_TRUE(stackInt.push(i));
        comparison.push_back(i);
    }
    EXPECT_FALSE(stackInt.push(1));
    EXPECT_TRUE(stackInt.isFull());

    std::vector<int> result;
    for (auto i = 1; i <= TypeParam::CAPACITY; ++i)
    {
        result.insert(result.begin(), stackInt.pop().value());
    }

    EXPECT_TRUE(stackInt.isEmpty());
    EXPECT_EQ(comparison, result);
    EXPECT_FALSE(stackInt.pop().has_value());

    EXPECT_TRUE(stackInt.push(1));
}



