#include <bits/stdc++.h>
using namespace std;
 

using ll = long long;
constexpr ll M = 1e9 + 7;

int main() {
    vector<vector<ll>> comb(512, vector<ll>(512));
    for(int i = 0; i < 512; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(i == j || j == 0) {
                comb[i][j] = 1;
            } else {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
            }
        }
    }

    vector<int> x;
    vector<int> sum = {0};
    for(int i = 0; i < 26; ++i) {
        int f;
        cin >> f;
        if(f == 0) {
            continue;
        }
        x.push_back(f);
        sum.push_back(f + sum.back());
    }

    int const n = x.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(300));
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= sum[i]; ++j) {
            for(int k = 1; k <= x[i]; ++k) {
                for(int l = 0; l <= min(j, k); ++l) {
                    ll t = comb[x[i] - 1][k - 1];
                    t = (t * comb[j][l]) % M;
                    t = (t * comb[sum[i] - j + 1][k - l]) % M;
                    t = (t * dp[i][j]) % M;
                    (dp[i + 1][j - l + x[i] - k] += t) %= M;
                }
            }
        }
    }
    cout << dp[n][0] << endl;
}
