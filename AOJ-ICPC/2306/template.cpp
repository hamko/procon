#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; 
static const long long INF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    vvll g(n, vll(n)); rep(i, n) g[i][i] = INF;

    rep(i, m) {
        ll u, v, f; cin >> u >> v >> f; u--, v--;
        g[u][v] = g[v][u] = f;
    }

    vll vs;
    function<ll(vll&)> f = [&](vll& vs) {
        ll ret = 0;
        rep(i, vs.size()) {
            ll min_f = INF;
            rep(j, vs.size()) 
                chmin(min_f, g[vs[i]][vs[j]]);
            ret += min_f != INF ? min_f : 0;
        }
        repi(i, vs.size() ? vs.back()+1 : 0, n) {
            for (auto v : vs) if (!g[v][i]) goto next;
            vs.pb(i);
            chmax(ret, f(vs));
            vs.pop_back();
            next:;
        }
        return ret;
    };
    cout << f(vs) << endl;
    return 0;
}
