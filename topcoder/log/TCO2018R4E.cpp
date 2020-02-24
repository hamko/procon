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

class SumPyramid {
    public:
        int p(int levels, int top) {
            int c[1001][1001] = {};
            c[0][0] = 1;
            repi(i, 1, levels) {
                c[i][0] = 1;
                repi(k, 1, i+1) {
                    c[i][k] = c[i-1][k-1]+c[i-1][k];
                    if (c[i][k] > top) c[i][k] = top + top;
                }
            }
            int s[2][1001] = {};
            s[0][top] = 1;
            rep(i, levels) {
                int cur = i % 1;
                int next = cur ^ 1;
                rep(j, top+1) {
                    s[next][j] = 0;
                }
                rep(j, top+1) for (int k = 0; c[levels-1][i] * k <= j; k++) {
                    const int part = c[levels-1][i] * k;
                    s[next][j-part] += s[cur][j];
                    if (s[next][j-part] >= mo) s[next][j-part] -= mo;
                }
            }
            return s[levels&1][0];

        }

        bool used[1010][1010] = {};
        ll dp[1010][1010] = {};
        ll dfs(vll& c, ll i, ll rem) {
            if (used[i][rem]) {
                return dp[i][rem];
            }
            used[i][rem] = 1;
            ll& ret = dp[i][rem];
            if (i == c.size() - 1) {
                return ret = 1;
            }
            for (ll d = 0; d <= rem; d += c[i]) {
                (ret += dfs(c, i+1, rem - d)) %= mo;
            }
            return ret % mo;
        }
        int countPyramids(int l_, int t_) {
            rep(i, 1010) rep(j, 1010) {
                used[i][j] = 0;
                dp[i][j] = 0;
            }
            ll l = l_, t = t_;
            vll a(l);
            a[0] = 1;
            rep(i, l-1) {
                vll b(l);
                b[0] = a[0];
                repi(j, 1, l) {
                    b[j] = a[j] + a[j-1];
                    if (b[j] > 1001) {
                        b[j] = 1001;
                    }
                }
                swap(a, b);
            }
            //            cout << a << endl;
            vll c;
            rep(i, a.size()) {
                if (a[i] < 1001) {
                    c.pb(a[i]);
                }
            }
            sort(all(c)), reverse(all(c));
            //            cout << c << endl;
            return dfs(c, 0, t);
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
    /*
       cout << "Test " << testNum << ": [" << p0 << "," << p1;
       cout << "]" << endl;
       */
    SumPyramid *obj;
    int answer;
    obj = new SumPyramid();
    clock_t startTime = clock();
    answer = obj->countPyramids(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << double(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    /*
       cout << "Your answer:" << endl;
       cout << "\t" << answer << endl;
       */
    if (hasAnswer) {
        res = answer == p2;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        //		cout << "Match :-)" << endl;
    } else {
        //		cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    SumPyramid *obj;
    obj = new SumPyramid();
    cout << obj->p(2, 10) << "HOGE" << endl;;
    cout << obj->p(2, 0) << endl;;
    return 0;
    /*
    repi(i, 2, 1001) {
        rep(j, 1001) {
        cout << i  << " " << j << endl;
            if (obj->countPyramids(i, j) != obj->p(i, j)) {
                cout << i << " " << j << endl;
            }
        }
    }

    */
    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    int p0;
    int p1;
    int p2;

    // ----- test 0 -----
    disabled = false;
    p0 = 1;
    p1 = 47;
    p2 = 1;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = 2;
    p1 = 10;
    p2 = 11;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // ----- test 1 -----
    disabled = false;
    p0 = 2;
    p1 = 0;
    p2 = 1;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    repi(j, 1, 1001) {
        disabled = false;
        p0 = 2;
        p1 = j;
        p2 = j+1;
        all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
        tests_disabled = tests_disabled || disabled;
    }

    // ----- test 2 -----
    disabled = false;
    p0 = 3;
    p1 = 2;
    p2 = 4;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // ----- test 2 -----
    disabled = false;
    p0 = 1;
    p1 = 0;
    p2 = 1;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // ----- test 2 -----
    disabled = false;
    p0 = 3;
    p1 = 3;
    p2 = 6;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = 5;
    p1 = 7;
    p2 = 18;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;

    /*
       repi(i, 70, 1001) {
       cout <<"###################################################" << i << endl;
       rep(j, 1001) {
    // ----- test 3 -----
    disabled = false;
    p0 = i;
    p1 = j;
    p2 = -1;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, false, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;


    }
    }
    */
    // ------------------
    /*
    //	// ----- test 3 -----
    disabled = false;
    p0 = 15;
    p1 = 7;
    p2 = 18;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    //	// ----- test 3 -----
    disabled = false;
    p0 = 20;
    p1 = 1000;
    p2 = 18;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;

    // ----- test 3 -----
    disabled = false;
    p0 = 1000;
    p1 = 1000;
    p2 = -1;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    */

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
// A sum pyramid is a two-dimensional arrangement of numbers into a pyramid-like shape in which each number (except for the numbers in the bottom row) is the sum of the two numbers that are diagonally below its place.
// Here's an example of a sum pyramid:
// 
// 
// 
//       25
//    12   13
//  7    5    8
// 
// 
// 
// Note that 12 = 7+5, 13 = 5+8, and 25 = 12+13.
// 
// 
// 
// Each row of the sum pyramid is called a level. The sum pyramid shown above has three levels. Note that the number of elements in the bottom row is equal to the number of levels.
// 
// 
// 
// You are given the ints levels and top. Consider all sum pyramids with the following properties:
// 
// 
// 
// All numbers in the pyramid are nonnegative integers.
// The pyramid has levels levels.
// The number on the top of the pyramid is top.
// 
// 
// 
// Compute and return the number of such pyramids, modulo 10^9 + 7.
// 
// 
// DEFINITION
// Class:SumPyramid
// Method:countPyramids
// Parameters:int, int
// Returns:int
// Method signature:int countPyramids(int levels, int top)
// 
// 
// CONSTRAINTS
// -levels will be between 1 and 1000, inclusive.
// -top will be between 0 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 47
// 
// Returns: 1
// 
// In this case the only valid pyramid is just the single number 47.
// 
// 1)
// 2
// 10
// 
// Returns: 11
// 
// Three of the eleven valid pyramids:
// 
// 
//   10       10        10
// 10  0     4  6      1  9
// 
// 
// 2)
// 3
// 2
// 
// Returns: 4
// 
// The four pyramids look as follows:
// 
// 
//   2       2       2       2
//  2 0     1 1     1 1     0 2
// 2 0 0   1 0 1   0 1 0   0 0 2
// 
// 
// 3)
// 5
// 7
// 
// Returns: 18
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
