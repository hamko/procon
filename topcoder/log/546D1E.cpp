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

#define MAX_N 100005

class KleofasTail {
public:
    ll rec(ll k, ll x) {
//        cout << k << " " << x << "#start" << endl;
        if (!k) return x + 1;
        if (k > x) return 0;
        if (!(k & 1)) return rec(k << 1, x) + rec(k | 1, x) + 1;
        ll ret = 0;
        ll i = 0;
        while (1) {
            ll l = (k << i), r = l + (1 << i);  // 半開
//            cout << l << " " << r << "#range" << endl;
            ll d = min<ll>(r - l, max<ll>(0, x - l + 1));
            ret += d;
            if (!d)
                break;
            i++;
        }
//        cout << k << " " << x << " : " << ret << "#ret" << endl;
        return ret;
    }
	long long countGoodSequences(long long K, long long A, long long B) {
//        while(1){ll k, x; cin >> k >> x; rec(k, x);}
        return rec(K, B) - rec(K, A-1);
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
bool KawigiEdit_RunTest(int testNum, long long p0, long long p1, long long p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	KleofasTail *obj;
	long long answer;
	obj = new KleofasTail();
	clock_t startTime = clock();
	answer = obj->countGoodSequences(p0, p1, p2);
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
	
	long long p0;
	long long p1;
	long long p2;
	long long p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 3ll;
	p1 = 4ll;
	p2 = 8ll;
	p3 = 2ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 1ll;
	p1 = 23457ll;
	p2 = 123456ll;
	p3 = 100000ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 1234567890123456ll;
	p1 = 10ll;
	p2 = 1000000ll;
	p3 = 0ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 0ll;
	p1 = 0ll;
	p2 = 2ll;
	p3 = 3ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 2ll;
	p1 = 3ll;
	p2 = 3ll;
	p3 = 1ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = 13ll;
	p1 = 12345ll;
	p2 = 67890123ll;
	p3 = 8387584ll;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = 0ll;
	p1 = 1ll;
	p2 = 2ll;
	p3 = 2ll;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = 12ll;
	p1 = 100ll;
	p2 = 101ll;
	p3 = 2ll;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 8 -----
	disabled = false;
	p0 = 4ll;
	p1 = 2ll;
	p2 = 10ll;
	p3 = 5ll;
	all_right = (disabled || KawigiEdit_RunTest(8, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 9 -----
	disabled = false;
	p0 = 7ll;
	p1 = 123456789012ll;
	p2 = 123456789034ll;
	p3 = 23ll;
	all_right = (disabled || KawigiEdit_RunTest(9, p0, p1, p2, true, p3) ) && all_right;
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
// Let X be a nonnegative integer.
// The Kleofas tail of X is an infinite sequence of nonnegative integers, defined as follows:
// 
// 
// The first element is X.
// After an even element Y, the next element of the sequence is Y/2.
// After an odd element Z, the next element of the sequence is Z-1.
// 
// 
// For example, the Kleofas tail of 60 starts as follows: 60, 30, 15, 14, 7, 6, ...
// 
// 
// You are given long longs K, A, and B.
// Return the number of integers X between A and B, inclusive, such that the Kleofas tail of X contains at least one occurrence of K.
// 
// 
// DEFINITION
// Class:KleofasTail
// Method:countGoodSequences
// Parameters:long long, long long, long long
// Returns:long long
// Method signature:long long countGoodSequences(long long K, long long A, long long B)
// 
// 
// NOTES
// -Zero is an even number.
// 
// 
// CONSTRAINTS
// -K will be between 0 and 10^18, inclusive.
// -A will be between 0 and 10^18, inclusive.
// -B will be between 0 and 10^18, inclusive.
// -A will be less than or equal to B.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 4
// 8
// 
// Returns: 2
// 
// The value 3 occurs in the Kleofas tail of 6 and also in the Kleofas tail of 7.
// 
// 1)
// 1
// 23457
// 123456
// 
// Returns: 100000
// 
// For each X between 23457 and 123456, inclusive, the Kleofas tail of X contains the value 1.
// 
// 2)
// 1234567890123456
// 10
// 1000000
// 
// Returns: 0
// 
// Each Kleofas tail is a nonincreasing sequence.
// 
// 3)
// 0
// 0
// 2
// 
// Returns: 3
// 
// 
// 
// 4)
// 2
// 3
// 3
// 
// Returns: 1
// 
// The Kleofas tail of 3 is 3, 2, 1, 0, 0, 0, ...
// 
// 5)
// 13
// 12345
// 67890123
// 
// Returns: 8387584
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
