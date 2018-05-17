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
    map<ll, ll> num;
    rep(i, divisors_list.size()) 
        num[divisors_list[i]]++;
    ll p = 1;
    for (auto x : num) 
        p *= x.second + 1;
    return p;
}


/**********************************************************/
// 前処理なしの素数判定
/**********************************************************/
using u64 = unsigned long long;
using u128 = __uint128_t;
__uint128_t mul(u64 a, u64 b, u64 m) { return u128(a) * b % m; };
bool isPrime(unsigned long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    static mt19937 mt(time(NULL));
    u64 s = n - 1;
    int e = 0;
    for (; s % 2 == 0; s /= 2) e++;
    for (int ii = 0; ii < 8; ii++) {
        u64 x = std::uniform_int_distribution<u64>(2, n - 1)(mt);
        u64 r = 1;
        for (u64 i = s; i > 0; i >>= 1, x = mul(x, x, n)) {
            if (i & 1) r = mul(r, x, n);
        }
        if (r == 1) continue;
        for (int i = 1; i < e && r != n - 1; i++) {
            r = mul(r, r, n);
        }
        if (r != n - 1) return false;
    }
    return true;
}


// O(n^0.25)
// ローのアルゴリズム
// 計算結果はrho_retに保存される
using ull = unsigned long long;
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


class TheRoundCityDiv1 {
    public:
        ll brutal(ll r) {
            unordered_set<P> s;
            repi(x, 1, r+1) repi(y, 0, r+1) if ((x||y)&&x*x+y*y<=r*r) {
                ll g = __gcd(x, y);
                s.insert(P(x/g,y/g));
            }
            return s.size() * 4ll;
        }
        ll count(ll y, ll m) {
            // [1, m]で
            auto ds = factorize(y);
//            cout << y << " " << m << " " << ds<< endl;
            vll div;
            for (auto d : ds) {
                div.pb(d.fi);
            }
            ll ret = m;
            rep(mask, 1ll<<div.size()) if (mask) {
                ll d = 1;
                rep(i, div.size()) if (mask & (1ll << i)) {
                    d *= div[i];
                }
                ret += (__builtin_popcountll(mask) % 2 == 0 ? +1 : -1) * m / d;
            }

            return ret;
        }
        ll solve(ll r) {
            cout << r << endl;

            ll ret = 1;
            repi(y, 1, r+1) {
                ret += count(y, (ll)(sqrt(r*r-y*y)+EPS));
            }
            return ret * 4ll;

        }

        long long find(int r_) {
            constructPrime(1e6+10);
            ll r = r_;
            repi(i, 1,1000) assert(brutal(i)==solve(i));

            return 0;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, long long p1) {
    cout << "Test " << testNum << ": [" << p0;
    cout << "]" << endl;
    TheRoundCityDiv1 *obj;
    long long answer;
    obj = new TheRoundCityDiv1();
    clock_t startTime = clock();
    answer = obj->find(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    int p0;
    long long p1;

    // ----- test 0 -----
    disabled = false;
    p0 = 1;
    p1 = 4ll;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = 2;
    p1 = 8ll;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = 3;
    p1 = 16ll;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = 47;
	p1 = 4176ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	    // ----- test 3 -----
    disabled = false;
    p0 = 1e6;
	p1 = 4176ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// John and Brus have found a nice horizontal plane and they built a round city somewhere on the plane.
// The center of the city is at coordinates (0, 0).
// This point is left empty.
// There is a house at each other lattice point that is at most r units away from the city center.
// That is, the lattice point (x, y) other than (0, 0) contains a house if and only if sqrt(x*x + y*y) ≤ r.
// 
// 
// John and Brus are wondering how many houses are visible from the city center.
// A house is visible if and only if there are no other houses on the line segment connecting the house and the city center.
// (For the purpose of this definition, each house is a single point.)
// 
// 
// You are given the int r.
// Return the number of houses that are visible from the city center.
// 
// 
// DEFINITION
// Class:TheRoundCityDiv1
// Method:find
// Parameters:int
// Returns:long long
// Method signature:long long find(int r)
// 
// 
// CONSTRAINTS
// -r will be between 1 and 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: 4
// 
// There are four houses in the city: at (0, 1), (0, -1), (1, 0), and (-1, 0).
// All four of them are visible from the city center.
// 
// 1)
// 2
// 
// Returns: 8
// 
// There are twelve houses in the city: 
// 
// (0, 1), (0, -1), (1, 0), (-1, 0), 
// 
// (1, 1), (1, -1), (-1, 1), (-1, -1),
// 
// (0, 2), (0, -2), (2, 0), (-2, 0), 
// 
// 
// The last four are not visible from the city center. For example, (0, 2) is not visible because (0, 1) is on the line segment from (0, 2) to the city center.
// 
// 2)
// 3
// 
// Returns: 16
// 
// There are twenty-eight houses in the city:
// 
// (0, 1), (0, -1), (1, 0), (-1, 0), 
// 
// (0, 2), (0, -2), (2, 0), (-2, 0), (1, 1), (1, -1), (-1, 1), (-1, -1),
// 
// (0, 3), (0, -3), (3, 0), (-3, 0), (1, 2), (1, -2), (-1, 2), (-1, -2),
// 
// (2, 1), (2, -1), (-2, 1), (-2, -1), (2, 2), (2, -2), (-2, 2), (-2, -2).
// 
// 
// Twelve of them:
// 
// (0, 2), (0, -2), (2, 0), (-2, 0),
// 
// (0, 3), (0, -3), (3, 0), (-3, 0), (2, 2), (2, -2), (-2, 2), (-2, -2)
// 
// are not visible from the city center.
// 
// 3)
// 47
// 
// Returns: 4176
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
