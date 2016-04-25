#include <bits/stdc++.h>
using namespace std;

// 開区間！！！なので注意

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
}; Pool pool;

template<class T>
class AssosiativeOperator {
public:
    AssosiativeOperator(void) { }
    T T0; // 単位元
    virtual T op(T a, T b) = 0; // 結合二項演算

    // 以下は、範囲更新クエリのために必要。点更新しかしないなら、そもそも呼ばれないので、適当な値を返してよい。
    virtual T op_lazy(T a, T b) = 0; // 遅延更新クエリの結合二項演算
    virtual T resolve_lazy(T d, T l, int nl, int nr) = 0; // 頂点(量d)が、その子ら[nl, nr)の遅延更新クエリlを解消した時の、頂点の量
};

template<class T>
class AssosiativeOperatorSum : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorSum(void) { }
    T T0 = 0;
    virtual T op(T a, T b) { return a + b; } // Range Sum
    virtual T op_lazy(T a, T b) { return a + b; } // Range Add
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return d + l * (nr - nl); }  // 子の数だけ総和が増える
};

template<class T>
class AssosiativeOperatorMax : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorMax(void) { }
    T T0 = std::numeric_limits<T>::min();
    virtual T op(T a, T b) { return max(a, b); } // Range Max
    virtual T op_lazy(T a, T b) { return a + b; } // Range Add
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return d + l; } // 全部上がってるので、子によらず増える
};

template<class T>
class AssosiativeOperatorMin : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorMin(void) { }
    T T0 = std::numeric_limits<T>::max();
    virtual T op(T a, T b) { return min(a, b); } // Range Min
    virtual T op_lazy(T a, T b) { return a + b; } // Range Add
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return d + l; } // 全部上がってるので、子によらず増える
};



// 範囲更新はデフォルトOFFなので、範囲更新が必要ならenableRangeUpdate(true)にして*_lazyを実装すること。
template<class T>
struct SegmentTree {
    // dat, lazyのデータ構造
    // 0123456789ABCDEF // インターフェースの添字
    // ################
    // 1---------------
    // 2-------3-------
    // 4---5---6---7---
    // 8-9-A-B-C-D-E-F-
    // GHIJKLMNOPQRSTUV

    // v<<1, v<<1|1は子どもたちを表している

    T *dat, *lazy;
    AssosiativeOperator<T>* op;
    int n = 1, ql, qr;
    const size_t size_;
    bool enable_range_update_flag = false;
    SegmentTree(int n_, AssosiativeOperator<T>* op) : size_(n_) {
        this->op = op;
        while(n < n_) n <<= 1;
        dat = pool.fetch<T>(n+n);
        lazy = pool.fetch<T>(n+n);
        fill_n(dat, n*4, 0);
    }
    void enableRangeUpdate(bool flag) {
        enable_range_update_flag = flag;
    }
    // 親→子
    // lazy[v]: vとその子供たち[nl, nr)の全員はquery(lazy[v])を遅延しているという意味
    // 親のlazyを解消して子に押し付ける
    // 子がいなければ押し付けない
    void inline pushdown(int v, int nl, int nr){
        assert(enable_range_update_flag);
        dat[v] = op->resolve_lazy(dat[v], lazy[v], nl, nr);
        if(v < n){ // 子がいれば
            lazy[v<<1] = op->op_lazy(lazy[v<<1], lazy[v]);
            lazy[v<<1|1] = op->op_lazy(lazy[v<<1|1], lazy[v]);
        }
        lazy[v] = 0;
    }
    // 子→親
    void inline pullup(int v){
        assert(enable_range_update_flag);
        dat[v] = op->op(dat[v<<1], dat[v<<1|1]); 
    }
    // 点更新
    void update(int v, const T &x){
        v += size();
        dat[v] = op->op(dat[v], x);
        while (v){
            v = v >> 1;
            dat[v] = op->op(dat[v<<1], dat[v<<1|1]); //親の区間の和は, 子の区間の和を足しあわせたもの.
        }
    }
    // 範囲更新
    void update(int n, int nl, int nr, const T &x){
        assert(enable_range_update_flag);
        if(nr <= ql || qr <= nl)
            return;
        if(ql <= nl && nr <= qr) {
            lazy[n] = op->op_lazy(lazy[n], x);
            pushdown(n, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(n<<1, nl, m, x);
        update(n<<1|1, m, nr, x);
        pullup(n);
    }
    void update(int l, int r, const T &x){
        ql = l; qr = r;
        return update(1, 0, size(), x);
    }
    T query(int n, int nl, int nr){
        if (enable_range_update_flag)
            pushdown(n, nl, nr);
        if(nr <= ql || qr <= nl) return op->T0;     // 範囲外
        if(ql <= nl && nr <= qr) return dat[n]; // ぴったりな範囲

        if (enable_range_update_flag)
            pullup(n);
        int m = (nl + nr) / 2;
        return op->op(query(n<<1, nl, m), query(n<<1|1, m, nr));
    }
    T query(int l, int r){
        ql = l; qr = r;
        return query(1, 0, size());
    }
    size_t size() const { return size_; }
};

int main(void) {
    int n = 16;

//    SegmentTree<int> s(n, new AssosiativeOperatorMax<int>());
//    SegmentTree<int> s(n, new AssosiativeOperatorMin<int>());
    SegmentTree<int> s(n, new AssosiativeOperatorSum<int>());

    s.enableRangeUpdate(true); // これを切ると、op_lazy, resolve_lazyが定義不要になる。範囲更新しようとするとassertで落ちる。

    // 範囲
    for (int i = 0; i < n; i++) 
        s.update(i, i+1, i);
    // 点
    for (int i = 0; i < n; i++) 
        s.update(i, i);

    for (int i = 0; i < n*2; i++) {
        cout << i << " " << s.dat[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << i << " " << s.query(0, i+1) << endl;
    }

    return 0;
}
