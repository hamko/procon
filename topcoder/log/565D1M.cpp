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

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)が必須！
/**********************************************************/
// O(n log n)
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
ll getFactorizationNum(ll n) {
    ll ret = 0;
    if (n <= 1) return ret;

    ll prime_index = 0;
    while (1) {
        ll prime = primesList[prime_index];
        if (n < prime * prime) break;
        if (n % prime == 0) {
            ret++;
            n /= prime;
        } else {
            prime_index++;
        }
    }
    ret++;

    return ret;
}

class TheDivisionGame {
    public:
        long long countWinningIntervals(int l, int r) {
            ll n = r - l + 1;
            constructPrimesList(1e6);
            vll grundy_sum(n+1);

            unordered_map<ll, ll> counter;
            counter[0]++;
            rep(i, n) {
                grundy_sum[i+1] = grundy_sum[i] ^ getFactorizationNum(l + i);
                counter[grundy_sum[i+1]]++;
            }
            ll ret = n * (n + 1) / 2;
            for (auto x : counter) 
                ret -= x.se * (x.se - 1) / 2; 

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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, long long p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1;
    cout << "]" << endl;
    TheDivisionGame *obj;
    long long answer;
    obj = new TheDivisionGame();
    clock_t startTime = clock();
    answer = obj->countWinningIntervals(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
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
    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    int p0;
    int p1;
    long long p2;

    // ----- test 0 -----
    disabled = false;
    p0 = 9;
    p1 = 10;
    p2 = 2ll;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = 2;
    p1 = 5;
    p2 = 9ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 2;
	p1 = 6;
	p2 = 13ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 2;
	p1 = 100;
	p2 = 4345ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 12566125;
	p1 = 12567777;
	p2 = 1313432ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //
		// ----- test 4 -----
	disabled = false;
	p0 = 1000000000;
	p1 = 1001000000;
	p2 = 1313432ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
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
// Manao likes to play the Division Game with his friends. This two-player game is played with some collection of natural numbers S. Manao plays first and the players alternate in making a move. A move is choosing some number X from S and a natural number Y &gt 1 such that Y divides X. Then, X is replaced by X / Y in the collection. Note that at any moment the collection may contain multiple copies of the same number. The game proceeds until no more moves can be made. The player who managed to make the last move is declared the winner.
// 
// Since hot debates arise on what numbers should be in S, the friends decided to regularize their choice. They always choose a contiguous interval of numbers [A, B] to be the initial collection S. That is, at the beginning of the game, the collection S contains each of the integers A through B, inclusive, exactly once. Manao knows that A and B will satisfy the condition L &le A &le B &le R. You are given the ints L and R. Count the number of such intervals for which Manao will win the Division Game given that both players play optimally.
// 
// DEFINITION
// Class:TheDivisionGame
// Method:countWinningIntervals
// Parameters:int, int
// Returns:long long
// Method signature:long long countWinningIntervals(int L, int R)
// 
// 
// NOTES
// -Only one number from the collection changes in each move. For example, if the collection contains three copies of the number 8, and the player chooses X=8 and Y=4, only one of the 8s in the collection will change to a 2.
// 
// 
// CONSTRAINTS
// -L will be between 2 and 1,000,000,000, inclusive.
// -R will be between L and L + 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 9
// 10
// 
// Returns: 2
// 
// If the chosen interval is [9,9] or [10,10], the collection S contains only one number. In these two situations Manao can win the game in a single move. On the other hand, if the chosen interval is [9,10], Manao will lose to an optimally playing opponent.
// 
// 
// 1)
// 2
// 5
// 
// Returns: 9
// 
// The only case where Manao loses is if the game starts with the interval [2,3]. Note that if the starting interval is [2,5], Manao can choose X=4 and Y=2 in his first move. After that move, the collection will contain the values 2, 2, 3, and 5.
// 
// 2)
// 2
// 6
// 
// Returns: 13
// 
// Manao will also lose the game if the starting interval is [3,6].
// 
// 3)
// 2
// 100
// 
// Returns: 4345
// 
// 
// 
// 4)
// 12566125
// 12567777
// 
// Returns: 1313432
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
