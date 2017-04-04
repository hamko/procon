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

class TaroJiroGrid {
    public:
        ll n;
        vector<string> b;
        bool ok(void) {
            rep(j, n) {
                ll count = 0;
                rep(i, n-1) {
                    if (b[i][j] == b[i+1][j]) 
                        count++;
                    else
                        count = 0;
                    if (count + 1 > n / 2) 
                        return false;
                }
            }
            return true;
        }
        int getNumber(vector <string> b_) {
            b = b_;
            n = b.size();
            if (ok()) 
                return 0;

            rep(mask, 1<<1) rep(i, n) {
                string bi = b[i]; b[i] = string(n, ((mask & (1 << 0)) ? 'W' : 'B'));
                if (ok()) return 1;
                b[i] = bi;
            }


            rep(mask, 1<<2) rep(i, n) rep(j, n) if (i < j) {
                string bi = b[i]; b[i] = string(n, ((mask & (1 << 0)) ? 'W' : 'B'));
                string bj = b[j]; b[j] = string(n, ((mask & (1 << 1)) ? 'W' : 'B'));
                if (ok()) return 2;
                b[i] = bi;
                b[j] = bj;
            }

            rep(mask, 1<<3) rep(i, n) rep(j, n) rep(h, n) if (i < j) if (j < h) {
                string bi = b[i]; b[i] = string(n, ((mask & (1 << 0)) ? 'W' : 'B'));
                string bj = b[j]; b[j] = string(n, ((mask & (1 << 1)) ? 'W' : 'B'));
                string bh = b[h]; b[h] = string(n, ((mask & (1 << 2)) ? 'W' : 'B'));
                if (ok()) return 3;
                b[i] = bi;
                b[j] = bj;
                b[h] = bh;
            }
            return 4;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TaroJiroGrid *obj;
	int answer;
	obj = new TaroJiroGrid();
	clock_t startTime = clock();
	answer = obj->getNumber(p0);
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
	
	vector <string> p0;
	int p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"WB","BB"};
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"WB","WW"};
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"WB","WB"};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"WBBW","WBWB","WWBB","BWWW"};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"WBBWBB","BBWBBW","WWBWBW","BWWBBB","WBWBBW","WWWBWB"};
	p1 = 1;
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
// Cat Taro and Fox Jiro work with a square grid with N rows and N columns (N is even).
// Each cell of the grid is painted either black or white.
// You are given a vector <string> grid which represents the current state of the grid.
// Each element of grid represents one row of the grid.
// In grid, the character 'W' represents a white cell, and the character 'B' represents a black cell. 
// 
// 
// 
// 
// Taro works with the rows of the grid.
// He will take zero or more turns. In each turn he can choose any row of the grid and perform one of the following operations:
// 
// 
// 
// Paint all black cells of the row white.
// 
// 
// Paint all white cells of the row black.
// 
// 
// 
// Jiro works with the columns of the grid.
// He thinks that a column is bad if there are more than N/2 consecutive cells of the same color in the column.
// He is happy only if there are no bad columns in the grid.
// 
// 
// 
// 
// Return the minimum number of turns that Taro must perform in order to make Jiro happy.
// 
// 
// DEFINITION
// Class:TaroJiroGrid
// Method:getNumber
// Parameters:vector <string>
// Returns:int
// Method signature:int getNumber(vector <string> grid)
// 
// 
// CONSTRAINTS
// -N will be between 2 and 50, inclusive.
// -N will be even.
// -grid will contain exactly N elements.
// -Each element of grid will contain exactly N characters.
// -Each character in grid will be 'W' or 'B'.
// 
// 
// EXAMPLES
// 
// 0)
// {"WB",
//  "BB"}
// 
// Returns: 1
// 
// Initially, Jiro is not happy because all cells of the column 1 (0-based index) are black. In one operation, Taro can paint the first row white. After the operation, Jiro will be happy about the grid. Thus, the answer is 1.
// 
// 1)
// {"WB",
//  "WW"}
// 
// Returns: 1
// 
// 
// 
// 2)
// {"WB",
//  "WB"}
// 
// Returns: 2
// 
// In this case, Taro should paint the first row white, and the second one black (or vice versa). Note that it is not possible to make Jiro happy in fewer than two operations.
// 
// 3)
// {"WBBW",
//  "WBWB",
//  "WWBB",
//  "BWWW"}
// 
// Returns: 2
// 
// 
// 
// 4)
// {"WBBWBB",
//  "BBWBBW",
//  "WWBWBW",
//  "BWWBBB",
//  "WBWBBW",
//  "WWWBWB"}
// 
// Returns: 1
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
