#include "bits/stdc++.h"
using namespace std;

// TODO
// O(n)系の初期化をまとめたものが欲しい。Euler Tour, DFSで木の深さをメモるとか。
// 木をGraphの子クラスとして実装？
// FordFulkerson, Tarjan's OLCA, EulerTour, Treeをマージ
// Graphなどを全部クラスにする


/***********************/
// 共通部分
/***********************/

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
void printGraph(Graph& g) {
    REP(i, g.size()) {
        if (!g[i].size())
            continue;
        REP(j, g[i].size()) 
            cout << "(" << i << ", " << g[i][j].dst << "), ";
        cout << endl;
    }
}
/***********************/
// 共通部分おわり
/***********************/

// rootからの連結頂点をrootに塗る
// connectedはサイズ頂点数, -1で初期化。
// O(V), UNTESTED, RUNTIME ERROR OCCURS
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


// Dijkstra
// O(E log V)
void shortestPathDI(const Graph &g, int s,
        vector<Weight> &dist, vector<int> &prev) {
    int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
    for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (prev[e.dst] != -1) continue;
        prev[e.dst] = e.src;
        FOR(f,g[e.dst]) {
            if (dist[f->dst] > e.weight+f->weight) {
                dist[f->dst] = e.weight+f->weight;
                Q.push(Edge(f->src, f->dst, e.weight+f->weight));
            }
        }
    }
}
vector<int> buildPathDI(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}


// Floyd Warshall
// O(V^3)
void shortestPathFW(const Matrix &g,
        Matrix &dist, vector< vector<int> > &inter) {
    int n = g.size();
    dist = g;
    inter.assign(n, vector<int>(n,-1));
    REP(k, n) REP(i, n) REP(j, n) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            inter[i][j] = k;
        }
    }
}
void buildPathFW(const vector< vector<int> > &inter,
        int s, int t, vector<int> &path) {
    int u = inter[s][t];
    if (u < 0) path.push_back(s);
    else buildPathFW(inter, s, u, path), buildPathFW(inter, u, s, path);
}
vector<int> buildPathFW(
        const vector< vector<int> > &inter, int s, int t) {
    vector<int> path;
    buildPathFW(inter, s, t, path);
    path.push_back(t);
    return path;
}
void initFW(Matrix& m, int n){
    m = Matrix(n, Array(n, INF));
    REP(i, n) m[i][i] = 0;
}
void setFW(Matrix& m, int u, int v, int w){ m[u][v] = w; }
void setUndirectedFW(Matrix& m, int u, int v, int w){ m[u][v] = m[v][u] = w; }



// Johnson
// 前処理 O(V E)． 中間処理 O(V E log V)． 後処理 O(V^2)．
bool shortestPathJO(const Graph &g,
        Matrix &dist, vector<vector<int> > &prev) {
    int n = g.size();
    Array h(n+1);
    REP(k,n) REP(i,n) FOR(e,g[i]) {
        if (h[e->dst] > h[e->src] + e->weight) {
            h[e->dst] = h[e->src] + e->weight;
            if (k == n-1) return false; // negative cycle
        }
    }
    dist.assign(n, Array(n, INF));
    prev.assign(n, vector<int>(n, -2));
    REP(s, n) {
        priority_queue<Edge> Q;
        Q.push(Edge(s, s, 0));
        while (!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            if (prev[s][e.dst] != -2) continue;
            prev[s][e.dst] = e.src;
            FOR(f,g[e.dst]) {
                if (dist[s][f->dst] > e.weight + f->weight) {
                    dist[s][f->dst] = e.weight + f->weight;
                    Q.push(Edge(f->src, f->dst, e.weight + f->weight));
                }
            }
        }
        REP(u, n) dist[s][u] += h[u] - h[s];
    }
}
vector<int> buildPathJO(const vector< vector<int> >& prev, int s, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[s][u])
        path.push_back(u);
    reverse(ALL(path));
    return path;
}


// Bellman Ford
// O(V E)．
bool shortestPathBE(const Graph g, int s, vector<Weight> &dist, vector<int> &prev) {
    int n = g.size();
    dist.assign(n, INF+INF); dist[s] = 0;
    prev.assign(n, -2);
    bool negative_cycle = false;
    REP(k, n) REP(i, n) FOR(e,g[i]) {
        if (dist[e->dst] > dist[e->src] + e->weight) {
            dist[e->dst] = dist[e->src] + e->weight;
            prev[e->dst] = e->src;
            if (k == n-1) {
                dist[e->dst] = -INF;
                negative_cycle = true;
            }
        }
    }
    return !negative_cycle;
}
vector<int> buildPathBE(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

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

// k-shortest
// O(k E log V)
Weight k_shortestPath(const Graph &g, int s, int t, int k) {
    const int n = g.size();

    Graph h(n); // make reverse graph
    REP(u, n) FOR(e, g[u])
        h[e->dst].push_back(Edge(e->dst,e->src,e->weight));

    vector<Weight> d(n, INF); d[t] = 0; // make potential
    vector<int> p(n, -1);               // using backward dijkstra
    priority_queue<Edge> Q; Q.push(Edge(t, t, 0));
    while (!Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (p[e.dst] >= 0) continue;
        p[e.dst] = e.src;
        FOR(f, h[e.dst]) if (d[f->dst] > e.weight + f->weight) {
            d[f->dst] = e.weight + f->weight;
            Q.push(Edge(f->src, f->dst, e.weight + f->weight));
        }
    }
    int l = 0; // forward dijkstra-like method
    priority_queue<Edge> R; R.push(Edge(-1,s,0));
    while (!R.empty()) {
        Edge e = R.top(); R.pop();
        if (e.dst == t && ++l == k) return e.weight + d[s];
        FOR(f, g[e.dst])
            R.push(Edge(f->src, f->dst, e.weight+f->weight-d[f->src]+d[f->dst]));
    }
    return -1; // not found
}

// Prim
// O(E log V)
pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
    int n = g.size();
    Edges T;
    Weight total = 0;

    vector<bool> visited(n);
    priority_queue<Edge> Q;
    Q.push( Edge(-1, r, 0) );
    while (!Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (visited[e.dst]) continue;
        T.push_back(e);
        total += e.weight;
        visited[e.dst] = true;
        FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
    }
    return pair<Weight, Edges>(total, T);
}

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) { if (data[y] < data[x]) swap(x, y); data[x] += data[y]; data[y] = x; }
        return x != y;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
};

// Kruskal
// O(E log V + A(r) E)
pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
    int n = g.size();
    UnionFind uf(n);
    priority_queue<Edge> Q;
    REP(u, n) FOR(e, g[u]) if (u < e->dst) Q.push(*e);

    Weight total = 0;
    Edges F;
    while (F.size() < n-1 && !Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (uf.unionSet(e.src, e.dst)) {
            F.push_back(e);
            total += e.weight;
        }
    }
    return pair<Weight, Edges>(total, F);
}



// Cuninghame-Green
Weight minimumDiameterSpanningTree(const Graph &g) {
    int n = g.size();
    Matrix dist(n, Array(n, INF)); // all-pair shortest
    REP(u, n) dist[u][u] = 0;
    REP(u, n) FOR(e, g[u]) dist[e->src][e->dst] = e->weight;
    REP(k, n) REP(i, n) REP(j, n)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    Edges E;
    REP(u, n) FOR(e, g[u]) if (e->src < e->dst) E.push_back(*e);
    int m = E.size();

    Weight H = INF;
    vector<Weight> theta(m);
    REP(r, m) {
        int u = E[r].src, v = E[r].dst;
        Weight d = E[r].weight;
        REP(w, n) theta[r] = max(theta[r], min(dist[u][w], dist[v][w]));
        H = min(H, d + 2 * theta[r]);
    }
    Weight value = INF;
    REP(r, m) if (2 * theta[r] <= H) {
        int u = E[r].src, v = E[r].dst;
        Weight d = E[r].weight;
        vector< pair<Weight,Weight> > list;
        REP(w, n) list.push_back( make_pair(dist[u][w], dist[v][w]) );
        sort(ALL(list), greater< pair<Weight,Weight> >());
        int p = 0;
        value = min(value, 2 * list[0].first);
        REP(k, n) if (list[p].second < list[k].second)
            value = min(value, d + list[p].second + list[k].first), p = k;
        value = min(value, 2 * list[p].second);
    }
    return n == 1 ? 0 : value;
}

// Chu-Liu/Edmond
// O(VE)
void visit(Graph &h, int v, int s, int r,
        vector<int> &no, vector< vector<int> > &comp,
        vector<int> &prev, vector< vector<int> > &next, vector<Weight> &mcost,
        vector<int> &mark, Weight &cost, bool &found) {
    const int n = h.size();
    if (mark[v]) {
        vector<int> temp = no;
        found = true;
        do {
            cost += mcost[v];
            v = prev[v];
            if (v != s) {
                while (comp[v].size() > 0) {
                    no[comp[v].back()] = s;
                    comp[s].push_back(comp[v].back());
                    comp[v].pop_back();
                }
            }
        } while (v != s);
        FOR(j,comp[s]) if (*j != r) FOR(e,h[*j])
            if (no[e->src] != s) e->weight -= mcost[ temp[*j] ];
    }
    mark[v] = true;
    FOR(i,next[v]) if (no[*i] != no[v] && prev[no[*i]] == v)
        if (!mark[no[*i]] || *i == s)
            visit(h, *i, s, r, no, comp, prev, next, mcost, mark, cost, found);
}
Weight minimumSpanningArborescence(const Graph &g, int r) {
    const int n = g.size();
    Graph h(n);
    REP(u,n) FOR(e,g[u]) h[e->dst].push_back(*e);

    vector<int> no(n);
    vector< vector<int> > comp(n);
    REP(u, n) comp[u].push_back(no[u] = u);

    for (Weight cost = 0; ;) {
        vector<int> prev(n, -1);
        vector<Weight> mcost(n, INF);

        REP(j,n) if (j != r) FOR(e,g[j])
            if (no[e->src] != no[j])
                if (e->weight < mcost[ no[j] ])
                    mcost[ no[j] ] = e->weight, prev[ no[j] ] = no[e->src];

        vector< vector<int> > next(n);
        REP(u,n) if (prev[u] >= 0)
            next[ prev[u] ].push_back(u);

        bool stop = true;
        vector<int> mark(n);
        REP(u,n) if (u != r && !mark[u] && !comp[u].empty()) {
            bool found = false;
            visit(h, u, u, r, no, comp, prev, next, mcost, mark, cost, found);
            if (found) stop = false;
        }
        if (stop) {
            REP(u,n) if (prev[u] >= 0) cost += mcost[u];
            return cost;
        }
    }
}


Weight minimum_steiner_tree(const vector<int>& T, const Matrix &g) {
    const int n = g.size();
    const int numT = T.size();
    if (numT <= 1) return 0;

    Matrix d(g); // all-pair shortest
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

    Weight OPT[(1 << numT)][n];
    for (int S = 0; S < (1 << numT); ++S)
        for (int x = 0; x < n; ++x)
            OPT[S][x] = INF;

    for (int p = 0; p < numT; ++p) // trivial case
        for (int q = 0; q < n; ++q)
            OPT[1 << p][q] = d[T[p]][q];

    for (int S = 1; S < (1 << numT); ++S) { // DP step
        if (!(S & (S-1))) continue;
        for (int p = 0; p < n; ++p)
            for (int E = 0; E < S; ++E)
                if ((E | S) == S)
                    OPT[S][p] = min( OPT[S][p], OPT[E][p] + OPT[S-E][p] );
        for (int p = 0; p < n; ++p)
            for (int q = 0; q < n; ++q)
                OPT[S][p] = min( OPT[S][p], OPT[S][q] + d[p][q] );
    }
    Weight ans = INF;
    for (int S = 0; S < (1 << numT); ++S)
        for (int q = 0; q < n; ++q)
            ans = min(ans, OPT[S][q] + OPT[((1 << numT)-1)-S][q]);
}


// Edmonds-Karp
// O(E^2 V)．以下の実装では内部で隣接行列を生成するため，O(V^2) の追加コスト
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlowEdmondsKarp(const Graph &g, int s, int t) {
    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n));
    REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    while (1) {
        queue<int> Q; Q.push(s);
        vector<int> prev(n, -1); prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            int u = Q.front(); Q.pop();
            FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                prev[e->dst] = u;
                Q.push(e->dst);
            }
        }
        if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
        Weight inc = INF;
        for (int j = t; prev[j] != j; j = prev[j])
            inc = min(inc, RESIDUE(prev[j], j));
        for (int j = t; prev[j] != j; j = prev[j])
            flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
        total += inc;
    }
}


// Dinic
// O(E V^2)
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight augment(const Graph &g, const Matrix &capacity, Matrix &flow,
        const vector<int> &level, vector<bool> &finished, int u, int t, Weight cur) {
    if (u == t || cur == 0) return cur;
    if (finished[u]) return 0;
    finished[u] = true;
    FOR(e, g[u]) if (level[e->dst] > level[u]) {
        Weight f = augment(g, capacity, flow, level, finished,
                e->dst, t, min(cur, RESIDUE(u, e->dst)));
        if (f > 0) {
            flow[u][e->dst] += f; flow[e->dst][u] -= f;
            finished[u] = false;
            return f;
        }
    }
    return 0;
}
Weight maximumFlowDinic(const Graph &g, int s, int t) {
    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n)); // adj. matrix
    REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    for (bool cont = true; cont; ) {
        cont = false;
        vector<int> level(n, -1); level[s] = 0; // make layered network
        queue<int> Q; Q.push(s);
        for (int d = n; !Q.empty() && level[Q.front()] < d; ) {
            int u = Q.front(); Q.pop();
            if (u == t) d = level[u];
            FOR(e, g[u]) if (RESIDUE(u,e->dst) > 0 && level[e->dst] == -1)
                Q.push(e->dst), level[e->dst] = level[u] + 1;
        }
        vector<bool> finished(n); // make blocking flows
        for (Weight f = 1; f > 0; ) {
            f = augment(g, capacity, flow, level, finished, s, t, INF);
            if (f == 0) break;
            total += f; cont = true;
        }
    }
    return total;
}



// Goldberg-Tarjan
// O(V^2 sqrt(E))
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
#define GLOBAL_RELABELING() { \
    queue<int> Q; Q.push(t); \
    fill(ALL(d), INF); d[t] = 0; \
    while (!Q.empty()) { \
        int u = Q.front(); Q.pop(); \
        FOR(e, g[u]) if (RESIDUE(e->dst, u) > 0 && d[u] + 1 < d[e->dst])  \
        Q.push(e->dst), d[e->dst] = d[u] + 1; \
    } \
}
#define PUSH(u, v) { \
    Weight delta = min(excess[u], RESIDUE(u, v)); \
    flow[u][v] += delta; flow[v][w] -= delta; \
    excess[u] -= delta; excess[v] += delta; }
Weight maximumFlowGoldbergTarjan(const Graph &g, int s, int t) {
    int n = g.size(), count = 0;
    Matrix flow(n, Array(n)), capacity(n, Array(n)); // adj. matrix
    REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    vector<Weight> excess(n); excess[s] = INF; // initialize step
    vector<int> d(n);
    GLOBAL_RELABELING();
    vector< queue<int> > B(n); B[ d[s] ].push( s );

    for (int b = d[s]; b >= 0; ) {
        if (B[b].empty()) { --b; continue; }
        int v = B[b].front(); B[b].pop();
        if (excess[v] == 0 || v == t) continue;

        FOR(e, g[v]) {
            int w = e->dst; // e is the current edge of v
            if (RESIDUE(v,w) > 0 && d[v] == d[w] + 1) { // (w,v) is admissible
                PUSH(v, w);
                if (excess[w] > 0 && w != t) B[d[w]].push( w );
            }
        }
        if (excess[v] == 0) continue;
        d[v] = n;
        FOR(e, g[v]) if (RESIDUE(v, e->dst) > 0)
            d[v] = min(d[v], d[e->dst] + 1);
        if (d[v] < n) B[b = d[v]].push(v);

        if (++count % n == 0) GLOBAL_RELABELING(); // !!HEURISTICS
    }
    return excess[t];
}


// Nagamochi-Ibaraki
// O(V^3), 本当はO(VE + V log V)
Weight minimumCut(const Graph &g) {
    int n = g.size();
    vector< vector<Weight> > h(n, vector<Weight>(n)); // make adj. matrix
    REP(u,n) FOR(e,g[u]) h[e->src][e->dst] += e->weight;
    vector<int> V(n); REP(u, n) V[u] = u;

    Weight cut = INF;
    for(int m = n; m > 1; m--) {
        vector<Weight> ws(m, 0);
        int u, v;
        Weight w;
        REP(k, m) {
            u = v; v = max_element(ws.begin(), ws.end())-ws.begin();
            w = ws[v]; ws[v] = -1;
            REP(i, m) if (ws[i] >= 0) ws[i] += h[V[v]][V[i]];
        }
        REP(i, m) {
            h[V[i]][V[u]] += h[V[i]][V[v]];
            h[V[u]][V[i]] += h[V[v]][V[i]];
        }
        V.erase(V.begin()+v);
        cut = min(cut, w);
    }
    return cut;
}



// Gomory-Hu 木
// O(V MAXFLOW)
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Graph cutTree(const Graph &g) {
    int n = g.size();
    Matrix capacity(n, Array(n)), flow(n, Array(n));
    REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    vector<int> p(n), prev;
    vector<Weight> w(n);
    for (int s = 1; s < n; ++s) {
        int t = p[s]; // max-flow(s, t)
        REP(i,n) REP(j,n) flow[i][j] = 0;
        Weight total = 0;
        while (1) {
            queue<int> Q; Q.push(s);
            prev.assign(n, -1); prev[s] = s;
            while (!Q.empty() && prev[t] < 0) {
                int u = Q.front(); Q.pop();
                FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                    prev[e->dst] = u;
                    Q.push(e->dst);
                }
            }
            if (prev[t] < 0) goto esc;
            Weight inc = INF;
            for (int j = t; prev[j] != j; j = prev[j])
                inc = min(inc, RESIDUE(prev[j], j));
            for (int j = t; prev[j] != j; j = prev[j])
                flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
            total += inc;
        }
esc:w[s] = total; // make tree
    REP(u, n) if (u != s && prev[u] != -1 && p[u] == t)
        p[u] = s;
    if (prev[p[t]] != -1)
        p[s] = p[t], p[t] = s, w[s] = w[t], w[t] = total;
    }
    Graph T(n); // (s, p[s]) is a tree edge of weight w[s]
    REP(s, n) if (s != p[s]) {
        T[  s ].push_back( Edge(s, p[s], w[s]) );
        T[p[s]].push_back( Edge(p[s], s, w[s]) );
    }
    return T;
}
// Gomory-Hu tree を用いた最大流 O(n)
Weight maximumFlowGomoryHu(const Graph &T, int u, int t, int p = -1, Weight w = INF) {
    if (u == t) return w;
    Weight d = INF;
    FOR(e, T[u]) if (e->dst != p)
        d = min(d, maximumFlowGomoryHu(T, e->dst, t, u, min(w, e->weight)));
    return d;
}



// Primal-Dual
// O(V^2 U C)
// 変数定義がよくわからなかったのでnot yet


// 最小共通先祖 Tarjan 
// 構築O(E A(V))、参照O(1)、のはずだがなぜかクエリ数にものすごく依存してる…
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



// 全頂点を根とした時の木の高さの最大値
// O(E)
Weight visitH(const Graph &g, Graph& T, int i, int j) {
    if (T[i][j].weight >= 0) return T[i][j].weight;
    T[i][j].weight = g[i][j].weight;
    int u = T[i][j].dst;
    REP(k, T[u].size()) {
        if (T[u][k].dst == i) continue;
        T[i][j].weight = max(T[i][j].weight, visitH(g,T,u,k)+g[i][j].weight);
    }
    return T[i][j].weight;
}
vector<Weight> heightMax(const Graph& g) {
    const int n = g.size();
    Graph T(g); // memoise on tree
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < T[i].size(); ++j)
            T[i][j].weight = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < T[i].size(); ++j)
            if (T[i][j].weight < 0)
                T[i][j].weight = visitH(g, T, i, j);

    vector<Weight> ht(n); // gather results
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < T[i].size(); ++j)
            ht[i] = max(ht[i], T[i][j].weight);
    return ht;
}


// 木の直径
// O(E)
typedef pair<Weight, int> Result;
Result visit(int p, int v, const Graph &g) {
    Result r(0, v);
    FOR(e, g[v]) if (e->dst != p) {
        Result t = visit(v, e->dst, g);
        t.first += e->weight;
        if (r.first < t.first) r = t;
    }
    return r;
}
Weight diameter(const Graph &g) {
    Result r = visit(-1, 0, g);
    Result t = visit(-1, r.second, g);
    return t.first; // (r.second, t.second) is farthest pair
}


// 有効オイラー路判定
// O(E)
void visitE(Graph& g, int a, vector<int>& path) {
    while (!g[a].empty()){
        int b = g[a].back().dst;
        g[a].pop_back();
        visitE(g, b, path);
    }
    path.push_back(a);
}
bool eulerPath(Graph g, int s, vector<int> &path) {
    int n = g.size(), m = 0;
    vector<int> deg(n);
    REP(u, n){
        m += g[u].size();
        FOR(e, g[u]) --deg[e->dst]; //  in-deg
        deg[u] += g[u].size();      // out-deg
    }
    int k = n - count(ALL(deg), 0);
    if (k == 0 || (k == 2 && deg[s] == 1)) {
        path.clear();
        visitE(g, s, path);
        reverse(ALL(path));
        return path.size() == m + 1;
    }
    return false;
}


// 無向オイラー路判定
// O(E)
void visitEWithoutDirection(const Graph &g, vector< vector<int> > &adj, int s, vector<int> &path) {
    FOR(e, g[s]) if (adj[e->src][e->dst]) {
        --adj[e->src][e->dst];
        --adj[e->dst][e->src];
        visitEWithoutDirection(g, adj, e->dst, path);
    }
    path.push_back(s);
}
bool eulerPathWithoutDirection(const Graph &g, int s, vector<int> &path) {
    int n = g.size();
    int odd = 0, m = 0;
    REP(i, n) {
        if (g[i].size() % 2 == 1) ++odd;
        m += g[i].size();
    }
    m /= 2;
    if (odd == 0 || (odd == 2 && g[s].size() % 2 == 0)) {
        vector< vector<int> > adj(n, vector<int>(n));
        REP(u, n) FOR(e, g[u]) ++adj[e->src][e->dst];
        path.clear();
        visitEWithoutDirection(g, adj, s, path);
        reverse(ALL(path));
        return path.size() == m + 1;
    }
    return false;
}


// 無向中国人郵便配達問題
// O(o m log n + o^2 2^o), o=18が限度
Weight chinesePostman(const Graph &g) {
    Weight total = 0;
    vector<int> odds;
    REP(u, g.size()) {
        FOR(e, g[u]) total += e->weight;
        if (g[u].size() % 2) odds.push_back(u);
    }
    total /= 2;
    int n = odds.size(), N = 1 << n;
    Weight w[n][n]; // make odd vertices graph
    REP(u,n) {
        int s = odds[u]; // dijkstra's shortest path
        vector<Weight> dist(g.size(), INF); dist[s] = 0;
        vector<int>    prev(g.size(), -2);
        priority_queue<Edge> Q;
        Q.push( Edge(-1, s, 0) );
        while (!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            if (prev[e.dst] != -2) continue;
            prev[e.dst] = e.src;
            FOR(f,g[e.dst]) {
                if (dist[f->dst] > e.weight+f->weight) {
                    dist[f->dst] = e.weight+f->weight;
                    Q.push(Edge(f->src, f->dst, e.weight+f->weight));
                }
            }
        }
        REP(v,n) w[u][v] = dist[odds[v]];
    }
    Weight best[N]; // DP for general matching 
    REP(S,N) best[S] = INF;
    best[0] = 0;

    for (int S = 0; S < N; ++S)
        for (int i = 0; i < n; ++i) if (!(S&(1<<i)))
            for (int j = i+1; j < n; ++j) if (!(S&(1<<j)))
                best[S|(1<<i)|(1<<j)] = min(best[S|(1<<i)|(1<<j)], best[S]+w[i][j]);
    return total + best[N-1];
}



// 最短ハミルトン路
// O(V!) の計算量がかかるが，動的計画法に基づくアルゴリズムによって O(V^2 2^V) の計算量に軽減
// O(V^2 2^V), V=18が限度
const int M = 20;
Weight best[1<<M][M];
int    prev_[1<<M][M];
void buildPath(int S, int i, vector<int> &path) {
    if (!S) return;
    buildPath(S^(1<<i), prev_[S][i], path);
    path.push_back(i);
}
Weight shortestHamiltonPath(Matrix w, int s, vector<int> &path) {
    int n = w.size(); // 僕が追加
    int N = 1 << n;
    REP(S,N) REP(i,n) best[S][i] = INF;
    best[1<<s][s] = 0;
    REP(S,N) REP(i,n) if (S&(1<<i)) REP(j,n)
        if (best[S|(1<<j)][j] > best[S][i] + w[i][j])
            best[S|(1<<j)][j] = best[S][i] + w[i][j],
                prev_[S|(1<<j)][j] = i;
    int t = min_element(best[N-1], best[N-1]+n) - best[N-1];
    path.clear(); buildPath(N-1, t, path);
    return best[N-1][t];
}


bool visitT(const Graph &g, int v, vector<int> &order, vector<int> &color) {
    color[v] = 1;
    FOR(e, g[v]) {
        if (color[e->dst] == 2) continue;
        if (color[e->dst] == 1) return false;
        if (!visitT(g, e->dst, order, color)) return false;
    }
    order.push_back(v); color[v] = 2;
    return true;
}
bool topologicalSort(const Graph &g, vector<int> &order) {
    int n = g.size();
    vector<int> color(n);
    REP(u, n) if (!color[u] && !visitT(g, u, order, color))
        return false;
    reverse(ALL(order));
    return true;
}



// グラフの同型性判別
// 最悪O(V!)、ランダムグラフに対しては O(V log V)
typedef pair<int, int> VertexInfo;
#define index second
#define degree first
bool permTest(int k, const Matrix &g, const Matrix &h,
        vector<VertexInfo> &gs, vector<VertexInfo> &hs) {
    const int n = g.size();
    if (k >= n) return true;
    for (int i = k; i < n && hs[i].degree == gs[k].degree; ++i) {
        swap(hs[i], hs[k]);
        int u = gs[k].index, v = hs[k].index;
        for (int j = 0; j <= k; ++j) {
            if (g[u][gs[j].index] != h[v][hs[j].index]) goto esc;
            if (g[gs[j].index][u] != h[hs[j].index][v]) goto esc;
        }
        if (permTest(k+1, g, h, gs, hs)) return true;
esc:swap(hs[i], hs[k]);
    }
    return false;
}
bool isomorphism(const Matrix &g, const Matrix &h) {
    const int n = g.size();
    if (h.size() != n) return false;
    vector<VertexInfo> gs(n), hs(n);
    REP(i, n) {
        gs[i].index = hs[i].index = i;
        REP(j, n) {
            gs[i].degree += g[i][j];
            hs[j].degree += h[i][j];
        }
    }
    sort(ALL(gs)); sort(ALL(hs));
    REP(i, n) if (gs[i].degree != hs[i].degree) return false;

    return permTest(0, g, h, gs, hs);
}

#define rep(i,n) for(int i = 0; i < n; i++)
main(void)
{
    // 基本的な使い方
    {
        Graph g(6);
//        Graph g; // 先に頂点数nで初期化しないとaddUndirectedとかできない
        addDirected(g, 0, 3);       // 有向辺。重みは自動で1に
        addDirected(g, 2, 3, 5);    // 有向辺。重みを明示的に指定
        addUndirected(g, 1, 4);     // 無向辺。重みは自動で1に
        addUndirected(g, 4, 2, 5);  // 無向辺。重みを明示的に指定
//        addDirected(g, -1, 0) // 0未満を使ってはならない。
//        addDirected(g, 0, 6) // サイズ以上を使ってはならない。
    }
    // 強連結分解
    {
        Graph g = Graph(6); // ちゃんとnで初期化しないとaddUndirectedとかできない
        addDirected(g, 0, 1), addDirected(g, 1, 2), addDirected(g, 2, 0); // 強連結
        addDirected(g, 2, 3);
        addDirected(g, 3, 4), addDirected(g, 4, 3); // 強連結
        addDirected(g, 4, 5);

        vector<vector<int>> scc;
        stronglyConnectedComponents(g, scc);
        rep(i, scc.size()) {
            rep(j, scc[i].size()) cout << scc[i][j] << " ";
            cout << endl;
        }
    }
}
