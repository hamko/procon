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

    ll h = x;
    ll w = x;
    cout << h << " " << w << endl;
    vector<string> s(h, string('#', w));
    while (1) {
        rep(i, h) {
            rep(j, w) {
                char tmp = (rand()%2 == 0 ? '#':'.');
                s[i][j] = tmp;
            }
        }
        if (s[0][0] != '#' && s[h-1][w-1] != '#') {
            rep(i, h) {
                cout << s[i] << endl;;
            }
            break;
        }
    }


    return 0;
}

