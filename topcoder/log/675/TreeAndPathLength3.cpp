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
using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

class TreeAndPathLength3 {
    public:
        vector <int> construct(int s) {
            if (s <= 10) { vector<int> ret; rep(i, s + 2) { ret.pb(i); ret.pb(i+1); } return ret;}

            ll r = 0;
            int i = 0;
            while (i * (i + 1) <= s) r = i++;

            ll p = s - r * (r + 1);
            vi ret;
            ret.pb(0); ret.pb(1);
            rep(i, r) { ret.pb(0); ret.pb(i + 2); }
            rep(i, r) { ret.pb(1); ret.pb(2 + r + i); }
            rep(i, p + 1) { ret.pb(2 * r + 1 + i); ret.pb(2 * r + 1 + i + 1); }

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
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TreeAndPathLength3 *obj;
	vector <int> answer;
	obj = new TreeAndPathLength3();
	clock_t startTime = clock();
	answer = obj->construct(p0);
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
	
	int p0;
	vector <int> p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 1;
	p1 = {0,1,1,2,2,3};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 2;
	p1 = {0,1,1,2,2,3,3,4};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 6;
	p1 = {0,1,1,2,0,3,3,4,0,5,5,6};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 8;
	p1 = {0,1,1,2,1,3,3,4,3,5,5,6,5,7};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    // ----- test 4 -----
	disabled = false;
	p0 = 601;
	p1 = {0,1,1,2,1,3,3,4,3,5,5,6,5,7};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
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
// You are given an int s.
// Your task is to construct an undirected tree such that:
// 
// The number of nodes is between 1 and 500, inclusive.
// The number of simple paths of length 3 in the tree is exactly s.
// 
// 
// Note that the direction of the simple path does not matter: A-B-C-D is the same simple path as D-C-B-A.
// 
// It is guaranteed that for the constraints used in this task a tree with the required properties always exists.
// Find one such tree.
// 
// If your tree has n nodes, they must be labeled 0 through n-1.
// Return a vector <int> with (n-1)*2 elements.
// For each valid i, elements 2i and 2i+1 of the return value should be the endpoints of one of the edges in your tree.
// If there are multiple correct solutions, you may return any of them.
// 
// DEFINITION
// Class:TreeAndPathLength3
// Method:construct
// Parameters:int
// Returns:vector <int>
// Method signature:vector <int> construct(int s)
// 
// 
// CONSTRAINTS
// -s will be between 1 and 10,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: {0, 1, 1, 2, 2, 3 }
// 
// The return value has 6 elements, so it has to describe a tree on 4 vertices.
// This tree contains the edges 0-1, 1-2, and 2-3.
// We can easily verify that this tree does indeed contain exactly one simple path of length 3: the path 0-1-2-3.
// 
// 1)
// 2
// 
// Returns: {0, 1, 1, 2, 2, 3, 3, 4 }
// 
// The returned tree has 5 vertices.
// The two simple paths of length 3 in this tree are the paths 0-1-2-3 and 1-2-3-4.
// 
// 2)
// 6
// 
// Returns: {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }
// 
// The six simple paths of length 3 in this tree are the following paths:
// 2-1-0-3, 2-1-0-5, 4-3-0-1, 4-3-0-5, 6-5-0-1, and 6-5-0-3.
// 
// 3)
// 8
// 
// Returns: {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
