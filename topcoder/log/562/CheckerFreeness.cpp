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

class CheckerFreeness {
    public:
        string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
            string wx, wy, bx, by;
            for (auto x : whiteX) wx += x;
            for (auto x : whiteY) wy += x;
            for (auto x : blackX) bx += x;
            for (auto x : blackY) by += x;

            vector<ll> px;
            vector<ll> py;
            stringstream ss;
            ll tmp;

            ss << wx; while (ss >> tmp) px.pb(tmp); ss.clear();
            ss << wy; while (ss >> tmp) py.pb(tmp); ss.clear();
            ll wnum = px.size();
            ss << bx; while (ss >> tmp) px.pb(tmp); ss.clear();
            ss << by; while (ss >> tmp) py.pb(tmp); ss.clear();

            vector<bool> color(px.size());
            rep(i, wnum) {
                color[i] = 1;
            }

            /*
            cout << px << endl;
            cout << py << endl;
            return 0;
            */

            ll point_num = px.size();
            vector<vector<ll>> x(point_num, vll(2));
            double s = 0;
            rep(i, point_num) {
                x[i][0] = px[i];
                x[i][1] = py[i];
                s += px[i] + py[i];
            }
            cout << x << endl;
            cout << color << endl;

            double w[2] = {0.2, 0.3};
            double
                g, /*識別関数*/
                a = 0.5, /*学習率*/
                decision /*判定*/;

            bool ret = 0;
            rep(_, 1000) {
                decision = 0;
                for(int i=0; i<point_num; i++){
                    g = x[i][0] * w[0] + x[i][1] * w[1];
                    /*
                    cout << "入力:" << x[i][0] << "," << x[i][1]
                        << "  重み:" << w[0] <<  "," << w[1] 
                        << "  識別値:" << g << endl;
                        */
                    if(color[i] && g<0){
//                        cout << i << " " << color[i] << " " << g  << endl;
                        decision++;
                        w[0] = w[0] + a * x[i][0];
                        w[1] = w[1] + a * x[i][1];
                    }
                    if(!color[i] && g>0){
//                        cout << i << " " << color[i] << " " << g  << endl;
                        decision++;
                        w[0] = w[0] - a * x[i][0];
                        w[1] = w[1] - a * x[i][1];
                    }
                }
//                cout << endl;
                if(decision == 0) {
                    ret = 1;
                    break;
                }
            }


            return ret ? "YES" : "NO";
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, vector <string> p3, bool hasAnswer, string p4) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p1[i] << "\"";
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p2[i] << "\"";
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p3[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    CheckerFreeness *obj;
    string answer;
    obj = new CheckerFreeness();
    clock_t startTime = clock();
    answer = obj->isFree(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p4 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
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

    vector <string> p0;
    vector <string> p1;
    vector <string> p2;
    vector <string> p3;
    string p4;

    // ----- test 0 -----
    disabled = false;
    p0 = {"1 2"};
    p1 = {"2 1"};
    p2 = {"1 2"};
    p3 = {"1 2"};
    p4 = "NO";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = {"2","5","3"," ","1","7","3"};
    p1 = {"180 254"};
    p2 = {"32","5 1","42"};
    p3 = {"462 423"};
    p4 = "YES";
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    /*
    // ----- test 2 -----
    disabled = false;
    p0 = {"1 10000000 9999999"};
    p1 = {"1 9999999 1"};
    p2 = {"2 5000000 9999998"};
    p3 = {"2 5000001 9999999"};
    p4 = "YES";
    all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = {"1"};
    p1 = {"2"};
    p2 = {"3"};
    p3 = {"4"};
    p4 = "YES";
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7","716 9645 2547 9490 9365 326 6601 5215 6771 7153 72","93 5922 714 2258 4369 9524 302 8417 6620 1143"};
    p1 = {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279","6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665","4 446 3561 7241 6168 2025 4739 9501 5340 6446"};
    p2 = {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94","24 5374 6718 2919 6068 6644 5070 710 7121 1630 370","3 1051 5739 9294 8798 3371 8107 2130 6608 534"};
    p3 = {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 ","8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 ","7259 8842 5294 7209 2317 3825 3413 820 3774 5393"};
    p4 = "NO";
    all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 5 -----
    disabled = false;
    p0 = {"219211 1996214 1706774 3634920 909831 1774128 8503","52 2233050 2099138 3380396 1128982 3682525 1483700"," 763080 487867 8203 1791027 463556 1103323 1406861"," 6374234 760949 4340236 727393 2073832 1289052 103","8147 4448130 151066 412440 1068735 377239 2677933 ","1299598 339843 289973 3707319 555280 230418 431719"};
    p1 = {"1638083 5698739 3105504 9726902 9745795 5049444 15","80592 3952120 6606668 7460527 7239299 8726128 4913","547 6264100 5701660 8865937 4969114 8014845 327236","1 6389154 9739755 2561669 9412417 5452337 3150506 ","5832197 1571976 8779325 3306446 948271 5133709 949","394 6919798 7525636 3568024 6833196 9237472 733313","1 9939064 9720014"};
    p2 = {"5860334 8007503 7455523 4864927 9573526 2718360 81","12104 6684287 9921506 4840886 5415948 3451454 5320","996 9268757 9261724 8254668 2292750 8035828 233352","1 7676906 5234406 8533320 6562751 4884098 4971897 ","5569360 8519168 3100295 9351613 7733878 7579030 32","46775 7297460 8370542 7099759 5782969 2978083 3390","488 7482758 1332401 6094629 9717305 5503121 572842","1 4903563 6331656 2867455 3410007 7751527 7228221 ","4111694 5171296 6847697 4601273 7599828 5515929 94","60593 9332762 5389080 4512091 8668538 5711743 5838","534 4825079 8145628 3810005 2964724 5594550 785748","3 6283769"};
    p3 = {"5911694 8009943 212555 5838688 9896256 607434 5857","663 4616750 1477573 7168026 3090917 4379806 326465","7 4189076 2104028 3279691 94211 8503556 78457 4394","360 3344176 3223317 2624498 4883494 1532240 732937","1 1518674 1353567 892134 5536454 8527392 2603965 6","623264 8830827 2030444 3002706 83058 4475866 20876","25 1790695 4034441 5409379 3571098 4600050 736561 ","250475 3733256 3011439 2144994 4523046 3119883 607","582 8361403 6525451 7518329 926803 4884524 8424659"," 7088689 5762049 9532481 4914186 7314621 4339084 3","741685 3837953 3177252 612550 9688871 5872931"};
    p4 = "YES";
    all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    */
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
// Given is a finite set S of distinct points in the XY plane.
// No three of the points lie on the same line.
// Each of the points is colored either white or black.
// A convex quadrilateral with vertices in four of the vertices of S is called a checker if no pair of adjacent vertices shares the same color.
// In other words, in a checker two opposite vertices have to be white and the other two have to be black.
// The set S is called checker-free if there is no checker with vertices in the set.
// 
// 
// 
// 
// 
// You are given four vector <string>s: whiteX, whiteY, blackX, and blackY.
// These encode the X and Y coordinates of all white and all black points in S, respectively.
// By concatenating all elements of whiteX you will obtain a list of positive integers separated by single spaces: the X-coordinates of all white points.
// By concatenating all elements of whiteY you will obtain a list of positive integers separated by single spaces: the Y-coordinates of all white points, in the same order.
// The vector <string>s blackX and blackY describe the black points in S in the same way.
// 
// Return "YES" if the given set is checker-free. Otherwise, return "NO".
// 
// DEFINITION
// Class:CheckerFreeness
// Method:isFree
// Parameters:vector <string>, vector <string>, vector <string>, vector <string>
// Returns:string
// Method signature:string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY)
// 
// 
// CONSTRAINTS
// -whiteX, whiteY, blackX and blackY will each contain between 1 and 50 elements, inclusive.
// -Each element of whiteX, whiteY, blackX and blackY will contain between 1 and 50 characters, inclusive.
// -After concatenating the elements of whiteX, the resulting string will be a single space separated list of integers. The same things will hold for whiteY, blackX and blackY.
// -There will be between 1 and 222 integers in each of the lists.
// -The number of integers in the lists of whiteX and whiteY will be the same.
// -The number of integers in the lists of blackX and blackY will be the same.
// -Each integer in the lists will be between 1 and 10,000,000, inclusive.
// -No two points will be the same.
// -No three points will be on the same line.
// -Integers in the lists will have no leading zeros.
// 
// 
// EXAMPLES
// 
// 0)
// {"1 2"}
// {"2 1"}
// {"1 2"}
// {"1 2"}
// 
// Returns: "NO"
// 
// 
// 
// 
// 1)
// {"2", "5", "3", " ", "1", "7", "3"}
// {"180 254"}
// {"32", "5 1", "42"}
// {"462 423"}
// 
// Returns: "YES"
// 
// Concatenate all elements of each vector <string> correctly.
// 
// 
// 
// 
// 2)
// {"1 10000000 9999999"}
// {"1 9999999 1"}
// {"2 5000000 9999998"}
// {"2 5000001 9999999"}
// 
// Returns: "YES"
// 
// The values of coordinates can be large.
// Watch out for overflow and precision errors.
// 
// 3)
// {"1"}
// {"2"}
// {"3"}
// {"4"}
// 
// Returns: "YES"
// 
// There are only two points, so this input is obviously checker-free.
// 
// 4)
// {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
// ,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
// ,"93 5922 714 2258 4369 9524 302 8417 6620 1143"}
// {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
// ,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
// ,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"}
// {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
// ,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
// ,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"}
// {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
// ,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
// ,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"}
// 
// Returns: "NO"
// 
// 
// 
// 5)
// {"219211 1996214 1706774 3634920 909831 1774128 8503"
// ,"52 2233050 2099138 3380396 1128982 3682525 1483700"
// ," 763080 487867 8203 1791027 463556 1103323 1406861"
// ," 6374234 760949 4340236 727393 2073832 1289052 103"
// ,"8147 4448130 151066 412440 1068735 377239 2677933 "
// ,"1299598 339843 289973 3707319 555280 230418 431719"}
// {"1638083 5698739 3105504 9726902 9745795 5049444 15"
// ,"80592 3952120 6606668 7460527 7239299 8726128 4913"
// ,"547 6264100 5701660 8865937 4969114 8014845 327236"
// ,"1 6389154 9739755 2561669 9412417 5452337 3150506 "
// ,"5832197 1571976 8779325 3306446 948271 5133709 949"
// ,"394 6919798 7525636 3568024 6833196 9237472 733313"
// ,"1 9939064 9720014"}
// {"5860334 8007503 7455523 4864927 9573526 2718360 81"
// ,"12104 6684287 9921506 4840886 5415948 3451454 5320"
// ,"996 9268757 9261724 8254668 2292750 8035828 233352"
// ,"1 7676906 5234406 8533320 6562751 4884098 4971897 "
// ,"5569360 8519168 3100295 9351613 7733878 7579030 32"
// ,"46775 7297460 8370542 7099759 5782969 2978083 3390"
// ,"488 7482758 1332401 6094629 9717305 5503121 572842"
// ,"1 4903563 6331656 2867455 3410007 7751527 7228221 "
// ,"4111694 5171296 6847697 4601273 7599828 5515929 94"
// ,"60593 9332762 5389080 4512091 8668538 5711743 5838"
// ,"534 4825079 8145628 3810005 2964724 5594550 785748"
// ,"3 6283769"}
// {"5911694 8009943 212555 5838688 9896256 607434 5857"
// ,"663 4616750 1477573 7168026 3090917 4379806 326465"
// ,"7 4189076 2104028 3279691 94211 8503556 78457 4394"
// ,"360 3344176 3223317 2624498 4883494 1532240 732937"
// ,"1 1518674 1353567 892134 5536454 8527392 2603965 6"
// ,"623264 8830827 2030444 3002706 83058 4475866 20876"
// ,"25 1790695 4034441 5409379 3571098 4600050 736561 "
// ,"250475 3733256 3011439 2144994 4523046 3119883 607"
// ,"582 8361403 6525451 7518329 926803 4884524 8424659"
// ," 7088689 5762049 9532481 4914186 7314621 4339084 3"
// ,"741685 3837953 3177252 612550 9688871 5872931"}
// 
// Returns: "YES"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
