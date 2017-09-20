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
    struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec);

    ll n = 300000, m = 300000;
    cout << n << " " << m << endl;
    rep(i, n) {
        cout << randr(-1, 1) << endl;
    }

    rep(i, m) {
        ll u = randr(1, n-1);
        ll v = randr(u+1, n);
        cout << u << " " << v << endl;
    }

    return 0;
}

