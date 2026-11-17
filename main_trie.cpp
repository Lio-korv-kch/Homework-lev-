#include <iostream>
#include "BinaryTreee_mod.hpp"

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<string> words;
    vector<string> seps;

    int n = s.size();
    int i = 0;
    int start = 0;
    while (i < n && s[i] == '.') i++;
    seps.push_back(s.substr(0, i));

    while (i < n) {
        int wstart = i;
        while (i < n && s[i] != '.') i++;
        words.push_back(s.substr(wstart, i - wstart));

        int dstart = i;
        while (i < n && s[i] == '.') i++;
        seps.push_back(s.substr(dstart, i - dstart));
    }

    sort(words.begin(), words.end());

    string res;
    for (int k = 0; k < (int)words.size(); k++) {
        res += seps[k];
        res += words[k];
    }
    res += seps.back();

    cout << res << endl;
}
}
