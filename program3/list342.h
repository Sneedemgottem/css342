#ifndef LIST342_H_
#define LIST342_H_

#include <string>
using std::string;

template <class T>
struct Node {
    T *data;
    Node *next;
};

template <class T>
class List342 {
    public:
        List342() {
            this->head_ = nullptr;
            this->length_ = 0;
        }
        ~List342() { // TODO: change to free all nodes
            this->DeleteList();
        }

        // getters
        int Length() {
            return this->length_;
        }

        bool BuildList(string filename);
        void PrintList() const;

        // Public Modifiers
        bool Insert(T *item);
        bool Remove(T target, T &result);
        bool Peek(T target, T &result);
        int Size() const;
        void DeleteList() {}
        bool Merge(List342<T> &list);

        // operator overloads
        // TODO: write the overloads


    private:
        Node<T> *head_;
        int length_;
};

template <class T>
bool List342<T>::Insert(T *item) {
    // create a new node and put the data in it
    T *copy = new T(*item);
    Node<T> *node = new Node<T>;
    node->data = copy;
    node->next = nullptr;

    // if there's no head node yet, use this one
    if (this->head_ == nullptr) {
        this->head_ = node;
        this->length_++;
        return true;
    }

    // if this node should be the new head, make it the head.
    if (*copy < *(this->head_->data)) {
        Node<T> *temp = this->head_;
        this->head_ = node;
        this->head_->next = temp;
        this->length_++;
        return true;
    }

    Node<T> *curr = this->head_;
    for (int i = 0; i < this->length_ - 1; i++) {
        if (*(curr->next->data) > *copy) {
            break;
        }
        curr = curr->next;
    }

    // curr should be at the pointer where copy should be inserted after.
    if (*(curr->data) == *copy) { // If there's a copy, it should be here where it's supposed to be inserted
        return false;
    } else {
        Node<T> *temp = curr->next;
        curr->next = node;
        node->next = temp;
        this->length_++;
        return true;
    }
}


template <class T>
void List342<T>::PrintList() const {
    const Node<T> *curr = this->head_;
    for (int i = 0; i < this->length_; i++) {
        std::cout << "[Node #" << i << "] " << "(val: " << *(curr->data) << ")\n";
        curr = curr->next;
    }
}

#endif