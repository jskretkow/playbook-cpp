/*
 * List implementation single linked
 * 
 */

template <class T>
struct Node
{
    T value_;
    Node<T>* next_;
};

template <class T>
class SingleLinkedList
{
public:

    bool isEmpty()
    {
        bool empty = (head == nullptr && tail == nullptr);
        assert(empty ? nodeCount == 0 : nodeCount > 0);
        return  empty;
    }

    void  append(T value)
    {
        Node<T>* node = new Node<T>{value, nullptr};

        if (isEmpty())
        {
            head = tail = node;
        }
        else
        {
            tail->next_ = node;
            tail = tail->next_;
        }
        nodeCount++;
    }

    void prepend(T value)
    {
        Node<T>* node = new Node<T>{value, head};

        if (isEmpty())
        {
            head = tail = node;
        }
        else
        {
            head = node;
        }
        nodeCount++;
    }

    bool removeFront()
    {
        if (isEmpty())
        {
            return false;
        }

        auto currentHead = head;
        head = head->next_;
        delete currentHead;
        nodeCount--;
        if (head == nullptr)
            tail = head;
        return true;
    }

    bool removeBack()
    {
        if (isEmpty())
        {
            return false;
        }

        return removeNode(tail->value_);
    }

    bool  removeNode(const T& value)
    {
        if (isEmpty())
        {
            return false;
        }
        if (head->value_ == value)
        {
            return removeFront();
        }

        auto[preceeding, nodeToDelete] = findNodesForRemoval(value);

        if (preceeding == nullptr and nodeToDelete == nullptr)
        {
            return false;
        }

        preceeding->next_ = nodeToDelete->next_;
        if (nodeToDelete == tail)
            tail = preceeding;
        delete nodeToDelete;
        nodeCount--;
        return true;
    }

    void display()
    {
        Node<T>* current = head;
        if (head != nullptr)
            std::cout<< "List: \n";
        while(current != nullptr)
        {
            std::cout << "\t v: "<< current->value_ <<
                ", next: " << (current->next_ != nullptr ? std::to_string(current->next_->value_) : "nullptr")  <<
                '\n';
            current = current->next_;
        }
    }

    Node<T>* getHead() { return head; }
    Node<T>* getTail() { return tail; }
    std::uint32_t size() { return nodeCount; }

private:
    std::pair<Node<T>*, Node<T>*> findNodesForRemoval(const T& value)
    {
        assert(head != nullptr);
        if (head->value_ == value)
            return {nullptr, head};

        Node<T>* preceeding = head;
        Node<T>* current = head->next_;

        while(current != nullptr and  current->value_ != value)
        {
            preceeding = current;
            current = current->next_;
        }

        if (current == nullptr)
        {
            std::cout << "Node with value: " << value << " not found!\n";
            return {nullptr, nullptr};
        }

        return {preceeding, current};
    }

    Node<T>* head{nullptr};
    Node<T>* tail{nullptr};
    std::uint32_t nodeCount{0};
};

