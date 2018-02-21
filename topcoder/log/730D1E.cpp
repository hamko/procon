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

class StonesOnATree {
    public:
        vll w;
        ll n;
        vvll g;
        vll dp;
        ll dfs(ll v, ll p) {
            ll cnum = g[v].size();
            if (cnum == 0) return dp[v] = w[v];
            for (auto x : g[v]) if (x != p) {
                dfs(x, v);
            }
            if (cnum == 1) {
                return dp[v] = max(dp[g[v][0]], w[v]+w[g[v][0]]);
            } else if (cnum == 2) {
                ll ret = INF;
                chmin(ret, dp[g[v][0]]+w[g[v][1]]);
                chmin(ret, dp[g[v][1]]+w[g[v][0]]);
                chmax(ret, w[g[v][0]]+w[g[v][1]]+w[v]);
                chmax(ret, dp[g[v][0]]);
                chmax(ret, dp[g[v][1]]);
                return dp[v] = ret;
            } else {
                assert(0);
            }
            assert(0);
        }

        int minStones(vector <int> p, vector <int> w_) {
            w = conv(w_);
            n = w.size();
            g.resize(n);
            dp.resize(n);
            rep(i, n-1) {
                g[p[i]].pb(i+1);
            }
            dfs(0, -1);
            return *max_element(all(dp));
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
    StonesOnATree *obj;
    int answer;
    obj = new StonesOnATree();
    clock_t startTime = clock();
    answer = obj->minStones(p0, p1);
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
    p0 = {0,1,2,3};
    p1 = {1,2,2,4,4};
    p2 = 8;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {0,0};
    p1 = {1,2,3};
    p2 = 6;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {0};
	p1 = {100000,100000};
	p2 = 200000;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {0,0,1,1,2,2};
	p1 = {1,1,1,1,1,1,1};
	p2 = 4;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {0,0,1,2,3,4,4,2,1,3,6,7};
	p1 = {1,2,3,4,5,6,6,7,8,8,8,9,10};
	p2 = 22;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 4 -----
	disabled = false;
	p0 = {0,0,2,1,1};
	p1 = {5,8,2,9,10,7};
	p2 = 25;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
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
// You are given a rooted tree with n nodes.
// The nodes are labeled from 0 to n-1.
// Node 0 is the root.
// Each node of the tree has at most two children.
// 
// 
// 
// 
// You are given the description of the tree: the vector <int>s p and w.
// The vector <int> p has n-1 elements.
// For each valid i, node p[i] is the parent of node (i+1).
// You may assume that for each i we have p[i] ≤ i.
// The vector <int> w has n elements.
// For each valid i, w[i] is the weight of node i.
// 
// 
// 
// 
// 
// The vector <int> w has a special property: it is non-decreasing.
// That is, for each valid i we have w[i-1] ≤ w[i].
// 
// 
// 
// 
// 
// All nodes of the tree are currently empty.
// You are now going to play a game with the tree and an unlimited supply of stones.
// The game is played in turns.
// In each turn you can either remove a single stone from anywhere into a tree, or you can place a single stone onto a node of the tree.
// However, there is a restriction on placing the stones:
// you may only place a stone onto a node if all of its children currently have stones placed on them.
// (Note that this means that you can always place a stone onto any leaf of the tree.)
// 
// 
// 
// 
// 
// The weight of a given state of the game is equal to the sum of weights of nodes with stones.
// 
// 
// 
// 
// 
// You win the game by placing a stone onto the root of the tree.
// You want to win the game.
// If there are multiple ways to do so, you prefer a way for which the maximum weight of a state during the game is minimized.
// Compute and return this weight.
// In other words, compute and return the smallest W for which there is a way to win the game such that during the game the total weight of nodes with stones never exceeds W.
// 
// 
// DEFINITION
// Class:StonesOnATree
// Method:minStones
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int minStones(vector <int> p, vector <int> w)
// 
// 
// CONSTRAINTS
// -p will have between 1 and 999 elements, inclusive. (Thus, the number of nodes is between 2 and 1,000, inclusive.)
// -The i-th element of p will be between 0 and i, inclusive.
// -In the given tree each node will have at most two children. In other words, each value will appear in p at most twice.
// -w will have exactly len(p)+1 elements.
// -Each element of w will be 1 and 10^5, inclusive.
// -Elements of w will be non-decreasing.
// 
// 
// EXAMPLES
// 
// 0)
// {0,1,2,3}
// {1,2,2,4,4}
// 
// Returns: 8
// 
// There are five nodes in a line. 
// Here, one optimal solution is as follows:
// 
// 
//  Place stone on node 4 (weight = 4). 
//  Place stone on node 3 (weight = 8). 
//  Remove stone from node 4 (weight = 4). 
//  Place stone on node 2 (weight = 6). 
//  Place stone on node 1 (weight = 8). 
//  Remove stone from node 2 (weight = 6). 
//  Place stone on node 0 (weight = 7). 
// 
// 
// The maximum weight over all states is 8. It can be shown there is no other sequence of moves that has a smaller maximum weight.
// 
// 1)
// {0,0}
// {1,2,3}
// 
// Returns: 6
// 
// In order to be able to place a stone onto node 0 we have to place stones onto both of its children. Thus, at the end of the game each of these three nodes will have a stone.
// 
// 
// 2)
// {0}
// {100000,100000}
// 
// Returns: 200000
// 
// 
// 
// 3)
// {0,0,1,1,2,2}
// {1,1,1,1,1,1,1}
// 
// Returns: 4
// 
// 
// 
// 4)
// {0,0,1,2,3,4,4,2,1,3,6,7}
// {1,2,3,4,5,6,6,7,8,8,8,9,10}
// 
// Returns: 22
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
