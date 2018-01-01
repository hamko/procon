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
   ll x = 100;
    if (argc >= 2) 
        x = atoi(argv[1]);



    ll n = randr(1, x);
    ll m = randr(1, x);;
    cout << n << " " << m << endl;
    vector<pair<ll, ll>> ab;
    rep(i, n) {
        ll a = randr(0, m);
        ab.push_back(pair<ll, ll>(a, randr(a, m)));
    }
    sort(ab.begin(), ab.end());
    rep(i, n) {
        cout << ab[i].first << " " << ab[i].second <<endl;
    }

    return 0;
}

