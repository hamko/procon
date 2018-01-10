#include "bits/stdc++.h"
using namespace std;

// TODO
// O(n)系の初期化をまとめたものが欲しい。Euler Tour, DFSで木の深さをメモるとか。
// 木をGraphの子クラスとして実装？
// FordFulkerson, Tarjan's OLCA, EulerTour, Treeをマージ
// Graphなどを全部クラスにする

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;


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
    Weight weight; // 最小費用流ではcostの役割
    ll cap;
    ll rev; // 残余グラフの対応用
    bool rev_flag = false; // revなら1
    Edge(int src = 0, int dst = 0, Weight weight = 0, Weight cap = 1): 
        src(src), dst(dst), weight(weight), cap(cap){ }
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
void addDirected(Graph& g, ll src, ll dst, Weight weight = 0, ll cap = 0) {
    assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0);
    g[src].push_back(Edge(src, dst, weight, cap)); 
}
vector<string> names;
unordered_map<string, int> name_server;
void clearNameServer(void) {
    names.clear();
    name_server.clear();
}
int constructNameServer(vector<string>& names_) {
    names = names_;
    for (int i = 0; i < names.size(); i++) {
        name_server[names[i]] = i;
    }
    return name_server.size();
}
void addDirected(Graph& g, string src, string dst, Weight weight = 0, ll cap = 0) {
    if (!name_server.count(src)) { cerr << "No such node : " << src << endl; exit(1); }
    if (!name_server.count(dst)) { cerr << "No such node : " << dst << endl; exit(1); }
    addDirected(g, name_server[src], name_server[dst], weight, cap);
}

void addUndirected(Graph& g, ll src, ll dst, Weight weight = 0, ll cap = 0) { 
    addDirected(g, src, dst, weight, cap);
    addDirected(g, dst, src, weight, cap);
} 

void transformFromMatrixToGraph(Graph& g, Matrix& m) {
    ll n = m.size();
    g.resize(n);
    rep(i, n) rep(j, n) if (m[i][j] != INF) {
        addDirected(g, i, j, m[i][j]);
    }
}

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
// 0 : デフォルト。辺だけ表示
// 1 : 重みweightだけ表示
// 2 : フロー用。weight, capを表示。
//
// directed
// 有向グラフなら1、そうでないなら0
// 
void vizGraph(Graph& g, int mode = 0, int directed = 1, string filename = "out.png") {
   
    ofstream ofs("./out.dot");
    ofs << (directed ? "di" : "") << "graph graph_name {" << endl;
    string arrow = (directed ? " -> " : " -- ");

    set<pair<int, int>> used;
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) {
            // 多重辺はないと前提
            if (used.count(pair<int, int>(g[i][j].src, g[i][j].dst))) continue;
            used.insert(pair<int, int>(g[i][j].src, g[i][j].dst));
            if (directed == 0) used.insert(pair<int, int>(g[i][j].dst, g[i][j].src));

            // 頂点に名前がついていれば名前を優先して出す
            if (name_server.size()) {
                ofs << "    " << names[i] << arrow << names[g[i][j].dst]; 
            } else {
                ofs << "    " << i << arrow << g[i][j].dst; 
            }

            // 重みや容量があるならそれも出力
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
        rep(i, g[from].size()) {
            Edge& e = g[from][i];
            if (e.rev_flag) continue;
            if (e.dst == to) { // もともとあったら
                e.cap += cap;
                found = true;
                break;
            }
        }
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
                vector<bool> used(n);
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


// Dijkstra
// O(E log V)
//
// s: 始点
// dist: 空ベクトルを渡すと副作用で始点sからの最短距離を計算してくれる
// prev: 空ベクトルを渡すと副作用で何かが出てくる。経路復元に必要
void shortestPathDI(const Graph &g, ll s,
        vector<Weight> &dist, vector<ll> &prev) {
    ll n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
    for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (prev[e.dst] != -1) continue;
        prev[e.dst] = e.src;
        FOR(f,g[e.dst]) {
            if (dist[f->dst] > e.weight+f->weight) {
                dist[f->dst] = e.weight+f->weight;
                Q.push(Edge(f->src, f->dst, e.weight+f->weight));
            }
        }
    }
}
vector<ll> buildPathDI(const vector<ll> &prev, ll t) {
    vector<ll> path;
    for (ll u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
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

// Floyd Warshall with 経路復元
// O(V^3)
// inter: これなんだろう？
void shortestPathFW(const Matrix &g, Matrix &dist, vector< vector<ll> > &inter) {
    ll n = g.size();
    dist = g;
    inter.assign(n, vector<ll>(n,-1));
    rep(k, n) rep(i, n) rep(j, n) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            inter[i][j] = k;
        }
    }
}
void buildPathFW(const vector< vector<ll> > &inter,
        ll s, ll t, vector<ll> &path) {
    ll u = inter[s][t];
    if (u < 0) path.push_back(s);
    else buildPathFW(inter, s, u, path), buildPathFW(inter, u, s, path);
}
vector<ll> buildPathFW(
        const vector< vector<ll> > &inter, ll s, ll t) {
    vector<ll> path;
    buildPathFW(inter, s, t, path);
    path.push_back(t);
    return path;
}

// Johnson
// 前処理 O(V E)． 中間処理 O(V E log V)． 後処理 O(V^2)．
bool shortestPathJO(const Graph &g,
        Matrix &dist, vector<vector<ll> > &prev) {
    ll n = g.size();
    Array h(n+1);
    rep(k,n) rep(i,n) FOR(e,g[i]) {
        if (h[e->dst] > h[e->src] + e->weight) {
            h[e->dst] = h[e->src] + e->weight;
            if (k == n-1) return false; // negative cycle
        }
    }
    dist.assign(n, Array(n, INF));
    prev.assign(n, vector<ll>(n, -2));
    rep(s, n) {
        priority_queue<Edge> Q;
        Q.push(Edge(s, s, 0));
        while (!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            if (prev[s][e.dst] != -2) continue;
            prev[s][e.dst] = e.src;
            FOR(f,g[e.dst]) {
                if (dist[s][f->dst] > e.weight + f->weight) {
                    dist[s][f->dst] = e.weight + f->weight;
                    Q.push(Edge(f->src, f->dst, e.weight + f->weight));
                }
            }
        }
        rep(u, n) dist[s][u] += h[u] - h[s];
    }
    return true;
}
vector<ll> buildPathJO(const vector< vector<ll> >& prev, ll s, ll t) {
    vector<ll> path;
    for (ll u = t; u >= 0; u = prev[s][u])
        path.push_back(u);
    reverse(all(path));
    return path;
}


// Bellman Ford
// O(V E)．
bool shortestPathBE(const Graph g, ll s, vector<Weight> &dist, vector<ll> &prev) {
    ll n = g.size();
    dist.assign(n, INF+INF); dist[s] = 0;
    prev.assign(n, -2);
    bool negative_cycle = false;
    rep(k, n) rep(i, n) FOR(e,g[i]) {
        if (dist[e->dst] > dist[e->src] + e->weight) {
            dist[e->dst] = dist[e->src] + e->weight;
            prev[e->dst] = e->src;
            if (k == n-1) {
                dist[e->dst] = -INF;
                negative_cycle = true;
            }
        }
    }
    return !negative_cycle;
}
vector<ll> buildPathBE(const vector<ll> &prev, ll t) {
    vector<ll> path;
    for (ll u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
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

// k-shortest
// O(k E log V)
Weight k_shortestPath(const Graph &g, ll s, ll t, ll k) {
    const ll n = g.size();

    Graph h(n); // make reverse graph
    rep(u, n) FOR(e, g[u])
        h[e->dst].push_back(Edge(e->dst,e->src,e->weight));

    vector<Weight> d(n, INF); d[t] = 0; // make potential
    vector<ll> p(n, -1);               // using backward dijkstra
    priority_queue<Edge> Q; Q.push(Edge(t, t, 0));
    while (!Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (p[e.dst] >= 0) continue;
        p[e.dst] = e.src;
        FOR(f, h[e.dst]) if (d[f->dst] > e.weight + f->weight) {
            d[f->dst] = e.weight + f->weight;
            Q.push(Edge(f->src, f->dst, e.weight + f->weight));
        }
    }
    ll l = 0; // forward dijkstra-like method
    priority_queue<Edge> R; R.push(Edge(-1,s,0));
    while (!R.empty()) {
        Edge e = R.top(); R.pop();
        if (e.dst == t && ++l == k) return e.weight + d[s];
        FOR(f, g[e.dst])
            R.push(Edge(f->src, f->dst, e.weight+f->weight-d[f->src]+d[f->dst]));
    }
    return -1; // not found
}

// Prim
// O(E log V)
// 
// 与えられるgは無向グラフ
pair<Weight, Edges> minimumSpanningTree(const Graph &g, ll r = 0) {
    ll n = g.size();
    Edges T;
    Weight total = 0;

    vector<bool> visited(n);
    priority_queue<Edge> Q;
    Q.push( Edge(-1, r, 0) );
    while (!Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (visited[e.dst]) continue;
        T.push_back(e);
        total += e.weight;
        visited[e.dst] = true;
        FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
    }
    return pair<Weight, Edges>(total, T);
}

struct UnionFind {
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) { }
    bool unionSet(ll x, ll y) {
        x = root(x); y = root(y);
        if (x != y) { if (data[y] < data[x]) swap(x, y); data[x] += data[y]; data[y] = x; }
        return x != y;
    }
    bool findSet(ll x, ll y) { return root(x) == root(y); }
    ll root(ll x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    ll size(ll x) { return -data[root(x)]; }
};

// Kruskal
// O(E log V + A(r) E)
pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
    ll n = g.size();
    UnionFind uf(n);
    priority_queue<Edge> Q;
    rep(u, n) FOR(e, g[u]) if (u < e->dst) Q.push(*e);

    Weight total = 0;
    Edges F;
    while (F.size() < n-1 && !Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (uf.unionSet(e.src, e.dst)) {
            F.push_back(e);
            total += e.weight;
        }
    }
    return pair<Weight, Edges>(total, F);
}



// Cuninghame-Green
Weight minimumDiameterSpanningTree(const Graph &g) {
    ll n = g.size();
    Matrix dist(n, Array(n, INF)); // all-pair shortest
    rep(u, n) dist[u][u] = 0;
    rep(u, n) FOR(e, g[u]) dist[e->src][e->dst] = e->weight;
    rep(k, n) rep(i, n) rep(j, n)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    Edges E;
    rep(u, n) FOR(e, g[u]) if (e->src < e->dst) E.push_back(*e);
    ll m = E.size();

    Weight H = INF;
    vector<Weight> theta(m);
    rep(r, m) {
        ll u = E[r].src, v = E[r].dst;
        Weight d = E[r].weight;
        rep(w, n) theta[r] = max(theta[r], min(dist[u][w], dist[v][w]));
        H = min(H, d + 2 * theta[r]);
    }
    Weight value = INF;
    rep(r, m) if (2 * theta[r] <= H) {
        ll u = E[r].src, v = E[r].dst;
        Weight d = E[r].weight;
        vector< pair<Weight,Weight> > list;
        rep(w, n) list.push_back( make_pair(dist[u][w], dist[v][w]) );
        sort(all(list), greater< pair<Weight,Weight> >());
        ll p = 0;
        value = min(value, 2 * list[0].first);
        rep(k, n) if (list[p].second < list[k].second)
            value = min(value, d + list[p].second + list[k].first), p = k;
        value = min(value, 2 * list[p].second);
    }
    return n == 1 ? 0 : value;
}

// Chu-Liu/Edmond
// O(VE)
void visit(Graph &h, ll v, ll s, ll r,
        vector<ll> &no, vector< vector<ll> > &comp,
        vector<ll> &prev, vector< vector<ll> > &next, vector<Weight> &mcost,
        vector<ll> &mark, Weight &cost, bool &found) {
    if (mark[v]) {
        vector<ll> temp = no;
        found = true;
        do {
            cost += mcost[v];
            v = prev[v];
            if (v != s) {
                while (comp[v].size() > 0) {
                    no[comp[v].back()] = s;
                    comp[s].push_back(comp[v].back());
                    comp[v].pop_back();
                }
            }
        } while (v != s);
        FOR(j,comp[s]) if (*j != r) FOR(e,h[*j])
            if (no[e->src] != s) e->weight -= mcost[ temp[*j] ];
    }
    mark[v] = true;
    FOR(i,next[v]) if (no[*i] != no[v] && prev[no[*i]] == v)
        if (!mark[no[*i]] || *i == s)
            visit(h, *i, s, r, no, comp, prev, next, mcost, mark, cost, found);
}
Weight minimumSpanningArborescence(const Graph &g, ll r) {
    const ll n = g.size();
    Graph h(n);
    rep(u,n) FOR(e,g[u]) h[e->dst].push_back(*e);

    vector<ll> no(n);
    vector< vector<ll> > comp(n);
    rep(u, n) comp[u].push_back(no[u] = u);

    for (Weight cost = 0; ;) {
        vector<ll> prev(n, -1);
        vector<Weight> mcost(n, INF);

        rep(j,n) if (j != r) FOR(e,g[j])
            if (no[e->src] != no[j])
                if (e->weight < mcost[ no[j] ])
                    mcost[ no[j] ] = e->weight, prev[ no[j] ] = no[e->src];

        vector< vector<ll> > next(n);
        rep(u,n) if (prev[u] >= 0)
            next[ prev[u] ].push_back(u);

        bool stop = true;
        vector<ll> mark(n);
        rep(u,n) if (u != r && !mark[u] && !comp[u].empty()) {
            bool found = false;
            visit(h, u, u, r, no, comp, prev, next, mcost, mark, cost, found);
            if (found) stop = false;
        }
        if (stop) {
            rep(u,n) if (prev[u] >= 0) cost += mcost[u];
            return cost;
        }
    }
}


Weight minimum_steiner_tree(const vector<ll>& T, const Matrix &g) {
    const ll n = g.size();
    const ll numT = T.size();
    if (numT <= 1) return 0;

    Matrix d(g); // all-pair shortest
    for (ll k = 0; k < n; ++k)
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < n; ++j)
                d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

    Weight OPT[(1 << numT)][n];
    for (ll S = 0; S < (1 << numT); ++S)
        for (ll x = 0; x < n; ++x)
            OPT[S][x] = INF;

    for (ll p = 0; p < numT; ++p) // trivial case
        for (ll q = 0; q < n; ++q)
            OPT[1 << p][q] = d[T[p]][q];

    for (ll S = 1; S < (1 << numT); ++S) { // DP step
        if (!(S & (S-1))) continue;
        for (ll p = 0; p < n; ++p)
            for (ll E = 0; E < S; ++E)
                if ((E | S) == S)
                    OPT[S][p] = min( OPT[S][p], OPT[E][p] + OPT[S-E][p] );
        for (ll p = 0; p < n; ++p)
            for (ll q = 0; q < n; ++q)
                OPT[S][p] = min( OPT[S][p], OPT[S][q] + d[p][q] );
    }
    Weight ans = INF;
    for (ll S = 0; S < (1 << numT); ++S)
        for (ll q = 0; q < n; ++q)
            ans = min(ans, OPT[S][q] + OPT[((1 << numT)-1)-S][q]);
    return ans;
}

/*
// !!!!!!!!!!!!!!!!!何故かコストがでかいとバグる
//
// 何故かEdmonds KarpもDinicもぶっ壊れている。何でだろう…
// https://beta.atcoder.jp/contests/arc085/submissions/1961687
// https://beta.atcoder.jp/contests/arc085/submissions/1961557
//

// Edmonds-Karp
// O(E^2 V)．以下の実装では内部で隣接行列を生成するため，O(V^2) の追加コスト
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlowEdmondsKarp(const Graph &g, ll s, ll t) {
    ll n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n));
    rep(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    while (1) {
        queue<ll> Q; Q.push(s);
        vector<ll> prev(n, -1); prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            ll u = Q.front(); Q.pop();
            FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                prev[e->dst] = u;
                Q.push(e->dst);
            }
        }
        if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
        Weight inc = INF;
        for (ll j = t; prev[j] != j; j = prev[j])
            inc = min(inc, RESIDUE(prev[j], j));
        for (ll j = t; prev[j] != j; j = prev[j])
            flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
        total += inc;
    }
}


// Dinic
// O(E V^2)なのだが、ランダムケースに対しては、2乗オーダーレベルにめちゃくちゃ速い。
// 逆に最悪ケースはめっちゃ遅い。
// 容量が整数以外の場合は無限ループに陥るケースが存在する
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight augment(const Graph &g, const Matrix &capacity, Matrix &flow,
        const vector<ll> &level, vector<bool> &finished, ll u, ll t, Weight cur) {
    if (u == t || cur == 0) return cur;
    if (finished[u]) return 0;
    finished[u] = true;
    FOR(e, g[u]) if (level[e->dst] > level[u]) {
        Weight f = augment(g, capacity, flow, level, finished,
                e->dst, t, min(cur, RESIDUE(u, e->dst)));
        if (f > 0) {
            flow[u][e->dst] += f; flow[e->dst][u] -= f;
            finished[u] = false;
            return f;
        }
    }
    return 0;
}
Weight maximumFlowDinic(const Graph &g, ll s, ll t) {
    ll n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n)); // adj. matrix
    rep(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    for (bool cont = true; cont; ) {
        cont = false;
        vector<ll> level(n, -1); level[s] = 0; // make layered network
        queue<ll> Q; Q.push(s);
        for (ll d = n; !Q.empty() && level[Q.front()] < d; ) {
            ll u = Q.front(); Q.pop();
            if (u == t) d = level[u];
            FOR(e, g[u]) if (RESIDUE(u,e->dst) > 0 && level[e->dst] == -1)
                Q.push(e->dst), level[e->dst] = level[u] + 1;
        }
        vector<bool> finished(n); // make blocking flows
        for (Weight f = 1; f > 0; ) {
            f = augment(g, capacity, flow, level, finished, s, t, INF);
            if (f == 0) break;
            total += f; cont = true;
        }
    }
    return total;
}


*/

/*
 * !!!!!!!!!!!!!!!!!これはそもそもセグフォる！！！！！！
 *
// Goldberg-Tarjan
// O(V^2 sqrt(E))
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
#define GLOBAL_RELABELING() { \
    queue<ll> Q; Q.push(t); \
    fill(all(d), INF); d[t] = 0; \
    while (!Q.empty()) { \
        ll u = Q.front(); Q.pop(); \
        FOR(e, g[u]) if (RESIDUE(e->dst, u) > 0 && d[u] + 1 < d[e->dst])  \
        Q.push(e->dst), d[e->dst] = d[u] + 1; \
    } \
}
#define PUSH(u, v) { \
    Weight delta = min(excess[u], RESIDUE(u, v)); \
    flow[u][v] += delta; flow[v][w] -= delta; \
    excess[u] -= delta; excess[v] += delta; }
Weight maximumFlowGoldbergTarjan(const Graph &g, ll s, ll t) {
    ll n = g.size(), count = 0;
    Matrix flow(n, Array(n)), capacity(n, Array(n)); // adj. matrix
    rep(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    vector<Weight> excess(n); excess[s] = INF; // initialize step
    vector<ll> d(n);
    GLOBAL_RELABELING();
    vector< queue<ll> > B(n); B[ d[s] ].push( s );

    for (ll b = d[s]; b >= 0; ) {
        if (B[b].empty()) { --b; continue; }
        ll v = B[b].front(); B[b].pop();
        if (excess[v] == 0 || v == t) continue;

        FOR(e, g[v]) {
            ll w = e->dst; // e is the current edge of v
            if (RESIDUE(v,w) > 0 && d[v] == d[w] + 1) { // (w,v) is admissible
                PUSH(v, w);
                if (excess[w] > 0 && w != t) B[d[w]].push( w );
            }
        }
        if (excess[v] == 0) continue;
        d[v] = n;
        FOR(e, g[v]) if (RESIDUE(v, e->dst) > 0)
            d[v] = min(d[v], d[e->dst] + 1);
        if (d[v] < n) B[b = d[v]].push(v);

        if (++count % n == 0) GLOBAL_RELABELING(); // !!HEURISTICS
    }
    return excess[t];
}

*/

// Nagamochi-Ibaraki
// O(V^3), 本当はO(VE + V log V)
Weight minimumCut(const Graph &g) {
    ll n = g.size();
    vector< vector<Weight> > h(n, vector<Weight>(n)); // make adj. matrix
    rep(u,n) FOR(e,g[u]) h[e->src][e->dst] += e->weight;
    vector<ll> V(n); rep(u, n) V[u] = u;

    Weight cut = INF;
    for(ll m = n; m > 1; m--) {
        vector<Weight> ws(m, 0);
        ll u, v;
        Weight w;
        rep(k, m) {
            u = v; v = max_element(ws.begin(), ws.end())-ws.begin();
            w = ws[v]; ws[v] = -1;
            rep(i, m) if (ws[i] >= 0) ws[i] += h[V[v]][V[i]];
        }
        rep(i, m) {
            h[V[i]][V[u]] += h[V[i]][V[v]];
            h[V[u]][V[i]] += h[V[v]][V[i]];
        }
        V.erase(V.begin()+v);
        cut = min(cut, w);
    }
    return cut;
}



// Gomory-Hu 木
// O(V MAXFLOW)
#undef RESIDUE
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Graph cutTree(const Graph &g) {
    ll n = g.size();
    Matrix capacity(n, Array(n)), flow(n, Array(n));
    rep(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

    vector<ll> p(n), prev;
    vector<Weight> w(n);
    for (ll s = 1; s < n; ++s) {
        ll t = p[s]; // max-flow(s, t)
        rep(i,n) rep(j,n) flow[i][j] = 0;
        Weight total = 0;
        while (1) {
            queue<ll> Q; Q.push(s);
            prev.assign(n, -1); prev[s] = s;
            while (!Q.empty() && prev[t] < 0) {
                ll u = Q.front(); Q.pop();
                FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                    prev[e->dst] = u;
                    Q.push(e->dst);
                }
            }
            if (prev[t] < 0) goto esc;
            Weight inc = INF;
            for (ll j = t; prev[j] != j; j = prev[j])
                inc = min(inc, RESIDUE(prev[j], j));
            for (ll j = t; prev[j] != j; j = prev[j])
                flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
            total += inc;
        }
esc:w[s] = total; // make tree
    rep(u, n) if (u != s && prev[u] != -1 && p[u] == t)
        p[u] = s;
    if (prev[p[t]] != -1)
        p[s] = p[t], p[t] = s, w[s] = w[t], w[t] = total;
    }
    Graph T(n); // (s, p[s]) is a tree edge of weight w[s]
    rep(s, n) if (s != p[s]) {
        T[  s ].push_back( Edge(s, p[s], w[s]) );
        T[p[s]].push_back( Edge(p[s], s, w[s]) );
    }
    return T;
}
// Gomory-Hu tree を用いた最大流 O(n)
Weight maximumFlowGomoryHu(const Graph &T, ll u, ll t, ll p = -1, Weight w = INF) {
    if (u == t) return w;
    Weight d = INF;
    FOR(e, T[u]) if (e->dst != p)
        d = min(d, maximumFlowGomoryHu(T, e->dst, t, u, min(w, e->weight)));
    return d;
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


// 最小共通先祖 Tarjan 
// 構築O(E A(V))、参照O(1)、のはずだがなぜかクエリ数にものすごく依存してる…
struct Query {
    ll u, v, w;
    Query(ll u, ll v) : u(u), v(v), w(-1) { }
};
void visitTarjan(const Graph &g, ll u, ll w,
        vector<Query> &qs, vector<ll> &color,
        vector<ll> &ancestor, UnionFind &uf) {
    ancestor[ uf.root(u) ] = u;
    FOR(e, g[u]) if (e->dst != w) {
        visitTarjan(g, e->dst, u, qs, color, ancestor, uf);
        uf.unionSet( e->src, e->dst );
        ancestor[ uf.root(u) ] = u;
    }
    color[u] = 1;
    FOR(q, qs) {
        ll w = (q->v == u ? q->u : q->u == u ? q->v : -1);
        if (w >= 0 && color[w]) q->w = ancestor[ uf.root(w) ];
    }
}
void leastCommonAncestor(const Graph &g, ll r, vector<Query> &qs) {
    UnionFind uf(g.size());
    vector<ll> color(g.size()), ancestor(g.size());
    visitTarjan(g, r, -1, qs, color, ancestor, uf);
}



// 全頂点を根とした時の木の高さの最大値
// O(E)
Weight visitH(const Graph &g, Graph& T, ll i, ll j) {
    if (T[i][j].weight >= 0) return T[i][j].weight;
    T[i][j].weight = g[i][j].weight;
    ll u = T[i][j].dst;
    rep(k, T[u].size()) {
        if (T[u][k].dst == i) continue;
        T[i][j].weight = max(T[i][j].weight, visitH(g,T,u,k)+g[i][j].weight);
    }
    return T[i][j].weight;
}
vector<Weight> heightMax(const Graph& g) {
    const ll n = g.size();
    Graph T(g); // memoise on tree
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < T[i].size(); ++j)
            T[i][j].weight = -1;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < T[i].size(); ++j)
            if (T[i][j].weight < 0)
                T[i][j].weight = visitH(g, T, i, j);

    vector<Weight> ht(n); // gather results
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < T[i].size(); ++j)
            ht[i] = max(ht[i], T[i][j].weight);
    return ht;
}


// 木の直径
// O(E)
typedef pair<Weight, ll> Result;
Result visit(ll p, ll v, const Graph &g) {
    Result r(0, v);
    FOR(e, g[v]) if (e->dst != p) {
        Result t = visit(v, e->dst, g);
        t.first += e->weight;
        if (r.first < t.first) r = t;
    }
    return r;
}
Weight diameter(const Graph &g) {
    Result r = visit(-1, 0, g);
    Result t = visit(-1, r.second, g);
    return t.first; // (r.second, t.second) is farthest pair
}


// 有効オイラー路判定
// O(E)
void visitE(Graph& g, ll a, vector<ll>& path) {
    while (!g[a].empty()){
        ll b = g[a].back().dst;
        g[a].pop_back();
        visitE(g, b, path);
    }
    path.push_back(a);
}
bool eulerPath(Graph g, ll s, vector<ll> &path) {
    ll n = g.size(), m = 0;
    vector<ll> deg(n);
    rep(u, n){
        m += g[u].size();
        FOR(e, g[u]) --deg[e->dst]; //  in-deg
        deg[u] += g[u].size();      // out-deg
    }
    ll k = n - count(all(deg), 0);
    if (k == 0 || (k == 2 && deg[s] == 1)) {
        path.clear();
        visitE(g, s, path);
        reverse(all(path));
        return path.size() == m + 1;
    }
    return false;
}


// 無向オイラー路判定
// O(E)
void visitEWithoutDirection(const Graph &g, vector< vector<ll> > &adj, ll s, vector<ll> &path) {
    FOR(e, g[s]) if (adj[e->src][e->dst]) {
        --adj[e->src][e->dst];
        --adj[e->dst][e->src];
        visitEWithoutDirection(g, adj, e->dst, path);
    }
    path.push_back(s);
}
bool eulerPathWithoutDirection(const Graph &g, ll s, vector<ll> &path) {
    ll n = g.size();
    ll odd = 0, m = 0;
    rep(i, n) {
        if (g[i].size() % 2 == 1) ++odd;
        m += g[i].size();
    }
    m /= 2;
    if (odd == 0 || (odd == 2 && g[s].size() % 2 == 0)) {
        vector< vector<ll> > adj(n, vector<ll>(n));
        rep(u, n) FOR(e, g[u]) ++adj[e->src][e->dst];
        path.clear();
        visitEWithoutDirection(g, adj, s, path);
        reverse(all(path));
        return path.size() == m + 1;
    }
    return false;
}


// 無向中国人郵便配達問題
// O(o m log n + o^2 2^o), o=18が限度
Weight chinesePostman(const Graph &g) {
    Weight total = 0;
    vector<ll> odds;
    rep(u, g.size()) {
        FOR(e, g[u]) total += e->weight;
        if (g[u].size() % 2) odds.push_back(u);
    }
    total /= 2;
    ll n = odds.size(), N = 1 << n;
    Weight w[n][n]; // make odd vertices graph
    rep(u,n) {
        ll s = odds[u]; // dijkstra's shortest path
        vector<Weight> dist(g.size(), INF); dist[s] = 0;
        vector<ll>    prev(g.size(), -2);
        priority_queue<Edge> Q;
        Q.push( Edge(-1, s, 0) );
        while (!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            if (prev[e.dst] != -2) continue;
            prev[e.dst] = e.src;
            FOR(f,g[e.dst]) {
                if (dist[f->dst] > e.weight+f->weight) {
                    dist[f->dst] = e.weight+f->weight;
                    Q.push(Edge(f->src, f->dst, e.weight+f->weight));
                }
            }
        }
        rep(v,n) w[u][v] = dist[odds[v]];
    }
    Weight best[N]; // DP for general matching 
    rep(S,N) best[S] = INF;
    best[0] = 0;

    for (ll S = 0; S < N; ++S)
        for (ll i = 0; i < n; ++i) if (!(S&(1<<i)))
            for (ll j = i+1; j < n; ++j) if (!(S&(1<<j)))
                best[S|(1<<i)|(1<<j)] = min(best[S|(1<<i)|(1<<j)], best[S]+w[i][j]);
    return total + best[N-1];
}



// 最短ハミルトン路
// O(V!) の計算量がかかるが，動的計画法に基づくアルゴリズムによって O(V^2 2^V) の計算量に軽減
// O(V^2 2^V), V=18が限度
const ll M = 20;
Weight best[1<<M][M];
ll    prev_[1<<M][M];
void buildPath(ll S, ll i, vector<ll> &path) {
    if (!S) return;
    buildPath(S^(1<<i), prev_[S][i], path);
    path.push_back(i);
}
Weight shortestHamiltonPath(Matrix w, ll s, vector<ll> &path) {
    ll n = w.size(); // 僕が追加
    ll N = 1 << n;
    rep(S,N) rep(i,n) best[S][i] = INF;
    best[1<<s][s] = 0;
    rep(S,N) rep(i,n) if (S&(1<<i)) rep(j,n)
        if (best[S|(1<<j)][j] > best[S][i] + w[i][j])
            best[S|(1<<j)][j] = best[S][i] + w[i][j],
                prev_[S|(1<<j)][j] = i;
    ll t = min_element(best[N-1], best[N-1]+n) - best[N-1];
    path.clear(); buildPath(N-1, t, path);
    return best[N-1][t];
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



// グラフの同型性判別
// 最悪O(V!)、ランダムグラフに対しては O(V log V)
typedef pair<ll, ll> VertexInfo;
#define index second
#define degree first
bool permTest(ll k, const Matrix &g, const Matrix &h,
        vector<VertexInfo> &gs, vector<VertexInfo> &hs) {
    const ll n = g.size();
    if (k >= n) return true;
    for (ll i = k; i < n && hs[i].degree == gs[k].degree; ++i) {
        swap(hs[i], hs[k]);
        ll u = gs[k].index, v = hs[k].index;
        for (ll j = 0; j <= k; ++j) {
            if (g[u][gs[j].index] != h[v][hs[j].index]) goto esc;
            if (g[gs[j].index][u] != h[hs[j].index][v]) goto esc;
        }
        if (permTest(k+1, g, h, gs, hs)) return true;
esc:swap(hs[i], hs[k]);
    }
    return false;
}
bool isomorphism(const Matrix &g, const Matrix &h) {
    const ll n = g.size();
    if (h.size() != n) return false;
    vector<VertexInfo> gs(n), hs(n);
    rep(i, n) {
        gs[i].index = hs[i].index = i;
        rep(j, n) {
            gs[i].degree += g[i][j];
            hs[j].degree += h[i][j];
        }
    }
    sort(all(gs)); sort(all(hs));
    rep(i, n) if (gs[i].degree != hs[i].degree) return false;

    return permTest(0, g, h, gs, hs);
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

int main(void)
{
    // 基本的な使い方
    // リスト表記
    {
        cout << "########Basic Usage" << endl;
        Graph g(6);
        //        Graph g; // 先に頂点数nで初期化しないとaddUndirectedとかできない
        addDirected(g, 0, 3);       // 有向辺。重みは自動で1に
        addDirected(g, 2, 3, 5);    // 有向辺。重みを明示的に指定
        addUndirected(g, 1, 4);     // 無向辺。重みは自動で1に
        addUndirected(g, 4, 2, 5);  // 無向辺。重みを明示的に指定
        //        addDirected(g, -1, 0) // 0未満を使ってはならない。
        //        addDirected(g, 0, 6) // サイズ以上を使ってはならない。
        printGraph(g);
    }

    // ワーシャルフロイド without 経路復元
    {
        cout << "########Warshall Floyd without inter" << endl;
        Matrix g; initFW(g, 3);
        g[0][1] = 3; g[1][2] = 4; g[0][2] = 1;

        Matrix dist;
        shortestPathFW(g, dist);
        cout << dist << endl;
    }

    // 強連結分解
    {
        cout << "########Strongly Connected Component" << endl;
        Graph g = Graph(6); // ちゃんとnで初期化しないとaddUndirectedとかできない
        addDirected(g, 0, 1), addDirected(g, 1, 2), addDirected(g, 2, 0); // 強連結
        addDirected(g, 2, 3);
        addDirected(g, 3, 4), addDirected(g, 4, 3); // 強連結
        addDirected(g, 4, 5);

        vector<vector<ll>> scc;
        stronglyConnectedComponents(g, scc);
        rep(i, scc.size()) {
            rep(j, scc[i].size()) cout << scc[i][j] << " ";
            cout << endl;
        }
    }

    // 二部マッチング
    {
        cout << "########Bipartite Matching" << endl;
        Graph g;
        auto f = [&](int i, int j) { 
//            return (i == 0 && j == 0) || (i == 2 && j == 1) || (i == 0 && j == 1);
            return (i == 0 && j == 0) || (i == 0 && j == 1);
        };
        int L = 3, R = 2;
        constructBiparitate(g, L, R, f);
        printGraph(g);

        Edges matching;
        int ret = bipartiteMatching(g, L, matching);
        cout << ret << endl;
    }

    // トポロジカルソート成功例
    {
        cout << "########Topological Sort" << endl;
        Graph g = Graph(6);
        addDirected(g, 4, 2);
        addDirected(g, 5, 0);
        addDirected(g, 2, 0);
        addDirected(g, 0, 3);
        addDirected(g, 5, 3);
        addDirected(g, 3, 1);

        vector<ll> order;
        topologicalSort(g, order);
        cout << order << endl;
    }

    // トポロジカルソート成功例
    {
        cout << "########Topological Sort (Failure)" << endl;
        Graph g = Graph(3);
        addDirected(g, 0, 1);
        addDirected(g, 1, 2);
        addDirected(g, 2, 0);

        vector<ll> order;
        bool success = topologicalSort(g, order);
        if (success) 
            cout << order << endl;
        else 
            cout << "NOT DAG" << endl;
    }

    // SCCからのDAG構成からのトポロジカルソート
    // 0 -> 2  ->  1 -> 4
    //       <- 3 <-
    //          |
    //          5 -> 6
    {
        cout << "########Topological Sort (Failure)" << endl;
        Graph g = Graph(7);
        addDirected(g, 0, 2);
        addDirected(g, 2, 1);
        addDirected(g, 1, 3);
        addDirected(g, 3, 5);
        addDirected(g, 3, 2);
        addDirected(g, 1, 4);
        addDirected(g, 5, 6);

        // ループを潰すための前処理
        vector<vector<ll>> scc;
        stronglyConnectedComponents(g, scc);
        rep(i, scc.size()) {
            rep(j, scc[i].size()) cout << scc[i][j] << " ";
            cout << endl;
        }

        // 各頂点が、どのSCCに属しているか
        vector<ll> scc_inv(g.size());
        rep(i, scc.size()) rep(j, scc[i].size()) scc_inv[scc[i][j]] = i;
        cout << scc_inv << endl;

        // 新しいDAGのグラフ作成
        // グラフdagの頂点iは、実際には(vector<ll> scc[i])たちを表している。
        Graph dag(scc.size());
        rep(from, g.size()) rep(to, g[from].size()) if (scc_inv[from] != scc_inv[g[from][to].dst]) {
            addDirected(dag, scc_inv[from], scc_inv[g[from][to].dst]);
        }
        printGraph(dag);

        vector<ll> order;
        bool success = topologicalSort(dag, order);
        if (success) 
            cout << order << endl;
        else 
            cout << "NOT DAG" << endl; // 絶対DAGになるはず！
    }

    {
        cout << "########Ford Fullkerson" << endl;
        Graph g = Graph(5);
        addDirected(g, 0, 1, 0, 10);
        addDirected(g, 0, 3, 0, 2);
        addDirected(g, 1, 2, 0, 6);
        addDirected(g, 1, 3, 0, 6);
        addDirected(g, 2, 3, 0, 3);
        addDirected(g, 2, 4, 0, 8);
        addDirected(g, 3, 4, 0, 5);
        FordFulkerson ff(g, 0, 4);
        cout << ff.get() << endl;
    }
   
    {
        cout << "########Ford Fullkerson (Dynamic)" << endl;
        Graph g = Graph(3);
        addDirected(g, 0, 1, 0, 10);
        addDirected(g, 1, 2, 0, 2);
        FordFulkerson ff(g, 0, 2); 
        printGraphCap(ff.g);
        cout << ff.get() << endl; // 1-2が2で少ないので、2が答え
        cout << ff.add(0, 2, 6) << endl; // 0-1-2は2で、0-2が6なので、8が答え
        printGraphCap(ff.g);
        cout << ff.erase(0, 2, 1) << endl;
        printGraphCap(ff.g);
        cout << ff.erase(0, 2, 5) << endl;
        cout << ff.erase(0, 2, 1) << endl; // 削除しすぎても自動的にクリップする

        cout << ff.add(1, 2, 6) << endl; 
    }
    {
        cout << "########Ford Fullkerson (Dynamic)" << endl;
        Graph g = Graph(2);
        addDirected(g, 0, 1, 0, 1);
        FordFulkerson ff(g, 0, 1); 
        cout << ff.erase(0, 1, 1) << endl; 
    }
    {
        cout << "########Ford Fullkerson (Dynamic)" << endl;
        Graph g = Graph(2);
        addDirected(g, 0, 1, 0, 1);
        addDirected(g, 1, 0, 0, 1);
        FordFulkerson ff(g, 0, 1); 
        printGraphCap(ff.g);
        cout << ff.erase(0, 1, 1) << endl; 
        printGraphCap(ff.g);
        cout << ff.erase(1, 0, 1) << endl; 
        printGraphCap(ff.g);
        cout << ff.add(0, 1, 1) << endl; 
        cout << ff.add(1, 0, 1) << endl; 
    }

    {
        cout << "########Primal Dual" << endl;
        // https://www.msi.co.jp/nuopt/docs/v18/examples/html/02-08-00.html
        Graph g(6);
        addDirected(g, 0, 1, 250, 4);
        addDirected(g, 0, 2, 200, 6);
        addDirected(g, 1, 3, 270, 5);
        addDirected(g, 2, 3, 300, 4);
        addDirected(g, 2, 4, 220, 3);
        addDirected(g, 3, 5, 190, 8);
        addDirected(g, 4, 5, 170, 3);

        // 8だけ流す。もし全力で流すなら、8のかわりにINF
        // 
        // 答えは5260
        pair<Weight, Weight> ret = minimumCostFlow(g, 0, 5, 8); 
        cout << ret << endl;
    }

}
