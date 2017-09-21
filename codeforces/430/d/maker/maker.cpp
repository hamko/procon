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

    ll id = 0;
    if (argc >= 2) 
        id = atoi(argv[1]);

    if (id < 5) {
        ll n, m, nm, mm;
        n = 3e5, m = 3e5;

        cout << n << " " << m << endl;
        rep(i, n) {
            cout << i << " ";
        }
        cout << endl;
        rep(i, m) {
            cout << i << endl;
        }
    } else if (id < 10) {
        ll n, m, nm, mm;
        n = 3e5, m = 3e5;

        cout << n << " " << m << endl;
        rep(i, n) {
            cout << randr(0, 3e5) << endl;
        }
        cout << endl;
        rep(i, m) {
            cout << randr(0, 3e5) << endl;
        }
    } else if (id < 50) {
        ll n, m, nm, mm;
        n = 1e3, m = 1e3;

        cout << n << " " << m << endl;
        rep(i, n) {
            cout << randr(0, 1e3) << endl;
        }
        cout << endl;
        rep(i, m) {
            cout << randr(0, 1e3) << endl;
        }
    } else {
        assert(1);
    }

    return 0;
}

