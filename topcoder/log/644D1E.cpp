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

class OkonomiyakiParty {
    public:
        static const int M = 55;
        ll dp[M][M][M];
        int count(vector <int> a, int m, int k) {
            ll n = a.size();
            sort(all(a));
            rep(i, M) rep(j, M) rep(h, M) dp[i][j][h] = 0;
            dp[0][0][M-1] = 1;
            rep(i, n) rep(j, m + 1) rep(h, M) {
                if (j == 1 && h == M-1) 
                    (dp[i+1][j][i] = 1) %= mo;
                if (j > 1 && abs(a[i] - a[h]) <= k) 
                    (dp[i+1][j][h] += dp[i][j-1][h]) %= mo;
                (dp[i+1][j][h] +=  dp[i][j][h]) %= mo;
            }

            ll ret = 0;
            rep(h, n) 
                (ret += dp[n][m][h]) %= mo;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	OkonomiyakiParty *obj;
	int answer;
	obj = new OkonomiyakiParty();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2);
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
	
	vector <int> p0;
	int p1;
	int p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,4,6,7,9};
	p1 = 2;
	p2 = 3;
	p3 = 6;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,6,2,7,4,2,6,1,5,2,4};
	p1 = 4;
	p2 = 3;
	p3 = 60;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,4,5,7,10,11,13,16,18};
	p1 = 4;
	p2 = 5;
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {55,2,7,232,52,5,5332,623,52,6,532,5147};
	p1 = 6;
	p2 = 10000;
	p3 = 924;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,5682,7775,4356,5140,8923,9801,3729};
	p1 = 15;
	p2 = 4003;
	p3 = 114514;
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
// Wolf Sothe is planning a party for his M friends.
// He wants to give them some okonomiyaki at the party.
// (Okonomiyaki is a Japanese pancake.)
// 
// Sothe just came to an okonomiyaki restaurant.
// The restaurant makes several types of okonomiyaki.
// Each type of okonomiyaki has its specific size.
// You are given the sizes of all okonomiyaki types as a vector <int> osize.
// 
// Sothe would like to buy exactly M okonomiyaki.
// They must all have different types, so that the people at the party have the most options to choose from.
// Additionally, they must all have roughly the same sizes, so that nobody feels disappointed.
// More precisely, the difference between the size of the largest and smallest okonomiyaki ordered by Sothe must be K or less.
// 
// You are given the vector <int> osize and the ints M and K.
// Compute and return the number of different orders Sothe could place at the restaurant, modulo 1,000,000,007.
// 
// DEFINITION
// Class:OkonomiyakiParty
// Method:count
// Parameters:vector <int>, int, int
// Returns:int
// Method signature:int count(vector <int> osize, int M, int K)
// 
// 
// CONSTRAINTS
// -osize will contain between 2 and 50 elements, inclusive.
// -Each element in osize will be between 1 and 10,000, inclusive.
// -M will be between 2 and the number of elements in osize, inclusive.
// -K will be between 1 and 10,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,4,6,7,9}
// 2
// 3
// 
// Returns: 6
// 
// There are five types of okonomiyaki.
// Let's call them types A, B, C, D, and E.
// (Type A has size 1, type B has size 4, and so on.)
// Sothe wants to buy M=2 different okonomiyaki and their sizes must differ by K=3 or less.
// There are 6 valid orders: A+B, B+C, B+D, C+D, C+E, and D+E.
// 
// Note that B+A is the same order as A+B: you get one pancake of type A and one pancake of type B.
// 
// 1)
// {1,6,2,7,4,2,6,1,5,2,4}
// 4
// 3
// 
// Returns: 60
// 
// Different types of okonomiyaki may have equal sizes.
// An order may contain multiple okonomiyaki of the same size, they are only required to have different types.
// 
// 2)
// {1,4,5,7,10,11,13,16,18}
// 4
// 5
// 
// Returns: 0
// 
// In this test case there is no valid order: regardless of which 4 pancakes Sothe wants, the difference between their sizes will be too large.
// 
// 3)
// {55,2,7,232,52,5,5332,623,52,6,532,5147}
// 6
// 10000
// 
// Returns: 924
// 
// 
// 
// 4)
// {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
// 1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
// 5682,7775,4356,5140,8923,9801,3729}
// 15
// 4003
// 
// Returns: 114514
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
