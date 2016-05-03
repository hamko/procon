#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define print(v) for(auto x:(v)){cout<<x<<" ";}cout<<endl;
#define printi(b,e) for(auto x=(b); x!=(e); x++)cout<<*x<<" ";cout<<endl;
#define printa(a,n) rep(i,n)cout<<a[i]<<" ";cout<<endl;
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;


#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef int Weight;

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

void addDirected(Graph& g, int src, int dst, Weight weight) { g[src].push_back(Edge(src, dst, weight)); }
void addUndirected(Graph& g, int src, int dst, Weight weight) { g[src].push_back(Edge(src, dst, weight)); g[dst].push_back(Edge(src, dst, weight)); }
void addDirected(Graph& g, int src, int dst) { addDirected(g, src, dst, 0); }
void addUndirected(Graph& g, int src, int dst) { addUndirected(g, src, dst, 0); }

// rootからの連結頂点をrootに塗る
// connectedはサイズ頂点数, -1で初期化。
// O(V)
void paintConnected(const Graph &g, int root, vector<int>& connected) {
    int n = g.size();
    if (!connected.size()) connected = vector<int>(n, -1);
    if (n != connected.size()) connected.resize(n);

    queue<Edge> Q;
    Q.push( Edge(-1, root, 0) );
    while (!Q.empty()) {
        Edge e = Q.front(); Q.pop();
        if (connected[e.dst] != -1) 
            continue;
        connected[e.dst] = root;
        for(auto f : g[e.dst]) 
            if (!connected[f.dst]) 
                Q.push(f);
    }
}


int main(void) {
    int n, k; cin >> n >> k;
    Graph g;
    rep(i, k) {
        int u, v; cin >> u >> v;
        addUndirected(g, u, v);
    }
    vector<int> connected(n, -1);
    int ret = 0;
    rep(i, k) {
        if (connected[i] == -1) {
            paintConnected(g, i, connected);
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}
