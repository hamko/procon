#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
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
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

// 素数の個数はO(n / log n)

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)が必須！
/**********************************************************/
// O(n log log n)
void sieve_of_eratosthenes(vector<ll>& primes, ll n) {
    primes.resize(n);
    for (ll i = 2; i < n; ++i)
        primes[i] = i;
    for (ll i = 2; i*i < n; ++i)
        if (primes[i])
            for (ll j = i*i; j < n; j+=i)
                primes[j] = 0;
}
void getPrimesList(ll n, vector<ll>& primes_list) {
    vector<ll> tmpList;
    primes_list.clear(); primes_list.resize(0); primes_list.reserve(n / 5);
    sieve_of_eratosthenes(tmpList, n);
    rep(i, n) { 
        if (tmpList[i])
            primes_list.push_back(i);
    }
}

// 素数テーブル構築: O(n log n)
vector<ll> primesList;      // 素数リスト（primesListMaxまで）。こいつ自体を使うことあるかも。
set<ll> primesSet;
ll primesListMax;
void constructPrimesList(ll n) {
    if (primesListMax >= n) 
        return;
    primesListMax = n;
    getPrimesList(n, primesList);
    for (ll i = 0; i < primesList.size(); i++) {
        primesSet.insert(primesList[i]);
    }
}
// constructされていないなら、O(n log n)
// constructされているなら、O(log n)
bool isPrimeLookup(ll n) {
    return primesSet.count(n);
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
// Divisor系は、最大nをMAXNとしてconstructPrimesList(sqrt(MAXN))で早くなる
void getPrimeFactorizationList(ll n, vector<ll>& divisors_list) {
    divisors_list.clear(); divisors_list.resize(0);
    if (n <= 1) return;

    ll prime = 2;
    while (n >= prime * prime) {
        if (n % prime == 0) {
            divisors_list.push_back(prime);
            n /= prime;
        } else {
            prime++;
        }
    }
    divisors_list.push_back(n);
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
// Divisor系は、最大nをMAXNとしてconstructPrimesList(sqrt(MAXN))で早くなる
void getDivisorsList(ll n, vector<ll>& divisors_list) {
    divisors_list.clear(); divisors_list.resize(0);

    vector<ll> fac_list;
    getPrimeFactorizationList(n, fac_list);
    map<ll, ll> counter;
    for (auto x : fac_list) 
        counter[x]++;
    divisors_list.push_back(1);
    for (auto x : counter) {
        ll tmp_size = divisors_list.size();
        ll p = 1;
        for (ll i = 0; i < x.second; i++) {
            p *= x.first;
            for (ll j = 0; j < tmp_size; j++) 
                divisors_list.push_back(divisors_list[j] * p);
        }
    }
    sort(divisors_list.begin(), divisors_list.end());
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
ll getDivisorsNum(ll n) {
    vector<ll> divisors_list; getPrimeFactorizationList(n, divisors_list);
    map<ll, ll> num;
    for (ll i = 0; i < divisors_list.size(); i++) {
        num[divisors_list[i]]++;
    }
    ll p = 1;
    for (auto x : num) {
        p *= x.second + 1;
    }
    return p;
}

class FromToDivisibleDiv2 {
    public:
        int shortest(int n, int s, int t, vector <int> a, vector <int> b) {
            vector<ll> memo(n+10, -1);
            constructPrimesList(200000);
            vector<ll> q, q_next;
            vector<bool> used_d(200000);

            q_next.pb(s);
            memo[s] = 0;
            while (q_next.size()) {
//                cout << counter << "#test" << endl; counter++;
                swap(q, q_next);
                q_next.clear();
//                cout << q << endl;
                for (auto&& x : q) {
//                    cout << x << "x" << endl;
                    ll now = memo[x];
                    vll dl; getDivisorsList(x, dl);
//                    cout << x << " " << dl << endl;
                    for (auto&& d : dl) if (!used_d[d]) {
                        used_d[d] = true;
                        rep(i, a.size()) if (a[i] == d) {
                            for (ll j = b[i]; j <= n; j += b[i]) {
//                                cout << j << "#hit" << endl;
                                if (memo[j] != -1) continue;
                                memo[j] = now + 1;
                                q_next.pb(j);
                            }
                        }
                    }
                }
//                cout << q_next << endl;
            }
            return memo[t];
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, vector <int> p3, vector <int> p4, bool hasAnswer, int p5) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p4.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p4[i];
    }
    cout << "}";
    cout << "]" << endl;
    FromToDivisibleDiv2 *obj;
    int answer;
    obj = new FromToDivisibleDiv2();
    clock_t startTime = clock();
    answer = obj->shortest(p0, p1, p2, p3, p4);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p5 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p5;
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

    int p0;
    int p1;
    int p2;
    vector <int> p3;
    vector <int> p4;
    int p5;

    // ----- test 0 -----
    disabled = false;
    p0 = 11;
    p1 = 9;
    p2 = 6;
    p3 = {3,10};
    p4 = {5,2};
    p5 = 2;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 12345;
	p1 = 18;
	p2 = 12;
	p3 = {1,42,50};
	p4 = {1,17,3};
	p5 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 60;
	p1 = 30;
	p2 = 8;
	p3 = {16,15,12};
	p4 = {2,20,5};
	p5 = -1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 77;
	p1 = 10;
	p2 = 62;
	p3 = {2,5,7,4,17,26};
	p4 = {25,7,11,13,31,34};
	p5 = 4;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 100;
	p1 = 90;
	p2 = 40;
	p3 = {20,30,100,99,100};
	p4 = {10,30,100,100,99};
	p5 = 2;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = 100000;
	p1 = 700;
	p2 = 42345;
	p3 = {3500,12000,42345,20000,35,19};
	p4 = {15,1,700,20000,40000,17};
	p5 = 3;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = 2;
	p1 = 1;
	p2 = 2;
	p3 = {2};
	p4 = {1};
	p5 = -1;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
   
		// ----- test 6 -----
	disabled = false;
	p0 = 100000;
	p1 = 1;
	p2 = 100000;
	p3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	p4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	p5 = 1;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
			// ----- test 6 -----
	disabled = false;
	p0 = 100000;
	p1 = 1;
	p2 = 100000;
    p3 = vector<int>(500, 1);
    p4 = vector<int>(500, 1);
    rep(i, 500) {
        p4[i] = i+1;
    }
	p5 = 1;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
				// ----- test 6 -----
	disabled = false;
	p0 = 100000;
	p1 = 1;
	p2 = 100000;
    p3 = vector<int>(500, 1);
    rep(i, 500) {
        p3[i] = i+1;
    }
    p4 = vector<int>(500, 1);
	p5 = 1;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, true, p5) ) && all_right;
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
// Bearland consists of N cities, numbered 1 through N.
// Some pairs of cities are connected by one-way roads of unit length.
// The distance from city X to city Y is the smallest number of roads you need to traverse in order to get from X to Y.
// 
// The road network has a special structure.
// You are given a description of this structure: two vector <int>s a and b, each with M elements.
// For each pair of distinct cities (X,Y), there is a one-way road from X to Y if and only if there is at least one index i such that X is divisible by a[i] and Y is divisible by b[i].
// 
// For example, suppose that N = 7, M = 1, a[0] = 2, and b[0] = 3.
// In this case the country has 7 cities and it contains the following one-way roads: 2 -> 3, 2 -> 6, 4 -> 3, 4 -> 6, 6 -> 3, and 6 -> 6.
// 
// You are given the int N.
// You are also given two ints S and T: the source city where you start your journey and the target city you want to reach.
// Finally, you are given the vector <int>s a and b described above.
// 
// If there is no path from S to T, return -1.
// Otherwise, compute and return the distance from S to T.
// 
// DEFINITION
// Class:FromToDivisibleDiv2
// Method:shortest
// Parameters:int, int, int, vector <int>, vector <int>
// Returns:int
// Method signature:int shortest(int N, int S, int T, vector <int> a, vector <int> b)
// 
// 
// CONSTRAINTS
// -N will be between 2 and 10^5, inclusive.
// -S and T will each be between 1 and N, inclusive.
// -S and T will be different.
// -M will be between 1 and 500, inclusive.
// -a and b will each contain exactly M elements.
// -Each element in a and in b will be between 1 and N, inclusive.
// -The pairs (a[i],b[i]) are all distinct.
// 
// 
// EXAMPLES
// 
// 0)
// 11
// 9
// 6
// {3,10}
// {5,2}
// 
// Returns: 2
// 
// The one-way roads are: (3,5), (3,10), (6,5), (6,10), (9,5), (9,10), (10,2), (10,4), (10,6), (10,8).
// The shortest path from city 9 to city 6 is 9 -> 10 -> 6.
// It uses two roads, so the length is 2.
// 
// 1)
// 12345
// 18
// 12
// {1,42,50}
// {1,17,3}
// 
// Returns: 1
// 
// Since a[0] = b[0] = 1, there is a one-way road from any city to any other city.
// In particular, there is a road from city 18 to city 12.
// 
// 2)
// 60
// 30
// 8
// {16,15,12}
// {2,20,5}
// 
// Returns: -1
// 
// 
// 
// 3)
// 77
// 10
// 62
// {2,5,7,4,17,26}
// {25,7,11,13,31,34}
// 
// Returns: 4
// 
// 
// 
// 4)
// 100
// 90
// 40
// {20,30,100,99,100}
// {10,30,100,100,99}
// 
// Returns: 2
// 
// The only optimal path is 90 -> 60 -> 40.
// 
// 5)
// 100000
// 700
// 42345
// {3500,12000,42345,20000,35,19}
// {15,1,700,20000,40000,17}
// 
// Returns: 3
// 
// 
// 
// 6)
// 2
// 1
// 2
// {2}
// {1}
// 
// Returns: -1
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
