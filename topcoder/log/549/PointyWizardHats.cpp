#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

/***********************/
// 共通部分
/***********************/
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

typedef long long Weight;

struct Edge {
    ll src, dst;
    Weight weight;
    Edge(ll src, ll dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void addDirected(Graph& g, ll src, ll dst, Weight weight) { assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0); g[src].push_back(Edge(src, dst, weight)); }
void addUndirected(Graph& g, ll src, ll dst, Weight weight) { assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0); g[src].push_back(Edge(src, dst, weight)); g[dst].push_back(Edge(dst, src, weight)); }
void addDirected(Graph& g, ll src, ll dst) { addDirected(g, src, dst, 1); }
void addUndirected(Graph& g, ll src, ll dst) { addUndirected(g, src, dst, 1); }
void printGraph(Graph& g) {
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) 
            cout << "(" << i << ", " << g[i][j].dst << "), ";
        cout << endl;
    }
}


// 二部マッチング
// O(V (V + E))
// 入力：
// g : 二部グラフ．0 ... L-1 が左側頂点，L ... g.size()-1 が右側頂点に対応する．
// L : 二部グラフの左側の頂点の数．
// 出力：matching : マッチングに用いられる辺集合．
bool augment(const Graph& g, int u,
        vector<int>& matchTo, vector<bool>& visited) {
    if (u < 0) return true;
    FOR(e, g[u]) if (!visited[e->dst]) {
        visited[e->dst] = true;
        if (augment(g, matchTo[e->dst], matchTo, visited)) {
            matchTo[e->src] = e->dst;
            matchTo[e->dst] = e->src;
            return true;
        }
    }
    return false;
}
int bipartiteMatching(const Graph& g, int L, Edges& matching) {
    const int n = g.size();
    vector<int> matchTo(n, -1);
    int match = 0;
    rep(u, L) {
        vector<bool> visited(n);
        if (augment(g, u, matchTo, visited)) ++match;
    }
    rep(u, L) if (matchTo[u] >= 0) // make explicit matching
        matching.push_back( Edge(u, matchTo[u], 1) );
    return match;
}
// 二部マッチングの入力グラフを特性関数から構築
// bool f(i, j) : 左のi in [0, L)から右のj in [0, R)との辺があれば1, なければ0
template<class Function>
void constructBiparitate(Graph& g, int L, int R, Function f) {
    g = Graph(L + R);
    rep(l, L) rep(r, R) if (f(l, r)) addDirected(g, l, L + r);
}

class PointyWizardHats {
    public:
        int getNumHats(vector <int> th, vector <int> tr, vector <int> bh, vector <int> br) {
            ll L = th.size();
            ll R = bh.size();
            auto f = [&](int i, int j) { 
                return (tr[i] < br[j] && th[i] * br[j] > tr[i] * bh[j]); 
            };
            Graph g;
            constructBiparitate(g, L, R, f);
            Edges matching;
            return bipartiteMatching(g, L, matching);
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
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
	PointyWizardHats *obj;
	int answer;
	obj = new PointyWizardHats();
	clock_t startTime = clock();
	answer = obj->getNumHats(p0, p1, p2, p3);
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {30};
	p1 = {3};
	p2 = {3};
	p3 = {30};
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {4,4};
	p1 = {4,3};
	p2 = {5,12};
	p3 = {5,4};
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {3};
	p1 = {3};
	p2 = {1,1};
	p3 = {2,4};
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {10,10};
	p1 = {2,5};
	p2 = {2,9};
	p3 = {3,6};
	p4 = 2;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {3,4,5};
	p1 = {5,4,3};
	p2 = {3,4,5};
	p3 = {3,8,5};
	p4 = 2;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {1,2,3,4,5};
	p1 = {2,3,4,5,6};
	p2 = {2,3,4,5,6};
	p3 = {1,2,3,4,5};
	p4 = 0;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = {123,214,232,323,342,343};
	p1 = {123,123,232,123,323,434};
	p2 = {545,322,123,545,777,999};
	p3 = {323,443,123,656,767,888};
	p4 = 5;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = {999,999,999,10000,10000,10000};
	p1 = {10000,10000,10000,1,2,3};
	p2 = {2324,2323,234,5454,323,232};
	p3 = {1,2,3222,434,5454,23};
	p4 = 3;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, p3, true, p4) ) && all_right;
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
// The Order of All Things Pointy and Magical has commissioned the creation of some new wizard hats. A wizard hat is created by taking two cones: a decorative top cone, and a warm and fluffy bottom cone. To assemble the hat, both cones are first placed onto a table, so that their bases are horizontal and their apexes point upwards. The top cone is then lifted and placed onto the bottom cone. The base of the top cone has to remain horizontal, and the apex of the top cone must be strictly above the apex of the bottom cone. 
// 
// Not every pair of cones can be used to create a wizard hat. A wizard hat is only produced if the following two criteria are both met:
// 
// The apex of the top cone must be strictly above the apex of the bottom cone. I.e., when the top cone is placed on top of the bottom cone and released, their apexes must not touch.
// Some part of the bottom cone must remain visible to form the brim of the hat. (Otherwise, the hat would look like a simple cone, not like a wizard hat!)
// 
// 
// You have several top cones and several bottom cones of various sizes. Each cone can be described by its height (the distance between the apex and the base) and by the radius of its base. The top cones you have are described by topHeight and topRadius: for each valid i, you have one top cone with height topHeight[i] and radius topRadius[i]. The bottom cones you have are described by bottomHeight and bottomRadius in the same way. 
// 
// Your task is to determine the maximum number of wizard hats you can make using each of the available top and bottom cones at most once.
// 
// DEFINITION
// Class:PointyWizardHats
// Method:getNumHats
// Parameters:vector <int>, vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius)
// 
// 
// CONSTRAINTS
// -topHeight and topRadius will contain the same number of elements.
// -bottomHeight and bottomRadius will contain the same number of elements.
// -topHeight will contain between 1 and 50 elements, inclusive.
// -topRadius will contain between 1 and 50 elements, inclusive.
// -bottomHeight will contain between 1 and 50 elements, inclusive.
// -bottomRadius will contain between 1 and 50 elements, inclusive.
// -Each element of topHeight, topRadius, bottomHeight, and bottomRadius will be between 1 and 10,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {30}
// {3}
// {3}
// {30}
// 
// Returns: 1
// 
// The top and bottom cone can be used together to make a wizard hat.
// 
// 1)
// {4,4}
// {4,3}
// {5,12}
// {5,4}
// 
// Returns: 1
// 
// The only way to produce a wizard hat is to use the top cone 1 (height 4, radius 3) and the bottom cone 0 (height 5, radius 5).
// 
// 2)
// {3}
// {3}
// {1,1}
// {2,4}
// 
// Returns: 1
// 
// 
// 
// 3)
// {10,10}
// {2,5}
// {2,9}
// {3,6}
// 
// Returns: 2
// 
// 
// 
// 4)
// {3,4,5}
// {5,4,3}
// {3,4,5}
// {3,8,5}
// 
// Returns: 2
// 
// 
// 
// 5)
// {1,2,3,4,5}
// {2,3,4,5,6}
// {2,3,4,5,6}
// {1,2,3,4,5}
// 
// Returns: 0
// 
// 
// 
// 6)
// {123,214,232,323,342,343}
// {123,123,232,123,323,434}
// {545,322,123,545,777,999}
// {323,443,123,656,767,888}
// 
// Returns: 5
// 
// 
// 
// 7)
// {999,999,999,10000,10000,10000}
// {10000,10000,10000,1,2,3}
// {2324,2323,234,5454,323,232}
// {1,2,3222,434,5454,23}
// 
// Returns: 3
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
