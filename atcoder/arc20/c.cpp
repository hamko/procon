#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n), l(n); rep(i, n) cin >> a[i] >> l[i];
    ll b; cin >> b;

    vll digit(n);
    rep(i, n) {
        ll tmp = a[i], dig = 0; 
        while (tmp) {tmp /= 10; dig++;}
        digit[i] = dig;
    }

    ll cycle = 60;

    vll tens(cycle); // 10^(2^i) mod b
    tens[0] = 10 % b; // 10^1
    rep(i, cycle-1) 
       (tens[i+1] = tens[i] * tens[i]) %= b;
    auto modpow10 = [&](ll dig){
        ll ret = 1;
        rep(i, cycle) 
            if (dig & (1ll << i))
                (ret *= tens[i]) %= b;
        return ret;
    };

    vector<vll> d(n, vll(cycle, 0)); // a[i]を2^j回繰り返した時のmod b
    rep(i, n) d[i][0] = a[i] % b;
    rep(i, n) rep(j, cycle-1) { 
        (d[i][j+1] += d[i][j] * modpow10(digit[i] * (1ll << j))) %= b;
        (d[i][j+1] += d[i][j]) %= b;;
    }

    ll ret = 0;
    rep(i, n) {
        ll mask = l[i];
        rep(j, cycle) {
            if (!(mask & (1ll << j)))
                continue;
            (ret *= modpow10(digit[i] * (1ll << j))) %= b;
            (ret += d[i][j]) %= b;
        }
    }
    cout << ret % b << endl;

    return 0;
}
