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

class Coversta {
    public:
        ll k;
        ll n, m;
        vector<int> x, y;
        vector<string> a;
        ll getSingleScore(ll i, ll j) {
            ll ret = 0;
            rep(kk, k) {
                ll id = x[kk];
                ll jd = y[kk];
                ll ii = i + id;
                ll jj = j + jd;
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                ret += a[ii][jj] - '0';
            }
            return ret;
        }

        ll getDoubleScore(vll s, vll t) {
            set<P> memo;
            ll ret = 0;
            for (auto z : {s, t}) {
                rep(kk, k) {
                    ll id = x[kk];
                    ll jd = y[kk];
                    ll ii = z[1] + id;
                    ll jj = z[2] + jd;
                    if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                    memo.insert(P(ii, jj));
                }
            }
            for (auto x : memo) {
                ret += a[x.fi][x.se] - '0';
            }
            return ret;
        }

        int place(vector <string> a_, vector <int> x_, vector <int> y_) {
            a = a_;
            x = x_;
            y = y_;
            n = a.size();
            m = a[0].size();
            k = x.size();

            vector<vll> scores;
            rep(i, n) rep(j, m) {
                vll s(3);
                ll single_score = getSingleScore(i, j);
                if (single_score == -INF) continue;
                scores.pb({single_score, i, j});
            }
            sort(all(scores));
            reverse(all(scores));
            ll ret = 0;
            rep(i, scores.size()) {
                rep(j, min<ll>(100, scores.size())) {
                    chmax(ret, getDoubleScore(scores[i], scores[j]));
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}" << "," << "{";
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
    Coversta *obj;
    int answer;
    obj = new Coversta();
    clock_t startTime = clock();
    answer = obj->place(p0, p1, p2);
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

    vector <string> p0;
    vector <int> p1;
    vector <int> p2;
    int p3;

    // ----- test 0 -----
    disabled = false;
	p0 = {"11","11"};
	p1 = {0,0};
	p2 = {0,1};
	p3 = 4;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"11","11"};
	p1 = {0,1};
	p2 = {0,1};
	p3 = 3;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"15","61"};
	p1 = {0};
	p2 = {0};
	p3 = 11;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"151","655","661"};
	p1 = {0,0,-1};
	p2 = {0,1,0};
	p3 = 33;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"303","333","000"};
	p1 = {-1,-1};
	p2 = {-1,1};
	p3 = 12;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {"0000000","1010101"};
	p1 = {-1,-1};
	p2 = {-1,1};
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
    //	// ----- test 5 -----
	disabled = false;
	p0 = {"409488245", "517115276", "142322168"};
	p1 = {0, -1, 2, -2, 1};
	p2 = {-8, 4, -3, -8, 3};
	p3 = 22;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    // {{"9722828907", "8158612425", "8626539246", "1821197629", "5200391819", "5325258677", "2294196982", "5549125083", "9396799769", "3576658254", "4161633553"}, {4, -2, 5}, {-1, -9, 2}}
    //
    disabled = false;
	p0 = {"9722828907", "8158612425", "8626539246", "1821197629", "5200391819", "5325258677", "2294196982", "5549125083", "9396799769", "3576658254", "4161633553"};
	p1 = {4,-2,5};
	p2 = {-1,-9,2};
	p3 = 35;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;

    //{{"409488245", "517115276", "142322168"}, {0, -1, 2, -2, 1}, {-8, 4, -3, -8, 3}}
		// ----- test 5 -----
	disabled = true;
	p0 = {
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
    };
	p1 = {-1,-1,2,3,2,4,5,2,5,3};
	p2 = {-1,-1,2,3,2,4,5,2,5,3};
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
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
// There is a rectangular field divided into a grid of n rows by m columns of unit square cells.
// Each cell (i, j) has some strategic value which is an integer between 0 and 9, inclusive.
// You are given these values as a vector <string> a where each a[i][j] is a digit between '0' and '9', inclusive.
// 
// It is possible to build stations in some cells.
// A station built in a cell covers some set of cells.
// You are given the offsets of those cells as vector <int>s x and y.
// More precisely, for each valid k, a station in the cell (i, j) covers the cell (i + x[k], j + y[k]) if a cell with those coordinates exists.
// Note that it may be the case that a station in (i, j) does not cover the cell (i, j).
// 
// Your task is to place two stations into two distinct cells.
// The total strategic value of the two stations is the sum of strategic values of all cells that are covered by at least one of the stations.
// Return the largest possible total strategic value of the two stations.
// 
// DEFINITION
// Class:Coversta
// Method:place
// Parameters:vector <string>, vector <int>, vector <int>
// Returns:int
// Method signature:int place(vector <string> a, vector <int> x, vector <int> y)
// 
// 
// NOTES
// -The two stations must be built in two distinct cells of the given rectangular array. It is not allowed to build the stations at coordinates that are outside the given array.
// 
// 
// CONSTRAINTS
// -n will be between 2 and 100, inclusive.
// -m will be between 2 and 100, inclusive.
// -a will contain exactly n elements.
// -Each element of a will contain exactly m characters.
// -Each character in a will be a digit ('0'-'9').
// -x will contain between 1 and 10 elements, inclusive.
// -x and y will contain the same number of elements.
// -Each element in x will be between -(n-1) and (n-1), inclusive.
// -Each element in y will be between -(m-1) and (m-1), inclusive.
// -The pairs (x[k], y[k]) will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// {"11",
//  "11"}
// {0,0}
// {0,1}
// 
// Returns: 4
// 
// A station at (i, j) covers the cells (i, j) and (i, j+1). The optimal solution is to place the two stations at (0, 0) and (1, 0).
// 
// 1)
// {"11",
//  "11"}
// {0,1}
// {0,1}
// 
// Returns: 3
// 
// Here a station at (i, j) also covers (i+1, j+1). One optimal solution is to place the two stations at (0, 0) and (0, 1). The first station also covers the cell (1, 1).
// 
// 2)
// {"15",
//  "61"}
// {0}
// {0}
// 
// Returns: 11
// 
// In this test case each station only covers its own cell. The optimal solution is to build the two stations in the two most important locations.
// 
// 3)
// {"151",
//  "655",
//  "661"}
// {0,0,-1}
// {0,1,0}
// 
// Returns: 33
// 
// 
// 
// 4)
// {"303",
//  "333",
//  "000"}
// {-1,-1}
// {-1,1}
// 
// Returns: 12
// 
// Note that in this test case the offset (0, 0) is not among the offsets (x[k], y[k]).
// 
// 5)
// {"0000000",
//  "1010101"}
// 
// {-1,-1}
// {-1,1}
// 
// Returns: 0
// 
// The stations must be built on some cells of the given field. They cannot be built outside the field.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
