#include <iostream>
#include <vector>
#include <algorithm>
#pragma once
using namespace std;

struct Node {
    long long priority;
    Node* left;
    Node* right;
    Node* parent;
    Node(long long pr, Node* p = nullptr)
        : priority(pr), left(nullptr), right(nullptr), parent(p) {}
};

class MinHeap {
private:
    Node* root;
    vector<Node*> nodes;
    long long size_;

    void healDamage(Node* node){
        if (!node) return;
        Node* smallest = node;
        if (node->left  && node->left->priority  < smallest->priority) smallest = node->left;
        if (node->right && node->right->priority < smallest->priority) smallest = node->right;
        if (smallest != node){
            swap(node->priority, smallest->priority);
            healDamage(smallest);
        }
    }

    void healUp(Node* node){
        while (node->parent && node->priority < node->parent->priority){
            swap(node->priority, node->parent->priority);
            node = node->parent;
        }
    }

    Node* add(long long priority){
        Node* node = new Node(priority);
        long long i = size_;
        nodes.push_back(node);
        if (i == 0){
            root = node;
        } else {
            long long p = (i - 1) / 2;
            node->parent = nodes[p];
            if (!nodes[p]->left)  nodes[p]->left  = node;
            else                  nodes[p]->right = node;
        }
        size_++;
        return node;
    }

    void destruct(Node* node){
        if (!node) return;
        destruct(node->right);
        destruct(node->left);
        delete node;
    }

public:
    MinHeap() : root(nullptr), size_(0) {}
    ~MinHeap() { destruct(root); }

    long long size() const { return size_; }
    bool empty() const { return size_ == 0; }

    Node* top_node() const { return root; }

    void insert(long long priority){
        healUp(add(priority));
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
        root->priority = last->priority;

        Node* p = last->parent;
        if (p->left == last) p->left = nullptr;
        else                 p->right = nullptr;

        nodes.pop_back();
        delete last;
        size_--;
        healDamage(root);
    }

    void print() const {
        vector<long long> vals;
        vals.reserve(nodes.size());
        for (Node* n : nodes) vals.push_back(n->priority);
        sort(vals.begin(), vals.end());
        for (size_t i = 0; i < vals.size(); ++i) {
            if (i) cout << ' ';
            cout << vals[i];
        }
        cout << '\n';
    }
};
