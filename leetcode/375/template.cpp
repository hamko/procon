#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; 
using P = pair<ll, ll>;
static const long long INF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll dp[1000][1000];
    rep(i, 1000) rep(j, 1000) dp[i][j] = -1;

    function<ll(ll, ll)> f = [&](ll l, ll r) {
        if (l >= r) return 0ll;
        if (dp[l][r] >= 0) return dp[l][r];
        ll ret = INF; 
        repi(i, l, r) {
            chmin(ret, i + max(f(l, i-1), f(i+1, r)));
        }
        return dp[l][r] = ret;
    };
    cout << f(1, n) << endl;

    return 0;
}
