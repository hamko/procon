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

class PowerOfThree {
    public:
        string ableToGet(int x_, int y_) {
            ll x = x_, y = y_;
            rep(_, 100) {
                x = abs(x), y = abs(y);
                if (!x && !y) return "Possible";
                ll x3 = x % 3;
                ll y3 = y % 3;
                if ((!!x3 ^ !!y3) == 0) return "Impossible";
                if (x3 == 1) {
                    x -= 1;
                } else if (x3 == 2) {
                    x += 1;
                } else if (y3 == 1) {
                    y -= 1;
                } else if (y3 == 2) {
                    y += 1;
                } else {
                    cout << x3 << " " << y3 << endl;
                    assert(0);
                }
                x /= 3, y /= 3;
            }
            if (x % 3 && y % 3) return "Impossible";
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	PowerOfThree *obj;
	string answer;
	obj = new PowerOfThree();
	clock_t startTime = clock();
	answer = obj->ableToGet(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 1;
	p1 = 3;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 0;
	p1 = 2;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 1;
	p1 = 9;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 3;
	p1 = 0;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = -6890;
	p1 = 18252;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = 1000000000;
	p1 = -1000000000;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
		// ----- test 4 -----
	disabled = false;
	p0 = 760;
	p1 = -427;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = 0;
	p1 = 0;
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //	// ----- test 7 -----
	disabled = false;
	p0 = -834;
	p1 = -2423;
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, true, p2) ) && all_right;
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
// Fox Ciel has a robot.
// The robot is located on an infinite plane.
// At the beginning, the robot starts at the coordinates (0, 0).
// The robot can then make several steps.
// The steps are numbered starting from 0.
// 
// In each step, Ciel must choose one of four directions for the robot: left (x coordinate decreases), right (x coordinate increases), up (y coordinate increases), or down (y coordinate decreases).
// In step k, the robot will move 3^k units in the chosen direction.
// It is not allowed to skip a step.
// 
// You are given ints x and y.
// Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps.
// Otherwise, return "Impossible".
// 
// DEFINITION
// Class:PowerOfThree
// Method:ableToGet
// Parameters:int, int
// Returns:string
// Method signature:string ableToGet(int x, int y)
// 
// 
// CONSTRAINTS
// -x will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -y will be between -1,000,000,000 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 3
// 
// Returns: "Possible"
// 
// In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).
// 
// 1)
// 0
// 2
// 
// Returns: "Possible"
// 
// The robot will move from (0,0) down to (0,-1) and then up to (0,2).
// 
// 2)
// 1
// 9
// 
// Returns: "Impossible"
// 
// Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.
// 
// 3)
// 3
// 0
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// 1
// 1
// 
// Returns: "Impossible"
// 
// 
// 
// 5)
// -6890
// 18252
// 
// Returns: "Possible"
// 
// 
// 
// 6)
// 1000000000
// -1000000000
// 
// Returns: "Impossible"
// 
// 
// 
// 7)
// 0
// 0
// 
// Returns: "Possible"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
