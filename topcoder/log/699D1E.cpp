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

class OthersXor {
    public:
        long long minSum(vector <int> x) {
            ll q = count(all(x), -1);
            ll res = 0;
            rep(b, 30) {
                vll memo(2);
                rep(i, x.size()) if (x[i] != -1) 
                    memo[(x[i]>>b)&1]++;

                ll ret = INF;
                if (q == 0) {
                    if (memo[1] % 2 == 0) chmin(ret, memo[1]);
                    if (memo[0] % 2 == 1) chmin(ret, memo[0]);
                    if (ret == INF) return -1;
                } else {
                    chmin(ret, (memo[1] % 2 ? memo[1] + 1 : memo[1])); // 全体が偶数
                    chmin(ret, (memo[0] % 2 ? memo[0] : memo[0] + 1)); // 全体が奇数
                }
                cout << b << " " << ret << endl;
                res += ret << b;
            }
            return res;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	OthersXor *obj;
	long long answer;
	obj = new OthersXor();
	clock_t startTime = clock();
	answer = obj->minSum(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <int> p0;
	long long p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,-1,3};
	p1 = 3ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {0,0,1};
	p1 = -1ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {70,100};
	p1 = 170ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {-1,0,-1,100,36};
	p1 = 164ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,1073741823,1073741823,1073741823,123456789,987654321,804289383};
	p1 = 11992352010ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703};
	p1 = -1ll;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = {-1,-1};
	p1 = 0ll;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, true, p1) ) && all_right;
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
// N wolves are going to challenge bear Limak.
// Each wolf chooses an integer between 0 and 2^30-1, inclusive, and shows it to all other wolves.
// No wolf is going to reveal their own number to Limak.
// Some wolves may remain completely silent, some may give Limak some information.
// The only information a wolf will tell Limak is the bitwise xor of the numbers of all N-1 other wolves (i.e., all wolves except for the wolf who gives this particular information).
// 
// Limak's goal is to find the sum of the numbers chosen by the wolves.
// If there are multiple sums that are consistent with the information Limak was given, he wants to find the smallest of them.
// 
// You are given a vector <int> x with N elements.
// Each element of x represents one of the wolves.
// If x[i] equals -1, wolf i remained silent.
// Otherwise, wolf i announced that the bitwise xor of the other wolves' numbers is x[i].
// 
// If there is at least one sequence of integers between 0 and 2^30-1, inclusive, that is consistent with the information given by the wolves, return the smallest possible sum of such a sequence of numbers. Otherwise, return -1.
// 
// DEFINITION
// Class:OthersXor
// Method:minSum
// Parameters:vector <int>
// Returns:long long
// Method signature:long long minSum(vector <int> x)
// 
// 
// CONSTRAINTS
// -N will be between 2 and 40, inclusive.
// -x will contain exactly N elements.
// -Each element in x will be between -1 and 1073741823 (i.e. 2^30-1), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,-1,3}
// 
// Returns: 3
// 
// There are many scenarios that are consistent with this information.
// For example, it is possible that the wolves chose the numbers {15, 12, 13}.
// Wolf 0 announces (12 xor 13) = 1, and wolf 2 announces (15 xor 12) = 3.
// In this case, the sum of the wolves' numbers would be 15+12+13 = 40.
// 
// However, the sum 40 is not the smallest sum possible.
// The optimal solution looks as follows:
// The wolves chose the numbers {2, 1, 0}.
// Wolf 0 announces (1 xor 0) = 1, and wolf 2 announces (2 xor 1) = 3.
// The sum in this case is only 2+1+0 = 3, and it can be shown that this is the smallest sum that can be obtained.
// 
// 1)
// {0,0,1}
// 
// Returns: -1
// 
// 
// 
// 2)
// {70,100}
// 
// Returns: 170
// 
// In the only possible scenario wolves choose numbers 100 and 70, resulting in xors 70 and 100.
// 
// 3)
// {-1,0,-1,100,36}
// 
// Returns: 164
// 
// 
// 
// 4)
// {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
// 0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
// 1073741823,1073741823,1073741823,123456789,987654321,804289383}
// 
// Returns: 11992352010
// 
// 
// 
// 5)
// {1287325,424244444,92759185,812358213,1000000000,825833522,749092703}
// 
// Returns: -1
// 
// 
// 
// 6)
// {-1,-1}
// 
// Returns: 0
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
