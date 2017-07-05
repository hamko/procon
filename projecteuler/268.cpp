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
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

// 素数の個数はO(n / log n)

/**********************************************************/
// 素数テーブルの作成
/**********************************************************/
// 素数テーブル構築: O(n log n)
vector<bool> is_prime;
vector<ll> primes;      // 素数リスト
void constructPrime(ll n) {
    if (n > 10000000) assert(0);
    is_prime.resize(n);
    primes.resize(0);
    for (ll i = 2; i < n; ++i)
        is_prime[i] = true;
    for (ll i = 2; i*i < n; ++i)
        if (is_prime[i])
            for (ll j = i*i; j < n; j+=i)
                is_prime[j] = false;
    for (ll i = 0; i < is_prime.size(); i++) 
        if (is_prime[i]) 
            primes.push_back(i);
}

extern vector<bool> is_prime;
extern vector<ll> primes;      // 素数リスト


// 高速ゼータ変換
// O(n 2^n)
// fは2^nでなければならない
//
// fに集合Sでの計算結果を入れてこれを呼び出すと、fがSを部分集合とする計算結果の総和になる。
// これは、厳密な集合計算から、?を含む集合のreductionを計算できる。
//
// input:   「bit iが1 -> P(i)が満たされる。bit iが0 -> not P(i)が満たされる」時の場合の数
// output:  「bit iが1 -> P(i)が満たされる。bit iが0 -> '?'であり何でもいい」 時の場合の数。
void FZT(vll& f) {
    rep(i, round(log(f.size())/log(2))) rep(j, f.size()) if(!(j & (1 << i))) f[j] += f[j | (1 << i)];
}
// 高速メビウス変換
// O(n 2^n)
// fは2^nでなければならない
//
// fに積集合の計算結果を入れてこれを呼び出すと、fが厳密な積集合の計算結果になる。
//
// input:   「bit iが0 -> P(i)が満たされる。bit iが1 -> '?'であり何でもいい」時の場合の数
// output:  「bit iが0 -> P(i)が満たされる。bit iが1 -> not P(i)が満たされる」 時の場合の数。
void FMT(vll& f) {
    rep(i, round(log(f.size())/log(2))) rep(j, f.size()) if(j & (1 << i)) f[j] -= f[j ^ (1 << i)];
}

int main(void) {
    ll n; cin >> n;
    constructPrime(1000);
    vll p;
    for (int i = 0; primes[i] < 100; i++) 
        p.pb(primes[i]);
    ll m = p.size();

    vll dp(1ll<<m);
    rep(mask, 1ll<<m) {
        ll tmp = 1;
        rep(i, m) if (mask & (1ll << i)) {
            if (tmp*1.0*p[i] > n) goto skip;
            tmp *= p[i];
        }
        dp[mask] = (n-1)/tmp;
        skip:;
    }

    rep(i, dp.size() / 2) swap(dp[i], dp[((1ll<<m)-1)^i]);
    FMT(dp);
    ll ret = 0;
    rep(mask, 1ll<<m) if (dp[mask] && m-__builtin_popcount(mask) >= 4) 
        ret += dp[mask];
    cout << ret << endl;

    return 0;
}
