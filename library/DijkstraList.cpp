#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 100000000;
const int MAX_N = 10000;
struct edge{int to, dist;};

int d[MAX_N]; // 最短距離
vector<edge> roads[MAX_N]; // 頂点iからの辺集合。.toが行き先、.distがコスト
int N;
void dijkstra(int sp) // sp = start point
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

int main() {
    // roadsの入力
    int M;
    cin >> N >> M;
    while (M--) {
        int u, v, t;
        cin >> u >> v >> t;
        // 片方向なら
        edge e1 = {v, t}; roads[u].push_back(e1);
        // 両方向なら
//        edge e2 = {u, t}; roads[v].push_back(e2);
    }

    // 最短距離dを更新
    int start_point = 0;
    dijkstra(start_point);

    for (int i = 0; i < N; i++) {
        cout << d[i] << endl;
    }

    return 0;
}
