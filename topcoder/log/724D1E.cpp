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

class OrAndSum {
    public:
        string isPossible(vector<long long> o, vector<long long> s) {
            ll n = o.size();
            vll a(n);
 	           rep(i, n) {
                a[i] = s[i] - o[i];
                if (a[i] < 0) return "Impossible";
            }
            rep(d, 63) {
                vll x, y;
                rep(i, n) {
                    x.pb(!!(o[i] & (1ll<<d)));
                    y.pb(!!(a[i] & (1ll<<d)));
                }
                rep(i, x.size()) {
                    if (x[i] == 0 && y[i] == 1) {
                        return "Impossible";
                    }
                }
                vll tmp(x.size()+1, -1);
                rep(i, x.size()) {
                    if (tmp[i] == -1) {
                        if (x[i] == 0 && y[i] == 0) {
                            tmp[i] = tmp[i+1] = 0;
                        } else if (x[i] == 1 && y[i] == 1) {
                            tmp[i] = tmp[i+1] = 1;
                        } else {
                            tmp[i] = tmp[i+1] = -1;
                        }
                    } else if (tmp[i] == 0) {
                        if (x[i] == 0 && y[i] == 0) {
                            tmp[i] = tmp[i+1] = 0;
                        } else if (x[i] == 1 && y[i] == 1) {
                            return "Impossible";
                        } else {
                            tmp[i+1] = 1;
                        }
                    } else if (tmp[i] == 1) {
                        if (x[i] == 0 && y[i] == 0) {
                            return "Impossible";
                        } else if (x[i] == 1 && y[i] == 1) {
                            tmp[i] = tmp[i+1] = 1;
                        } else {
                            tmp[i+1] = 0;
                        }
                    } else {
                        exit(1);
                    }
                }
            }
            return "Possible";
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
bool KawigiEdit_RunTest(int testNum, vector<long long> p0, vector<long long> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	OrAndSum *obj;
	string answer;
	obj = new OrAndSum();
	clock_t startTime = clock();
	answer = obj->isPossibleA(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	vector<long long> p0;
	vector<long long> p1;
	string p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {7ll};
	p1 = {11ll};
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {11ll};
	p1 = {7ll};
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {3ll,3ll,7ll,5ll,7ll};
	p1 = {3ll,5ll,7ll,9ll,11ll};
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1ll,100ll,1000ll};
	p1 = {100ll,1000ll,10000ll};
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {261208776456074191ll,261208776456074191ll,261208776456074191ll};
	p1 = {333333333333333333ll,333333333333333333ll,333333333333333333ll};
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {0ll};
	p1 = {0ll};
	p2 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
		// ----- test 5 -----
	disabled = false;
	p0 = {0, 1, 0};
	p1 = {0, 1, 0};
	p2 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 5 -----
	disabled = false;
	p0 = {1, 1, 1};
	p1 = {2, 1, 2};
	p2 = "Impossible";
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
// You are given two vector<long long>s: pairOr and pairSum.
// Each of these arrays will contain n non-negative integers.
// 
// 
// Determine whether it is possible to construct a sequence x[0], ..., x[n] of nonnegative integers with the following properties:
// 
// for each i between 0 and n-1, inclusive, x[i] or x[i+1] = pairOr[i]
// for each i between 0 and n-1, inclusive, x[i] + x[i+1] = pairSum[i]
// 
// 
// Note that the sequence x should contain n+1 elements: one more than the length of each of the given arrays.
// 
// 
// Return "Possible" if we can find at least one such sequence x, and "Impossible" if not.
// 
// DEFINITION
// Class:OrAndSum
// Method:isPossible
// Parameters:vector<long long>, vector<long long>
// Returns:string
// Method signature:string isPossible(vector<long long> pairOr, vector<long long> pairSum)
// 
// 
// CONSTRAINTS
// -pairOr will contain between 1 and 50 elements, inclusive.
// -pairOr and pairSum will contain the same number of elements.
// -Each element in pairOr will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
// -Each element in pairSum will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {7}
// {11}
// 
// Returns: "Possible"
// 
// One of the solutions is {5,6}.
// 
// 1)
// {11}
// {7}
// 
// Returns: "Impossible"
// 
// The sum of two numbers will always be greater than or equal to their bitwise or.
// 
// 2)
// {3,3,7,5,7}
// {3,5,7,9,11}
// 
// Returns: "Possible"
// 
// One of the solutions is {1,2,3,4,5,6}.
// 
// 3)
// {1,100,1000}
// {100,1000,10000}
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// {261208776456074191,261208776456074191,261208776456074191}
// {333333333333333333,333333333333333333,333333333333333333}
// 
// Returns: "Possible"
// 
// 
// 
// 5)
// {0}
// {0}
// 
// Returns: "Possible"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
