#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long;
using P = pair<ll, ll>;

int main(void) {
    ll h, w; cin >> h >> w; vector<string> b(h); 
    assert(h >= 2);
    assert(w >= 2);
    assert(h <= 100);
    assert(w <= 100);
    vector<P> star;
    rep(i, h) {
        cin >> b[i];
        assert(b[i].size() == w);
        rep(j, w) if (b[i][j] == '*') star.push_back(P(i, j));
    }
    assert(star.size() == 2);
    assert(b.size() == h);
    ((star[0].first == star[1].first) ? b[(star[0].first+1)%h][star[0].second] : b[star[0].first][(star[0].second+1)%w]) = '*';
    rep(i, h) cout << b[i] << endl;

    return 0;
}
