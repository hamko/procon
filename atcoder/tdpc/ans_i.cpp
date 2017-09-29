#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int const n = s.size();
    // [l, r)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int w = 0; w <= n; ++w) {
        for(int l = 0; l + w <= n; ++l) {
            for(int i = l; i <= l + w; ++i) {
                dp[l][l + w] = max(dp[l][l + w], dp[l][i] + dp[i][l + w]);
            }
            if(dp[l][l + w] != w) {
                continue;
            }
            for(int d = 0; d <= 3; ++d) {
                if(l - d < 0 || n < l + w + 3 - d) {
                    continue;
                }
                auto iwi = s.substr(l - d, d) + s.substr(l + w, 3 - d);
                if(iwi == "iwi") {
                    dp[l - d][l + w + 3 - d] = dp[l][l + w] + 3;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            res = max(dp[i][j], res);
        }
    }
    res /= 3;
    cout << res << endl;
}
