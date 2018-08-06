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

class Sunnygraphs {
    public:
        vvll g;
        void dfs(ll u, vll& vis) {
            if (vis[u]) return;
            vis[u] = 1;
            for (auto next_u : g[u]) {
                dfs(next_u, vis);
            }
        }
        long long count(vector <int> v) {
            ll n = v.size();
            g.resize(n);
            rep(i, n) {
                g[i].pb(v[i]);
            }

            vll from0(n), from1(n);
            dfs(0, from0);
            dfs(1, from1);
            cout << from0 << endl;
            cout << from1 << endl;
            ll a = 0, b = 0, ab = 0, c = 0;
            rep(i, n) {
                if (from0[i] && from1[i]) {
                    ab++;
                } else if (from0[i] && !from1[i]) {
                    a++;
                } else if (!from0[i] && from1[i]) {
                    b++;
                } else if (!from0[i] && !from1[i]) {
                    c++;
                }
            }
            cout << mt(a, b, c, ab) << endl;
            if (!ab) {
                ll ret = ((1ll << a) - 1ll) * ((1ll << b) - 1ll);
                return ret << c;
            } else {
                ll ret = 0;
                ret += ((1ll << a) - 1) * ((1ll << b) - 1) * ((1ll << ab) - 0);
                ret += 1ll              * ((1ll << b) - 1) * ((1ll << ab) - 1);
                ret += ((1ll << a) - 1) * 1ll              * ((1ll << ab) - 1);
                ret += 1ll              * 1ll              * ((1ll << ab) - 0);
                return ret << c;
            }
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	Sunnygraphs *obj;
	long long answer;
	obj = new Sunnygraphs();
	clock_t startTime = clock();
	answer = obj->count(p0);
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
	
	vector <int> p0;
	long long p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,0};
	p1 = 4ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {2,2,0};
	p1 = 7ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {2,3,0,1};
	p1 = 9ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {2,2,3,4,3};
	p1 = 30ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
	p1 = 2198754820096ll;
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
// Hero has just constructed a very specific graph.
// He started with n isolated vertices, labeled 0 through n-1.
// For each vertex i Hero then chose a vertex a[i] (other than i) and he added an edge that connected i and a[i].
// This way he created a graph with n vertices and n edges.
// Note that if a[x]=y and a[y]=x, the vertices x and y were connected by two different edges.
// 
// Hero now wants to perform the following procedure:
// 
// Add a new isolated vertex number n.
// Choose a subset M of the original vertices.
// For each x in M, erase an edge between vertices x and a[x].
// For each x in M, add a new edge between vertices x and n.
// 
// 
// Hero's goal is to create a final graph in which the vertices 0 and 1 are in the same connected component.
// (I.e., there is a path from one of them to the other.)
// 
// In step 2 of the above procedure Hero has 2^n possible subsets to choose from.
// A choice of M is good if it produces a graph with the desired property.
// Count how many of the 2^n possibilities are good choices.
// Return that count as a long long.
// 
// DEFINITION
// Class:Sunnygraphs
// Method:count
// Parameters:vector <int>
// Returns:long long
// Method signature:long long count(vector <int> a)
// 
// 
// CONSTRAINTS
// -a will contain n elements.
// -n will be between 2 and 50, inclusive.
// -Each element in a will be between 0 and n - 1, inclusive.
// -For each i between 0 and n - 1 holds a[i] != i.
// 
// 
// EXAMPLES
// 
// 0)
// {1,0}
// 
// Returns: 4
// 
// The original graph contained the vertices 0 and 1.
// This pair of vertices was connected by two edges.
// 
// Next, Hero added a new vertex 2.
// Then he had to choose one of four possible subsets M:
// 
// If he chose M = {}, the resulting graph contained the edges 0-1 and 0-1. The vertices 0 and 1 were connected.
// If he chose M = {0}, the resulting graph contained the edges 0-1 and 0-2. The vertices 0 and 1 were connected.
// If he chose M = {1}, the resulting graph contained the edges 0-1 and 1-2. The vertices 0 and 1 were connected.
// Finally, if he chose M = {0, 1}, the resulting graph contained the edges 0-2 and 1-2. And again, the vertices 0 and 1 were connected: there is a path 0-1-2.
// 
// 
// As all four choices of M are good, the correct answer is 4.
// 
// 1)
// {2,2,0}
// 
// Returns: 7
// 
// Here, the original graph contained the edges 0-2, 0-2, and 1-2.
// For this graph M = {1} is not a good choice.
// This choice produces a graph with edges 0-2, 0-2, and 1-3.
// In this graph the vertices 0 and 1 are not in the same connected component.
// The other seven possible choices of M are all good.
// 
// 2)
// {2,3,0,1}
// 
// Returns: 9
// 
// 
// 
// 3)
// {2,2,3,4,3}
// 
// Returns: 30
// 
// 
// 
// 4)
// {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8}
// 
// Returns: 2198754820096
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
