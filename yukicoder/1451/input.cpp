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
//    int seed; cin >> seed; srand(seed);

    ll m = 1000000;
    cin >> m;
    cout << m << endl;
    rep(i, m) {
        int a = 0, b = 0;
        double t;
        while (a == b && a == 0) {
            a = randr(0, 10);
            b = randr(0, 10);
            t = randrf(0.1, 10);
        }
        cout << a << " " << b << " " << fixed << setprecision(4) << t << endl;
    }

    return 0;
}

