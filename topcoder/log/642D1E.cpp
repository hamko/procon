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

class WaitingForBus {
    public:
        double whenWillBusArrive(vector <int> t, vector <int> p, int s) {
            if (!s) return 0;
            vector<double> dp(1000000); dp[0] = 1;
            rep(i, s) {
                rep(j, t.size()) {
                    ll next = i + t[j];
                    if (next >= dp.size()) continue;
                    dp[next] += dp[i] * (double)p[j] / 100.0;
                }
            }
            double ret = 0;
            for (ll i = s; i < dp.size(); i++) 
                ret += dp[i] * (double)(i - s);
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, double p3) {
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
	cout << "}" << "," << p2;
	cout << "]" << endl;
	WaitingForBus *obj;
	double answer;
	obj = new WaitingForBus();
	clock_t startTime = clock();
	answer = obj->whenWillBusArrive(p0, p1, p2);
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
		res = answer == answer && fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	vector <int> p1;
	int p2;
	double p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {5,100};
	p1 = {90,10};
	p2 = 5;
	p3 = 9.5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {5};
	p1 = {100};
	p2 = 101;
	p3 = 4.0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {5,10};
	p1 = {50,50};
	p2 = 88888;
	p3 = 3.666666666666667;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,2,3,4};
	p1 = {10,20,30,40};
	p2 = 1000;
	p3 = 1.166666666666667;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {10,100,1000,10000,100000};
	p1 = {90,4,3,2,1};
	p2 = 100000;
	p3 = 21148.147303578935;
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
// 
// The bus station in Joseph's town operates randomly.
// Before the bus station opens, there are N buses at the station.
// The buses are numbered 0 through N-1.
// Whenever a bus has to depart the station, one of these buses is chosen at random.
// Different buses may be chosen with different probabilities.
// More precisely, for each i, the probability that bus i will be chosen is prob[i]/100.
// After bus i departs the station, it follows its specific route.
// The time the bus needs to complete its route is time[i].
// 
// 
// 
// The bus station opens at time 0.
// At that time, the first random bus will depart.
// During the day, as soon as a bus returns from its route, a new bus is randomly chosen to depart in that same moment.
// (The probability distribution is the same for each random choice, and the random choices are mutually independent.
// It is possible that the bus chosen to depart will again be the bus that just arrived.)
// 
// 
// 
// Joseph just arrived to the bus station.
// The current time is s.
// He is going to wait for the next bus.
// (If there is a bus departing precisely at the time s, Joseph can still catch it.
// In this case, his waiting time is zero.)
// 
// 
// 
// You are given the vector <int>s time and prob, and the int s.
// Return Joseph's expected waiting time.
// 
// 
// DEFINITION
// Class:WaitingForBus
// Method:whenWillBusArrive
// Parameters:vector <int>, vector <int>, int
// Returns:double
// Method signature:double whenWillBusArrive(vector <int> time, vector <int> prob, int s)
// 
// 
// NOTES
// -Your return value must have an absolute or relative error smaller than 1e-6
// 
// 
// CONSTRAINTS
// -time will contain between 1 and 100 elements, inclusive.
// -prob will contain the same number of elements as time
// -Each element of time will be between 1 and 10^5, inclusive.
// -Each element of prob will be between 1 and 100, inclusive.
// -The sum of all elements of prob will be exactly 100. 
// -s will be between 0 and 10^5, inclusive. 
// 
// 
// EXAMPLES
// 
// 0)
// {5,100}
// {90,10}
// 5
// 
// Returns: 9.5
// 
// 
// Joseph will arrive to the bus station at time 5.
// At time 0, one of the two buses was chosen.
// With probability 90% it was bus 0.
// This bus will return to the station at time 5.
// Therefore, a new bus will be chosen to depart at time 5 and Joseph can board it immediately.
// With probability 10% the bus that departed the station at time 0 was bus 1.
// If this was the case, the next bus will depart the station at time 100, which means that Joseph's waiting time will be 95.
// Thus, the expected waiting time is 0.9 * 0 + 0.1 * 95 = 9.5.
// 
// 
// 1)
// {5}
// {100}
// 101
// 
// Returns: 4.0
// 
// 
// 
// 2)
// {5,10}
// {50,50}
// 88888
// 
// Returns: 3.666666666666667
// 
// 
// 
// 3)
// {1,2,3,4}
// {10,20,30,40}
// 1000
// 
// Returns: 1.166666666666667
// 
// 
// 
// 4)
// {10,100,1000,10000,100000}
// {90,4,3,2,1}
// 100000
// 
// Returns: 21148.147303578935
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
