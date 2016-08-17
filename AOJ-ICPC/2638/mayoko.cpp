#include <bits/stdc++.h>
using namespace std;

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
const int MAXD = 303;
const int MOD = 1e9+7;
int D, S;
int l[MAXD];
int dp[MAXD][MAXD*MAXD][2];

ll mod_pow(ll x, ll p, int MOD) {
    if (x == 0) return 0;
    ll a = 1;
    while (p) {
        if (p%2) a = a*x%MOD;
        x = x*x%MOD;
        p/=2;
    }
    return a;
}

int dfs(int d, int rest, int flag) {
    int& ret = dp[d][rest][flag];
    if (ret >= 0) return ret;
    if (d == D) {
        ret = mod_pow(rest, D, MOD);
        if (flag) ret = -ret;
        ret = (ret%MOD+MOD)%MOD;
    } else {
        ret = dfs(d+1, rest, flag);
        if (rest >= l[d]) {
            ret += dfs(d+1, rest-l[d], flag^1);
        }
        ret %= MOD;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> D;
    for (int i = 0; i < D; i++)
        cin >> l[i];
    cin >> S;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, S, 0) << endl;
    return 0;
}
