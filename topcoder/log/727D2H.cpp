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

class ManageSubsequences {
    public:
        int minAdded(string s, string a, string b) {
            const ll M = 30; // TODO 310
            ll dp[M][M][M];
            rep(i, M) rep(j, M) rep(h, M) dp[i][j][h] = INF;
            dp[0][0][0] = 0;
            rep(i, s.length()+1) {
                cout << i << " #####" << endl;
                rep(j, a.length()+1) rep(h, b.length()+1) {
                    if (dp[i][j][h] != INF) {
                        cout << mt(i, j, h) << endl;
                        chmin(dp[i][j+1][h], dp[i][j][h]+1);
                        chmin(dp[i][j][h+1], dp[i][j][h]+1);
                    }
                }
                rep(j, a.length()) rep(h, b.length()) {
                    if (dp[i][j][h] != INF) {
                        if (i < s.length()) {
                            if (s[i] == a[j] && s[i] == b[h]) 
                                chmin(dp[i+1][j+1][h+1], dp[i][j][h]);
                            else if (s[i] == a[j]) 
                                chmin(dp[i+1][j+1][h], dp[i][j][h]);
                            else if (s[i] == b[h]) 
                                chmin(dp[i+1][j][h+1], dp[i][j][h]);
                            chmin(dp[i+1][j][h], dp[i][j][h]);
                        }
                    }
                }
            }
            rep(i, s.length()+1) {
                rep(j, a.length()+1) rep(h, b.length()+1) {
                    if (dp[i][j][h] != INF) {
                        cout << mt(i, j, h) << " " << dp[i][j][h] << endl;
                    }
                }
            }
            ll ret = INF;
            rep(h, b.length()) {
                chmin(ret, dp[s.length()][a.length()][h]);
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
bool KawigiEdit_RunTest(int testNum, string p0, string p1, string p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"" << "," << "\"" << p2 << "\"";
    cout << "]" << endl;
    ManageSubsequences *obj;
    int answer;
    obj = new ManageSubsequences();
    clock_t startTime = clock();
    answer = obj->minAdded(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
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

    string p0;
    string p1;
    string p2;
    int p3;

    // ----- test 0 -----
    disabled = false;
    p0 = "ABXBCA";
    p1 = "ABCD";
    p2 = "XD";
    p3 = 2;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = "BXC";
    p1 = "BOCZ";
    p2 = "DSFHDS";
    p3 = 2;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = "BXC";
    p1 = "BOCZ";
    p2 = "BZ";
	p3 = -1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "ABC";
	p1 = "CDE";
	p2 = "ABCE";
	p3 = 3;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "BANANA";
	p1 = "APPLE";
	p2 = "ANNA";
	p3 = -1;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = "BANANA";
	p1 = "ANANAS";
	p2 = "BS";
	p3 = 6;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = "BANANA";
	p1 = "ANANAS";
	p2 = "BNNS";
	p3 = 3;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, true, p3) ) && all_right;
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
// Definition: for two strings X and Y, we say that a string X has a subsequence Y if and only if it's possible to remove 0 or more characters in X so that the remaining characters form the string Y. For example, "ABCDEFFF" has subsequences "B", "ABFF" and "ABCDEFFF", but doesn't have subsequences "XSFJ", "BA" and "CCDD".
// 
// Limak has a string S that consists of uppercase English letters ('A' - 'Z').
// He can add more characters (also uppercase English letters) in S.
// For example, if S is "ABXB", he can get "BAOUBXBB" by inserting 'B', 'O', 'U' and 'B'.
// 
// You are given three strings S, A and B, each consisting of uppercase English letters.
// Limak wants to add characters anywhere into S, including its beginning and end, so that the new string has the subsequence A but doesn't have the subsequence B.
// Find and return the minimum possible number of added characters.
// If Limak can't obtain a string with the desired properties, return -1 instead.
// 
// DEFINITION
// Class:ManageSubsequences
// Method:minAdded
// Parameters:string, string, string
// Returns:int
// Method signature:int minAdded(string S, string A, string B)
// 
// 
// CONSTRAINTS
// -S will contain between 1 and 300 characters, inclusive.
// -A will contain between 1 and 300 characters, inclusive.
// -B will contain between 1 and 300 characters, inclusive.
// -Each character in S, A and B will be an uppercase English letter ('A' - 'Z').
// 
// 
// EXAMPLES
// 
// 0)
// "ABXBCA"
// "ABCD"
// "XD"
// 
// Returns: 2
// 
// Limak has the string "ABXBCA".
// Adding 'D' at the end would be enough to obtain a string that has the subsequence "ABCD" as needed, but the new string can't have the subsequence "XD".
// 
// Limak should add 'C' and 'D' just after the first 'B' in the "ABXBCA", obtaining "ABCDXBCA".
// The number of added characters is 2.
// 
// 1)
// "BXC"
// "BOCZ"
// "DSFHDS"
// 
// Returns: 2
// 
// Limak has the string "BXC" and wants to obtain a string that has the subsequence "BOCZ" and doesn't have the subsequence "DSFHDS".
// 
// For example, he can add 'O' just after 'B', and add 'Z' at the end, getting the string "BOXCZ".
// The number of added characters is 2.
// 
// 2)
// "BXC"
// "BOCZ"
// "BZ"
// 
// Returns: -1
// 
// The new string must have the subsequence "BOCZ" but can't have the subsequence "BZ", what is impossible.
// You should return -1.
// 
// 3)
// "ABC"
// "CDE"
// "ABCE"
// 
// Returns: 3
// 
// 
// 
// 4)
// "BANANA"
// "APPLE"
// "ANNA"
// 
// Returns: -1
// 
// 
// 
// 5)
// "BANANA"
// "ANANAS"
// "BS"
// 
// Returns: 6
// 
// 
// 
// 6)
// "BANANA"
// "ANANAS"
// "BNNS"
// 
// Returns: 3
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
