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

class BuildingRoutes {
    public:
        int build(vector <string> dist, int T) {
            ll n = dist.size();
            vvll g(n, vll(n, INF));
            rep(i, n) rep(j, n) {
                dist[i][j] -= '0';
            }
            rep(i, n) g[i][i] = 0;
            rep(i, n) rep(j, n) g[i][j] = dist[i][j];
            rep(k, n) rep(i, n) rep(j, n) {
                chmin(g[i][j], g[i][k] + g[k][j]);
            }
            ll ans = 0;
            rep(i, n) rep(j, n) if (i != j) {
                // i->jの辺を見て
                ll ret = 0;
                rep(h, n) rep(k, n) if (h != k) {
                    // その辺が頂点h->kの最短経路の一部に使われる個数
                    ret += g[h][k] == g[h][i] + dist[i][j] + g[j][k];
                }
                ans += (ret >= T) * dist[i][j];
            }
            return ans;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	BuildingRoutes *obj;
	int answer;
	obj = new BuildingRoutes();
	clock_t startTime = clock();
	answer = obj->build(p0, p1);
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
	
	vector <string> p0;
	int p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"011","101","110"};
	p1 = 1;
	p2 = 6;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"033","309","390"};
	p1 = 1;
	p2 = 12;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"0123","1023","1203","1230"};
	p1 = 2;
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"05789654","10347583","65085479","55602398","76590934","57939045","12345608","68647640"};
	p1 = 3;
	p2 = 40;
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
// In the Republic of Nlogonia there are N cities.
// For convenience, the cities are numbered 0 through N-1.
// For each two different cities i and j, there is a direct one-way road from i to j.
// You are given the lengths of those roads as a vector <string> dist with N elements, each with N characters.
// For each i and j, the character dist[i][j] represents the length of the road from i to j.
// 
// The lengths of roads are integers between 1 and 9, inclusive, and they are represented by digits '1' through '9'.
// That is, for distinct i and j, dist[i][j] will be between '1' and '9'.
// For each i, dist[i][i] will be '0'.
// Note that the roads from i to j and from j to i may have different lengths.
// 
// Every year on Algorithms Day (the most important holiday in Nlogonia) people travel between the cities.
// More precisely, for each pair of distinct cities i and j, one full bus of people travels from i to j.
// Each of those buses drives along a shortest path from its origin to its destination.
// If there are multiple shortest paths, the bus driver picks one of them arbitrarily.
// 
// The roads in Nlogonia are currently limited.
// You are given an int T with the following meaning: 
// each of the current roads is only safe if it is guaranteed that there will be strictly fewer than T buses driving along the road.
// In other words, a road is unsafe if it is possible that T or more buses will use it.
// The government wants to rebuild all unsafe roads before the next Algorithms Day.
// Return the sum of lengths of all unsafe roads.
// 
// DEFINITION
// Class:BuildingRoutes
// Method:build
// Parameters:vector <string>, int
// Returns:int
// Method signature:int build(vector <string> dist, int T)
// 
// 
// CONSTRAINTS
// -N will be between 2 and 50, inclusive.
// -dist will contain exactly N elements.
// -Each element of dist will contain exactly N characters.
// -For each i, dist[i][i] will be '0'.
// -For each pair of distinct i and j, dist[i][j] will be between '1' and '9', inclusive.
// -T will be between 1 and 2500, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"011",
//  "101",
//  "110"}
// 1
// 
// Returns: 6
// 
// As T=1, a road is unsafe as soon as it is possible that a bus will use it. 
// Each of the six roads in this test case belongs to some shortest path, hence each of them is unsafe
// 
// 1)
// {"033",
//  "309",
//  "390"}
// 1
// 
// Returns: 12
// 
// The roads 1->2 and 2->1 (the two roads of length 9) will not be used by any bus.
// Only the four remaining roads are unsafe in this case.
// 
// 2)
// {"0123",
//  "1023",
//  "1203",
//  "1230"}
// 2
// 
// Returns: 5
// 
// 
// 
// 3)
// {"05789654",
//  "10347583",
//  "65085479",
//  "55602398",
//  "76590934",
//  "57939045",
//  "12345608",
//  "68647640"}
// 3
// 
// Returns: 40
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
