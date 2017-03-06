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

class CaptureFish {
    public:
        string compress(string& fish) {
            string s;
            rep(i, fish.size()) 
                if (s.size() == 0 || s.back() != fish[i])  {
                    s += fish[i];
                }
            return s;
        }
        int getParity(string fish) {
//            string s = compress(fish);
            string s = fish;
            ll n = s.size();
            vll idx;
            rep(i, n) 
                if (s[i] == '*')
                    idx.pb(i);
            string org_s = s;

            ll ret = 0;
            rep(mask, 1ll<<idx.size()) {
                rep(i, idx.size()) 
                    s[idx[i]] = ((mask & (1ll << i)) ? 'O' : 'X');
                if (count(all(s), 'O') == s.length()) 
                    ret++;
                else if (count(all(s), 'X') == s.length()) 
                    ret++;
                else if (compress(s) == "O" || compress(s) == "X" || compress(s) == "OXO" || compress(s) == "XOX") 
                    ret++;
                cout << s << " " << compress(s) << endl;
                s = org_s;
            }
            return ret % 2;
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	CaptureFish *obj;
	int answer;
	obj = new CaptureFish();
	clock_t startTime = clock();
	answer = obj->getParity(p0);
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
	
	string p0;
	int p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = "OXOXO";
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "OO";
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "**OX**";
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "O***O***O***O";
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 3 -----
	disabled = false;
	p0 = "OX";
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
			// ----- test 3 -----
	disabled = false;
	p0 = "OXO";
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
				// ----- test 3 -----
	disabled = false;
	p0 = "XXXXXXOOOOOXXXXX";
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
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
// There are N fish and N+1 buoys in a small pond. Mr. Jeipouju wants to capture some of the fish.
// 
// In this problem, regard the pond as a 2-dimensional Cartesian plane (as seen from above). Each fish and each buoy is a point on the plane.
// The buoys are lined up on x axis and numbered 0 to N from left to right.
// There is exactly one fish between each two neighboring buoys.  The fish are numbered 0 to N-1 from left to right.
// For the purpose of this problem we will assume that the fish are staying on their spots without any movement.
// The exact coordinates of the fish and the buoys do not matter.  See the following image for clarity.
// 
// 
// 
// You are given a string fish with N characters. Each character of fish is either letter 'O' or 'X' or '*'. If fish[i] is 'O', it represents that he must capture fish i. If fish[i] is 'X', he must not capture fish i. If fish[i] is '*', he does not care whether he capture fish i or not.
// 
// To capture the fish, Mr. Jeipouju wants to set up a net in the pond so that the net will separate the caught fishes from the uncaught ones.
// From above, the net must be a closed curve in our plane.
// Furthermore, this closed curve must satisfy the following conditions:
// 
// 
//   The net is not allowed to pass through any of the fish.
//   The net is not allowed to touch or intersect itself.
//   The net may only cross the x axis at points that contain the buoys. The net is not allowed to touch the x axis without crossing it.
//   The net must cross the x axis at least twice.
//   The fish Mr. Jeipouju wants to capture and the fish he wants not to capture must be separated by the net.
//   That is, either all fish marked with 'X' are to be inside the net and all fish marked with 'O' outside, or vice versa. 
//   The fish marked '*' may be anywhere, possibly some of them inside and some outside the net.
// 
// 
// The following image shows some examples of valid and invalid net placements: 4 nets to the left are valid and 5 nets to the right are invalid.
// 
// 
// 
// A net can be encoded into a sequence using the following algorithm:
// 
//   Start anywhere on the net, but not on a buoy.
//   Walk along the net until you reach your starting point again.
//   During the walk, each time you encounter a buoy, write down its number and the halfplane in which you are moving away from the x axis. (The halfplane is "+" if after visiting the buoy your y coordinate is positive and "-" if it is negative.)
// 
// In this way you will obtain some sequence (buoy1,side1,...,buoyK,sideK).
// Two nets are considered the same if they can be encoded to the same sequence.
// 
// Mr. Jeipouju wants to know whether the number of different nets is odd or even.
// Your method must return the number of different nets, modulo 2.
// 
// 
// DEFINITION
// Class:CaptureFish
// Method:getParity
// Parameters:string
// Returns:int
// Method signature:int getParity(string fish)
// 
// 
// CONSTRAINTS
// -fish will contain between 1 and 50 characters, inclusive.
// -Each character of fish will be either letter 'O' or 'X' or '*'.
// -fish will contain at least one 'O' character.
// 
// 
// EXAMPLES
// 
// 0)
// "OXOXO"
// 
// Returns: 0
// 
// In this case, there are 5 fish. There are 8 ways to separate them.
// 
// 
// 
// 1)
// "OO"
// 
// Returns: 1
// 
// There is only one valid net and it looks as follows:
// 
// 
// 
// Two things to notice:
// First, the net does not have to pass through all the buoys.
// Second, it is allowed to have no fish at all at either side of the net.
// 
// 2)
// "**OX**"
// 
// Returns: 0
// 
// 
// 
// 3)
// "O***O***O***O"
// 
// Returns: 1
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
