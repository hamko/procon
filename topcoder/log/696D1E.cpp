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

class Gperm {
    public:
        vvll g;
        int countfee(vector <int> x, vector <int> y) {
            ll n = 50;
            ll m = x.size();
            vll pmask(n);
            rep(i, n) rep(j, m) if (x[j] == i || y[j] == i) 
                pmask[i] |= (1ll << j);

            vll dp(1ll << m, INF);
            dp[0] = 0;
            // 配るDP
            rep(mask, 1ll << m) rep(i, n) {
                chmin(dp[mask | pmask[i]], dp[mask] + m - __builtin_popcount(mask));
            }
            return dp.back();
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	Gperm *obj;
	int answer;
	obj = new Gperm();
	clock_t startTime = clock();
	answer = obj->countfee(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {0};
	p1 = {1};
	p2 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {0,1};
	p1 = {1,2};
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {4,7,7};
	p1 = {7,4,4};
	p2 = 3;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	

	// ----- test 4 -----
	disabled = false;
	p0 = {7,8,9};
	p1 = {4,5,6};
	p2 = 6;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28};
	p1 = {45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27};
	p2 = 53;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 3 -----
	disabled = false;
	p0 = {0,0,1};
	p1 = {1,2,2};
	p2 = 4;
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
// Hero has an undirected multigraph.
// (Each pair of vertices can be connected by arbitrarily many undirected edges. There may also be arbitrarily many self-loops at each vertex.)
// Hero's graph has exactly 50 vertices, labeled 0 through 49.
// 
// The graph has at most 20 edges.
// You are given the list of those edges: the vector <int>s x and y.
// For each valid i, there is an edge that connects the vertices x[i] and y[i].
// (Self-loops have x[i] = y[i].)
// 
// Hero needs to paint all vertices red.
// He can paint the vertices in any order he likes, one vertex at a time.
// Each time he paints a vertex he has to pay a fee.
// The fee is computed as the number of edges that already have both endpoints red.
// 
// Hero wants to minimize the sum of all fees he has to pay.
// Find the order in which he should paint the vertices, and return the corresponding total fee.
// 
// DEFINITION
// Class:Gperm
// Method:countfee
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int countfee(vector <int> x, vector <int> y)
// 
// 
// CONSTRAINTS
// -x will contain between 1 and 20 elements, inclusive.
// -x and y will contain the same number of elements.
// -Each element in x and y will be between 0 and 49, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {0}
// {1}
// 
// Returns: 1
// 
// One optimal order of painting the vertices is 49, 48, 47, ..., 3, 2, 1, 0.
// The first 49 times the fee is 0.
// After Hero paints the last vertex, the last fee is 1.
// 
// 1)
// {0,1}
// {1,2}
// 
// Returns: 2
// 
// One optimal order of painting these vertices is 49, 48, ..., 5, 4, 3, 0, 2, 1. The last three fees will be 0, 0, and 2.
// 
// 2)
// {4,7,7}
// {7,4,4}
// 
// Returns: 3
// 
// 
// 
// 3)
// {0,0,1}
// {1,2,2}
// 
// Returns: 4
// 
// Hero should first paint the 47 isolated vertices and then the remaining three vertices in any order.
// Regardless of the order in which Hero paints the last three vertices, the last three fees will be 0, 1, and 3.
// 
// 4)
// {7,8,9}
// {4,5,6}
// 
// Returns: 6
// 
// 
// 
// 5)
// {45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28}
// {45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27}
// 
// Returns: 53
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
