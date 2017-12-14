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

// 閉区間なので注意！
//
// (0) 初めは数直線は全て白
// (1) 数直線[l, r]を黒く塗る
// (2) 数直線[l, r]を白く塗る
// (3) 黒く塗られた長さを答える
// (4) 黒く塗られた線の連結成分数を答える
//
// を全てO(log n)以下で行う
template <typename T>
class Interval {
    public:
        set<pair<T, T>> interval; 
        Interval(void) {}

        // 区間[l, r]を追加する
        void add(T l, T r) {
            if (l >= r) return;
            auto it = interval.lower_bound(pair<T, T>(l, -INF));
            while (it != interval.end()) {
                if (!(r < it->se || l > it->fi)) {
                    if (it->se <= l && r <= it->fi) { // ----(--)----
                        return;
                    } else if (it->se <= l && l <= it->fi) { // -----(--    )
                        auto tmp = *it;
                        interval.erase(it);
                        add(tmp.se, r);
                        return;
                    } else if (it->se <= r && r <= it->fi) { // (   --)-----
                        auto tmp = *it; interval.erase(it); tmp.se = l; if (tmp.se < tmp.fi) interval.insert(tmp);
                        return;
                    } else if (l <= it->se && it->fi <= r) { // (  ----  )
                        interval.erase(it);
                        add(l, r);
                        return;
                    } else {
                        assert(0);
                    }
                } else {
                    break;
                }
            }
            interval.insert(pair<T, T>(r, l));
        }

        // 区間[l, r]を消す
        void erase(T l, T r) {
            if (l >= r) return;
            auto it = interval.lower_bound(pair<T, T>(l, -INF));
            while (it != interval.end()) {
                if (it->fi == l) {
                    it++;
                    continue;
                }
                if (!(r < it->se || l > it->fi)) {
                    if (it->se <= l && r <= it->fi) { // ----(--)----
                        auto tmp = *it; T itfi = it->fi; interval.erase(it); tmp.fi = l; if (tmp.se < tmp.fi) interval.insert(tmp);
                        add(r, itfi);
                        return;
                    } else if (it->se <= l && l <= it->fi) { // -----(--    )
                        auto tmp = *it; T itfi = it->fi; interval.erase(it); tmp.fi = l; if (tmp.se < tmp.fi) interval.insert(tmp);
                        erase(itfi, r);
                        return;
                    } else if (it->se <= r && r <= it->fi) { // (   --)-----
                        auto tmp = *it; interval.erase(it); tmp.se = r; if (tmp.se < tmp.fi) interval.insert(tmp);
                        return;
                    } else if (l <= it->se && it->fi <= r) { // (  ----  )
                        T tmp_r = it->fi;
                        interval.erase(it);
                        erase(tmp_r, r);
                        return;
                    } else {
                        assert(0);
                    }
                } else {
                    break;
                }
            }
        }
        // 区間の長さを答える
        T length(void) {
            T ret = 0;
            for (auto x : interval) {
                ret += x.fi - x.se;
            }
            return ret;
        }
        // 区間の数を答える
        int num(void) {
            return interval.size();
        }
        // 点xが区間に含まれるかを判定
        bool contain(T x) {
            auto it = interval.lower_bound(pair<T, T>(x, -INF));
            return it->se <= x && x <= it->fi;
        }

        // デバッグ出力
        void printInterval(void) {
            for (auto x : interval) {
                cout << "[" << x.se << ", " << x.fi << "], ";
            }
            cout << endl;
            T prev = -INF-10;
            for (auto x : interval) {
                assert(prev < x.se);
                assert(x.se < x.fi);
                prev = x.fi;
            }
        }
};



class RadioRange {
    public:
        double RadiusProbability(vector <int> x_, vector <int> y_, vector <int> r_, int z_) {
            ll n = x_.size();
            vector<double> x, y, r; rep(i, n) x.pb(x_[i]), y.pb(y_[i]), r.pb(r_[i]);
            double z = z_;
            Interval<double> in;
            rep(i, n) {
                double d = sqrt(x[i]*1.0*x[i]+y[i]*1.0*y[i]);
                in.add(max(0.0, d-r[i]), min(z, d+r[i]));
                cout << max(0.0, d-r[i]) << " " <<min(z, d+r[i]) <<endl;;
                in.printInterval();
                /*
                if (d < r[i]) {
                    in.add(0, r[i] + d);
                } else {
                    in.add(d - r[i], d + r[i]);
                }
                */
            }
//            in.printInterval();
            /*
            in.erase(-INF, 0);
            in.erase(z, INF);
            in.printInterval();
            */
            return (z - in.length()) / z;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, int p3, bool hasAnswer, double p4) {
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
	RadioRange *obj;
	double answer;
	obj = new RadioRange();
	clock_t startTime = clock();
	answer = obj->RadiusProbability(p0, p1, p2, p3);
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
		res = answer == answer && fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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
	double p4;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {0};
	p1 = {0};
	p2 = {5};
	p3 = 10;
	p4 = 0.5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {0};
	p1 = {0};
	p2 = {10};
	p3 = 10;
	p4 = 0.0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {10};
	p1 = {10};
	p2 = {10};
	p3 = 10;
	p4 = 0.4142135623730951;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {11,-11,0,0};
	p1 = {0,0,11,-11};
	p2 = {10,10,10,10};
	p3 = 31;
	p4 = 0.3548387096774194;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {100};
	p1 = {100};
	p2 = {1};
	p3 = 10;
	p4 = 1.0;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {1000000000};
	p1 = {1000000000};
	p2 = {1000000000};
	p3 = 1000000000;
	p4 = 0.41421356237309503;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = {20,-20,0,0};
	p1 = {0,0,20,-20};
	p2 = {50,50,50,50};
	p3 = 100;
	p4 = 0.3;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = {0,-60,-62,-60,63,-97};
	p1 = {-72,67,61,-8,-32,89};
	p2 = {6,7,8,7,5,6};
	p3 = 918;
	p4 = 0.9407071068962471;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    	// ----- test 7 -----
	disabled = false;
	p0 = {-196, 450, 79, -220, -916, 991, -451, 462, -58, -353, -500, 783, 816, 511};
	p1 = {188, 681, -234, -330, -14, 991, -969, 347, -458, -940, 454, -28, 767, -620};
	p2 = {64, 31, 60, 49, 65, 100, 1, 98, 33, 66, 52, 45, 69, 2};
	p3 = 1484;
	p4 = 0.22007657635156566;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
//
    //{, {188, 681, -234, -330, -14, 991, -969, 347, -458, -940, 454, -28, 767, -620}, {64, 31, 60, 49, 65, 100, 1, 98, 33, 66, 52, 45, 69, 2}, 1484}
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
// Note that the return value is a floating-point number and that in this problem the allowed absolute or relative error has been increased to 1e-6.
// 
// This problem takes place in a plane.
// Nikola works at a radio station that is located in the point (0, 0).
// You can hear the station if and only if you are within a circle with center at (0, 0) and some unknown radius.
// 
// There are some cities near the station.
// Each city has the shape of a circle with some positive integer radius.
// Cities may partially or even completely overlap each other, and some of them may contain the radio station.
// You are given the description of all cities as vector <int>s X, Y, and R.
// For each valid i, there is a city with center at (X[i], Y[i]) and radius R[i].
// 
// The radius of our radio station is bad if there is a city that is only partially covered by the radio signal.
// Otherwise, the radius is good.
// In other words, if there is a point in a city where you can listen to our radio and another point in the same city where you cannot do so, the radius is bad.
// A radius is good if and only if each city is either covered completely by radio signal, or not covered at all.
// 
// You are given a int Z.
// The radius of our radio station is a real number chosen uniformly at random from the range [0, Z].
// Return the probability that the radius is good.
// 
// DEFINITION
// Class:RadioRange
// Method:RadiusProbability
// Parameters:vector <int>, vector <int>, vector <int>, int
// Returns:double
// Method signature:double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z)
// 
// 
// NOTES
// -Your return value must have an absolute or relative error less than 1e-6.
// 
// 
// CONSTRAINTS
// -X will contain between 1 and 100 elements, inclusive.
// -X, Y, and R will each contain the same number of elements.
// -Each element of X will be between -10^9 and 10^9, inclusive.
// -Each element of Y will be between -10^9 and 10^9, inclusive.
// -Each element of R will be between 1 and 10^9, inclusive.
// -Z will be between 1 and 10^9, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {0}
// {0}
// {5}
// 10
// 
// Returns: 0.5
// 
// Our radio station is in the center of a city with radius 5, and we are choosing the radius for the station uniformly at random from [0,10].
// Radii in [0,5) are all bad, because people in the center of the city can hear our radio but people on its boundary cannot.
// Radii in [5,10] are all good, as the entire city is covered.
// Hence, the probability of having a good radius is 5/10 = 0.5.
// 
// 1)
// {0}
// {0}
// {10}
// 10
// 
// Returns: 0.0
// 
// Our radio station is in the center of a city with radius 10, and we are choosing the radius for the station uniformly at random from [0,10].
// In this case, the only good radius is 10, but the probability that it will be chosen is zero.
// 
// 2)
// {10}
// {10}
// {10}
// 10
// 
// Returns: 0.4142135623730951
// 
// The center of the city is at (10, 10) and its radius is 10.
// The good radii for our station are those where the city is not covered at all.
// These are the radii from 0 to approximately 4.14.
// 
// 3)
// {11, -11, 0, 0}
// {0, 0, 11, -11}
// {10, 10, 10, 10}
// 31
// 
// Returns: 0.3548387096774194
// 
// Here we have four cities.
// They are located to the north, south, east, and west of the station.
// A radius is good if it lies in [0,1) or in [21,31].
// 
// 4)
// {100}
// {100}
// {1}
// 10
// 
// Returns: 1.0
// 
// It is possible that some cities will not be covered even if the radius of our radio station is Z.
// 
// 5)
// {1000000000}
// {1000000000}
// {1000000000}
// 1000000000
// 
// Returns: 0.41421356237309503
// 
// 
// 
// 6)
// {20, -20, 0, 0}
// {0, 0, 20, -20}
// {50, 50, 50, 50}
// 100
// 
// Returns: 0.3
// 
// 
// 
// 7)
// {0, -60, -62, -60, 63, -97}
// {-72, 67, 61, -8, -32, 89}
// {6, 7, 8, 7, 5, 6}
// 918
// 
// Returns: 0.9407071068962471
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
