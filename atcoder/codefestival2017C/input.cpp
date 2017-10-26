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

    ll x = 0, y = 0;
    if (argc >= 2) 
        x = atoi(argv[1]);
    if (argc >= 3) 
        y = atoi(argv[2]);

    ll n = x;
    string s; 
    rep(i, n) {
        s += 'a' + randr(0, y-1);
    }
    cout << s << endl;

    return 0;
}

