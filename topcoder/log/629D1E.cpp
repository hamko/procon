#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

class RectangleCovering {
    public:
        int minimumNumber(int h, int w, vector <int> bh, vector <int> bw) {
            ll n = bh.size();
            
            ll ret = INF;
            rep(_, 2) {
                swap(h, w);
                ll s = 0;
                ll m = 0;
                vll d(n);
                rep(i, n) {
                    d[i] = max<ll>(bh[i] > h ? bw[i] : 0, bw[i] > h ? bh[i] : 0);
                }
                sort(all(d), greater<ll>());
                rep(i, n) {
                    s += d[i];
                    m++;
                    if (s >= w) {
                        chmin(ret, m);
                        break;
                    }
                }
            }
            return (ret == INF ? -1 : ret);
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
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
	RectangleCovering *obj;
	int answer;
	obj = new RectangleCovering();
	clock_t startTime = clock();
	answer = obj->minimumNumber(p0, p1, p2, p3);
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
	int p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 5;
	p1 = 5;
	p2 = {8,8,8};
	p3 = {2,3,4};
	p4 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 10;
	p1 = 10;
	p2 = {6,6,6,6};
	p3 = {6,6,6,6};
	p4 = -1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 5;
	p1 = 5;
	p2 = {5};
	p3 = {5};
	p4 = -1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 3;
	p1 = 5;
	p2 = {6};
	p3 = {4};
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 10000;
	p1 = 5000;
	p2 = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25};
	p3 = {1442,2448,42,1818,3535,3333,3456,7890,1,52};
	p4 = 3;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
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
// There is a rectangular hole in the ground.
// You are given the dimensions of this rectangle: ints holeH and holeW.
// 
// 
// 
// You have a collection of rectangular boards.
// You are given their dimensions as two vector <int>s: boardH and boardW.
// For each valid i, you have a rectangular board with dimensions boardH[i] and boardW[i].
// You would like to cover the hole completely, using as few of these boards as possible.
// 
// 
// 
// There are some rules you must follow when covering the hole:
// 
// The boards may overlap arbitrarily.
// Together, the boards must cover the entire hole.
// You may rotate each board, but you must place it so that the sides of the board are parallel to the sides of the hole.
// All corners of each board must be strictly outside the hole. (That is, they are not allowed to lie on the boundary of the hole, either.)
// 
// 
// 
// 
// If you can cover the hole using the boards you have, return the smallest number of boards that is sufficient to cover the hole. Otherwise, return -1.
// 
// 
// DEFINITION
// Class:RectangleCovering
// Method:minimumNumber
// Parameters:int, int, vector <int>, vector <int>
// Returns:int
// Method signature:int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW)
// 
// 
// CONSTRAINTS
// -holeH and holeW will be between 1 and 1,000,000,000, inclusive.
// -boardH and boardW will contain between 1 and 50 elements, inclusive.
// -boardH and boardW will contain the same number of elements.
// -Each element of boardH and boardW will be between 1 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 5
// 5
// {8,8,8}
// {2,3,4}
// 
// Returns: 2
// 
// You cannot cover this hole completely by using a single board. You can cover it by taking any two boards and placing them side by side.
// 
// 1)
// 10
// 10
// {6,6,6,6}
// {6,6,6,6}
// 
// Returns: -1
// 
// These four boards cannot be used to cover the hole. This is because of the rule that all board corners must be outside the hole.
// 
// 2)
// 5
// 5
// {5}
// {5}
// 
// Returns: -1
// 
// The corners of a board are not allowed to be on the boundary of the hole.
// 
// 3)
// 3
// 5
// {6}
// {4}
// 
// Returns: 1
// 
// 
// 
// 4)
// 10000
// 5000
// {12345,12343,12323,12424,1515,6666,6789,1424,11111,25}
// {1442,2448,42,1818,3535,3333,3456,7890,1,52}
// 
// Returns: 3
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
