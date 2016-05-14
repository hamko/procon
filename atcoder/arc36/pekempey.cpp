#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K;
    cin >> n >> K;
    string s;
    cin >> s;

    const int offset = 333;
    const long long mod = 1e9 + 7;
    static int dp0[666][666], dp1[666][666]; // min(0-1), max(0-1)

    dp0[offset][offset] = 1;

    for (int i = 0; i < n; i++) {
        memset(dp1, 0, sizeof(dp1));
        for (int j = offset - K; j <= offset + K; j++) {
            for (int k = offset - K; k <= offset + K; k++) {
                if (dp0[j][k] == 0) continue;
                if (s[i] == '0' || s[i] == '?')
                    (dp1[min(j + 1, offset + 1)][max(k + 1, offset + 1)] += dp0[j][k]) %= mod;
                if (s[i] == '1' || s[i] == '?')
                    (dp1[min(j - 1, offset - 1)][max(k - 1, offset - 1)] += dp0[j][k]) %= mod;
            }
        }
        for (int j = offset - K; j <= offset + K; j++) {
            for (int k = offset - K; k <= offset + K; k++) {
                if (dp1[j][k]) {
                    cout << i << "\t" << j-offset << "\t" << k-offset << "\t:\t" << dp1[j][k] << endl;
                }
            }
        }
        swap(dp0, dp1);
    }

    long long ans = 0;
    for (int j = offset - K; j <= offset + K; j++) {
        for (int k = offset - K; k <= offset + K; k++) {
            (ans += dp0[j][k]) %= mod;
        }
    }
    cout << ans << endl;
}
