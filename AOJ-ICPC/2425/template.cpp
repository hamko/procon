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

#define index(i, x, y) ((i)*(2*lx+1)*(2*ly+1)+(x+lx)*(2*ly+1)+(y+ly))
ll sx, sy, gx, gy; 
ll n; 
set<P> s;
ll lx, ly;
bool is_valid(ll x, ll y) {
    ll ynum = (2 * ly + 1) - abs(x);
    return (-lx <= x && x <= lx && -(ynum/2) <= y && y <= (ynum-1)/2);
}
int main(void) {
cin.tie(0); ios::sync_with_stdio(false);
    cin >> sx >> sy >> gx >> gy;
    cin >> n;
    rep(i, n) {
        ll x, y; cin >> x >> y;
        s.insert(P(x, y));
    }
    cin >> lx >> ly;

    vll dx = {0, 1, 1, 0, -1, -1, 0};
    vll dy_e = {1, 0, -1, -1, -1, 0, 0};
    vll dy_o = {1, 1, 0, -1, 0, 1, 0};
    static Graph g(6*(lx+lx+1)*(ly+ly+1));
    rep(t, 6) {
        ll nextt = (t+1) % 6;
        for (ll x = -lx; x <= lx; x++) {
            ll ynum = (2 * ly + 1) - abs(x);
            for (ll y = -(ynum / 2); y <= (ynum-1)/2; y++) {
                ll nocost = abs(x * y * t) % 6;
                rep(d, dx.size()) {
                    ll nextx, nexty;
                    nextx = x + dx[d];
                    if (x % 2) 
                        nexty = y + dy_o[d];
                    else 
                        nexty = y + dy_e[d];
                    if (!is_valid(nextx, nexty))
                        continue;
                    if (s.count(P(nextx, nexty)))
                        continue;
                    addDirected(g, index(t, x, y), index(nextt, nextx, nexty), d == nocost ? 0 : 1);
//                    cout << mt(t, x, y) << " " << mt(nextt, nextx, nexty) << " " << (d != nocost) << endl;
               }
            }
        }
    }

    vll dist, prev;
    shortestPathDI(g, index(0, sx, sy), dist, prev);

    ll ret = INF;
    rep(t, 6) {
        chmin(ret, dist[index(t, gx, gy)]);
    }
    cout << (ret == INF ? -1 : ret) << endl;

    return 0;
}
