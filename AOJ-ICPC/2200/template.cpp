#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
static const long long INF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n, m; 
    while (cin >> n >> m && n && m) {
        vvll dl(n, vll(n, INF)), ds(n, vll(n, INF));
        rep(i, n) dl[i][i] = ds[i][i] = 0;

        rep(i, m) {
            ll x, y, t; char sl; cin >> x >> y >> t >> sl; x--; y--;
            (sl == 'L' ? dl : ds)[x][y] = (sl == 'L' ? dl : ds)[y][x] = t;
        }
        rep(k, n) rep(i, n) rep(j, n) 
            chmin(dl[i][j], dl[i][k]+dl[k][j]), chmin(ds[i][j], ds[i][k]+ds[k][j]);

        ll r; cin >> r;
        vll z(r); rep(i, r) { cin >> z[i]; z[i]--; } 

        // 船がjにある時にi個配達を終わらせた時の最短時間
        vvll dp(r+1, vll(n, INF));
        dp[0][z[0]] = 0;
        rep(i, r) rep(j, n) { // jは港町
            if (dp[i][j] == INF) continue;
            rep(k, n) { // kはjから行ける港町, kを介してz[i]に行く
                if (ds[j][k] == INF) continue;
                ll tmp = (dp[i][j]/*今までかかってた時間*/ + 
                        dl[i?z[i-1]:z[0]][j]/*jにある船に戻る*/ +
                        ds[j][k]/*jからkに移動*/ + 
                        dl[k][z[i]]/*kから配達場所に移動*/);
                chmin(dp[i+1][k], tmp);
            }
            if (dl[i?z[i-1]:z[0]][z[i]] != INF)
                chmin(dp[i+1][j], 
                        dp[i][j]/*今までかかってた時間*/ + 
                        dl[i?z[i-1]:z[0]][z[i]]/*配達場所に移動*/);
        }

        ll ret = INF;
        rep(j, n) 
            chmin(ret, dp[r][j]);
        cout << ret << endl;
    }
    return 0;
}
