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

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
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
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }

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
map<ll, ll> factorize(ll n) {
    if (n <= 1) return map<ll, ll>();
    map<ll, ll> divisors_list;

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
/**********************************************************/
// 前処理なしの素数判定
/**********************************************************/
#define ull unsigned long long
// dla n < 2^32: inline ull mul(ull a, ull b, ull mod) { return (a*b) % mod; }
const int _k = 25; const ull _mask = (1<<_k)-1;
ull mul (ull a, ull b, ull mod) { // zaĹ‚: b, mod < 2^(64-_k)
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


int main(void) {
    ll q; cin >> q;
    constructPrime(1e5);
    rep(_, q) {
        ll n;cin>>n;
        if (n <= 3 || n == 5 || n == 7 || n == 11) {
            cout << -1 << endl;
        } else {
            ll ret =0;
            if (n % 2 == 1) {
                n -= 9;
                ret++;
            }
            cout << ret + n / 4 << endl;
        }
    }
    return 0;
}
