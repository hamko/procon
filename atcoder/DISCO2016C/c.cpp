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
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
template <typename T,typename U> class umap:public std::unordered_map<T,U,myhash::myhash<T>> { public: using MAP=std::unordered_map<T,U,myhash::myhash<T>>; umap():MAP(){MAP::rehash(myhash::Bsizes[rand()%20]);} };    

struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); srand((unsigned int)time(NULL)); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

// 素数の個数はO(n / log n)

/**********************************************************/
// 素数テーブルの作成
/**********************************************************/
// 素数テーブル構築: O(n log n)
#define MAX_NUM 20000000
ll prime_size = -1;
bool is_prime[MAX_NUM];
vector<ll> primes;      // 素数リスト
void sieve_of_atkin(ll N) {
    ll sqrtN = sqrt(N);
    int n;
    for (int z = 1; z <= 5; z += 4) {
        for (int y = z; y <= sqrtN; y += 6) {
            for (int x = 1; x <= sqrtN && (n = 4*x*x+y*y) <= N; ++x)
                is_prime[n] = !is_prime[n];
            for (int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x += 2)
                is_prime[n] = !is_prime[n];
        }
    }
    for (int z = 2; z <= 4; z += 2) {
        for (int y = z; y <= sqrtN; y += 6) {
            for (int x = 1; x <= sqrtN && (n = 3*x*x+y*y) <= N; x += 2)
                is_prime[n] = !is_prime[n];
            for (int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x += 2)
                is_prime[n] = !is_prime[n];
        }
    }
    for (int y = 3; y <= sqrtN; y += 6) {
        for (int z = 1; z <= 2; ++z) {
            for (int x = z; x <= sqrtN && (n = 4*x*x+y*y) <= N; x += 3)
                is_prime[n] = !is_prime[n];
        }
    }
    for (int n = 5; n <= sqrtN; ++n)
        if (is_prime[n])
            for (int k = n*n; k <= N; k+=n*n)
                is_prime[k] = false;
    is_prime[2] = is_prime[3] = true;
}

void sieve_of_eratosthenes(ll n) {
    for (ll i = 2; i < n; ++i)
        is_prime[i] = true;
    for (ll i = 2; i*i < n; ++i)
        if (is_prime[i])
            for (ll j = i*i; j < n; j+=i)
                is_prime[j] = false;
    for (ll i = 0; i < n; i++) 
        if (is_prime[i]) 
            primes.push_back(i);
}

void constructPrime(ll n) {
    assert(n < MAX_NUM);
    prime_size = n;
#if 1
    sieve_of_atkin(n);
#else
    sieve_of_eratosthenes(n);
#endif
    primes.reserve(1.2*n*log(n)); // 素数定理よりn>100でOK
    rep(i, n) if (is_prime[i]) {
        primes.pb(i);
    }
}

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

int bs[200010];


int main(void) {
    constructPrime(1e5);

    ll n, k; cin >> n >> k;
    vll a(n); cin >> a;
    rep(i, n) {
        a[i] = __gcd(a[i], k);
    }

    map<ll, ll> memo;
    rep(i, n) {
        memo[a[i]]++;
    }
    ll ret = 0;
    for (auto x_ : memo) for (auto y_ : memo) {
        ll x = x_.fi;
        ll xn = x_.se;
        ll y = y_.fi;
        ll yn = y_.se;
        if (x * y % k) continue;
        if (x != y) {
            ret += xn * yn;
        } else {
            assert(xn == yn);
            ret += xn * xn - xn;
        }
    }
    assert(ret % 2 == 0);
    cout << ret / 2 << endl;

    return 0;
}
