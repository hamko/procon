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

class MulticoreProcessing {
    public:
        long long fastestTime(long long x, int p_, vector <int> speed, vector <int> c_) {
            long long p = p_;
            vll vv = conv(speed);
            vll cv = conv(c_);

            ll n = vv.size();
            ld ret = INF;
            rep(i, n) {
                ll v = vv[i];
                ll c = cv[i];
                ld a = (ld)x / (ld)v;

                vll kv = {1, c};
                if (p) {
                    ld k_opt = sqrtl((ld)a / (ld)p);
                    if (k_opt <= (ld)2*(ld)c) {
                        kv.pb((ll)k_opt);
                        kv.pb(((ll)k_opt)+1);
                        kv.pb(((ll)k_opt)-1);
                    }
                }
                rep(j, kv.size()) {
                    ll k = kv[j];
                    if (1 <= k && k <= c) {
                        chmin(ret, (ld)a/(ld)k+(ld)(p)*(ld)(k-1));
                    }
                }
            }
            return ceill(ret-1e-60);
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
bool KawigiEdit_RunTest(int testNum, long long p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, long long p4) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}";
    cout << "]" << endl;
    MulticoreProcessing *obj;
    long long answer;
    obj = new MulticoreProcessing();
    clock_t startTime = clock();
    answer = obj->fastestTime(p0, p1, p2, p3);
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

    long long p0;
    int p1;
    vector <int> p2;
    vector <int> p3;
    long long p4;

    // ----- test 0 -----
    disabled = false;
    p0 = 2000ll;
	p1 = 5;
	p2 = {40,20};
	p3 = {2,4};
	p4 = 30ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 2000ll;
	p1 = 5;
	p2 = {10,20};
	p3 = {2,4};
	p4 = 40ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 1000ll;
	p1 = 0;
	p2 = {10};
	p3 = {3};
	p4 = 34ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 10000ll;
	p1 = 5;
	p2 = {39,37,44};
	p3 = {8,16,6};
	p4 = 63ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 3 -----
	disabled = false;
	p0 = (ll)1e18;
	p1 = 2;
	p2 = {1,(ll)1e9};
	p3 = {(ll)1e9,(ll)1e9};
	p4 = -1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
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
// In the last several years CPU manufacturers have been making processors with an ever-increasing number of processing cores.
// Utilizing multiple cores to process workloads sometimes creates challenges for developers.
// When a processing workload gets split into multiple parts, there is often some performance penalty caused by having to split the work and recombine the results.
// For example, a job that takes 1000 ms on a single core might be expected to run in 500 ms across two cores, but in reality ends up taking 650 ms.
// 
// Your team has a workload that needs to be processed.
// The workload requires jobLength units of computation.
// If we use multiple cores to process the job, the computation will be split equally among all cores.
// For example, if you split 1000 units of computation among 3 cores, each core will get exactly 1000/3 units of computation to perform.
// 
// You have several available systems that can be used for the computation.
// Each system has some number of cores.
// All cores in a system have the same speed of computation.
// You need to choose a single system that will be used to process the workload, and you need to choose how many cores of that system will be used for the computation.
// 
// The description of the systems you have is given in the vector <int>s speed and cores.
// For each valid i you own a system with cores[i] cores such that each of the cores can execute speed[i] units of computation per millisecond.
// 
// Due to the overhead with parallelization, the computation will take additional corePenalty milliseconds for each core used beyond the first.
// This constant is the same for all systems you have.
// 
// You are given the long long jobLength, the int corePenalty, and the vector <int>s speed and cores.
// Find the best system you should use and the best number of cores you should use on that system.
// Return the smallest positive integer T such that it is possible to execute the entire computation in T milliseconds or less.
// 
// DEFINITION
// Class:MulticoreProcessing
// Method:fastestTime
// Parameters:long long, int, vector <int>, vector <int>
// Returns:long long
// Method signature:long long fastestTime(long long jobLength, int corePenalty, vector <int> speed, vector <int> cores)
// 
// 
// CONSTRAINTS
// -jobLength will be between 1 and 10^18, inclusive.
// -corePenalty will be between 0 and 1000000000, inclusive.
// -speed will have between 1 and 50 elements, inclusive.
// -cores will have the same number of elements as speed.
// -Each element of speed will be between 1 and 1000000000, inclusive.
// -Each element of cores will be between 1 and 1000000000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2000
// 5
// {40,20}
// {2,4}
// 
// Returns: 30
// 
// The first system is twice as fast as the second one, but the first system only has two cores while the second one has four.
// Their raw processing power is the same, but using more cores incurs the core penalty multiple times.
// Thus, in this particular case it is better to use the first system.
// If we use both cores, each of them has to do 1000 steps of computation, and with speed 40 this will take exactly 25 milliseconds.
// We then add the 5-millisecond core penalty to compute that the total running time for this option is exactly 30 milliseconds.
// 
// 1)
// 2000
// 5
// {10,20}
// {2,4}
// 
// Returns: 40
// 
// Now, the faster machine is also the one with more cores. Even with the core penalty it's far faster overall.
// 
// 2)
// 1000
// 0
// {10}
// {3}
// 
// Returns: 34
// 
// We need to perform 1000 units of computation.
// On a system with 3 cores, each with speed 10, we will need 1000/(3*10) = 33.3333333... milliseconds of time.
// The correct return value is this exact value rounded up to the nearest integer: 34 milliseconds is the smallest integer amount of milliseconds sufficient for the computation.
// 
// 3)
// 10000
// 5
// {39,37,44}
// {8,16,6}
// 
// Returns: 63
// 
// These are roughly the specs of some current-day CPUs.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
