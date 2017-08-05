#include <string.h>
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define ZERO(a) memset(a,0,sizeof(a))
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

//const int TOP = 25;
const int TOP = 40;
const int MAXN = 1010;
uint32_t board[TOP][MAXN][MAXN];
ll get(ll bi, ll i1, ll j1, ll i2, ll j2) {
    /*
    cout << bi << " " << i1 << " " << j1 << " " << i2 << " " << j2 << " : " 
       <<  + board[bi][i2][j2] <<  " "
       <<  - board[bi][i2][j1-1]<<  " "
       << - board[bi][i1-1][j2]<<  " "
       << + board[bi][i1-1][j1-1] << endl;;
       */
    return 
        + board[bi][i2][j2]
        - board[bi][i2][j1-1]
        - board[bi][i1-1][j2]
        + board[bi][i1-1][j1-1];
}

class BearDarts {
    public:
        ll b = 10000;
        long long count(vector <int> w_) {
            ZERO(board);
            vll w = conv(w_);
            ll n = w.size();
            map<ll, vll> memo;
            rep(i, n) rep(j, n) if (i < j)  
                memo[w[i]*w[j]].pb(i*b+j);

            vector<P> size_arr;
            for (auto&& v : memo) {
                size_arr.pb(P(v.se.size(), v.fi));
            }
            sort(all(size_arr));
            reverse(all(size_arr));

            map<ll, ll> s;
            rep(i, min<ll>(TOP, size_arr.size())) {
                s[size_arr[i].se] = i;
            }

            rep(i, n) rep(j, n) if (i < j) if (s.count(w[i]*w[j]))  
                board[s[w[i]*w[j]]][i][j] = 1;

            rep(_, TOP) {
                rep(i, MAXN-1) rep(j, MAXN) 
                    board[_][i+1][j] += board[_][i][j];
                rep(i, MAXN) rep(j, MAXN-1) 
                    board[_][i][j+1] += board[_][i][j];
            }

            ll ret = 0;
            for (auto&& v : memo) {
                vector<P> p;
                for (auto&& x : v.se)
                    p.pb(P(x/b, x%b));
                ll val = v.fi;

                rep(i, p.size()) {
                    // ここを高速化する！
                    // 点群pの中で、(ia, ic) x (ic, inf)内に入っているものをカウントする
                    ll ia = p[i].fi, ic = p[i].se;
                    if (ic - ia <= 1) continue; 

                    if (s.count(val)) {
                        ll bi = s[val];
                        ll i1 = ia+1, j1 = ic-1, i2 = ic+1, j2 = MAXN-1;
                        ret += get(bi, i1, i2, j1, j2);
                    } else {
                        rep(j, p.size()) 
                            if (ia < p[j].fi && p[j].fi < ic && ic < p[j].se)
                                ret++;
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
    BearDarts *obj;
    long long answer;
    obj = new BearDarts();
    clock_t startTime = clock();
    answer = obj->count(p0);
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
    p0 = {6,8,4,3,6};
    p1 = 2ll;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {3,4,12,1};
    p1 = 0ll;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
	disabled = false;
	p0 = {42,1000000,1000000,42,1000000,1000000};
	p1 = 3ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,1,1,1,1};
	p1 = 5ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,2,3,4,5,6,5,4,3,2,1};
	p1 = 22ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {33554432,33554432,67108864,134217728};
	p1 = 0ll;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
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
// Limak is an old brown bear who likes to play darts.
// 
// Limak just picked up an empty scorecard.
// He then threw a sequence of darts into a dartboard and for each dart he recorded the point value of the area it hit.
// You are given a vector <int> w containing the contents of Limak's scorecard: a sequence of point values.
// 
// Today there is a special jackpot.
// In order to win the jackpot, the player must present a scorecard with exactly four scores: (a, b, c, d).
// Additionally, these scores must be such that a*c = b*d.
// Note that order matters: the scores a, b, c, d must have been obtained in this particular order.
// 
// Limak wants to erase all but four scores from his scorecard in such a way that he will win the jackpot.
// Compute and return the number of different ways in which he can do that.
// 
// DEFINITION
// Class:BearDarts
// Method:count
// Parameters:vector <int>
// Returns:long long
// Method signature:long long count(vector <int> w)
// 
// 
// CONSTRAINTS
// -w will contain between 4 and 1000 elements, inclusive.
// -Each element in w will be between 1 and 10^9, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {6,8,4,3,6}
// 
// Returns: 2
// 
// Limak must present a scorecard with four scores, so here he has to erase exactly one of these five scores.
// There are two ways to do that and win the jackpot: he can erase either the first throw or the last throw.
// If he erases the first throw, he will be left with (a,b,c,d) = (8,4,3,6), and indeed 8*3 = 4*6.
// If he erases the last throw, he will be left with (a,b,c,d) = (6,8,4,3), and we have 6*4 = 8*3.
// 
// 1)
// {3,4,12,1}
// 
// Returns: 0
// 
// Limak cannot erase anything, so the only thing he can try is to present this scorecard without any changes.
// However, 3*12 does not equal 4*1, so he won't win the jackpot.
// 
// 2)
// {42,1000000,1000000,42,1000000,1000000}
// 
// Returns: 3
// 
// In this case there are three valid solutions:
// 
// Erase the elements with 0-based indices 4 and 5.
// Erase the elements with 0-based indices 1 and 2.
// Erase the elements with 0-based indices 0 and 3.
// 
// 
// 3)
// {1,1,1,1,1}
// 
// Returns: 5
// 
// Here, Limak can erase any single score.
// Note that the five ways are considered different, even though they all produce a scorecard with four 1s.
// 
// 4)
// {1,2,3,4,5,6,5,4,3,2,1}
// 
// Returns: 22
// 
// 
// 
// 5)
// {33554432, 33554432, 67108864, 134217728}
// 
// Returns: 0
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
