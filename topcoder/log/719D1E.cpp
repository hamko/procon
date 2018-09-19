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

class LongMansionDiv1 {
    public:
        vll t;
        ll dist(ll sx_, ll ex_) {
                ll ret = 0;
                repi(i, min(sx_, ex_), max(sx_, ex_) + 1) {
                    ret += t[i];
                }
                return ret;
        }
        long long minimalTime(vector <int> t_, int sx_, int sy_, int ex_, int ey_) {
            t = conv(t_);
            ll sx = sx_, sy = sy_, ex = ex_, ey = ey_;
            if (sx == ex && sy == ey) {
                return t[sx];
            }
            if (sy == ey) {
                return dist(sx_, ex_);
            }
            ll n = t.size();
            ll ret = INF;
            rep(i_, n) {
                ll cost = 0;
                cost += t[i_] * max(0ll, abs(ey - sy) - 1);
                cost += dist(i_, sx);
                cost += dist(i_, ex);
                chmin(ret, cost);
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	LongMansionDiv1 *obj;
	long long answer;
	obj = new LongMansionDiv1();
	clock_t startTime = clock();
	answer = obj->minimalTime(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	int p1;
	int p2;
	int p3;
	int p4;
	long long p5;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {5,3,10};
	p1 = 2;
	p2 = 0;
	p3 = 2;
	p4 = 2;
	p5 = 29ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {5,3,10};
	p1 = 0;
	p2 = 2;
	p3 = 0;
	p4 = 0;
	p5 = 15ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {137,200,184,243,252,113,162};
	p1 = 0;
	p2 = 2;
	p3 = 4;
	p4 = 2;
	p5 = 1016ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {995,996,1000,997,999,1000,997,996,1000,996,1000,997,999,996,1000,998,999,995,995,998,995,998,995,997,998,996,998,996,997,1000,998,997,995,1000,996,997,1000,997,997,999,998,995,999,999,1000,1000,998,997,995,999};
	p1 = 18;
	p2 = 433156521;
	p3 = 28;
	p4 = 138238863;
	p5 = 293443080673ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1};
	p1 = 0;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	p5 = 1ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) ) && all_right;
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
// LYC is the pet dog of Emperor Zhangzj of Yali Empire. Zhangzj has a huge affluence. Besides his palace, he has multiple estates. One of them is the Long Mansion, a famous site in Yali. LYC loves to play. One day, he accidentally enters the labyrinthine Long Mansion.
// 
// The mansion can be seen as a grid of unit square cells. There are N rows, indexed from 0 to (N - 1). The number of columns is infinite in one direction. The columns are indexed by nonnegative integers, starting from 0. You are given ints sX, sY, eX, eY. Initially LYC is standing on the cell on the sXth row, and the sYth column. The exit is at the cell on the eXth row, and the eYth column. LYC can walk to a cell that shares an edge with the cell he is at. He wished to reach the exit as soon as possible.
// 
// Unfortunately, each cell contains some obstacles that slow LYC down. For each cell we know the time LYC needs to spend there while passing through the cell. LYC also needs to spend that amount of time in the initial cell and in the exit cell as well. There is a pattern to the obstacles: each column of the mansion looks the same. In other words, all cells within any given row contain the same obstacle type, and therefore they delay LYC by the same amount of time. For example, the entire first row are some bushes, the entire second row contains some walls, and so on. You are given the times in the vector <int> t. More precisely, LYC will spend t[i] time in each cell he visits in row i.
// 
// You are given one vector <int> t and 4 ints sX, sY, eX, eY. Return the minimal time LYC needs to spend to reach the exit.
// 
// DEFINITION
// Class:LongMansionDiv1
// Method:minimalTime
// Parameters:vector <int>, int, int, int, int
// Returns:long long
// Method signature:long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 50, inclusive.
// -t will contain exactly N elements.
// -Each element of t will be between 1 and 1,000, inclusive.
// -sX and eX will be between 0 and (N - 1), inclusive.
// -sY and eY will be between 0 and 1,000,000,000 inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5, 3, 10}
// 2
// 0
// 2
// 2
// 
// Returns: 29
// 
// The optimal path would be (2, 0) &rarr (1, 0) &rarr (1, 1) &rarr (1, 2) &rarr (2, 2). The total time would be 10 + 3 + 3 + 3 + 10 = 29. Note that you should count the time LYC spends on the inital cell and the cell of the exit as well.
// 
// 
// 1)
// {5, 3, 10}
// 0
// 2
// 0
// 0
// 
// Returns: 15
// 
// This time the optimal path would be (0, 2) &rarr (0, 1) &rarr (0, 0).
// 
// 
// 2)
// {137, 200, 184, 243, 252, 113, 162}
// 0
// 2
// 4
// 2
// 
// Returns: 1016
// 
// 
// 
// 3)
// {995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999}
// 18
// 433156521
// 28
// 138238863
// 
// Returns: 293443080673
// 
// 
// 
// 4)
// {1}
// 0
// 0
// 0
// 0
// 
// Returns: 1
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
