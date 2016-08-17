#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define ldout fixed << setprecision(40) 

static const long long mo = 1e9+7;


/***********************/
// 共通部分
/***********************/
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long Weight;
const Weight INF = 1e18;
const Weight EPS = 0; // 浮動小数点なら1e-14

struct Edge {
    ll src, dst;
    ll cap = 1;
    Weight weight; // 最小費用流ではcostの役割
    ll rev; // 残余グラフの対応用
    bool rev_flag = false; // revなら1
    Edge() {};
    Edge(ll src, ll dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
    Edge(int src, int dst, int cap, Weight cost): // 最小費用流用
        src(src), dst(dst), cap(cap), weight(cost){ }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

// 最大流と最小費用流の有向
// 無向は自分でひっくり返して追加して下さい
void addDirected(Graph& g, ll src, ll dst, Weight weight, ll cap) {
    assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0);
    Edge e = Edge(src, dst, weight);
    e.cap = cap;
    g[src].push_back(e); 
}

// 普通のやつ　
void addDirected(Graph& g, ll src, ll dst, Weight weight) { assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0); g[src].push_back(Edge(src, dst, weight)); } 
void addUndirected(Graph& g, ll src, ll dst, Weight weight) { assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0); g[src].push_back(Edge(src, dst, weight)); g[dst].push_back(Edge(dst, src, weight)); } 

// 普通のやつ、辺重みは1固定
void addDirected(Graph& g, ll src, ll dst) { addDirected(g, src, dst, 1); }
void addUndirected(Graph& g, ll src, ll dst) { addUndirected(g, src, dst, 1); }

void printGraph(Graph& g) {
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) 
            cout << "(" << i << ", " << g[i][j].dst << "), ";
        cout << endl;
    }
}
void printGraphCap(Graph& g) {
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) 
            cout << "(" << i << ", " << g[i][j].dst << " : " << g[i][j].cap << ", " << (g[i][j].rev_flag ? "rev" : "for") << "), ";
        cout << endl;
    }
}

void vizGraph(Graph& g, bool with_cap = 0) {
    ofstream ofs("./out.dot");
    ofs << "digraph graph_name {" << endl;
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) {
            ofs << "    " << i << " -> " << g[i][j].dst; 
            if (with_cap) {
                ofs << " [ label = \"" << g[i][j].weight << "/" << (g[i][j].cap  == INF ? "inf" : to_string(g[i][j].cap)) << "\"];"; 
            }
            ofs << endl;
        }
    }
    ofs << "}" << endl;
    ofs.close();
    system("dot -T png out.dot > sample.png");
}

// Primal-Dual
// O(V^2 U C)
// 変数定義がよくわからなかったのでnot yet
#undef RESIDUE
#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
pair<Weight, Weight> minimumCostFlow(const Graph &g, int s, int t, ll F) {
    const int n = g.size();
    Matrix capacity(n, Array(n)), cost(n, Array(n)), flow(n, Array(n));
    REP(u,n) FOR(e,g[u]) {
        capacity[e->src][e->dst] += e->cap;
        cost[e->src][e->dst] += e->weight;
    }
    pair<Weight, Weight> total; // (cost, flow)
    vector<Weight> h(n);

    for (; F > 0; ) { // residual flow
        vector<Weight> d(n, INF); d[s] = 0;
        vector<int> p(n, -1);
        priority_queue<Edge> Q; // "e < f" <=> "e.cost > f.cost"
        for (Q.push(Edge(-2, s, 0, 0)); !Q.empty(); ) {
            Edge e = Q.top(); Q.pop();
            if (p[e.dst] != -1) continue;
            p[e.dst] = e.src;
            FOR(f, g[e.dst]) if (RESIDUE(f->src, f->dst) > EPS) {
                if (d[f->dst] > d[f->src] + RCOST(f->src, f->dst) + EPS) {
                    d[f->dst] = d[f->src] + RCOST(f->src, f->dst);
                    Q.push( Edge(f->src, f->dst, 0, d[f->dst]) );
                }
            }
        }
        if (p[t] == -1) break;

        Weight f = F;
        for (int u = t; u != s; u = p[u])
            f = min(f, RESIDUE(p[u], u));
        for (int u = t; u != s; u = p[u]) {
            total.first += f * cost[p[u]][u];
            flow[p[u]][u] += f; flow[u][p[u]] -= f;
        }
        F -= f;
        total.second += f;
        REP(u, n) h[u] += d[u];
    }
    return total;
}

pair<Weight, Weight> minimumCostFlow(const Graph &g, int s, int t) {
    return minimumCostFlow(g, s, t, INF);
}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n), b(n); rep(i, a.size()) cin >> a[i] >> b[i];
    set<ll> tmp;
    rep(i, n) {
        tmp.insert(a[i]);
        tmp.insert(b[i]);
    }
    ll vn = tmp.size();

    unordered_map<ll, int> s_rev;
    ll counter = 0;
    for (auto x : tmp) {
        s_rev[x] = counter;
        counter++;
    }

    // [0, n)       積み木
    // [n, n+vn)    幅
    // n+vn         使わない積み木
    // n+vn+1       始点
    // n+vn+2       終点
    ll not_used = n+vn;
    ll s = n+vn+1;
    ll t = n+vn+2;

    // 始点 -> 積み木
    Graph g(n + vn + 3);
    rep(i, n) {
        addDirected(g, n+vn+1, i, 0, 1);
    }

    // 積み木 -> 幅
    rep(i, n) {
        addDirected(g, i, n + s_rev[a[i]], -b[i], 1);
        addDirected(g, i, n + s_rev[b[i]], -a[i], 1);
        addDirected(g, i, not_used, 0, 1);
    }

    // 幅 -> 終点
    addDirected(g, not_used, t, 0, INF);
    for (int i = n; i < n + vn; i++) {
        addDirected(g, i, t, 0, 1);
    }
//    vizGraph(g, true);

    cout << -minimumCostFlow(g, s, t, n).fi << endl;
    return 0;
}
