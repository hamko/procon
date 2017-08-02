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
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
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

class ParenthesesDiv1Medium {
    public:
        int minSwaps(string s, vector <int> l, vector <int> r) {
            ll n = s.length();
            ll m = l.size();
            rep(i, m) {
                r[i]++;
            }

            bool f[2010] = {};
            rep(i, m) {
                repi(j, l[i], r[i]) {
                    f[j] = 1;
                }
            }
            ll counter = 0;
            rep(i, 2010) {
                if (f[i]) cout << i << " ";
                counter += f[i];
            }
            cout << endl;
            ll open = count(all(s), '(');
            ll close = count(all(s), ')');
            if (!(open >= counter / 2 && close >= counter / 2)) {
                cout << "lacking for par" << endl;
                cout << open << " " << close << " " << counter << endl;
                return -1;
            }

            set<ll> events;
            rep(i, m) {
                events.insert(l[i]);
                events.insert(r[i]);
            }
            cout << events << endl;

            set<P> intervals;
            vector<P> lr;
            rep(i, m) {
                lr.pb(P(l[i], r[i]));
            }
            sort(all(lr));
            cout << lr << endl;

            for (auto&& x : lr) {
                ll a = x.fi; // a以上の最小のbを探す
                intervals.insert(P(a, *upper_bound(all(events), a)));
            }

            // 分割後奇数はダメ
            cout << intervals << endl;
            for (auto&& x : intervals) {
                cout << s.substr(x.fi, x.se-x.fi) << endl;
            }
            for (auto&& x : intervals) {
                if ((x.se - x.fi) % 2 == 1) {
                    cout << "odd interval" << endl;
                    cout << x << endl;
                    return -1;
                }
            }

            ll ni = intervals.size();
            vector<P> bm; // P(balance, min)
            for (auto&& x : intervals) {
                ll a = x.fi, b = x.se;
                ll balance = 0;
                ll m = 0;
                repi(i, a, b) {
                    balance += (s[i] == '(' ? 1 : -1);
                    chmin(m, balance);
                }
                bm.pb(P(balance, m));
            }

            cout << bm << endl;
            ll ret = 0;

            ll pl = 0, mi = 0; 
            rep(i, bm.size()) {
                if (bm[i].fi > 0) {
                    pl += bm[i].fi;
                } else if (bm[i].fi < 0) {
                    mi += bm[i].fi;
                } else {
                }
            }
            cout << pl << " " << mi << "#pimi" <<endl;
            ll rem_pi = min(pl, -mi), rem_mi = min(pl, -mi);
            ret += min(pl, -mi) / 2;
            rep(i, bm.size()) {
                if (bm[i].fi > 0) {
                    ll tmp = min(rem_pi, bm[i].fi);
                    rem_pi -= tmp;
                    bm[i].fi -= tmp;
                } else if (bm[i].fi < 0) {
                    ll tmp = min(rem_mi, -bm[i].fi);
                    rem_mi -= tmp;
                    bm[i].fi += tmp;
                    bm[i].se += tmp * 2;
                }
            }
            cout << rem_pi << " " << rem_mi <<endl;
            cout << bm << endl;

            rep(i, bm.size()) {
                if (bm[i].fi > 0) {
                    ll tmp = bm[i].fi / 2;
                    ret += tmp;
                    bm[i].fi = 0;
                    bm[i].se += 2 * tmp;
                    chmin(bm[i].se, 0);
                } else if (bm[i].fi < 0) {
                    ll tmp = -bm[i].fi / 2;
                    ret += tmp;
                    bm[i].fi = 0;
                    bm[i].se += 2 * tmp;
                } else {
                }
            }
            cout << bm << endl;

            rep(i, bm.size()) {
                if (bm[i].se < 0) {
                    ret += (-bm[i].se + 1) / 2;
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
bool KawigiEdit_RunTest(int testNum, string p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	ParenthesesDiv1Medium *obj;
	int answer;
	obj = new ParenthesesDiv1Medium();
	clock_t startTime = clock();
	answer = obj->minSwaps(p0, p1, p2);
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
	
	string p0;
	vector <int> p1;
	vector <int> p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = ")(";
	p1 = {0,0,0,0};
	p2 = {1,1,1,1};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "(())";
	p1 = {0,2};
	p2 = {1,3};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 1 -----
	disabled = false;
	p0 = "))((";
	p1 = {0,2};
	p2 = {1,3};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "(((())";
	p1 = {0,2};
	p2 = {1,3};
	p3 = 2;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "(((((((((";
	p1 = {0,2};
	p2 = {1,3};
	p3 = -1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "()()()()";
	p1 = {0,0,0,0,2,2,2,4,4,6};
	p2 = {1,3,5,7,3,5,7,5,7,7};
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = ")()(()()((())()()()()()()))(()())()()()(";
	p1 = {3,5,17,25,35};
	p2 = {12,10,30,30,38};
	p3 = 3;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
//    ", {1, 4, 3, 2, 0}, {8, 5, 6, 7, 9
	// ----- test 5 -----
	disabled = false;
	p0 = "((()())())";
	p1 = {1,4,3,2,0};
	p2 = {8,5,6,7,9};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 1 -----
	disabled = false;
	p0 = "(())";
	p1 = {1,2};
	p2 = {0,3};
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
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
// Correct parentheses sequences can be defined recursively as follows:
// 
// The empty string "" is a correct sequence.
// If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
// If "X" is a correct sequence, then "(X)" is a correct sequence.
// Each correct parentheses sequence can be derived using the above rules.
// 
// Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".
// 
// 
// You are given a string s.
// You are also given vector <int>s L and R, each with the same number of elements.
// These encode a set of conditions.
// For each valid i, you have to satisfy the following condition:
// the substring of s that begins at the 0-based index L[i] and ends at the 0-based index R[i] must be a correct parentheses sequence.
// 
// 
// 
// You can only modify s in one way: in each step you can choose two characters of s and swap them.
// Return the minimal number of swaps needed to produce a string that satisfies all the given conditions.
// If it is impossible, return -1 instead.
// 
// DEFINITION
// Class:ParenthesesDiv1Medium
// Method:minSwaps
// Parameters:string, vector <int>, vector <int>
// Returns:int
// Method signature:int minSwaps(string s, vector <int> L, vector <int> R)
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 2,000 characters, inclusive.
// -Each character in s will be '(' or ')'.
// -L will contain between 1 and 2,000 elements, inclusive.
// -L and R will contain the same number of elements.
// -For each valid i, 0 <= L[i] <= R[i] < |s|.
// 
// 
// EXAMPLES
// 
// 0)
// ")("
// {0,0,0,0}
// {1,1,1,1}
// 
// Returns: 1
// 
// We have four identical conditions.
// Each of them tells us that the substring that begins at index 0 and ends at index 1 must be a correct parentheses sequence.
// We can satisfy all conditions by swapping s[0] with s[1].
// This swap produces the string "()".
// 
// 
// 1)
// "(())"
// {0,2}
// {1,3}
// 
// Returns: 1
// 
// The only way to satisfy both conditions is to change s into "()()".
// This can be done in 1 swap: by swapping s[1] with s[2].
// 
// 
// 2)
// "(((())"
// {0,2}
// {1,3}
// 
// Returns: 2
// 
// This time we do swap(s[1],s[4]) and swap(s[3],s[5]).
// 
// 3)
// "((((((((("
// {0,2}
// {1,3}
// 
// Returns: -1
// 
// 
// 
// 4)
// "()()()()"
// {0,0,0,0,2,2,2,4,4,6}
// {1,3,5,7,3,5,7,5,7,7}
// 
// Returns: 0
// 
// 
// 
// 5)
// ")()(()()((())()()()()()()))(()())()()()("
// {3,5,17,25,35}
// {12,10,30,30,38}
// 
// Returns: 3
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
