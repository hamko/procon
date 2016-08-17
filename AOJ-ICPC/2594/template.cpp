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
    ll cap = 1;
    Weight weight;
    ll rev; // 残余グラフの対応用
    bool rev_flag = false; // revなら1
    Edge() {};
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

void addDirected(Graph& g, ll src, ll dst, Weight weight, ll cap) {
    assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0);
    Edge e = Edge(src, dst, weight);
    e.cap = cap;
    g[src].push_back(e); 
}
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
void printGraphCap(Graph& g) {
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) 
            cout << "(" << i << ", " << g[i][j].dst << " : " << g[i][j].cap << ", " << (g[i][j].rev_flag ? "rev" : "for") << "), ";
        cout << endl;
    }
}

/***********************/
// 共通部分おわり
/***********************/
// 逆辺のグラフを得る
void reverseGraph(Graph& g_dst, Graph& g_src) { /*g_dstは空graphを渡す*/
    g_dst = Graph(g_src.size());
    rep(i, g_src.size()) {
        rep(j, g_src[i].size()) {
            addDirected(g_dst, g_src[i][j].dst, g_src[i][j].src, g_src[i][j].weight);
        }
    }
}
// グラフの深さ優先探索のテンプレート
// O(V)
// gはグラフ, visitedはg.size()の配列, sは直前の頂点(根なら-1), tは今処理している頂点
void dfs(Graph& g, bool* visited, ll s, ll t) {
    visited[t] = true;
    rep(j, g[t].size()) {
        ll dst = g[t][j].dst;
        if (dst == s) continue;
        if (visited[dst]) continue;
        dfs(g, visited, t, dst); 
    }
}

// 木の深さ優先探索のテンプレート
// O(V)
// gはグラフ, visitedはg.size()の配列, sは直前の頂点(根なら-1), tは今処理している頂点
ll dfs(Graph& g, ll s, ll t) {
    ll ret = 0;
    rep(j, g[t].size()) {
        ll dst = g[t][j].dst;
        if (dst == s) continue;
        ret += g[t][j].weight;
        ret += dfs(g, t, dst); 
    }
    return ret;
}

// 無向グラフ閉路検出
// O(V)
// dfs(g, visited, -1, root)で、rootからの連結をvisitに全列挙しつつ、閉路があれば1を返す
// visitedはg.size()の配列
bool detectClosedCircuit(Graph& g, bool* visited, ll s, ll t) { // 一つ前がs(なければ-1)->tと来た時の閉路検出
    visited[t] = true;
    bool ret = false;
    rep(j, g[t].size()) {
        ll dst = g[t][j].dst;
        if (dst == s) continue;
        if (visited[dst]) { ret = true; continue; }
        ret |= detectClosedCircuit(g, visited, t, dst); 
    }
    return ret;
}

// TODO 計算量間違ってない？
class FordFulkerson {
public:
    Graph g; // 残余ネットワーク
    int s, t; // 始点, 終点
    int n; // 頂点数
    ll flow = 0; // 最大フロー、これを辺追加・削除時にきちんと情報を保つ

    // 普通のフォードフルカーソン
    // O(E ret)
    FordFulkerson(Graph& input, int s_, int t_) : s(s_), t(t_) {
        n = input.size();
        g.resize(n);
        used.resize(n);
        for (auto&& from : input) {
            for (auto&& e_for : from) {
                addEdge(e_for);
            }
        }

        flow = 0;
        revise();
    }
    // 順向きの辺のsrc, dst, capの情報から、
    // 残余グラフの順逆辺を追加する
    void addEdge(Edge& e_for) {
        Edge e_rev;
        e_rev.src = e_for.dst; 
        e_rev.dst = e_for.src;
        e_rev.cap = 0;

        e_for.rev = g[e_rev.src].size();
        e_rev.rev = g[e_for.src].size(); // 逆辺のマーカー
        e_rev.rev_flag = true;
        g[e_for.src].push_back(e_for);
        g[e_rev.src].push_back(e_rev);
    }
    // 残余グラフが初期、あるいは変更された時に
    // flowを再計算する
    //
    // O(V ret)
    ll revise(void) {
        while (1) {
            ll f = update(INF);
            if (!f) { // 残余グラフが収束したら
                break;
            }
            flow += f;
        }
        return flow;
    }

    // 一回だけ、
    // 残余グラフで、vからtへの正のパスを探して、あればそこに流す
    //
    // sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す。
    // fは流そうとしている流量
    //
    // O(V)
    vector<bool> used;
    int dfs(int v/*from*/, int to, ll f) {
        rep(i, n) {
            used[i] = 0;
        }
        return dfs_rec(v, to, f);
    }
    int dfs_rec(int v/*from*/, int to, ll f) {
        if (v == to)
            return f;
        used[v] = true;
        for (int i = 0; i < g[v].size(); i++) {
            Edge &e = g[v][i];
            if (used[e.dst] || e.cap <= 0) 
                continue;
            // キャパシティが残っている辺を探す 
            int d = dfs_rec(e.dst, to, min(f, e.cap)); // 流そうとしてる流量、キャパシティのうち小さい方を次に流そうとする
            if (d > 0) {
                e.cap -= d; // 残余グラフの辺を更新
                g[e.dst][e.rev].cap += d; // 残余グラフの逆辺を更新
                return d;
            }
        }
        return 0;
    }

    // 一回だけDFSのラッパ関数。
    // s, tが予め指定されているなら、こっちを使ったほうが簡潔
    //
    // O(V)
    int update(ll f) {
        return update(f, t);
    }
    int update(ll f, int to) {
        return dfs(s, to, f);
    }

    // sからtへの最大流量を返す。
    // s == tならINFを返す, 不可能なら0を返す
    ll get(void) {
        return flow;
    }

    // O(V) 
    // fromからtoへの有向辺にcapを追加して、その時の最大流量を返す
    // もし有向辺がもともとはなかったら辺を追加する
    int add(int from, int to, ll cap) {
        bool found = false;
        /*
        rep(i, g[from].size()) {
            Edge& e = g[from][i];
            if (e.rev_flag) continue;
            if (e.dst == to) { // もともとあったら
                e.cap += cap;
                found = true;
                break;
            }
        }
        */
        if (found == false) {
            Edge e;
            e.src = from;
            e.dst = to;
            e.cap = cap;
            this->addEdge(e);
        }
        revise();
        return flow;
    }

    //  最 大 流 自 体 は 変 え ず に、from->toのフローを最小化したグラフに置き換える。
    //
    // fromからtoへの辺のフロー=to->fromの逆辺コストを、代替パス=from->toのパスを探すことで、最大流を変えない条件下でなるべく低下させる。
    // from->toのパスの下がったフローの量を返し、副作用でfrom->toのフロー最小化グラフへとgを書き換える。
    //
    // from->パス->to->fromで、ループが出来るならば、
    // from->toの逆辺をループのコスト分だけ下げることができる。
    // パスもコスト分だけ下げたあとに、逆辺を上げることが出来る。
    //
    // O(V ret)
    ll minimizeFlowOfEdgePreservingMaxFlow(int from, int to) {
        ll sum = 0;
        rep(i, g[from].size()) {
            Edge& e = g[from][i];
            if (e.rev_flag) continue;
            if (e.dst != to) continue;
            if (g[e.dst][e.rev].cap == 0) continue;
            // フローが流れているfromからtoへの順向き辺を全列挙

            Edge& e_rev = g[e.dst][e.rev];
            // 消すべき辺のフローを頑張って全部押し戻そうとする
            // 押し戻しきれなかったらあとで考える
            ll ret = 0;
            while (1) { // TODO 必要な分だけ空ければいい
                // e.srcを通る残余グラフの閉路があれば押し戻せる
                bool used[n];
                rep(i, n) {
                    used[i] = false;
                }
                function<ll(ll, ll)> dfs_lam = [&](ll v, ll c) {
                    if (v == e.dst) {
                        return c;
                    }
                    used[v] = true;
                    for (auto&& tmp : g[v]) if (used[tmp.dst] == false && tmp.cap) {
                        ll f = dfs_lam(tmp.dst, min(c, tmp.cap));
                        if (f) {
                            tmp.cap -= f;
                            g[tmp.dst][tmp.rev].cap += f;
                            return f;
                        }
                    }
                    return 0ll;
                };
                ll can_erase = dfs_lam(e.src, e_rev.cap);
                ret += can_erase;
                sum += can_erase;
                e_rev.cap -= can_erase;

                if (can_erase == 0) { // 閉路では消しきれない
                    // TODO 本当はここに来た時点で、全部の辺を確認する必要はなく次に進んでいいはず。
                    break;
                }
            }
            e.cap += ret;
        }
        return sum;
    }

    // fromからtoへの有向辺からcapを減らして、その時の最大流量を返す
    // capが0になっても、残余グラフそのものの辺は消さない
    //
    // O(V ret)
    int erase(int from, int to, ll cap) {
        // 削除クエリの容量が、実際に消せる容量を上回っていないかを確認
        ll cap_sum = 0;
        rep(i, g[from].size()) if (g[from][i].dst == to) {
            Edge& e = g[from][i];
            if (e.rev_flag) continue;
            // 順向き辺を全列挙

            cap_sum += e.cap + g[e.dst][e.rev].cap;
        }
        if (cap > cap_sum) {
            cap = cap_sum;
        }

        // (1) 使ってない辺があったら気にせず削除
        rep(i, g[from].size()) {
            Edge& e = g[from][i];
            if (e.rev_flag) continue;
            if (e.dst != to) continue;
            if (g[e.dst][e.rev].cap != 0) continue;
            // フローが流れていないfromからtoへの順向きの辺を全列挙

            ll to_erase = min(e.cap, cap);
            e.cap -= to_erase;
            cap -= to_erase;
        }
        if (cap == 0) { // もう消す必要がないなら終わり
            return flow;
        }

        // (2) 使っていても、他のパスに同じフローを押し付けられるなら最大流は変わらない
        minimizeFlowOfEdgePreservingMaxFlow(from, to); // これでfrom->toのフローがcapだけ空いた
        // 空いたフローを消す
        rep(i, g[from].size()) {
            Edge& e = g[from][i];
            if (e.rev_flag) continue;
            if (e.dst != to) continue;
            ll m = min(cap, e.cap);
            cap -= m;
            e.cap -= m;
        }
        if (cap == 0) { // もう消す必要がないなら終わり
            return flow;
        }
 
        // (2) もう他に押し付けられないので、削除したいぶんだけフローを押し戻して最大流を低下させる
        //
        // 残余グラフでのt->sへの増大路をcap分だけ見つけて、押し戻してflowを減少させる
        // 減少後には、必ず削除すべき辺を含む閉路が存在するので、先ほどと同じように押し戻す
        ll sum = 0;
        while (1) {
            ll f = dfs(t, s, cap);
            if (!f) break;
            flow -= f;
            cap -= f;
            sum += f;
        }
        assert(cap == 0);
        minimizeFlowOfEdgePreservingMaxFlow(from, to); // これでfrom->toのフローがちょうどcapだけ空いた

        // 空いたフローを消す
        rep(i, g[from].size()) {
            Edge& e = g[from][i];
            if (e.rev_flag) continue;
            if (e.dst != to) continue;
            ll m = min(sum, e.cap);
            sum -= m;
            e.cap -= m;
        }
        return flow;
    }

    // fromからtoへの辺の全削除 
    //
    // O(V ret)
    int erase(int from, int to) {
        return erase(from, to, INF);
    }
};


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m, s, t;
    while (cin >> n >> m >> s >> t && n) { s--; t--;
        Graph g = Graph(n);
        vector<int> us, vs;
        rep(i, m) {
            ll u, v; cin >> u >> v; u--, v--;
            us.pb(u), vs.pb(v);
            addDirected(g, u, v, 0, 1);
        }
        FordFulkerson ff(g, s, t);
        ll initial = ff.get();
        ll ret = 0;
        rep(i, m) {
            ll u = us[i], v = vs[i];
            ff.erase(u, v);
            ff.add(v, u, 1);
            if (initial < ff.get()) ret++;
            ff.erase(v, u);
            ff.add(u, v, 1);
        }
        cout << initial + !!ret << " " << ret << endl;
    }
    return 0;
}
