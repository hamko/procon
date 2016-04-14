#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define MAX_N 100005

int main(void) {
    int N; cin >> N;

    int c[MAX_N][3] = {};
    int r[MAX_N] = {}, h[MAX_N] = {};
    rep(i, N) {
        cin >> r[i] >> h[i]; h[i]--;
        c[r[i]][h[i]]++;
    }

    int s[MAX_N] = {};
    rep(i, MAX_N) rep(j, 3)
        s[i] += c[i][j];
    rep(i, MAX_N-1) 
        s[i+1] += s[i];

    rep(i, N) {
        int win, draw;
        win = s[r[i]-1] + c[r[i]][(h[i]+1)%3];
        draw = c[r[i]][h[i]] - 1;
        cout << win << " " << N - 1 - draw - win << " " << draw << endl;
    }

    return 0;
}
