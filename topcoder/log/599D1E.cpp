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

template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); return s; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }

// 素数の個数はO(n / log n)

/**********************************************************/
// 素数テーブルの作成
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
void factorize(ll n, unordered_map<ll, ll>& divisors_list) {
    if (n <= 1) return;

    ll prime;
    for (ll i = 0; (prime = primes[i]) && n >= prime * prime; )  
        if (n % prime) 
            i++;
        else 
            divisors_list[prime]++, n /= prime;
    if (n != 1) 
        divisors_list[n]++;
}

class BigFatInteger {
    public:
        int minOperations(int a, int b) {
            constructPrime(2000000);
            unordered_map<ll, ll> p; factorize(a, p);
            ll maxb = 0;
            for (auto&& x : p) 
                chmax(maxb, x.se);
            maxb *= b;
            maxb--;
            cout << maxb << endl;
            
            ll maxbit = -1;
            rep(i, 60) if (maxb & (1ll << i)) maxbit = i;
            return p.size() + maxbit + 1;

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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	BigFatInteger *obj;
	int answer;
	obj = new BigFatInteger();
	clock_t startTime = clock();
	answer = obj->minOperations(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 6;
	p1 = 1;
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 162;
	p1 = 1;
	p2 = 4;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 999983;
	p1 = 9;
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 360;
	p1 = 8;
	p2 = 8;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
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
// This problem statement contains superscipts that may not display properly outside the applet.
// 
// Lun the dog loves very large integers. Her favorite is AB (A to the power of B).
// 
// 
// She has an integer variable X. Initially, the value of X is set to 1. She can perform the following two kinds of operations in any order, any number of times.
// 
// Operation 1: choose a prime number p, then multiply X by p.
// Operation 2: choose a positive divisor d of the value of X at that point, then multiply X by d.
// 
// 
// 
// You are given two ints A and B. Return the minimum number of operations Lun needs to perform
// in order to obtain X = AB from the initial state X = 1.
// 
// DEFINITION
// Class:BigFatInteger
// Method:minOperations
// Parameters:int, int
// Returns:int
// Method signature:int minOperations(int A, int B)
// 
// 
// CONSTRAINTS
// -A will be between 2 and 1,000,000 (106), inclusive.
// -B will be between 1 and 1,000,000 (106), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 6
// 1
// 
// Returns: 2
// 
// Here, AB = 61 = 6. Here is one of the optimal sequences of operations:
// 
// Perform operation 1 by choosing p=2. X is now 1*2 = 2.
// Perform operation 1 by choosing p=3. X is now 2*3 = 6.
// 
// 
// 1)
// 162
// 1
// 
// Returns: 4
// 
// One of the optimal sequences of operations:
// 
// Perform operation 1 by choosing p=3. X is now 1*3 = 3.
// Perform operation 1 by choosing p=3. X is now 3*3 = 9.
// Perform operation 2 by choosing d=9. X is now 9*9 = 81.
// Perform operation 1 by choosing p=2. X is now 81*2 = 162.
// 
// 
// 2)
// 999983
// 9
// 
// Returns: 5
// 
// Here, A is prime. One of the optimal sequences of operations:
// 
// Perform operation 1 by choosing p=A. X is now A.
// Perform operation 1 by choosing p=A. X is now A2.
// Perform operation 1 by choosing p=A. X is now A3.
// Perform operation 2 by choosing d=A3. X is now A6.
// Perform operation 2 by choosing d=A3. X is now A9.
// 
// 
// 3)
// 360
// 8
// 
// Returns: 8
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
