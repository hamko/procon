#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
vector<int> graph[MAX], query[MAX], answer[MAX];
int n, q, x, y, rep[MAX], rank[MAX], anc[MAX];
short int visited[MAX]; //0 - not visited, 1 - visited 2 - processed

int Find(int a)
{
    if(rep[a] != a)
        rep[a] = Find(rep[a]);
    return rep[a];
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b) return;

    if(rank[a] < rank[b])
        rep[a] = b;
    else if(rank[b] < rank[a])
        rep[b] = a;
    else {
        rep[a] = b;
        ++rank[b];
    }
}

void MakeSets(int m)
{
    while(m--) {
        rep[m] = m;
        rank[m] = 0;
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

void LCA(int n, int root)
{
    MakeSets(n);
    for(int i = 1; i <= n; ++i)
        answer[i].resize(query[i].size());
    dfs(root);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y; x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int q; cin >> q;
    map<int, int> corr;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        cout << a << " " << b << endl;
        corr[i] = query[a].size();
        query[a].push_back(b);
        if(a!=b) query[b].push_back(a);
    }
    LCA(n, 1);
    for (int i = 0; i < q; i++) {
        cout << i << " " << corr[i] << " " << answer[i][corr[i]] << endl;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < query[i].size(); ++j) {
            if(answer[i][j] != 0)
                printf("LCA(%d, %d) = %d\n", i, query[i][j], answer[i][j]);
        }
    }
    return 0;
}
