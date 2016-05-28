#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

class ShadowSculpture {
    public:
        string possible(vector <string> xy, vector <string> yz, vector <string> zx) {
            ll n = xy.size();
            bool a[10][10][10];
            rep(x, n) rep(y, n) rep(z, n) {
                a[x][y][z] = 1;
            }
            rep(x, n) rep(y, n) rep(z, n) {
                if (xy[x][y] == 'N')
                    a[x][y][z] = 0;
                if (yz[y][z] == 'N')
                    a[x][y][z] = 0;
                if (zx[z][x] == 'N')
                    a[x][y][z] = 0;
            }
            rep(z, n) { cout << "z = " << z << endl; 
                rep(y, n) {
                    rep(x, n)  {
                        cout << a[x][y][z];
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << "xy" << endl;
            rep(x, n) rep(y, n) {
                bool tmp = 0; rep(z, n) if (a[x][y][z]) tmp = 1;
                cout << x << " " << y << " " << tmp << endl;
                if (xy[x][y] != (tmp ? 'Y' : 'N')) return "Impossible";
            }
            cout << "yz" << endl;
            rep(y, n) rep(z, n) {
                bool tmp = 0; rep(x, n) if (a[x][y][z]) tmp = 1;
                cout << y << " " << z << " " << tmp << endl;
                if (yz[y][z] != (tmp ? 'Y' : 'N')) return "Impossible";
            }
            cout << "zx" << endl;
            rep(z, n) rep(x, n) {
                bool tmp = 0; rep(y, n) if (a[x][y][z]) tmp = 1;
                cout << z << " " << x << " " << tmp << endl;
                if (zx[z][x] != (tmp ? 'Y' : 'N')) return "Impossible";
            }


            ll num = 0;
            ll sx, sy, sz;
            rep(x, n) rep(y, n) rep(z, n) {
                if (a[x][y][z]) {
                    num++;
                    sx = x; sy = y; sz = z;
                }
            }
            if (!num) {
                return "Possible";
            }

            bool memo[10][10][10] = {};
            vll dx = {1, 0, 0, -1, 0, 0};
            vll dy = {0, 1, 0, 0, -1, 0};
            vll dz = {0, 0, 1, 0, 0, -1};
            function<void(ll, ll, ll)> f = [&](ll x, ll y, ll z) { 
                rep(i, 6) {
                    if (x + dx[i] >= n || y + dy[i] >= n || z + dz[i] >= n) continue;
                    if (x + dx[i] <  0 || y + dy[i] <  0 || z + dz[i] <  0) continue;
                    if (memo[x+dx[i]][y+dy[i]][z+dz[i]]) continue;
                    if (!a[x+dx[i]][y+dy[i]][z+dz[i]]) continue;
                    memo[x+dx[i]][y+dy[i]][z+dz[i]] = 1;
                    f(x+dx[i], y+dy[i], z+dz[i]);
                }
            };
            memo[sx][sy][sz] = 1;
            f(sx, sy, sz);
            ll connected_num = 0;
            rep(x, n) rep(y, n) rep(z, n) {
                if (memo[x][y][z])
                    connected_num++;
            }
            cout << connected_num << " " << num << endl;
            return (num == connected_num ? "Possible" : "Impossible");
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
	
	// ----- test 5 -----
	disabled = false;
	p0 = {"NYYYYYYY", "NYYYYYYY", "YNYYYNYY", "YYYYYYYN", "YYYYYYNY", "YYNYYYYY", "YYYYYNYN", "YYNNYYYY"};
	p1 = {"YYYYYYYY", "YNYYNYYY", "YNYYYYYY", "NYYYYYYY", "YYYYYNYY", "YYNYYYYY", "YYYNYNYN", "YYYYYYYY"};
	p2 = {"YNYYYYYY", "YNYYNYYY", "YYYNYYNN", "YYNYNYNY", "YNYYNYYY", "YYYYYYYN", "YYYYYYNN", "NNYYYYYY"};
	p3 = "Possible";
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
