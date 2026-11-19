#include <iostream>
#include "stack.hpp"

using namespace std;

int main() {
    Stack<long long> st;
    long long n;

    if (!(cin >> n)) return 0;

    for (long long i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        st.push(x);
    }

    Stack<long long> tmp;

    while (!st.empty()) {
        long long cur = st.top();
        st.pop();

        while (!tmp.empty() && tmp.top() > cur) {
            st.push(tmp.top());
            tmp.pop();
        }

        tmp.push(cur);
    }

    while (!tmp.empty()) {
        st.push(tmp.top());
        tmp.pop();
    }

    st.print();
    cout << '\n';
}
