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

class LuckySum {
    public:
        ll dp[20][2][3];
        long long construct(string s) {
            ll n = s.length();
            rep(i, 20) rep(j, 2) rep(h, 3) dp[i][j][h] = INF;
            dp[0][0][2] = 0;
            rep(i, n) {
                bool q = s[n-i-1] == '?';
                ll d = s[n-i-1] - '0'; 
                rep(j, 2) rep(h, 3) if (dp[i][j][h] != INF) {
                    ll v = dp[i][j][h];
                    if (h == 2) {
                        if (q || d == j + 4 + 4)  // a[i] = 4, b[i] = 4
                            chmin(dp[i+1][0][2], v + pow(10, i) * (4 + 4));
                        if (q || d == (j + 4 + 7) % 10) // a[i] = 4, b[i] = 7
                            chmin(dp[i+1][1][2], v + pow(10, i) * (4 + 7));
                        if (q || d == (j + 7 + 7) % 10) // a[i] = 7, b[i] = 7
                            chmin(dp[i+1][1][2], v + pow(10, i) * (7 + 7));
                    }
                    if (!i) continue; // 最初のbitは必ずどちらかで埋めないと
                    
                    if (h >= 1) {
                        if (q || d == j + 4) // a[i] = 4, b[i] = 0
                            chmin(dp[i+1][0][1], v + pow(10, i) * (4));
                        if (q || d == j + 7) // a[i] = 0, b[i] = 7
                            chmin(dp[i+1][0][1], v + pow(10, i) * (7));
                    }

                    if (i == n - 1 && j && (q || d == 1)) {
                        if (q || d == 1) 
                            chmin(dp[i+1][0][0], v);
                    }
                }
            }
            ll ret = INF;
            rep(h, 3)
                chmin(ret, dp[n][0][h]);
            if (ret == INF)
                return -1;
            else 
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	LuckySum *obj;
	long long answer;
	obj = new LuckySum();
	clock_t startTime = clock();
	answer = obj->construct(p0);
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
	
	string p0;
	long long p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = "?";
	p1 = 8ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "?1";
	p1 = 11ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "4?8";
	p1 = 448ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "2?" "?";
	p1 = -1ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?";
	p1 = 11888888888888ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// A lucky number is a positive integer such that each of its digits is a 4 or a 7.
// A lucky sum is the sum of two (not necessarily distinct) lucky numbers.
// Cat loves lucky sums!
// 
// 
// 
// Cat has a string note.
// Each character in note is either a digit or a question mark.
// A number matches note if it can be produced from note by changing each question mark to a single digit.
// Note that the number produced this way must not have any leading zeros: after the changes, note[0] must be between '1' and '9', inclusive.
// 
// 
// 
// Find and return the smallest lucky sum that matches note.
// If there are no lucky sums that match note, return -1.
// 
// 
// DEFINITION
// Class:LuckySum
// Method:construct
// Parameters:string
// Returns:long long
// Method signature:long long construct(string note)
// 
// 
// CONSTRAINTS
// -note will contain between 1 and 14 characters, inclusive.
// -Each character of note will be either a digit ('0'-'9') or a question mark ('?').
// -The first character of note will not be '0'.
// -At least one character of note will be '?'.
// 
// 
// EXAMPLES
// 
// 0)
// "?"
// 
// Returns: 8
// 
// 4+4=8, which is the smallest lucky sum.
// 
// 1)
// "?1"
// 
// Returns: 11
// 
// 4+7=11
// 
// 2)
// "4?8"
// 
// Returns: 448
// 
// 4+444=448
// 
// 3)
// "2??"
// 
// Returns: -1
// 
// The numbers that match this note are the numbers 200 through 299. None of these numbers is a lucky sum.
// 
// 4)
// "??????????????"
// 
// Returns: 11888888888888
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
