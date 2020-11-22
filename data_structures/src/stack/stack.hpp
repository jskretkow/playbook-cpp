/*
 * Stack implementation - using array
 *
 */

#include <iostream>

template <class T>
class StackArray {
public:
    constexpr static uint32_t CAPACITY{4};

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        std::cout << "Stack:: elements: " << top + 1 << "/" << CAPACITY
                  << std::endl;
        for (auto i = 0; i <= top; ++i)
        {
            std::cout << "\tElement [" << i << "] = " << buffer_.at(i) << std::endl;
        }
    }

    bool isEmpty() { return top == std::numeric_limits<int>::max(); }
    bool isFull() { return (top + 1) == CAPACITY; }

    bool push(T element)
    {
        if (isFull())
        {
            std::cout << "Stack is full capacity: " << CAPACITY << std::endl;
            return false;
        }
        top = isEmpty() ? 0 : ++top;
        buffer_.at(top) = element;
        return true;
    }

    std::optional<T> pop()
    {
        if (isEmpty())
            return {};
        std::optional<T> element = std::optional<T>{buffer_[top]};
        top = top == 0 ? std::numeric_limits<int>::max() : --top;
        return element;
    }

private:
    std::array<T, CAPACITY> buffer_;
    int top{std::numeric_limits<int>::max()};
};
