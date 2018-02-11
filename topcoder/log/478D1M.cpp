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

class KiwiJuice {
    public:
        int theProfit(int c_, vector <int> a_, vector <int> p_) {
            ll c = c_;
            vll a = conv(a_);
            vll p = conv(p_);
            ll n = a.size();
            function<ll(ll)> profit = [&](ll mask) {
                ll s = 0;
                rep(i, n) if (mask & (1ll << i)) {
                    s += a[i];
                }
                ll bottle_num = __builtin_popcountll(mask);
                ll full = s / c;
                ll mid = !!(s % c);
                ll emp = bottle_num - full - mid;
                ll ret = full * p[c] + mid * p[s%c]
                    + p[0] * emp;
                return ret;
            };

            // dp[S] = Sをいい感じに部分分割したときの最大利益
            ll dp[1<<15] = {};
            rep(i, 1<<n) {
                dp[i] = profit(i);
            }
            rep(mask, 1<<n) {
                for (ll i = mask; i > 0; i=(i-1)&mask) {
                    if (i == mask) continue;
                    chmax(dp[mask], dp[i] + dp[i ^ mask]);
                }
            }
            return dp[(1ll<<n)-1];
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	KiwiJuice *obj;
	int answer;
	obj = new KiwiJuice();
	clock_t startTime = clock();
	answer = obj->theProfit(p0, p1, p2);
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
	
	int p0;
	vector <int> p1;
	vector <int> p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 10;
	p1 = {5};
	p2 = {1,2,3,4,5,6,7,8,0,0,10};
	p3 = 6;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 10;
	p1 = {5,8};
	p2 = {0,0,0,0,0,10,10,10,10,10,10};
	p3 = 20;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 10;
	p1 = {4,5,3,7};
	p2 = {14,76,12,35,6,94,26,3,93,90,420};
	p3 = 625;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 1;
	p1 = {0};
	p2 = {1000000,1000000};
	p3 = 1000000;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 49;
	p1 = {2,47,24,14,0,32,9,12,31,46,39,12,16,22,29};
	p2 = {428668,995687,128567,37241,496916,238624,304781,997819,85856,417008,398570,951499,750349,333625,927594,188616,942498,259414,654344,354809,25303,226854,98578,207140,305527,358343,393213,256248,282644,103327,667191,103402,609183,619323,189127,518006,778846,400460,128334,795097,605203,669142,121825,934404,837430,554265,610818,546228,80784,949440};
	p3 = 12873962;
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
// Taro has prepared delicious kiwi fruit juice. He poured it into N bottles numbered from 0 to N-1. Each bottle has a capacity of C liters, and he poured bottles[i] liters of kiwi juice into the i-th bottle initially. Taro will sell these bottles after performing an arbitrary number of operations of the following type (possibly zero). In each operation, he chooses two distinct bottles A and B, and pours kiwi juice from bottle A to bottle B until either bottle A becomes empty or bottle B becomes full, whichever happens earlier.
// 
// 
// If a bottle contains x liters of kiwi juice at the end (where x is an integer between 0 and C, inclusive), then Taro can sell the bottle for prices[x] dollars. Return the maximum amount of money he can earn.
// 
// 
// 
// DEFINITION
// Class:KiwiJuice
// Method:theProfit
// Parameters:int, vector <int>, vector <int>
// Returns:int
// Method signature:int theProfit(int C, vector <int> bottles, vector <int> prices)
// 
// 
// CONSTRAINTS
// -C will be between 1 and 49, inclusive.
// -bottles will contain between 1 and 15 elements, inclusive.
// -Each element of bottles will be between 0 and C, inclusive.
// -prices will contain exactly C + 1 elements.
// -Each element of prices will be between 0 and 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 10
// {5, 8}
// {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10}
// 
// Returns: 10
// 
// If Taro pours kiwi juice from bottle 0 to bottle 1, then bottle 0 will contain 3 liters of kiwi juice and bottle 1 will contain 10 liters of kiwi juice. He can sell bottle 1 for 10 dollars.
// 
// 1)
// 10
// {5, 8}
// {0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10}
// 
// Returns: 20
// 
// Sell both bottles without pouring.
// 
// 2)
// 10
// {4, 5, 3, 7}
// {14, 76, 12, 35, 6, 94, 26, 3, 93, 90, 420}
// 
// Returns: 625
// 
// It is possible that a bottle containing lesser juice is more expensive.
// 
// 3)
// 1
// {0}
// {1000000, 1000000}
// 
// Returns: 1000000
// 
// 
// 
// 4)
// 49
// {2, 47, 24, 14, 0, 32, 9, 12, 31, 46, 39, 12, 16, 22, 29}
// {428668, 995687, 128567, 37241, 496916, 238624, 304781, 997819, 85856, 417008,
// 398570, 951499, 750349, 333625, 927594, 188616, 942498, 259414, 654344, 354809,
// 25303, 226854, 98578, 207140, 305527, 358343, 393213, 256248, 282644, 103327,
// 667191, 103402, 609183, 619323, 189127, 518006, 778846, 400460, 128334, 795097,
// 605203, 669142, 121825, 934404, 837430, 554265, 610818, 546228, 80784, 949440}
// 
// Returns: 12873962
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
