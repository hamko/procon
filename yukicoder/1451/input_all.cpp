#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)

ll randr(ll i, ll j) { if (i > j) return i; else return (ll)rand() % (j - i + 1) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(void)
{
    ll m = 1000000;
    ll cycle = 0;
    cout << m << endl;
    rep(a, 11) rep(b, 11) repi(t, 1000, 100001) {
        cout << 10 - a << " " << 10 - b << " " << fixed << setprecision(4) << (double)t/10000.0 << endl;
        cycle++;
        if (cycle == m) goto END;
    }

END:
    return 0;
}

