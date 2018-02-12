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

vector<vector<int16_t>> g;
class FrogSquare {
    public:
        int minimalJumps(int n, int d, int sx, int sy, int tx, int ty) {
            if (mt(sx, sy) == mt(tx, ty)) return 0;
            vector<P> pos;
            pos.pb(P(sx, sy));
            pos.pb(P(tx, ty));
            rep(i, n) pos.pb(P(0  , i));
            rep(i, n) pos.pb(P(n-1, i));
            rep(i, n) pos.pb(P(i, 0));
            rep(i, n) pos.pb(P(i, n-1));

            n = pos.size();
            g = vector<vector<int16_t>>(n);
            rep(i, n) {
                rep(j, n) if (i != j) {
                    double dist = sqrt(pow(pos[i].fi - pos[j].fi, 2) + pow(pos[i].se - pos[j].se, 2));
                    if (dist >= d) {
                        g[i].pb(j);
                    }
                }
            }
//            cout << g << endl;

            vll states, states_next;
            states.pb(0);
            vll dist(n, INF);
            ll cyc = 0;
            while (states.size()) {
                states_next.clear();
//                cout << states << endl;
                for (auto now : states) {
                    if (dist[now] != INF) continue;
                    dist[now] = cyc;
                    for (auto v : g[now]) {
                        states_next.pb(v);
                    }
                }
                swap(states, states_next);
                cyc++;
            }
            if (dist[1] == INF) 
                return -1;
            else 
                return dist[1];
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	FrogSquare *obj;
	int answer;
	obj = new FrogSquare();
	clock_t startTime = clock();
	answer = obj->minimalJumps(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	int p3;
	int p4;
	int p5;
	int p6;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 100;
	p1 = 10;
	p2 = 0;
	p3 = 0;
	p4 = 3;
	p5 = 4;
	p6 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 100;
	p1 = 5;
	p2 = 0;
	p3 = 0;
	p4 = 3;
	p5 = 4;
	p6 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 100;
	p1 = 200;
	p2 = 0;
	p3 = 0;
	p4 = 3;
	p5 = 4;
	p6 = -1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 10;
	p1 = 7;
	p2 = 4;
	p3 = 4;
	p4 = 5;
	p5 = 5;
	p6 = 3;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	p5 = 0;
	p6 = 0;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    
		// ----- test 4 -----
	disabled = false;
	p0 = 689;
	p1 = 731;
	p2 = 249;
	p3 = 97;
	p4 = 599;
	p5 = 237;
	p6 = 4;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
			// ----- test 4 -----
	disabled = false;
	p0 = 880;
	p1 = 150;
	p2 = 436;
	p3 = 858;
	p4 = 457;
	p5 = 781;
	p6 = 2;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
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
// We have an n by n board.
// Both rows and columns are numbered 0 through n-1.
// 
// 
// 
// There is a frog on the board.
// Initially, the frog is located in the cell (sx, sy).
// Its goal is to reach the cell (tx, ty).
// 
// 
// 
// The frog can move by making a sequence of zero or more jumps.
// Each jump must have length at least d.
// More precisely, the frog can jump from (r1,c1) to (r2,c2) if and only if the Euclidean distance between the centers of those two cells is at least d.
// Formally, sqrt( (r1-r2)^2 + (c1-c2)^2 ) must be greater than or equal to d.
// 
// 
// 
// The frog is not allowed to jump outside the board.
// 
// 
// 
// You are given the ints n, d, sx, sy, tx, and ty.
// Compute and return the minimum number of jumps the frog needs to make to reach its goal.
// If the goal cannot be reached, return -1 instead.
// 
// DEFINITION
// Class:FrogSquare
// Method:minimalJumps
// Parameters:int, int, int, int, int, int
// Returns:int
// Method signature:int minimalJumps(int n, int d, int sx, int sy, int tx, int ty)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 1,000, inclusive.
// -d will be between 1 and 2,000, inclusive.
// -sx will be between 0 and n-1, inclusive.
// -sy will be between 0 and n-1, inclusive.
// -tx will be between 0 and n-1, inclusive.
// -ty will be between 0 and n-1, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 100
// 10
// 0
// 0
// 3
// 4
// 
// Returns: 2
// 
// The distance between (0, 0) and (3, 4) is 5, which is less than 10, so we can't jump there direcly. However we can get there in 2 jumps, for example: from (0, 0) to (10, 0), then to (3, 4).
// 
// 1)
// 100
// 5
// 0
// 0
// 3
// 4
// 
// Returns: 1
// 
// This time we can jump to (3, 4) directly.
// 
// 2)
// 100
// 200
// 0
// 0
// 3
// 4
// 
// Returns: -1
// 
// You can't jump to anywhere on the board from (0, 0). Thus you can't get to (3, 4).
// 
// 3)
// 10
// 7
// 4
// 4
// 5
// 5
// 
// Returns: 3
// 
// 
// 
// 4)
// 1
// 1
// 0
// 0
// 0
// 0
// 
// Returns: 0
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
