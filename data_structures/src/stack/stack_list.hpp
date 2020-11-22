/*
 * Stack implementation using list 
 * 
 */

#include <iostream>

template <class T>
struct StackNode
{
    T value_;
    StackNode<T>* previous_;
};

template<class T>
class StackList
{
public:
    constexpr static uint32_t CAPACITY{4};

    void showStack() const
    {
        std::cout << "Stack:: elements: " << currentNodes << "/" << CAPACITY <<std::endl;
        int index = currentNodes;

        StackNode<T>* currentNode = topNode;
        while(currentNode != nullptr)
        {
            std::cout << "\t index: " << index-- << ", value: " << currentNode->value_ << std::endl;
            currentNode = currentNode->previous_;
        }
    }

    bool isEmpty() { return currentNodes == 0; }
    bool isFull() { return currentNodes == CAPACITY ; }

    bool push(const T element)
    {
        if (isFull())
        {
            std::cout << "Stack is full capacity: " << CAPACITY <<std::endl;
            return false;
        }
        StackNode<T>* node = new StackNode<T>{element, topNode};
        topNode = node;
        currentNodes++;
        return true;
    }

    std::optional<T> pop()
    {
        if (isEmpty()) return {};
        auto node = topNode;
        topNode = topNode->previous_;
        std::optional<T> element = std::optional<T>{node->value_};
        delete node;
        currentNodes--;
        return element;
    }

private:
    int currentNodes{0};
    StackNode<T>* topNode{nullptr};
};
