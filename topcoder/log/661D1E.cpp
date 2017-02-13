#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
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

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

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

// [0, n]の範囲を全て素因数分解する。
void factorize(ll n, vector<unordered_map<ll, ll>>& fact) {
    fact.clear();
    fact.resize(n+1);

    vector<ll> rem(n+1); rep(i, n+1) rem[i] = i;
    for (auto x : primes) {
        for (ll i = x; i <= n; i += x) {
            while (rem[i] % x == 0) {
                rem[i] /= x;
                fact[i][x]++;
            }
        }
    }
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

extern vector<bool> is_prime;
extern vector<ll> primes;      // 素数リスト

class MissingLCM {
    public:
        int getMin(int n) {
            constructPrime(n+10);
            cout << "$$$$$$$$$$$$$$" << endl;


            unordered_map<ll, ll> fact;

            vector<ll> rem(n+1); rep(i, n+1) rem[i] = i;
            for (auto x : primes) { // n / log n
                for (ll i = x; i <= n; i += x) { // log n
                    ll c = 0;
                    while (rem[i] % x == 0) 
                        rem[i] /= x, c++;
                    chmax(fact[x], c);
                }
            }

            ll ret = 2;
            for (auto x : fact) {
                ll pk = pow(x.fi, x.se);
                chmax(ret, (n / pk + 1) * pk);
//                cout << x << " " << pk << endl;
            }
            return ret;
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
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << p0;
    cout << "]" << endl;
    MissingLCM *obj;
    int answer;
    obj = new MissingLCM();
    clock_t startTime = clock();
    answer = obj->getMin(p0);
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
    int p1;

    // ----- test 0 -----
    disabled = false;
    p0 = 1;
    p1 = 2;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = 2;
    p1 = 4;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = 3;
    p1 = 6;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = 4;
	p1 = 8;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 5;
	p1 = 10;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = 42;
	p1 = 82;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = 10000000;
	p1 = 1999966;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, true, p1) ) && all_right;
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
// 
// The least common multiple (denoted "lcm") of a non-empty sequence of positive integers is the smallest positive integer that is divisible by each of them.
// For example, lcm(2)=2, lcm(4,6)=12, and lcm(1,2,3,4,5)=60.
// 
// 
// 
// Alice had a positive integer N.
// Then she chose some positive integer M that was strictly greater than N.
// Afterwards, she computed two values:
// the value A = lcm(N+1, N+2, ..., M) and the value B = lcm(1, 2, ..., M).
// She was surprised when she saw that A = B.
// 
// 
// 
// You are given the int N.
// Find and return the smallest M Alice could have chosen.
// (Such an M will always exist.)
// 
// 
// DEFINITION
// Class:MissingLCM
// Method:getMin
// Parameters:int
// Returns:int
// Method signature:int getMin(int N)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: 2
// 
// Alice needs to choose an M > 1 such that lcm(2,...,M) = lcm(1,...,M). We can see M=2 is the minimum value that works, since lcm(1,2) = lcm(2) = 2.
// 
// 1)
// 2
// 
// Returns: 4
// 
// 
// 
// 2)
// 3
// 
// Returns: 6
// 
// We have lcm(4,5,6) = lcm(1,2,3,4,5,6) = 60.
// 
// 3)
// 4
// 
// Returns: 8
// 
// 
// 
// 4)
// 5
// 
// Returns: 10
// 
// 
// 
// 5)
// 42
// 
// Returns: 82
// 
// Oh... that doesn't fit the pattern.
// 
// 6)
// 999999
// 
// Returns: 1999966
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
