/*
 * List implementation double linked
 * 
 */

template <class T>
struct Node
{
    T value_;
    Node<T>* next_;
    Node<T>* prev_;
};

template <class T>
class DoubleLinkedList
{

public:

    bool isEmpty() const
    {
        bool empty = (head == nullptr && tail == nullptr);
        assert(empty ? nodeCount == 0 : nodeCount > 0);
        return  empty;
    }
    Node<T>* append(T value)
    {
        Node<T>* node = new Node<T>{value, nullptr, tail};

        if (isEmpty())
        {
            head = tail = node;
        }
        else
        {
            tail->next_ = node;
            tail = node;
        }
        nodeCount++;
        return node;
    }

    Node<T>* prepend(T value)
    {
        Node<T>* node = new Node<T>{value, head, nullptr};

        if (isEmpty())
        {
            head = tail = node;
        }
        else
        {
            head->prev_ = node;
            head = node;
        }
        nodeCount++;
        return node;
    }

    void removeFront()
    {
        removeNode(head);
    }

    Node<T>* findPrecedingNode(Node<T>* node)
    {
        return node->prev_;
    }

    void removeBack()
    {
        removeNode(tail);
    }

    void removeNode(Node<T>* node)
    {
        if (isEmpty())
        {
            return;
        }

        if (node == head)
        {
            auto currentHead = head;
            head = head->next_;
            delete currentHead;
            nodeCount--;

            if (head == nullptr)
                tail = head;
            else
                head->prev_ = nullptr;
            return;
        }
        auto preceeding = findPrecedingNode(node);
        if (preceeding == nullptr)
        {
            std::cout <<"preceding not found exiting \n";
            return;
        }

        preceeding->next_ = node->next_;
        if (node == tail)
            tail = preceeding;
        else
            preceeding->next_->prev_ = preceeding;
        delete node;
        nodeCount--;

    }

    void display() const
    {
        Node<T>* current = head;
        if (head != nullptr)
            std::cout<< "List: \n";
        while(current != nullptr)
        {
            std::cout << "\t v: "<< current->value_ <<
                ", previous: " << (current->prev_ != nullptr ? std::to_string(current->prev_->value_) : "nullptr")  <<
                ", next: " << (current->next_ != nullptr ? std::to_string(current->next_->value_) : "nullptr")  <<
                '\n';
            current = current->next_;
        }
    }

    Node<T>* getHead() { return head; }
    Node<T>* getTail() { return tail; }
    std::uint32_t size() { return nodeCount; }

private:
    Node<T>* head{nullptr};
    Node<T>* tail{nullptr};
    std::uint32_t nodeCount{0};
};

