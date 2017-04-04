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

template <class BidirectionalIterator>
bool next_combination (BidirectionalIterator first1,
        BidirectionalIterator last1,
        BidirectionalIterator first2,
        BidirectionalIterator last2)
{
    if ((first1 == last1) || (first2 == last2)) {
        return false;
    }
    BidirectionalIterator m1 = last1;
    BidirectionalIterator m2 = last2; --m2;
    while (--m1 != first1 && !(*m1 <*m2)){
    }
    bool result = (m1 == first1) && !(*first1 <*m2);
    if (!result) {
        while (first2 != m2 && !(*m1 <*first2)) {
            ++first2;
        }
        first1 = m1;
        std::iter_swap(first1, first2);
        ++first1;
        ++first2;
    }
    if ((first1 != last1) && (first2 != last2)) {
        m1 = last1; m2 = first2;
        while ((m1 != first1) && (m2 != last2)) {
            std::iter_swap(--m1, m2);
            ++m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return !result;
}

template <class BidirectionalIterator>
bool next_combination (BidirectionalIterator first,
        BidirectionalIterator middle,
        BidirectionalIterator last)
{
    return next_combination (first, middle, middle, last);
}
template <class BidirectionalIterator>
    inline
bool prev_combination (BidirectionalIterator first,
        BidirectionalIterator middle,
        BidirectionalIterator last)
{
    return next_combination (middle, last, first, middle);
}


class BearKRoads {
    public:
        int maxHappy(vector <int> x, vector <int> a, vector <int> b, int k) {
            int n = x.size(), m = a.size();
            vector<P> edges;
            rep(i, m) {
                edges.pb(P(x[a[i]]+x[b[i]], i));
            }
            sort(all(edges)); reverse(all(edges));
            
            int ret = 0;
            vector<int> data(min<int>(35, m));

            vector<int> e;
            bitset<1010> used;
            for(int i=0; i<data.size(); i++){ data[i]=i; }
            while (1) {
                rep(i, k) {
                    int tmp = edges[data[i]].se;
                    e.pb(a[tmp]), e.pb(b[tmp]);
                }
                int s = 0;
                for (auto t : e) if (!used[t]) {
                    used[t] = 1;
                    s += x[t];
                }
                for (auto t : e) 
                    used[t] = 0;

                chmax(ret, s);
                e.clear();
               
                if (!next_combination(data.begin(), data.begin()+k, data.end()))
                    break;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, int p3, bool hasAnswer, int p4) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
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
    cout << "}" << "," << p3;
    cout << "]" << endl;
    BearKRoads *obj;
    int answer;
    obj = new BearKRoads();
    clock_t startTime = clock();
    answer = obj->maxHappy(p0, p1, p2, p3);
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

    vector <int> p0;
    vector <int> p1;
    vector <int> p2;
    int p3;
    int p4;

    // ----- test 0 -----
    disabled = false;
    p0 = {10,50,50,10};
    p1 = {0,1,2};
    p2 = {1,2,3};
    p3 = 1;
	p4 = 100;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {10,50,50,10};
	p1 = {0,1,2};
	p2 = {1,2,3};
	p3 = 2;
	p4 = 120;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {42,100,500};
	p1 = {0,1};
	p2 = {1,2};
	p3 = 2;
	p4 = 642;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {42,100,500,999,999,999,999};
	p1 = {0,1};
	p2 = {1,2};
	p3 = 2;
	p4 = 642;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {969,467,808,263,179,428,595,557,406,80};
	p1 = {5,4,9,7,9,3};
	p2 = {4,0,8,8,0,1};
	p3 = 3;
	p4 = 2841;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {1,2,3,4};
	p1 = {0,0,0};
	p2 = {1,2,3};
	p3 = 2;
	p4 = 8;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = {1,2,3,4,2};
	p1 = {0,0,0,1};
	p2 = {1,2,3,4};
	p3 = 2;
	p4 = 9;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = {8,18,14,10,7,16,4,19,6,12,17,10,12,3,15,8,15,12};
	p1 = {0,15,1,5,7,3,17,4,15,3,13,14,4,7};
	p2 = {8,10,16,13,2,10,2,10,11,13,0,9,3,6};
	p3 = 7;
	p4 = 173;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
   // ----- test 7 -----
	disabled = false;
	p0 = {371, 12, 198, 367, 599, 987, 760, 216, 655, 837, 348, 954, 780, 512, 599, 860, 727, 675, 105, 578, 216, 987, 799, 355, 178, 808, 471, 467, 843, 919, 966, 349, 362, 125, 523, 610, 537, 582, 525, 68, 694, 734, 725, 853, 125, 188, 944, 33, 670, 185};
	p1 = {48, 15, 2, 14, 20, 32, 32, 10, 2, 42, 13, 11, 33, 35, 48, 45, 9, 37, 37, 27, 29, 14, 30, 26, 14, 4, 47, 2, 12, 42, 8, 31, 10, 3, 29, 31, 17, 39, 45, 33, 3, 27, 16, 25, 35, 6, 32, 16, 11, 31};
	p2 = {39, 13, 47, 17, 11, 49, 38, 18, 33, 12, 1, 8, 34, 38, 18, 36, 44, 47, 38, 4, 26, 6, 23, 5, 37, 44, 22, 21, 23, 39, 15, 5, 7, 30, 0, 6, 28, 44, 21, 45, 26, 46, 21, 0, 24, 8, 48, 49, 15, 34};
	p3 = 3;
	p4 = 5046;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

		// ----- test 7 -----
	disabled = false;
	p0 = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,};
	p1 = {0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,};
	p2 = {8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,8,10,16,13,2,};
	p3 = 7;
	p4 = 173;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
	
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
// Bearland consists of N cities, numbered 0 through N-1.
// For each i, city i is inhabited by x[i] citizens.
// You are given the vector <int> x with N elements.
// 
// There are M bidirectional roads.
// Each road connects two different cities.
// No two roads connect the same pair of cities.
// 
// Do you know that feeling when your fridge is full and you still don't know what to eat (and you eventually order a pizza)?
// The citizens of Bearland have the same feeling whenever they have to choose from too many roads.
// Thus, the road network in Bearland was designed in such a way that every city is incident to at most three roads.
// In other words, each city is directly connected to at most three other cities.
// 
// You are given the description of the road network: the vector <int>s a and b with M elements each.
// For each valid i, there is a road that connects cities a[i] and b[i].
// 
// All roads in Bearland were built a long time ago and their current condition is quite bad.
// Limak, a public transport inspector, can choose a few of the existing roads and renovate them.
// You are given the int K: the maximum number of roads Limak can renovate.
// 
// After the renovation, each citizen will be happy if and only if at least one of the roads from their city was renovated.
// Find and return the maximum number of happy citizens.
// 
// DEFINITION
// Class:BearKRoads
// Method:maxHappy
// Parameters:vector <int>, vector <int>, vector <int>, int
// Returns:int
// Method signature:int maxHappy(vector <int> x, vector <int> a, vector <int> b, int K)
// 
// 
// NOTES
// -N will be between 2 and 1000, inclusive.
// -x will contain exactly N elements.
// -Each element in x will be between 1 and 999, inclusive.
// -M will be between 1 and 1000.
// -a and b will each contain exactly M elements.
// -Each element in a and in b will be between 0 and N-1, inclusive.
// -No road will connect a city to itself.
// -No two roads will connect the same pair of cities.
// -Every city will be incident to at most three roads.
// -K will be between 1 and 7, inclusive.
// -K will not be greater than M.
// 
// 
// EXAMPLES
// 
// 0)
// {10, 50, 50, 10}
// {0, 1, 2}
// {1, 2, 3}
// 1
// 
// Returns: 100
// 
// There are four cities and three roads: 0-1, 1-2 and 2-3.
// We can only renovate at most one road.
// It is optimal to renovate the road 1-2.
// This makes 100 citizens happy.
// 
// 1)
// {10, 50, 50, 10}
// {0, 1, 2}
// {1, 2, 3}
// 2
// 
// Returns: 120
// 
// This is the same country but now we have K=2.
// Now the optimal solution is to renovate the roads 0-1 and 2-3.
// This makes all 120 citizens happy.
// 
// 2)
// {42, 100, 500}
// {0, 1}
// {1, 2}
// 2
// 
// Returns: 642
// 
// We can renovate both roads.
// All 42 + 100 + 500 = 642 citizens will be happy.
// 
// 3)
// {42, 100, 500, 999, 999, 999, 999}
// {0, 1}
// {1, 2}
// 2
// 
// Returns: 642
// 
// 
// 
// 4)
// {969,467,808,263,179,428,595,557,406,80}
// {5,4,9,7,9,3}
// {4,0,8,8,0,1}
// 3
// 
// Returns: 2841
// 
// 
// 
// 5)
// {1,2,3,4}
// {0,0,0}
// {1,2,3}
// 2
// 
// Returns: 8
// 
// 
// 
// 6)
// {1,2,3,4,2}
// {0,0,0,1}
// {1,2,3,4}
// 2
// 
// Returns: 9
// 
// 
// 
// 7)
// {8,18,14,10,7,16,4,19,6,12,17,10,12,3,15,8,15,12}
// {0,15,1,5,7,3,17,4,15,3,13,14,4,7}
// {8,10,16,13,2,10,2,10,11,13,0,9,3,6}
// 7
// 
// Returns: 173
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
