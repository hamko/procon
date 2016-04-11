#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

/* Begin Dijkstra */
typedef pair<int, int> P;
const int INF = 1e9;
const int MAX_N = 1e5+5;
struct edge{int to, dist;};

int d[MAX_N]; // 最短距離
vector<edge> roads[MAX_N]; // 頂点iからの辺集合。.toが行き先、.distがコスト
int N;
void dijkstra(int sp, int N, vector<edge> *roads/*input*/, int* d/*output*/) // sp = start point
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

int main() {
    int M;
    cin >> N >> M;

    // roadsの入力。uが始点、vが終点、dが距離
    vector<edge> roads[MAX_N]; // 頂点iからの辺集合。.toが行き先、.distがコスト
    while (M--) {
        int u, v, d;
        cin >> u >> v >> d;
        // 片方向なら
        roads[u].push_back(edge{v, d});
        // 両方向なら
//        edge e2 = {u, d}; roads[v].push_back(e2);
    }

    // 最短距離dを更新
    int start_point = 0;
    int d[MAX_N]; // 最短距離
    dijkstra(start_point, N, roads, d); // roadsを事前設定しておくと、dが計算される

    for (int i = 0; i < N; i++) {
        cout << d[i] << endl;
    }

    return 0;
}
