#include <bits/stdc++.h>
using namespace std;

//セグ木の理解とともに、GeneralSegmentがひどいライブラリに見えるようになってきた
//
//ノードの一部だけをupdateする
//でも全部もできるようになってほしい
//構築不要の場合があるので、ノードを直接叩けるようになっていて欲しい
//無駄に結合opクラス作るの良くない
//単位元は構築サボる時以外いらない

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ld, ld> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

// 半開区間！！！なので注意

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
    T L0; // 単位操作
    virtual T op_lazy(T a, T b) = 0; // 遅延更新クエリの結合二項演算。元の値がaで、今新しく来たの値がb。
    virtual T resolve_lazy(T d, T l, int nl, int nr) = 0; // 頂点(量d)が、その子ら[nl, nr)の全遅延更新クエリlを解消した時の、頂点の量
};

template<class T>
class AssosiativeOperatorSum : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorSum(void) { AssosiativeOperator<T>::T0 = 0; AssosiativeOperator<T>::L0 = 0; }
    virtual T op(T a, T b) { return a + b; } // Range Sum
    virtual T op_lazy(T a, T b) { return a + b; } // Range Add
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return d + l * (nr - nl); }  // 子の数だけ総和が増える
};

/*
   レンジアサインsumってどうすればいいの？
template<class T>
class AssosiativeOperatorSumAssign : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorSumAssign(void) { }
    T T0 = 0;
    virtual T op(T a, T b) { return a + b; } // Range Sum
    T L0 = 0; // 単位操作
    virtual T op_lazy(T a, T b) { return a + b; } // Range Assign
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return l * (nr - nl); }  // 子の数だけ総和が増える
};
*/


template<class T>
class AssosiativeOperatorMax : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorMax(void) { AssosiativeOperator<T>::T0 = std::numeric_limits<T>::min(); AssosiativeOperator<T>::L0 = 0; }
    virtual T op(T a, T b) { return max(a, b); } // Range Max
    virtual T op_lazy(T a, T b) { return a + b; } // Range Add
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return d + l; } // 全部上がってるので、子によらず増える
};

template<class T>
class AssosiativeOperatorMin : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorMin(void) { AssosiativeOperator<T>::T0 = std::numeric_limits<T>::max(); AssosiativeOperator<T>::L0 = 0; }
    virtual T op(T a, T b) { return min(a, b); } // Range Min
    virtual T op_lazy(T a, T b) { return a + b; } // Range Add
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return d + l; } // 全部上がってるので、子によらず増える
};

template<class T>
class AssosiativeOperatorLinearFunction : public AssosiativeOperator<pair<T, T>> {
public:
    AssosiativeOperatorLinearFunction(void) { AssosiativeOperator<pair<T, T>>::T0 = P(1, 0); }
    virtual P op(P a, P b) { return P(b.first * a.first, b.second + b.first * a.second); }
    virtual P op_lazy(P a, P b) { return P(0, 0); } // not valid
    virtual P resolve_lazy(P d, P l, int nl, int nr) { return P(0, 0); } // not valid
};


template<class T>
class SegmentTree {
public:
    // dat, lazyのデータ構造
    // 0123456789ABCDEF // インターフェースの添字
    // ################
    // 1--------------- // datの添字, 0は使わない！！
    // 2-------3-------
    // 4---5---6---7---
    // 8-9-A-B-C-D-E-F-
    // GHIJKLMNOPQRSTUV

    // v<<1, v<<1|1は子どもたちを表している
    // lazy[v]: vとその子供たち[nl, nr)の全員はquery(lazy[v])を遅延しているという意味
    T *dat, *lazy; 
    AssosiativeOperator<T>* op;
    int n = 1; // 確保しているサイズ！
    int bits = 0; // n == 1 << bits
    const size_t size_; // 確保しているサイズではない！！
    int ql, qr;
    bool enable_range_update_flag = false;
    bool enable_point_update_with_op_flag = false;
    SegmentTree(int n_, AssosiativeOperator<T>* op) : size_(n_) {
        this->op = op;
        while(n < n_) { n <<= 1; bits++; }
        dat = pool.fetch<T>(n+n);
        lazy = pool.fetch<T>(n+n);
        fill_n(dat, n*4, this->op->T0);
    }
    void enableRangeUpdate(bool flag) { enable_range_update_flag = flag; }
    void enablePointUpdateWithOp(bool flag) { enable_point_update_with_op_flag = flag; }
    // 親→子
    // これが呼ばれると、必ずvが正しい状態になる！
    // 親のlazyを解消して子に押し付ける
    // 子がいなければ押し付けない
    void inline pushdown(int v, int nl, int nr){
        assert(enable_range_update_flag);
        dat[v] = op->resolve_lazy(dat[v], lazy[v], nl, nr);
        if(v < n){ // 子がいれば
            lazy[v<<1] = op->op_lazy(lazy[v<<1], lazy[v]);
            lazy[v<<1|1] = op->op_lazy(lazy[v<<1|1], lazy[v]);
        }
        lazy[v] = op->L0;
    }
    // 子→親
    void inline pullup(int v){
        assert(enable_range_update_flag);
        dat[v] = op->op(dat[v<<1], dat[v<<1|1]); 
    }
    // 点更新
    void update(int v, const T &x){
        v += n;
        if (enable_point_update_with_op_flag) 
            dat[v] = op->op(dat[v], x);
        else
            dat[v] = x;
        while (v){
            v = v >> 1;
            dat[v] = op->op(dat[v<<1], dat[v<<1|1]); 
        }
    }
    // 範囲更新
    // 範囲番号nの区間[nl, nr)にop(x)を演算する
    void update(int n, int nl, int nr, const T &x){
        // この関数は、[ql, qr)より上のノードとその子の全てにHITする
        assert(enable_range_update_flag);
        pushdown(n, nl, nr);
        if(nr <= ql || qr <= nl) return;
        if(ql <= nl && nr <= qr) {
            // 一回の区間更新に付き最大3回、した区間が小さい順にHitする。
            lazy[n] = op->op_lazy(lazy[n], x);
            pushdown(n, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        update(n<<1, nl, m, x);     // 子供1
        update(n<<1|1, m, nr, x);   // 子供2
        pullup(n);
    }
    // [l, r)にop(x)の演算を行う。
    void update(int l, int r, const T &x){
        ql = l; qr = r;
        return update(1, 0, n, x);
    }
    // 範囲クエリ
    // 範囲番号nの区間[nl, nr)にop(x)を演算結果を返す
    T query(int n, int nl, int nr){
        // この関数は、[ql, qr)より上のノードとその子の全てにHITする
        if (enable_range_update_flag) pushdown(n, nl, nr);
        if(nr <= ql || qr <= nl) return op->T0;
        if(ql <= nl && nr <= qr) return dat[n]; // 一回の区間更新に付き最大3回、した区間が小さい順にHitする。
        if (enable_range_update_flag) pullup(n);
        int m = (nl + nr) / 2;
        return op->op(query(n<<1, nl, m), query(n<<1|1, m, nr)); 
    }
    // [l, r)の演算結果を出力
    T query(int l, int r){
        ql = l; qr = r;
        return query(1, 0, n);
    }
    // lの値を出力
    T query(int l){
        return query(l, l + 1);
    }

    void print(void) {
        rep(i, size()) { cout << query(i) << " "; } cout << endl;
    }
    void printAll(void) {
        for (int i = 1; i < n * 2; i++) { 
            cout << dat[i];
            int j = i, count = 0; while (j) { j /= 2; count++; } 
            for (int j = 0; j < (1 << (bits - count + 1)); j++) cout << "\t"; 
            if (__builtin_popcount(i+1) == 1) cout << endl; 
        } 
        cout << endl;
    }
    void printLazy(void) {
        for (int i = 1; i < n * 2; i++) { 
            cout << lazy[i];
            int j = i, count = 0; while (j) { j /= 2; count++; } 
            for (int j = 0; j < (1 << (bits - count) + 1); j++) cout << "\t"; 
            if (__builtin_popcount(i+1) == 1) cout << endl; 
        } 
        cout << endl;
    }

    size_t size() const { return size_; }
};

int main(void) {
    int n = 7;

    {
        //    SegmentTree<int> s(n, new AssosiativeOperatorMax<int>());
        //    SegmentTree<int> s(n, new AssosiativeOperatorMin<int>());
        SegmentTree<int> s(n, new AssosiativeOperatorSum<int>());

        // 範囲更新はデフォルトOFFなので、範囲更新が必要ならenableRangeUpdate(true)して*_lazyを実装すること。
        // これを切ると、op_lazy, resolve_lazyが定義不要になる。そして、範囲更新しようとするとassertで落ちる。
        s.enableRangeUpdate(true); 

        // 点更新の時、デフォルトはPointAssignなので、PointAddのようにopで更新したいなら以下をtrueにする。
        s.enablePointUpdateWithOp(true);

        /*
        // 範囲
        for (int i = 0; i < n; i++) 
            s.update(i, i+1, i);
        // 点
        for (int i = 0; i < n; i++) 
            s.update(i, i);
            */

        while (1) {
            cout << "[ruq] l r val" << endl;
            char mode; cin >> mode;
            int a, b, c; cin >> a >> b >> c;
            if (mode == 'r') // resolve lazy 
                s.print();
            else if (mode == 'u')
                s.update(a, b, c);
            else if (mode == 'q')
                cout << s.query(a, b) << "#query" << endl;
            s.printAll();
            s.printLazy();
        }
    }
}
