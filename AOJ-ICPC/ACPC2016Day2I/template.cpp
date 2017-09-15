#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;

int main(void) {
    ll n; cin >> n;
    vvll g(n);
    rep(i, n-1) {
        ll u, v; cin >> u >> v; u--, v--;
        g[u].pb(v), g[v].pb(u);
    }

    vll d(n);
    function<ll(ll, ll)> f = [&](ll v, ll p) {
        for (auto u : g[v]) if (u != p) chmax(d[v], f(u, v));
        return d[v] + 1;
    };
    f(0, -1);

    vll ret(n);
    // dpar[v][p] = pのvを除く部分木の中で最大のd
    function<void(ll, ll, ll)> ff = [&](ll v, ll p, ll dpar) {
        vector<P> children;
        for (auto u : g[v]) children.emplace_back(u == p ? dpar + 1 : d[u] + 1, u);
        sort(all(children)); reverse(all(children));

        ret[v] = children[0].fi;

        for (auto u : g[v]) if (u != p) ff(u, v, children[children[0].se==u].fi);
    };
    ff(0, -1, 0);

    rep(i, n) cout << 2 * (n - 1) - ret[i] << endl;


    return 0;
}
