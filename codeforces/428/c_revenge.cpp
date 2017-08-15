#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
#define doubleout fixed << setprecision(40) 

vvll g;

double ret = 0;
void dfs(ll v, ll p, double prob, ll depth) {
    if (g[v].size() == 1) 
        ret += prob * depth;
    else 
        for (auto u : g[v]) if (u != p) 
            dfs(u, v, prob / (g[v].size() - 1) , depth+1);
}

int main(void) {
    ll n; cin >> n;
    g = vvll(n);
    rep(i, n - 1){
        ll u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (auto x : g[0]) 
        dfs(x, 0, 1.0 / g[0].size(), 1);

    cout << doubleout << ret << endl;

    return 0;
}
