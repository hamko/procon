#include <bits/stdc++.h>
#include <sys/time.h>
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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
ll ugauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return a/b; else return (a+(a>0?-1:1))/b+1; }
ll lgauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return (a+(a>0?-1:1))/b-1; else return a/b; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

//セグ木の理解とともに、GeneralSegmentがひどいライブラリに見えるようになってきた
//
//ノードの一部だけをupdateする
//でも全部もできるようになってほしい
//構築不要の場合があるので、ノードを直接叩けるようになっていて欲しい
//無駄に結合opクラス作るの良くない
//単位元は構築サボる時以外いらない

#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
#define MAX_N 100005

// 半開区間！！！なので注意

struct Pool {
    int pos;
    char mem[(ll)2e8]; // 200MB
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
class AssosiativeOperatorInversion : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorInversion(void) { AssosiativeOperator<T>::T0 = mt(0, 0, 0); AssosiativeOperator<T>::L0 = mt(0, 0, 0); }
    virtual T op(T a, T b) { return mt(get<0>(a) + get<0>(b), get<1>(a) + get<1>(b), get<2>(a) + get<2>(b) + get<0>(a) * get<1>(b));} // Range Sum
    T op_lazy(T a, T b) {return mt(0, 0, 0); }
    T resolve_lazy(T d, T l, int nl, int nr) {return mt(0, 0, 0);}
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
    ll n; cin >> n;
    string t; cin >> t;

    SegmentTree<tuple<ll, ll, ll>> s(n, new AssosiativeOperatorInversion<tuple<ll, ll, ll>>());
    rep(i, n) {
        if (t[i] == 'M') {
            s.update(i, mt(1, 0, 0));
        } else if (t[i] == 'C') {
            s.update(i, mt(0, 1, 0));
        } else {
            s.update(i, mt(0, 0, 0));
        }
    }
    /*
    while (1) {
        ll l, r; cin >> l >> r;
        cout << s.query(l, r) << endl;
    }
    */


    ll q; cin >> q;
    rep(_, q) {
        ll k; cin >> k;
        ll ret = 0;
        rep(i, n) if (t[i] == 'D') {
            ret += get<2>(s.query(i, min(n, i + k)));
        }
        cout << ret << endl;
    }

    return 0;
}
