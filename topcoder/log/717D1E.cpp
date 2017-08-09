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
static const int inf = 1e9;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

const ll MAX = 210;
struct edge { int to, cap, rev; };
vector<edge> G[MAX];
bool used[MAX];

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, int(G[to].size())});
    G[to].push_back((edge){from, 0, int(G[from].size()-1)});
}

int dfs(int v, int t, int f) {
    if(v == t) return f;
    used[v] = 1;
    for(int i = 0 ; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(used[e.to] or e.cap <= 0) continue;
        int d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
        }
    }
    return 0;
}

int ford_fulkerson(int s, int t) {
    int flow = 0, f;
    while(1){
        memset(used, 0, sizeof(used));
        f = dfs(s, t, inf);
        if(f == 0) return flow;
        flow += f;
    }
}
class ScoresSequence {
    public:
        int count(vector <int> a) {
            ll n = a.size();
            rep(i, MAX) G[i].clear(), used[i] = 0;

            sort(all(a)); reverse(all(a));
            ll src = 2*n, dst = 2*n+1;
            rep(i, n) rep(j, n) if (i != j) {
                add_edge(i, n+j, 1);
            }
            rep(i, n) 
                add_edge(src, i, a[i]), add_edge(n+i, dst, n-a[i]-1);

            ford_fulkerson(src, dst);

            vvll g(n, vll(n, INF));
            rep(i, n) g[i][i] = 0;
            
            // i->x.toの辺
            // n<=i<2*nが先、0<=x.to<nが前
            // x.capがx.toからi-nの最大フロー
            rep(i, MAX) for (auto x : G[i]) if (x.cap && n <= i && i < 2*n && 0 <= x.to && x.to < n) 
                g[x.to][i-n] = 1;

            rep(k, n) rep(i, n) rep(j, n) chmin(g[i][j], g[i][k]+g[k][j]);

            ll ret = 0;
            rep(i, n) rep(j, n) 
                ret += g[i][j] != INF;

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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    ScoresSequence *obj;
    int answer;
    obj = new ScoresSequence();
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
    int p1;

    // ----- test 0 -----
    disabled = false;
    p0 = {2,0,1};
    p1 = 6;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {1,0,2};
    p1 = 6;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = {1,1,1};
    p1 = 9;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = {0,2,8,4,3,9,1,5,7,6};
    p1 = 55;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3};
    p1 = 1422;
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
// A tournament is a directed graph on n vertices that can be obtained by taking an undirected complete graph on n vertices and assigning a direction to each edge.
// The outdegree of a vertex is the number of directed edges that start at that vertex.
// The score of a tournament is the list of the outdegrees of its vertices, in no particular order.
// 
// 
// 
// Alice used to have a tournament T but she lost it.
// She only remembers its score.
// You are given the score of T in the vector <int> s.
// 
// 
// 
// Determine and return the number of pairs of vertices (u,v) such that in the tournament T the vertex v was reachable from the vertex u.
// Note that each vertex is reachable from itself.
// 
// 
// You may assume that the answer can always be uniquely determined.
// 
// 
// DEFINITION
// Class:ScoresSequence
// Method:count
// Parameters:vector <int>
// Returns:int
// Method signature:int count(vector <int> s)
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 100 elements, inclusive.
// -s will be a valid score of some tournament.
// 
// 
// EXAMPLES
// 
// 0)
// {2, 0, 1}
// 
// Returns: 6
// 
// 
// There are three vertices. Let's call them A, B, and C, in the order in which they are mentioned in the score.
// As the outdegree of A is 2, the tournament must contain the edges A -> B and A -> C.
// As the outdegree of B is 0, the tournament must also contain the edge C -> B.
// 
// 
// 
// There are six pairs of vertices (u,v) such that there is a path from u to v.
// These are the pairs (A,A), (B,B), (C,C), (A,B), (A,C), and (B,C).
// 
// 
// 1)
// {1, 0, 2}
// 
// Returns: 6
// 
// 
// 
// 2)
// {1, 1, 1}
// 
// Returns: 9
// 
// This tournament must clearly be a cycle.
// Hence, each vertex is reachable from each vertex.
// 
// 
// 3)
// {0, 2, 8, 4, 3, 9, 1, 5, 7, 6}
// 
// Returns: 55
// 
// 
// 
// 4)
// {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3}
// 
// Returns: 1422
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
