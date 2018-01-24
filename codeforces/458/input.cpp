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

    ll n = 5e5;
    if (argc >= 2) 
        n = atoi(argv[1]);

    ll q = 4e5;
    cout << n << endl;
    rep(i, n) {
        cout << randr(1, 1e9) << " ";
    }
    cout << endl;
    cout << q << endl;
    rep(i, q) {
        ll t = randr(1, 2);
        if (t) {
            /*
            ll l = randr(1, n);
            ll r = randr(l, n);
            */
            ll l = 1;
            ll r = n;
            cout << 1 << " " << l << " " << r << " " << randr(1, 1e9) << endl;
        } else {
            cout << 2 << " " << randr(1, n) << " " << randr(1, 1e9) << endl;
        }
    }

    return 0;
}

