#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-14;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

#define MAX_N 105

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

void addDirected(Graph& g, int src, int dst, Weight weight) { g[src].push_back(Edge(src, dst, weight)); }
void addUndirected(Graph& g, int src, int dst, Weight weight) { g[src].push_back(Edge(src, dst, weight)); g[dst].push_back(Edge(dst, src, weight)); }
void addDirected(Graph& g, int src, int dst) { addDirected(g, src, dst, 1); }
void addUndirected(Graph& g, int src, int dst) { addUndirected(g, src, dst, 1); }

void visitStronglyConnectedComponents(const Graph &g, int v, vector< vector<int> >& scc,
        stack<int> &S, vector<bool> &inS,
        vector<int> &low, vector<int> &num, int& time) {
    low[v] = num[v] = ++time;
    S.push(v); inS[v] = true;
    FOR(e, g[v]) {
        int w = e->dst;
        if (num[w] == 0) {
            visitStronglyConnectedComponents(g, w, scc, S, inS, low, num, time);
            low[v] = min(low[v], low[w]);
        } else if (inS[w])
            low[v] = min(low[v], num[w]);
    }
    if (low[v] == num[v]) {
        scc.push_back(vector<int>());
        while (1) {
            int w = S.top(); S.pop(); inS[w] = false;
            scc.back().push_back(w);
            if (v == w) break;
        }
    }
}
void stronglyConnectedComponents(const Graph& g,
        vector< vector<int> >& scc) {
    const int n = g.size();
    vector<int> num(n), low(n);
    stack<int> S;
    vector<bool> inS(n);
    int time = 0;
    REP(u, n) if (num[u] == 0)
        visitStronglyConnectedComponents(g, u, scc, S, inS, low, num, time);
}
void printGraph(Graph& g) {
    REP(i, g.size()) {
        if (!g[i].size())
            continue;
        REP(j, g[i].size()) {
            cout << "(" << i << ", " << g[i][j].dst << "), ";
        }
        cout << endl;
    }
}

ll n, a, b;
vector<vi> c;
vi u, v;

int main(void) {
    cin >> n >> a; 
    Graph g_(n);
    rep(i, a) { ll x, y; cin >> x >> y; x--; y--;  addDirected(g_, y, x); }
    cin >> b;
    u = vi(b), v = vi(b);
    rep(i, b) { ll x, y; cin >> x >> y; x--; y--; u[i] = x; v[i] = y; }

    ll ret = 0;
    rep(mask, 1 << b) {
//        cout << "############" << endl;
        Graph g = g_;
        rep(j, b) {
            if (mask & (1 << j)) {
                addDirected(g, u[j], v[j]);
            } else {
//                cout << u[j] << " is forbidden" << endl;
            }
        }
//        printGraph(g);
        vector<vector<int>> scc;
        stronglyConnectedComponents(g, scc);

        stack<ll> s;
        vll memo(n, 0);
        rep(j, b) {
            if ((mask & (1 << j)) == 0) {
                s.push(u[j]);
            }
        }
        rep(j, scc.size()) {
            if (scc[j].size() > 1)
                rep(k, scc[j].size()) 
                    s.push(scc[j][k]);
        }
        while (!s.empty()) {
            ll index = s.top(); s.pop();
            memo[index] = 1;
//            cout << index << endl;
            rep(j, g[index].size()) {
                if (memo[g[index][j].dst])
                    continue;
                s.push(g[index][j].dst);
            }
        }
//        for (int i = 0; i < b; i++) cout << !!(mask & (1 << i)) << " "; cout << ":";
//        for (int i = 0; i < n; i++) cout << memo[i] << " "; cout << endl;

        ll tmp = n;
        rep(j, memo.size())
            tmp -= memo[j];
        ret = max(ret, tmp);
//        cout << tmp << "tmp ret" << endl;
    }
    cout << ret << endl;

    return 0;
}
