#include <cstdio>
#include <bits/stdc++.h>
using namespace std;


// Usage  : init -> add -> LCA(g, root) -> getAnswer
const int MAX = 1000000;
const int NOT_VALID_INDEX = -1;
vector<int> graph[MAX], query[MAX], answer[MAX];
int rep_[MAX], rank_[MAX], anc[MAX];
short int visited[MAX]; //0 - not visited, 1 - visited 2 - processed
vector<int> depth; // depth[i]: 頂点iの根からの深さ, 根が0
int root = NOT_VALID_INDEX;
int V;

// 辿って親と深さを確認するだけ
void updateDepth(int v, int p, int d) {
    depth[v] = d;
    for (int i = 0; i < graph[v].size(); i++){
        int next = graph[v][i];
        if (next != p) updateDepth(next, v, d+1);
    }
}

int Find(int a)
{
    if(rep_[a] != a)
        rep_[a] = Find(rep_[a]);
    return rep_[a];
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b) return;

    if(rank_[a] < rank_[b])
        rep_[a] = b;
    else if(rank_[b] < rank_[a])
        rep_[b] = a;
    else {
        rep_[a] = b;
        ++rank_[b];
    }
}

void MakeSets(int m)
{
    while(m--) {
        rep_[m] = m;
        rank_[m] = 0;
    }
}

void dfs(int v)
{
    visited[v] = 1;
    anc[v] = v;
    for(int i = 0; i < graph[v].size(); ++i) {
        if(visited[graph[v][i]] == 0) {
            dfs(graph[v][i]);
            Union(v, graph[v][i]);
            anc[Find(v)] = v;
        }
    }
    visited[v] = 2;
    for(int i = 0; i < query[v].size(); ++i) {
        if(visited[query[v][i]] == 2)
            answer[v][i] = anc[Find(query[v][i])];
    }
}

typedef pair<int, int> P;
map<P, P> memo;
void addQuery(int x, int y) 
{
    memo[P(x, y)] = P(x, query[x].size());
    query[x].push_back(y);
    if(x!=y) {
        memo[P(y, x)] = P(y, query[y].size());
        query[y].push_back(x);
    }
}

void LCA(int n, int root)
{
    MakeSets(n);
    for(int i = 0; i < n; ++i) {
        answer[i].resize(query[i].size());
        for (int j = 0; j < answer[i].size(); j++) {
            answer[i][j] = NOT_VALID_INDEX;
        }
    }
    dfs(root);
}

int getLCAAnswer(int x, int y) 
{
    if (!memo.count(P(x, y)) && !memo.count(P(y, x))) 
        return NOT_VALID_INDEX;
    P I1 = memo[P(x, y)];
    P I2 = memo[P(y, x)];
    if (answer[I1.first][I1.second] != NOT_VALID_INDEX)
        return answer[I1.first][I1.second];
    else if (answer[I2.first][I2.second] != NOT_VALID_INDEX)
        return answer[I2.first][I2.second];
    cerr << "ERROR" << endl;
    exit(1);
    return NOT_VALID_INDEX;
}

void init(int r, int vnum)
{
    memo.clear();
    root = r;
    V = vnum;
    depth.resize(vnum);
    updateDepth(root, -1, 0);
}

#define rep(i,n) for(int i = 0; i < n; i++)
int main()
{
    int n; cin >> n;
    rep(i, n-1) {
        int x, y; cin >> x >> y; x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    init(0/*root*/, n);

    int q; cin >> q;
    vector<int> xs, ys;
    for(int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y; x--; y--;
        addQuery(x, y);
        xs.push_back(x); ys.push_back(y); 
    }

    LCA(n, 0);

    for(int i = 0; i < q; ++i) {
        cout << depth[xs[i]] + depth[ys[i]] - 2 * depth[getLCAAnswer(xs[i], ys[i])] + 1 << endl;;
    }

    return 0;
}
