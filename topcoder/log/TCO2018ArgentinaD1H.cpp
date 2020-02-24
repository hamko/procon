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

#define double ld
class ProbabilisticAlice {
    public:
        double computeExpectation(vector <string> g, int pn, int pd) {
            ll n = g.size();
            ll m = g[0].size();
            double p = (double)pn / (double)pd;
            vector<vector<double>> dp(n, vector<double>(m));

            for (ll i = n-1; i >= 0; i--) {
                for (ll j = m-1; j >= 0; j--) {
                    if (g[i][j] == 'T') {
                        dp[i][j] = 0;
                    } else {
                        if (i == n-1 && j == m-1) {
                            dp[i][j] = 1;
                        } else if (i == n-1) {
                            dp[i][j] = dp[i][j+1];
                        } else if (j == m-1) {
                            dp[i][j] = dp[i+1][j];
                        } else {
                            dp[i][j] = dp[i+1][j] * p + dp[i][j+1] * (1. - p);
                        }
                    }
                }
            }
            cout << dp[0][0] << endl;

            double q = dp[0][0];
            if (q == 0) {
                return -1;
            } else {
                return (1 - q) / q;
            }


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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	ProbabilisticAlice *obj;
	double answer;
	obj = new ProbabilisticAlice();
	clock_t startTime = clock();
	answer = obj->computeExpectation(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	
	vector <string> p0;
	int p1;
	int p2;
	double p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"..",".."};
	p1 = 1;
	p2 = 2;
	p3 = 0.0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {".T",".."};
	p1 = 1;
	p2 = 2;
	p3 = 1.0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {".T",".."};
	p1 = 46;
	p2 = 47;
	p3 = 0.021739130434782705;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {".....T.","....T..","T..T..."};
	p1 = 2;
	p2 = 3;
	p3 = -1.0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"....T.","...TT.",".T....","...T..","......"};
	p1 = 3;
	p2 = 7;
	p3 = 5.417334860633832;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
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
// The city of Gridland can be seen as a matrix of cells with R rows and C columns.
// The rows and columns are numbered starting from 0.
// Some cells are empty, others contain teleporters.
// Each teleporter transports people from its cell to the cell (0, 0).
// 
// 
// 
// You are given the map of the city in the vector <string> grid.
// The character 'T' represents a teleporter, the character '.' an empty cell.
// 
// 
// 
// Alice is a tourist who just visited Gridland.
// She is currently in the cell (0, 0) and she wants to reach the cell (R-1, C-1).
// While moving around the city, Alice follows a simple set of rules:
// 
// 
// 
// Whenever she moves, she moves to a cell that is adjacent to her current cell and closer to her goal. Thus, in general, from the cell (i, j) she will move either to (i+1, j) or to (i, j+1).
// If Alice only has one valid move, she makes it.
// If Alice has two valid moves, she flips a biased coin to choose one of them.
// 
// 
// 
// You are given the ints pnum and pden.
// Let p = pnum / pden.
// Whenever Alice is in some cell (i, j) and she has two valid ways to move, she moves to the cell (i+1, j) with probability p and to the cell (i, j+1) with probability 1-p.
// 
// 
// 
// Compute and return the expected number of times Alice will get teleported back to (0, 0) before she reaches the cell (R-1, C-1).
// If Alice cannot reach her target cell at all, return -1 instead.
// 
// 
// DEFINITION
// Class:ProbabilisticAlice
// Method:computeExpectation
// Parameters:vector <string>, int, int
// Returns:double
// Method signature:double computeExpectation(vector <string> grid, int pnum, int pden)
// 
// 
// NOTES
// -Your answer will be accepted if it has an absolute or a relative error at most 1e-9.
// 
// 
// CONSTRAINTS
// -R and C will each be between 2 and 20, inclusive.
// -grid will contain R elements.
// -Each element of grid will contain C characters.
// -Each character in grid will be either 'T' or '.'.
// -grid[0][0] will be '.'.
// -grid[R-1][C-1] will be '.'.
// -pden will be between 2 and 1000, inclusive.
// -pnum will be between 1 and pden-1, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"..",
//  ".."}
// 1
// 2
// 
// Returns: 0.0
// 
// There are no teleporters. Alice will reach her goal without getting teleported.
// 
// 1)
// {".T",
//  ".."}
// 1
// 2
// 
// Returns: 1.0
// 
// 
// When standing in the cell (0, 0). Alice always flips a fair coin to choose where to go next. With probability 1/2 she moves down, and from there she will reach her goal. With probability 1/2 she moves to the right, steps into the teleporter, and gets teleported back to where she started.
// 
// 
// 
// One possible path Alice can take: Step right, get teleported back, step right, get teleported back, step down, and step right to reach the goal.
// She will take this particular path with probability 1/8.
// 
// 
// 
// One way of computing the expected number of times she will be teleported is as follows:
// 
// She will be teleported 0 times with probability 1/2.
// She will be teleported 1 times with probability 1/4.
// She will be teleported 2 times with probability 1/8.
// ...
// 
// 
// 
// 
// Thus, the expected number of times she will be teleported is 0 * (1/2) + 1 * (1/4) + 2 * (1/8) + ... = 1.
// 
// 
// 2)
// {".T",
//  ".."}
// 46
// 47
// 
// Returns: 0.021739130434782705
// 
// The map is the same but now Alice almost always moves downwards. Thus, the expected number of times she hits the teleporter is now much lower.
// 
// 3)
// {".....T.",
//  "....T..",
//  "T..T..."}
// 2
// 3
// 
// Returns: -1.0
// 
// In this city Alice will never reach her goal.
// 
// 4)
// {"....T.",
//  "...TT.",
//  ".T....",
//  "...T..",
//  "......"}
// 3
// 7
// 
// Returns: 5.417334860633832
// 
// One of these teleporters is in a place Alice will never reach.
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
