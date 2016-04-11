#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)

typedef long long ll;

/* Begin Dijkstra */
typedef pair<int, int> P;
const int INF = 1e9;
const int MAX_N = 100005;
struct edge{int to, dist;};

void dijkstra(int sp, int N, vector<edge> *roads, int* d) // sp = start point
{
    fill(d, d + N, INF);
    d[sp] = 0;
    // P(最短距離、頂点)
    priority_queue<P, vector<P>, greater<P> > qu;
    qu.push(P(0, sp));
    // ダイクストラ
    while (!qu.empty()) {
        P p = qu.top();
        qu.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < roads[v].size(); i++) {
            edge e = roads[v][i];
            if (d[e.to] > d[v] + e.dist) {
                d[e.to] = d[v] + e.dist;
                qu.push(P(d[e.to], e.to));
            }
        }
    }
}
/* End Dijkstra */

int main(void) {
    int n, M, t;
    cin >> n >> M >> t;

    int money[MAX_N];
    rep(i, n) cin >> money[i];

    vector<edge> roads_for[MAX_N], roads_back[MAX_N]; // 頂点iからの辺集合。.toが行き先、.distがコスト
    rep(i, M) {
        int u, v, d;
        cin >> u >> v >> d; u--; v--;
        roads_for[u].push_back(edge{v, d});
        roads_back[v].push_back(edge{u, d});
    }

    int d_for[MAX_N], d_back[MAX_N]; // 最短距離
    dijkstra(0, n, roads_for, d_for);
    dijkstra(0, n, roads_back, d_back);

    ll m = -1;
    rep(i, n) {
        if (d_for[i] == INF || d_back[i] == INF)// || t < d_for[i] + d_back[i])
            continue;
        m = max(m, (ll)money[i] * (t - d_for[i] - d_back[i]));
    }
    cout << m << endl;

    return 0;
}
