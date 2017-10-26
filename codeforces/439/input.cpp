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

    ll n = randr(1, (ll)10);
    cout << n << endl;
    vll a(n);
    rep(i, n) a[i] = randr(1, 100);
    cout << endl;
    vll b(n);
    rep(i, n) b[i] = randr(1, 100);
    cout << endl;
    unordered_map<ll, ll> memo;
    rep(i, n) {
        memo[a[i]]++;
        memo[b[i]]++;
    }
    for (auto x : memo) {
        if (x.second > 1) {
            cout << "INVALID"<< endl;
            return 1;
        }
    }
    rep(i, n) { cout << a[i] << " "; } cout<<endl;
    rep(i, n) { cout << b[i] << " "; } cout<<endl;

    return 0;
}

