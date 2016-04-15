#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// gcdは関数__gcdを使いましょう。ll対応している。

// a^b (MOD mod)
// bに対してO(log n)
ll modpow(ll a, ll b, ll mod) {
    ll ret = 1;
    for (; b > 0; a = a * a % mod, b /= 2) if (b & 1) ret = ret * a % mod;
    return ret;
}

// a^0 + ... + a^(b-1) (MOD mod)
// bに対してO((log n)^2)
ll modpowsum(ll a, ll b, ll mod) {
    if (b == 0) return 0;
    if (b % 2 == 1) return (modpowsum(a, b - 1, mod) * a + 1) % mod;
    ll result = modpowsum(a, b / 2, mod);
    return (result * modpow(a, b / 2, mod) + result) % mod;
}

int main(void) {
    cout << __gcd(12, 18) << endl;
    cout << modpow(2, 4, 3) << endl;
    cout << modpowsum(2, 4, 3) << endl;

    return 0;
}
