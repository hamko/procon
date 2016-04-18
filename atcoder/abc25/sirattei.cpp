#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define bitcount(b) __builtin_popcount(b)
#define MOD 1000000007
typedef long long ll;

int B[25]; // 盤のiにある数
int P[25]; // 数iが盤上位置

int dp[1 << 25];

#define XY(x, y) (1 << ((y) * 5 + (x)))

bool f(int i, int j) {
    int y = j / 5; int x = j % 5;
    if ((1 <= y && y <= 3) && (!(i & XY(x, y - 1)) ^ !(i & XY(x, y + 1))))
        return false;
    if ((1 <= x && x <= 3) && (!(i & XY(x - 1, y)) ^ !(i & XY(x + 1, y)))) 
        return false;
    return true;
}

int main() {
    memset(B,0xff,sizeof(B)); memset(P,0xff,sizeof(P));

    rep(xy, 25) {
        int i; cin >> i; i--;
        B[xy] = i;
        if (i != -1) {
            P[i] = xy;
        }
    }

    dp[0] = 1;
    // iで配ると、必ずその後にしか影響しないので、順方向に見ていけばOK
    rep(i, 1<<25) {
        if (dp[i] == 0) continue; // これがなかったのでTLE
        int n = bitcount(i);

        if (P[n] != -1) { // n は位置が決まっている
            int bn = 1<<P[n]; 
            if (i & bn) continue;
            if (!f(i, P[n])) continue;
            (dp[i | bn] += dp[i]) %= MOD;
        } else { 
            rep(j, 25) { // 盤面iのjにnを入れられそうなら配る
                int bj = 1<<j;
                if (B[j] != -1) continue;
                if (i & bj) continue;
                if (!f(i, j)) continue;
                (dp[i | bj] += dp[i]) %= MOD;
            }
        }
    }

    cout << dp[(1<<25)-1] << endl;

    return 0;
}
