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
    ll n = 100;
    ll k = 100;
    ll l = 100;
    cin >> n >> k >> l;

    cout << n << " " << k << " " << l << endl;
    rep(i, k) {
        cout << randr(1, n) << " " << randr(1, n) << endl;
    }
    rep(i, l) {
        cout << randr(1, n) << " " << randr(1, n) << endl;
    }

    return 0;
}

