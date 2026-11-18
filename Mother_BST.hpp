#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    long long value;
    Node(long long val) : left(nullptr), right(nullptr), value(val) {}
};

class BinaryTree {
private:
    size_t length;
    Node* root;

    Node* insertt(Node* node, long long val) {
        if (!node) return new Node(val);
        if (val < node->value) node->left  = insertt(node->left,  val);
        else   node->right = insertt(node->right, val);
        return node;
    }

    long long find_max(Node* node) const {
        if (!node) return -1;
        while (node->right) node = node->right;
        return node->value;
    }

    long long find_sec_max(Node* node) const {
        if (!node) return -1;

        Node* cur = node;
        while (cur) {
            if (cur->right) {

                if (!cur->right->right && !cur->right->left)
                    return cur->value;

                if (!cur->right->right && cur->right->left)
                    return find_max(cur->right->left);
                cur = cur->right;
            } else {

                if (!cur->left) return -1;
                return find_max(cur->left);
            }
        }
        return -1;
    }

    bool isLeaf(Node* node) const {
        return node && !node->left && !node->right;
    }

    void get_leaves(Node* node, vector<long long>& res) const {
        if (!node) return;
        if (isLeaf(node)) { res.push_back(node->value); return; }
        get_leaves(node->left,  res);
        get_leaves(node->right, res);
    }

    bool hasTwoChildren(Node* node) const {
        return node && node->left && node->right;
    }

    void get_family(Node* node, vector<long long>& res) const {
        if (!node) return;
        if (hasTwoChildren(node)) res.push_back(node->value);
        get_family(node->left,  res);
        get_family(node->right, res);
    }

    void destruct(Node* node) {
        if (!node) return;
        destruct(node->left);
        destruct(node->right);
        delete node;
    }

    Node* destructNode(Node* node, long long val) {
        if (!node) return nullptr;

        if (val < node->value) {
            node->left = destructNode(node->left, val);
            return node;
        }
        if (val > node->value) {
            node->right = destructNode(node->right, val);
            return node;
        }

        if (!node->left) {
            Node* r = node->right;
            delete node;
            return r;
        }
        if (!node->right) {
            Node* l = node->left;
            delete node;
            return l;
        }

        Node* succ = node->right;
        while (succ->left) succ = succ->left;
        node->value = succ->value;
        node->right = destructNode(node->right, succ->value);
        return node;
    }

    bool contains(Node* node, long long val) const {
        while (node) {
            if (val < node->value)      node = node->left;
            else if (val > node->value) node = node->right;
            else                        return true;
        }
        return false;
    }
public:
    BinaryTree() : length(0), root(nullptr) {}

    BinaryTree(const BinaryTree&) = delete;
    BinaryTree& operator=(const BinaryTree&) = delete;

    ~BinaryTree() {
        destruct(root);
        root = nullptr;
        length = 0;
    }

    void build(const vector<long long>& arr) {
        for (size_t i = 0; i < arr.size(); ++i) {
            insert(arr[i]);
        }
    }

    void insert(long long val) {
        size_t before = length;
        root = insertt(root, val);
        length = before + 1;
    }

    long long get_sec_max() const { return find_sec_max(root); }
    long long getMax()       const { return find_max(root); }

    vector<long long> getLeaves() const {
        vector<long long> res;
        get_leaves(root, res);
        return res;
    }

    vector<long long> getFamily() const {
        vector<long long> res;
        get_family(root, res);
        return res;
    }

    size_t size() const { return length; }

    bool erase(long long val) {
        if (!contains(root, val)) return false;
        root = destructNode(root, val);
        if (length > 0) --length;
        return true;
    }

    bool print_root() {
        if (!root) return false;
        cout << root->value;
        return true;
    }
};
