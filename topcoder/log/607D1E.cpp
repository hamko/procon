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

class PalindromicSubstringsDiv1 {
    public:
        double expectedPalindromes(vector <string> S1, vector <string> S2) {
            string t; rep(i, S1.size()) t+=S1[i]; rep(i, S2.size()) t+=S2[i]; 
            string s=t;
            ll n = s.length();
            ld num = 0;
            rep(i, n) num+=s[i]=='?';

            ld ans = 0;
            rep(i, n) {
                ld ret = 0;
                ll m = num;
                ret += pow(26, m - num);
                m -= s[i] == '?';
                ld tmp = s[i] == '?' ? 26 : 1;
                repi(j, 1, n) {
                    if (i-j < 0 || i+j >= n) break;
                    ll l = s[i-j], r = s[i+j];
                    if (l != '?' && r != '?' && l != r) break;
                    m -= l == '?';
                    m -= r == '?';
                    tmp *= (l == '?' && r == '?') ? 26 : 1;
                    ret += tmp * pow(26, m - num);
                }
                cout << ret << endl;
                ans += ret;
            }
            rep(i, n-1) {
                ld ret = 0;
                ll m = num;
                ld tmp = 1;
                rep(j, n) {
                    if (i-j<0||i+1+j>=n) break;
                    ll l = s[i-j], r = s[i+1+j];
                    if (l != '?' && r != '?' && l != r) break;
                    m -= l == '?';
                    m -= r == '?';
                    tmp *= (l == '?' && r == '?') ? 26 : 1;
                    ret += tmp * pow(26, m - num);
                }
                cout << ret << endl;
                ans += ret;
            }
            cout << pow(26, 5000) << endl;

 
            return ans;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PalindromicSubstringsDiv1 *obj;
	double answer;
	obj = new PalindromicSubstringsDiv1();
	clock_t startTime = clock();
	answer = obj->expectedPalindromes(p0, p1);
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
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	vector <string> p1;
	double p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"a","a",""};
	p1 = {"a"};
	p2 = 6.0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"z?" "?"};
	p1 = {};
	p2 = 3.115384615384615;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"ab","c"};
	p1 = {"?" "?","a?"};
	p2 = 7.315088757396449;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {};
	p1 = {"?"};
	p2 = 1.0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"ab?def","?"};
	p1 = {"f?" "?a"};
	p2 = 12.545971779699588;
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
// Marco likes strings.
// In particular, he likes strings that have a lot of palindromic substrings.
// For example, he really likes the string "aaa" because it has 6 palindromic substrings: "a" occurs three times, "aa" occurs twice, and "aaa" occurs once.
// 
// Right now, Marco has a string S composed of lowercase letters and question marks.
// You are to reconstruct S from the given vector <string>s S1 and S2 as follows:
// 
// Concatenate all elements of S1 to make a string A.
// Concatenate all elements of S2 to make a string B.
// Finally, concatenate A and B to get S.
// 
// 
// 
// Marco is going to replace every question mark in S with a random lowercase letter ('a' - 'z').
// Return the expected number of palindromic substrings in the resulting string.
// 
// DEFINITION
// Class:PalindromicSubstringsDiv1
// Method:expectedPalindromes
// Parameters:vector <string>, vector <string>
// Returns:double
// Method signature:double expectedPalindromes(vector <string> S1, vector <string> S2)
// 
// 
// NOTES
// -For each question mark, the letter used to replace it is chosen uniformly at random. That is, the probability of choosing any particular letter is 1/26. All random choices are mutually independent.
// -A palindromic string is a string that reads the same forwards and backwards.
// -Your return value must have an absolute or a relative error of less than 1e-9.
// 
// 
// CONSTRAINTS
// -S1 and S2 will contain no more than 50 elements.
// -Each element of S1 and S2 will contain no more than 50 characters.
// -S will contain at least 1 character.
// -S will contain only lowercase letters ('a' - 'z') and question marks ('?').
// 
// 
// EXAMPLES
// 
// 0)
// {"a","a",""}
// {"a"}
// 
// Returns: 6.0
// 
// This is the example given in the statement.
// 
// 1)
// {"z??"}
// {}
// 
// Returns: 3.115384615384615
// 
// There are 26^2 = 676 equally likely possibilities for the letters used to replace the question marks.
// Here are all possible outcomes:
// 
// The string "zzz" has 6 palindromic substrings.
// Each of the 25 strings "zaz", "zbz", ..., "zyz" has 4 palindromic substrings.
// Each of the 25 strings "zza", "zzb", ..., "zzy" has 4 palindromic substrings.
// Each of the 25 strings "zaa", "zbb", ..., "zyy" has 4 palindromic substrings.
// Each of the remaining 600 possible strings only has the 3 single-letter palindromic substrings.
// 
// The expected number of palindromic substrings can be computed simply as the average over all 676 possible cases.
// Hence, the correct return value is (6 + 75*4 + 600*3) / 676.
// 
// 2)
// {"ab","c"}
// {"??","a?"}
// 
// Returns: 7.315088757396449
// 
// 
// 
// 3)
// {}
// {"?"}
// 
// Returns: 1.0
// 
// 
// 
// 4)
// {"ab?def","?"}
// {"f??a"}
// 
// Returns: 12.545971779699588
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
