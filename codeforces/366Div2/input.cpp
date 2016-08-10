#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(void)
{
    ll n = 300000;
    cout << n << " " << n+1 << endl;
    rep(i, n) {
        cout << 1 << " " << 1 << " ";
    }
    cout << 3 << " " << 300000 << " ";

    return 0;
}

