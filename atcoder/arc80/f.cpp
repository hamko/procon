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
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
template <typename T> ostream &operator<<(ostream &o, const priority_queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} o << endl; return o; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define rand randxor

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

/***********************/
// 共通部分
/***********************/
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long Weight;

struct Edge {
    ll src, dst;
    Weight weight; // 最小費用流ではcostの役割
    ll cap;
    ll rev; // 残余グラフの対応用
    bool rev_flag = false; // revなら1
    Edge(int src = 0, int dst = 0, int weight = 0, Weight cap = 1): 
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
            if (name_server.size()) {
                ofs << "    " << names[i] << " -> " << names[g[i][j].dst]; 
            } else {
                ofs << "    " << i << " -> " << g[i][j].dst; 
            }
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



/**********************************************************/
// 前処理なしの素数判定
/**********************************************************/
#define ull unsigned long long
// dla n < 2^32: inline ull mul(ull a, ull b, ull mod) { return (a*b) % mod; }
const int _k = 25; const ull _mask = (1<<_k)-1;
ull mul (ull a, ull b, ull mod) { // zaĹ‚: b, mod < 2^(64-_k)
    ull result = 0;
    while (a) {
        ull temp = (b * (a & _mask)) % mod;
        result = (result + temp) % mod;
        a >>= _k;
        b = (b << _k) % mod;
    }
    return result;
}
 
ull pow(ull a, ull w, ull mod) {
    ull res = 1;
    while (w){
        if (w&1) res = mul(res, a, mod);
        a = mul(a, a, mod);
        w /= 2;
    }
    return res;
}
 
bool primetest(ull n, int a) {
    if (a > n-1) return 1;
    ull d = n-1;
    int s = 0;
    while (!(d&1)) {
        d /= 2;
        s++;
    }
    ull x = pow(a, d, n);
    if (x == 1 || x == n-1) return 1;
    rep(i,s-1){
        x = mul(x, x, n);
        if (x == 1) return 0;
        if (x == n-1) return 1;
    }
    return 0;
}

bool isPrime(ull n) {
    if (n < 4) return n > 1;
    bool pr = n%2;
    if (n < (1LL << 32)) {
       for (int a : {2,7,61}) pr = pr && primetest(n,a);
    } else if (n < (1LL << 48)) {
       for (int a : {2,3,5,7,11,13,17}) pr = pr && primetest(n,a);
    } else {
       for (int a : {2,325,9375,28178,450775,9780504,1795265022}) pr = pr && primetest(n,a);
    }
    return pr;
}

ll cost(ll x, ll y) {
    if ((x - y) % 2 == 0) {
        return 2;
    } else if (isPrime(abs(x - y))) {
        return 1;
    } else {
        return 3;
    }
}

int main(void) {
    ll n; cin >> n;
    vll x(n); cin >> x;
    vll a;
    ll prev = -INF;
    rep(i, n) {
        if (x[i] != prev + 1) {
            a.pb(x[i]-1);
        }
        if (i == n-1 || x[i] + 1 != x[i+1]) {
            a.pb(x[i]);
        }
        prev = x[i];
    }
    sort(all(a));
//    cout << a << endl;

    n = a.size();
    Graph g = Graph(n+2);
    ll odd_num = 0, even_num = 0;
    rep(i, n) {
        if (a[i] % 2 == 0) {
            addDirected(g, i, n+1, 0, 1);
            even_num++;
        } else {
            addDirected(g, n, i, 0, 1);
            odd_num++;
        }
    }
    rep(i, n) rep(j, n) if (i != j && a[i] % 2 == 1 && a[j] % 2 == 0) if (cost(a[i], a[j]) == 1) {
        addDirected(g, i, j, 0, 1);
    }
//    vizGraph(g, 2);

    FordFulkerson ff(g, n, n+1);
    ll one = ff.get();
//    cout << one << endl;
//    vizGraph(ff.g, 2, "zanyo.png");

    even_num -= one;
    odd_num -= one;

    ll two = even_num / 2 + odd_num / 2;
    ll three = even_num % 2;

    cout << one + 2 * two + 3 * three << endl;


    return 0;
}
