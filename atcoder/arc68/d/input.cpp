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

    ll n = 10;
    if (argc >= 2) 
        n = atoi(argv[1]);
    ll m = 10;
    if (argc >= 3)
        m = atoi(argv[2]);

    cout << n << " " << m << endl;
    rep(i, n) {
        ll l = randr(1, m);
        ll r = randr(l, m);
        cout << l << " " << r << endl;
    }

    return 0;
}

