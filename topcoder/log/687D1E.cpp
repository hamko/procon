#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vld = vector<ld>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

class AlmostFibonacciKnapsack {
    public:
        vector <int> getIndices(long long x) {
            vector<int> ret; ret.reserve(10000);

            vector<ll> f; f.reserve(10000);
            f.pb(2), f.pb(3);
            ll i = 2;
            while (f[f.size()-1] < 1e18) {
                f.pb(f[i-1]+f[i-2]-1); 
                i++;
            }
            cout << f << endl;
            for (ll i = f.size() - 1; i >= 0; i--) {
                if (x >= f[i] && x - f[i] != 1) {
                    x -= f[i];
                    ret.pb(i+1);
                }
            }
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
bool KawigiEdit_RunTest(int testNum, long long p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	AlmostFibonacciKnapsack *obj;
	vector <int> answer;
	obj = new AlmostFibonacciKnapsack();
	clock_t startTime = clock();
	answer = obj->getIndices(p0);
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
	
	long long p0;
	vector <int> p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 148ll;
	p1 = {6,10,8,5};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 2ll;
	p1 = {1};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 13ll;
	p1 = {2,3,4};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 3ll;
	p1 = {2};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 86267769395ll;
	p1 = {3,14,15,9,26,53,5,8};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// You are given a sequence of integers.
// This sequence is defined as follows:
// 
// A[1] = 2
// A[2] = 3
// for each n >= 3, A[n] = A[n-1] + A[n-2] - 1
// 
// 
// 
// 
// You are given a long long x that is at least 2.
// Your task is to write x as a sum of distinct elements of the above sequence.
// More precisely, you have to find and return any valid vector <int> B with the following properties:
// 
// The elements of B are distinct positive integers.
// x = A[B[0]] + A[B[1]] + ... + A[B[k-1]], where k is the number of elements in B.
// 
// 
// 
// 
// If there are multiple solutions, return any of them.
// If there are no solutions, return the vector <int> {-1} instead.
// 
// 
// DEFINITION
// Class:AlmostFibonacciKnapsack
// Method:getIndices
// Parameters:long long
// Returns:vector <int>
// Method signature:vector <int> getIndices(long long x)
// 
// 
// CONSTRAINTS
// -x will be between 2 and 10^18, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 148
// 
// Returns: {6, 10, 8, 5 }
// 
// The first few terms of the sequence are 2,3,4,6,9,14,22,35,56,90.
// We can see that 14+90+35+9=148, and their respective indices are 6,10,8,5.
// 
// 1)
// 2
// 
// Returns: {1 }
// 
// 
// 
// 2)
// 13
// 
// Returns: {2, 3, 4 }
// 
// 
// 
// 3)
// 3
// 
// Returns: {2 }
// 
// 
// 
// 4)
// 86267769395
// 
// Returns: {3, 14, 15, 9, 26, 53, 5, 8 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
