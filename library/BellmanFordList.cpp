#include <iostream>
#include <vector>
using namespace std;

// 隣接リストで使う辺を表す型
struct Edge {
    int to, cost;  // 辺の接続先頂点, 辺の重み
    Edge(int to, int cost) : to(to), cost(cost) {}  // コンストラクタ
};

typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
AdjList graph;  // グラフの辺を格納した構造体
// graph[v][i]は頂点vから出るi番目の辺Edge

const int INF = 100000000;

vector<int> dist; // 最短距離

// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
    dist = vector<int>(n, INF);
    dist[s] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph = AdjList(n);

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(Edge(to, cost));
    }

    bellman_ford(n, 0);

    for (int i = 1; i < n; i++) {
        if (dist[i] != INF)
            cout << "0から" << i << "へのコスト: " << dist[i] << endl;
    }

    return 0;
}
