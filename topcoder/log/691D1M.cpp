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

vvll p;
ll ret = 0;
ll x = 0;
ll c = 0;
ll N = 0;
vector<P> ab;
// ちょうどi個を見終えて、残りがsで、現在の配列がaである場合。
void dfs(ll s, ll i, vll& av, const vll& amax, const int target_sum, vll& amaxsum) {
    if (amaxsum.back() - amaxsum[i] < s) return; // 枝刈り
    if (s && i == av.size()) return;
    if (!s) {
        c++;
        if (c % 10000 == 0) cout << c << endl;
        vector<P> first_half, second_half;
        ll mask = 0;
        rep(b, p.size()) {
            rep(ai, av[b]) {
                mask |= (1ll << p[b][ai]);
            }
        }
        ll money = 0;
        ll exp = 0;
        rep(bit, 2) {
            rep(j, N) if (!bit == !!(mask & (1ll << j))) {
                exp += ab[j].fi;
                money += exp * ab[j].se;
            }
            exp += x;
        }
        chmax(ret, money);

        return;
    }
    rep(j, min(s, amax[i])+1) {
        av[i] = j;
        dfs(s-j, i+1, av, amax, target_sum, amaxsum);
        av[i] = 0;
    }
}
void start_dfs(const vll amax, const int target_sum) {
    c = 0;
    ll s = target_sum; vll a(amax.size()); 
    vll amaxsum(amax.size()+1);
    rep(i, amax.size()) amaxsum[i+1] = amaxsum[i] + amax[i];
    dfs(s, 0, a, amax, target_sum, amaxsum);
}


class Moneymanager {
    public:
        int getbest(vector <int> a, vector <int> b, int X) {
            N = a.size();
            ab.clear();
            rep(i, a.size()) {
                ab.pb(P(a[i], b[i]));
            }
            sort(all(ab), [&](P x, P y){return x.fi*y.se>y.fi*x.se;});

            x = X;
            ll n = a.size() / 2;
            ret = 0;

            p.clear();
            p.resize(11);
            rep(i, ab.size()) {
                p[ab[i].se].pb(i);
            }
            rep(i, p.size()) {
                sort(all(p[i]), [&](ll x, ll y){return ab[x].fi>ab[y].fi;});
            }

            vll amax(11);
            rep(i, b.size()) {
                amax[b[i]]++;
            }
            
            start_dfs(amax, n);

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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
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
	Moneymanager *obj;
	int answer;
	obj = new Moneymanager();
	clock_t startTime = clock();
	answer = obj->getbest(p0, p1, p2);
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
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,1};
	p1 = {2,1};
	p2 = 0;
	p3 = 5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,1};
	p1 = {1,5};
	p2 = 10;
	p3 = 61;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {4,4,6,6};
	p1 = {2,2,3,3};
	p2 = 100;
	p3 = 726;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    
    // ----- test 2 -----
	disabled = false;
	p0 = {1,4,2,6};
	p1 = {2,2,3,3};
	p2 = 100;
	p3 = 690;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	

	// ----- test 3 -----
	disabled = false;
	p0 = {30,13,28,59,26,62,48,75,6,69,94,51};
	p1 = {4,6,4,5,4,3,1,5,6,5,2,2};
	p2 = 62;
	p3 = 22096;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    // ----- test 3 -----
	disabled = false;
	p0 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	p1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,};

	p2 = 85191;
	p3 = 22096;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
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
// One day Hero realized that he has zero experience with practical projects.
// Thus, he decided to spend one whole year on projects, gaining some experience and making some money along the way.
// 
// Hero already chose which projects he is going to do.
// All that remains is to choose the order in which he'll do them.
// 
// Each project can be described by two positive integers a[i] and b[i].
// More precisely, when Hero works on project i, the following two things happen, in order:
// 
// First, his work on the project increases his experience by a[i].
// Then, when the project is done, he earns money for the project. The amount earned is (b[i] * E), where E is his total amount of experience at the moment of finishing the project.
// 
// 
// The number of projects Hero has planned is even.
// In addition to the projects, Hero has one extra plan: after finishing exactly one half of the projects, he wants to attend a training camp.
// The training camp will increase his experience by X.
// He will not earn any money at the training camp.
// 
// At the beginning, Hero has no experience and no money.
// You are given the vector <int>s a and b (both with the same number of elements; that number is even) and the int X.
// Find and return the maximum total amount of money Hero can earn during the year.
// 
// DEFINITION
// Class:Moneymanager
// Method:getbest
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int getbest(vector <int> a, vector <int> b, int X)
// 
// 
// CONSTRAINTS
// -Number of elements in a will be between 2 and 50, inclusive.
// -Number of elements in a will be even.
// -a and b will contain the same number of elements.
// -Each element in a will be between 1 and 100,000, inclusive.
// -Each element in b will be between 1 and 10, inclusive.
// -X will be between 0 and 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,1}
// {2,1}
// 0
// 
// Returns: 5
// 
// An optimal solution:
// 
// Hero works on project #1 (zero-based index). He first gains 1 experience and then he makes 1*1 = 1 money.
// Hero goes to the training camp and gains X=0 experience.
// Hero works on project #0. He first gains 1 experience and then he makes 2*2 = 4 money.
// 
// The total amount of money earned during this solution is 1 + 4 = 5.
// 
// 1)
// {1,1}
// {1,5}
// 10
// 
// Returns: 61
// 
// An optimal solution:
// 
// Hero works on project #0. He first gains 1 experience and then he makes 1*1 = 1 money.
// Hero goes to the training camp and gains 10 experience.
// Hero works on project #1. He first gains 1 experience and then he makes 5*12 = 60 money.
// 
// The total amount of money earned during this solution is 1 + 60 = 61.
// 
// 2)
// {4,4,6,6}
// {2,2,3,3}
// 100
// 
// Returns: 726
// 
// One optimal solution: project #0, project #1, training camp, project #3, project #2.
// 
// 3)
// {30,13,28,59,26,62,48,75,6,69,94,51}
// {4,6,4,5,4,3,1,5,6,5,2,2}
// 62
// 
// Returns: 22096
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
