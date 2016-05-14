#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> m(n); rep(i, n) cin >> m[i];

    int ret = 0;
    rep(i, n) {
        int lastj = -1;
        rep(j, n) 
            if (m[i][j] == '.') 
                lastj = j;
        if (!~lastj) continue;

        ret++;
        rep(j, lastj+1) 
            m[i][j] = 'o';
        if (i != n-1) 
            for (int j = lastj; j < n; j++) 
                m[i+1][j] = 'o';
    }
    cout << ret << endl;
    return 0;
}
