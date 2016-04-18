#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// gcdは関数__gcdを使いましょう。ll対応している。

// a^b (MOD mod), bに対してO(log n)
// condition: mod^mod<LLONG_MAX
ll modpow(ll a, ll b, ll mod) {
    ll ret = 1; a %= mod;
    for (; b > 0; a = a * a % mod, b /= 2) if (b & 1) ret = ret * a % mod;
    return ret;
}

// a^0 + ... + a^(b-1) (MOD mod), bに対してO((log n)^2)
// condition: mod^mod<LLONG_MAX
ll modpowsum(ll a, ll b, ll mod) {
    if (b == 0) return 0;
    if (b % 2 == 1) return (modpowsum(a, b - 1, mod) * a + 1) % mod;
    ll result = modpowsum(a, b / 2, mod) % mod;
    return (result * modpow(a, b / 2, mod) + result) % mod;
}

int main(void) {
    cout << __gcd(12, 18) << endl;
    cout << modpow(2, 4, 3) << endl;
    cout << modpow(3333333333, 1e5, 3) << endl;
    cout << modpowsum(2, 4, 3) << endl;

    long long   n = 8e18;
    printf("long long x 1= %Ld\n", n);
    printf("long long x 2 = %Ld\n", n*2);
    long double m = n;
    printf("long double x 1= %Lf\n", m);
    printf("long double x 2 = %Lf\n", m*2);

    return 0;
}
