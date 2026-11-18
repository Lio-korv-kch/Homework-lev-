#include <iostream>
#include "Heap_mod.hpp"

using namespace std;

int main() {
int n;
cin >> n;
MaxHeap heap;
for (int i = 0; i < n; i++){
    int command;
    cin >> command;
    if (command == 0 && heap.size() == 0){
        int num;
        cin >> num;
        heap.builder(vector <int> {num});
    }
    else if (command == 0 && heap.size() != 0){
        int num;
        cin >> num;
        heap.insert(num);
    }
    if (command == 1){
         cout << heap.top() << endl;
         heap.pop();
    }
}
}
}
