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
    Edge(int src = 0, int dst = 0, int cap = 0, Weight cost = 0): // 最小費用流用
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
void addDirected(Graph& g, ll src, ll dst, Weight weight = 0, ll cap = 0) {
    assert(src < g.size() && src >= 0 && dst < g.size() && dst >= 0);
    Edge e = Edge(src, dst, weight);
    e.cap = cap;
    g[src].push_back(e); 
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
    addDirected(g, name_server[src], name_server[dst], weight, cap);
}

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
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    for(int h, w, c, m, nw, nc, nm; cin >> h >> w >> c >> m >> nw >> nc >> nm, h >= 0;){
        clearNameServer();
        vector<string> s;

        vll type = {h, w, c, m, 1, 1, 1};
        vector<string> tn = {"h", "w", "c", "m", "W", "C", "M"};
        rep(t, type.size()) rep(i, type[t])
            s.pb(tn[t] + "b" + to_string(i)); // buffer
        rep(t, type.size()) rep(i, type[t]) 
            s.pb(tn[t] + to_string(i));
        s.pb("s");
        s.pb("t");

        Graph g(constructNameServer(s));
        
        // バッファを全部つなぐ
        rep(t, 4) rep(i, type[t]) 
            addDirected(g, tn[t] + "b" + to_string(i), tn[t] + to_string(i), 0, 1);
        addDirected(g, "Wb0", "W0", 0, nw);
        addDirected(g, "Cb0", "C0", 0, nc);
        addDirected(g, "Mb0", "M0", 0, nm);

        for (auto x : {mt(w, "h", "wb"), mt(c, "w", "cb"), mt(m, "c", "mb")}) {
            rep(i, get<0>(x)) {
                ll a; cin >> a;
                rep(_, a) {
                    ll index; cin >> index; index--;
                    addDirected(g, get<1>(x) + to_string(index), get<2>(x) + to_string(i), 0, 1);
                }
            }
        }

        // 使わない前
        for (auto x : {mt(h, "h", "Wb0"), mt(w, "w", "Cb0"), mt(c, "c", "Mb0")}) rep(i, get<0>(x)) 
            addDirected(g, get<1>(x) + to_string(i), get<2>(x), 0, 1);
        // 使わない前
        for (auto x : {mt(c, "cb", "W0"), mt(m, "mb", "C0")}) rep(i, get<0>(x)) 
                addDirected(g, get<2>(x), get<1>(x) + to_string(i), 0, 1);

        // スタートからヒーロー
        rep(i, h) 
            addDirected(g, "s", "hb" + to_string(i), 0, 1);

        // メイジからゴール
        rep(i, m) 
            addDirected(g, "m" + to_string(i), "t", 0, 1);
        addDirected(g, "M0", "t", 0, nm);

        FordFulkerson ff(g, name_server["s"], name_server["t"]);
        cout << ff.get() << endl;
    }

    return 0;
}
