#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

using ll = long long;
using P = pair<ll, ll>;
int main(void) {
    ll h, w; cin >> h >> w;
    vector<string> b(h);

    vector<P> star;
    rep(i, h) {
        cin >> b[i];
        assert(b[i].size() == w);
        rep(j, w) if (b[i][j] == '*') star.push_back(P(i, j));
    }

    while (1) {
        ll ah = rand() % h;
        ll aw = rand() % w;
        star.push_back(P(ah, aw));
        if ((star[1].first - star[0].first) * (star[2].second - star[0].second) - (star[2].first - star[0].first) * (star[2].second - star[0].second)) {
            b[ah][aw] = '*';
            rep(i, h) cout << b[i] << endl;
            return 0;
        }
        star.pop_back();
    }

    return 0;
}
