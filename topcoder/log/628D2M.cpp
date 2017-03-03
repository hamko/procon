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

class BracketExpressions {
    public:
        bool ok(string& s) {
            stack<char> st;
            map<char, ll> memo; 
            memo['['] = ']';
            memo['('] = ')';
            memo['{'] = '}';
            rep(i, s.length()) {
                if (st.empty()) {
                    if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                        st.push(s[i]);
                    } else 
                        return false;
                } else {
                    if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                        st.push(s[i]);
                    } else {
                        if (memo[st.top()] != s[i]) {
                            return false;
                        } else {
                            st.pop();
                        }
                    }
                }

            }
            return st.empty();
        }
        string ifPossible(string e) {
            vll idx;
            rep(i, e.length()) {
                if (e[i] == 'X') 
                    idx.pb(i);
            }
            string bra = "[](){}";
            rep(mask, pow(6, idx.size())) {
                ll tmp = mask;
                auto s = e;
                rep(i, idx.size()) {
                    s[idx[i]] = bra[tmp % 6];
                    tmp /= 6;
                }
                if (ok(s)) {
                    return "possible";
                }
            }
            return "impossible";
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	BracketExpressions *obj;
	string answer;
	obj = new BracketExpressions();
	clock_t startTime = clock();
	answer = obj->ifPossible(p0);
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
	
	string p0;
	string p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = "([]{})";
	p1 = "possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "(())[]";
	p1 = "possible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "({])";
	p1 = "impossible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "[]X";
	p1 = "impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "([]X()[()]XX}[])X{{}}]";
	p1 = "possible";
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
// We have three types of brackets: "()", "[]", and "{}".
// We are now interested in some special strings.
// A string is special if all the following conditions hold:
// 
// Each character of the string is one of the six bracket characters mentioned above.
// The characters of the string can be divided into disjoint pairs such that in each pair we have an opening bracket and a closing bracket of the same type.
// For each pair, the opening bracket must occur to the left of the corresponding closing bracket.
// For each pair, the substring strictly between the opening and the closing bracket must be a special string (again, according to this definition).
// 
// 
// For example, the empty string is a special string: there are 0 pairs of brackets.
// The string "[]" is also a special string: there is one pair of matching brackets, they are in the proper order, and the string between them (which is the empty string) is a special string.
// 
// The character 'X' (uppercase x) occurs in expression at most five times; all other characters in expression are brackets of the types mentioned above.
// We want to change expression into a special string by changing each 'X' into one of the brackets.
// (Different occurrences of 'X' may be changed into different brackets.)
// Return "possible" (quotes for clarity) if we can do that, and "impossible" otherwise.
// 
// DEFINITION
// Class:BracketExpressions
// Method:ifPossible
// Parameters:string
// Returns:string
// Method signature:string ifPossible(string expression)
// 
// 
// CONSTRAINTS
// -expression will have between 1 and 50 characters, inclusive.
// -Each character in expression will be '(', ')', '[', ']', '{', '}' or 'X'.
// -There will be at most 5 occurences of 'X' in expression.
// 
// 
// EXAMPLES
// 
// 0)
// "([]{})"
// 
// Returns: "possible"
// 
// This is already a special string. As there are no 'X's, we do not get to change anything.
// 
// 1)
// "(())[]"
// 
// Returns: "possible"
// 
// 
// 
// 2)
// "({])"
// 
// Returns: "impossible"
// 
// 
// 
// 3)
// "[]X"
// 
// Returns: "impossible"
// 
// Regardless of bracket type you put instead of 'X', you cannot create a special string.
// 
// 4)
// "([]X()[()]XX}[])X{{}}]"
// 
// Returns: "possible"
// 
// You can replace 'X's respectively with '{', '(', ')' and '['.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
