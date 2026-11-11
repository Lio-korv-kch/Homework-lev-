#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        Node(const T& v, Node* p = nullptr, Node* n = nullptr)
            : value(v), prev(p), next(n) {}
        Node(T&& v, Node* p = nullptr, Node* n = nullptr)
            : value(move(v)), prev(p), next(n) {}
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    int size_ = 0;

    template <typename V>
    Node* attach_before(Node* pos, V&& v) {
        Node* prev = pos ? pos->prev : tail_;
        Node* n = new Node(forward<V>(v), prev, pos);
        if (prev) prev->next = n; else head_ = n;
        if (pos)  pos->prev  = n; else tail_ = n;
        ++size_;
        return n;
    }

    template <typename V>
    Node* attach_after(Node* pos, V&& v) {
        Node* next = pos ? pos->next : head_;
        Node* n = new Node(forward<V>(v), pos, next);
        if (pos)  pos->next  = n; else head_ = n;
        if (next) next->prev = n; else tail_ = n;
        ++size_;
        return n;
    }
public:

    List() = default;

    List(const List&) = delete;
    List& operator=(const List&) = delete;

    ~List() { clear(); }

    void push_back(const T& v) { attach_after(tail_, v); }
    void push_front(const T& v) { attach_before(head_, v); }

    void pop() {
        if (!tail_) return;
        Node* n = tail_;
        tail_ = tail_->prev;
        if (tail_) tail_->next = nullptr; else head_ = nullptr;
        delete n;
        --size_;
    }

    void clear() {
        Node* cur = head_;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
    }

    int size()  const { return size_; }
    bool empty() const { return size_ == 0; }
};
