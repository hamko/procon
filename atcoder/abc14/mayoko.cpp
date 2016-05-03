#include <bits/stdc++.h>
using namespace std;

class Tree {
    public:
        Tree(int V, int root) : V(V), root(root) {
            T.resize(V);
            for (int i = 0; i < MAXLOGV; i++) parent[i].resize(V);
            depth.resize(V);
        }
        // 有向辺の構築
        void uniteDirected(int u, int v) {
            T[u].push_back(v);
        }
        // 無向辺の構築
        void uniteUndirected(int u, int v) {
            T[u].push_back(v);
            T[v].push_back(u);
        }
        // rootからの深さと親を確認。
        // これも呼ばないとlcaが求められない
        void init() {
            dfs(root, -1, 0);
            for (int k = 0; k+1 < MAXLOGV; k++) { // 2^k代祖先を計算
                for (int v = 0; v < V; v++) {
                    if (parent[k][v] < 0) parent[k+1][v] = -1; // 2^k代の親が根を超えてるなら、2^(k+1)代の親ももちろん根を超えている
                    else parent[k+1][v] = parent[k][parent[k][v]]; // 2^(k+1)代の親は、2^k代の親の2^k代の親。
                }
            }
        }
        // 頂点u, vの最小共通先祖
        int lca(int u, int v) const {
            if (depth[u] > depth[v]) swap(u, v); // uのほうが浅くなるように
            for (int k = 0; k < MAXLOGV; k++) {  // vをuと同じ深さまで遡る
                if ((depth[v] - depth[u])>>k & 1) {
                    v = parent[k][v];
                }
            }
            if (u == v) return u;
            for (int k = MAXLOGV-1; k >= 0; k--) { // 行き過ぎないギリギリで遡る
                if (parent[k][u] == parent[k][v]) // 行き過ぎ
                    continue; 
                u = parent[k][u];
                v = parent[k][v];
            }
            return parent[0][u];
        }
        // uとvの距離を求める
        // 距離はエッジの重みではなく、遷移回数で定義
        int dist(int u, int v) const {
            int p = lca(u, v);
            return (depth[u]-depth[p]) + (depth[v]-depth[p]);
        }
        // 辿って親と深さを確認するだけ
        void dfs(int v, int p, int d) {
            parent[0][v] = p;
            depth[v] = d;
            for (int next : T[v]) {
                if (next != p) dfs(next, v, d+1);
            }
        }
        static const int MAXLOGV = 25;
        vector<vector<int> > T; // T[i][j]が存在: i->jの辺が存在
        int V; // 頂点の数, V<2^MAXLOGV
        int root; // 根ノードの番号

        vector<int> parent[MAXLOGV]; // parent[i][j]: jのi^2番目の親。j=0で直近の親。
        vector<int> depth; // depth[i]: 頂点iの根からの深さ, 根が0
};

int main() {
    int n; cin >> n;
    Tree tree(n, 0/*root*/);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        tree.uniteUndirected(x, y);
    }
    tree.init();
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        cout << tree.dist(a, b) + 1 << endl;
    }
    return 0;
}
