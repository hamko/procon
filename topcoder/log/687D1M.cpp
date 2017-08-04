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

int mat[51][51];
int ma[51][51];

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ, O(A^-1)
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1, O(A^-1)
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る, O(A^-1)
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す, O(A^-1)
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す, O(n)
    int getSetNum(void) {
        unordered_map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
    // 頂点vと連結な集合を返す, O(n)
    vector<int> getContainingSet(int v) {
        vector<int> ret;
        for (int i = 0; i < data.size(); i++) 
            if (root(i) == root(v))
                ret.push_back(i);
        return ret;
    }

    // 集合ごとに全部の要素を出力, O(n)
    vector<vector<int>> getUnionList(void) {
        map<int, vector<int>> c;
        for (int i = 0; i < data.size(); i++) 
            c[root(i)].pb(i);
        vector<vector<int>> v;
        for (auto x : c) 
            v.push_back(x.second);
        return v;
    }
};
ostream &operator<<(ostream &o, struct UnionFind v) {  v.getUnionList(); int i = 0; for (auto x : v.getUnionList()) { o << i << "\t"; for (auto y : x) o << y << " "; o << endl; i++;} return o; }


class AllGraphCuts {
    public:
        vector <int> findGraph(vector <int> X) {
            ll n = sqrt(X.size()) + 1e-8;
            UnionFind uf(n);
            rep(i, n) {
                if (X[i*n+i] != 0) return {-1};
            }
            rep(i, n) rep(j, n) {
                if (X[i*n+j] != X[j*n+i]) return {-1};
            }

            vvll g(100010);
            rep(i, X.size()) {
                g[X[i]].pb(i);
            }
            vector<int> ret;
            rep(w_rev, g.size()) {
                ll w = g.size() - 1 - w_rev;
                // uf: w超の頂点集合
                // 重みwの頂点がuf内部にあると、uf内部の頂点を介してw+1以上のフローが流せるのでminになり得ない
                for (auto x : g[w]) {
                    if (x/n != x%n && uf.find(x/n, x%n)) {
                        return {-1};
                    }
                }
                for (auto x : g[w]) {
                    if (!uf.find(x/n, x%n)) {
                        uf.unite(x/n, x%n);
                        cout << x/n << " " << x%n <<" " << w << endl;
                        ret.pb(w*n*n+x/n*n+x%n);
                    }
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, vector <int> p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    AllGraphCuts *obj;
    vector <int> answer;
    obj = new AllGraphCuts();
    clock_t startTime = clock();
    answer = obj->findGraph(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "{";
        for (int i = 0; int(p1.size()) > i; ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << p1[i];
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
        if (answer.size() != p1.size()) {
            res = false;
        } else {
            for (int i = 0; int(answer.size()) > i; ++i) {
                if (answer[i] != p1[i]) {
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

    vector <int> p0;
    vector <int> p1;

    // ----- test 0 -----
    disabled = false;
    p0 = {0,1,1,0};
    p1 = {6};
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {0,1,1,1};
    p1 = {-1};
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = {0,2,2,2,0,2,2,2,0};
    p1 = {10,11,14};
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = {0,1,2,3,4,1,0,2,3,4,1,2,0,3,4,1,2,3,0,4,1,2,3,4,0};
    p1 = {-1};
    all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = {0,0,0,0};
    p1 = {2};
    all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 5 -----
    disabled = false;
    p0 = {0,2545,2348,2993,2606,2623,2013,3001,2626,2440,2495,2262,2342,2617,2773,2662,2736,2827,3044,3082,2545,0,2348,2545,2545,2545,2013,2545,2545,2440,2495,2262,2342,2545,2545,2545,2545,2545,2545,2545,2348,2348,0,2348,2348,2348,2013,2348,2348,2348,2348,2262,2342,2348,2348,2348,2348,2348,2348,2348,2993,2545,2348,0,2606,2623,2013,2993,2626,2440,2495,2262,2342,2617,2773,2662,2736,2827,2993,2993,2606,2545,2348,2606,0,2606,2013,2606,2606,2440,2495,2262,2342,2606,2606,2606,2606,2606,2606,2606,2623,2545,2348,2623,2606,0,2013,2623,2623,2440,2495,2262,2342,2617,2623,2623,2623,2623,2623,2623,2013,2013,2013,2013,2013,2013,0,2013,2013,2013,2013,2013,2013,2013,2013,2013,2013,2013,2013,2013,3001,2545,2348,2993,2606,2623,2013,0,2626,2440,2495,2262,2342,2617,2773,2662,2736,2827,3001,3001,2626,2545,2348,2626,2606,2623,2013,2626,0,2440,2495,2262,2342,2617,2626,2626,2626,2626,2626,2626,2440,2440,2348,2440,2440,2440,2013,2440,2440,0,2440,2262,2342,2440,2440,2440,2440,2440,2440,2440,2495,2495,2348,2495,2495,2495,2013,2495,2495,2440,0,2262,2342,2495,2495,2495,2495,2495,2495,2495,2262,2262,2262,2262,2262,2262,2013,2262,2262,2262,2262,0,2262,2262,2262,2262,2262,2262,2262,2262,2342,2342,2342,2342,2342,2342,2013,2342,2342,2342,2342,2262,0,2342,2342,2342,2342,2342,2342,2342,2617,2545,2348,2617,2606,2617,2013,2617,2617,2440,2495,2262,2342,0,2617,2617,2617,2617,2617,2617,2773,2545,2348,2773,2606,2623,2013,2773,2626,2440,2495,2262,2342,2617,0,2662,2736,2773,2773,2773,2662,2545,2348,2662,2606,2623,2013,2662,2626,2440,2495,2262,2342,2617,2662,0,2662,2662,2662,2662,2736,2545,2348,2736,2606,2623,2013,2736,2626,2440,2495,2262,2342,2617,2736,2662,0,2736,2736,2736,2827,2545,2348,2827,2606,2623,2013,2827,2626,2440,2495,2262,2342,2617,2773,2662,2736,0,2827,2827,3044,2545,2348,2993,2606,2623,2013,3001,2626,2440,2495,2262,2342,2617,2773,2662,2736,2827,0,3044,3082,2545,2348,2993,2606,2623,2013,3001,2626,2440,2495,2262,2342,2617,2773,2662,2736,2827,3044,0};
    p1 = {76801,87602,76403,15604,14005,14406,95607,14408,45609,54010,113211,102812,53613,72414,10015,90416,110417,108818,76819,20022,5223,16824,14025,20426,37227,115628,118829,105230,39631,114032,70833,2434,9235,71636,3637,108438,68439,16443,24444,37245,54046,118447,46048,13249,38450,27651,23652,105253,76054,22455,112056,5657,82458,28859,31264,117665,73666,91667,11268,67269,110870,18471,114872,119673,22074,86075,44876,22477,74478,93679,96085,8486,59687,110088,1689,107290,56091,56092,74893,61294,109295,109296,18097,66498,20899,12506,98907,82908,77309,51710,110111,108112,22513,66514,43315,36516,19717,15318,26519,34127,70128,8929,20930,131,81732,80133,29334,68935,53336,81737,36538,57739,35348,96149,25750,19351,15752,4153,80554,107355,96556,70557,66958,48559,33769,81370,55771,15372,61373,72574,11375,2976,66577,108178,57779,590,78991,14992,10593,69794,47395,33796,113397,77398,68999,77811,28212,12613,64614,80215,9816,27017,30618,73819,46632,66633,7834,100635,636,7437,4238,76639,87453,16254,10255,31856,50257,18258,3459,73474,69475,63876,41077,3878,28679,13495,56696,109497,101098,116699,60316,107517,12318,98719,51137,91138,81139,108358,119959,106379};
    all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // ----- test 3 -----
    disabled = false;
    p0 =   {0,3,7,5,
            3,0,3,3,
            7,3,0,5,
            5,3,5,0};
    p1 = {-1};
    all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
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
// All graphs in this problem statement are simple undirected graphs with nonnegative integer edge weights.
// Here, "simple" means that there are no self-loops and each pair of vertices is connected by at most one direct edge.
// 
// 
// 
// Given a connected graph G, a cut between vertices i and j is a set E of edges such that each path from i to j contains at least one edge from the set E.
// In other words, if you cut all edges in E, the vertices i and j will end in different connected components.
// 
// 
// 
// If E is a set of edges, the weight of E is the sum of weights of edges it contains.
// For any distinct vertices i and j, the min cut weight between i and j is the minimum weight of a cut between i and j.
// Additionally, for any vertex i we define that the min cut weight between i and i is 0.
// 
// 
// 
// You are given a vector <int> x with n*n elements.
// You would like to find a connected graph G with n vertices, labeled 0 through n-1.
// The graph G must have the following properties:
// 
// For each i and j, the min cut weight between vertices i and j must be exactly x[i*n+j].
// G must have at most 1000 edges.
// The weight of each edge must be between 0 and 10^5, inclusive.
// 
// For the given constraints it is guaranteed that whenever there is a graph that has the first property, there is a graph that has all three properties.
// 
// 
// 
// If there are no solutions, return the vector <int> {-1}.
// Otherwise, find any graph G that has the required properties and return a vector <int> with exactly m elements, where m is the number of edges in G.
// If G contains an edge (i,j) with weight w, the return value should contain the number (w*n*n + i*n + j).
// 
// 
// DEFINITION
// Class:AllGraphCuts
// Method:findGraph
// Parameters:vector <int>
// Returns:vector <int>
// Method signature:vector <int> findGraph(vector <int> x)
// 
// 
// CONSTRAINTS
// -n will be between 2 and 50, inclusive.
// -x will have exactly n*n elements.
// -Each element of x will be between 0 and 10^5, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {0,1,
//  1,0}
// 
// Returns: {6 }
// 
// In this case n = 2. The output can be decoded as a single edge between nodes 0 and 1 with weight 1 (i.e. 1*2*2 + 1*2 + 0 = 6).
// 
// 1)
// {0,1,
//  1,1}
// 
// Returns: {-1 }
// 
// Note that since we have x[1*2+1] != 0, there is no valid solution.
// 
// 2)
// {0,2,2,
//  2,0,2,
//  2,2,0}
// 
// Returns: {10, 11, 14 }
// 
// This graph can be decoded as a triangle graph, where all the edge weights are 1.
// 
// 3)
// {0,1,2,3,4,
//  1,0,2,3,4,
//  1,2,0,3,4,
//  1,2,3,0,4,
//  1,2,3,4,0}
// 
// Returns: {-1 }
// 
// 
// 
// 4)
// {0,0,0,0}
// 
// Returns: {2 }
// 
// Note that some edge weights can be zero.
// The empty vector <int> {} is not a correct return value, since the graph G you return must be connected.
// 
// 5)
// {
// 0, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 3082,
// 2545, 0, 2348, 2545, 2545, 2545, 2013, 2545, 2545, 2440, 2495, 2262, 2342, 2545, 2545, 2545, 2545, 2545, 2545, 2545,
// 2348, 2348, 0, 2348, 2348, 2348, 2013, 2348, 2348, 2348, 2348, 2262, 2342, 2348, 2348, 2348, 2348, 2348, 2348, 2348,
// 2993, 2545, 2348, 0, 2606, 2623, 2013, 2993, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 2993, 2993,
// 2606, 2545, 2348, 2606, 0, 2606, 2013, 2606, 2606, 2440, 2495, 2262, 2342, 2606, 2606, 2606, 2606, 2606, 2606, 2606,
// 2623, 2545, 2348, 2623, 2606, 0, 2013, 2623, 2623, 2440, 2495, 2262, 2342, 2617, 2623, 2623, 2623, 2623, 2623, 2623,
// 2013, 2013, 2013, 2013, 2013, 2013, 0, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013,
// 3001, 2545, 2348, 2993, 2606, 2623, 2013, 0, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3001, 3001,
// 2626, 2545, 2348, 2626, 2606, 2623, 2013, 2626, 0, 2440, 2495, 2262, 2342, 2617, 2626, 2626, 2626, 2626, 2626, 2626,
// 2440, 2440, 2348, 2440, 2440, 2440, 2013, 2440, 2440, 0, 2440, 2262, 2342, 2440, 2440, 2440, 2440, 2440, 2440, 2440,
// 2495, 2495, 2348, 2495, 2495, 2495, 2013, 2495, 2495, 2440, 0, 2262, 2342, 2495, 2495, 2495, 2495, 2495, 2495, 2495,
// 2262, 2262, 2262, 2262, 2262, 2262, 2013, 2262, 2262, 2262, 2262, 0, 2262, 2262, 2262, 2262, 2262, 2262, 2262, 2262,
// 2342, 2342, 2342, 2342, 2342, 2342, 2013, 2342, 2342, 2342, 2342, 2262, 0, 2342, 2342, 2342, 2342, 2342, 2342, 2342,
// 2617, 2545, 2348, 2617, 2606, 2617, 2013, 2617, 2617, 2440, 2495, 2262, 2342, 0, 2617, 2617, 2617, 2617, 2617, 2617,
// 2773, 2545, 2348, 2773, 2606, 2623, 2013, 2773, 2626, 2440, 2495, 2262, 2342, 2617, 0, 2662, 2736, 2773, 2773, 2773,
// 2662, 2545, 2348, 2662, 2606, 2623, 2013, 2662, 2626, 2440, 2495, 2262, 2342, 2617, 2662, 0, 2662, 2662, 2662, 2662,
// 2736, 2545, 2348, 2736, 2606, 2623, 2013, 2736, 2626, 2440, 2495, 2262, 2342, 2617, 2736, 2662, 0, 2736, 2736, 2736,
// 2827, 2545, 2348, 2827, 2606, 2623, 2013, 2827, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 0, 2827, 2827,
// 3044, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 0, 3044,
// 3082, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 0
// }
// 
// 
// Returns: {76801, 87602, 76403, 15604, 14005, 14406, 95607, 14408, 45609, 54010, 113211, 102812, 53613, 72414, 10015, 90416, 110417, 108818, 76819, 20022, 5223, 16824, 14025, 20426, 37227, 115628, 118829, 105230, 39631, 114032, 70833, 2434, 9235, 71636, 3637, 108438, 68439, 16443, 24444, 37245, 54046, 118447, 46048, 13249, 38450, 27651, 23652, 105253, 76054, 22455, 112056, 5657, 82458, 28859, 31264, 117665, 73666, 91667, 11268, 67269, 110870, 18471, 114872, 119673, 22074, 86075, 44876, 22477, 74478, 93679, 96085, 8486, 59687, 110088, 1689, 107290, 56091, 56092, 74893, 61294, 109295, 109296, 18097, 66498, 20899, 12506, 98907, 82908, 77309, 51710, 110111, 108112, 22513, 66514, 43315, 36516, 19717, 15318, 26519, 34127, 70128, 8929, 20930, 131, 81732, 80133, 29334, 68935, 53336, 81737, 36538, 57739, 35348, 96149, 25750, 19351, 15752, 4153, 80554, 107355, 96556, 70557, 66958, 48559, 33769, 81370, 55771, 15372, 61373, 72574, 11375, 2976, 66577, 108178, 57779, 590, 78991, 14992, 10593, 69794, 47395, 33796, 113397, 77398, 68999, 77811, 28212, 12613, 64614, 80215, 9816, 27017, 30618, 73819, 46632, 66633, 7834, 100635, 636, 7437, 4238, 76639, 87453, 16254, 10255, 31856, 50257, 18258, 3459, 73474, 69475, 63876, 41077, 3878, 28679, 13495, 56696, 109497, 101098, 116699, 60316, 107517, 12318, 98719, 51137, 91138, 81139, 108358, 119959, 106379 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
