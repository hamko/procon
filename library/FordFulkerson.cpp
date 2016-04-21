#include <vector>
#include <iostream>

using namespace std;

#define MAX_V 50
#define INF (1<<20)

//to:行き先,cap:容量,rev:逆(G[e.to][e.rev]で逆辺の構造体にアクセスできる。)
struct edge {
    int to,cap,rev;
};

vector<edge> G[MAX_V];
bool used[MAX_V];

//辺を追加。revは,相互参照できるようにしている。sizeで実現しているが、別のルールを用いても良い(i.e ハッシュ)。逆辺の逆辺は通常の辺である。
    void
add_edge(int from,int to,int cap)
{
    G[from].push_back( (edge){ to,cap,(int)G[to].size() } );
    G[to].push_back( (edge){ from,0,(int)G[from].size()-1});
}

//sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す。
    int
dfs(int v,int t,int f)
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
    int
max_flow(int s,int t)
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

    int
main()
{
    vector<vector<int> >  to =
    {
        {1,3},
        {2,3},
        {3,4},
        {4}
    }
    ;
    vector<vector<int> > cap =
    {
        {10,2},
        {6,6},
        {3,8},
        {5}
    }
    ;
    for (int i=0; i<to.size(); ++i) {
        for (int j=0; j<to[i].size(); ++j) {
            add_edge(i, to[i][j], cap[i][j]);
        }
    }
    cout << max_flow(0, 4) << endl;
}
