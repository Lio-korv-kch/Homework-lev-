#include <iostream>
#include "Mother_BST.hpp"
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    BinaryTree tree;
    for (int i = 0; i < n; ++i) {
        long long temp;
        cin >> temp;
        tree.insert(temp);
    }

    while (tree.size() > 1) {
        long long a = tree.getMax();
        long long b = tree.get_sec_max();
        tree.erase(a);
        tree.erase(b);
        if (a != b) tree.insert(a - b);
    }

    if (tree.size() == 0) cout << 0 << '\n';
    else cout << tree.getMax() << '\n';

}
