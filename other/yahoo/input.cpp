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

    int seed; cin >> seed; srand(seed);

    ll n =randr(1, (ll)10); 
    ll k = randr(1, (ll)n);
    cout << n << " " << k << endl;
    rep(i, k) {
        cout << i + 1 << " " ;
    }
    cout << endl;
    rep(i, n) {
        string s; 
        rep(i, randr(1, 4)) 
            s += 'a' + rand() % 26;
        cout << s << endl;
    }

    return 0;
}

