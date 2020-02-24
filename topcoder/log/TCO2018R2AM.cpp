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

static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 
/***********************/
// 共通部分
/***********************/
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long Weight;
const Weight INF = 1e18;
const Weight EPS = 0; // 浮動小数点なら1e-14

struct Edge {
    ll src, dst;
    Weight weight; // 最小費用流ではcostの役割
    ll cap;
    ll rev; // 残余グラフの対応用
    bool rev_flag = false; // revなら1
    Edge(int src = 0, int dst = 0, Weight weight = 0, Weight cap = 1): 
        src(src), dst(dst), weight(weight), cap(cap){ }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

// 最大流と最小費用流の有向
// 無向は自分でひっくり返して追加して下さい
void addDirected(Graph& g, ll src, ll dst, Weight weight = 0, ll cap = 0) {
    assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0);
    g[src].push_back(Edge(src, dst, weight, cap)); 
}
vector<string> names;
unordered_map<string, int> name_server;
void clearNameServer(void) {
    names.clear();
    name_server.clear();
}
int constructNameServer(vector<string>& names_) {
    names = names_;
    for (int i = 0; i < names.size(); i++) {
        name_server[names[i]] = i;
    }
    return name_server.size();
}
void addDirected(Graph& g, string src, string dst, Weight weight = 0, ll cap = 0) {
    if (!name_server.count(src)) { cerr << "No such node : " << src << endl; exit(1); }
    if (!name_server.count(dst)) { cerr << "No such node : " << dst << endl; exit(1); }
    addDirected(g, name_server[src], name_server[dst], weight, cap);
}

void addUndirected(Graph& g, ll src, ll dst, Weight weight = 0, ll cap = 0) { 
    addDirected(g, src, dst, weight, cap);
    addDirected(g, dst, src, weight, cap);
} 

void transformFromMatrixToGraph(Graph& g, Matrix& m) {
    ll n = m.size();
    g.resize(n);
    rep(i, n) rep(j, n) if (m[i][j] != INF) {
        addDirected(g, i, j, m[i][j]);
    }
}

void printGraph(Graph& g) {
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) 
            cout << "(" << i << ", " << g[i][j].dst << "), ";
        cout << endl;
    }
}
void printGraphCap(Graph& g) {
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) 
            cout << "(" << i << ", " << g[i][j].dst << " : " << g[i][j].cap << ", " << (g[i][j].rev_flag ? "rev" : "for") << "), ";
        cout << endl;
    }
}

// mode
// 0 : デフォルト。辺だけ表示
// 1 : 重みweightだけ表示
// 2 : フロー用。weight, capを表示。
//
// directed
// 有向グラフなら1、そうでないなら0
// 
void vizGraph(Graph& g, int mode = 0, int directed = 1, string filename = "out.png") {
   
    ofstream ofs("./out.dot");
    ofs << (directed ? "di" : "") << "graph graph_name {" << endl;
    string arrow = (directed ? " -> " : " -- ");

    set<pair<int, int>> used;
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) {
            // 多重辺はないと前提
            if (used.count(pair<int, int>(g[i][j].src, g[i][j].dst))) continue;
            used.insert(pair<int, int>(g[i][j].src, g[i][j].dst));
            if (directed == 0) used.insert(pair<int, int>(g[i][j].dst, g[i][j].src));

            // 頂点に名前がついていれば名前を優先して出す
            if (name_server.size()) {
                ofs << "    " << names[i] << arrow << names[g[i][j].dst]; 
            } else {
                ofs << "    " << i << arrow << g[i][j].dst; 
            }

            // 重みや容量があるならそれも出力
            if (mode == 1) {
                ofs << " [ label = \"" << g[i][j].weight << "\"];"; 
            } else if (mode == 2) {
                ofs << " [ label = \"" << g[i][j].weight << "/" << (g[i][j].cap  == INF ? "inf" : to_string(g[i][j].cap)) << "\"];"; 
            }
            ofs << endl;
        }
    }
    ofs << "}" << endl;
    ofs.close();
    system(((string)"dot -T png out.dot >" + filename).c_str());
}

// 強連結分解
// O(V+E)
// const Graph& g               有向グラフ
// vector< vector<ll> >& scc   グラフの強連結成分
void visitStronglyConnectedComponents(const Graph &g, ll v, vector< vector<ll> >& scc,
        stack<ll> &S, vector<bool> &inS,
        vector<ll> &low, vector<ll> &num, ll& time) {
    low[v] = num[v] = ++time;
    S.push(v); inS[v] = true;
    FOR(e, g[v]) {
        ll w = e->dst;
        if (num[w] == 0) {
            visitStronglyConnectedComponents(g, w, scc, S, inS, low, num, time);
            low[v] = min(low[v], low[w]);
        } else if (inS[w])
            low[v] = min(low[v], num[w]);
    }
    if (low[v] == num[v]) {
        scc.push_back(vector<ll>());
        while (1) {
            ll w = S.top(); S.pop(); inS[w] = false;
            scc.back().push_back(w);
            if (v == w) break;
        }
    }
}
void stronglyConnectedComponents(const Graph& g, vector< vector<ll> >& scc) {
    const ll n = g.size();
    vector<ll> num(n), low(n);
    stack<ll> S;
    vector<bool> inS(n);
    ll time = 0;
    rep(u, n) if (num[u] == 0)
        visitStronglyConnectedComponents(g, u, scc, S, inS, low, num, time);
}



class MakingRegularGraph {
    public:
        vector <int> addEdges(int n_, vector <int> x_, vector <int> y_) {
            ll n = n_;
            vll x = conv(x_);
            vll y = conv(y_);
            ll m = x.size();

            if (n <= 2) {
                return {-1};
            }
            {
                Graph g = Graph(n);
                rep(i, m) {
                    addDirected(g, x[i], y[i]);
                    addDirected(g, y[i], x[i]);
                }
                vector<vector<ll>> scc;
                stronglyConnectedComponents(g, scc);
                rep(i, scc.size()) {
                    ll edges = 0;
//                    rep(j, scc[i].size()) cout << scc[i][j] << " ";
//                    cout << endl;
                    rep(j, scc[i].size()) edges += g[scc[i][j]].size();
                    if (edges == scc[i].size() * 2) {
                        return {-1};
                    }
                }
            }

            vector<int> ret;
            {
                vvll g(n);
                rep(i, m) {
                    g[x[i]].pb(y[i]);
                    g[y[i]].pb(x[i]);
                }
                vector<ll> color(n, -1);
                rep(i, n) if (color[i] == -1) {
                    stack<ll> s;
                    s.push(i);
                    color[i] = i;
                    while (s.size()) {
                        ll x = s.top(); s.pop();
                        for (auto y : g[x]) if (color[y] == -1) {
                            s.push(y);
                            color[y] = i;
                        }
                    }
                }
//                cout << color << endl;
                priority_queue<P, vector<P>, greater<P>> q;
                rep(c, n) {
                    vll deg1;
                    rep(i, n) if (color[i] == c && g[i].size() <= 1) {
                        deg1.pb(i);
                    }
                    if (deg1.size() == 1) {
                        q.push(P(deg1[0], deg1[0]));
                    } else if (deg1.size() == 2) {
                        if (deg1[0] > deg1[1]) swap(deg1[0], deg1[1]);
                        q.push(P(deg1[0], deg1[1]));
                    }
//                    cout << deg1 << endl;
                }
//                auto qq = q; while (qq.size()) { auto x = qq.top(); cout << x << " "; qq.pop(); } cout << endl;
                while (q.size() > 1) {
                    P l1 = q.top(); q.pop();
                    P l2 = q.top(); q.pop();

                    ret.pb(l1.fi);
                    ret.pb(l2.fi);
                    P newl = P(l1.se, l2.se);
                    if (newl.fi > newl.se) swap(newl.fi, newl.se);
                    q.push(newl);
                }
                if (q.size() == 1) {
                    P newl = q.top(); q.pop();
                    if (newl.fi > newl.se) swap(newl.fi, newl.se);
                    ret.pb(newl.fi);
                    ret.pb(newl.se);
                }
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, vector <int> p3) {
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
	cout << "}";
	cout << "]" << endl;
	MakingRegularGraph *obj;
	vector <int> answer;
	obj = new MakingRegularGraph();
	clock_t startTime = clock();
	answer = obj->addEdges(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p3[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
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
		// ----- test 0 -----
	disabled = false;
	p0 = 1;
	p1 = {};
	p2 = {};
	p3 = {-1};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
			// ----- test 0 -----
	disabled = false;
	p0 = 2;
	p1 = {};
	p2 = {};
	p3 = {-1};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
				// ----- test 0 -----
	disabled = false;
	p0 = 2;
	p1 = {0};
	p2 = {1};
	p3 = {-1};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 0 -----
	disabled = false;
	p0 = 6;
	p1 = {0,2};
	p2 = {2,3};
	p3 = {0,1,1,4,3,5,4,5};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 4;
	p1 = {1,2,1};
	p2 = {2,3,3};
	p3 = {-1};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 3;
	p1 = {};
	p2 = {};
	p3 = {0,1,0,2,1,2};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 5;
	p1 = {0};
	p2 = {4};
	p3 = {0,1,1,2,2,3,3,4};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 5;
	p1 = {2};
	p2 = {3};
	p3 = {0,1,0,2,1,4,3,4};
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
// 
// A simple graph is an undirected graph in which each edge connects two different vertices and each pair of vertices is connected by at most one edge.
// In other words, there are no self-loops and no multiple edges.
// 
// 
// 
// 
// A 2-regular graph is a simple graph such that the degree of each vertex is 2.
// 
// 
// 
// 
// You are given the int n and two vector <int>s x and y.
// These variables describe a simple graph G on n vertices, labeled 0 through n-1.
// For each valid i, the graph G contains an edge that connects the vertices x[i] and y[i].
// It is guaranteed that each vertex in G has degree 2 or less.
// 
// 
// 
// 
// You want to change G into a 2-regular graph by adding some edges.
// Determine whether this can be done, and if yes, find the lexicographically smallest way of doing so.
// A more precise definition of the task follows.
// 
// 
// 
// 
// An encoding of a set of k edges is any vector <int> E of length 2k such that the set of edges is equal to the set { (E[0], E[1]), (E[2], E[3]), ... }.
// For example, suppose you have the edges (1,7) and (2,5).
// Then {1,7,5,2} and {2,5,1,7} are two of the valid encodings.
// On the other hand, {1,2,5,7} is not a valid encoding.
// 
// 
// 
// 
// If changing G into a 2-regular graph is impossible, return the vector <int> {-1}, i.e., an array that contains only one integer, -1.
// Otherwise, find and return the lexicographically smallest encoding of a set of edges that should be added to G in order to make it 2-regular.
// 
// 
// DEFINITION
// Class:MakingRegularGraph
// Method:addEdges
// Parameters:int, vector <int>, vector <int>
// Returns:vector <int>
// Method signature:vector <int> addEdges(int n, vector <int> x, vector <int> y)
// 
// 
// NOTES
// -Given two different vector <int>s S and T with the same number of elements, the lexicographically smaller one is the one that has a smaller element at the first index at which they differ.
// 
// 
// CONSTRAINTS
// -n will be between 1 and 1,000, inclusive.
// -x will contain between 0 and n-1 elements, inclusive.
// -y will contain the same number of elements as x.
// -Each element of x will be between 0 and n-2, inclusive.
// -Each element of y will be between 1 and n-1, inclusive.
// -x[i] < y[i] will hold for all i (i.e., no self-loops).
// -In a graph described by n, x, and y, every vertex will have degree 2 or less (For every integer v between 0 and n-1, v appears at most twice in x and y combined).
// -In a graph described by n, x, and y, there will be at most one edge between a pair of vertices (two equalities (x[i] = x[j] and y[i] = y[j]) will hold only when i = j).
// 
// 
// EXAMPLES
// 
// 0)
// 6
// {0,2}
// {2,3}
// 
// Returns: {0, 1, 1, 4, 3, 5, 4, 5 }
// 
// There are many ways to turn this G into a 2-regular graph. For example, you may:
// 
// add the edges (3, 4), (4, 5), (5, 1), (1, 0) to obtain one large cycle of length 6
// add the edges (3, 5), (5, 4), (4, 1), (1, 0) to obtain another cycle of length 6
// add the edges (0, 3), (1, 4), (4, 5), (1, 5) to obtain two cycles of length 3 each
// ...
// 
// 
// Each of these options has multiple encodings.
// The return value shown above is the lexicographically smallest out of all encodings of all options.
// It corresponds to the second set of edges listed above.
// 
// 1)
// 4
// {1,2,1}
// {2,3,3}
// 
// Returns: {-1 }
// 
// The given graph contains a cycle of length 3 and an isolated vertex.
// Unfortunately, we cannot turn this into a 2-reguglar graph.
// 
// 
// 2)
// 3
// {}
// {}
// 
// Returns: {0, 1, 0, 2, 1, 2 }
// 
// x and y can be empty, meaning there are no edges present.
// In this example, there is a unique set of edges we can add in order to create a 2-regular graph: (0, 1), (0, 2), and (1, 2).
// However, there exist many different ways to describe these three edges. 
// For instance, both {0, 1, 2, 0, 2, 1} and {0, 1, 0, 2, 1, 2} describe the same set of edges.
// Recall that you must return the one that comes lexicographically first. 
// 
// 
// 3)
// 5
// {0}
// {4}
// 
// Returns: {0, 1, 1, 2, 2, 3, 3, 4 }
// 
// 
// 
// 4)
// 5
// {2}
// {3}
// 
// Returns: {0, 1, 0, 2, 1, 4, 3, 4 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
