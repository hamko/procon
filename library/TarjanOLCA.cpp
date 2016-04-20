#include <cstdio>
#include <bits/stdc++.h>
using namespace std;


// Usage  : init -> add -> LCA(g, root) -> getAnswer
const int MAX = 1000000;
const int NOT_VALID_INDEX = -1;
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
    else
    {
        rep[a] = b;
        ++rank[b];
    }
}

void MakeSets(int m)
{
    while(m--)
    {
        rep[m] = m;
        rank[m] = 0;
    }
}

void dfs(int v)
{
    visited[v] = 1;
    anc[v] = v;
    for(int i = 0; i < graph[v].size(); ++i)
    {
        if(visited[graph[v][i]] == 0)
        {
            dfs(graph[v][i]);
            Union(v, graph[v][i]);
            anc[Find(v)] = v;
        }
    }
    visited[v] = 2;
    for(int i = 0; i < query[v].size(); ++i)
    {
        if(visited[query[v][i]] == 2)
            answer[v][i] = anc[Find(query[v][i])];
    }
}

typedef pair<int, int> P;
map<P, P> memo;
void addQuery(int x, int y) 
{
    memo[P(x, y)] = P(x, query[x].size());
    cout << memo[P(x, y)].first << " " << memo[P(x, y)].second << "#" << x << " " << y << endl;
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
int getAnswer(int x, int y) 
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
void init(void)
{
    memo.clear();
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    init();

    scanf("%d", &q);
    vector<int> xs, ys;
    for(int i = 0; i < q; ++i) {
        scanf("%d%d", &x, &y);
        addQuery(x, y);
        xs.push_back(x); ys.push_back(y); 
    }
    LCA(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < query[i].size(); ++j) {
            if(answer[i][j] != NOT_VALID_INDEX)
                printf("LCA(%d, %d) = %d\n", i, query[i][j], answer[i][j]);
        }
    }

    cout << "#" << endl;
    for(int i = 0; i < q; ++i) {
        cout << xs[i] << " " << ys[i] << " " << getAnswer(xs[i], ys[i]) << endl;;
    }

    return 0;
}
