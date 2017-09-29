#include <bits/stdc++.h>
using namespace std;

static const long long mo = 1e9+7;
long long dp[1000010] = {1, 0, 1};
int main(void) {
    int n, k; cin >> n >> k;
    for (int i = 3; i <= n; i++) 
        dp[i] = ((2ll * dp[i-1] - (i-k-1>=0 ? dp[i-k-1] : 0)) % mo + mo) % mo;

    cout << ((dp[n] - dp[n-k]) % mo + mo) % mo << endl;

    return 0;
}
