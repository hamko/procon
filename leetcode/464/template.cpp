#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(char i = 0; i < (char)(n); i++)

int8_t dp[1<<20];
int max_m;
class Solution {
    public:
        bool dfs(int32_t mask, int16_t d) {
            if (d <= 0) 
                return 0;
            if (dp[mask] != -1) 
                return dp[mask];

            rep(i, max_m) 
                if ((mask & (1 << i)) == 0) 
                    if (d <= i + 1 || !dfs(mask | (1 << i), d - (i + 1)))
                        return dp[mask] = 1;

            return dp[mask] = 0;
        }
        bool canIWin(int m, int d) { // m <= 20, d <= 300
            if (d == 0) 
                return 1; 
            if (m * (m + 1) / 2 < d) 
                return 0;

            max_m = m;
            memset(dp, -1, sizeof(dp));
            return dfs(0, d);
        }
};

int main(void) {
    int m, d; cin >> m >> d;
    Solution s;
    cout << s.canIWin(m, d) << endl;

    return 0;
}
