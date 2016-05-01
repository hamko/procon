// Atcoder ABC 23D

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

int main(void) {
    cin >> n; rep(i, n) cin >> h[i] >> s[i];

    /*
    // デバッグはここでチェック関数を確認するといい
    while (1) {
        ll t; cin >> t; 
        cout << check(t) << endl;
    }
    */

    // 構造は00000011111なら、check(mid)
    // 構造は11111000000なら、!check(mid)
    // lは最大の満たさない場所、rは最小の満たす場所。
    ll lo = -1, ro = (ll)4e18; // lが満たさないことを確認！
    while (ro - lo != 1) { 
        ll mid = (lo + ro) / 2; 
        // check関数が単純ならここに書いてもいいが、デバッグしにくくなるので関数は分けるべき
        check(mid)?ro=mid:lo=mid; 
    }
    cout << ro << endl;

    return 0;
}
