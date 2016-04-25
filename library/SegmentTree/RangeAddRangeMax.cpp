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
    T T0 = 1e8;

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
    void pushdown(int v){
        dat[v] += lazy[v];
        if(v < n){
            lazy[v<<1] += lazy[v];
            lazy[v<<1|1] += lazy[v];
        }
        lazy[v] = 0;
    }
    void pullup(int v){
        dat[v] = std::max(dat[v<<1], dat[v<<1|1]);
    }
    void add(int n, int nl, int nr, const T &x){
        pushdown(n);
        if(nr <= ql || qr <= nl){
            return;
        } else if(ql <= nl && nr <= qr){
            lazy[n] += x;
            pushdown(n);
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
    T max(int n, int nl, int nr){
        pushdown(n);
        if(nr <= ql || qr <= nl){
            return -T0;
        } else if(ql <= nl && nr <= qr){
            return dat[n];
        } else {
            int m = (nl + nr) / 2;
            T l = max(n<<1, nl, m);
            T r = max(n<<1|1, m, nr);
            pullup(n);
            return std::max(l, r);
        }
    }
    T max(int l, int r){
        ql = l; qr = r;
        return max(1, 0, size());
    }
    size_t size() const { return size_; }
    vector<T> to_a(int l = -1, int r = -1){
        if(l == -1) l = 0;
        if(r == -1) r = size();
        vector<T> res(r-l);
        for(int i = l; i < r; i++) res[i-l] = max(i, i+1);
        return res;
    }
    T operator [] (const int &idx) { return max(idx, idx + 1); }
};

int main(void) {
    int n = 10;
    SegmentTree<int> s(n);
    s.add(0, 10, 1);
    s.add(0, 5, 2);
    s.add(3, 5, 3);
    cout << s.max(0, 10) << endl;

    for (int i = 0; i < n; i++) 
        cout << s[i] << " ";
    cout << endl;

    return 0;
}
