#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long; using vll = vector<ll>;

int main(void) {
    ll n, m; cin >> n >> m;
    vll a(m); rep(i, a.size()) cin >> a[i];
    sort(all(a));
    ll negnum = (ll)(upper_bound(all(a), 0) - a.begin());
    ll ret = 1e18; 
    rep(j, n + 1) { // j個正のを取る
        if (j > m - negnum || n - j > negnum) continue;
        ll sp = (j == 0 ? 0 : +a[negnum+j-1]);
        ll sn = (j == n ? 0 : -a[negnum+j-n]);
        ret = min(ret, min(sp + sn * 2, sn + sp * 2));
    }
    cout << ret << endl;

    return 0;
}
