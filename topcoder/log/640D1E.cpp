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
#define forall(a, f) all_of((a).begin(), (a).end(), (f))
#define exists(it, a, f) (((it)=find_if((a).begin(), (a).end(), (f)))!=(a).end())

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
#define ldout fixed << setprecision(40) 

template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); return s; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }

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


class ChristmasTreeDecoration {
    public:
        int solve(vector <int> c, vector <int> x, vector <int> y) {
            ll n = c.size();
            UnionFind uf(n);
            rep(i, x.size()) 
                if (c[x[i]-1] != c[y[i]-1]) 
                    uf.unite(x[i]-1, y[i]-1);
            return uf.getSetNum() - 1;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
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
	cout << "}";
	cout << "]" << endl;
	ChristmasTreeDecoration *obj;
	int answer;
	obj = new ChristmasTreeDecoration();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1, p2);
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
	vector <int> p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,1,2,2};
	p1 = {1,2,3,4};
	p2 = {2,3,4,1};
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,1,2,2};
	p1 = {1,2,3,4,1,2};
	p2 = {2,3,4,1,3,4};
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {50,50,50,50};
	p1 = {1,2,3,1,1,2};
	p2 = {2,3,4,4,3,4};
	p3 = 3;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,4,2,3};
	p1 = {1,2,3};
	p2 = {2,3,4};
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,1,1,2,2,2,3,3,3,4,4,4};
	p1 = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1};
	p2 = {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4};
	p3 = 5;
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
// 
// Christmas is just around the corner, and Alice just decorated her Christmas tree.
// There are N stars on the tree.
// The stars are numbered 1 through N.
// Additionally, each star has some color.
// You are given the colors of stars as a vector <int> col with N elements.
// For each i, col[i] is the color of star i+1.
// (Different integers represent different colors.)
// 
// 
// 
// Alice has prepared N-1 ribbons and she is now going to attach them to the tree.
// Each ribbon will connect two of the stars.
// The ribbons have to be placed in such a way that all stars and ribbons will hold together.
// (In other words, in the resulting arrangement the stars and ribbons will correspond to vertices and edges of a tree.)
// 
// 
// 
// Only some pairs of stars can be connected by a ribbon.
// You are given a list of all such pairs of stars in two vector <int>s: x and y.
// For each valid i, it is possible to add a ribbon that connects the stars with numbers x[i] and y[i].
// 
// 
// 
// According to Alice, a ribbon that connects two stars that share the same color is less beautiful than a ribbon that connects two stars with different colors.
// Therefore, she would like to minimize the number of ribbons that connect two same-colored stars.
// Compute and return the smallest possible number of such ribbons.
// 
// 
// DEFINITION
// Class:ChristmasTreeDecoration
// Method:solve
// Parameters:vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int solve(vector <int> col, vector <int> x, vector <int> y)
// 
// 
// CONSTRAINTS
// -N will be between 2 and 50, inclusive.
// -The number of elements in col will be N exactly.
// -The number of elements in x will be between 1 and 200, inclusive.
// -The number of elements in y will be the same as the number of elements in x.
// -All elements of x and y will be between 1 and N, inclusive.
// -For each i, the numbers x[i] and y[i] will be different.
// -All unordered pairs (x[i], y[i]) will be distinct.
// -There will be at least one way to choose N-1 ribbons that form a connected graph.
// 
// 
// EXAMPLES
// 
// 0)
// {1,1,2,2}
// {1,2,3,4}
// {2,3,4,1}
// 
// Returns: 1
// 
// We have four stars. Stars 1 and 2 have the same color, and stars 3 a 4 have the same color.
// There are four pairs of stars we may connect: 1-2, 2-3, 3-4, and 4-1.
// One optimal solution is to use the following ribbons: 2-3, 3-4, and 4-1.
// Two of these are beautiful (2-3 and 4-1) and only one (3-4) is not beautiful.
// 
// 1)
// {1,1,2,2}
// {1,2,3,4,1,2}
// {2,3,4,1,3,4}
// 
// Returns: 0
// 
// Now we can have three beautiful ribbons.
// 
// 2)
// {50,50,50,50}
// {1,2,3,1,1,2}
// {2,3,4,4,3,4}
// 
// Returns: 3
// 
// All stars have the same color. Regardless of how we attach the ribbons, none of them will be beautiful.
// 
// 3)
// {1,4,2,3}
// {1,2,3}
// {2,3,4}
// 
// Returns: 0
// 
// 
// 
// 4)
// {1,1,1,2,2,2,3,3,3,4,4,4}
// {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1}
// {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4}
// 
// Returns: 5
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
