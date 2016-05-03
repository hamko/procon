#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
#define MAX_N 100005

typedef ll Weight;
const Weight INF = 1e18;

struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void addDirected(Graph& g, int src, int dst, Weight weight) { g[src].push_back(Edge(src, dst, weight)); }
void addUndirected(Graph& g, int src, int dst, Weight weight) { g[src].push_back(Edge(src, dst, weight)); g[dst].push_back(Edge(dst, src, weight)); }
void addDirected(Graph& g, int src, int dst) { addDirected(g, src, dst, 1); }
void addUndirected(Graph& g, int src, int dst) { addUndirected(g, src, dst, 1); }

Graph g;
vector<ll> dist;

void rec(ll index, ll bnum) {
    rep(i, g[index].size()) {
        ll dst = g[index][i].dst;
        ll cost_tobe = dist[index]+1;
        if (g[index][i].weight) 
            cost_tobe += bnum;
        if (dist[dst] > cost_tobe) {
            dist[dst] = cost_tobe;
            if (g[index][i].weight) 
                rec(dst, bnum+1);
            else 
                rec(dst, bnum);
        }
    }
}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, m; cin >> n >> m;
    dist = vector<ll>(n, INF);
    dist[0] = 0;
    g = Graph(n);

    rep(i, m) {
        ll c, a, b; cin >> c >> a >> b;
        addUndirected(g, a, b, c);
    }
    rec(0, 0);
    rep(i, n) {
        cout << dist[i] << endl;
    }
    return 0;
}
