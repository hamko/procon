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

class TheProgrammingContestDivOne {
    public:
        int find(int T, vector <int> p, vector <int> d, vector <int> dt) {
            ll n = p.size();
            vvll pddt(n, vll(3));
            rep(i, n) {
                pddt[i][0] = p[i];
                pddt[i][1] = d[i];
                pddt[i][2] = dt[i];
            }
            sort(all(pddt), [&](vll a, vll b) {
                return a[1]*b[2]>b[1]*a[2];
            });
            cout << pddt << endl;
            vvll dp(n+1, vll(T+1, -INF));
            dp[0][0] = 0;
            rep(i, n) {
                rep(t, T+1) {
                    if (t + pddt[i][2] <= T) {
                        chmax(dp[i+1][t+pddt[i][2]], dp[i][t] + pddt[i][0] - pddt[i][1] * (t + pddt[i][2]));
                    }
                    chmax(dp[i+1][t], dp[i][t]);
                }
            }
            ll ret = 0;
            rep(t, T+1) {
                chmax(ret, dp[n][t]);
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	TheProgrammingContestDivOne *obj;
	int answer;
	obj = new TheProgrammingContestDivOne();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	vector <int> p3;
	int p4;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 74;
	p1 = {502};
	p2 = {2};
	p3 = {47};
	p4 = 408;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 40000;
	p1 = {100000,100000};
	p2 = {1,100000};
	p3 = {50000,30000};
	p4 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 75;
	p1 = {250,500,1000};
	p2 = {2,4,8};
	p3 = {25,25,25};
	p4 = 1200;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 30;
	p1 = {100,100,100000};
	p2 = {1,1,100};
	p3 = {15,15,30};
	p4 = 97000;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
    // ----- test 4 -----
	disabled = false;
	p0 = 75;
	p1 = {250, 500, 1000};
	p2 = {2, 4, 8};
	p3 = {25, 25, 25};
	p4 = 1200;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
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
// Farmer John and Fox Brus are participating in a programming contest as a team.
// 
// 
// The duration of the contest is T minutes and they are given N tasks. Solutions can be submitted at any time during the contest, including exactly T minutes after the start of the contest. If they solve the i-th task immediately after the start of the contest, they get maxPoints[i] points and it decreases by pointsPerMinute[i] points per minute. In other words, if they solve the i-th task t minutes after the start of the contest, they will get maxPoints[i] - t * pointsPerMinute[i] points. It takes them requiredTime[i] minutes to solve the i-th task.
// 
// 
// Return the maximal points they can get.
// 
// DEFINITION
// Class:TheProgrammingContestDivOne
// Method:find
// Parameters:int, vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime)
// 
// 
// CONSTRAINTS
// -T will be between 1 and 100,000, inclusive.
// -maxPoints will contain between 1 and 50 elements, inclusive.
// -maxPoints, pointsPerMinute and requiredTime will contain the same number of elements.
// -Each element of maxPoints will be between 1 and 100,000, inclusive.
// -Each element of pointsPerMinute will be between 1 and 100,000, inclusive.
// -Each element of requiredTime will be between 1 and 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 74
// {502}
// {2}
// {47}
// 
// Returns: 408
// 
// They can solve the task 47 minutes after the start of the contest. They will get 502 - 2 * 47 = 408 points.
// 
// 1)
// 40000
// {100000, 100000}
// {1, 100000}
// {50000, 30000}
// 
// Returns: 0
// 
// They don't have time to solve the first task. If they solve the second task, they will get negative points (100000 - 100000 * 30000 = -2999900000 points), so they shouldn't solve it.
// 
// 2)
// 75
// {250, 500, 1000}
// {2, 4, 8}
// {25, 25, 25}
// 
// Returns: 1200
// 
// 
// First, they can solve the third task 25 minutes after the start of the contest. They get 1000 - 8 * 25 = 800 points.
// Second, they can solve the second task 50 minutes after the start of the contest. They get 500 - 4 * 50 = 300 points.
// Third, they can solve the first task 75 minutes after the start of the contest. They get 250 - 2 * 75 = 100 points.
// 
// In total, they can get 800 + 300 + 100 = 1200 points.
// 
// 3)
// 30
// {100, 100, 100000}
// {1, 1, 100}
// {15, 15, 30}
// 
// Returns: 97000
// 
// The best strategy is solving only the third task.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
