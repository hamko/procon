#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
#define MAX_N 100005

/**********************************************************/
// 前処理ありの素数判定
// 素数の最大値Mに対して先にconstructPrimesList(M)するといい
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
    constructPrimesList(n);
    return primesSet.count(n);
}

// constructされていないなら、O(sqrt(n) log n)
// constructされているなら、O(log n)
// Divisor系は、最大nをMAXNとしてconstructPrimesList(sqrt(MAXN))で早くなる
void getPrimeFactorizationList(ll n, vector<ll>& divisors_list) {
    divisors_list.clear(); divisors_list.resize(0);
    if (n <= 1) return;
    constructPrimesList(sqrt(n)+1);

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
    constructPrimesList(sqrt(n)+1);

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


class RectangularSum {
public:
    bool f(ll W, ll d, ll mid, ll hrange) {
        return (d-W*mid)<=hrange;
    }
	bool ok(ll W, ll d, ll wrange, ll hrange) {
        if (d < 0) return false;
        if (wrange < 0 || hrange < 0) return false;
        if (d <= wrange) return true;

        // 構造は00000011111なら、check(mid)
        ll roinit = min(d / W, hrange)+1;
        ll lo = 0, ro = roinit;
        while (ro - lo != 1) { 
            ll mid = (lo + ro) / 2; 
            cout << W << " " << d << " " << mid << " " << wrange << ":" << f(W, d, mid, wrange) << endl;
            // check関数が単純ならここに書いてもいいが、デバッグしにくくなるので関数は分けるべき
            f(W, d, mid, wrange)?ro=mid:lo=mid; 
        }
        return !(ro == roinit);
    }
	long long minimalArea(int H, int W, long long S) {
//        while (1) {
//            ll W; cin >> W;
//            cout << ok(25, 340, 24, 0) << endl;
//            cout << f(5, 13, W, 5) << endl;
//            exit(1);
//        }
        constructPrimesList(2000000);
        vll AB;
        getDivisorsList(2ll*S, AB);
        ll ret = INF;
        rep(i, AB.size()) {
            ll ab = AB[i];
            vll A;
            getDivisorsList(ab, A);
            rep(j, A.size()) {
                ll a = A[j];
                ll b = AB[i] / A[j];
                ll c = S * 2ll / a / b - (a - 1ll) - W * (b - 1ll);
                if (c % 2 != 0) 
                    continue;
                ll d = c / 2;
                // Is there exist (w, h) s.t. w + W * h = d?
                cout << a << " " <<  b << ": w + " << W << "h = " << d << "#" << W-a << ", " << H-b << " ->  " << ok(W, d, W-a, H-b)<< endl;
                if (ok(W, d, W-a, H-b))
                    ret = min(ret, ab);
            }
        }
        return ret == INF ? -1 : ret;
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, long long p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	RectangularSum *obj;
	long long answer;
	obj = new RectangularSum();
	clock_t startTime = clock();
	answer = obj->minimalArea(p0, p1, p2);
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
	
	int p0;
	int p1;
	long long p2;
	long long p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 2;
	p1 = 3;
	p2 = 8ll;
	p3 = 4ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 3;
	p1 = 3;
	p2 = 10ll;
	p3 = -1ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 3;
	p1 = 3;
	p2 = 36ll;
	p3 = 9ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 25;
	p1 = 25;
	p2 = 16000ll;
	p3 = 32ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 1000000;
	p1 = 1000000;
	p2 = 1000000000000ll;
	p3 = 2ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = 2;
	p1 = 3;
	p2 = 5ll;
	p3 = 1ll;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = 65;
	p1 = 42;
	p2 = 10441ll;
	p3 = -1ll;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, true, p3) ) && all_right;
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
// Consider the following table:
// 
// 
// The table has height rows and width columns.
// Rows and columns are each numbered sequentially, starting from 0.
// For each i, j: the cell in row i, column j contains the number (i*width+j).
// For example, the table with height=2 and width=3 looks as follows:
// 
// 0 1 2
// 3 4 5
// 
// 
// A subtable of this table is any table that can be obtained from the original table by selecting a rectangle of cells and erasing everything outside the rectangle.
// 
// You are given the ints height and width, and a long long S.
// If there is no subtable in which the elements sum to S, return -1.
// Otherwise, return the smallest possible area of such a subtable.
// 
// DEFINITION
// Class:RectangularSum
// Method:minimalArea
// Parameters:int, int, long long
// Returns:long long
// Method signature:long long minimalArea(int height, int width, long long S)
// 
// 
// CONSTRAINTS
// -height will be between 1 and 1,000,000 (10^6), inclusive.
// -width will be between 1 and 1,000,000 (10^6), inclusive.
// -S will be between 1 and 1,000,000,000,000 (10^12), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 3
// 8
// 
// Returns: 4
// 
// The following subtable (shown in bold italic) has a sum of 8:
// 
// 0 1 2
// 3 4 5
// 
// 
// 1)
// 3
// 3
// 10
// 
// Returns: -1
// 
// 
// 
// 2)
// 3
// 3
// 36
// 
// Returns: 9
// 
// 
// 
// 3)
// 25
// 25
// 16000
// 
// Returns: 32
// 
// 
// 
// 4)
// 1000000
// 1000000
// 1000000000000
// 
// Returns: 2
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
