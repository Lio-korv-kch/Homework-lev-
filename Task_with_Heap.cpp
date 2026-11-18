#include <iostream>
#include "Min_Heap.hpp"
using namespace std;

int main(){
    int cur_element;
    MinHeap heap;
    while (cin >> cur_element){
        heap.insert(cur_element);
    }
    heap.print();
}
