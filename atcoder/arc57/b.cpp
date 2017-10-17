#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
using ld = long double;  using vld = vector<ld>; 
static const long long INF = 1e18;

int main(void) {
    ll n, k; cin >> n >> k;
    vll a(n); rep(i, n) cin >> a[i];
    vll s(n+1); rep(i, n) s[i+1] = s[i] + a[i];
    if (accumulate(all(a), 0ll) == k) {
        cout << 1 << endl;
        return 0;
    }

    // dp[i][j] = i日見てj日嬉しい時の最小勝利回数
    vvll dp(n+1, vll(n+1, INF));

    dp[0][0] = 0;
    // 配るDP
    rep(i, n) {
        rep(j, n) if (dp[i][j] != INF) {
            chmin(dp[i+1][j], dp[i][j]);
            ll k = 1;
            if (j != 0)
                k = ceill((ld)dp[i][j] * (ld)s[i+1] / (ld)s[i] - dp[i][j] + 1e-9l);

            chmin(dp[i+1][j+1], dp[i][j] + k);
        }
    }
    ll ret = 0;
    rep(j, dp[n].size()) if (dp[n][j] <= k) 
        chmax(ret, j);
    cout << ret << endl;

    return 0;
}
