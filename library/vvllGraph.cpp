// SCC
// O(n+m)
vvll g;

vll order;
ll order_counter = 0;
void scc_for(ll v) {
    if (order[v] >= 0) return;
    order[v] = INF;
    for (auto u : g[v]) 
        scc_for(u);
    order[v] = order_counter++;
}
vvll scc_set;
vector<bool> flag;
void scc_rev(ll i, ll v) {
    if (flag[v]) return;
    flag[v] = 1;
    scc_set[i].pb(v);
    for (auto u : gr[v]) 
        scc_rev(i, u);
}
vvll getSCC(void) {
    ll n = g.size();

    order.resize(n, -1);
    order_counter = 0;
    scc_set.clear();
    flag.resize(n);

    rep(v, g.size()) 
        scc_for(v);
    vll order_rev(n);
    rep(i, n) 
        order_rev[n-1-order[i]] = i;
    rep(i, g.size()) {
        ll v = order_rev[i];
        if (!flag[v]) {
            scc_set.pb({});
            scc_rev(scc_set.size()-1, v);
        }
    }
    return scc_set;
}

int main(void) {
    ll n, m; cin >> n >> m;
    g.resize(n), gr.resize(n);
    rep(i, m) {
        ll v, u; cin >> v >> u;
        g [v].pb(u);
        gr[u].pb(v);
    }
    vvll scc = getSCC();
    cout << scc << endl;

    return 0;
}


