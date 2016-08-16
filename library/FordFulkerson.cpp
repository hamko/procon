#include <bits/stdc++.h>

using namespace std;

#define MAX_V 50
#define INF (1<<20)

// FordFulkerson
// O(V ret)

//to:行き先,cap:容量,rev:逆(G[e.to][e.rev]で逆辺の構造体にアクセスできる。)
struct edge {
    int to,cap,rev;
};

// G[v]: vから出てる辺の集合
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap)
{
    G[from].push_back( (edge){ to,cap,(int)G[to].size() } );
    G[to].push_back( (edge){ from,0,(int)G[from].size()-1}); // これが余剰グラフの逆辺。非常に重要。初めはフローが流れていないので、cap=0
}

//sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す。
// fは流そうとしている流量
int dfs(int v/*from*/ ,int t/*goal*/,int f) {
    if (v==t)
        return f;
    used[v] = true;
    for (int i=0; i<G[v].size(); ++i) {
        edge &e = G[v][i]; // to
        if (!used[e.to] && e.cap>0) { // キャパシティが残っている辺を探す 
            int d = dfs(e.to, t, min(f,e.cap)); // 流そうとしてる流量、キャパシティのうち小さい方を次に流そうとする
            if (d > 0) {
                e.cap -= d; // 余剰グラフの辺を更新
                G[e.to][e.rev].cap += d; // 余剰グラフの逆辺を更新
                return d;
            }
        }
    }
    return 0;
}

//sからtへの最大流量を返す。
int max_flow(int s,int t)
{
    int flow = 0;
    for (;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f==0) {
            return flow;
        }
        flow += f;
    }
}

int main()
{
    // 有向グラフ
    {
        vector<vector<int> >  to =
        {
            {1,3},
            {2,3},
            {3,4},
            {4}
        } ;
        vector<vector<int> > cap =
        {
            {10,2},
            {6,6},
            {3,8},
            {5}
        } ;
        for (int i=0; i<to.size(); ++i) {
            for (int j=0; j<to[i].size(); ++j) {
                add_edge(i, to[i][j], cap[i][j]);
            }
        }
        cout << max_flow(0, 4) << endl;
    }

    // 無向グラフの場合には両方に張るだけでOK
    {
        vector<vector<int>> to =
        {
            {1,2},
            {2,0},
            {0,1},
        } ;
        vector<vector<int>> cap =
        {
            {1,1},
            {1,1},
            {3,3},
        } ;
        for (int i=0; i<to.size(); ++i) {
            for (int j=0; j<to[i].size(); ++j) {
                add_edge(i, to[i][j], cap[i][j]);
            }
        }
        cout << max_flow(0, 2) << endl;
    }
}
