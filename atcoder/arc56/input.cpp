#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

using P = pair<ll, ll>;
ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(void)
{
    ll n = 10;
    ll m = 10;
    ll s = n / 2;
    cout << n << " " << m << " " << s << endl;
    rep(i, m) {
        ll u = 0, v = 0;
        while (u == v) {
            u = randr(1, n), v = randr(1, n);
        }
        cout << u << " " << v << endl;
    }

    return 0;
}

