#include <iostream>
#include <vector>
using namespace std;

// 隣接リストで使う辺を表す型
const int MAX_N = 1e5+5;
const int INF = 1e9;
struct edge { int to, cost; };
vector<int> dist; // 最短距離
vector<edge> roads[MAX_N]; // グラフの辺を格納した構造体
// graph[v][i]は頂点vから出るi番目の辺edge



// 戻り値がtrueなら負の閉路を含む
void bellman_ford(int sp, int n, vector<edge> *roads/*input*/, int* d/*output*/) // sp = start point
    dist = vector<int>(n, INF);
    dist[sp] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < roads[v].size(); k++) {
                edge e = roads[v][k];
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

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        roads[from].push_back(edge{to, cost});
    }

    bellman_ford(n, 0);

    for (int i = 1; i < n; i++) {
        if (dist[i] != INF)
            cout << "0から" << i << "へのコスト: " << dist[i] << endl;
    }

    return 0;
}
