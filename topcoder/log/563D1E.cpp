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

class FoxAndHandle {
    public:
        string lexSmallestName(string ss) {
            ll n = ss.size() / 2;
            map<char, ll> fss;
            rep(i, 2*n) {
                fss[ss[i]]++;
            }
            for (auto&& x : fss) {
                x.se /= 2;
            }
            string ret;
            ll pos = 0; // looking at ss[pos, 2*n)
            rep(i, n) {
//                cout << i << " " << fss << endl;
                for (auto&& x : fss) if (x.se) {
                    char c = x.fi;
                    x.se--;
                    ll j = pos;
                    while (ss[j] != c) j++;
                    // ss[j] == c
                    // freq(j, 2*n) >= fss
                    map<char, ll> freq;
                    repi(h, j+1, 2*n) {
                        freq[ss[h]]++;
                    }
                    ll faf = 1;
                    for (auto x : fss) {
                        faf &= freq[x.fi] >= x.se;
                    }
                    if (faf) {
                        pos = j+1;
                        ret += c;
                        break;
                    } 
                    x.se++;
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	FoxAndHandle *obj;
	string answer;
	obj = new FoxAndHandle();
	clock_t startTime = clock();
	answer = obj->lexSmallestName(p0);
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
	p0 = "foxfox";
	p1 = "fox";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "ccieliel";
	p1 = "ceil";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "abaabbab";
	p1 = "aabb";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "bbbbaaaa";
	p1 = "bbaa";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "fedcbafedcba";
	p1 = "afedcb";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = "nodevillivedon";
	p1 = "deilvon";
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
// We say that a string Z can be obtained by shuffling two strings X and Y together, if it is possible to interleave the letters of X and Y so that Z is obtained. It is not allowed to change the order of letters in X and Y.
// For example, you can shuffle the strings X="abcd" and Y="efg" to produce any of the strings "abcdefg", "aebfcgd", "abcefgd", or "eabcfdg", but you cannot produce the string "bacdefg".
// 
// 
// 
// Formally, let Shuffle(X,Y) be the set of all strings that can be produced by shuffling X and Y together.
// We can define Shuffle inductively as follows:
// 
// for any string X: Shuffle("",X) = Shuffle(X,"") = { X }
// for any letters a, b and any strings X, Y:
// Shuffle(aX,bY) = { aZ : Z belongs to Shuffle(X,bY) } united with { bZ : Z belongs to Shuffle(aX,Y) }.
// 
// 
// 
// 
// Fox Ciel wants to register on TopCoder.
// In order to do that, she has to pick a handle.
// Ciel has a pet cat called S.
// As her handle, Ciel wants to use a string H with the following property:
// S can be obtained by shuffling H and some permutation of H together.
// For example, if S="ceiiclel", one possible handle would be H="ciel":
// she can permute H to obtain H'="eicl", and then shuffle these H and H' together to produce S.
// 
// 
// 
// You are given the string S.
// The constraints guarantee that there is at least one possible handle H with the above property.
// Find and return the lexicographically smallest valid H.
// 
// DEFINITION
// Class:FoxAndHandle
// Method:lexSmallestName
// Parameters:string
// Returns:string
// Method signature:string lexSmallestName(string S)
// 
// 
// CONSTRAINTS
// -S will contain between 2 and 50 characters, inclusive.
// -Each character of S will be a lowercase letter ('a'-'z').
// -Each letter ('a'-'z') will occur in S an even number of times.
// 
// 
// EXAMPLES
// 
// 0)
// "foxfox"
// 
// Returns: "fox"
// 
// There are five possible handles for Fox Ciel in this test case: "fox", "fxo", "ofx", "oxf", and "xfo".
// The lexicographically smallest one is "fox".
// 
// 1)
// "ccieliel"
// 
// Returns: "ceil"
// 
// Note that "ciel" is also a valid handle, but "ceil" is lexicographically smaller.
// 
// 2)
// "abaabbab"
// 
// Returns: "aabb"
// 
// 
// 
// 3)
// "bbbbaaaa"
// 
// Returns: "bbaa"
// 
// 
// 
// 4)
// "fedcbafedcba"
// 
// Returns: "afedcb"
// 
// 
// 
// 5)
// "nodevillivedon"
// 
// Returns: "deilvon"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
