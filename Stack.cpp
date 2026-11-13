#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data_;

public:
    bool empty() const { return data_.empty(); }
    long long size() const { return data_.size(); }

    T& top() { return data_.back(); }
    const T& top() const { return data_.back(); }

    void push(const T& v) { data_.push_back(v); }
    void push(T&& v) { data_.push_back(move(v));}

    void pop() {
        if (!data_.empty()) data_.pop_back();
    }

    void clear() { data_.clear(); }

    bool contains(const T& v) const {
        return find(data_.begin(), data_.end(), v) != data_.end();
    }

    void reverse() {
        reverse(data_.begin(), data_.end());
    }

    bool top_is_power_of_two() const {
        if (data_.empty()) return false;
        long long x = static_cast<long long>(data_.back());
        if (x <= 0) return false;
        double l = log2(static_cast<double>(x));
        return floor(l) == l;
    }

    void print(ostream& os = cout) const {
        for (size_t i = data_.size(); i-- > 0; ) {
            os << data_[i];
            if (i > 0) os << ", ";
        }
    }
};
