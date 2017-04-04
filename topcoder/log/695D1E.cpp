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

class BearPasswordLexic {
    public:
        string findPassword(vector <int> x_) {
            vll x = conv(x_);
            ll n = x.size();
            if (n != x[0]) return "";

            deque<ll> s;
            for (ll len = n - 1; len >= 0; len--) {
                while (x[len]) {
                    rep(j, len + 1) 
                        x[j] -= (len - j + 1);
                    s.pb(len + 1);
                    if (exists(all(x), [&](ll v) { return v < 0; }) != x.end()) return "";
                }
            }
            if (exists(all(x), [&](ll v) { return v; }) != x.end()) return "";
            rep(i, s.size())  cout << s[i] << endl; cout << endl;

            sort(all(s));
            string ret;
            ll i = 0;
            while (s.size()) {
                if (i & 1) {
                    ret += string(s.front(), 'b');
                    s.pop_front();
                } else {
                    ret += string(s.back(), 'a');
                    s.pop_back();
                }
                i++;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    BearPasswordLexic *obj;
    string answer;
    obj = new BearPasswordLexic();
    clock_t startTime = clock();
    answer = obj->findPassword(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p1 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
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
    string p1;

    // ----- test 0 -----
    disabled = false;
    p0 = {5,0,0,0,0};
    p1 = "ababa";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {4,2,1,0};
    p1 = "aaab";
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = {3,1,1};
    p1 = "";
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = {4,3,2,1};
    p1 = "aaaa";
    all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {1, 0};
	p1 = "a";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {4,0,3,2};
	p1 = "";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
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
// A substring of a string is any non-empty contiguous subsequence of its characters.
// For example, both "abc" and "bcd" are substrings of "abcde", but "ace" is not a substring of "abcde".
// 
// A string is called constant if all of its characters are the same.
// For example, "a" and "bbbbb" are constant strings, but "aba" is not a constant string.
// 
// Two substrings of the same string are considered distinct if they start or end at a different position.
// For example, the string "ababab" contains three distinct copies of the substring "ab", and the string "aaaa" contains two distinct copies of the substring "aaa".
// 
// Bear Limak is creating a new account and he needs to choose a password.
// His password should satisfy the following security requirements:
// 
// The password must be a string of length N.
// Each character of the password must be either 'a' or 'b'.
// For each i between 1 and N, inclusive, the password must contain exactly x[i-1] constant substrings of length i.
// 
// 
// You are given the vector <int> x with N elements.
// Help Limak: find and return a valid password!
// If there are many valid passwords, return the lexicographically smallest of them.
// If there are no valid passwords, return "" (i.e., an empty string).
// 
// DEFINITION
// Class:BearPasswordLexic
// Method:findPassword
// Parameters:vector <int>
// Returns:string
// Method signature:string findPassword(vector <int> x)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 50, inclusive.
// -x will contain exactly N elements.
// -Each element in x will be between 0 and N, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5,0,0,0,0}
// 
// Returns: "ababa"
// 
// Since the given vector <int> x has five elements, the password must contain exactly five characters.
// A password must contain x[0] = 5 constant substrings of length 1, and 0 constant substrings of bigger lengths.
// The only two valid passwords are "ababa" and "babab".
// The first one is smaller lexicographically.
// 
// 1)
// {4,2,1,0}
// 
// Returns: "aaab"
// 
// 
// 
// 2)
// {3,1,1}
// 
// Returns: ""
// 
// 
// 
// 3)
// {4,3,2,1}
// 
// Returns: "aaaa"
// 
// 
// 
// 4)
// {0}
// 
// Returns: ""
// 
// 
// 
// 5)
// {4,0,3,2}
// 
// Returns: ""
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
