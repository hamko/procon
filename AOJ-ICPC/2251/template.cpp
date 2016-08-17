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

// mode
//
// 0 : デフォルト。辺だけ表示
// 1 : 重みweightだけ表示
// 2 : フロー用。weight, capを表示。
void vizGraph(Graph& g, int mode = 0, string filename = "out.png") {
    ofstream ofs("./out.dot");
    ofs << "digraph graph_name {" << endl;
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) {
            ofs << "    " << i << " -> " << g[i][j].dst; 
            if (mode == 1) {
                ofs << " [ label = \"" << g[i][j].weight << "\"];"; 
            } else if (mode == 2) {
                ofs << " [ label = \"" << g[i][j].weight << "/" << (g[i][j].cap  == INF ? "inf" : to_string(g[i][j].cap)) << "\"];"; 
            }
            ofs << endl;
        }
    }
    ofs << "}" << endl;
    ofs.close();
    system(((string)"dot -T png out.dot >" + filename).c_str());
}

void transformFromMatrixToGraph(Graph& g, Matrix& m) {
    ll n = m.size();
    g.resize(n);
    rep(i, n) rep(j, n) if (m[i][j] != INF) {
        addDirected(g, i, j, m[i][j]);
    }
}

// Floyd Warshall
// O(V^3)
// 入力
// g: 隣接行列表記された有向グラフのコスト。辺と逆辺の異なる重みは許容する
// 出力
// dist: dist[i][j]がiからjへの有向最短経路。未初期化の変数を渡して答えを副作用で取得。 
//
// モノイドなら動く（演算子と初期値の変更で実装可能）
void shortestPathFW(const Matrix &g, Matrix &dist) {
    ll n = g.size();
    dist = g;
    rep(k, n) rep(i, n) rep(j, n)
        if (dist[i][j] > dist[i][k] + dist[k][j])
            dist[i][j] = dist[i][k] + dist[k][j];
}
// O(V^2)
// 未初期化のmとサイズnを与えると
void initFW(Matrix& m, ll n){
    m = Matrix(n, Array(n, INF));
    rep(i, n) m[i][i] = 0;
}

// 二部マッチング
// 入力：
// g : 二部グラフ．0 ... L-1 が左側頂点，L ... g.size()-1 が右側頂点に対応する．
// L : 二部グラフの左側の頂点の数．
// 出力：matching : マッチングに用いられる辺集合．
//
// 注意、gは左から右への 有 向 グラフ！
// O(V (V + E))
bool augment(const Graph& g, int u,
        vector<int>& matchTo, vector<bool>& visited) {
    if (u < 0) return true;
    FOR(e, g[u]) if (!visited[e->dst]) {
        visited[e->dst] = true;
        if (augment(g, matchTo[e->dst], matchTo, visited)) {
            matchTo[e->src] = e->dst;
            matchTo[e->dst] = e->src;
            return true;
        }
    }
    return false;
}
int bipartiteMatching(const Graph& g, int L, Edges& matching) {
    const int n = g.size();
    vector<int> matchTo(n, -1);
    int match = 0;
    rep(u, L) {
        vector<bool> visited(n);
        if (augment(g, u, matchTo, visited)) ++match;
    }
    rep(u, L) if (matchTo[u] >= 0) // make explicit matching
        matching.push_back( Edge(u, matchTo[u], 1) );
    return match;
}
// 二部マッチングの入力グラフを特性関数から構築
// bool f(i, j) : 左のi in [0, L)から右のj in [0, R)との辺があれば1, なければ0
template<class Function>
void constructBiparitate(Graph& g, int L, int R, Function f) {
    g = Graph(L + R);
    rep(l, L) rep(r, R) if (f(l, r)) addDirected(g, l, L + r);
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m, l;
    while (cin >> n >> m >> l && n) {
        Matrix dist;
        Matrix g_fw;
        initFW(g_fw, n);
        rep(i, m) {
            ll u, v, d; cin >> u >> v >> d;
            g_fw[u][v] = g_fw[v][u] = d;
        }
        shortestPathFW(g_fw, dist);

        /*
        Graph to_print;
        transformFromMatrixToGraph(to_print, g_fw);
        vizGraph(to_print, 1);
        */

        vll p(l), t(l);
        rep(i, l) {
            cin >> p[i] >> t[i];
        }

        Graph g(2*l);
        rep(i, l) rep(j, l) if (i != j) {
            if (dist[p[i]][p[j]] <= t[j] - t[i]) { // i -> jに行ければ
                addDirected(g, i, l+j);
            }
        }
        Edges matching;
        int ret = bipartiteMatching(g, l, matching);
        cout << l - ret << endl;
    }
    return 0;
}
