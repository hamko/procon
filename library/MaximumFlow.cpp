#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mo  (ll)(1e9+7)


/***********************/
// 共通部分
/***********************/
#define REP(i,n) for(long long i=0;i<(long long)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long Weight;
//const Weight INF = 1e18;
//const Weight EPS = 0; // 浮動小数点なら1e-14

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
//    cout << src << " " << dst << " " << weight << endl;
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
void vizGraph(Graph& g, ll mode = 0, ll directed = 1, string filename = "out.png") {
   
    ofstream ofs("./out.dot");
    ofs << (directed ? "di" : "") << "graph graph_name {" << endl;
    string arrow = (directed ? " -> " : " -- ");

    set<pair<ll, ll>> used;
    rep(i, g.size()) {
        if (!g[i].size())
            continue;
        rep(j, g[i].size()) {
            // 多重辺はないと前提
            if (used.count(pair<ll, ll>(g[i][j].src, g[i][j].dst))) continue;
            used.insert(pair<ll, ll>(g[i][j].src, g[i][j].dst));
            if (directed == 0) used.insert(pair<ll, ll>(g[i][j].dst, g[i][j].src));

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
void reverseGraph(Graph& g_dst, Graph& g_src) { /*g_dstは空graphを渡す*/ g_dst = Graph(g_src.size()); rep(i, g_src.size()) {
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
            f = augment(g, capacity, flow, level, finished, s, t, 2ll*INF);
            if (f == 0) break;
            total += f; cont = true;
        }
    }
    return total;
}

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

#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)
struct MaximumFlow {
	typedef int Index;
	typedef ll Flow;
	static constexpr Flow InfCapacity = INF;
	struct Edge {
		Index to;
		Flow capacity;
		Index rev;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = capacity;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	//gを破壊する
	Flow maximumFlow(int s, int t) {
		int n = g.size();
		vector<Index> level(n);
		Flow total = 0; bool update;
		do {
			update = false;
			fill(level.begin(), level.end(), -1); level[s] = 0;
			queue<Index> q; q.push(s);
			for (Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if (u == t) d = level[u];
				each(e, g[u]) if (e->capacity > 0 && level[e->to] == -1)
					q.push(e->to), level[e->to] = level[u] + 1;
			}
			vector<Index> iter(n);
			for (Index i = 0; i < n; i ++) iter[i] = (int)g[i].size() - 1;
			while (1) {
				Flow f = augment(level, iter, s, t, InfCapacity);
				if (f == 0) break;
				total += f; update = true;
			}
		} while (update);
		return total;
	}
	Flow augment(vector<Index> &level, vector<Index> &iter, Index u, Index t, Flow f) {
		if (u == t || f == 0) return f;
		Index lv = level[u];
		if (lv == -1) return 0;
		level[u] = -1;
		for (; iter[u] >= 0; -- iter[u]) {
			Edge &e = g[u][iter[u]];
			if (level[e.to] <= lv) continue;
			Flow l = augment(level, iter, e.to, t, min(f, e.capacity));
			if (l == 0) continue;
			e.capacity -= l; g[e.to][e.rev].capacity += l;
			level[u] = lv;
			return l;
		}
		return 0;
	}
};

int main(void) {
    ll n; cin >> n;
    vll a(n); cin >> a;
    ll src = n, dst = n+1;
    MaximumFlow mf;
    mf.init(n+2);

    ll base = 0;
    rep(i, n) { 
        ll x = i + 1;
        for (ll y = 2 * x; y <= n; y += x) {
            mf.add(i, y-1, INF);
        }
        base += max(a[i], 0ll);
        if (a[i] > 0) 
            mf.add(i, dst, a[i]);
        else 
            mf.add(src, i, -a[i]);
    }

//    vizGraph(g, 1);

    ll flow = mf.maximumFlow(src, dst);
    cout << base - flow << endl;


    return 0;
}

