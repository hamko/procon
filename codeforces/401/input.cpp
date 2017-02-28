#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i > j) return i; else return (ll)rand() % (j - i + 1) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(void)
{

    ll n = 400;
    ll m = 220;
    cout << n << " " << m << endl;
    rep(i, n) {
        rep(i, m) {
            cout << randr(1, 100) << " ";
        }
        cout << endl;
    }
    ll k = 100000;
    cout << k << endl;
    rep(i, k) {
        ll l = randr(1, n), r = randr(1, n);
        cout << min(l, r) << " " << max(l, r) << endl;
    }

    return 0;
}

