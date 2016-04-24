#include <bits/stdc++.h>
using namespace std;

// sumは閉区間なので注意！！
// add O(log n), sum O(log n)
// add(k, a) == v[k] = v[k] + a, sum(i, j) == v[i] + ... + v[j] 
// +は加群=結合・可換・可逆なら他のものでもOK
template <class T>
struct fenwick_tree {
    vector<T> x;
    fenwick_tree(int n) : x(n, 0) { }
    // O(log n)
    T sum(int i, int j) {
        if (i) return sum(0, j) - sum(0, i-1);
        T S = 0;
        for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j]; // 加群なら+以外に
        return S;
    }
    // O(log n)
    void add(int k, T a) {
        for (; k < x.size(); k |= k+1) x[k] += a; // 加群なら+以外に
    }
    // O(log n)
    T operator [] (const int &idx) { return sum(0, idx) - sum(0, idx - 1); }
};

int main(void) {
    fenwick_tree<int> f(1000);
    f.add(0, 10);
    f.add(1, 100);
    f.add(1, -f[1] + 99); // assign

    cout << f.sum(0, 0) << endl;
    cout << f.sum(0, 1) << endl;
    cout << f.sum(0, 2) << endl;
    cout << f.sum(1, 1) << endl;
    cout << f.sum(1, 2) << endl;
    cout << f.sum(2, 2) << endl;
    cout << f[0] << endl;
    cout << f[1] << endl;
    cout << f[2] << endl;
    

    return 0;
}
