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
//    struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec);
    int seed; cin >> seed; srand(seed);

    ll n = randr(1, (ll)10);
    ll m = 9;
    cout << n << " " << m << endl;
    rep(i, m) {
        cout << randr(1, n) << " " << randrf(-1, 1) << " " << randrf(-1, 1) << endl;
    }

    return 0;
}

