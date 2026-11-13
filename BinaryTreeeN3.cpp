#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node{
    public:
    Node *left;
    Node *right;
    long long value;
    Node(long long val) : left(nullptr), right(nullptr), value(val) {}
};
//tesrt
class BinaryTree{
private:
    int length;
    Node *root;


    Node* insert(Node* node, long long val){
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->value){
            node->left = insert(node->left,val);
        }
        else if (val > node->value){
            node->right = insert(node->right,val);
        }
        return node;
    }

    long long find_max (Node* node){
        while (node != nullptr && node->right != nullptr){
            node = node->right;
        }
        return node->value;
    }

    long long find_sec_max (Node* node){
    Node* cur_node = node;
    while (cur_node != nullptr){
        if (cur_node->right != nullptr){
            if (cur_node->right->right == nullptr && cur_node->right->left == nullptr){
                return cur_node->value;
            }
            if (cur_node->right->right == nullptr && cur_node->right->left != nullptr){
                return find_max(cur_node->right->left);
            }
            cur_node = cur_node->right;
        }
        else{
            return find_max(cur_node->left);
        }
    }
    return -1;
    }

    bool isLeath (Node* node){
    if (node->left == nullptr && node->right == nullptr){
        return true;
    }
    else{
        return false;
    }
    }

    void get_leathes(Node* node, vector <long long>& res){
        if(node == nullptr){
            return;
        }
        if (isLeath(node)){
            res.push_back(node->value);
            return;
        }
        get_leathes(node->left, res);
        get_leathes(node->right, res);
    }

    bool hasTwoChildren(Node* node) {
    if (node == nullptr) {
        return false;
    } else if (node->left != nullptr && node->right != nullptr) {
        return true;
    } else {
        return false;
    }
    }

     void get_family(Node* node, vector <long long>& res){
        if(node == nullptr){
            return;
        }
        if (hasTwoChildren(node)){
            res.push_back(node->value);
        }
        get_family(node->left, res);
        get_family(node->right, res);
    }

public:

    BinaryTree() {
        length = 0;
        root = nullptr;
    }

    void build (const vector <long long>& arr){
    for (int i = 0; i < arr.size(); i++) {
            root = insert(root, arr[i]);
            length++;
        }
    }

    long long get_sec_max(){
        return find_sec_max(root);
    }
    vector<long long> getLeaves() {
        vector<long long> res;
        get_leathes(root, res);
        return res;
    }

    vector<long long> getFamily() {
        vector<long long> res;
        get_family(root, res);
        return res;
    }
};

