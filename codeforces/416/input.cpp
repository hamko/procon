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
    ll n = 10000;
    ll m = 10000;
    cout << n << " " << m << endl;
    rep(i, n)
        cout << n-i << " " ;
    cout << endl;
    rep(i, m) {
        cout << 1 << " " << 10000 << " " << 3 << endl;;
    }

    return 0;
}

