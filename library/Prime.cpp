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
#define forall(a, f) all_of((a).begin(), (a).end(), (f))
#define exists(it, a, f) (((it)=find_if((a).begin(), (a).end(), (f)))!=(a).end())

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
#define ldout fixed << setprecision(40) 


// 素数の個数はO(n / log n)

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)が必須！
/**********************************************************/
// 素数テーブル構築: O(n log n)
vector<bool> is_prime;
vector<ll> primes;      // 素数リスト
void constructPrime(ll n) {
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

// 素因数分解
void factorize(ll n, vector<ll>& divisors_list) {
    if (n <= 1) return;
    divisors_list.clear(); 
    divisors_list.resize(0);

    ll prime;
    for (ll i = 0; (prime = primes[i]) && n >= prime * prime; )  
        if (n % prime) 
            i++;
        else 
            divisors_list.push_back(prime), n /= prime;
    if (n != 1) 
        divisors_list.push_back(n);
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
// Divisor系は、最大nをMAXNとしてconstructPrimesList(sqrt(MAXN))で早くなる
void divisors(ll n, vector<ll>& divisors_list) {
    divisors_list.clear(); divisors_list.resize(0);

    vector<ll> fac_list;
    factorize(n, fac_list);
    map<ll, ll> counter;
    for (auto x : fac_list) 
        counter[x]++;
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
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
ll getDivisorsNum(ll n) {
    vector<ll> divisors_list; factorize(n, divisors_list);
    map<ll, ll> num;
    for (ll i = 0; i < divisors_list.size(); i++) {
        num[divisors_list[i]]++;
    }
    ll p = 1;
    for (auto x : num) {
        p *= x.second + 1;
    }
    return p;
}
/**********************************************************/
// 前処理なしの素数判定
/**********************************************************/
// Millar-Rabin Test

using ull = unsigned long long;
bool isPrimeSmall(const ll &n){
    if(n == 2) return true;
    if(n < 2 || n%2 == 0) return false;
    const ll m = n-1, d = m / (m & -m);
    auto modpow = [&](ll a, ll b){
        ll res = 1;
        while(b){
            if(b&1) res = res*a%n;
            a = a*a%n;
            b >>= 1;
        }
        return res;
    };
    auto suspect = [&](ll a, ll t){
        a = modpow(a,t);
        while(t != -1+n && a != 1 && a != -1+n){
            a = a*a%n;
            t *= 2;
        }
        return a == n-1 || t%2 == 1;
    };
    static const ll witness[] = {2,7,61,0}; // n <= 2^32
    for(const ll *w = witness; *w < n && *w; w++){
        if(!suspect(*w,d)) return false;
    }
    return true;
}

bool isPrimeLarge(const ll &n){
    if(n == 2) return true;
    if(n < 2 || n%2 == 0) return false;
    const ll m = n-1, d = m / (m & -m);
    auto modmul = [&](ll a, ll b){
        ll res = 0;
        while(b){
            if(b&1) res = ((ull)res+a)%n;
            a = ((ull)a+a)%n;
            b >>= 1;
        }
        return res;
    };
    auto modpow = [&](ll a, ll b){
        ll res = 1;
        while(b){
            if(b&1) res = modmul(res,a);
            a = modmul(a,a);
            b >>= 1;
        }
        return res;
    };
    auto suspect = [&](ll a, ll t){
        a = modpow(a,t);
        while(t != -1+n && a != 1 && a != -1+n){
            a = modmul(a,a);
            t *= 2;
        }
        return a == n-1 || t%2 == 1;
    };
    static const ll witness[] = {2,325,9375,28178,450775,9780504,1795265022,0}; // n <= 2^64
    for(const ll *w = witness; *w < n && *w; w++){
        if(!suspect(*w,d)) return false;
    }
    return true;
}

bool isPrime(const ll &n){
    return n < INT_MAX ? isPrimeSmall(n) : isPrimeLarge(n);
}

// ガウス素数＝複素数の素数判定
bool isGaussianPrime(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b % 4 == 3 && isPrime(b);
    if (b == 0) return a % 4 == 3 && isPrime(a);
    return isPrime(a*a+b*b);
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



ll n = 100000;
int main(void) {
    // 構築O(n log n), 参照O(log n)
    constructPrime(n);

    // [0, 30)の素数
    rep(i, 30) 
        if (is_prime[i]) 
            cout << i << " ";
    cout << endl;

    // 素因数分解
    int m; vll f;
    m = 1; factorize(m, f); cout << f << endl;
    m = 2; factorize(m, f); cout << f << endl;
    m = 4; factorize(m, f); cout << f << endl;
    m = 8; factorize(m, f); cout << f << endl;
    m = 3; factorize(m, f); cout << f << endl;
    m = 120; factorize(m, f);  cout << f << endl;
    m = 1000000007; factorize(m, f); cout << f << endl;

    vector<ll> d;
    m = 120; divisors(m, d);
    rep(i, d.size()) 
        cout << d[i] << " ";
    cout << "# num = " << getDivisorsNum(m) << " ";
    cout << endl;

    return 0;
}

