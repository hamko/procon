#include <bits/stdc++.h>
using namespace std;

// Point Assign Range Sum
template<class T>
struct SegmentTreeSum {
    int n;
    T inf;
    vector<T> dat;
    SegmentTreeSum(int n_ = 0) : n(n_){
        inf = 0;
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, inf);
    }
    T sum(int v, int w, int l, int r){
        if(r <= l || w == 0) return inf;
        if(r - l == w) return dat[v]; // assert(l == 0 && r == w);
        int m = w/2;
        return (sum(v*2, m, l, min(r,m)) + sum(v*2+1, m, max(0,l-m), r-m));
    }
    void assign(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) dat[i/2] = dat[i] + dat[i^1];
    }
    T sum(int l, int r){ return sum(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return sum(idx, idx + 1); }
};

int main(void) {
    fenwick_tree<int> f(1000);
    f.add(0, 10);
    f.add(1, 100);
    f.add(1, -f[1] + 99); // assign

    cout << f.sum(0, 1) << endl;
    cout << f.sum(0, 2) << endl;
    cout << f.sum(0, 3) << endl;
    cout << f.sum(1, 2) << endl;
    cout << f.sum(1, 3) << endl;
    cout << f.sum(2, 3) << endl;
    cout << f[0] << endl;
    cout << f[1] << endl;
    cout << f[2] << endl;
    

    return 0;
}
