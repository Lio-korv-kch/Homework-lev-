#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    char symbol;
    bool is_end_of_word;
    vector<Node*> children;
    int count;
    Node(char ch = '\0') : symbol(ch), is_end_of_word(false), count(0) {}
};

class Trie {
    private:
        Node* root;

        void insert(string word){
            Node* cur_node = root;
            for(char cSymbol : word){
                bool met_end = false;
                for(auto const cChild : cur_node->children){
                    if (cChild->symbol == cSymbol)  {
                        cur_node = cChild;
                        met_end = true;
                        break;
                    }
                }
                if(!met_end){
                    Node* node = new Node(cSymbol);
                    cur_node->children.push_back(node);
                    cur_node = node;
                }
            }
            cur_node->is_end_of_word = true;
        }

        bool does_start_with (string prefix){
            Node* cur_node = root;
            int truth_counter = 0;
            int counter = 0;
            for(char cSymbol : prefix){
                counter++;
                for(auto const cChild : cur_node->children){
                    if (cChild->symbol == cSymbol)  {
                        truth_counter++;
                        cur_node = cChild;
                        break;
                    }
                }
            }
            if (truth_counter == counter){
                return true;
            }
            else{
                return false;
            }
        }
        bool containss(string word){
            Node* cur = root;
            int truth_counter = 0;
            int counter = 0;
            for(char cSymbol : word){
                counter++;
                for(int i = 0; i < (int)cur->children.size(); i++){
                    if (cur->children[i]->symbol == cSymbol)  {
                        truth_counter++;
                        cur = cur->children[i];
                        break;
                    }
                }
            }
            if (truth_counter == counter && cur->is_end_of_word){
                return true;
            }
            else{
                return false;
            }

        }
    public:
        Trie() : root(new Node()) {}
        ~Trie() {delete root;}
        void enplace(const string& word){insert(word);}
        bool starts_with_prefix(const string& prefixx){return does_start_with(prefixx);}
        bool contains(const string& word){return containss(word);}

};
