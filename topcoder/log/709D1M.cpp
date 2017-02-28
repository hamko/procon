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

class Softmatch {
    public:
        bool match(char c, ll d) {
            if (c == 'a') return d == 0 || d == 1;
            if (c == 'A') return d == 2 || d == 3;
            if (c == 'b') return d == 0 || d == 2;
            if (c == 'B') return d == 1 || d == 3;
            return 0;
        }
        ll matchNum(string patt, string s) {
            ll ret = 0;
            rep(h, patt.size() - s.size() + 1) {
                ll faf = 1;
                rep(l, s.size()) {
                    if (!match(patt[h+l], s[l] - '0')) {
                        faf = 0;
                        break;
                    }
                }
                ret += faf;
            }
            return ret;
        }

        int count(string s, vector <string> p) {
            ll n = p.size();

            ll pnum = min<ll>(5, s.length());
            vvll dp(60, vll(1<<pnum));

            /*
            cout << matchNum("AAAAA", "00000") << endl;;
            cout << matchNum("AAAAA", "23232") << endl;;
            cout << matchNum("AAAAA", "232") << endl;;
            */
            map<string, ll> memo;
            rep(i, 1<<pnum) {
                rep(j, 1<<pnum) {
                    string t;
                    rep(j, pnum) t += ((i & (1ll << j)) ? "b" : "a");
                    rep(h, pnum) t[h] += ((j & (1ll << h)) ? 'A' - 'a' : 0);
                    ll ret = 0;
                    rep(k, n) {
                        ret += matchNum(t, p[k]);
                    }
                    memo[t] = ret;
                }
            }

            if (s.length() <= 5) {
                ll ret = 0;
                rep(i, 1<<s.length()) {
                    string tmp = s;
                    rep(j, s.length()) {
                        tmp[j] += ((i & (1ll << j)) ? 'A' - 'a' : 0);
                    }
                    chmax(ret, memo[tmp]);
                }
                return ret;
            }

            cout << memo << endl;
            rep(i, 1ll<<pnum) {
                string tmp = s;
                rep(j, s.length()) {
                    tmp[j] += ((i & (1ll << j)) ? 'A' - 'a' : 0);
                }
                dp[5][i] = memo[tmp];

            }

            repi(i, 5, s.length()) {
                rep(j, 1<<pnum) {
                    ll mask0 = (j>>1)+(0<<(pnum-1)); // 0????
                    ll mask1 = (j>>1)+(1<<(pnum-1)); // 1????

                    string t0, t1, tj;
                    // ????# = j
                    // 0???? = mask0
                    // 1???? = mask1
                    //
                    // ----????#
                    // ---0???? -> dp[---0????] + memo[????#] - memo[0????]
                    // ---1???? -> dp[---1????] + memo[????#] - memo[1????]
                    rep(k, pnum) t0 += s[i-pnum+k] + ((mask0 & (1ll << k)) ? 'A' - 'a' : 0);
                    rep(k, pnum) t1 += s[i-pnum+k] + ((mask1 & (1ll << k)) ? 'A' - 'a' : 0);
                    rep(k, pnum) tj += s[i-pnum+k+1] + ((j     & (1ll << k)) ? 'A' - 'a' : 0);
                    cout << t0 << " " << t1 << " " << tj << endl;

                    chmax(dp[i+1][j], dp[i][mask0] + memo[tj] - memo[t0]);
                    chmax(dp[i+1][j], dp[i][mask1] + memo[tj] - memo[t1]);
                }
            }
            ll ret = 0;
            rep(i, 1ll<<pnum) {
                chmax(ret, dp[n][i]);
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
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    Softmatch *obj;
    int answer;
    obj = new Softmatch();
    clock_t startTime = clock();
    answer = obj->count(p0, p1);
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

    string p0;
    vector <string> p1;
    int p2;

    // ----- test 0 -----
    disabled = false;
    p0 = "aaa";
    p1 = {"03","21"};
    p2 = 2;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "aba";
	p1 = {"03","11"};
	p2 = 3;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "bba";
	p1 = {"00","00"};
	p2 = 4;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "bbbbbb";
	p1 = {"1110","011","100"};
	p2 = 3;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "abbaa";
	p1 = {"123"};
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = "aababbaab";
	p1 = {"012","332","101","0313"};
	p2 = 7;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
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
// Hero has a collection of (not necessarily distinct) strings.
// You are given this collection in the vector <string> patterns.
// Each character in each string is one of '0', '1', '2', and '3'.
// 
// Hero also has a string of wildcard characters.
// You are given it as the string S.
// Each character of S is either 'a' or 'b'.
// You are allowed to modify S by changing some (possibly none or all) characters to their uppercase versions: that is 'a' to 'A' and 'b' to 'B'.
// 
// The meaning of the wildcard characters in S is as follows:
// 
// 'a' matches small digits: '0' and '1'
// 'A' matches big digits: '2' and '3'
// 'b' matches even digits: '0' and '2'
// 'B' matches odd digits: '1' and '3'
// 
// 
// We say that S contains an occurrence of the pattern p at position j if for each valid i the wildcard character S[j+i] exists and matches the digit patterns[p][i].
// 
// As we already mentioned above, you are allowed to modify S by changing some of its letters to uppercase.
// Your goal is to maximize the total number of occurrences of the given patterns in your modified S.
// In other words, you want to maximize the number of pairs (p,j) such that your modified S contains an occurrence of the pattern p at position j.
// 
// Compute and return the largest possible total number of occurrences of the given patterns in the modified string of wildcards.
// 
// DEFINITION
// Class:Softmatch
// Method:count
// Parameters:string, vector <string>
// Returns:int
// Method signature:int count(string S, vector <string> patterns)
// 
// 
// CONSTRAINTS
// -S will contain between 1 and 50 characters, inclusive.
// -Each character in S will be either 'a' or 'b'.
// -patterns will contain between 1 and 5 elements, inclusive.
// -Each element in patterns will contain between 1 and 50 characters, inclusive.
// -Each character in patterns will be between '0' and '3', inclusive.
// -Each element in patterns will be at most as long as S.
// 
// 
// EXAMPLES
// 
// 0)
// "aaa"
// {"03","21"}
// 
// Returns: 2
// 
// There are two optimal solutions:
// 
// You may change S to "AaA". This string contains an occurrence of pattern 1 at position 0 and an occurrence of pattern 0 at position 1.
// You may change S to "aAa". This string contains an occurrence of pattern 0 at position 0 and an occurrence of pattern 1 at position 1.
// 
// In either case, the total number of occurrences of a pattern is 2.
// 
// 1)
// "aba"
// {"03","11"}
// 
// Returns: 3
// 
// The string "aBa" contains three occurrences of the given patterns: pattern 0 occurs at position 0, and pattern 1 occurs both at position 0 and at position 1.
// 
// 2)
// "bba"
// {"00","00"}
// 
// Returns: 4
// 
// Even if two patterns are equal, we count the occurrences of each of them separately.
// 
// 3)
// "bbbbbb"
// {"1110","011","100"}
// 
// Returns: 3
// 
// 
// 
// 4)
// "abbaa"
// {"123"}
// 
// Returns: 2
// 
// 
// 
// 5)
// "aababbaab"
// {"012","332","101", "0313"}
// 
// Returns: 7
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
