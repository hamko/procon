#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matrix;

const int INF = 100000000;
Matrix graph; // グラフの距離を格納した2次元配列（隣接行列）
// graph[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF）

vector<int> dist; // 最短距離

// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
    dist = vector<int>(n, INF);
    dist[s] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                int cost = graph[j][k];
                if (dist[j] != INF && dist[k] > dist[j] + cost) {
                    dist[k] = dist[j] + cost;
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

    graph = Matrix(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
    }

    bellman_ford(n, 0);

    for (int i = 1; i < n; i++) {
        if (dist[i] != INF)
            cout << "0から" << i << "へのコスト: " << dist[i] << endl;
    }

    return 0;
}
