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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ, O(A^-1)
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1, O(A^-1)
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る, O(A^-1)
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す, O(A^-1)
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す, O(n)
    int getSetNum(void) {
        unordered_map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
    // 頂点vと連結な集合を返す, O(n)
    vector<int> getContainingSet(int v) {
        vector<int> ret;
        for (int i = 0; i < data.size(); i++) 
            if (root(i) == root(v))
                ret.push_back(i);
        return ret;
    }

    // 集合ごとに全部の要素を出力, O(n)
    vector<vector<int>> getUnionList(void) {
        map<int, vector<int>> c;
        for (int i = 0; i < data.size(); i++) 
            c[root(i)].pb(i);
        vector<vector<int>> v;
        for (auto x : c) 
            v.push_back(x.second);
        return v;
    }
};
ostream &operator<<(ostream &o, struct UnionFind v) {  v.getUnionList(); int i = 0; for (auto x : v.getUnionList()) { o << i << "\t"; for (auto y : x) o << y << " "; o << endl; i++;} return o; }


class ShadowSculpture {
    public:
        string possible(vector <string> xy, vector <string> yz, vector <string> zx) {
            ll n = xy.size();
            ll b[10][10][10];
            set<ll> disabled;
            rep(i, n) rep(j, n) rep(h, n) b[i][j][h] = 1;
            rep(i, n) rep(j, n) if (xy[i][j] == 'N') rep(h, n) b[i][j][h] = 0, disabled.insert(i*n*n+j*n+h);
            rep(j, n) rep(h, n) if (yz[j][h] == 'N') rep(i, n) b[i][j][h] = 0, disabled.insert(i*n*n+j*n+h);
            rep(h, n) rep(i, n) if (zx[h][i] == 'N') rep(j, n) b[i][j][h] = 0, disabled.insert(i*n*n+j*n+h);
            if (disabled.size() == n * n * n) {
                ll faf = 1;
                for (auto s : {xy, yz, zx}) rep(i, n) rep(j, n) faf &= s[i][j] == 'N';
                return faf ? "Possible" : "Impossible";
            }

            UnionFind uf(n*n*n);
            vll di = {1, -1, 0, 0, 0, 0};
            vll dj = {0, 0, 1, -1, 0, 0};
            vll dh = {0, 0, 0, 0, 1, -1};
            rep(i, n) rep(j, n) rep(h, n) if (b[i][j][h]) {
                rep(d, 6) {
                    ll ii = i + di[d];
                    ll jj = j + dj[d];
                    ll hh = h + dh[d];
                    if (ii < 0 || ii >= n) continue;
                    if (jj < 0 || jj >= n) continue;
                    if (hh < 0 || hh >= n) continue;
                    if (b[ii][jj][hh] == 0) continue;
                    uf.unite(n*n*i+n*j+h, n*n*ii+n*jj+hh);
                }
            }
            auto bb = uf.getUnionList();
            for (auto&& x : bb) {
                if (x.size() == 1 && disabled.count(x[0])) continue;
                cout << x << endl;
                ll tmp[10][10][10] = {};
                vector<string> xy_(n,string(n, 'N'));
                vector<string> yz_(n,string(n, 'N'));
                vector<string> zx_(n,string(n, 'N'));
                for (auto ijh : x) {
                    ll i = ijh / n / n;
                    ll j = ijh - i * n * n; j /= n;
                    ll h = ijh % n;
                    cout << i << " " << j << " " << h << endl;
                    xy_[i][j] = 'Y';
                    yz_[j][h] = 'Y';
                    zx_[h][i] = 'Y';
                }
                cout << xy << " " << yz << " " << zx << endl;
                cout << xy_ << " " << yz_ << " " << zx_ << endl;
                ll faf = 1;
                faf &= xy_ == xy;
                faf &= yz_ == yz;
                faf &= zx_ == zx;
                cout << faf << " #faf"<<endl;
                if (faf) return "Possible";
            }

            return "Impossible";
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, bool hasAnswer, string p3) {
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
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ShadowSculpture *obj;
	string answer;
	obj = new ShadowSculpture();
	clock_t startTime = clock();
	answer = obj->possible(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	vector <string> p1;
	vector <string> p2;
	string p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"YN","NN"};
	p1 = {"YN","NN"};
	p2 = {"YN","NN"};
	p3 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"YN","NY"};
	p1 = {"YN","NY"};
	p2 = {"YN","NY"};
	p3 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"YYY","YNY","YYY"};
	p1 = {"YYY","YNY","YYY"};
	p2 = {"YYY","YNY","YYY"};
	p3 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"YYY","YNY","YYY"};
	p1 = {"NYY","YNY","YYY"};
	p2 = {"YYY","YNY","YYN"};
	p3 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"N"};
	p1 = {"N"};
	p2 = {"N"};
	p3 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 4 -----
	disabled = false;
	p0 = {"Y"};
	p1 = {"N"};
	p2 = {"N"};
	p3 = "Impossible";
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
// A shadow sculpture is a 3D object that seems amorphous but casts a beautiful shadow.
// 
// 
// 
// You want to create a simple shadow sculpture that will consist of unit cubes.
// More precisely, imagine an n*n*n cube that is aligned with the coordinate axes and divided into unit cubes.
// Your sculpture will consist of some of those unit cubes (possibly none or all of them).
// The unit cubes have coordinates (x,y,z) where 0 <= x,y,z < n.
// 
// 
// 
// You have already determined three shadows your sculpture should cast: its orthogonal projections onto the XY, YZ, and ZX plane.
// You are given their description in three vector <string>s: XY, YZ, and ZX.
// 
// 
// 
// Their meaning is as follows:
// For each i and j, the character XY[i][j] is either 'Y' or 'N'.
// The character 'Y' means that the unit square (i,j) of the projection is dark.
// In other words, if XY[i][j] is 'Y', at least one of the cubes with coordinates (i,j,k) has to be a part of your sculpture.
// On the other hand, if XY[i][j] is 'N', none of the cubes with coordinates (i,j,k) may belong into your sculpture.
// YZ and ZX describe the other two projections in the same way.
// E.g., if ZX[i][j] is 'Y', you have to use at least one of the cubes (j,k,i).
// 
// 
// 
// Finally, there is one last constraint:
// Your entire sculpture has to be 6-connected.
// (Formally: Your sculpture must form one connected component, given that two cubes are adjacent iff they share a common face.)
// 
// 
// 
// Return "Possible" if it is possible to construct a sculpture that matches all the given constraints.
// Otherwise, return "Impossible".
// 
// DEFINITION
// Class:ShadowSculpture
// Method:possible
// Parameters:vector <string>, vector <string>, vector <string>
// Returns:string
// Method signature:string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 10, inclusive.
// -XY, YZ and ZX will contain exactly n elements.
// -Each element of XY, YZ and ZX will contain exactly n characters.
// -Each element of XY, YZ and ZX will contain only 'Y' and 'N'.
// 
// 
// EXAMPLES
// 
// 0)
// {"YN","NN"}
// {"YN","NN"}
// {"YN","NN"}
// 
// Returns: "Possible"
// 
// It is possible: we only have one solid cell at (0, 0, 0).
// 
// 1)
// {"YN","NY"}
// {"YN","NY"}
// {"YN","NY"}
// 
// Returns: "Impossible"
// 
// Here it is impossible to make a valid sculpture.
// Note that you can make all three projections look right by using exactly two cubes: (0,0,0) and (1,1,1).
// However, this sculpture is not 6-connected.
// 
// 2)
// {"YYY","YNY","YYY"}
// {"YYY","YNY","YYY"}
// {"YYY","YNY","YYY"}
// 
// Returns: "Possible"
// 
// 
// 
// 3)
// {"YYY","YNY","YYY"}
// {"NYY","YNY","YYY"}
// {"YYY","YNY","YYN"}
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// {"N"}
// {"N"}
// {"N"}
// 
// Returns: "Possible"
// 
// A sculpture that consists of no cubes is connected.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
