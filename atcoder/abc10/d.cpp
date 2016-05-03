#include <bits/stdc++.h>
using namespace std;

#define MAX_V 105
#define INF (1<<20)

//to:行き先,cap:容量,rev:逆(G[e.to][e.rev]で逆辺の構造体にアクセスできる。)
struct edge {
    int to,cap,rev;
};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from,int to,int cap)
{
    G[from].push_back( (edge){ to,cap,(int)G[to].size() } );
    G[to].push_back( (edge){ from,0,(int)G[from].size()-1}); // 相互参照できるように。これは必須。
}

//sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す。
int dfs(int v,int t,int f)
{
    if (v==t)
        return f;
    used[v] = true;
    for (int i=0; i<G[v].size(); ++i) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap>0) {
            int d = dfs(e.to, t, min(f,e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
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
    while (1) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f==0) {
            return flow;
        }
        flow += f;
    }
}

#define rep(i,n) for(int i = 0; i < n; i++)
int main()
{
    int n, g, e; cin >> n >> g >> e;
    rep(i, g) { 
        int girl; cin >> girl; 
        add_edge(girl, n, 1);
    }
    rep(i, e) {
        int u, v; cin >> u >> v;
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    cout << max_flow(0, n) << endl;
}

