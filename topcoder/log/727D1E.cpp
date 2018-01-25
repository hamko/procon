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
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
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

class Halving {
    public:
        unordered_map<ll, ll> en(ll n) {
            unordered_map<ll, ll> ret;
            vector<ll> q;
            q.pb(n);
            ll cyc = 0;
            while (q.size()) {
                vll q_next;
                for (auto x : q) {
                    if (ret.count(x)) continue;
                    ret[x] = cyc;
                    if (x % 2) {
                        q_next.pb(x / 2);
                        q_next.pb(x / 2 + 1);
                    } else {
                        q_next.pb(x / 2);
                    }
                }
                swap(q, q_next);
                cyc++;
            }
            return ret;
        }
        int minSteps(vector <int> a_) {
            vll a = conv(a_);
            ll n = a.size();
            vector<unordered_map<ll, ll>> t(n);
            set<ll> cands;

            rep(i, n) {
                t[i] = en(a[i]);
                for (auto x : t[i]) {
                    cands.insert(x.fi);
                }
            }
            ll ret = INF;
            for (auto x : cands) {
                ll faf = 1;
                ll tmp = 0;
                rep(i, n) {
                    if (t[i].count(x) == 0) {
                        faf = 0;
                        break;
                    }
                    tmp += t[i][x];
                }
                if (faf) 
                    chmin(ret, tmp);
            }
            return ret;
        }
        bool solved(const multiset<P>& s) {
            int a =begin(s)->fi;
            int b =begin(s)->se ;
            for (int t : {a,b}) {
                int cnt = 0;
                for (auto p : s) {
                    cnt+=p.fi==t||p.se==t;
                }
                if(cnt==s.size()){
                    return 1;
                }
            }
            return 0;
        }
        void devide(const int k, vll& res) {
            res.pb(k/2);
            res.pb((k+1)/2);
        }
        int compare(vector <int> A) {
            const int N = A.size();
            multiset<P> s;
            priority_queue<P> que;
            for (auto a : A) {
                s.insert(P(a,a));
                que.push(P(a,a));
            }
            int res = 0;
            while (!solved(s)){
                const P p = que.top();
                que.pop();
                s.erase(s.find(p));
                vll nums;
                devide(p.fi,nums);
                devide(p.se,nums);
                sort(all(nums));
                nums.erase(unique(all(nums)),end(nums));
                const P q(nums[0],nums[1]);
                s.insert(q);
                que.push(q);
                res++;
            }
            return res;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	Halving *obj;
	int answer;
	obj = new Halving();
	clock_t startTime = clock();
//	answer = obj->minSteps(p0);
	answer = obj->compare(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	int p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {11,4};
	p1 = 3;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1000000000,1000000000,1000000000,1000000000};
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,2,3,4,5,6,7};
	p1 = 10;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	

	// ----- test 3 -----
	disabled = false;
	p0 = {13,13,7,11,13,11};
	p1 = 11;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
		// ----- test 3 -----
	disabled = false;
	p0 = {
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
        13,13,7,11,13,11,
    };
	p1 = 11*10;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,1};
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	

	auto obj = new Halving();
    vector<int> p;
    rep(_, 10000) {
        cout << _ << endl;
        p.clear();
        rep(i, 2) {
            p.pb(rand()%(ll)(1e9) +1);
            if (obj->compare(p) != obj->minSteps(p)) {
                cout <<"HIT" << endl;
                cout << p << endl;
            }
        }
    }
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
// You have a collection of sticks.
// The length of each stick is a positive integer.
// 
// 
// You want to have a collection of sticks in which all the sticks have the same length.
// You may alter your current collection by performing zero or more steps.
// Each step must look as follows:
// 
// You choose one of your sticks. The chosen stick must have length at least 2.
// Let L be the length of the chosen stick.
// If L is even, cut the stick into two sticks of length L/2 each. Otherwise, cut it into sticks of lengths (L-1)/2 and (L+1)/2.
// Keep one of the two new sticks and throw away the other one.
// 
// 
// 
// It can be proved that any collection of sticks can be turned into a collection of sticks that all have the same length.
// You are given the current lengths of your sticks in the vector <int> a.
// Compute and return the smallest number of steps needed to reach your goal.
// 
// 
// DEFINITION
// Class:Halving
// Method:minSteps
// Parameters:vector <int>
// Returns:int
// Method signature:int minSteps(vector <int> a)
// 
// 
// CONSTRAINTS
// -a will contain between 2 and 50 elements, inclusive.
// -Each element of a will be between 1 and 109, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {11, 4}
// 
// Returns: 3
// 
// One optimal solution is:
// 
//  Pick the stick of length 11, cut it into sticks of lengths 5 and 6 and keep the part of length 5. 
//  Pick the stick of length 4, cut it into two sticks of length 2 and keep the part of length 2. 
//  Pick the stick of length 5, cut it into sticks of lengths 2 and 3 and keep the part of length 2. 
// 
// In the end, you'll have two sticks of length 2.
// 
// 1)
// {1000000000, 1000000000, 1000000000, 1000000000}
// 
// Returns: 0
// 
// All your sticks have the same length, no steps are needed.
// 
// 2)
// {1, 2, 3, 4, 5, 6, 7}
// 
// Returns: 10
// 
// 
// 
// 3)
// {13, 13, 7, 11, 13, 11}
// 
// Returns: 11
// 
// 
// 
// 4)
// {1, 1}
// 
// Returns: 0
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
