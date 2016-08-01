#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(void)
{
    int seed; cin >> seed; srand(seed);

    ll n = 100000;
    ll q = 100000;
    ll m = n-1; 
    cout << n << " " << m << endl;
    rep(i, m) {
        cout << i + 1 << " " << i + 2 << endl;
    }
    cout << q << endl;
    rep(i, q) {
        cout << (rand() % n + 1) << " " << (rand() % n + 1) << " " << (rand() % n + 1) << endl;
    }

    return 0;
}

