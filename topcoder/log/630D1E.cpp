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

class Egalitarianism3 {
    public:
        int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
            if (n == 1) return 1;

            vvll d(n, vll(n, INF));
            rep(i, n) d[i][i] = 0;
            rep(i, a.size()) d[a[i]-1][b[i]-1] = d[b[i]-1][a[i]-1] = len[i];
            rep(_, n) rep(l, n) rep(r, n) chmin(d[l][r], d[l][_] + d[_][r]);

            auto f = [&](set<ll>& s){ 
                ll dist = -1;
                for (auto x : s) for (auto y : s) if (x != y) {
                    if (dist != -1 && dist != d[x][y]) 
                        return false;
                    dist = d[x][y];
                }
                return true;
            };

            ll ret = 2;
            rep(i, n) rep(j, n) if (i > j) {
                // sは(i, j)から始めた、全ての距離が同じとなる集合
                set<ll> s; s.insert(i); s.insert(j);
                rep(_, 2500) {
                    ll k = _ % n;
                    if (s.count(k)) continue;
                    s.insert(k);
                    if (!f(s))
                        s.erase(k);
                }
                chmax(ret, s.size());
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	Egalitarianism3 *obj;
	int answer;
	obj = new Egalitarianism3();
	clock_t startTime = clock();
	answer = obj->maxCities(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 4;
	p1 = {1,1,1};
	p2 = {2,3,4};
	p3 = {1,1,1};
	p4 = 3;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 6;
	p1 = {1,2,3,2,3};
	p2 = {2,3,4,5,6};
	p3 = {2,1,3,2,3};
	p4 = 3;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 10;
	p1 = {1,1,1,1,1,1,1,1,1};
	p2 = {2,3,4,5,6,7,8,9,10};
	p3 = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
	p4 = 9;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 1;
	p1 = {};
	p2 = {};
	p3 = {};
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
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
// In Treeland there are n cities, numbered 1 through n.
// The cities are linked by n-1 bidirectional roads.
// Each road connects a pair of cities.
// The roads are built in such a way that each city is reachable from each other city by roads.
// (In other words, the topology of the road network is a tree.)
// 
// 
// You are given the int n and three vector <int>s that describe the road network: a, b, and len.
// For each i between 0 and n-2, inclusive, there is a road of length len[i] that connects the cities a[i] and b[i].
// 
// 
// The distance between two cities is the sum of lengths of roads on the sequence of roads that connects them. (Note that this sequence of roads is always unique.)
// 
// 
// You want to select k cities in such a way that all pairwise distances between the selected cities are the same.
// In other words, there must be a distance d such that the distance between every two selected cities is d.
// Return the largest possible value of k for which this is possible.
// 
// 
// DEFINITION
// Class:Egalitarianism3
// Method:maxCities
// Parameters:int, vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 50, inclusive.
// -a will contain exactly n-1 elements.
// -b will contain exactly n-1 elements.
// -len will contain exactly n-1 elements.
// -Each element in a will be between 1 and n, inclusive.
// -Each element in b will be between 1 and n, inclusive.
// -Each element in len will be between 1 and 1,000, inclusive.
// -The graph described by a and b will be a tree.
// 
// 
// EXAMPLES
// 
// 0)
// 4
// {1,1,1}
// {2,3,4}
// {1,1,1}
// 
// Returns: 3
// 
// There are 4 cities and 3 roads, each of length 1.
// The roads connect the following pairs of cities: (1,2), (1,3), and (1,4).
// The optimal answer is k=3.
// We can select three cities in the required way: we select the cities {2, 3, 4}.
// The distance between any two of these cities is 2.
// 
// 1)
// 6
// {1,2,3,2,3}
// {2,3,4,5,6}
// {2,1,3,2,3}
// 
// Returns: 3
// 
// Again, the largest possible k is 3.
// There are two ways to select three equidistant cities: {1, 4, 6} and {4, 5, 6}.
// (In both cases the common distance is 6.)
// 
// 2)
// 10
// {1,1,1,1,1,1,1,1,1}
// {2,3,4,5,6,7,8,9,10}
// {1000,1000,1000,1000,1000,1000,1000,1000,1000}
// 
// Returns: 9
// 
// 
// 
// 3)
// 1
// {}
// {}
// {}
// 
// Returns: 1
// 
// Note that n can be 1.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
