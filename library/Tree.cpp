#include <bits/stdc++.h>
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

// 静的木
class Tree {
public:
    static const int MAXLOGV = 25;
    vector<vector<int> > m_edges; // m_edges[i][j]が存在: i->jの辺が存在
    int vn; // 頂点の数, vn<2^MAXLOGV
    int root; // 根ノードの番号

    vector<vector<int>> parent; // parent[i][j]: jのi^2番目の親。j=0で直近の親。
    vector<int> depth; // depth[i]: 頂点iの根からの深さ, 根が0

    vector<int> euler; // 根から始めるオイラーツアー
    vector<int> f; // f[i] = eulerでiが出てくる1回目の位置
    vector<int> s; // f[i] = eulerでiが出てくる2回目の位置

    /*********/
    // 構築
    /*********/
    Tree(int vn, int root) : vn(vn), root(root) {
        parent.resize(MAXLOGV);
        m_edges.resize(vn);
        for (int i = 0; i < MAXLOGV; i++) parent[i].resize(vn);
        depth.resize(vn);
    }
    // 無向辺の構築
    // TODO parentは別途更新しているのだから、子供から親への辺はいらない
    void unite(int u, int v) {
        m_edges[u].push_back(v);
        m_edges[v].push_back(u);
    }
    // rootからの深さと親を確認。
    // uniteし終わったらまずこれを呼ぶこと。
    void init() {
        euler.clear(); euler.reserve(2 * vn);
        f.clear(); f.resize(vn);
        s.clear(); s.resize(vn);
        dfs(root, -1, 0);
        for (int k = 0; k+1 < MAXLOGV; k++) { // 2^k代祖先を計算
            for (int v = 0; v < vn; v++) {
                if (parent[k][v] < 0) parent[k+1][v] = -1; // 2^k代の親が根を超えてるなら、2^(k+1)代の親ももちろん根を超えている
                else parent[k+1][v] = parent[k][parent[k][v]]; // 2^(k+1)代の親は、2^k代の親の2^k代の親。
            }
        }
    }
    // 辿って親と深さを確認するだけ
    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        f[v]=euler.size();
        euler.push_back(v);
        for (int next : m_edges[v]) {
            if (next != p) dfs(next, v, d+1);
        }
        s[v]=euler.size();
        euler.push_back(v);
    }

    /*********/
    // クエリ
    /*********/
    // 頂点u, vの最小共通先祖
    //
    // O(log n)
    int lca(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v); // uのほうが浅くなるように
        for (int k = 0; k < MAXLOGV; k++)    // vをuと同じ深さまで遡る
            if ((depth[v] - depth[u])>>k & 1) 
                v = parent[k][v];
        if (u == v) return u;
        for (int k = MAXLOGV-1; k >= 0; k--) { // 行き過ぎないギリギリで遡る
            if (parent[k][u] == parent[k][v]) // 行き過ぎ
                continue; 
            u = parent[k][u];
            v = parent[k][v];
        }
        return parent[0][u];
    }
    // uとvの距離を求める
    // 距離はエッジの重みではなく、遷移回数で定義
    //
    // O(log n)
    int dist(int u, int v) const {
        int p = lca(u, v);
        return (depth[u]-depth[p]) + (depth[v]-depth[p]);
    }
    // [root, v]のうち、fを満たす最も根側のノードを返す。
    //
    // O(log n)
    // 1つも満たさないなら-1を返す。
    int binary_search(int v, function<bool(int)> f) {
        for(int j = MAXLOGV - 1; j >= 0;j--)
            if(parent[j][v] != -1 && f(parent[j][v])) 
                v = parent[j][v];
        return (f(v) ? v : -1);
    }
    // 木の構造描画
    void print_dfs(int v, int p) {
        for (int i = 0; i < depth[v]; i++)
            cout << " ";
        cout << v << endl;
        for (int next : m_edges[v]) if (next != p) 
            print_dfs(next, v);
    }
    void print(void) {
        print_dfs(root, -1);
    }

};

/*
  6
  0 1
  1 3
  0 2
  2 4
  2 5
 */
int main() {
    int n; cin >> n;
    Tree tree(n, 0/*root*/);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        tree.unite(x, y);
    }
    tree.init();

    tree.print();
    cout << tree.parent << endl;
    cout << tree.euler << endl;
    cout << tree.s << endl;
    cout << tree.f << endl;

    cout << tree.binary_search(5, [&](int v){ return v > 1; }) << endl;

    /*
       int Q; cin >> Q;
       for (int i = 0; i < Q; i++) {
       int a, b; cin >> a >> b;
       cout << tree.dist(a, b) + 1 << endl;
       }
       */
    return 0;
}
