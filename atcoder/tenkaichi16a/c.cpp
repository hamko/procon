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
static const long long INF = 1e18;
static const long long mo = 1e9+7;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す
    int setNum(void) {
        map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
    // O(n)
    // 集合ごとに全部の要素を出力
    vector<vector<int>> getUnionList(void) {
        map<int, vector<int>> c;
        for (int i = 0; i < data.size(); i++) 
            c[root(i)].pb(i);
        vector<vector<int>> v;
        for (auto x : c) 
            v.push_back(x.second);
        return v;
    }
    void print(void) {
        auto c = getUnionList();
        for (auto x : c) {
            for (auto y : x) 
                cout << y << " ";
            cout << endl;
        }
    }
};

/***********************/
// 共通部分
/***********************/
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

typedef long long Weight;

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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    static vector<string> a(n), b(n);
    UnionFind uf(26);
    set<P> memo;
    vvll g(26, vll());
    Graph gscc = Graph(26); 
    rep(i, n) {
        cin >> a[i] >> b[i];
        bool hit = 0;
        rep(j, min(a[i].size(), b[i].size())) {
            if (a[i][j] != b[i][j]) {
                if (!memo.count(P(a[i][j], b[i][j]))) {
                    g[a[i][j]-'a'].pb(b[i][j]-'a');
                    addDirected(gscc, a[i][j]-'a', b[i][j]-'a');
                    uf.unite(a[i][j]-'a', b[i][j]-'a');
                    memo.insert(P(a[i][j], b[i][j]));
                }
                hit = 1;
                break;
            }
        }
        if (!hit && a[i].size() > b[i].size()) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 強連結分解
    {
        vector<vector<ll>> scc;
        stronglyConnectedComponents(gscc, scc);
        rep(i, scc.size()) {
            if (scc[i].size() > 1) {
                cout << -1 << endl;
                return 0;
            }
            /*
            rep(j, scc[i].size()) cout << scc[i][j] << " ";
            cout << endl;
            */
        }
    }


    /*

    rep(c, 26) {
        bool loop = 0;
        vll visited(26);
        function<void(ll)> visit = [&](ll v){
            if (visited[v]) {
                loop = 1;
                return;
            } else {
                visited[v] = 1;
            }
            for (auto&& dst : g[v]) {
                visit(dst);
            }
        };
        visit(c);
        if (loop) {
            cout << -1 << endl;
            return 0;
        }
    }
    */

    vector<queue<char>> cands;

    vector<vector<int>> dags = uf.getUnionList();
//    cout << dags << endl;
    for (auto&& dag : dags) {
        priority_queue<ll, vector<ll>, greater<ll>> q;

        vector<set<ll>> revdag(26);
        for (auto&& v : dag) {
            for (auto&& dst : g[v]) {
                revdag[dst].insert(v);
            }
        }

        vll done(26);
        for (auto&& v : dag) {
            if (revdag[v].empty()) {
                q.push(v);
                done[v] = 1;
            }
        }
        string s;
        while(!q.empty()) {
            ll v = q.top(); q.pop();
            s += ((char)v + 'a');
            rep(i, 26) {
                if (revdag[i].count(v))
                    revdag[i].erase(v);
            }
            for (auto&& dst : g[v]) if (!done[dst] && revdag[dst].empty()) {
                q.push(dst);
                done[v] = 1;
            }
        }
        //        cout << s << endl;

        queue<char> tmpq;
        rep(i, s.length()) {
            tmpq.push(s[i]);
        }
        cands.pb(tmpq);
    }

    string ret;
    while (ret.size() != 26) {
        ll m = INF;
        ll mi = -1;
        rep(i, cands.size()) if (!cands[i].empty()) {
            char c = cands[i].front();
            if (m > c) {
                m = c;
                mi = i;
            }
        }
        cands[mi].pop();
        //        cout << mi << " " << m << endl;
        ret += (char)m;
    }

    cout << ret << endl;

    return 0;
}
