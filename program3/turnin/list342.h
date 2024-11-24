#ifndef LIST342_H_
#define LIST342_H_

#include <string>
using std::string;
#include <sstream>
#include <fstream>

template <class T>
struct Node {
    T *data;
    Node *next;
};

template <class T>
class List342;

template <class T>
std::ostream& operator <<(std::ostream &stream, const List342<T> &list);

template <class T>
class List342 {
    public:
        List342() {
            this->head_ = nullptr;
            this->length_ = 0;
        }

        // assignment operator. different from copy
        List342(const List342<T> &list) {
            this->head_ = nullptr;
            this->length_ = 0;
            *this = list;
        }

        ~List342() {
            this->DeleteList();
        }

        // getters
        int Length() {
            return this->length_;
        }

        bool BuildList(string filename);
        void PrintList() const;

        int Size() const {
            return this->length_;
        }

        // Public Modifiers
        bool Insert(T *item);
        bool Remove(T target, T &result);
        bool Peek(T target, T &result);
        void DeleteList();
        bool Merge(List342<T> &list);

        // operator overloads
        friend std::ostream& operator<< <>(std::ostream &stream, const List342<T> &list);
        List342<T> operator+(const List342<T> &other) const;
        List342<T>& operator+=(const List342<T> &other);
        bool operator==(const List342<T> &other) const;
        bool operator!=(const List342<T> &other) const;
        List342<T>& operator=(const List342<T> &other);

    private:
        Node<T> *head_;
        int length_;

        Node<T>* MergeHelper(Node<T> *a, Node<T> *b, int &new_length);
        void DeleteListHelper(Node<T> *curr);
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
        delete copy;
        delete node;
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
bool List342<T>::Remove(T target, T &result) {
    if (this->head_ == nullptr) {
        return false;
    }

    if (*(this->head_->data) == target) {
        Node<T> *temp = this->head_;
        this->head_ = temp->next;
        temp->next = nullptr;
        result = *(temp->data);
        delete temp->data;
        temp->data = nullptr;
        delete temp;

        this->length_--;
        return true;
    }

    Node<T> *curr = this->head_;
    for (int i = 0; i < this->length_ - 1; i++) {
        if (*(curr->next->data) == target) {
            Node<T> *temp = curr->next;
            curr->next = temp->next;
            result = *(temp->data);
            delete temp->data;
            delete temp;
            this->length_--;
            return true;
        }
        curr = curr->next;
    }

    return false;
}


template <class T>
void List342<T>::PrintList() const {
    if (this->head_ == nullptr && this->length_ == 0) {
        std::cout << "Empty list!\n";
    }

    const Node<T> *curr = this->head_;
    for (int i = 0; i < this->length_; i++) {
        std::cout << "[Node #" << i << "] " << "(val: " << *(curr->data) << ")\n";
        curr = curr->next;
    }
}

template <class T>
void List342<T>::DeleteListHelper(Node<T> *curr) {
    if (curr == nullptr) {
        return;
    }

    DeleteListHelper(curr->next);
    curr->next = nullptr;
    delete curr->data;
    curr->data = nullptr;
    delete curr;
}

template <class T>
void List342<T>::DeleteList() {
    DeleteListHelper(this->head_);
    this->head_ = nullptr;
    this->length_ = 0;
}

template <class T>
bool List342<T>::Peek(T target, T &result) {
    if (this->head_ == nullptr) {
        return false;
    }

    Node<T> *curr = this->head_;
    for (int i = 0; i < this->length_; i++) {
        if (*(curr->data) == target) {
            result = *(curr->data);
            return true;
        }

        curr = curr->next;
    }
    return false;
}

template <class T>
Node<T>* List342<T>::MergeHelper(Node<T> *a, Node<T> *b, int &new_length) {
    Node<T> *res = nullptr;

    if (a == nullptr) {
        return b;
    } else if (b == nullptr) {
        return a;
    }

    if (*(a->data) < *(b->data)) {
        res = a;
        res->next = MergeHelper(a->next, b, new_length);
    } else if (*(a->data) > *(b->data)) {
        res = b;
        res->next = MergeHelper(a, b->next, new_length);
    } else { // if they are equal we keep one and delete the other 
        new_length--;
        res = a;
        res->next = MergeHelper(a->next, b->next, new_length);
        Node<T> *temp = b;
        delete b->data;
        delete b;
    }

    return res;
}

template <class T>
bool List342<T>::Merge(List342<T> &list) {
    if (this == &list) {
        return true;
    }

    if (this->head_ == nullptr) {
        this->head_ = list.head_;
        list.head_ = nullptr;
        this->length_ = list.length_;
        return true;
    } else if (list.head_ == nullptr) {
        return true;
    }

    int new_length = this->length_ + list.length_;
    this->head_ = this->MergeHelper(this->head_, list.head_, new_length);
    list.head_ = nullptr;
    list.length_ = 0;
    this->length_ = new_length;

    return true;
}

template <class T>
std::ostream& operator <<(std::ostream &stream, const List342<T> &list) {
    Node<T> *curr = list.head_;
    while (curr != nullptr) {
        stream << *(curr->data);
        curr = curr->next;
    }

    return stream;
}

template <class T>
List342<T> List342<T>::operator+(const List342<T> &other) const {
    List342<T> res;
    res = *this;
    List342<T> other_copy;
    other_copy = other;
    res.Merge(other_copy);
    return res;
}


template <class T>
 List342<T>& List342<T>::operator+=(const List342<T> &other) {
    List342<T> copy;
    copy = other;
    this->Merge(copy);

    return *this;
 }

template <class T>
bool List342<T>::operator==(const List342<T> &other) const {
    Node<T> *curr = this->head_;
    Node<T> *other_curr = other.head_;

    while (curr != nullptr && other_curr != nullptr) {
        if (*(curr->data) != *(other_curr->data)) {
            return false;
        }

        curr = curr->next;
        other_curr = other_curr->next;
    }

    if (curr == nullptr && other_curr == nullptr) {
        return true;
    }
    return false;
}

template <class T>
bool List342<T>::operator!=(const List342<T> &other) const {
    return !(*this == other);
}

template <class T>
List342<T>& List342<T>::operator=(const List342<T> &other) {
    if (this == &other) {
        return *this;
    }
    this->DeleteList();
    Node<T> *curr = other.head_;
    while (curr != nullptr) {
        this->Insert(curr->data);
        curr = curr->next;
    }
    this->length_ = other.length_;

    return *this;
}

template <class T>
bool List342<T>::BuildList(string filename) {
    std::fstream file(filename, std::ios_base::in);

    T val;
    while (file >> val) {
        this->Insert(&val);
    }

    return true;
}

#endif