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

class DominoTiling {
    public:
        ll n, m;
        bool valid(ll mask) {
            ll cnt = 0;
            ll ng = 0;
            rep(j, m) {
                if ((mask & (1ll << j))) {
                    cnt++;
                } else {
                    if (cnt % 2 != 0) return 0;
                    cnt = 0;
                }
            }
            if (cnt % 2 != 0) return 0;
            return 1;

        }
        long long count(vector <string> b) {
            n = b.size();
            m = b[0].size();
            // i行目でmaskが上から来ている場合の数
            ll dp[n+1][1ll<<m];
            rep(i, n+1) rep(j, 1ll<<m) dp[i][j] = 0;
            dp[0][0] = 1;
            vll blocking;
            rep(i, n) {
                ll tmp = 0;
                rep(j, m) if (b[i][j] == 'X') tmp |= 1ll << j;
                blocking.pb(tmp);
            }
            // 配るDP
            rep(i, n) {
                rep(mask, 1<<m) if (dp[i][mask]) {
                    if (mask & blocking[i]) {
                        dp[i][mask] = 0;
                        continue;
                    }
                    ll ng_mask = mask | blocking[i];
                    ll ok_mask = ((1ll << m)-1) ^ ng_mask;
                    bool first = 1;
                    for(ll next_b=ok_mask;first&&next_b>=0;next_b=(next_b-1)&ok_mask) {
                        if (next_b == 0) first = 0;

                        // 横にするやつ
                        // okであってnext_bでないやつ
                        ll rem_mask = (next_b ^ ok_mask);
                        if (!valid(rem_mask)) continue;
                        dp[i+1][next_b] += dp[i][mask];
                    }
                }
            }
            return dp[n][0];
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, long long p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    DominoTiling *obj;
    long long answer;
    obj = new DominoTiling();
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
    long long p1;

    // ----- test 0 -----
    disabled = false;
    p0 = {"..",".."};
    p1 = 2ll;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {"...",".X.","..."};
    p1 = 2ll;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"...","...","..X"};
	p1 = 4ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {".....",".....",".X...",".X..."};
	p1 = 29ll;
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
// You are given a vector <string> grid that describes a rectangular grid of square cells.
// The character 'X' represents a cell that is already covered, the character '.' is a cell that still needs to be covered.
// 
// You want to cover all the '.' cells using a collection of disjoint 2x1 dominos.
// Return the number of ways to do this.
// Two ways are considered different if two cells are covered by the same domino in one tiling and by two different dominos in the other tiling.
// 
// 
// DEFINITION
// Class:DominoTiling
// Method:count
// Parameters:vector <string>
// Returns:long long
// Method signature:long long count(vector <string> grid)
// 
// 
// CONSTRAINTS
// -grid will contain between 1 and 12 elements, inclusive.
// -The length of each element of grid will be between 1 and 12, inclusive.
// -Each element of grid will be the same length.
// -Each character of each element of grid will be '.' or 'X'.
// 
// 
// EXAMPLES
// 
// 0)
// {"..",
//  ".."}
// 
// Returns: 2
// 
// There are exactly two ways to do this:
// 
// 
// --   or   ||
// --        ||
// 
// 
// 
// 1)
// {"...",
//  ".X.",
//  "..."}
// 
// 
// Returns: 2
// 
// Again, there are two solutions:
// 
// 
// --|     |--
// |X|     |X|
// |--     --|
// 
// 
// 
// 2)
// {"...",
//  "...",
//  "..X"}
// 
// 
// Returns: 4
// 
// 
// |||     --|     |--     --|
// |||     --|     |--     |||
// --X     __X     --X     ||X
// 
// 
// 
// 3)
// {".....",
//  ".....",
//  ".X...",
//  ".X..."}
// 
// Returns: 29
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
