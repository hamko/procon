#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

using ll = long long;
int main(void) {
    struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec);
    ll h, w; cin >> h >> w; vector<string> b(h); rep(i, h) cin >> b[i];
    ll ah, aw;
    while (1) {
        ah = rand() % h;
        aw = rand() % w;
        if (b[ah][aw] == '-') break;
    }
    b[ah][aw] = '*';
        
    rep(i, h) cout << b[i] << endl;

    return 0;
}
