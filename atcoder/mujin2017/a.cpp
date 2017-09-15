#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long; using vll = vector<ll>;
static const long long mo = 1e9+7;

int main(void) {
    ll n; cin >> n;
    vll a(n); rep(i, n) cin >> a[i];

    ll ret = 1, c = 0;
    rep(i, n) 
        if (a[i] < 2*(i-c)+1) 
            (ret *= i + 1 - c) %= mo, c++;

    rep(i, n-c) (ret *= (i + 1)) %= mo;
    cout << ret << endl;

    return 0;
}
