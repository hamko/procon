#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
int MOD = 1e9 + 7;

int main() {
    int D; cin >> D;
    vector<vector<int> > dp(D, vector<int>(2));
    dp[0][0] = 1;
    string s; cin >> s;
    for (char c: s) {
        int k = c - '0';
        vector<vector<int> > _dp(D, vector<int>(2));
        for (int x = 0; x < D; x++)
            for (int i = 0; i < 10; i++) {
                int _x = (x + i) % D;
                _dp[_x][1] = (_dp[_x][1] + dp[x][1]) % MOD;
                if (i < k) _dp[_x][1] = (_dp[_x][1] + dp[x][0]) % MOD;
                if (i == k) _dp[_x][0] = (_dp[_x][0] + dp[x][0]) % MOD;
            }
        dp = _dp;
    }
    int ans = (dp[0][0] + dp[0][1] - 1) % MOD;
    cout << ans << endl;
}
