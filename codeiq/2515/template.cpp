#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long; using vll = vector<ll>; 

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    static ll dp[1001][1001][7] = {};
    dp[0][0][0] = 1;
    vll c = {1, 5, 10, 50, 100, 500};
    rep(i, n) rep(j, 1001) rep(h, 7) if (dp[i][j][h]) rep(k, c.size()) {
        if (h && h - 1 > k) continue;
        if (j + c[k] > 1000) continue;
        dp[i+1][j+c[k]][k+1] += dp[i][j][h];
    }
    ll ret = 0;
    rep(i, 1001) rep(k, 7) {
        ret += dp[i][n][k];
    }
    cout << ret << endl;
    return 0;
}
