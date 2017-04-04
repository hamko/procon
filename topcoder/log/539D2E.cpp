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

class PlatypusPaternity {
    public:
        int maxFamily(vector <string> f, vector <string> m, vector <string> s) {
            ll ret = 0;
            for (auto ff : f) for (auto mm : m) for (auto ss : s) {
                bool f = 1;
                ll counter = 0;
                rep(i, ss.size()) if (ss[i] == 'Y') {
                    f &= (ff[i] == 'Y' && mm[i] == 'Y');
                    counter++;
                }
                if (f) 
                    chmax(ret, counter+2);
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, bool hasAnswer, int p3) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PlatypusPaternity *obj;
	int answer;
	obj = new PlatypusPaternity();
	clock_t startTime = clock();
	answer = obj->maxFamily(p0, p1, p2);
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
	
	vector <string> p0;
	vector <string> p1;
	vector <string> p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"YYYY","YYYY"};
	p1 = {"NNYN","YYYN"};
	p2 = {"YYYN","NNNY"};
	p3 = 5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"NNYYY"};
	p1 = {"YYNNN"};
	p2 = {"YYNNN","NNYYY"};
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"YYYYYYYYN"};
	p1 = {"YYYYYYYYY"};
	p2 = {"YNYNYNYNY","NNNYNYNNN","NYNNNNNYN"};
	p3 = 4;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"YY"};
	p1 = {"YY"};
	p2 = {"YN","NY"};
	p3 = 3;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"YYNNYYNNYYNN","YNYNYNYNYNYN","YYYNNNYYYNNN"};
	p1 = {"NYYNNYYNNYYN","YYNYYYNYYYNY","NNNNNNYYYYYY"};
	p2 = {"NYNNNYNNNNNN","NNNNNNNNYNNN","NNYNNNNNNNYN","YNNNNNNYNNNN","NNNNNNNNNYNY","NNNYYNYNNNNN"};
	p3 = 4;
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
// Our lab has just run into a dilemma. All our data about the lab's platypus population seems to have gotten mixed up. Each platypus in the lab is either a male adult, a female adult, or a child. The children are divided into several sibling groups. We know this division exactly. What we are missing are the parent-child relations. In order to reconstruct these, we conducted some genetic tests. We are going to do what some other lab did 4 years ago and hire you to make a program to help us fix the situation. You will be given three vector <string>s containing the results of these tests and the description of all sibling groups. The three vector <string>s are:
// 
// femaleCompatibility: The j-th character of the i-th element of femaleCompatibility is 'Y' if the i-th female adult is genetically compatible with the j-th child (i.e., the i-th female adult may be the mother of the j-th child). Otherwise, it is 'N'.
// maleCompatibility: The j-th character of the i-th element of maleCompatibility is 'Y' if the i-th male adult is genetically compatible with the j-th child (i.e., the i-th male adult may be the father of the j-th child). Otherwise, it is 'N'.
// siblingGroups: The j-th character of the i-th element of siblingGroups is 'Y' if the j-th child belongs to the i-th sibling group. Otherwise, it is 'N'. Each child belongs into exactly one sibling group. Two children are siblings if and only if they belong to the same sibling group.
// 
// The lab has defined a valid family as a set containing one female adult (mother), one male adult (father), and one sibling group. The mother and the father must be genetically compatible with each of the children in the sibling group. Return the maximum size of a family that follows these conditions or 0 if no such family exists.
// 
// 
// DEFINITION
// Class:PlatypusPaternity
// Method:maxFamily
// Parameters:vector <string>, vector <string>, vector <string>
// Returns:int
// Method signature:int maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups)
// 
// 
// CONSTRAINTS
// -The input will represent data for F females, M males, C children and S sibling groups, with F, M, C and S each being between 1 and 50, inclusive.
// -femaleCompatibility will contain F elements.
// -maleCompatibility will contain M elements.
// -siblingGroups will contain S elements.
// -Each element of femaleCompatibility, maleCompatibility and siblingGroups will contain C characters.
// -Each character of femaleCompatibility, maleCompatibility and siblingGroups will be 'Y' or 'N' (quotes for clarity).
// -For each child j there will be exactly one sibling group i such that siblingGroups[i][j] is 'Y'.
// -For each sibling group i, there will exist at least one child that belongs to that group.
// 
// 
// EXAMPLES
// 
// 0)
// {"YYYY", "YYYY"}
// {"NNYN", "YYYN"}
// {"YYYN", "NNNY"}
// 
// Returns: 5
// 
// One possible family is formed by the female adult 0 (0-indexed), the male adult 1, and the sibling group 0 (containing children 0, 1, and 2).
// The size of this family is: 1 female + 1 male + 3 children = 5 platypuses.
// There is no family of size more than 5.
// Another valid family of size 5 contains the female adult 1 instead of the female adult 0.
// 
// 1)
// {"NNYYY"}
// {"YYNNN"}
// {"YYNNN", "NNYYY"}
// 
// Returns: 0
// 
// Each adult is compatible with a different sibling group. There is no couple that is compatible with the same sibling group
// 
// 2)
// {"YYYYYYYYN"}
// {"YYYYYYYYY"}
// {"YNYNYNYNY",
//  "NNNYNYNNN",
//  "NYNNNNNYN"}
// 
// Returns: 4
// 
// The largest sibling group has size 5. However, there is no valid family that contains this sibling group, as the only available female adult is not compatible with one of the children in this group.
// 
// 3)
// {"YY"}
// {"YY"}
// {"YN", "NY"}
// 
// Returns: 3
// 
// 
// 
// 4)
// {"YYNNYYNNYYNN",
//  "YNYNYNYNYNYN",
//  "YYYNNNYYYNNN"}
// {"NYYNNYYNNYYN",
//  "YYNYYYNYYYNY",
//  "NNNNNNYYYYYY"}
// {"NYNNNYNNNNNN",
//  "NNNNNNNNYNNN",
//  "NNYNNNNNNNYN",
//  "YNNNNNNYNNNN",
//  "NNNNNNNNNYNY",
//  "NNNYYNYNNNNN"}
// 
// Returns: 4
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
