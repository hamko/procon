#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
static const long long INF = 1e18;

#define MAX_N 100005
int n, h[MAX_N], s[MAX_N];
ll tmp[MAX_N];
bool check(ll p)
{
    rep(i, n) {
        if (p < h[i]) return false;
        tmp[i] = (p - h[i]) / s[i];
    }
    sort(tmp, tmp+n);
    rep(i, n) if (tmp[i] < i) return false;
    return true;
}

// Atcoder ABC 23D
int main(void) {
    cin >> n; rep(i, n) cin >> h[i] >> s[i];

    // 構造は000000000000000111111111111111111
    // lは最大の満たさない場所、rは最小の満たす場所。
    ll l = -1, r = INF; // lが満たさないことを確認！

    while (r - l != 1) { ll mid = (l + r) / 2; if (check(mid)) r = mid; else l = mid; }
    cout << r << endl;

    return 0;
}
