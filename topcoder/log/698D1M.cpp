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
#define ldout fixed << setprecision(40) 

static const long long mo = 1e9+7;
class Mod {
    public:
        int num;
        Mod() : Mod(0) {}
        Mod(long long int n) : num(n) { }
        Mod(const string &s){ long long int tmp = 0; for(auto &c:s) tmp = (c-'0'+tmp*10) % mo; num = tmp; }
        Mod(int n) : Mod(static_cast<long long int>(n)) {}
        operator int() { return num; }
};
istream &operator>>(istream &is, Mod &x) { long long int n; is >> n; x = n; return is; }
ostream &operator<<(ostream &o, const Mod &x) { o << x.num; return o; }
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mo); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mo + a.num - b.num) % mo); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mo); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod factorial(const long long n) {
    if (n < 0) return 0;
    Mod ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
Mod operator^(const Mod a, const long long n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod modpowsum(const Mod a, const long long b) {
    if (b == 0) return 0;
    if (b % 2 == 1) return modpowsum(a, b - 1) * a + Mod(1);
    Mod result = modpowsum(a, b / 2);
    return result * (a ^ (b / 2)) + result;
}

/*************************************/
// 以下、modは素数でなくてはならない！
/*************************************/
Mod inv(const Mod a) { return a ^ (mo - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }
Mod operator/(const long long int a, const Mod b) { assert(b.num != 0); return Mod(a) * inv(b); }
Mod operator/=(Mod &a, const Mod b) { assert(b.num != 0); return a = a * inv(b); }

// n!と1/n!のテーブルを作る。
// nCrを高速に計算するためのもの。
//
// assertでnを超えていないかをきちんとテストすること。
//
// O(n log mo)
vector<Mod> fact, rfact;
void constructFactorial(const long long n) {
    fact.resize(n);
    rfact.resize(n);
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < n; i++) {
        fact[i] = fact[i-1] * i;
        rfact[i] = Mod(1) / fact[i];
    }
}

// O(1)
Mod nCr(const long long n, const long long r) {
//    assert(n < (long long)fact.size());
    if (n < 0 || r < 0) return 0;
    return fact[n] * rfact[r] * rfact[n-r];
}

// O(k log mo) 
Mod nCrWithoutConstruction(const long long n, const long long k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    Mod ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= n - (Mod)i;
        ret /= Mod(i+1);
    }
    return ret;
}
// n*mの盤面を左下から右上に行く場合の数
// O(1)
Mod nBm(const long long n, const long long m) {
    if (n < 0 || m < 0) return 0;
    return nCr(n + m, n);
}


class IntersectingConvexHull {
    public:
        int count(vector <int> x_, vector <int> y_) {
            constructFactorial(200);
            vll x = conv(x_), y = conv(y_);
            ll n = x.size();

            Mod ret = 0;
            rep(i, n) rep(j, n) if (i < j) {
                // #iと#jの直線より上・下の点は合計n-2個。
                ll l = 0, u = 0;
                rep(k, n) if (k != i && k != j) 
                    ((y[k]-y[i])*(x[j]-x[i])>(x[k]-x[i])*(y[j]-y[i]) ? l : u)++;

                ret += ((Mod(2)^l)-nCr(l, 0)-nCr(l, 1)) * ((Mod(2)^u)-nCr(u, 0)-nCr(u, 1)) * Mod(2);
            }
            ret *= -1;

            repi(u, 3, n+1) repi(l, 3, n+1-u) 
                ret += nCr(n, u) * nCr(n-u, l);

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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
	cout << "}";
	cout << "]" << endl;
	IntersectingConvexHull *obj;
	int answer;
	obj = new IntersectingConvexHull();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
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
		res = answer == p2;
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
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,0,-1,-1,0,1};
	p1 = {1,2,1,-1,-2,-1};
	p2 = 14;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {444,-646,367,302,-506,810};
	p1 = {-530,660,872,-78,-621,77};
	p2 = 10;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {-737,-245,-51,943,-7,1000,-976,-723};
	p1 = {-355,898,-372,-585,-98,-53,490,-954};
	p2 = 900;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {-928,852,840,813,-564,-594,-667,838,-74,-675,-530,-476,-154,702,817,969,845,592,867,-330};
	p1 = {-898,682,604,22,-452,901,464,-624,-272,-792,-906,36,249,-287,871,877,446,910,943,427};
	p2 = 296398747;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
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
// You are given a finite set S of points in the plane.
// For each valid i, one of those points has coordinates (x[i], y[i]).
// The points are all distinct and no three of them are collinear.
// 
// 
// Below, CH(s) denotes the convex hull of the set s: that is, the smallest of all convex polygons that contain the set s.
// 
// 
// We say that the ordered pair (s1, s2) is interesting if the following conditions are satisfied:
// 
// s1 is a subset of S
// s2 is a subset of S
// the sets s1 and s2 are disjoint (i.e., they have no elements in common)
// the intersection of the convex hulls CH(s1) and CH(s2) has a positive area
// 
// 
// Note that some points from S may remain unused (i.e., they will be neither in s1, nor in s2).
// 
// 
// You are given the coordinates of all points: the vector <int>s x and y.
// Please compute and return the number of interesting pairs of sets, modulo 10^9 + 7.
// 
// DEFINITION
// Class:IntersectingConvexHull
// Method:count
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int count(vector <int> x, vector <int> y)
// 
// 
// CONSTRAINTS
// -x will contain between 6 and 100 elements, inclusive.
// -x and y will contain the same number of elements.
// -Each element in x will be between -1,000,000 and 1,000,000, inclusive.
// -Each element in y will be between -1,000,000 and 1,000,000, inclusive.
// -All points will be distinct.
// -No three points will lie on the same line.
// 
// 
// EXAMPLES
// 
// 0)
// {1,0,-1,-1,0,1}
// {1,2,1,-1,-2,-1}
// 
// Returns: 14
// 
// We have 14 solutions:
// 
// s1 = {0,1,3}, s2 = {2,4,5}
// s1 = {0,2,3}, s2 = {1,4,5}
// s1 = {0,1,4}, s2 = {2,3,5}
// s1 = {0,2,4}, s2 = {1,3,5}
// s1 = {1,2,4}, s2 = {0,3,5}
// s1 = {0,3,4}, s2 = {1,2,5}
// s1 = {1,3,4}, s2 = {0,2,5}
// s1 = {0,2,5}, s2 = {1,3,4}
// s1 = {1,2,5}, s2 = {0,3,4}
// s1 = {0,3,5}, s2 = {1,2,4}
// s1 = {1,3,5}, s2 = {0,2,4}
// s1 = {2,3,5}, s2 = {0,1,4}
// s1 = {1,4,5}, s2 = {0,2,3}
// s1 = {2,4,5}, s2 = {0,1,3}
// 
// 
// 1)
// {444, -646, 367, 302, -506, 810}
// {-530, 660, 872, -78, -621, 77}
// 
// Returns: 10
// 
// This time we have 10:
// 
// s1 = {0,1,2}, s2 = {3,4,5}
// s1 = {0,1,3}, s2 = {2,4,5}
// s1 = {0,2,3}, s2 = {1,4,5}
// s1 = {0,2,4}, s2 = {1,3,5}
// s1 = {2,3,4}, s2 = {0,1,5}
// s1 = {0,1,5}, s2 = {2,3,4}
// s1 = {1,3,5}, s2 = {0,2,4}
// s1 = {1,4,5}, s2 = {0,2,3}
// s1 = {2,4,5}, s2 = {0,1,3}
// s1 = {3,4,5}, s2 = {0,1,2}
// 
// 
// 2)
// {-737, -245, -51, 943, -7, 1000, -976, -723}
// {-355, 898, -372, -585, -98, -53, 490, -954}
// 
// Returns: 900
// 
// 
// 
// 3)
// {-928, 852, 840, 813, -564, -594, -667, 838, -74, -675, -530, -476, -154, 702, 817, 969, 845, 592, 867, -330}
// {-898, 682, 604, 22, -452, 901, 464, -624, -272, -792, -906, 36, 249, -287, 871, 877, 446, 910, 943, 427}
// 
// Returns: 296398747
// 
// Don't forget to mod 10^9+7.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
