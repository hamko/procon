#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef int Weight;
const Weight INF = 1e9;

struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;


struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};


// 最小共通先祖 Tarjan 
// O(E A(V))
struct Query {
    int u, v, w;
    Query(int u, int v) : u(u), v(v), w(-1) { }
};
void visitTarjan(const Graph &g, int u, int w,
        vector<Query> &qs, vector<int> &color,
        vector<int> &ancestor, UnionFind &uf) {
    ancestor[ uf.root(u) ] = u;
    FOR(e, g[u]) if (e->dst != w) {
        visitTarjan(g, e->dst, u, qs, color, ancestor, uf);
        uf.unionSet( e->src, e->dst );
        ancestor[ uf.root(u) ] = u;
    }
    color[u] = 1;
    FOR(q, qs) {
        int w = (q->v == u ? q->u : q->u == u ? q->v : -1);
        if (w >= 0 && color[w]) q->w = ancestor[ uf.root(w) ];
    }
}
void leastCommonAncestor(const Graph &g, int r, vector<Query> &qs) {
    UnionFind uf(g.size());
    vector<int> color(g.size()), ancestor(g.size());
    visitTarjan(g, r, -1, qs, color, ancestor, uf);
}


#define rep(i,n) for(int i = 0; i < n; i++)
#define print(v) for(auto x:(v)){cout<<x<<" ";}cout<<endl;
#define printi(b,e) for(auto x=(b); x!=(e); x++)cout<<*x<<" ";cout<<endl;
#define printa(a,n) rep(i,n)cout<<a[i]<<" ";cout<<endl;
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

#define MAX_N 100005

Graph g;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int root;
    g = Graph(n, Edges());
    vector<int> counter(n, 0);
    rep(i, n-1) {
        int x, y; cin >> x >> y; x--; y--;
        counter[x]++; counter[y]++;
        g[x].push_back(Edge(x, y, 1)); g[y].push_back(Edge(y, x, 1));
    }
    rep(i, n) {
        if (counter[i] <= 2) {
            root = i;
            break;
        }
    }
    cout << root << "#root" << endl;

    vector<Weight> h(n, -1); h[root] = 0;
    queue<int> Q; Q.push(root);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        Weight wsum = h[v];
        rep(i, g[v].size()) {
            int next = g[v][i].dst;
            if (h[next] != -1)
                continue;
            h[next] = h[v] + g[v][i].weight;
//            cout << v << " " << next << endl;
            Q.push(next);
        }
    }
//    print(h);
    cout << "Depth" << endl;
    
    int q; cin >> q;
    vector<Query> qs;
    rep(i, q) {
        if (i % 1000 == 0) cout << i << endl;
        int a, b; cin >> a >> b; a--; b--;
        qs.push_back(Query(a, b));
    }
    cout << "Prepare Query" << endl;
    leastCommonAncestor(g, root, qs);
    cout << "LCA" << endl;
    for(auto x : qs) {
        cout << h[x.u] + h[x.v] - 2 * h[x.w] + 1 << endl;
    }
    return 0;
}
