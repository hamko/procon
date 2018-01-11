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

class OnlySanta {
    public:
        // OKで1
        bool check(string s) {
            ll mode = 0;
            rep(i, s.length()) {
//                cout << s[i] << " " << mode<< endl;
                if (mode == 0 && s[i] == 'S') mode = 1;
                else if (mode == 1 && s[i] == 'A') mode = 2;
                else if (mode == 2 && s[i] == 'T') mode = 3;
                else if (mode == 3 && s[i] == 'A') mode = 4;
                else if (mode == 4 && s[i] == 'N') return 0;
            }
            return 1;
        }
        bool haveSanta(string s) {
            ll mode = 0;
            rep(i, s.length()) {
//                cout << s[i] << " " << mode<< endl;
                if (mode == 0 && s[i] == 'S') mode = 1;
                else if (mode == 1 && s[i] == 'A') mode = 2;
                else if (mode == 2 && s[i] == 'N') mode = 3;
                else if (mode == 3 && s[i] == 'T') mode = 4;
                else if (mode == 4 && s[i] == 'A') return 1;
            }
            return 0;
        }
 
        void sl(void) {
            rep(_, 10000) {
                string s;
                string t= "SANT";
                rep(i, 5) {
                    s += (t[rand()%4]);
                }
                if (check(s)) {
                    string tmp = solve(s);
                    assert(check(s) == 1);
                }
            }
        }
        string solve(string S) {
            string s="SAT";
            int Len=S.length();
            int p=0;
            for(int i=0;i<3;i++)
                while(p<Len&&S[p]!=s[i])p++;
            if(p==Len)return S+"SANTA";


            return S;
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
    cout << "]" << endl;
    OnlySanta *obj;
    string answer;
    obj = new OnlySanta();
    clock_t startTime = clock();
    answer = obj->solve(p0);
    obj->sl();
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

    string p0;
    string p1;

    // ----- test 0 -----
    disabled = false;
    p0 = "STANA";
    p1 = "STANTA";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = "STN";
    p1 = "SANTNA";
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = "RATSNOOOA";
    p1 = "DEARATSNOOOSANTA";
    all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = "SXAYNTA";
	p1 = "OOOOSOXAYNTOOOOAOOO";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "SNTA";
	p1 = "SANTA";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = "ASNTA";
	p1 = "SASNTAS";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = "NIELATA";
	p1 = "SANIELATAJA";
	all_right = (disabled || KawigiEdit_RunTest(6, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = "X";
	p1 = "SSAAXNNTTAA";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 7 -----
	disabled = false;
	p0 = "X";
	p1 = "SSAAXNNTTAA";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
			// ----- test 7 -----
	disabled = false;
	p0 = "SATNTA";
	p1 = "";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
				// ----- test 7 -----
	disabled = false;
	p0 = "SANTA";
	p1 = "";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
					// ----- test 7 -----
	disabled = false;
	p0 = "ANTA";
	p1 = "";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
						// ----- test 7 -----
	disabled = false;
	p0 = "ASN";
	p1 = "";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, true, p1) ) && all_right;
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
// Definition: for two strings X and Y, we say that a string X has a subsequence Y if and only if it's possible to remove 0 or more characters in X so that the remaining characters form the string Y.
// For example, "ABCDEFFF" has subsequences "B", "ABFF" and "ABCDEFFF", but doesn't have subsequences "XSFJ", "BA" and "CCDD".
// 
// Kids often want to write a letter to Santa but they make a typo and send them to Satan instead.
// We say that the address written on an envelope is good if and only if it has the subsequence "SANTA" but it doesn't have the subsequence "SATAN" - otherwise the letter can be sent to the wrong place!
// 
// Limak already wrote a string S as the address.
// It's guaranteed that S doesn't have the subsequence "SATAN", but possibly it doesn't have the subsequence "SANTA" either.
// Your task is to add some (0 or more) characters anywhere into S, including its beginning and end, so that it is a good address, as defined above.
// 
// You are given the string S of length up to 1000 consisting of uppercase English letters, representing the currently written address.
// Formally, return any string X that satisifes the following conditions:
// 
// 
// X has a subsequence S.
// X has the subsequence "SANTA".
// X doesn't have the subsequence "SATAN".
// X has at most 1050 characters.
// Each character in X must be an uppercase English letter 'A' - 'Z'.
// 
// 
// DEFINITION
// Class:OnlySanta
// Method:solve
// Parameters:string
// Returns:string
// Method signature:string solve(string S)
// 
// 
// NOTES
// -It can be proved that a valid answer exists for any valid input.
// 
// 
// CONSTRAINTS
// -S will contain between 1 and 1000 characters, inclusive.
// -Each character in S will be an uppercase English letter: 'A' - 'Z'.
// -S will not have the subsequence "SATAN".
// 
// 
// EXAMPLES
// 
// 0)
// "STANA"
// 
// Returns: "STANTA"
// 
// Limak already wrote "STANA".
// He can add a single character 'T' to obtain "STANTA".
// This string has the subsequence "SANTA" and doesn't have the subsequence "SATAN".
// 
// 1)
// "STN"
// 
// Returns: "SANTNA"
// 
// Here, one correct solution is to add "AN" between 'S' and 'T' and also add 'A' at the end of the string.
// The returned string is: "S(A)(N)TN(A)", where brackets represent added characters.
// 
// 2)
// "RATSNOOOA"
// 
// Returns: "DEARATSNOOOSANTA"
// 
// 
// 
// 3)
// "SXAYNTA"
// 
// Returns: "OOOOSOXAYNTOOOOAOOO"
// 
// One correct answer is simply "SXAYNTA" because this given string already has the subsequence "SANTA".
// You don't have to minimize the number of added characters though.
// 
// 4)
// "SNTA"
// 
// Returns: "SANTA"
// 
// 
// 
// 5)
// "ASNTA"
// 
// Returns: "SASNTAS"
// 
// 
// 
// 6)
// "NIELATA"
// 
// Returns: "SANIELATAJA"
// 
// 
// 
// 7)
// "X"
// 
// Returns: "SSAAXNNTTAA"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
