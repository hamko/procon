#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(void)
{
    int seed; cin >> seed; srand(seed);

    ll n = 10;
    ll m = 10;
    ll q = 50;
    cout << n << " " << m << endl;
    rep(i, m) {
        cout << randr(1, n) << " " << randrf(-1, 1) << " " << randrf(-1, 1) << endl;
    }

    return 0;
}

