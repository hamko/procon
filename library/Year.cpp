#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

vll year        = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vll leapyear    = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vll syear       = {0,31,59,90,120,151,181,212,243,273,304,334,365};
vll sleapyear   = {0,31,60,91,121,152,182,213,244,274,305,335,366};
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
    cin.tie(0); ios::sync_with_stdio(false);
    return 0;
}
