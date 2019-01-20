#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTreeMin {
    int n;
    T inf;
    vector<T> dat;
    SegmentTreeMin(int n_ = 0) : n(n_){
        inf = 1e18;
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, inf);
    }
    T query(int v, int w, int l, int r){
        if(r <= l || w == 0) return inf;
        if(r - l == w) return dat[v]; // assert(l == 0 && r == w);
        int m = w/2;
        return min(query(v*2, m, l, min(r,m)), query(v*2+1, m, max(0,l-m), r-m));
    }
    void update(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) dat[i/2] = min(dat[i], dat[i^1]);
    }
    T query(int l, int r){ return query(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return query(idx, idx + 1); }
};

template<class T>
struct SegmentTreeMax {
    int n;
    T inf;
    vector<T> dat;
    SegmentTreeMax(int n_ = 0) : n(n_){
        inf = -1e18;
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, inf);
    }
    T query(int v, int w, int l, int r){
        if(r <= l || w == 0) return inf;
        if(r - l == w) return dat[v]; // assert(l == 0 && r == w);
        int m = w/2;
        return max(query(v*2, m, l, min(r,m)), query(v*2+1, m, max(0,l-m), r-m));
    }
    void update(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) dat[i/2] = max(dat[i], dat[i^1]);
    }
    T query(int l, int r){ return query(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return query(idx, idx + 1); }
};


int main(void) {
    SegmentTreeMin<int> s(10);
    s.update(0, 10);
    s.update(1, 4);
    s.update(2, 6);

    cout << s[1] << endl;
    cout << s.query(0, 1) << endl;
    cout << s.query(0, 2) << endl;
    cout << s.query(0, 3) << endl;
    return 0;
}
