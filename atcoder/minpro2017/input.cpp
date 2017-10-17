#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i > j) return i; else return (ll)rand() % (j - i + 1) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(int argc, char** argv)
{
    struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec);

    ll x = 0;
    if (argc >= 2) 
        x = atoi(argv[1]);

    ll n = x;
    ll m = 3;
    ll q = x;
    cout << n << " " << m << " " << q << endl;
    rep(i, n) {
        cout << randr(1, 1e9) << " ";
    }
    cout << endl;

#if 0
    rep(i, q) {
        ll l = randr(1, n);
        ll r = randr(1, n);
        if (l > r) swap(l, r);
        cout <<l<<" "<<r << " " << randr(1, 1e9) <<endl;
    }
#else
    rep(i, q) {
        ll l = 2;
        ll r = n-1;
        cout <<l<<" "<<r << " " << randr(1, 1e9) <<endl;
    }
#endif

    return 0;
}

