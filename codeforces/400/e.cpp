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
double sec() { struct timeval tv; gettimeofday(&tv, NULL); return tv.tv_sec + tv.tv_usec * 1e-6; }
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

/**********************************************************/
// 以下はよく行う処理のテンプレート
// そのままは大抵使えないので、改造するつもりで。
/**********************************************************/
// 素因数分解
//
// 小さい素数から見ていって、割れたら割って素因数リストに追加する
// 残ったnが素数リストよりも大きければ、そのnは素数だと見なして返す。
unordered_map<ll, ll> factorize(ll n) {
    if (n <= 1) return unordered_map<ll, ll>();
    unordered_map<ll, ll> divisors_list;

    ll prime;
    for (ll i = 0; (prime = primes[i]) && n >= prime * prime; )  
        if (n % prime) 
            i++;
        else 
            divisors_list[prime]++, n /= prime;
    if (n != 1) 
        divisors_list[n]++;
    return divisors_list;
}

// [0, n]の範囲を全て素因数分解する。「飛び飛びの」高速化。結構速い。
// n < 1,000,000で150ms
// n < 10,000,000で1000ms 
//
// 配列rem[i]は、初めiが入っている。
// 素数pを下から見るが、rem[i]を全て見る必要はなく、rem[p*i]だけでいい。
vector<unordered_map<ll, ll>> factorizeRange(ll n) {
    vector<unordered_map<ll, ll>> fact(n+1);

    vector<ll> rem(n+1); rep(i, n+1) rem[i] = i;
    for (auto x : primes) for (ll i = x; i <= n; i += x) 
        while (rem[i] % x == 0) 
            rem[i] /= x, fact[i][x]++;
    return fact;
}


// lcm(a)
// a[i] < 1e7
unordered_map<ll, ll> lcmSmall(set<ll>& a) {
    if (!a.size()) return unordered_map<ll, ll>();

    ll n = *(prev(a.end()));
    vector<ll> rem(n+1); 
    rep(i, n+1) rem[i] = i;
    unordered_map<ll, ll> ret;
    for (auto x : primes) {
        ll max_c = 0;
        for (ll i = x; i <= n; i += x) if (a.count(i)) {
            ll c = 0;
            while (rem[i] % x == 0) 
                rem[i] /= x, c++;
            chmax(max_c, c);
        }
        if (max_c) 
            ret[x] = max_c;
    }
    return ret;
}

// lcm(a)
// a[i]>1e7
unordered_map<ll, ll> lcmLarge(set<ll>& a) {
    if (!a.size()) return unordered_map<ll, ll>();

    unordered_map<ll, ll> ret;
    for (auto n : a) {
        auto d = factorize(n);
        for (auto x : d) 
            chmax(ret[x.fi], x.se);
    }
    return ret;
}


// 約数を全列挙する。
vector<ll> divisors(ll n) {
    vector<ll> divisors_list;

    auto counter = factorize(n);
    divisors_list.push_back(1);
    for (auto x : counter) {
        ll tmp_size = divisors_list.size();
        ll p = 1;
        for (ll i = 0; i < x.second; i++) {
            p *= x.first;
            for (ll j = 0; j < tmp_size; j++) 
                divisors_list.push_back(divisors_list[j] * p);
        }
    }
    sort(divisors_list.begin(), divisors_list.end());
    return divisors_list;
}

ll getDivisorsNum(ll n) {
    unordered_map<ll, ll> divisors_list = factorize(n);
    map<ll, ll> num;
    rep(i, divisors_list.size()) 
        num[divisors_list[i]]++;
    ll p = 1;
    for (auto x : num) 
        p *= x.second + 1;
    return p;
}

ll f(ll n) {
    if (n == 1) return 1;
    ll ret = 0;
    rep(i, n-1) {
        ll x = i + 1, y = n - x;
        ret = (__gcd(x, y) == 1);
    }
    return ret;
}
ll g(ll n) {
    vector<ll> dd = divisors(n);
    ll ret = 0;
    for (auto d : dd) {
        ret += f(n / d);
    }
    return ret;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    constructPrime(1000100);
    int n; cin >> n;
    cout << f(n) << endl;
    cout << g(n) << endl;
    cout << f(g(n)) << endl;
    return 0;
}
