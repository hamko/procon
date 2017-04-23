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
    string s(n, ' ');
    rep(i, n) {
        ll r = rand() % 3;
        if (r == 0) {
            s[i] = '(';
        } else if (r == 1) {
            s[i] = ')';
        } else {
            s[i] = '?';
        }
    }
    cout << n << endl;
    cout << s << endl;
    ll q = 100000;
    cout << q << endl;

    rep(i, q) {
        ll l = randr(1, n);
        ll r = randr(1, n);
        if (l > r) swap(l, r);
        cout << l << " " << r << endl;
    }

    return 0;
}

