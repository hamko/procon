#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()

using ll = long long; using vll = vector<ll>;

static const long long mo = 1e9+7;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, t; cin >> n >> t;
    vll a(n); rep(i, a.size()) cin >> a[i];
    sort(all(a));

    ll ret = 1;
    rep(i, n) 
        (ret *= i + 1 - (ll)(lower_bound(a.begin(), a.begin() + i + 1, a[i] - t) - a.begin())) %= mo; 
    cout << ret << endl;
    return 0;
}
