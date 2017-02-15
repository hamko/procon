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

class SquareScores {
    public:
        double calcexpectation(vector <int> p_, string s) {
            ll n = s.size();
            vector<double> p;
            rep(i, p_.size()) {
                p.pb(p_[i]/100.0);
            }

            vvll counter(256, vll(n+1));
            rep(i, counter.size()) 
                rep(j, n) 
                    counter[i][j+1] = counter[i][j] + (s[j] == i);
//            cout << counter << endl;

            double ret = 0;
            repi(len, 1, n + 1) {
                rep(i, n - len + 1) {
                    // [i, i+len)
                    ll x = 0;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (counter[c][i+len] - counter[c][i] == 0) continue;
                        if (x) {
                            x = -1;
                            break;
                        } else {
                            x = c;
                        }
                    }
                    if (x == -1) continue;
//                    cout << i << " " << i + len - 1 << "range" << endl; 
//                    if (x == 0) 
//                        cout << "?" << endl;
//                    else 
//                        cout << char(x) << "x" << endl; 
                    if (x == 0) { // ?のみ
                        double tmp = 0;
                        for (auto pp : p) {
                            tmp += pow(pp, counter['?'][i+len] - counter['?'][i]);
                        }
//                        cout << tmp << "????"<< endl;
                        ret += tmp;
                    } else {
                        double tmp = 0;
                        tmp = pow(p[x-'a'], counter['?'][i+len] - counter['?'][i]);
//                        cout << tmp << "aa?a" << endl;
                        ret += tmp;
                    }
                }
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, string p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	SquareScores *obj;
	double answer;
	obj = new SquareScores();
	clock_t startTime = clock();
	answer = obj->calcexpectation(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	double p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,99};
	p1 = "aaaba";
	p2 = 8.0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {10,20,70};
	p1 = "aa?bbbb";
	p2 = 15.0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {10,20,30,40};
	p1 = "a?" "?c?dc?b";
	p2 = 11.117;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {25,25,21,2,2,25};
	p1 = "a?" "?b?" "?" "?" "?" "?" "?" "?ff?" "?e";
	p2 = 21.68512690712425;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {4,4,4,3,4,4,4,4,4,4,3,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4};
	p1 = "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?";
	p2 = 31.16931963781721;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {4,3,4,3,8,2,4,3,4,4,3,2,4,4,3,4,2,4,7,6,4,4,3,4,4,3};
	p1 = "makigotapresentfromniko";
	p2 = 23.0;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 4 -----
	disabled = false;
	p0 = {4,4,4,3,4,4,4,4,4,4,3,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4};
	p1 = "????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????";
	p2 = 31.16931963781721;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
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
// A substring of a string is a contiguous sequence of characters from the string.
// For example, each of the strings "ab", "bcd", and "e" is a substring of "abcde". 
// On the other hand, "cba", "ace", and "f" are not substrings of "abcde".
// 
// 
// The score of a string S is the number of ways in which we can select a non-empty substring of S such that all characters in the substring are the same.
// If two substrings consist of the same letters but occur at different places in S, they are still considered different.
// For example, the score of "aaaba" is 8: there are four occurrences of the substring "a", two occurrences of "aa", one occurrence of "aaa", and one of "b".
// 
// 
// On her birthday, Maki got a string s from her friend Niko as a present.
// Each character in this string is either a lowercase letter or a question mark ('?').
// 
// 
// Maki is going to randomly change each question mark into a letter.
// For each question mark and each i, the probability that she changes it into the (i+1)-st letter of the alphabet is p[i] percent.
// (I.e., she will change it into an 'a' with probability p[0]/100, into a 'b' with probability p[1]/100, and so on.)
// The choices for different question marks are mutually independent.
// 
// 
// You are given the vector <int> p.
// Note that p may have fewer than 26 elements.
// In that case we assume that the missing probabilities are 0.
// 
// 
// Calculate and return the expected score of the string after all the question marks are changed into letters.
// 
// 
// DEFINITION
// Class:SquareScores
// Method:calcexpectation
// Parameters:vector <int>, string
// Returns:double
// Method signature:double calcexpectation(vector <int> p, string s)
// 
// 
// NOTES
// -The solution is correct if the relative error or the absolute error is at most 1e-9.
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 1,000 elements, inclusive.
// -Each character in s will be '?' or a lowercase letter ('a'-'z').
// -If a character in s is j'th lowercase letter(1-indexed), j will be between 1 and (the size of p), inclusive.
// -p will contain between 1 and 26 characters, inclusive.
// -Each element in p will be between 0 and 100, inclusive.
// -The sum of all elements in p will be exactly 100.
// 
// 
// EXAMPLES
// 
// 0)
// {1, 99}
// "aaaba"
// 
// Returns: 8.0
// 
// 
// 
// 1)
// {10, 20, 70}
// "aa?bbbb"
// 
// Returns: 15.0
// 
// 
// 
// 2)
// {10, 20, 30, 40}
// "a??c?dc?b"
// 
// Returns: 11.117
// 
// 
// 
// 3)
// {25, 25, 21, 2, 2, 25}
// "a??b???????ff??e"
// 
// Returns: 21.68512690712425
// 
// 
// 
// 4)
// {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4}
// "??????????????????????????????"
// 
// Returns: 31.16931963781721
// 
// 
// 
// 5)
// {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3}
// "makigotapresentfromniko"
// 
// Returns: 23.0
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
