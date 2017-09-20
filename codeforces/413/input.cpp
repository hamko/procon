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

    ll a = randr(1, (ll)1e5) , b = randr(1, 1e5), h = randr(1, 1e2), w = randr(1, 1e2);
    ll n = randr(1, (ll)10);
    cout << a << " " << b << " " << h << " " << w << " " << n << endl;
    rep(i, n) {
        cout << randr(2, 3) << " ";
    }
    cout << endl;

    return 0;
}

