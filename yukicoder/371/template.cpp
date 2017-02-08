#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long; using vll = vector<ll>; 

int main(void) {
    ll l, h; cin >> l >> h;
    vll primes; 
    vector<bool> is_prime(1e5+10, 1); 
    is_prime[0] = is_prime[1] = 0;
    for (ll p = 2; p < is_prime.size(); p++) if (is_prime[p]) {
        primes.push_back(p);
        for (ll x = p; x < is_prime.size(); x += p) 
            is_prime[x] = 0;
    }
    reverse(primes.begin(), primes.end());

    rep(pi, primes.size()) {
        ll p = primes[pi];
        for (ll x = h / p * p; x >= l; x -= p) 
            if (all_of(primes.begin() + pi + 1, primes.end(), [&](ll y){return x % y;})) {
            // xがp以下の素数を持たない
                cout << x << endl;
                return 0;
            }
    }

    return 0;
}
