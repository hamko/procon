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

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)が必須！
/**********************************************************/
// O(n log n)
void sieve_of_eratosthenes(vector<ll>& primes, ll n) {
    primes.resize(n);
    for (ll i = 2; i < n; ++i)
        primes[i] = i;
    for (ll i = 2; i*i < n; ++i)
        if (primes[i])
            for (ll j = i*i; j < n; j+=i)
                primes[j] = 0;
}
void getPrimesList(ll n, vector<ll>& primes_list) {
    vector<ll> tmpList;
    primes_list.clear(); primes_list.resize(0); primes_list.reserve(n / 5);
    sieve_of_eratosthenes(tmpList, n);
    rep(i, n) { 
        if (tmpList[i])
            primes_list.push_back(i);
    }
}

// 素数テーブル構築: O(n log n)
vector<ll> primesList;      // 素数リスト（primesListMaxまで）。こいつ自体を使うことあるかも。
set<ll> primesSet;
ll primesListMax;
void constructPrimesList(ll n) {
    if (primesListMax >= n) 
        return;
    primesListMax = n;
    getPrimesList(n, primesList);
    for (ll i = 0; i < primesList.size(); i++) {
        primesSet.insert(primesList[i]);
    }
}
// constructされていないなら、O(n log n)
// constructされているなら、O(log n)
bool isPrimeLookup(ll n) {
    return primesSet.count(n);
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
// Divisor系は、最大nをMAXNとしてconstructPrimesList(sqrt(MAXN))で早くなる
void getPrimeFactorizationList(ll n, map<ll, ll>& divisors_list) {
    divisors_list.clear();
    if (n <= 1) return;

    ll prime = 2;
    while (n >= prime * prime) {
        if (n % prime == 0) {
            divisors_list[prime]++;
            n /= prime;
        } else {
            prime++;
        }
    }
    divisors_list[n]++;
}

vll a;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    a = vll(n); rep(i, a.size()) cin >> a[i];

    constructPrimesList(1e6);
    map<ll, ll> f;
    getPrimeFactorizationList(k, f);
    for (auto x : f) {
        cout << x << endl;
        ll tex = 0;
        rep(i, n) {
            if (a[i] % (ll)pow(x.fi, x.se) == 0) {
                tex = 1;
            }
        }
        if (!tex) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    return 0;
}
