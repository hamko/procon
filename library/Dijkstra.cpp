// SRM 612 Div.1 Easy EmoticonsDiv1を例に、ダイクストラ法の実装方法を数個例示する。
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
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;

namespace std{ namespace { template <class T> inline void hash_combine(size_t& seed, T const& v) { seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2); } template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1> struct HashValueImpl { static void apply(size_t& seed, Tuple const& tuple) { HashValueImpl<Tuple, Index-1>::apply(seed, tuple); hash_combine(seed, get<Index>(tuple)); } }; template <class Tuple> struct HashValueImpl<Tuple,0> { static void apply(size_t& seed, Tuple const& tuple) { hash_combine(seed, get<0>(tuple)); } }; } template <typename ... TT> struct hash<tuple<TT...>> { size_t operator()(tuple<TT...> const& tt) const { size_t seed = 0; HashValueImpl<tuple<TT...> >::apply(seed, tt); return seed; } }; } 
namespace std { template<typename U, typename V> struct hash<pair<U, V>> { size_t operator()(pair<U, V> const& v) const { return v.first ^ v.second; } }; } struct pairhash { public: template <typename T, typename U> size_t operator()(const pair<T, U> &x) const { return hash<T>()(x.first) ^ hash<U>()(x.second); } };

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); return s; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

// 型Sが状態としたダイクストラ。
// 型Sは有限な状態ならば何でも入るが、かなり遅い上、メモリを多く消費する。
int printSmilesGeneral(int n) {
    using D = int16_t; // !! 距離の型
    using state_t = int16_t; 
    using S = tuple<state_t, state_t>; // !! 状態の型

    using T = tuple<D, S>; // (dist, state)
    priority_queue<T, vector<T>, greater<T>> q; // 頂点集合昇順

    q.push(mt(0, mt(1, 0))); // !! 初期値
    auto f = [&](S& x) {  // !! 異常判定基準
        state_t xx, yy; tie(xx, yy) = x; 
        return (xx >= 1050 || xx <= 0 || yy >= 520 || yy <= 0); 
    };

    unordered_map<S, D> dist;
    unordered_set<S> used;
    while (!q.empty()) {
        // この時点で、(d, t)が処理するべき頂点
        // usedのダブりはループ内で処理
        D d; S t; tie(d, t) = q.top(); q.pop();

        if (used.count(t)) continue; // もう来てたら終わり
        used.insert(t); 
        dist[t] = d; 

        // !! 遷移の定義
        vector<T> next_nodes;
        state_t x, y; tie(x, y) = t;
        next_nodes.pb(mt(2, mt(2*x, x)));
        next_nodes.pb(mt(1, mt(x-1, y)));
        next_nodes.pb(mt(1, mt(x+y, y)));

        for (auto&& next_node : next_nodes) {
            D nd; S nt; tie(nd, nt) = next_node;
            if (f(nt)) continue;
            if (dist.count(nt) && dist[nt] <= d + nd) continue;  // 枝刈り
            q.push(mt(d + nd, nt));
        }
    }

    // !! 後処理
    D ret = 10000; // INF
    rep(y, 2000) if (dist.count(mt(n, y))) 
        chmin(ret, dist[mt(n, y)]);

    return ret;
}

int printSmilesArray(int n) {
    using S = tuple<ll, ll>; // !! state

    using T = tuple<ll, S>; // dist, (x, y)
    priority_queue<T, vector<T>, greater<T>> q; // 未確定な頂点（距離が近い順）

    const int M = 1200; // !! 状態を張る
    static ll dist[M][M]; rep(i, M) rep(j, M) dist[i][j] = INF;
    static bool used[M][M];

    auto f = [&](S x) {  // !! 異常判定
        ll xx, yy; tie(xx, yy) = x; 
        return (xx >= M || xx <= 0 || yy >= M || yy <= 0); 
    };

    q.push(mt(0, mt(1, 0))); // !! 初期値
    while (!q.empty()) {
        // もうここに入った時点で処理するべき頂点
        ll d; S t; tie(d, t) = q.top(); q.pop();
        ll x, y; tie(x, y) = t;

        if (used[x][y]) continue; // !! 状態に応じてもう来ていたら終わり
        used[x][y] = 1;
        dist[x][y] = d;

        // !! 遷移の定義
        vll xx = {2 * x, x - 1, x + y};
        vll yy = {x, y, y};
        vll cost = {2, 1, 1};
        rep(i, 3) {
            if (f(mt(xx[i], yy[i]))) continue; // !! 状態に応じて異常判定
            if (dist[xx[i]][yy[i]] <= d + cost[i]) continue;  // !! 状態に応じて枝刈り
            q.push(mt(d + cost[i], mt(xx[i], yy[i]))); // !! 状態に応じて次の状態を追加
        }
    }
    // !! 後処理
    ll ret = INF;
    rep(y, M) 
        chmin(ret, dist[n][y]);
    return ret;
}

int main(void) {
    cout << printSmilesGeneral(1000) << endl;
    cout << printSmilesArray(1000) << endl;

    return 0;
}
