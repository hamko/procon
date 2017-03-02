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

void compress(map<ll, ll>& zip, map<ll, ll>& unzip, vector<ll> x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
}
// 二次元累積和の計算
// 構築O(n^2)
// クエリO(1)
const function<bool(ll, ll)> f2_default = [](ll x, ll y) { return 1; };
class Sum2d {
public:
    vector<vll> data;
    vector<vll> sumdata;
    Sum2d(vector<vll>& d, function<bool(ll, ll)> f = f2_default) {
        int n = d.size(), m = d[0].size();
        data = d;
        sumdata = vector<vll>(n+1, vll(m+1, 0));
        rep(i, n) rep(j, m) if(f(i, j)) sumdata[i+1][j+1] = data[i][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i+1][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i][j+1];
//        rep(i, n+1) {{rep(j, m+1) cout << sumdata[i][j] << " "; } cout << endl;}
    }
    // [(i0, j0), (i1, j1))の小区間の総和 (半開区間)
    ll sum(int i0, int j0, int i1, int j1) {
        return sumdata[i1][j1]-sumdata[i1][j0]-sumdata[i0][j1]+sumdata[i0][j0];
    }
    // [(i, j), (i+ilen, j+jlen))の小区間の総和 (半開区間)
    ll suml(int i, int j, int ilen, int jlen) {
        return this->sum(i, j, i+ilen, j+jlen);
    }
};


class MinimumSquare {
    public:
        long long minArea(vector <int> x_, vector <int> y_, int k) {
            if (k == 1) return 4;
            vll x = conv(x_);
            vll y = conv(y_);
            ll n = x.size();
            map<ll, ll> x_for;
            map<ll, ll> x_rev;
            map<ll, ll> y_for;
            map<ll, ll> y_rev;
            compress(x_for, x_rev, x);
            compress(y_for, y_rev, y);
            cout << x_for << " " << x_rev << endl;
            cout << y_for << " " << y_rev << endl;

            vvll b(n, vll(n));
            rep(i, n) {
                b[x_for[x[i]]][y_for[y[i]]] = 1;
            }
            cout << b << endl;

            Sum2d s(b);
            cout << s.sumdata << endl;

            ll ret = -1;
            ll m = INF;
            rep(i, n) {
                rep(j, n) if (i != j) {
                    ll xi = x_for[x[i]];
                    ll yi = y_for[y[i]];
                    ll xj = x_for[x[j]];
                    ll yj = y_for[y[j]];
                    if (xi > xj) continue;
                    if (yi > yj) continue;
                    cout << P(xi, yi) << " " << P(xj, yj) << " " << s.sum(xi, yi, xj+1, yj+1)<< endl;
                    if (s.sum(xi, yi, xj+1, yj+1) < k) continue;
                    cout << "ok" << endl;
                    if (m > (x[j] - x[i]) * (y[j] - x[i])) {
                        m = (x[j] - x[i]) * (y[j] - x[i]);
                        ret = max(x[j] - x[i], y[j] - y[i]);
                        cout << x[j] << " " <<  x[i] << " " <<  y[j] << " " <<  y[i] << endl;;
                        cout << x[j] - x[i] << " " <<  y[j] - y[i] << endl;;
                    }
                }
            }

            ret++;
            ret++;
            return ret * ret;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, long long p3) {
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
	cout << "}" << "," << p2;
	cout << "]" << endl;
	MinimumSquare *obj;
	long long answer;
	obj = new MinimumSquare();
	clock_t startTime = clock();
	answer = obj->minArea(p0, p1, p2);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	long long p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {0,3};
	p1 = {0,7};
	p2 = 2;
	p3 = 81ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {-4,3,1};
	p1 = {3,-1,-2};
	p2 = 2;
	p3 = 16ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {0,0,1,1,2,2};
	p1 = {0,1,0,1,0,1};
	p2 = 4;
	p3 = 9ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1000000000,1000000000,1000000000,-1000000000,-1000000000,-1000000000};
	p1 = {1000000000,0,-1000000000,1000000000,0,-1000000000};
	p2 = 3;
	p3 = 4000000008000000004ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {-47881,28623,1769,-38328,-16737,16653,-23181,37360,41429,26282,254,728,8299,-41080,-29498,17488,-23937,-11,33319,25232};
	p1 = {-46462,48985,-43820,-19587,-33593,-28337,13667,-48131,-5568,-2332,-41918,-31370,-3695,42599,-37788,-40096,39049,25045,-2122,3874};
	p2 = 8;
	p3 = 1695545329ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
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
// There are N points in the plane. You are given their description as two vector <int>s, x and y, with N elements each. The N points have coordinates (x[0],y[0]), (x[1],y[1]), ..., (x[N-1],y[N-1]).
// 
// You want to draw a single square onto the plane. The vertices of the square must have integer coordinates, and the sides of the square must be parallel to the coordinate axes. There is one additional constraint: at least K of the N given points must lie strictly inside the square (i.e., not on its boundary).
// 
// You are given x, y, and the int K. Return the smallest possible area of a square that satisfies the constraints above.
// 
// DEFINITION
// Class:MinimumSquare
// Method:minArea
// Parameters:vector <int>, vector <int>, int
// Returns:long long
// Method signature:long long minArea(vector <int> x, vector <int> y, int K)
// 
// 
// CONSTRAINTS
// -x will contain between 2 and 100 elements, inclusive.
// -y will contain the same number of elements as x.
// -K will be between 1 and the number of elements in x, inclusive.
// -All points will be pairwise distinct.
// -Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {0, 3}
// {0, 7}
// 2
// 
// Returns: 81
// 
// The square we seek must contain both given points. One optimal solution is the square with opposite corners at (-1,-1) and (8,8).
// 
// 1)
// {-4, 3, 1}
// {3 , -1, -2}
// 2
// 
// Returns: 16
// 
// 
// 
// 2)
// {0, 0, 1, 1, 2, 2}
// {0, 1, 0, 1, 0, 1}
// 4
// 
// Returns: 9
// 
// 
// 
// 3)
// {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000}
// {1000000000, 0, -1000000000, 1000000000, 0, -1000000000}
// 3
// 
// Returns: 4000000008000000004
// 
// In this case one of the optimal solutions is a square that contains all six points.
// 
// 4)
// {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232}
// {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874}
// 8
// 
// Returns: 1695545329
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
