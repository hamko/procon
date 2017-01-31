#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(void)
{
    ll n = 10000;
    cout << 2*n+n/2 << endl;
    vector<ll> a(n);
    rep(i, n) {
        a[i] = randr(1, 1e9);
        cout << '+' << " " << a[i] << endl;
    }
    rep(i, n) {
        if (i % 2)
            cout << '-' << " " << a[i] << endl;
    }
    rep(i, n) {
        cout << '?' << " " << randr(1, 1e9) << endl;
    }

    return 0;
}

