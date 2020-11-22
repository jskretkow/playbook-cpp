/*
 * Queue implementation using list
 *
 */

#include <iostream>

template <class T>
struct Node
{
    T value_;
    Node<T>* previous_;
};

template<class T>
class Queue
{
public:
    void display() const
    {
        Node<T>* currentNode = head;
        while(currentNode != nullptr)
        {
            std::cout << "\t value: " << currentNode->value_ << std::endl;
            currentNode = currentNode->previous_;
        }
    }

    bool isEmpty()
    {
        bool empty = (head == nullptr && tail == nullptr);
        assert(empty ? nodeCount == 0 : nodeCount > 0);
        return  empty;
    }

    void push(const T element)
    {
        Node<T>* node = new Node<T>{element, nullptr};
        if (isEmpty())
            tail = head = node;
        else
        {
            tail->previous_ = node;
            tail = node;
        }
        nodeCount++;
    }

    std::optional<T> pop()
    {
        if (isEmpty()) return {};
        auto node = head;
        head = head->previous_;
        std::optional<T> element = std::optional<T>{node->value_};
        delete node;
        nodeCount--;
        if (head == nullptr)
            tail = nullptr;
        return element;
    }

private:
    int nodeCount{0};
    Node<T>* head{nullptr};
    Node<T>* tail{nullptr};
};
