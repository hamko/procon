#include <bits/stdc++.h>
using namespace std;

template<class T>
struct RMQ {
    vector<vector<T>> dat;
    void build(vector<T> a) {
        int n = 32 - __builtin_clz(a.size());
        dat.resize(n, vector<T>(a.size()));
        dat[0] = a;
        for (int i = 0, t = 1; i < n - 1; i++, t <<= 1)
            for (int j = 0; j + t < a.size(); j++)
                dat[i + 1][j] = min(dat[i][j], dat[i][j + t]);
    }
    T query(int l, int r) {
        int k = 31 - __builtin_clz(r - l);
        return min(dat[k][l], dat[k][r - (1 << k)]);
    }
};

struct LCA {
    vector<vector<int>> g;
    vector<int> depth;
    vector<pair<int, int>> euler;
    RMQ<pair<int, int>> rmq;
    vector<int> ord;
    LCA(int n) : g(n), depth(n), ord(n) {}
    void add(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build() {
        dfs(0, -1);
        rmq.build(euler);
    }
    int query(int u, int v) {
        int l, r;
        tie(l, r) = minmax(ord[u], ord[v]);
        return rmq.query(l, r + 1).second;
    }
    void dfs(int curr, int prev) {
        ord[curr] = euler.size();
        euler.emplace_back(depth[curr], curr);
        for (int next : g[curr]) if (next != prev) {
            depth[next] = depth[curr] + 1;
            dfs(next, curr);
            euler.emplace_back(depth[curr], curr);
        }
    }
};

long long input() { long long x; scanf("%lld", &x); return x; }

int main() {
    int n = input();
    LCA lca(n);
    for (int i = 0; i < n - 1; i++) lca.add(input() - 1, input() - 1);
    lca.build();

    int Q = input();
    while (Q--) {
        int a = input() - 1;
        int b = input() - 1;
        int l = lca.query(a, b);
        int ans = lca.depth[a] + lca.depth[b] - 2 * lca.depth[l] + 1;
        printf("%d\n", ans);
    }
}
