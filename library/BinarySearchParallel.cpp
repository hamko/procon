#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
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

struct UnionFind {
    vector<int> par;
    int n, cnt;
    UnionFind(const int& x = 0) {init(x);}
    void init(const int& x) {par.assign(cnt=n=x, -1);}
    inline int find(const int& x) {return par[x] < 0 ? x : par[x] = find(par[x]);}
    inline bool same(const int& x, const int& y) {return find(x) == find(y);}
    inline bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return false;
        --cnt;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y]; par[y] = x;
        return true;
    }
    inline int count(int x) {return -par[find(x)];}

};
 
// 並列二分探索
//
// Incrementalな時変データ構造に対して、
// test(t, q)==trueであるのはいつか？というクエリをQ個処理する
// ただしtest(t, q0)はtに対して単調であることを前提とする
//
// O((qnum qtime + stime + tmax nexttime) log tmax) 
// qnum: クエリサイズ
// qtime: クエリ応答時間
// stime: データ構造の一回構築時間
// tmax: 時間幅最大

template <class query>
class TimeDependentCharacteristicFunction {
public:
    TimeDependentCharacteristicFunction(void) {};
    virtual bool test(query& q) = 0;
    virtual void next(void) = 0;
    virtual void init(void) = 0;
};

template <class query>
class BinarySearchParallel {
public:
    ll tmax;
    TimeDependentCharacteristicFunction<query>* f;
    vector<query> qs;
    vector<ll> fail, pass;

    BinarySearchParallel(ll t, TimeDependentCharacteristicFunction<query>* tdcf) : tmax(t), f(tdcf) { }
    void addQuery(query& q) { qs.push_back(q); }

    void solve(void) {
        fail.assign(qs.size(), -1); pass.assign(qs.size(), tmax);
        rep(stage, (ll)(log(tmax) / log(2) + 2)) {
            vector<vi> check(tmax);
            rep(i, qs.size()) 
                check[(fail[i] + pass[i]) / 2].push_back(i);
            f->init();
            rep(i, tmax) {
                f->next();
                for (int id : check[i]) if (pass[id] - fail[id] > 1) 
                    (f->test(qs[id]) ? pass : fail)[id] = i;
            }
        }
    }
};

// ここで定義されるデータ構造がO(log tmax)回構築される。
// 
// init: データ構造と時間を初期化する
// O(stime)
//
// next: 時間を進めて、データ構造を1つ進める
// O(nexttime)
//
// test: 現在時刻tにおけるデータ構造を用いて、クエリに応答する
//
// 具体例はAGC 02D
struct Query {
    int u, v, point;
};
template <class query>
class TD_UnionFind : public TimeDependentCharacteristicFunction<query> {
    public:
        vector<P> op; // m
        UnionFind uf; // n
        ll t;
        ll n;
        TD_UnionFind(ll n, vector<P> op) : op(op), n(n) {
            this->init();
        }
        bool test(query& q) {
            int cnt;
            if (uf.same(q.u, q.v)) {
                cnt = uf.count(q.u);
            } else {
                cnt = uf.count(q.u) + uf.count(q.v);
            }
            return cnt >= q.point;
        }
        void next(void) {
            uf.unite(op[t].first, op[t].second);
            t++;
        }
        void init(void) {
            uf.init(n);
            t = 0;
        }
};

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<P> es(m); rep(i, m) { cin >> es[i].fi >> es[i].se; es[i].fi--; es[i].se--; }

    BinarySearchParallel<Query> bsp(m, new TD_UnionFind<Query>(n, es));

    int qn; cin >> qn;
    rep(_, qn) {
        Query q; cin >> q.u >> q.v >> q.point; q.u--; q.v--;
        bsp.addQuery(q);
    }

    bsp.solve();

    for (auto x : bsp.pass)
        cout << x+1 << endl;

    return 0;
}
