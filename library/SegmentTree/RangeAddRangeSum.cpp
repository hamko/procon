#include <bits/stdc++.h>
using namespace std;

struct Pool {
    int pos;
    char mem[20000000]; // 20MB
    Pool(){ free(); }
    template<class T>
        T *fetch(size_t n = 1) {
            T *res = (T*)(mem + pos);
            pos += sizeof(T)*n;
            return res;
        }
    void free(){ pos = 0; }
};
Pool pool;

template<class T>
struct SegmentTree {
    T *dat, *lazy;
    int n, ql, qr;
    const size_t size_;
    SegmentTree(int n_) : size_(n_) {
        n = 1;
        while(n < n_) n <<= 1;
        dat = pool.fetch<T>(n+n);
        lazy = pool.fetch<T>(n+n);
        fill_n(dat, n*4, 0);
    }
    void pushdown(int v, int nl, int nr){
        dat[v] += lazy[v] * (nr - nl);
        if(v < n){
            lazy[v<<1] += lazy[v];
            lazy[v<<1|1] += lazy[v];
        }
        lazy[v] = 0;
    }
    void pullup(int v){
        dat[v] = dat[v<<1] + dat[v<<1|1];
    }
    void add(int n, int nl, int nr, const T &x){
        pushdown(n, nl, nr);
        if(nr <= ql || qr <= nl){
            return;
        } else if(ql <= nl && nr <= qr){
            lazy[n] += x;
            pushdown(n, nl, nr);
        } else {
            int m = (nl + nr) / 2;
            add(n<<1, nl, m, x);
            add(n<<1|1, m, nr, x);
            pullup(n);
        }
    }
    void add(int l, int r, const T &x){
        ql = l; qr = r;
        return add(1, 0, size(), x);
    }
    T sum(int n, int nl, int nr){
        pushdown(n, nl, nr);
        if(nr <= ql || qr <= nl){
            return 0;
        } else if(ql <= nl && nr <= qr){
            return dat[n];
        } else {
            int m = (nl + nr) / 2;
            T l = sum(n<<1, nl, m);
            T r = sum(n<<1|1, m, nr);
            pullup(n);
            return l + r;
        }
    }
    T sum(int l, int r){
        ql = l; qr = r;
        return sum(1, 0, size());
    }
    size_t size() const { return size_; }
    vector<T> to_a(int l = -1, int r = -1){
        if(l == -1) l = 0;
        if(r == -1) r = size();
        vector<T> res(r-l);
        for(int i = l; i < r; i++) res[i-l] = sum(i, i+1);
        return res;
    }
    T operator [] (const int &idx) { return sum(idx, idx + 1); }
};

int main(void) {
    int n = 10;
    SegmentTree<int> s(n);
    s.add(0, 10, 1);
    s.add(0, 5, 2);
    s.add(3, 5, 3);
    cout << s.sum(0, 10) << endl;

    for (int i = 0; i < n; i++) 
        cout << s[i] << " ";
    cout << endl;

    return 0;
}
