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
using P = pair<ll, char>;

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

class TaroFillingAStringDiv1 {
    public:
        int getNumber(int n, vector <int> p, string v) {
            ll m = p.size();
            vector<P> pp;
            rep(i, m) pp.pb(P(p[i], v[i]));
            sort(all(pp));

            ll ret = 1;
            rep(i, pp.size() - 1) {
                ll l = pp[i+1].fi - pp[i].fi - 1;
                if ( (pp[i].se == pp[i+1].se && !(l % 2)) || 
                     (pp[i].se != pp[i+1].se &&  (l % 2)) )
                    (ret *= l + 1) %= mo;
            }
            return ret % mo;
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, string p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "\"" << p2 << "\"";
	cout << "]" << endl;
	TaroFillingAStringDiv1 *obj;
	int answer;
	obj = new TaroFillingAStringDiv1();
	clock_t startTime = clock();
	answer = obj->getNumber(p0, p1, p2);
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
	string p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 3;
	p1 = {1,3};
	p2 = "AB";
	p3 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 4;
	p1 = {2,1,3,4};
	p2 = "ABBA";
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 25;
	p1 = {23,4,8,1,24,9,16,17,6,2,25,15,14,7,13};
	p2 = "ABBBBABABBAAABA";
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 305;
	p1 = {183,115,250,1,188,193,163,221,144,191,92,192,58,215,157,187,227,177,206,15,272,232,49,11,178,59,189,246};
	p2 = "ABAABBABBAABABBBBAAAABBABBBA";
	p3 = 43068480;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
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
// Cat Taro likes strings.
// He is currently constructing a string S of length N.
// Each character of S will be either 'A' or 'B'.
// Taro has already chosen some of the characters.
// You are given these choices as a vector <int> position and a string value.
// For each valid i, the character at the 1-based index position[i] in S is the character value[i].
// 
// 
// 
// 
// To Taro, the ugliness of a string is the number of pairs of equal consecutive characters.
// For example, the ugliness of "ABABAABBB" is 3: there is one pair "AA" and two (overlapping) pairs "BB".
// 
// 
// 
// 
// Taro now wants to finish S by filling in the remaining characters.
// His goal is to create a string with the smallest possible ugliness.
// Let X be the number of possible strings Taro may produce.
// Return the value (X modulo 1,000,000,007).
// 
// 
// DEFINITION
// Class:TaroFillingAStringDiv1
// Method:getNumber
// Parameters:int, vector <int>, string
// Returns:int
// Method signature:int getNumber(int N, vector <int> position, string value)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 1,000,000,000, inclusive.
// -position will contian between 1 and 50 elements, inclusive.
// -value and position will contain the same number of elements.
// -Each element of position will be between 1 and N, inclusive.
// -All elements of position will be distinct.
// -value will consist only of characters 'A' and 'B'.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// {1, 3}
// "AB"
// 
// Returns: 2
// 
// Currently, Taro's string looks as follows: A_B.
// He can either produce the string AAB or the string ABB.
// Both have the same ugliness.
// 
// 1)
// 4
// {2, 1, 3, 4}
// "ABBA"
// 
// Returns: 1
// 
// All characters of S have already been chosen.
// 
// 2)
// 25
// {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13}
// "ABBBBABABBAAABA"
// 
// Returns: 1
// 
// 
// 
// 3)
// 305
// {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246}
// "ABAABBABBAABABBBBAAAABBABBBA"
// 
// Returns: 43068480
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!