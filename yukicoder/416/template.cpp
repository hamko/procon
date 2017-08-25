#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define ZERO(a) memset(a,0,sizeof(a))

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

size_t random_seed; 
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); srand((unsigned int)time(NULL)); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ, O(A^-1)
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1, O(A^-1)
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る, O(A^-1)
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
};

#define MAXN 100010
ll ret[MAXN];

vvll g;
void dfs(ll v, ll c) {
    if (ret[v] != -2) return;
    ret[v] = c;
    for (auto x : g[v]) 
        dfs(x, c);
}

int main(void) {
    ll n, m, q; cin >> n >> m >> q;
    g=vvll(n);
    rep(i, MAXN) ret[i] = -2;
    
    vvll g_all(n);
    set<P> edges;
    rep(i, m) {
        ll u, v; cin>>u>>v;u--,v--;
        g_all[u].pb(v), g_all[v].pb(u), edges.insert(P(u, v));
    }
    vll c(q),d(q);
    rep(i, q) {
        cin >> c[i] >> d[i]; c[i]--, d[i]--;
        edges.erase(P(c[i], d[i]));
    }
    reverse(all(c)), reverse(all(d));

    for (auto x : edges) 
        g[x.fi].pb(x.se), g[x.se].pb(x.fi);

    {
        UnionFind uf(n);
        rep(i, n) for (auto u : g_all[i]) uf.unite(i, u);
        rep(i, n) if (uf.find(0, i) == 0) ret[i] = 0;
    }

    UnionFind uf(n);
    for (auto x : edges) uf.unite(x.fi, x.se);
    rep(i, n) if (uf.find(0, i) == 1) 
        ret[i] = -1;

    rep(i, q) {
        ll u = c[i], v = d[i];
        if (uf.find(0, u) ^ uf.find(0, v)) {
            if (!uf.find(0, u) && uf.find(0, v)) 
                swap(u, v);
            dfs(v, q-i);
        }
        uf.unite(u, v), g[v].pb(u), g[u].pb(v);
    }

    repi(i, 1, n) 
        cout << ret[i] << endl;

    return 0;
}
