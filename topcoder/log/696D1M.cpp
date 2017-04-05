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

class Clicounting {
public:
    int s[40][40]; // 隣接行列
    long long S[40]; // 隣接行列をbitwiseで詰め込んだもの
    int v[40]; // 頂点の利用状況
    int val; // 最大独立集合の数
    int n; // 頂点数
    long long uk=0; // v[i]=0のiを詰め込んだもの
    // 隣接行列としてSを埋める→initを読んで全部初期化→calcを計算→valに最大独立集合の大きさが入っている
    void calc(){
        int nm=0;
        rep(i, n) if(v[i] == 1) nm++;
        val = max(val, nm);

        rep(i, n) {
            if (v[i] == 0 && __builtin_popcountll(uk & S[i]) < 2){
                v[i] = 1;
                uk -= 1ll << i;
                long long ch=0;
                rep(j, n) if (v[j] == 0 && s[i][j]) {
                    v[j] = 2;
                    ch += 1ll << j;
                    uk -= 1ll << j;
                }
                calc();
                v[i] = 0;
                uk += 1ll<<i;
                rep(j, n) if (ch & (1ll << j)) v[j] = 0, uk += 1LL<<j;
                return;
            }
        }
        int dm = 1;
        int at = -1;
        rep(i, n) if(v[i] == 0 && __builtin_popcountll(uk & S[i]) >= dm){
            dm = __builtin_popcountll(uk & S[i]);
            at = i;
        }
        if(at == -1) return;
        v[at] = 2;
        uk -= 1LL<<at;
        calc();
        v[at] = 0;
        uk += 1LL<<at;

        v[at] = 1;
        uk -= 1LL<<at;
        long long ch=0;
        rep(j, n) if(v[j] == 0 && s[at][j]) {
            v[j] = 2;
            uk -= 1ll << j;
            ch += 1ll << j ;
        }
        calc();
        rep(j, n) if(ch & 1ll << j) { v[j] = 0; uk += 1ll << j; }
        v[at] = 0;
        uk += 1ll << at;
        return;
    }
    void init(){
        rep(j, n) v[j] = 0;
        rep(j, n) {
            S[j] = 0;
            rep(k, n) if (s[j][k]) S[j] |= (1ll << k);
        }
        val = 0;
        uk = (1ll<<n) - 1;
    }
    int count(vector <string> g) {
        n = g.size();
        int ret = 0;
        vector<P> p;
        rep(i, n) repi(j, i+1, n) if (g[i][j] == '?') p.pb(P(i, j));
        int m = p.size();
        rep(i, 1<<m) {
            rep(j, n) rep(k, n) 
                s[j][k] = (j != k && g[j][k] == '0');
            rep(j, m) if (i & (1ll << j)) 
                s[p[j].fi][p[j].se] = s[p[j].se][p[j].fi] = 1;
            init();
            calc();
            ret += val;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    Clicounting *obj;
    int answer;
    obj = new Clicounting();
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

    vector <string> p0;
    int p1;

    // ----- test 0 -----
    disabled = false;
    p0 = {"011","101","110"};
    p1 = 3;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {"01?","101","?10"};
    p1 = 5;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = {"0?","?0"};
    p1 = 3;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = {"0?" "?","?0?","?" "?0"};
    p1 = 16;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = {"0?" "?" "?","?0?" "?","?" "?0?","?" "?" "?0"};
    p1 = 151;
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
// Hero has a simple undirected graph.
// I.e., the graph has no self-loops and each pair of vertices is connected by at most one edge.
// 
// Hero would like to solve a standard problem: he wants to find the size of the largest clique in his graph.
// (A clique is a subset C of vertices such that each pair of vertices in C is connected by an edge. 
// The size of a clique is the number of vertices in C.)
// 
// However, Hero is facing an issue:
// for some (at most 10) pairs of vertices he does not remember whether they are connected by an edge or not.
// You are given the information Hero remembers: a vector <string> g with n elements, where n is the number of vertices in the graph.
// The vertices are numbered 0 through n-1.
// For each valid i and j, g[i][j] is one of '0', '1', and '?'.
// Here, '0' means that vertices i and j are not connected, '1' means that they are connected, and '?' means that Hero does not remember whether they are connected.
// 
// Let there be k unordered pairs of vertices for which Hero does not remember whether they are connected or not.
// Then, there are exactly 2^k different graphs consistent with what Hero remembers.
// For each of those graphs find the size of the largest clique, and return the sum of those 2^k numbers.
// 
// 
// DEFINITION
// Class:Clicounting
// Method:count
// Parameters:vector <string>
// Returns:int
// Method signature:int count(vector <string> g)
// 
// 
// CONSTRAINTS
// -g will contain n elements. 
// -n will be between 1 and 38, inclusive.
// -Each element in g will contain exactly n characters.
// -Each character in g will be either '0', '1' or '?'.
// -For each valid i and j, g[i][j] will be equal to g[j][i].
// -For each valid i, g[i][i] will be '0'.
// -Number of unknown edges (number of '?' characters divided by 2) will be between 0 and 10, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"011","101","110"}
// 
// Returns: 3
// 
// This is a complete graph on 3 vertices. The size of the maximum clique is 3.
// 
// 1)
// {"01?","101","?10"}
// 
// Returns: 5
// 
// Hero is not sure about a single edge.
// If the edge is in the graph, we get the situation from Example 0.
// If the edge is not there, we get a graph in which the size of the maximum clique is 2.
// The answer is therefore 3+2 = 5.
// 
// 2)
// {"0?","?0"}
// 
// Returns: 3
// 
// Here the maximum clique size is either 2 (if the unknown edge is present) or 1 (if the edge is absent).
// 
// 3)
// {"0??","?0?","??0"}
// 
// Returns: 16
// 
// 
// 
// 4)
// {"0???","?0??","??0?","???0"}
// 
// Returns: 151
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
