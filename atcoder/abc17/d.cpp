#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
using ll = long long; using vi = vector<int>;

#define MAX_N 100005
#define mod 1000000007

int main(void) {
    int n, m; cin >> n >> m;
    vi f(n); rep(i, n) { cin >> f[i]; f[i]--; }

    vi diff(n);
    map<int, int> memo;
    int b = -1;
    rep(i, n) {
        if (!memo.count(f[i])) {
            diff[i] = i - b;
        } else {
            diff[i] = min(i - b, i - memo[f[i]]);
            b = max(b, memo[f[i]]);
        }
        memo[f[i]] = i;
    }


    // サプリiまで食べることが確定している時の場合の数
    // 集めるDP
    ll dp[MAX_N] = {};
    ll dpsum[MAX_N] = {};
    dp[0] = 1; dpsum[0] = 1;
    rep(i, n) { 
        (dp[i+1] += (dpsum[i] - dpsum[i-diff[i]])) %= mod;
        (dpsum[i+1] = dpsum[i] + dp[i+1]) %= mod;
    }

    cout << (dp[n] + mod)%mod << endl;

    return 0;
}
