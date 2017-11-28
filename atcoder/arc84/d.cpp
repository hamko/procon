#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;

#define INF 1e18

int main(void) {
    ll k; cin >> k;
    vvll g[2] = {vvll(k), vvll(k)};
    rep(i, k) {
        g[1][i].push_back((i+1)%k);
        g[0][i].push_back((i*10)%k);
    }
    vll q = {1}, d(k, INF);
    ll step = 0;
    while (q.size()) {
        vll q_next, q0;
        rep(i, q.size()) if (d[q[i]] == INF) {
            ll x = q[i];
            d[x] = step;
            q_next.push_back(g[1][x][0]);
            if (d[g[0][x][0]] == INF) {
                q0.push_back(g[0][x][0]);
                d[g[0][x][0]] = step;
            }
        }
        while (q0.size()) {
            ll x = q0.back(); q0.pop_back();
            q_next.push_back(g[1][x][0]);
            if (d[g[0][x][0]] == INF) {
                q0.push_back(g[0][x][0]);
                d[g[0][x][0]] = step;
            }
        }
        swap(q, q_next);
        step++;
    }
    cout << d[0] + 1 << endl;

    return 0;
}
