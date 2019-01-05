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
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
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

// n以下の素数リストを作成する
//
// 素数はn個でも、n^2までの素因数分解ができる！
// よほどのことがなければn=1e6+10とかを確保すれば十分。
//
// 1e7は割とMLEするので注意
void constructPrime(ll n) {
    if (n > 5e6) {
        cerr << "WATCH OUT!!!! YOU ARE USING TOO LARGE MEMORY!" << endl;
    }
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
//
// 約数を試し割りするより、n=1000000で4倍くらい早い。
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
    return divisors_list;
}

ll getDivisorsNum(ll n) {
    unordered_map<ll, ll> divisors_list = factorize(n);
    ll p = 1;
    for (auto x : divisors_list) 
        p *= x.second + 1;
    return p;
}


/**********************************************************/
// 前処理なしの素数判定
/**********************************************************/
#define UINT128ENV
static inline uint32_t modpow32(uint32_t a, uint32_t k, uint32_t n){
    uint32_t r;
    for(r=1;k;k/=2){
        if(k&1) r = (uint64_t)r*a%n;
        a = (uint64_t) a*a%n;
    }
    return r;
}

int is_prime32(uint32_t n){
    static const uint32_t as32[] = {2, 7, 61};
    int i, j, r;
    uint32_t d;
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(!(n & 1)) return 0;
    r = __builtin_ctz(n-1);
    d = (n-1) >> r;
    for(i=0;i<3;i++){
        uint32_t a = as32[i] % n;
        if(a == 0) return 1;
        uint32_t t = modpow32(a, d, n);
        if(t == 1) continue;
        for(j=0;t!=n-1;j++){
            if(j == r-1) return 0;
            t = (uint64_t) t * t % n;
            if(t == 1) return 0;
        }
    }
    return 1;
}
#ifdef UINT128ENV
typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;
static inline uint64_t ex_gcd(uint64_t y){
    int i;
    uint64_t u, v;
    u = 1; v = 0;
    uint64_t x = 1LL<<63;

    for(i=0;i<64;i++){
        if(u&1){
            u = (u + y) / 2;
            v = v/2 + x;
        }
        else {
            u >>= 1; v >>= 1;
        }
    }

    return v;
} 

static inline uint64_t MR(uint128_t x, uint64_t m, uint64_t n){
    uint64_t z = ((uint128_t) ((uint64_t) x * m) * n + x) >> 64;
    return z < n ? z : z - n;
}

static inline uint64_t RM(uint64_t x, uint64_t r2, uint64_t m, uint64_t n){
    return MR((uint128_t) r2 * x, m, n);
}


static inline uint64_t modpow64(uint64_t a, uint64_t k, uint64_t m, uint64_t n){
    uint64_t r;
    for(r=a,--k;k;k/=2){
        if(k&1) r = MR((uint128_t)r*a, m, n);
        a = MR((uint128_t) a*a, m, n);
    }
    return r;
}

int is_prime64(uint64_t n){
    static const uint64_t as64[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int i, j, r;
    uint64_t d, one, mone, r2, m;
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(!(n & 1)) return 0;
    if(n < (1LL << 32)) return is_prime32(n);
    r = __builtin_ctzll(n-1);
    d = (n-1) >> r;
    m = ex_gcd(n);
    one = -1ULL % n + 1;
    mone = n - one;
    r2 = (uint128_t) (int128_t) -1 % n + 1;
    for(i=0;i<7;i++){
        uint64_t a = RM(as64[i], r2, m, n);
        if(a == 0) return 1;
        uint64_t t = modpow64(a, d, m, n);
        if(t == one) continue;
        for(j=0;t!=mone;j++){
            if(j == r-1) return 0;
            t = MR((uint128_t) t * t, m, n);
            //      if(t == one) return 0;
        }
    }
    return 1;
}
#endif

int isPrime(uint64_t n){
#ifdef UINT128ENV
    return is_prime64(n);
#else
    return is_prime32(n);
#endif
}

// ローのアルゴリズム。整数nを素因数分解する。
// 1e6 <= n <= 1e10くらいの範囲で愚直より高速
// （特に効果があるのは1e7-1e9で、約2-7倍速）
//
// 計算結果はrho_retに保存される
// 体感平均計算量 O(n^{1/2} log n / 10)
// 体感最悪計算量 O(n^{1/2} log n * 10)
//
// ロー法による素因数分解は意外と時間がかかる。
// n     平均秒   最悪秒
// 1e+05 5.42e-06 2e-05
// 1e+06 6.82e-06 3.3e-05
// 1e+07 8.82e-06 6.6e-05
// 1e+08 1.11e-05 7.9e-05
// 1e+09 0.000013 0.00008
// 1e+10 0.000212 0.03607
// 1e+11 0.001177 0.22825
// 1e+12 0.003593 0.31959
// 1e+13 0.014982 1.26338
// 1e+14 0.042568 4.53350
// 1e+15 0.157090 28.5738
//
// 構築なし素因数分解はこんな感じ。
// n     平均秒   最悪秒
// 1e+05 4.55e-06 8e-06
// 1e+06 7.56e-06 3.8e-05
// 1e+07 1.58e-05 8.1e-05 
// 1e+08 3.30e-05 0.000218
// 1e+09 0.000087 0.000576
// 1e+10 0.000237 0.002122
// 1e+11 0.000653 0.005520
// 1e+12 0.001602 0.015735
// 1e+13 0.004801 0.053189
// 1e+14 0.014975 0.190736
// 1e+15 0.038690 0.673158
using ull = uint64_t;
#ifdef UINT128ENV
using u64 = uint32_t;
using u128 = uint64_t;
#else
using u64 = uint64_t;
using u128 = uint128_t;
#endif
uint64_t mul(uint64_t a, uint64_t b, uint64_t m) { return u128(a) * b % m; };
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

// constructPrimeが不要な素因数分解
// O(sqrt(n))
unordered_map<ll, ll> factorizeWithoutConstruction(ll n) {
    unordered_map<ll, ll> divisors_list;
    for (ll p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            divisors_list[p]++;
            n /= p;
        }
    }
    if (n > 1) {
        divisors_list[n]++;
    }
    return divisors_list;
}


// ガウス素数＝複素数の素数判定
bool isGaussianPrime(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b % 4 == 3 && is_prime[b];
    if (b == 0) return a % 4 == 3 && is_prime[a];
    return is_prime[a*a+b*b];
}

// 区間篩
// O( n log n )．
const ll N = 100000000; // MAXPRIME 
const ll M = 10000;     // SQRT(N)
const ll K = 6000000;   // NUMBER OF PRIMES, CHOOSE 9/8 * N / LOG(N)
vector<ll> iterativeSieve() {
    static ll p[K], table[M];
    for (ll i = 2; i < M; ++i) p[i] = i;
    for (ll i = 2; i*i < M; ++i)
        if (p[i])
            for (ll j = i*i; j < M; j += i)
                p[j] = 0;
    p[0] = p[1] = 0;
    ll num = remove(p, p+M, 0) - p;
    for (ll m = M; m < N; m += M) {
        for (ll x = m; x < m+M; ++x)
            table[x-m] = x;
        for (ll i = 0, j; p[i]*p[i] < m+M; ++i) {
            if (p[i] >= m)          j = p[i] * p[i];
            else if (m % p[i] == 0) j = m;
            else                    j = m - (m % p[i]) + p[i];
            for (; j < m+M; j += p[i]) table[j-m] = 0;
        }
        num = remove_copy(table, table+M, p+num, 0) - p;
    }
    return vector<ll>(p, p+num);
}

ll n = 1000000;
int main(void) {
    // 構築O(n log n), 参照O(log n)
    constructPrime(n);

    // Millar Rubin Testのチェック
    rep(i, n) 
        assert(is_prime[i] == isPrime(i));

    // [0, 30)の素数
    rep(i, 30) 
        if (is_prime[i]) 
            cout << i << " ";
    cout << endl;

    // 素因数分解
    vll cands = {1, 2, 4, 8, 3, 120, 1000000007};
    for (auto x : cands) 
        cout << factorize(x) << endl;

    // 約数
    auto d = divisors(120);
    rep(i, d.size()) 
        cout << d[i] << " ";
    cout << "# num = " << getDivisorsNum(120) << " ";
    cout << endl;

    // 範囲素因数分解
    auto fact = factorizeRange(10);
    rep(i, fact.size()) 
        cout << fact[i] << endl;

    // 範囲LCM
    set<ll> a = {2, 3, 4, 6, 8, 10};
    cout << lcmSmall(a) << endl;

    {
        // 大きい数字の素因数分解
        repi(d, 5, 10) {
            ll range = 1000;
            double total_time = 0;
            double max_time = 0;
            repi(i, pow(10, d), pow(10, d) +range) {
                double time = sec();
                auto f = factorizeWithoutConstruction(i);
                total_time += sec() - time;
                max_time = max(max_time, sec() - time);
                //            cout << i << " " << sec() - time << " " << f << endl;
            }
            cout << pow(10, d) << " "<< total_time / range << " " << max_time << " #Brutal" << endl;
        }

        // 大きい数字の素因数分解
        repi(d, 5, 10) {
            ll range = 1000;
            double total_time = 0;
            double max_time = 0;
            repi(i, pow(10, d), pow(10, d) +range) {
                double time = sec();
                rho(i);
                total_time += sec() - time;
                max_time = max(max_time, sec() - time);
                //            cout << i << " " << sec() - time << " " << rho_ret << endl;
            }
            cout << pow(10, d) << " "<< total_time / range << " " << max_time << " #Rho" << endl;
        }

    }


    return 0;
}

