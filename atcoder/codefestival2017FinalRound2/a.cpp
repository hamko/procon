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


// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
    rep(i,n) par[i] = i;
  }

  // データxが属する木の根を得る
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // データの根ノードを得る
    x = find(x);
    y = find(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  int size(int x) {
    return sizes[find(x)];
  }
};


// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge
{
  int a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  int n;  // 頂点数
  vector<Edge> es;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  int kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind uf(n);
    int min_cost = 0;

    rep(ei, es.size()) {
      Edge& e = es[ei];
      if (!uf.same(e.a, e.b)) {
        // 辺を追加しても閉路ができないなら、その辺を採用する
        min_cost += e.cost;
        uf.unite(e.a, e.b);
      }
    }

    return min_cost;
  }
};
struct UF {
    vector<int> data;
    UF(int size) : data(size, -1) { }
    // x, yをマージ, O(A^-1)
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1, O(A^-1)
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る, O(A^-1)
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す, O(A^-1)
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す, O(n)
    int getSetNum(void) {
        unordered_map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
    // 頂点vと連結な集合を返す, O(n)
    vector<int> getContainingSet(int v) {
        vector<int> ret;
        for (int i = 0; i < data.size(); i++) 
            if (root(i) == root(v))
                ret.push_back(i);
        return ret;
    }

    // 集合ごとに全部の要素を出力, O(n)
    vector<vector<int>> getUnionList(void) {
        map<int, vector<int>> c;
        for (int i = 0; i < data.size(); i++) 
            c[root(i)].pb(i);
        vector<vector<int>> v;
        for (auto x : c) 
            v.push_back(x.second);
        return v;
    }
};
ostream &operator<<(ostream &o, struct UF v) {  v.getUnionList(); int i = 0; for (auto x : v.getUnionList()) { o << i << "\t"; for (auto y : x) o << y << " "; o << endl; i++;} return o; }


// 標準入力からグラフを読み込む
Graph input_graph() {
  Graph g;
  int m;
  cin >> g.n >> m;
  ll k; cin >>k ;
  vll c(g.n); cin >> c;
  UF uf(g.n);
  rep(i, m) {
    Edge e;
    cin >> e.a >> e.b >> e.cost;
    e.a--, e.b--;
    uf.unite(e.a, e.b);
    g.es.push_back(e);
  }
  if (uf.size(0) != g.n)  {
      cout << -1 << endl;
      exit(0);
  }
  return g;
}


int main()
{
  Graph g = input_graph();
//  cout << "最小全域木のコスト: " << g.kruskal() << endl;
//  cout 
  cout << g.kruskal() << endl;
  return 0;
}
