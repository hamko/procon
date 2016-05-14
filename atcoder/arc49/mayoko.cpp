#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
#include<complex>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

struct SCC {
    int V;
    vector<vi> G, rG;
    vector<int> vs, used, cmp;
    SCC(const vector<vi>& g) : V(g.size()), G(g), rG(V), used(V), cmp(V) {
        for (int i = 0; i < V; i++) for (int u : G[i]) rG[u].push_back(i);
    }
    void dfs(int v) {
        used[v] = 1;
        for (int u : G[v]) if (!used[u]) dfs(u);
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        used[v] = 1;
        cmp[v] = k;
        for (int u : rG[v]) if (!used[u]) rdfs(u, k);
    }
    int calc() {
        fill(used.begin(), used.end(), 0);
        vs.clear();
        for (int v = 0; v < V; v++) {
            if (!used[v]) dfs(v);
        }
        fill(used.begin(), used.end(), 0);
        int k = 0;
        for (int i = vs.size()-1; i >= 0; i--) {
            if (!used[vs[i]]) rdfs(vs[i], k++);
        }
        return k;
    }
};

const int MAX = 110;
int N, A, B;
int X[MAX], Y[MAX], U[MAX], V[MAX];

bool NG[MAX];

void dfs(int v, const vector<vi>& G) {
    NG[v] = true;
    for (int u : G[v]) {
        if (!NG[u]) dfs(u, G);
    }
}

int calc(int state) {
    memset(NG, false, sizeof(NG));
    vector<vi> G(N), rG(N);
    vector<int> degree(N, 0);
    for (int i = 0; i < A; i++) {
        G[Y[i]].push_back(X[i]);
        rG[X[i]].push_back(Y[i]);
    }
    for (int i = 0; i < B; i++) {
        if (((state & (1 << i)) == 0)) {
            G[U[i]].push_back(V[i]);
            rG[V[i]].push_back(U[i]);
        } else {
            NG[U[i]] = true;
        }
//        state /= 2;
    }
    cout << "only state NG" << endl;
    for (int i = 0; i < B; i++) cout << !!(state & (1 << i)) << " "; cout << ":";
    for (int i = 0; i < N; i++) cout << NG[i] << " "; cout << endl;

    SCC scc(G);
    int k = scc.calc();
    vector<vi> comp(k);
    for (int i = 0; i < N; i++) comp[scc.cmp[i]].push_back(i);
    for (int i = 0; i < k; i++) {
        if (comp[i].size() > 1) for (int v : comp[i]) NG[v] = true;
    }
    cout << "scc NG" << endl;
    for (int i = 0; i < B; i++) cout << !!(state & (1 << i)) << " "; cout << ":";
    for (int i = 0; i < N; i++) cout << NG[i] << " "; cout << endl;
    for (int i = 0; i < N; i++) if (NG[i]) dfs(i, G);
    cout << "all NG" << endl;
    for (int i = 0; i < B; i++) cout << !!(state & (1 << i)) << " "; cout << ":";
    for (int i = 0; i < N; i++) cout << NG[i] << " "; cout << endl;
    int ans = N;
    for (int i = 0; i < N; i++) if (NG[i]) ans--;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> A;
    for (int i = 0; i < A; i++) {
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
    }
    cin >> B;
    for (int i = 0; i < B; i++) {
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
    }
    int ans = 0;
    for (int state = 0; state < 1<<B; state++) {
        ans = max(ans, calc(state));
    }
    cout << ans << endl;
    return 0;
}

