#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

vll year    = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vll leapyear        = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vll syear   = {0,31,59,90,120,151,181,212,243,273,304,334,365};
vll sleapyear       = {0,31,60,91,121,152,182,213,244,274,305,335,366};
bool is_leap(ll y) {
    return !!((1 / (y % 4 + 1)) * (1 - 1 / (y % 100 + 1)) + (1 / (y % 400 + 1)));
}
ll get_days(ll y) {
    return (is_leap(y) ? 366 : 365);
}
// 西暦y年の、0-index番目の月・日を返す。
// 異常値は月が13以上か、日が0以下
P get_day(ll y, ll index) {
    int m = 0, d = 0;
    rep(i, 12) 
        if (index<=(is_leap(y)?sleapyear:syear)[i+1])
            break;
        else 
            m++;
    return P(m+1, index-(is_leap(y)?sleapyear:syear)[m]);
}
ll get_index(ll y, P md) {
    return (is_leap(y)?sleapyear:syear)[md.first-1] + md.second;
}

int main(void) {
    /*
    while(1) {
    ll y, index; cin >> y >> index;
    cout << get_day(y, index) << endl;
    }
    */


    int y, m, d; scanf("%d/%d/%d", &y, &m, &d);
    vll months = (is_leap(y) ? leapyear : year);

    for (int i = get_index(y, P(m, d)); i < get_days(y); i++) {
        P md = get_day(y, i);
        if (y % (md.first * md.second) == 0) {
            P md = get_day(y, i);
            cout << y 
                << "/" << (md.first<10?"0":"") << md.first
                << "/" << (md.second<10?"0":"") << md.second <<endl;
            return 0;
        }
    }
    cout << y + 1 << "/01/01" << endl;

    return 0;
}
