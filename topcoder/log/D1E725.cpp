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

class FiveRooks {
    public:
        vector<string> gen(void) {
            vector <string> b;
            while (1) {
                b = vector<string>(8);
                rep(i, 8) {
                    string s;
                    rep(j, 8) {
                        s += (rand() % 2 ? "R" : ".");
                    }
                    b[i] = s;
                }
                ll ret = 0;
                rep(i, 8) {
                    rep(j, 8) {
                        ret += b[i][j] == 'R';
                    }
                }
                if (ret >= 33) break;
            }
            return b;
        }
        bool check(vector<string> b, vector <int> ret) {
            if (ret.size() != 10) return cout << " size" << endl, false;
            rep(i, 10) {
                if (ret[i] < 0 || ret[i] >= 8) return cout << " index range" << endl, false;
            }
            rep(i, 5) repi(j, i+1, 5) {
                if (ret[2*i] == ret[2*j]) return cout << " x dup" << endl, false;
                if (ret[2*i+1] == ret[2*j+1]) return cout << " y dup" << endl, false;
            }
            rep(i, 5) {
                if (b[ret[2*i]][ret[2*i+1]] != 'R') return cout << " no r" << endl, false;
            }
            return true;
        }
        vector <int> ans(vector <string> b) {
            vector<P> r;
            rep(i, 8) {
                rep(j, 8) {
                    if (b[i][j] == 'R') {
                        r.pb(P(i, j));
                    }
                }
            }
            ll n = r.size();
            rep(i, n) repi(j, i+1, n) repi(h, j+1, n) repi(k, h+1, n) repi(l, k+1, n) {
                vll f = {i, j, h, k, l};
                vll tmp = {7, 11, 16, 22, 24} ;
                ll hoge = 0;
                if (f == tmp) {
                    cout << f << endl;
                }
                ll no = 0;
                rep(x, 5) {
                    repi(y, x+1, 5) {
                        if (r[f[x]].fi == r[f[y]].fi) { if (hoge) {cout << x << " " << y << endl;} no = 1; break;}
                        if (r[f[x]].se == r[f[y]].se) { if (hoge) {cout << x << " " << y << endl;} no = 1; break;} 
                    }
                    if (no) break;
                }
                if (!no) {
                    vector<int> ret;
                    for (auto x : f) {
                        assert(b[r[x].fi][r[x].se] == 'R');
                        ret.pb(r[x].fi), ret.pb(r[x].se);
                    }
                    return ret; 
                }
            }
            assert(0);
            return {};

        }
        vector<P> rocks;
        vector <int> hack(vector <string> b) {
            vector<int> ans;
            rep(i, b.size()) {
                rep(j, b.size()) {
                    if (b[i][j]=='R')
                        rocks.pb({i, j});
                }
            }
            vector<int> is_i(8,1),is_j(8,1);
            int im=1,np=0,mag[10]={};
            for (im=1;im>0;np++){
                if (np<rocks.size()) {
                    if(is_i[rocks[np].fi]&&is_j[rocks[np].se]){
                        if (im==5) {
                            mag[im]=np;
                            repi(i, 1, im+1) {
                                ans.pb(rocks[mag[i]].fi), ans.pb(rocks[mag[i]].se);;
                                return ans;
                            }
                        } else {
                            mag[im++]=np;
                            is_i[rocks[np].fi] = is_j[rocks[np].se] = 0;
                        }
                    }
                } else {
                    np = mag[--im];
                    is_i[rocks[np].fi] = is_j[rocks[np].se]=1;
                }
            }
            return ans;
        }
        vector <int> find(vector <string> b) {
            /*
            rep(_, 10000) {
                cout << _ << "###" << endl;
                vector<string> tmp = gen();
                cout << _ << "###" << endl;
//                vector<int> ret = hack(tmp); 
                vector<int> ret = ans(tmp); 
                cout << _ << "###" << endl;
                if (check(tmp, ret) == 0) {
                    cout <<"HIT" << endl;
                    cout << tmp << endl;
                    cout << ret << endl;
                    assert(0);
                }
            }
            */
            return hack(b);

            return ans(b); 
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	FiveRooks *obj;
	vector <int> answer;
	obj = new FiveRooks();
	clock_t startTime = clock();
	answer = obj->find(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"RRRRRRRR","RRRRRRRR","RRRRRRRR","RRRRRRRR","R.......","........","........","........"};
	p1 = {0,7,1,3,2,4,3,6,4,0};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"R.R.R.R.",".R.R.R.R","R.R.R.R.",".R.RRR.R","R.R.R.R.",".R.R.R.R","R.R.R.R.",".R.R.R.R"};
	p1 = {0,0,1,7,2,6,3,5,4,4};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"RRRRRRRR","RRRRRRRR","RRRRRRRR","RRRRRRRR","RRRRRRRR","RRRRRRRR","RRRRRRRR","RRRRRRRR"};
	p1 = {0,7,1,3,2,4,3,6,4,0};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {".RRRRRR.","RRRRRRRR","....RRRR","...RRRR.","..RRRR..",".RRRR...","RRRR....","RRR....."};
	p1 = {1,7,2,6,3,5,4,4,5,3};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {".RRRRRR.","RRRRRRRR","....RRRR","...RRRR.","..RRRR..",".RRRR...","RRRRRRRR",".RRRRRR."};
	p1 = {1,7,2,6,3,5,4,4,5,3};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {".RRRRRR.","RRRRRRRR",".RRRR...","..RRRR..","...RRRR.","....RRRR","RRRRRRRR",".RRRRRR."};
	p1 = {1,7,3,5,4,4,6,2,7,1};
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
// 
// You have an 8x8 chessboard.
// Each cell is either empty or contains a single rook.
// You are given a description of the chessboard in the vector <string> board.
// Empty cells are represented by '.' (period), rooks are represented by 'R'.
// The character board[r][c] describes the cell in row r, column c.
// (Hence, both rows and columns are numbered from 0 to 7.)
// 
// 
// 
// There are many rooks. More precisely, it is guaranteed that the board has strictly more rooks than empty squares.
// 
// 
// 
// Your task is to choose exactly five rooks.
// The five chosen rooks will remain on the chessboard, all other rooks will be removed.
// The five rooks must be chosen in such a way that on the resulting chessboard no two of them will attack each other.
// In other words, the five chosen rooks must be in five distinct rows and at the same time they must be in five distinct columns.
// It is guaranteed that for the given constraints such a set of five rooks always exists.
// 
// 
// 
// Return a vector <int> with exactly 10 elements.
// The first two elements denote the row and column of the first rook, the third and fourth element describe the second rook, and so on.
// If there are multiple solutions, you may return any one of them.
// 
// 
// 
// 
// DEFINITION
// Class:FiveRooks
// Method:find
// Parameters:vector <string>
// Returns:vector <int>
// Method signature:vector <int> find(vector <string> board)
// 
// 
// CONSTRAINTS
// -board will have exactly 8 elements.
// -Each element of board will have exactly 8 characters.
// -Each character of board will be '.' or 'R'.
// -There are strictly more 'R' characters than '.' characters within all elements of board.
// 
// 
// EXAMPLES
// 
// 0)
// {
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR",
// "R.......",
// "........",
// "........",
// "........"
// }
// 
// Returns: {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 }
// 
// The return value corresponds to the following chosen rooks:
// 
// 
// {
// "RRRRRRR*",
// "RRR*RRRR",
// "RRRR*RRR",
// "RRRRRR*R",
// "*.......",
// "........",
// "........",
// "........"
// }
// 
// 
// 1)
// {
// "R.R.R.R.",
// ".R.R.R.R",
// "R.R.R.R.",
// ".R.RRR.R",
// "R.R.R.R.",
// ".R.R.R.R",
// "R.R.R.R.",
// ".R.R.R.R"
// }
// 
// Returns: {0, 0, 1, 7, 2, 6, 3, 5, 4, 4 }
// 
// 
// 
// 2)
// {
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR",
// "RRRRRRRR"
// }
// 
// Returns: {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 }
// 
// 
// 
// 3)
// {
// ".RRRRRR.",
// "RRRRRRRR",
// "....RRRR",
// "...RRRR.",
// "..RRRR..",
// ".RRRR...",
// "RRRR....",
// "RRR....."
// }
// 
// 
// Returns: {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 }
// 
// 
// 
// 4)
// {
// ".RRRRRR.",
// "RRRRRRRR",
// "....RRRR",
// "...RRRR.",
// "..RRRR..",
// ".RRRR...",
// "RRRRRRRR",
// ".RRRRRR."
// }
// 
// Returns: {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 }
// 
// 
// 
// 5)
// 
// {
// ".RRRRRR.",
// "RRRRRRRR",
// ".RRRR...",
// "..RRRR..",
// "...RRRR.",
// "....RRRR",
// "RRRRRRRR",
// ".RRRRRR."
// }
// 
// Returns: {1, 7, 3, 5, 4, 4, 6, 2, 7, 1 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
