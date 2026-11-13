#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long value;
    Node* left;
    Node* right;
    Node* parent;
    Node(long long v, Node* p = nullptr)
        : value(v), left(nullptr), right(nullptr), parent(p) {}
};

class MaxHeap {
private:
    Node* root;
    vector<Node*> nodes;
    long long size_;

    Node* build(const vector<long long>& arr, long long i, Node* parent){
        if (i >= (long long)arr.size()) return nullptr;
        Node* node = new Node(arr[i], parent);
        node->left  = build(arr, 2*i + 1, node);
        node->right = build(arr, 2*i + 2, node);
        return node;
    }

    void healDamage(Node* node){
        if (!node) return;
        Node* largest = node;
        if (node->left  && node->left->value  > largest->value) largest = node->left;
        if (node->right && node->right->value > largest->value) largest = node->right;
        if (largest != node){
            swap(node->value, largest->value);
            healDamage(largest);
        }
    }

    void healUp(Node* node){
        while (node->parent && node->value > node->parent->value){
            swap(node->value, node->parent->value);
            node = node->parent;
        }
    }

    void arise(Node* node){
        if (!node) return;
        arise(node->left);
        arise(node->right);
        healDamage(node);
    }

    Node* add(long long val){
        Node* node = new Node(val);
        long long i = size_;
        nodes.push_back(node);

        if (i == 0){
            root = node;
            node->parent = nullptr;
        } else {
            long long p = (i - 1) / 2;
            node->parent = nodes[p];
            if (!nodes[p]->left)  nodes[p]->left  = node;
            else                  nodes[p]->right = node;
        }

        size_++;
        return node;
    }

public:
    MaxHeap() : root(nullptr), size_(0) {}

    long long size()  const { return size_; }
    bool empty() const { return size_ == 0; }

    long long top() const {
        if (!root) return 0;
        return root->value;
    }

    void insert(long long val){
        healUp(add(val));
    }

    void pop(){
        if (!root) return;
        if (size_ == 1){
            delete root;
            root = nullptr;
            nodes.clear();
            size_ = 0;
            return;
        }

        Node* last = nodes.back();
        root->value = last->value;

        Node* p = last->parent;
        if (p->left == last) p->left = nullptr;
        else                 p->right = nullptr;

        nodes.pop_back();
        delete last;
        size_--;

        healDamage(root);
    }

    void builder(const vector<long long>& arr){
        destruct(root);
        root = nullptr;
        nodes.clear();
        size_ = 0;
        if (arr.empty()) return;

        root = build(arr, 0, nullptr);
        size_ = (long long)arr.size();

        nodes.reserve(size_);
        vector<Node*> q{root};
        for (long long i = 0; i < (long long)q.size(); ++i){
            nodes.push_back(q[i]);
            if (q[i]->left)  q.push_back(q[i]->left);
            if (q[i]->right) q.push_back(q[i]->right);
        }

        arise(root);
    }

    void destruct(Node* node){
        if (!node) return;
        destruct(node->right);
        destruct(node->left);
        delete node;
    }

    void superNova(){
        destruct(root);
        root = nullptr;
        nodes.clear();
        size_ = 0;
    }
};


