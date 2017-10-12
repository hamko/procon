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

class TCPhoneHome {
    public:
        ll n;
        vvll g;
        ll d;
        vll pow10;
        vector<string> nodes;
        ll dfs(ll v, ll p, ll depth) {
            if (!g[v].size()) return pow10[d - depth];
            ll ret = 0;
            for (auto x : g[v]) if (x != p) {
                ret += dfs(x, v, depth+1);
            }
            return ret;
        }
        long long validNumbers(int d_, vector <string> a) {
            d = d_;
            n = a.size();
            sort(all(a));
            ll tmp = 1;
            pow10.clear();
            rep(i, 18) {
                pow10.pb(tmp);
                tmp*=10;
            }
            if (a.size() == 0) {
                return pow10[d];
            }
            set<string> s, t; 
            t.insert("");
            rep(i, n) {
                string cand = a[i];
                ll found = 0;
                rep(j, cand.size()-1) {
                    if (s.count(cand.substr(0, j+1))) {
                        found = 1;
                        break;
                    }
                }
                if (found) continue;
                s.insert(cand);
                rep(j, cand.size()) {
                    if (!t.count(cand.substr(0, j+1))) {
                        t.insert(cand.substr(0, j+1));
                    }
                }
            }

            nodes = vector<string>(all(t));
            n = nodes.size();
            g.resize(n);
            rep(i, n) rep(j, n) if (i < j) {
                if (nodes[i].size() + 1 == nodes[j].size() && nodes[i] == nodes[j].substr(0, nodes[i].size())) {
                    g[i].pb(j);
                }
            }

            ll ret = dfs(0, -1, 0);


            return pow10[d] - ret;
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TCPhoneHome *obj;
	long long answer;
	obj = new TCPhoneHome();
	clock_t startTime = clock();
	answer = obj->validNumbers(p0, p1);
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
	
	int p0;
	vector <string> p1;
	long long p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 7;
	p1 = {"0","1","911"};
	p2 = 7990000ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 10;
	p1 = {"0","1","911"};
	p2 = 7990000000ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 8;
	p1 = {"1","12","123"};
	p2 = 90000000ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 9;
	p1 = {"12","13","14"};
	p2 = 970000000ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 3;
	p1 = {"411"};
	p2 = 999ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 4 -----
	disabled = false;
	p0 = 17;
	p1 = {"1","2","3","4","5","6","7","8","9","0"};
	p2 = 999ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
			// ----- test 4 -----
	disabled = false;
	p0 = 1;
	p1 = {"2","3","4","5","6","7","8","9","0"};
	p2 = 999ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		disabled = false;
	p0 = 1;
	p1 = {};
	p2 = 10ll;
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
// Typically, telephone numbers are sequences of digits (0-9) that all have the same length.
// However, some prefixes may be reserved for special purposes.
// This limits the total number of possible full-length telephone numbers that are available for general use in the system.
// 
// As an example, in much of the United States and Canada the local telephone numbers are 7 digits long.
// However, dialing 1 starts a special sequence for long distance, dialing 0 connects to the operator, and dialing 911 connects to emergency services.
// Thus, there are fewer than the theoretical 10,000,000 possible valid telephone numbers.
// 
// You are given the int digits: the length of the standard telephone numbers in the system.
// You are also given a vector <string> specialPrefixes.
// Each element of specialPrefixes is a string of digits that defines one reserved prefix.
// Standard telephone numbers cannot start with any of the reserved prefixes.
// 
// Compute and return the number of different standard telephone numbers in the system.
// 
// 
// DEFINITION
// Class:TCPhoneHome
// Method:validNumbers
// Parameters:int, vector <string>
// Returns:long long
// Method signature:long long validNumbers(int digits, vector <string> specialPrefixes)
// 
// 
// CONSTRAINTS
// -digits will be between 1 and 17, inclusive.
// -specialPrefixes will contain beteween 0 and 50 elements, inclusive.
// -The length of each element of specialPrefixes will be between 1 and digits, inclusive.
// -Each character of each element of specialPrefixes will be a digit ('0'...'9').
// -No two elements of specialPrefixes will be the same.
// 
// 
// EXAMPLES
// 
// 0)
// 7
// {"0", "1", "911"}
// 
// Returns: 7990000
// 
// The example from the problem statement.
// 
// 1)
// 10
// {"0", "1", "911"}
// 
// Returns: 7990000000
// 
// Same prefixes, longer numbers.
// 
// 2)
// 8
// {"1", "12", "123"}
// 
// Returns: 90000000
// 
// The sets of numbers reserved by different special prefixes may sometimes overlap.
// For example, in this case the net effect of these three special prefixes is that all numbers that start with "1" are reserved.
// 
// 3)
// 9
// {"12", "13", "14"}
// 
// Returns: 970000000
// 
// 
// 
// 4)
// 3
// {"411"}
// 
// Returns: 999
// 
// Sometimes a "prefix" is actually a full length phone number that is specially reserved for some reason.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
