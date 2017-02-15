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

class CountryGroupHard {
    public:
        ll dp[105][105];
        vll a;
        ll rec(ll i, ll j) { // count [i, j] 
            if (i == j) {
                cout << i << " " << j << " " << (a[i] <= 1) << "#ret 1" << endl;
                return a[i] <= 1;
            }
            if (i > j) { 
                cout << i << " " << j << " " << 1 << "#ret range" << endl;
                return 1;
            }
            if (dp[i][j] >= 0) {
                cout << i << " " << j << " " << dp[i][j] << "#ret dp" << endl;
                return dp[i][j];
            }
            cout << i << " " << j << endl;
            auto it = exists(a.begin() + i, a.begin() + j + 1, [&](ll x) { return x > 0; });
            if (it == a.begin() + j + 1) {
                cout << i << " " << j << " " << 2 << "#ret mul0" << endl;
                return dp[i][j] = 2; // all 0
            }
            ll num = *it;
            ll p = (ll)(it - a.begin());
            cout <<  num << " " << p << "#num, p" << endl;
            
            /*
            if (forall((ci)i, (ci)(j+1), [&](ll x) { return a[x] == 0 || a[x] == num; }) && (j - i + 1 == num)) {
                cout << i << " " << j << "#hit" << endl;
                return dp[i][j] = 1;
            }
            */

            ll ret = 0;
            for (ll l = p - num + 1; l <= p; l++) {
                ll r = l + num - 1;
                if (l < i || j < r) continue;
                if (!forall((ci)l, (ci)(r+1), [&](ll x) { return a[x] == 0 || a[x] == num; })) continue;
                cout << l << " " << r << "#lr " << endl;
                ret += rec(i, l-1) * rec(r+1, j);
            }
            cout << i << " " << j << " " << min(2ll, ret) << "#ret end" << endl;
            return dp[i][j] = min(2ll, ret);
        }
        string solve(vector <int> a_) {
            a = conv(a_);
            rep(i, 105) rep(j, 105) dp[i][j] = -1;
            cout << rec(0, a.size()-1) << endl;;
            return rec(0, a.size()-1) == 1 ? "Sufficient" : "Insufficient";
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	CountryGroupHard *obj;
	string answer;
	obj = new CountryGroupHard();
	clock_t startTime = clock();
	answer = obj->solve(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {0,2,3,0,0};
	p1 = "Sufficient";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {0,2,0};
	p1 = "Insufficient";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {0,3,0,0,3,0};
	p1 = "Sufficient";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {0,0,3,3,0,0};
	p1 = "Insufficient";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {2,2,0,2,2};
	p1 = "Sufficient";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	// ----- test 4 -----
	disabled = false;
	p0 = {0,2,2};
	p1 = "Sufficient";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 4 -----
	disabled = false;
	p0 = {4, 4, 0, 0, 2, 2, 3, 3, 3, 3, 3, 3, 2, 0, 5, 5, 5, 0, 5, 3, 3, 3, 1, 1, 5, 5, 0, 0, 0, 2, 0, 5, 5, 5, 5, 5, 1, 3, 3, 3, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0, 3, 1, 2, 2, 2, 2, 5, 5, 5, 5, 5, 2, 2, 0, 2, 0, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 0, 0, 3, 3, 3, 2, 0, 1, 4, 0, 4, 0, 2, 2};
	p1 = "Sufficient";
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
// 
// Some people are sitting in a row.
// Each person came here from some country.
// People from the same country are all sitting together.
// 
// 
// 
// A reporter has already approached some of the people and asked each of them the same question:
// "How many people from your country (including you) are here?"
// All the people who were asked the question gave her correct answers.
// 
// 
// 
// You are given a vector <int> a.
// The elements of a correspond to the people in the row, in order.
// For each i, element i of a is either 0 if the corresponding person was not asked the question, or a positive integer: the answer given by that person.
// 
// 
// 
// The reporter just realized that she might be able to reconstruct all the missing answers from the answers she already knows.
// Return "Sufficient" if she can do that, or "Insufficient" if she cannot.
// 
// 
// DEFINITION
// Class:CountryGroupHard
// Method:solve
// Parameters:vector <int>
// Returns:string
// Method signature:string solve(vector <int> a)
// 
// 
// CONSTRAINTS
// -The number of elements in a will be between 1 and 100, inclusive.
// -All numbers of a will be between 0 and 100, inclusive.
// -There exist valid country assignment of people for input.
// 
// 
// EXAMPLES
// 
// 0)
// {0,2,3,0,0}
// 
// Returns: "Sufficient"
// 
// The first two people must be from the same country. The last three people must also be from the same country. Thus, the only possible sequence of answers is {2,2,3,3,3}.
// 
// 1)
// {0,2,0}
// 
// Returns: "Insufficient"
// 
// There are still two different sequences of answers that are consistent with the reporter's information: the answers can be either {1,2,2} or {2,2,1}.
// 
// 2)
// {0,3,0,0,3,0}
// 
// Returns: "Sufficient"
// 
// 
// 
// 3)
// {0,0,3,3,0,0}
// 
// Returns: "Insufficient"
// 
// 
// 
// 4)
// {2,2,0,2,2}
// 
// Returns: "Sufficient"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
