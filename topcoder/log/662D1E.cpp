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
#define forall(a, f) all_of((a).begin(), (a).end(), (f))
#define exists(it, a, f) (((it)=find_if((a).begin(), (a).end(), (f)))!=(a).end())

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;

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
#define ldout fixed << setprecision(40) 

template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); return s; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }

class FoxesOfTheRoundTable {
    public:
        vector <int> minimalDifference(vector <int> h) {
            ll n = h.size();
            vector<P> hi; 
            rep(i, n) 
                hi.pb(P(h[i], i));
            sort(all(hi)); 

            vector<P> v1, v2;
            rep(i, n) if (i & 1) v1.pb(hi[i]);
            rep(i, n) if (!(i & 1)) v2.pb(hi[i]);
            reverse(all(v2));

            vector<int> ret;
            for (auto x : v1) ret.pb(x.se);
            for (auto x : v2) ret.pb(x.se);
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	FoxesOfTheRoundTable *obj;
	vector <int> answer;
	obj = new FoxesOfTheRoundTable();
	clock_t startTime = clock();
	answer = obj->minimalDifference(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,99,50,50};
	p1 = {0,3,1,2};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {123,456,789};
	p1 = {0,1,2};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {10,30,40,50,60};
	p1 = {0,1,4,3,2};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,2,3,4,8,12,13,14};
	p1 = {0,1,2,3,5,6,7,4};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	p1 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// There are n foxes, numbered 0 through n-1.
// You are given a vector <int> h with n elements.
// The elements of h are the heights of those foxes.
// Your task is to arrange all foxes around a round table.
// 
// 
// Given an arrangement of foxes, let D be the largest height difference between adjacent foxes.
// For example, suppose that four foxes with heights { 10, 30, 20, 40 } sit around the table in this order.
// The height differences are |10-30|=20, |30-20|=10, |20-40|=20, and |40-10|=30.
// (Note that the last fox is also adjacent to the first one, as this is a round table.)
// Then, the value D is max(20,10,20,30) = 30.
// 
// 
// Find an arrangement of the given foxes for which the value D is as small as possible.
// Return a permutation of foxes that describes your arrangement.
// I.e., return a vector <int> with n elements: the numbers of foxes in order around the table.
// If there are multiple optimal solutions, you may return any of them.
// 
// DEFINITION
// Class:FoxesOfTheRoundTable
// Method:minimalDifference
// Parameters:vector <int>
// Returns:vector <int>
// Method signature:vector <int> minimalDifference(vector <int> h)
// 
// 
// CONSTRAINTS
// -h will contain between 3 and 50 elements, inclusive.
// -Each element in h will be between 1 and 1,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,99,50,50}
// 
// Returns: {0, 3, 1, 2 }
// 
// In the optimal solution the foxes with heights 1 and 99 mustn't be adjacent.
// Hence, the heights of foxes have to be 1, 50, 99, 50, in this cyclic order, and the optimal value of D is 49.
// One permutation that produces this order of foxes is 0, 3, 1, 2.
// 
// 1)
// {123,456,789}
// 
// Returns: {0, 1, 2 }
// 
// Whatever we do, the result will always be 789-123.
// 
// 2)
// {10,30,40,50,60}
// 
// Returns: {0, 1, 4, 3, 2 }
// 
// The permutation {0, 1, 4, 3, 2 } specifies that the heights of foxes are in the following order: 10, 30, 60, 50, 40.
// 
// 3)
// {1,2,3,4,8,12,13,14 }
// 
// Returns: {0, 1, 2, 3, 5, 6, 7, 4 }
// 
// 
// 
// 4)
// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
// 
// Returns: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
