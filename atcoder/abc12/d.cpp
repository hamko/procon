#include <bits/stdc++.h>
using namespace std;

typedef int Weight;
const Weight INF = 1e9;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

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

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Max(x) *max_element(all(x))
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

int main(void) {
    int n, m; cin >> n >> m;
    Matrix connection; initFW(connection, n);
    rep(i, m) {
        int x, y, w; cin >> x >> y >> w; x--; y--;
        setUndirectedFW(connection, x, y, w);
    }
    Matrix ret;
    vector< vector<int> > inter;
    shortestPathFW(connection, ret, inter);

    int m_ = INF;
    rep(i, n) { 
        m_ = min(m_, Max(ret[i]));
    }
    cout << m_ << endl;
    return 0;
}
