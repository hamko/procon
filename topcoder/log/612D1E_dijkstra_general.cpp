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

class EmoticonsDiv1 {
    public:
        int printSmiles(int n) {
            using D = int16_t; // !! 距離の型
            using state_t = int16_t; 
            using S = tuple<state_t, state_t>; // !! 状態の型

            using T = tuple<D, S>; // (dist, state)
            priority_queue<T, vector<T>, greater<T>> q; // 頂点集合昇順

            q.push(mt(0, mt(1, 0))); // !! 初期値
            auto f = [&](S& x) {  // !! 異常判定基準
                state_t xx, yy; tie(xx, yy) = x; 
                return (xx >= 1050 || xx <= 0 || yy >= 520 || yy <= 0); 
            };

            unordered_map<S, D> dist;
            unordered_set<S> used;
            while (!q.empty()) {
                // この時点で、(d, t)が処理するべき頂点
                // usedのダブりはループ内で処理
                D d; S t; tie(d, t) = q.top(); q.pop();

                if (used.count(t)) continue; // もう来てたら終わり
                used.insert(t); 
                dist[t] = d; 

                // !! 遷移の定義
                vector<T> next_nodes;
                state_t x, y; tie(x, y) = t;
                next_nodes.pb(mt(2, mt(2*x, x)));
                next_nodes.pb(mt(1, mt(x-1, y)));
                next_nodes.pb(mt(1, mt(x+y, y)));

                for (auto&& next_node : next_nodes) {
                    D nd; S nt; tie(nd, nt) = next_node;
                    if (f(nt)) continue;
                    if (dist.count(nt) && dist[nt] <= d + nd) continue;  // 枝刈り
                    q.push(mt(d + nd, nt));
                }
            }

            // !! 後処理
            D ret = 10000; // INF
            rep(y, 2000) if (dist.count(mt(n, y))) 
                chmin(ret, dist[mt(n, y)]);

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
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << p0;
    cout << "]" << endl;
    EmoticonsDiv1 *obj;
    int answer;
    obj = new EmoticonsDiv1();
    clock_t startTime = clock();
    answer = obj->printSmiles(p0);
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

    int p0;
    int p1;

    // ----- test 0 -----
    disabled = false;
    p0 = 2;
    p1 = 2;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = 998;
    p1 = 22;
    all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // ----- test 4 -----
	disabled = false;
	p0 = 997;
	p1 = 23;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
			// ----- test 4 -----
	disabled = false;
	p0 = 512;
	p1 = 18;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
				// ----- test 4 -----
	disabled = false;
	p0 = 513;
	p1 = 19;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	

	// ----- test 1 -----
	disabled = false;
	p0 = 4;
	p1 = 4;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 6;
	p1 = 5;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 18;
	p1 = 8;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 11;
	p1 = 8;
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
// You are very happy because you advanced to the next round of a very important programming contest.
// You want your best friend to know how happy you are.
// Therefore, you are going to send him a lot of smile emoticons.
// You are given an int smiles: the exact number of emoticons you want to send.
// 
// You have already typed one emoticon into the chat.
// Then, you realized that typing is slow.
// Instead, you will produce the remaining emoticons using copy, paste, and possibly some deleting.
// 
// You can only do three different operations:
// 
// Copy all the emoticons you currently have into the clipboard.
// Paste all emoticons from the clipboard.
// Delete one emoticon from the message.
// 
// Each operation takes precisely one second.
// Copying replaces the old content of the clipboard.
// Pasting does not empty the clipboard.
// You are not allowed to copy just a part of the emoticons you already have.
// You are not allowed to delete an emoticon from the clipboard.
// 
// Return the smallest number of seconds in which you can turn the one initial emoticon into smiles emoticons.
// 
// DEFINITION
// Class:EmoticonsDiv1
// Method:printSmiles
// Parameters:int
// Returns:int
// Method signature:int printSmiles(int smiles)
// 
// 
// CONSTRAINTS
// -smiles will be between 2 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 
// Returns: 2
// 
// First use copy, then use paste. The first operation copies one emoticon into the clipboard, the second operation pastes it into the message, so now you have two emoticons and you are done.
// 
// 1)
// 4
// 
// Returns: 4
// 
// One optimal solution is to copy the initial emoticon and then to paste it three times. Another optimal solution is to copy the one emoticon, paste it, copy the two emoticons you currently have, and paste two more.
// 
// 2)
// 6
// 
// Returns: 5
// 
// 
// Copy. This puts one emoticon into the clipboard.
// Paste. You now have 2 emoticons in the message.
// Copy. The clipboard now contains 2 emoticons.
// Paste. You now have 4 emoticons in the message.
// Paste. You now have 6 emoticons in the message and you are done.
// 
// 
// 3)
// 18
// 
// Returns: 8
// 
// 
// 
// 4)
// 11
// 
// Returns: 8
// 
// Sometimes we actually do delete an emoticon in the optimal solution.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
