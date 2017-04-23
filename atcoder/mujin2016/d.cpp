#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
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
#define VN(v) # v
//#define print(a) cout << a << "#" << VN(a) << endl;
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

// 累積和の計算
// 構築O(n)
// クエリO(1)
const function<bool(ll)> f1_default = [](ll x) { return 1; };
class Sum1d {
public:
    vll data;
    vll sumdata;
    Sum1d(vll& d, function<bool(ll)> f = f1_default) {
        int n = d.size();
        data = d;
        sumdata = vll(n+1, 0);
        rep(i, n) if(f(i)) sumdata[i+1] = data[i];
        rep(i, n) sumdata[i+1] += sumdata[i];
//        rep(i, n+1) cout << sumdata[i] << " "; cout << endl;
    }
    // [i, j)の小区間の総和 (半開区間)
    ll sum(int i, int j) {
        return sumdata[j]-sumdata[i];
    }
    // [i, i+ilen)の小区間の総和 (半開区間)
    ll suml(int i, int len) {
        return this->sum(i, i+len);
    }
};

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
class AssosiativeOperatorMin : public AssosiativeOperator<T> {
public:
    AssosiativeOperatorMin(void) { AssosiativeOperator<T>::T0 = std::numeric_limits<T>::max(); AssosiativeOperator<T>::L0 = 0; }
    virtual T op(T a, T b) { return min(a, b); } // Range Min
    virtual T op_lazy(T a, T b) { return a + b; } // Range Add
    virtual T resolve_lazy(T d, T l, int nl, int nr) { return d + l; } // 全部上がってるので、子によらず増える
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
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    string s; cin >> s;
    vll ls_(n), rs_(n), qs_(n);
    map<ll, ll> qpos;
    rep(i, n) { 
        ls_[i] = s[i] == '('; 
        rs_[i] = s[i] == ')'; 
        qs_[i] = s[i] == '?'; 
        if (s[i] == '?') 
            qpos[qpos.size()] = i;
    }
    Sum1d ls(ls_), rs(rs_), qs(qs_);

    SegmentTree<ll> l_rmq(n+1, new AssosiativeOperatorMin<ll>());
    SegmentTree<ll> r_rmq(n+1, new AssosiativeOperatorMin<ll>());
    l_rmq.update(0, 0);
    r_rmq.update(0, 0);
    ll l_sum = 0, r_sum = 0;
    rep(i, n) {
        l_sum -= (s[i] == ')'); l_sum += (s[i] == '('); l_sum += (s[i] == '?'); 
        r_sum -= (s[i] == ')'); r_sum += (s[i] == '('); r_sum -= (s[i] == '?'); 
        l_rmq.update(i+1, l_sum);
        r_rmq.update(i+1, r_sum);
    }

    ll Q; cin >> Q;
    rep(_, Q) {
        ll l, r; cin >> l >> r; l--;
        if ((r - l) % 2) { cout << "No" << endl; continue; }
        if (l + 1 == r) { cout << "Yes" << endl; continue; }

        ll l_lacking = (r - l) / 2 - ls.sum(l, r);
        ll r_lacking = (r - l) / 2 - rs.sum(l, r);
        if (l_lacking < 0 || r_lacking < 0) { cout << "No" << endl; continue; }

        vll lrange = {l, l};
        vll rrange = {l, r};
        if (l_lacking) 
            lrange[1] = rrange[0] = min<ll>(r, qpos[qs.sum(0, l) + l_lacking - 1] + 1);
//        cout << lrange << rrange << endl;

        // lrangeでの最小値が、lを下回らず
        ll l_min = l_rmq.query(lrange[0], lrange[1]);
        if (l_min != std::numeric_limits<ll>::max() && l_rmq.query(l) > l_min) { cout << "No" << endl; continue; }
        // rrangeでの最大値が、r-1を下回らず
        ll r_min = r_rmq.query(rrange[0], rrange[1]);
        if (r_min != std::numeric_limits<ll>::max() && r_rmq.query(r) > r_min) { cout << "No" << endl; continue; }

        cout << "Yes" << endl;
    }

    return 0;
}
