#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using vi = vector<int>;

#define MAX_W 10005
#define MAX_N 55

// dp(i, j, h) = 添字i未満までを使うとき、j枚貼り付け、幅wを占有したときの重要度合計最大値
int dp[2][MAX_N][MAX_W];

int main(void) {
    int w, n, k; cin >> w >> n >> k;
    vi a(n), b(n); rep(i, n) cin >> a[i] >> b[i];

    // 配る次元削減するDP
    dp[0][0][0] = 0;
    rep(i, n) { 
        int next = (i + 1) % 2, curr = i % 2;
        memset(dp[next], 0, sizeof(dp[next]));
        rep(j, k + 1) rep(h, w + 1) {  // ここをk, wをしていた。「k枚以下」などなので、ループの回し方に注意
            dp[next][j][h] = max(dp[next][j][h], dp[curr][j][h]); // iを使わない
            if (j <= k && h + a[i] <= w)
                dp[next][j+1][h+a[i]] = max(dp[next][j+1][h+a[i]], dp[curr][j][h] + b[i]); // iを使う
        }
        // ループの最後に、更新後の結果を出すとわかりやすい。
        // ↑のループに入れないのは、↑はたいていnextではなくcurrに関するcontinueで抜けちゃうから。
//        rep(j, k + 1) rep(h, w + 1) {
//             if (dp[next][j][h])
//                cout << i << " : " << j << " " << h << " : "  << dp[next][j][h] << endl; 
//        }
    }

    int ret = 0;
    int i = n % 2; rep(j, k+1) rep(h, w+1) 
        ret = max(ret, dp[i][j][h]);
    cout << ret << endl;

    return 0;
}
