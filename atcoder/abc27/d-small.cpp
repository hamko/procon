#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

#define rep(i,n) for(int i = 0; i < n; i++)
#define MAX_N 100005

int dp_[2][MAX_N*2];
int* dp[2];

int main(void) {
    rep(i, 2) dp[i] = dp_[i] + MAX_N;
    rep(i, 2) rep(j, MAX_N*2) dp_[i][j] = -INF;
    dp[0][0] = 0;

    string S; cin >> S;
    rep(i, S.length()) for (int j = -i-2; j < i+2; j++) {
        int next = (i + 1) % 2, prev = i % 2;
        if (S[i] == 'M') 
            dp[next][j] = max(dp[prev][j+1], dp[prev][j-1]);
        else if (S[i] == '+')
            dp[next][j] = dp[prev][j] + j;
        else 
            dp[next][j] = dp[prev][j] - j;
    }

    cout << dp[S.length()%2][0] << endl;

    return 0;
}
