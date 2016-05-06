#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 1e9

int main(void) {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        int tmp; cin >> a[i];
    }

    int dp[n];
    fill(dp, dp + n, INF);
    for (int i=0; i<n; ++i) {
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
    
    cout << (n - (int)(lower_bound(dp, dp+n, INF) - dp)) << endl;
    return 0;
}
