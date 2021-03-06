#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
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

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

class FoxAndChess {
    public:
        string ableToMove(string b, string t) {
            ll n = b.size();
            if (count_if(all(b), [&](char c) { return c == 'R'; }) != count_if(all(t), [&](char c) { return c == 'R'; } ))
                return "Impossible";
            if (count_if(all(b), [&](char c) { return c == 'L'; }) != count_if(all(t), [&](char c) { return c == 'L'; } ))
                return "Impossible";

            rep(_, 10000) {
                rep(ti, n) if (t[ti] != '.') {
                    ll dir = (t[ti] == 'L' ? 1 : -1);
                    ll rev = (t[ti] == 'L' ? 'R' : 'L');
                    ll bi = ti;
                    while (bi >= 0 && bi < n) {
                        if (b[bi] == rev) {
                            break;
                        }
                        else if (t[ti] == b[bi]) {
                            b[bi] = '.';
                            b[ti] = t[ti];
                            break;
                        }

                        bi += dir;
                    }
                }
            }

            return (b == t ? "Possible" : "Impossible");
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
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, string p2) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
    cout << "]" << endl;
    FoxAndChess *obj;
    string answer;
    obj = new FoxAndChess();
    clock_t startTime = clock();
    answer = obj->ableToMove(p0, p1);
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
    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    string p0;
    string p1;
    string p2;

    // ----- test 0 -----
    disabled = false;
    p0 = "R...";
    p1 = "..R.";
    p2 = "Possible";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = "..R.";
    p1 = "R...";
    p2 = "Impossible";
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = ".L.R.R.";
    p1 = "L...R.R";
    p2 = "Possible";
    all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = ".L.R.";
    p1 = ".R.L.";
    p2 = "Impossible";
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = "LRLLRLRLLRLLRLRLRL";
    p1 = "LRLLRLRLLRLLRLRLRL";
    p2 = "Possible";
    all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 5 -----
    disabled = false;
    p0 = "L";
    p1 = ".";
    p2 = "Impossible";
    all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
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
// Fox Ciel is playing a game with some chess pawns and a strip of paper.
// The strip of paper is divided into a row of cells.
// Each cell can contain at most one pawn.
// The white pawns will be denoted 'R', because they are only allowed to move to the right.
// The black pawns will be denoted 'L', because they are only allowed to move to the left.
// 
// 
// You are given a string begin that describes the current state of the strip: 'R' and 'L' are cells with corresponding pawns, and '.' are empty cells.
// 
// 
// You are now allowed to make some moves (as many as you wish, possibly zero).
// In each move you may either take a 'R' pawn and move it one cell to the right, or take a 'L' pawn and move it one cell to the left.
// Of course, both types of moves are only valid if the destination cell is currently empty.
// Pawns are not allowed to move out of bounds.
// 
// 
// You are also given a string target that represents the desired state of the strip.
// If it is possible to reach target from begin by making some valid moves, return "Possible" (quotes for clarity), otherwise return "Impossible".
// 
// DEFINITION
// Class:FoxAndChess
// Method:ableToMove
// Parameters:string, string
// Returns:string
// Method signature:string ableToMove(string begin, string target)
// 
// 
// CONSTRAINTS
// -begin will contain between 1 and 50 elements, inclusive.
// -begin and target will contain the same number of elements.
// -Each character in begin and target will be one of '.', 'L' and 'R'.
// 
// 
// EXAMPLES
// 
// 0)
// "R..."
// "..R."
// 
// Returns: "Possible"
// 
// You have to move the only pawn to the right twice.
// 
// 1)
// "..R."
// "R..."
// 
// Returns: "Impossible"
// 
// Here target cannot be reached because the only pawn is only allowed to move to the right.
// 
// 2)
// ".L.R.R."
// "L...R.R"
// 
// Returns: "Possible"
// 
// 
// 
// 3)
// ".L.R."
// ".R.L."
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// "LRLLRLRLLRLLRLRLRL"
// "LRLLRLRLLRLLRLRLRL"
// 
// Returns: "Possible"
// 
// 
// 
// 5)
// "L"
// "."
// 
// Returns: "Impossible"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
