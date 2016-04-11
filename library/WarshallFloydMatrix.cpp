#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int> > Matrix;

const int INF = 100000000;
Matrix d; // グラフの距離を格納した2次元配列（隣接行列）
// d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

void warshall_floyd(int n) { // nは頂点数
    for (int i = 0; i < n; i++)      // 経由する頂点
        for (int j = 0; j < n; j++)    // 開始頂点
            for (int k = 0; k < n; k++)  // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
    int n, m;
    cin >> n;

    d = Matrix(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;

    cin >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        d[from][to] = cost;
    }

    warshall_floyd(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && d[i][j] != INF)
                cout << i << "から" << j << "へのコスト: " << d[i][j] << endl;
        }
    }

    return 0;
}
