#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;

int main(void) {
    ll p, q; cin >> p >> q;
    ll g = __gcd(p, q); p /= g, q /= g;
    ll ret = 1;
    set<ll> primes;
    repi(i, 2, 40000) { 
        for (auto p : primes) 
            if (i % p == 0)
                goto SKIP;
        if (q % i == 0) ret *= i;
        primes.insert(i);
        while (!(q % i)) 
            q /= i; 
        SKIP:;
    }
    if (q > 1)
        ret *= q;
    cout << ret << endl;

    return 0;
}
