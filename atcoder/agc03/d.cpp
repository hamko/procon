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
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
template <typename T> ostream &operator<<(ostream &o, const priority_queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} o << endl; return o; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define rand randxor

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

#define ull unsigned long long
const int _k = 25; const ull _mask = (1<<_k)-1;
ull mul (ull a, ull b, ull mod) {
    ull result = 0;
    while (a) {
        ull temp = (b * (a & _mask)) % mod;
        result = (result + temp) % mod;
        a >>= _k;
        b = (b << _k) % mod;
    }
    return result;
}
 
ull pow(ull a, ull w, ull mod) {
    ull res = 1;
    while (w){
        if (w&1) res = mul(res, a, mod);
        a = mul(a, a, mod);
        w /= 2;
    }
    return res;
}
 
bool primetest(ull n, int a) {
    if (a > n-1) return 1;
    ull d = n-1;
    int s = 0;
    while (!(d&1)) {
        d /= 2;
        s++;
    }
    ull x = pow(a, d, n);
    if (x == 1 || x == n-1) return 1;
    rep(i,s-1){
        x = mul(x, x, n);
        if (x == 1) return 0;
        if (x == n-1) return 1;
    }
    return 0;
}

bool isPrime(ull n) {
    if (n < 4) return n > 1;
    bool pr = n%2;
    if (n < (1LL << 32)) {
       for (int a : {2,7,61}) pr = pr && primetest(n,a);
    } else if (n < (1LL << 48)) {
       for (int a : {2,3,5,7,11,13,17}) pr = pr && primetest(n,a);
    } else {
       for (int a : {2,325,9375,28178,450775,9780504,1795265022}) pr = pr && primetest(n,a);
    }
    return pr;
}
 
// O(n^0.25)
// ローのアルゴリズム
// 計算結果はrho_retに保存される
map<ull,int> rho_ret; // {p, k}, pの素因数がk個存在
ull find_factor(ull z) {
    if (!(z&1)) return 2;
    ull c = rand() % z, x = 2, y = 2, d = 1;
    while (d == 1) {
        ull tp = (mul(y,y,z) + c) % z;
        y = (mul(tp,tp,z) + c) % z;
        x = (mul(x,x,z) + c) % z;
        d = __gcd(x>y ? x-y : y-x, z);
    }
    return d;
}
void rhofact_rec(ull z) {
    if (z==1) return;
    if (isPrime(z)) { rho_ret[z]++; return; }
    while(1) {
        ull f = find_factor(z);
        if (f != z) {
            rhofact_rec(f);
            rhofact_rec(z/f);
            break;
        }
    }
}
void rho(ull z) {
    rho_ret.clear();
    rhofact_rec(z);
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n); rep(i, a.size()) cin >> a[i];
    map<ll, ll> memo_for, memo_rev;
    ll flag = 0;
    rep(i, n) {
        rho(a[i]);
        ll tmp_for = 1;
        for (auto& x : rho_ret) 
            rep(j, x.se % 3)
                tmp_for *= x.fi;
        flag |= tmp_for == 1;
        memo_for[tmp_for]++;

        long double tmp_rev = 1;
        for (auto& x : rho_ret) 
            rep(j, ((3 - x.se) % 3 + 3) % 3)
                tmp_rev *= x.fi;
        if (tmp_rev <= 1e10) {
            memo_rev[tmp_for] = tmp_rev;
            memo_rev[tmp_rev] = tmp_for;
        } else {
            memo_rev[tmp_for] = INF;
        }

    }

    for (auto x : memo_for) 
        if (!memo_for.count(memo_rev[x.fi])) 
            memo_for[memo_rev[x.fi]] = 0;

    ll ret = flag;
    for (auto x : memo_for) if (x.fi != 1 && x.fi < memo_rev[x.fi]) {
        ll l = x.se;
        ll r = memo_for[memo_rev[x.fi]];
        ret += max({l, r});
    }
    cout << ret << endl;
    return 0;
}
