#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

int main(void) {
    ll h, w; cin >> h >> w; vector<string> b(h); 
    
    vector<P> star;
    rep(i, h) {
        cin >> b[i];
        rep(j, w) if (b[i][j] == '*') star.pb(P(i, j));
    }
    ll reth, retw, m = 0;
    rep(i, h) rep(j, w) if (!(i == star[0].fi && j == star[0].se) && !(i == star[1].fi && j == star[1].se)) { 
        ll tmp = abs(star[0].fi - i) + abs(star[0].se - j) + abs(star[1].fi - i) + abs(star[1].se - j);
        if (m < tmp) m = tmp, reth = i, retw = j;
    }
    b[reth][retw] = '*';
    rep(i, h) cout << b[i] << endl;

    return 0;
}
