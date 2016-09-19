#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define ldout fixed << setprecision(40) 
static const long long INF = 1e18;


// 静的木
// できること
//
// 木の重心を求める O(n)
// 最短パスの頂点に乗った群データの積分 O(n)
// 頂点から根までの頂点の二分探索 O(log n)
// 頂点からn個親の頂点jを知る O(log n)
// 頂点iからn個親の頂点jまでの、辺の積分を知る O(log n)
//
// accumulateはモノイドデータに対して使う単語
// sumは群データに対して使う単語



/******************/
// Fenwick Tree
/******************/
// 0-indexed, sumは閉区間なので注意！！
template <class T> struct fenwick_tree {
    T T0 = 0; T op(T a, T b) { return a + b; }
    int n_org;
    vector<T> x;
    fenwick_tree(int n_)  { n_org = n_; int n = 1; while (n <= n_) n *= 2; x = vector<T>(n, T0); }
    fenwick_tree(void) {}
    T query(int j) { T S = T0; for (; j >= 0; j = (j & (j + 1)) - 1) S = op(S, x[j]); return S; }
    void update(int k, T a) { for (; k < x.size(); k |= k+1) x[k] = op(x[k], a); }
    T access(int k) { return query(k) - (k ? query(k-1) : 0); }
    void print(void) { for (int i = 0; i < n_org; i++) cout << access(i) << " "; cout << endl; }
};

/******************/
// Segment Tree
/******************/
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
    size_t size_; // 確保しているサイズではない！！
    int ql, qr;
    bool enable_range_update_flag = false;
    bool enable_point_update_with_op_flag = false;
    SegmentTree(void) : size_(0) { }
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

// 静的木
//
// 構築O(n): オイラーツアー, 木の高さ, 祖先ダブリング
//
// LCA O(log n)
// 頂点間最小辺数 O(log n)
// 頂点から根までのパスの二分探索 O(log n)
struct edge_t { int from, to; ll weight; };
using verticle_t = ll;
class Tree {
public:
    int MAXLOGV;
    vector<vector<edge_t>> m_edges; // m_edges[i][j]が存在: i->jの辺が存在
    int vn; // 頂点の数, vn<2^MAXLOGV
    int root; // 根ノードの番号

    vector<verticle_t> m_verticles; 
    vector<vector<verticle_t>> m_verticles_doubling; // m_verticles_doubling[i][j]: jのi^2番目の親までのm_vertivlesの結合演算opによる積分

    AssosiativeOperator<verticle_t>* op;

    vector<vector<int>> parent; // parent[i][j]: jのi^2番目の親。j=0で直近の親。
    vector<int> depth; // depth[i]: 頂点iの根からの深さ, 根が0

    /*********/
    // オイラーツアー
    /*********/
    vector<int> m_euler; // 根から始めるオイラーツアー、長さvn*2
    fenwick_tree<verticle_t> m_euler_verticles_positive; // 1回目で+, 2回目で+になる頂点に載ったデータ, 長さvn*2
    fenwick_tree<verticle_t> m_euler_verticles_negative; // 1回目で+, 2回目で-になる頂点に載ったデータ, 長さvn*2
    SegmentTree<verticle_t> m_euler_verticles_positive_segment; // 1回目で+, 2回目で+になる頂点に載ったデータ, 長さvn*2
    vector<int> m_euler_appears_first; // f[i] = eulerでiが出てくる1回目の位置, 長さvn
    vector<int> m_euler_appears_second; // f[i] = eulerでiが出てくる2回目の位置, 長さvn


    /*********/
    // 構築
    /*********/
    Tree(int vn, int root, AssosiativeOperator<verticle_t>* op_init) : vn(vn), root(root) {
        op = op_init;

        MAXLOGV = ceil(log(vn) / log(2)) + 2; // +2は念の為
        m_edges.resize(vn);
        m_verticles.resize(vn);
        parent.resize(MAXLOGV); rep(i, MAXLOGV) parent[i].resize(vn);

        m_verticles_doubling.resize(MAXLOGV); rep(i, MAXLOGV) m_verticles_doubling[i].resize(vn);
        rep(i, m_verticles_doubling.size()) rep(j, m_verticles_doubling[0].size()) 
            m_verticles_doubling[i][j] = op->T0;

        depth.resize(vn);
        m_euler_verticles_positive = fenwick_tree<verticle_t>(vn*2);
        m_euler_verticles_negative = fenwick_tree<verticle_t>(vn*2);
        m_euler_verticles_positive_segment = SegmentTree<verticle_t>(vn*2, op); 
    }

    // 辺の構築
    void unite(edge_t e) {
        m_edges[e.from].push_back({e.from, e.to, e.weight});
        m_edges[e.to].push_back({e.to, e.from, e.weight});
    }
    void unite(int u, int v) {
        unite({u, v, 1});
    }

    // 頂点の構築
    void setVerticle(int i, verticle_t v) {
        m_verticles_doubling[0][i] = m_verticles[i] = v;
    }

    // rootからの深さと親を確認。
    // uniteし終わったらまずこれを呼ぶこと。
    void init() {
        m_euler.clear(); m_euler.reserve(2 * vn);
        m_euler_appears_first.clear(); m_euler_appears_first.resize(vn);
        m_euler_appears_second.clear(); m_euler_appears_second.resize(vn);
        dfs(root, -1, 0);
        for (int k = 0; k+1 < MAXLOGV; k++) // 2^k代祖先を計算
            for (int v = 0; v < vn; v++) 
                if (parent[k][v] < 0) 
                    parent[k+1][v] = -1; // 2^k代親が根を超えてるなら、2^(k+1)代親も根を超える
                else 
                    parent[k+1][v] = parent[k][parent[k][v]]; // 2^(k+1)代の親は、2^k代親の2^k代親

        // 親のダブリング
        rep(k, MAXLOGV - 1) // 2^k代祖先を計算
            for (int v = 0; v < vn; v++) 
                if (parent[k][v] < 0) 
                    parent[k+1][v] = -1; // 2^k代親が根を超えてるなら、2^(k+1)代親も根を超える
                else 
                    parent[k+1][v] = parent[k][parent[k][v]]; // 2^(k+1)代の親は、2^k代親の2^k代親

        // 頂点の重みをダブリング
        // 頂点の重みはモノイドでOK
        rep(k, MAXLOGV-1) rep(v, vn) {
            ll tmp = m_verticles_doubling[k][v];
            int p = parent[k][v];
            if (p != -1) tmp = op->op(tmp, m_verticles_doubling[k][p]);
            m_verticles_doubling[k+1][v] = tmp;
        }

        // eulerのためのデータ用意
        rep(i, vn) { 
            m_euler_verticles_negative.update(m_euler_appears_first[i], +m_verticles[i]);
            m_euler_verticles_negative.update(m_euler_appears_second[i], -m_verticles[i]);
            m_euler_verticles_positive.update(m_euler_appears_first[i], +m_verticles[i]);
            m_euler_verticles_positive.update(m_euler_appears_second[i], +m_verticles[i]);
            m_euler_verticles_positive_segment.update(m_euler_appears_first[i], +m_verticles[i]);
            m_euler_verticles_positive_segment.update(m_euler_appears_second[i], +m_verticles[i]);
        }

        // HL分解
        constructHLD(); 
    }

    // 1つ親と深さとオイラーツアーを構築
    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        m_euler_appears_first[v]=m_euler.size();
        m_euler.push_back(v);
        for (edge_t next : m_edges[v]) 
            if (next.to != p)
                dfs(next.to, v, d+1);
        m_euler_appears_second[v]=m_euler.size();
        m_euler.push_back(v);
    }

    // 木の直径を求める
    // 辺が重み付きでもOK!
    //
    // O(V)
    ll diameter(void) {
        using Result = pair<ll, int>;
        function<Result(int, int)> visit = [&](int p, int v){ 
            Result r(0, v);
            for (auto e : m_edges[v]) if (e.to != p) {
                Result t = visit(v, e.to);
                t.first += e.weight;
                if (r.first < t.first) r = t;
            }
            return r;
        };

        Result r = visit(-1, 0);
        Result t = visit(-1, r.second);

        // このあと、r, tからの距離を使って木の中心を求めることができる。O(V)
        // t.firstが偶数なら、rからt.first/2かつtからt.first/2の距離
        // t.firstが偶数なら、rからt.first/2+1or+0かつtからt.first/2+1or+0の距離の二点
        
        return t.first; // (r.second, t.second) is farthest pair
    }

    /*************/
    // 頂点クエリ
    /*************/
    // 頂点u, vの最小共通先祖
    //
    // O(log n)
    int getParent(int index, ll n) const {
        ll ret = index;
        n = min(n, (1ll << MAXLOGV) - 1);
        rep(k, MAXLOGV) if (n & (1ll << k)) {
            ret = parent[k][ret];
        }
        return ret;
    }

    // 頂点u, vの最小共通先祖
    //
    // O(log n)
    int lca(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v); // uのほうが浅くなるように
        for (int k = 0; k < MAXLOGV; k++)    // vをuと同じ深さまで遡る
            if ((depth[v] - depth[u])>>k & 1) 
                v = parent[k][v];
        if (u == v) return u;
        for (int k = MAXLOGV-1; k >= 0; k--) { // 行き過ぎないギリギリで遡る
            if (parent[k][u] == parent[k][v]) // 行き過ぎ
                continue; 
            u = parent[k][u];
            v = parent[k][v];
        }
        return parent[0][u];
    }

    // uとvの距離を求める
    // 距離はエッジの重み=1としたときのもの
    //
    // O(log n)
    int dist(int u, int v) const {
        int p = lca(u, v);
        return (depth[u]-depth[p]) + (depth[v]-depth[p]);
    }

    // [root, v]のうち、fを満たす最も根側のノードを返す
    // 1つも満たさないなら-1を返す。
    //
    // O(log n)
    // 制約: 特性関数は、根から見て000000111111の形
    int binary_search(int v, function<bool(int)> f) const {
        for(int j = MAXLOGV - 1; j >= 0;j--) 
            if(parent[j][v] != -1 && f(parent[j][v]))
                v = parent[j][v];
        return f(v) ? v : -1;
    }

    /****************************************************/
    // 部分木に対するクエリ
    // モノイドに範囲更新・範囲クエリ (Lazy Segment Tree)
    /****************************************************/
    // uを根とする部分木に含まれる頂点全ての演算結果を求める。
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    verticle_t accumulateSubTree(int u) {
        return m_euler_verticles_positive_segment.query(m_euler_appears_first[u], m_euler_appears_second[u] + 1);
    }

    // 頂点uにxを足す
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    void addSubTree(int u, verticle_t x) {
        m_euler_verticles_positive_segment.update(m_euler_appears_first[u], x);
        m_euler_verticles_positive_segment.update(m_euler_appears_second[u], x);
    }

    // uを根とする部分木に含まれる頂点全てにxを足す
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    void addAllSubTree(int u, verticle_t x) {
        m_euler_verticles_positive_segment.enable_range_update_flag = true;
        m_euler_verticles_positive_segment.update(m_euler_appears_first[u], m_euler_appears_second[u] + 1, x);
    }

    /****************************************************/
    // 動的群データに対する最短パスの積分 (BIT)
    /****************************************************/
    // できること: op = sumの最短パスの積分
    // できないこと: op = min, max

    // u, vのパスの頂点に乗ったデータの総和を求める。
    //
    // O(log n)
    // 制約: 頂点のデータが群
    // 制約: u is parent of v !!!
    verticle_t sumMinimumLengthPathParentAndChild(int u, int v) {
        return m_euler_verticles_negative.query(m_euler_appears_first[v])
            - m_euler_verticles_negative.query(m_euler_appears_first[u] - 1);
    }

    // u, vの最短パスの頂点に乗ったデータの総和を求める。
    //
    // O(log n)
    // 制約: 頂点のデータが群
    verticle_t sumMinimumLengthPath(int u, int v) {
        int lca_v = lca(u, v); 
        return sumMinimumLengthPathParentAndChild(lca_v, u) 
            + sumMinimumLengthPathParentAndChild(lca_v, v);
    }

#if 0 // not yet
    // u, vのパスの頂点に乗ったデータの最小値を求める。
    // 群じゃないので、僕の知っている方法ではできない！
    // どうすればいい？？
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    // 制約: u is parent of v !!!
    verticle_t minMinimumLengthPathParentAndChild(int u, int v) {
        return m_euler_verticles_negative.query(m_euler_appears_first[v])
            - m_euler_verticles_negative.query(m_euler_appears_first[u] - 1);
    }

#endif

    /****************************************************/
    // 静的モノイドデータに対する最短パスの積分(ダブリング)
    /****************************************************/
    // できること: op = sum, min, maxの最短パスの積分
    // できないこと: データが静的なので、一度initしたら頂点に載せたデータを変えられない
 
    // uからn個上の頂点までに乗ったデータの結合演算opによる積分を求める。
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    // 制約: u is parent of v !!!
    verticle_t accumulateMinimumLengthPathParentAndChild(int u, ll n) {
        verticle_t ret = op->T0;
        ll index = u;
        n = min(n, (1ll << MAXLOGV) - 1);
        rep(k, MAXLOGV) if (n & (1ll << k)) {
            ret = op->op(ret, m_verticles_doubling[k][index]);
            index = parent[k][index];
        }
        return ret;
    }

    // u, vの最短パスの頂点に乗ったデータの結合演算opによる積分を求める。
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    verticle_t accumulateMinimumLengthPath(int u, int v) {
        int lca_v = lca(u, v); 
        return op->op(accumulateMinimumLengthPathParentAndChild(lca_v, depth[u] - depth[lca_v]), 
            accumulateMinimumLengthPathParentAndChild(lca_v, depth[v] - depth[lca_v]));
    }

    /*************/
    // 辺クエリ
    /*************/
    // そもそも、木では辺と頂点を同一視できるので必要ない！
    // 辺の重みを、子側の頂点に載せることで、頂点のテクニックと同様に取り扱うことができる

    /*********/
    // HL分解
    /*********/
    // heavy light decomposition
    //
    // 今までの番号を、Heavy-Lightパスの根から葉の方向へと付け替える in [0, n)
    // これ自体にはデータを載せず、パスの添字のみを取得するインターフェースのみ提供
    vector<int> treesize; // m_edges.size(): 子の数
    // i: ノードの添字
    // j: Heavy pathの添字
    int hl_size = 0; // Heavy pathの数
    vector<int> group; // m_edges.size(): ノードiが属するグループj
    vector<int> id; // m_edges.size(): ノードiに再割り振りされた新ノード番号id in [0, m_edges.size())
    vector<int> par; // hl_size: Heavy path jの根の親のノードi
    vector<int> bg; //  hl_size: Heavy path jの根のノードi
    void setTreeSize(int v, int p) {
        treesize[v]=1;
        for (auto &u:m_edges[v]) if (u.to != p) {
            cout << v << " " << p << " " << u.from << " " << u.to  << " " << p << endl;
            setTreeSize(u.to, v);
            treesize[v]+=treesize[u.to];
        }
    }
    void build(int v, int p, int g, int& i) {
        group[v]=g;
        id[v]=i++;
        if (m_edges[v].size() == 1) return;

        // 最大サイズの子hを求める
        int h=-1;
        for (auto &u:m_edges[v]) if (u.to != p) {
            if(treesize[h]<treesize[u.to]) {
                h=u.to;
            }
        }

        // Heavy
        build(h, v, g, i);

        // Light
        for (auto &u:m_edges[v]) if (u.to != p) if (h != u.to) { 
            cout << "*" << endl;
            par.push_back(v);
            bg.push_back(i);
            build(u.to, v, hl_size++, i);
        }
    }
    void constructHLD(void) {
        int n = m_edges.size();
        treesize.resize(n);
        group.resize(n);
        id.resize(n);

        setTreeSize(root, -1);
        cout << treesize << "#treesize" << endl;
        int i = 0; // 再度割り振り直す添字番号
        par.push_back(-1);
        bg.push_back(i);
        build(root, -1, hl_size++, i);
    }
    // O(log n)
    //
    // [r, c]の再割り振りされた添字区間を返す。区間は葉から根への順番。
    //
    // rがcより根側のノードでなければならない
    // c側から、以下の漸化式によってパスを分解する
    //      ret += {groupの根, c}, c = groupの根の親
    using P=pair<int, int>;
    vector<P> hl_decomposition(int r, int c) {
        vector<P> res;
        while (group[c]!=group[r]) {
            res.push_back(P(bg[group[c]], id[c]));
            c=par[group[c]];
        }
        res.push_back(P(id[r], id[c]));
        return res;
    }
    void print_HLDecomposition(void) {
        rep(i, m_edges.size()) {
            cout << group[i] << " " << id[i] << endl;
        }
        cout << "####" << endl;
        rep(i, hl_size) {
            cout << par[i] << " " << bg[i] << endl;
        }
    }

    /*************/
    // 描画
    /*************/
    void print_dfs(int v, int p) const {
        for (int i = 0; i < depth[v]; i++)
            cout << " ";
        cout << v << endl;
        for (edge_t next : m_edges[v]) if (next.to != p) 
            print_dfs(next.to, v);
    }
    void print(void) const {
        print_dfs(root, -1);
    }
};

/*
  6
  0 1
  1 3
  0 2
  2 4
  2 5

      0
    1   2
  3    4 5
 */
int main() {
    int n; cin >> n;
    Tree tree(n, 0/*root*/, new AssosiativeOperatorSum<verticle_t>());
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        tree.unite(x, y);
    }
    for (int i = 0; i < n; i++) {
        tree.setVerticle(i, i);
    }
    tree.init();

    tree.print();
    cout << tree.parent << endl;
    cout << tree.m_euler << endl;
    cout << tree.m_euler_appears_first << endl;
    cout << tree.m_euler_appears_second << endl;
    cout << tree.m_verticles_doubling << endl;

    cout << "Binary Search" << endl;
    cout << tree.binary_search(5, [&](int v){ return tree.m_verticles[v] > 1; }) << endl;
    cout << tree.binary_search(5, [&](int v){ return tree.m_verticles[v] > 6; }) << endl;

    cout << "Parent" << endl;
    cout << tree.getParent(3, 1) << endl;
    cout << tree.getParent(3, 2) << endl;
    cout << tree.getParent(3, 29) << endl;

    cout << "Accumulate SubTree" << endl;
    cout << tree.accumulateSubTree(0) << endl;
    cout << tree.accumulateSubTree(1) << endl;
    cout << tree.accumulateSubTree(2) << endl;

    cout << "Sum Minimum Length Path" << endl;
    cout << tree.sumMinimumLengthPath(0, 3) << endl;
    cout << tree.sumMinimumLengthPath(2, 5) << endl;
    cout << tree.sumMinimumLengthPath(0, 4) << endl;
    cout << tree.sumMinimumLengthPath(3, 5) << endl;

    cout << "Min Minimum Length Path" << endl;
    cout << tree.accumulateMinimumLengthPathParentAndChild(3, 1) << endl;
    cout << tree.accumulateMinimumLengthPathParentAndChild(3, 2) << endl;
    cout << tree.accumulateMinimumLengthPathParentAndChild(3, 3) << endl;
    cout << tree.accumulateMinimumLengthPath(3, 1) << endl;
    cout << tree.accumulateMinimumLengthPath(3, 2) << endl;
    cout << tree.accumulateMinimumLengthPath(3, 3) << endl;
    cout << tree.accumulateMinimumLengthPath(4, 5) << endl;

    cout << "Diameter" << endl;
    cout << tree.diameter() << endl;

    cout << "HL decomposition" << endl;
    tree.print_HLDecomposition();
    return 0;
}
