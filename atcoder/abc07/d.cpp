#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;

int main(void) {
    ll a, b; cin >> a >> b;
    ll dp[20/*d,pos*/][2/*i,less*/][2/*j,more*/][2/*k,has4*/][2/*h,has9*/] = {};
    vi l, m;
    while (b) {
        l.push_back(b % 10), m.push_back(a % 10); 
        b /= 10, a /= 10;
    }
    reverse(all(m)); reverse(all(l)); 

    dp[0][0][0][0][0] = 1;
    rep(d, m.size()) rep(i, 2) rep(j, 2) rep(k, 2) rep(h, 2) {
        if (!dp[d][i][j][k][h]) continue;
        rep(n, 10) {
            if (!i && l[d] < n) continue; 
            if (!j && m[d] > n) continue; 
            dp[d+1][i||n<l[d]][j||n>m[d]][k||n==4][h||n==9] += dp[d][i][j][k][h];
        }
    }

    ll count = 0;
    int d = m.size(); rep(i, 2) rep(j, 2) rep(k, 2) rep(h, 2) {
        if (!k && !h) continue;
        count += dp[d][i][j][k][h];
    }
    cout << count << endl;

    return 0;
}
