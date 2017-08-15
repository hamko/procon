#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long; 
static const long long mo = 1e6+3;

ll modpow(ll a, ll n = mo-2) {
    ll r=1;
    while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
    return r;
}

int main(void) {
    ll n; cin >> n; ll k; cin >> k;

    if ((k - 1) >> min(63ll, n)) {
        cout << "1 1" << endl;
        return 0;
    }

    ll p2 = modpow(2, n);
    ll inv2 = modpow(2);

    ll q = p2; q = modpow(q, k); // 2^nk
    ll p = 1;
    rep(i, min(k, mo)) 
        (p *= p2 - i) %= mo;

    ll counter = n;
    for (ll i = 2; i <= k; i *= 2) 
        counter += (k - 1) / i;

    cout << (((q - p) * modpow(inv2, counter)) % mo + mo) % mo << " " << ((q * modpow(inv2, counter)) % mo + mo) % mo << endl;

    return 0;
}
