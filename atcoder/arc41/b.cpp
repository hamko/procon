#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
using ll = long long;  using vll = vector<ll>;
static const long long INF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    vector<vll> a(n, vll(m, 0));
    rep(i, n) {
        string s; cin >> s;
        rep(j, m) {
            a[i][j] = s[j] - '0';
        }
    }

    vector<vll> ret(n, vll(m, 0));
    ll di[4] = {0, 1, -1, 0}, dj[4] = {1, 0, 0, -1};
    for (ll i = 1; i <= n-2; i++) for (ll j = 1; j <= m-2; j++) {
        ll mi = INF;
        rep(d, 4) mi = min(mi, a[i+di[d]][j+dj[d]]);
        rep(d, 4) a[i+di[d]][j+dj[d]] -= mi;
        ret[i][j] += mi;
    }
    rep(i, n) {
        rep(j, m) {
            cout << ret[i][j];
        }
        cout << endl;
    }

    return 0;
}
