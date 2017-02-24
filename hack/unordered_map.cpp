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



/*******************/
// 結論！！！
//
// (0) まず、どんな入力データを作るとしても、
// 絶対全部相違！！！！
//
// (1) 生のunordered_mapは、
// 30727の倍数を30000要素突っ込むと死ぬ！ (1e9の制限的に便利)
// 62233の倍数を60000要素突っ込むと死ぬ！
//
// (2) Codeforcesのsize_tは32bitなので、
// i*(1ll<<28)とかi*(ill<<30)とかをひたすら10万個投げると死ぬ！！
//
// (3) 入力制限がある場合があるが、
// 上で落とせないなら、基本無視する！！！
// 本当に落としたいなら、最後を何回もかぶらせる
// 
/*******************/





// unordered_mapのキーに、以下の倍数を投げまくると死ぬ。
//
// 1, 2, 5, 11, 23, 47, 97, 199, 409, 823, 1741, 3739, 7517, 15173, 
// 30727, 62233, <--------------- これが現実的！
// 126271, 256279, 520241,

ll M0 = 15173;
ll M1 = 30727;
ll M2 = 62233;

// 一番使い勝手が良い。
//
// 30727の倍数で殺す。30000要素の相違30727のケースを作るといい。
// 逆に言うと、n<15173では高速なので、適当に埋めておく。
ll hack30727(ll n) {
    unordered_map<ll, ll> memo;
    rep(i, n) 
        memo[i*M1] = 1;

    ll ret = 0; for (auto x : memo) ret += x.se; return ret;
}

















// 62233の倍数で殺す。60000要素の相違62233のケースを作るといい。 
// 逆に言うと、n<30727では高速なので、適当に埋めておく。
ll hack62233(ll n) {
    unordered_map<ll, ll> memo;
    rep(i, n) 
        memo[i*M2] = 1;

    ll ret = 0; for (auto x : memo) ret += x.se; return ret;
}

// maxが厳しいならこれ。
// こんな感じでclipするという手がある。
ll hack62233_max(ll n) {
    ll limit = 1e9;
    unordered_map<ll, ll> memo;
    rep(i, n) 
        if (i < M1) 
            memo[min<ll>(i*M1, limit/M1*M1)] = 0;
        else 
            memo[min<ll>((i-M1)*M2, limit/M2*M2)] = 1;

    ll ret = 0; for (auto x : memo) ret += x.se; return ret;
}


// ハッシュが自前実装されているくらいだったら殺せる
struct MyHash { size_t operator()(long long val) const { val ^= (val >> 32); val ^= (val >> 20) ^ (val >> 12); return val ^ (val >> 7) ^ (val >> 4); } };
ll hackMyHash(vector<ll>& hack_case) {
    unordered_map<ll, ll, MyHash> memo;
    for (auto x : hack_case) 
        memo[x] = 1;

    ll ret = 0; for (auto x : memo) ret += x.se; return ret;
}
vector<ll> makeHackCaseOfMyHash(ll n) {
    vll ret;
    rep(i, 1e18) {
        if (ret.size() == n)
            break;
        if (MyHash()(i) % n == 0) {
            ret.push_back(i);
            if (ret.size() % 100 == 0) {
                cout << ret.size() << endl;
            }
        }
    }
    return ret;
}

int main(void) {
    cout << "start" << endl;
    cout << hack62233_max(15000) << "#Fast" << endl;
    cout << hack62233_max(60000) << "#Hacked" << endl;

    cout << "start" << endl;
    cout << hack30727(15000) << "#Fast" << endl;
    cout << hack30727(30000) << "#Hacked" << endl;

    cout << "start" << endl;
    cout << hack62233(30000) << "#Fast" << endl;
    cout << hack62233(60000) << "#Hacked" << endl;

    vector<ll> hack_case;
    cout << "Making..." << endl; 
    hack_case = makeHackCaseOfMyHash(30000);
    cout << "Made." << endl; 
    cout << hackMyHash(hack_case) << "#Fast" << endl;
    cout << "Making..." << endl; 
    hack_case = makeHackCaseOfMyHash(60000);
    cout << "Made." << endl; 
    cout << hackMyHash(hack_case) << "#Hacked" << endl;
    return 0;
}
