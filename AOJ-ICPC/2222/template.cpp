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

static const double EPS = 1e-14;
static const long long mo = 1e9+7;

/***********************/
// 共通部分
/***********************/
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

typedef long long Weight;
const Weight INF = 1e18;

struct Edge {
    ll src, dst;
    Weight weight;
    Edge(ll src, ll dst, Weight weight) :
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

void addDirected(Graph& g, ll src, ll dst, Weight weight) { assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0); g[src].push_back(Edge(src, dst, weight)); }
void addUndirected(Graph& g, ll src, ll dst, Weight weight) { assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0); g[src].push_back(Edge(src, dst, weight)); g[dst].push_back(Edge(dst, src, weight)); }
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

// 強連結分解
// O(V+E)
// const Graph& g               有向グラフ
// vector< vector<ll> >& scc   グラフの強連結成分
void visitStronglyConnectedComponents(const Graph &g, ll v, vector< vector<ll> >& scc,
        stack<ll> &S, vector<bool> &inS,
        vector<ll> &low, vector<ll> &num, ll& time) {
    low[v] = num[v] = ++time;
    S.push(v); inS[v] = true;
    FOR(e, g[v]) {
        ll w = e->dst;
        if (num[w] == 0) {
            visitStronglyConnectedComponents(g, w, scc, S, inS, low, num, time);
            low[v] = min(low[v], low[w]);
        } else if (inS[w])
            low[v] = min(low[v], num[w]);
    }
    if (low[v] == num[v]) {
        scc.push_back(vector<ll>());
        while (1) {
            ll w = S.top(); S.pop(); inS[w] = false;
            scc.back().push_back(w);
            if (v == w) break;
        }
    }
}
void stronglyConnectedComponents(const Graph& g, vector< vector<ll> >& scc) {
    const ll n = g.size();
    vector<ll> num(n), low(n);
    stack<ll> S;
    vector<bool> inS(n);
    ll time = 0;
    rep(u, n) if (num[u] == 0)
        visitStronglyConnectedComponents(g, u, scc, S, inS, low, num, time);
}

// トポロジカルソート
// 頂点の順序付け u であって，u[i] から u[j] に辺がある => i < j が成立するものをいう．
//
// const Graph &g
// グラフ．
// vector<int> &order
// トポロジカルソートの結果を副作用で代入．意味を持つのは戻り値が true のときに限る．
// 戻り値
// トポロジカルソート可能かどうか．
//
// O(V+E)
bool visitT(const Graph &g, ll v, vector<ll> &order, vector<ll> &color) {
    color[v] = 1;
    FOR(e, g[v]) {
        if (color[e->dst] == 2) continue;
        if (color[e->dst] == 1) return false;
        if (!visitT(g, e->dst, order, color)) return false;
    }
    order.push_back(v); color[v] = 2;
    return true;
}
bool topologicalSort(const Graph &g, vector<ll> &order) {
    ll n = g.size();
    vector<ll> color(n);
    rep(u, n) if (!color[u] && !visitT(g, u, order, color))
        return false;
    reverse(all(order));
    return true;
}

// 逆辺のグラフを得る
void reverseGraph(Graph& g_dst, Graph& g_src) { /*g_dstは空graphを渡す*/
    g_dst = Graph(g_src.size());
    rep(i, g_src.size()) {
        rep(j, g_src[i].size()) {
            addDirected(g_dst, g_src[i][j].dst, g_src[i][j].src, g_src[i][j].weight);
        }
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    Graph g = Graph(n);
    rep(i, m) {
        ll u, v; cin >> u >> v; u--, v--;
        addDirected(g, u, v);
    }

    // ループを潰すための前処理
    vector<vector<ll>> scc;
    stronglyConnectedComponents(g, scc);

    // 各頂点が、どのSCCに属しているか
    vector<ll> scc_inv(g.size());
    rep(i, scc.size()) rep(j, scc[i].size()) scc_inv[scc[i][j]] = i;

    // 新しいDAGのグラフ作成
    // グラフdagの頂点iは、実際には(vector<ll> scc[i])たちを表している。
    Graph dag(scc.size());
    rep(from, g.size()) rep(to, g[from].size()) if (scc_inv[from] != scc_inv[g[from][to].dst]) {
        addDirected(dag, scc_inv[from], scc_inv[g[from][to].dst]);
    }

    // トポロジカルソートして、
    // 逆から見ることで、メモ化再帰できるようにする
    vector<ll> order;
    topologicalSort(dag, order);
    reverse(all(order));

    // トポロジカルソートを逆から見たいが、
    // 収束先の頂点は、より上流の集めるべき頂点を知らないので逆辺グラフを構築する
    Graph dag_rev;
    reverseGraph(dag_rev, dag);

    // dp[i]: 頂点iを塗ると仮定した時の、より上流の塗り方
    vll dp(dag.size(), -1);
    function<ll(ll)> f = [&](ll i){
        if (dp[i] != -1)
            return dp[i];
        dp[i] = 1;
        rep(j, dag_rev[i].size()) {
            (dp[i] *= f(dag_rev[i][j].dst) + 1) %= mo;
        }
        return dp[i];
    };

    // 分岐のないトポロジカルソートなので、
    // 後ろから見ていって初めて見たものは必ずその連結成分の最下流となる。
    ll ret = 1;
    rep(i, dag.size()) {
        if (dp[order[i]] != -1) 
            continue;
        (ret *= f(order[i]) + 1) %= mo;
    }
    cout << ret << endl;

    return 0;
}
