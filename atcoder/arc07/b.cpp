#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
int main(void) {
    ll n, m; cin >> n >> m;
    vll a(m); rep(i, m) cin >> a[i];

    vll cd(n+1); rep(i, n+1) cd[i] = i;
    rep(i, m) swap(cd[0], *find(all(cd), a[i]));

    rep(i, n) cout << cd[i+1] << endl;

    return 0;
}
