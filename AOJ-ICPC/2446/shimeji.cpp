#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
ll n, m, a[20], p[20], f[1 << 20];
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

int main(){
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> p[i];
    rep(i, 1 << n){
        ll t = 1;
        rep(j, n) if(i & 1 << j){
            ll u = a[j] / __gcd(t, a[j]);
            if(1.0 * t * u < 1.5e18) t *= u;
            else t = m + 1;
        }
        f[i] = m / t;
    }
    rep(i, n) rep(j, 1 << n) if(j & 1 << i) f[j] -= f[j ^ 1 << i];

    long double ans = 0;
    rep(i, 1 << n){
        long double e = 1;
        rep(j, n) e *= (i & 1 << j ? p[j] : 100 - p[j]) / 100.0l;
        ans += e * (m - abs(f[i]));
    }
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}
