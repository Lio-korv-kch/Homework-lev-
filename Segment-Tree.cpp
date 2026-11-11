#include <iostream>
#include <vector>
using namespace std;

class Tree{
private:
    int n;
    vector<int> t;
public:

    Tree(const vector<int>& arr){
        n = arr.size();
        t.assign(2 * n,0);
        for (int i = 0; i < n; ++i){
            t[n+i] = arr[i];
        }
    build();
    }

    void build() {
        for (int i = n-1; i > 0 ;--i){
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }

    int sum (int l, int r){
        int sum = 0;
        for(l += n , r += n; l < r; l >>= 1 , r >>= 1){
           if (l& 1){
                sum += t[l];
                l++;
           }
           if (r& 1){
                r--;
                sum += t[r];
           }
        }
        return sum;
    }

    void modify(int p, int value){
        for (t[p+=n] = value; p > 1; p >>= 1)       {t[p >> 1] = t[p] + t[p^1];}
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    Tree tree(arr);
    int N;
    cin >> N;
    for (int i  = 0; i < N; i++){
        int p,value;
        cin >> p >> value;
        tree.modify(p,value);
        cout << "sum is : " << tree.sum(0,n) << endl;
    }
}
