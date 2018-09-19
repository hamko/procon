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

int p10_mod[1024];
signed char dp_alice[1024][1024];
signed char dp_bob[1024][1024];
int rec_alice(int,int);
int rec_bob(int k, int rem) {
    auto& res= dp_bob[k][rem];
    if (res != -1) return res;
    if (k == length) return res = (rem==0);
    rep(i, 10) {
        if (!rec_alice(k+1,(rem+i*p10_mod[length-1-k])%divisors))
            return res = i;
    }
    return res = 0;
}
int rec_alice(int k, int rem) {
    auto& res= dp_alice[k][rem];
    if (res != -1) return res;
    if (k == length) return res = (rem==0);
    rep(i, 10) {
        if (!rec_bob(k+1,(rem+i*p10_mod[length-1-k])%divisors))
            return res = i;
    }
    return res = 0;
}

class LeftToRightGame {
    public:
        ll dp[1100][1100];
        string whoWins(int l, int d) {
            rep(i, l+10) rep(j, d+10) dp[i][j] = INF;

            rep(i, d) dp[l][i] = 0;
            dp[l][0] = 1;

            for (ll i = l-1; i >= 0; i--) {
                rep(j, d) {
                    if (i % 2) {
                        bool tef = 0;
                        rep(x, 10-(i==0)) {
                            tef |= dp[i+1][(10ll*j+x)%d];
                        }
                        dp[i][j] = tef;
                    } else {
                        bool faf = 1;
                        rep(x, 10-(i==0)) {
                            faf &= dp[i+1][(10ll*j+x)%d];
                        }
                        dp[i][j] = faf;
                    }
                }
            }
            /*
            rep(i, l+1) {
                rep(j, d) {
                    cout << dp[i][j];
                }
                cout << endl;
            }
            */
            return dp[0][0] ? "Bob" : "Alice" ;
        }

        string whoWins2(int l, int d) {
            if (l % 2 == 0 && d <= 10) return "Bob";
            if (d == 1) return "Bob";
            if (d == 11 && l % 2 == 0) return "Bob";
            return "Alice";
        }


        int cal(int i, int mod, int length, int divisor) {
            if (i == length) {
                if (mod == 0) {
                    return 0;
                } else {
                    return 1;
                }
            }
            if (f[i][mod]>=0){
                return f[i][mod];
            }
            int& res = f[i][mod];
            int start = 0;
            if (i == 0) {
                start = 1;
            }
            if (i % 2 == 0) {
                res = 0;
            } else {
                res = 1;
            }

            for (int k = start; k <= 9; k++) {
                int nextMod = (mod*10+k)%divisor;
                int nextValue=cal(i+1,nextMod,length,divisor);
                if(i%2==0){
                    if (nextValue==1) {
                        res = 1;
                            break;
                    }
                }else {
                    if (nextValue==0) {
                        res = 0;
                        break;
                    }
                }
            }
            return res;
        }
        string part(int length, int divisor) {
            rep(i,limit)rep(j,limit)f[i][j]=0;
            rep(i,limit)value[i]=0;

            value[0]=1;
            for (int i = 1; i < length; i++) {
                value[i] = (value[i-1]*10)%divisor;
            }
            memset(f,-1,sizeof f);
            int res = cal(0,0,length,divisor);
            if (res == 1) {
                return "Alice";
            } else {
                return "Bob";
            }
            return "Alice";
        }


        void check(void) {
            while (1) {
                /*
                int l = 1+rand()%1000;
                int d = 1+rand()%1000;
                */
                int l = 1+rand()%200;
                int d = 1+rand()%200;
                if (whoWins(l, d) != part(l, d)) {
                    cout <<"HIT"<<endl;
                    cout << l << " " << d << endl;
                    cout << whoWins(l, d) << " " << part(l, d) << endl;
                }
            }
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	LeftToRightGame *obj;
	string answer;
	obj = new LeftToRightGame();
	clock_t startTime = clock();
	answer = obj->whoWins(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	LeftToRightGame *obj = new LeftToRightGame();
    obj->check();

	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	int p0;
	int p1;
	string p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 4;
	p1 = 10;
	p2 = "Bob";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 3;
	p1 = 1000;
	p2 = "Alice";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 2;
	p1 = 3;
	p2 = "Bob";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 147;
	p1 = 47;
	p2 = "Alice";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 3 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = "Bob";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
			// ----- test 3 -----
	disabled = false;
	p0 = 1;
	p1 = 2;
	p2 = "Alice";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
				// ----- test 3 -----
	disabled = false;
	p0 = 2;
	p1 = 1;
	p2 = "Bob";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
					// ----- test 3 -----
	disabled = false;
	p0 = 2;
	p1 = 2;
	p2 = "Bob";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
						// ----- test 3 -----
	disabled = false;
	p0 = 2;
	p1 = 11;
	p2 = "Alice";
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
// Alice and Bob are playing a simple game. They take alternating turns writing the digits of a positive integer, from the left to the right. Alice starts. The number is not allowed to start with a zero, hence Alice must choose one of the digits 1 through 9 as her first move.
// 
// The game ends when the number has exactly length digits. Bob wins the game if that number is divisible by divisor. Alice wins in all other cases.
// 
// You are given the ints length and divisor. Return the name of the player who wins if both of them play the game optimally.
// 
// DEFINITION
// Class:LeftToRightGame
// Method:whoWins
// Parameters:int, int
// Returns:string
// Method signature:string whoWins(int length, int divisor)
// 
// 
// CONSTRAINTS
// -length will be between 1 and 1000, inclusive.
// -divisor will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 4
// 10
// 
// Returns: "Bob"
// 
// Alice and Bob are creating a 4-digit number. Bob wins if the number ends up being divisible by 10. As he is the one who will write down the last digit of the number, he has a very obvious winning strategy.
// 
// 1)
// 3
// 1000
// 
// Returns: "Alice"
// 
// A positive three-digit integer will never be divisible by 1000. Alice wins this game regardless of how she and Bob play it.
// 
// 2)
// 2
// 3
// 
// Returns: "Bob"
// 
// 
// 
// 3)
// 147
// 47
// 
// Returns: "Alice"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
