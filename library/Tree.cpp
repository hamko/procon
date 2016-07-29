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
// できること
//
// 木の重心を求める O(n)
// 最短パスの頂点に乗った群データの積分 O(n)
// 頂点から根までの頂点の二分探索 O(log n)
// 頂点からn個親の頂点jを知る O(log n)
// 頂点iからn個親の頂点jまでの、辺の積分を知る O(log n)


// データ型T, 単位元T0, 二項演算子opが与えられた時、
// 点更新opをO(log n)、0-indexの範囲sum(int j)をO(log n)で実現
// もしopに逆演算が定義できるならば、i-indexの範囲sum(int i, int j)が実現可能。

// 0-indexed, sumは閉区間なので注意！！

void printBit(int a) {cout << a << " "; for(; a > 0; a >>= 1) cout << (a & 1); cout << "#bit" << endl;}
template <class T>
struct fenwick_tree {
    /**********************/
    // 実装箇所
    /**********************/
    T T0 = 0;
    T op(T a, T b) { return a + b; }
    /**********************/
    // 実装終わり
    /**********************/

    // xのデータ構造。op=+, invop=1, T=int, T0=0の場合
    // iが最右添字な数字列をs[i]として、x[i] = s[i]の総和 (例: i=5, s[i]="45", x[i]=9)
    // 0123456789ABCDEF
    // 01234567--------
    // 0123----89AB----
    // 01--23--89--CD--
    // 0-2-4-6-8-A-C-E-
    int n_org;
    vector<T> x;
    fenwick_tree(int n_)  { 
        n_org = n_;
        int n = 1; while (n <= n_) n *= 2;
        x = vector<T>(n, T0);
    }
    fenwick_tree(void) {}

    // 範囲クエリ: [0, j]のreduceを行う。閉区間に注意
    // O(log n)
    T query(int j) {
        T S = T0;
        for (; j >= 0; j = (j & (j + 1)) - 1)  // jは、C->B->7と遷移する。0からCをカバーするための数字列の添字へ飛ぶ
            S = op(S, x[j]); 
        return S;
    }

    // 更新クエリ: #kにaを右から演算する
    // O(log n)
    void update(int k, T a) {
        for (; k < x.size(); k |= k+1) // kは、C->D->Fと遷移する。Cをカバーする数字列全てに飛ぶ
            x[k] = op(x[k], a); 
    }

    // #kにアクセスする
    // O(log n)
    T access(int k) {
        return query(k) - (k ? query(k-1) : 0);
    }
    void print(void) {
        for (int i = 0; i < n_org; i++) 
            cout << access(i) << " ";
        cout << endl;
    }
    void print_raw(void) {
        for (int i = 0; i < x.size(); i++) 
            cout << x[i] << " ";
        cout << endl;
    }
};


// 静的木
//
// 構築O(n): オイラーツアー, 木の高さ, 祖先ダブリング
//
// LCA O(log n)
// 頂点間最小辺数 O(log n)
// 頂点から根までのパスの二分探索 O(log n)
struct edge_t { int from, to; ll weight; };
using verticle_t = ll;
class Tree {
public:
    int MAXLOGV = 25;
    vector<verticle_t> m_verticles; 
    vector<vector<edge_t>> m_edges; // m_edges[i][j]が存在: i->jの辺が存在
    int vn; // 頂点の数, vn<2^MAXLOGV
    int root; // 根ノードの番号

    vector<vector<int>> parent; // parent[i][j]: jのi^2番目の親。j=0で直近の親。
    vector<int> depth; // depth[i]: 頂点iの根からの深さ, 根が0

    vector<int> m_euler; // 根から始めるオイラーツアー、長さvn*2
    fenwick_tree<verticle_t> m_euler_verticles_positive; // 1回目で+, 2回目で+になる頂点に載ったデータ, 長さvn*2
    fenwick_tree<verticle_t> m_euler_verticles_negative; // 1回目で+, 2回目で-になる頂点に載ったデータ, 長さvn*2
    vector<int> m_euler_appears_first; // f[i] = eulerでiが出てくる1回目の位置, 長さvn
    vector<int> m_euler_appears_second; // f[i] = eulerでiが出てくる2回目の位置, 長さvn

    /*********/
    // 構築
    /*********/
    Tree(int vn, int root) : vn(vn), root(root) {
        MAXLOGV = ceil(log(vn) / log(2)) + 2; // +2は念の為
        cout << MAXLOGV << "#MAXLOGV" << endl;
        parent.resize(MAXLOGV);
        m_edges.resize(vn);
        m_verticles.resize(vn);
        for (int i = 0; i < MAXLOGV; i++) 
            parent[i].resize(vn);
        depth.resize(vn);
        m_euler_verticles_positive = fenwick_tree<verticle_t>(vn*2);
        m_euler_verticles_negative = fenwick_tree<verticle_t>(vn*2);
    }

    // 辺の構築
    void unite(edge_t e) {
        m_edges[e.from].push_back({e.from, e.to, e.weight});
        m_edges[e.to].push_back({e.to, e.from, e.weight});
    }
    void unite(int u, int v) {
        unite({u, v, 1});
    }

    // 頂点の構築
    void setVerticle(int i, verticle_t v) {
        m_verticles[i] = v;
    }

    // rootからの深さと親を確認。
    // uniteし終わったらまずこれを呼ぶこと。
    void init() {
        m_euler.clear(); m_euler.reserve(2 * vn);
        m_euler_appears_first.clear(); m_euler_appears_first.resize(vn);
        m_euler_appears_second.clear(); m_euler_appears_second.resize(vn);
        dfs(root, -1, 0);
        for (int k = 0; k+1 < MAXLOGV; k++) // 2^k代祖先を計算
            for (int v = 0; v < vn; v++) 
                if (parent[k][v] < 0) 
                    parent[k+1][v] = -1; // 2^k代の親が根を超えてるなら、2^(k+1)代の親ももちろん根を超えている
                else 
                    parent[k+1][v] = parent[k][parent[k][v]]; // 2^(k+1)代の親は、2^k代の親の2^k代の親。

        // eulerのためのデータ用意
        rep(i, vn) { 
            m_euler_verticles_negative.update(m_euler_appears_first[i], +m_verticles[i]);
            m_euler_verticles_negative.update(m_euler_appears_second[i], -m_verticles[i]);
            m_euler_verticles_positive.update(m_euler_appears_first[i], +m_verticles[i]);
            m_euler_verticles_positive.update(m_euler_appears_second[i], +m_verticles[i]);
        }
    }

    // 1つ親と深さとオイラーツアーを構築
    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        m_euler_appears_first[v]=m_euler.size();
        m_euler.push_back(v);
        for (edge_t next : m_edges[v]) 
            if (next.to != p)
                dfs(next.to, v, d+1);
        m_euler_appears_second[v]=m_euler.size();
        m_euler.push_back(v);
    }
    
    // 木の直径を求める
    // 辺が重み付きでもOK!
    //
    // O(V)
    ll diameter(void) {
        using Result = pair<ll, int>;
        function<Result(int, int)> visit = [&](int p, int v){ 
            Result r(0, v);
            for (auto e : m_edges[v]) if (e.to != p) {
                Result t = visit(v, e.to);
                t.first += e.weight;
                if (r.first < t.first) r = t;
            }
            return r;
        };

        Result r = visit(-1, 0);
        Result t = visit(-1, r.second);

        // このあと、r, tからの距離を使って木の中心を求めることができる。O(V)
        // t.firstが偶数なら、rからt.first/2かつtからt.first/2の距離
        // t.firstが偶数なら、rからt.first/2+1or+0かつtからt.first/2+1or+0の距離の二点
        
        return t.first; // (r.second, t.second) is farthest pair
    }

    /*********/
    // クエリ
    /*********/
    // 頂点u, vの最小共通先祖
    //
    // O(log n)
    int getParent(int index, ll n) const {
        ll ret = index;
        n = min(n, (1ll << MAXLOGV) - 1);
        rep(k, MAXLOGV) if (n & (1ll << k)) {
            ret = parent[k][ret];
        }
        return ret;
    }

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
    // 距離はエッジの重み=1としたときのもの
    //
    // O(log n)
    int dist(int u, int v) const {
        int p = lca(u, v);
        return (depth[u]-depth[p]) + (depth[v]-depth[p]);
    }

    // uを根とする部分木に含まれる頂点全ての総和を求める。
    //
    // O(log n)
    // 制約: 頂点のデータが群
    verticle_t accumulateSubTree(int u) {
        return m_euler_verticles_positive.query(m_euler_appears_second[u]) -
            m_euler_verticles_positive.query(m_euler_appears_first[u] - 1);
    }

    // u, vのパスの頂点に乗ったデータの総和を求める。
    //
    // O(log n)
    // 制約: 頂点のデータが群
    // 制約: u is parent of v !!!
    verticle_t accumulateMinimumLengthPathParentAndChild(int u, int v) {
        return m_euler_verticles_negative.query(m_euler_appears_first[v])
            - m_euler_verticles_negative.query(m_euler_appears_first[u] - 1);
    }

    // u, vの最短パスの頂点に乗ったデータの総和を求める。
    //
    // O(log n)
    // 制約: 頂点のデータが群
    verticle_t accumulateMinimumLengthPath(int u, int v) {
        int lca_v = lca(u, v); 
        return accumulateMinimumLengthPathParentAndChild(lca_v, u) 
            + accumulateMinimumLengthPathParentAndChild(lca_v, v);
    }

#if 0 // not yet
    // uを根とする部分木に含まれる頂点全ての最小値を求める。
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    //
    // セグ木で持てば解決
    verticle_t minSubTree(int u) {
        return m_euler_verticles_positive_segment_tree.query(m_euler_appears_first[u], m_euler_appears_second[u] + 1);
    }

    // uを根とする部分木に含まれる頂点全てにwを足す。
    //
    // O(log n)
    // 制約: 頂点のデータがモノイド
    //
    // 遅延セグ木で持てば解決
    verticle_t minSubTree(int u) {
        return m_euler_verticles_positive_segment_tree.query(m_euler_appears_first[u], m_euler_appears_second[u] + 1);
    }

    // u, vのパスの頂点に乗ったデータの最小値を求める。
    //
    // O(log n)
    // 制約: 頂点のデータが群
    // 制約: u is parent of v !!!
    //
    // 群じゃないので、オイラーツアーでは無理！
    // ダブリングを使って実装する必要あり？
    verticle_t minMinimumLengthPathParentAndChild(int u, int v) {
        return m_euler_verticles_negative.query(m_euler_appears_first[v])
            - m_euler_verticles_negative.query(m_euler_appears_first[u] - 1);
    }

#endif

    // [root, v]のうち、fを満たす最も根側のノードを返す
    // 1つも満たさないなら-1を返す。
    //
    // O(log n)
    // 制約: 特性関数は、根から見て000000111111の形
    int binary_search(int v, function<bool(int)> f) const {
        for(int j = MAXLOGV - 1; j >= 0;j--) 
            if(parent[j][v] != -1 && f(parent[j][v]))
                v = parent[j][v];
        return f(v) ? v : -1;
    }

    // 木の構造描画
    void print_dfs(int v, int p) const {
        for (int i = 0; i < depth[v]; i++)
            cout << " ";
        cout << v << endl;
        for (edge_t next : m_edges[v]) if (next.to != p) 
            print_dfs(next.to, v);
    }
    void print(void) const {
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

      0
    1   2
  3    4 5
 */
int main() {
    int n; cin >> n;
    Tree tree(n, 0/*root*/);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        tree.unite(x, y);
    }
    for (int i = 0; i < n; i++) {
        tree.setVerticle(i, i);
    }
    tree.init();

    tree.print();
    cout << tree.parent << endl;
    cout << tree.m_euler << endl;
    cout << tree.m_euler_appears_first << endl;
    cout << tree.m_euler_appears_second << endl;

    cout << "Binary Search" << endl;
    cout << tree.binary_search(5, [&](int v){ return tree.m_verticles[v] > 1; }) << endl;
    cout << tree.binary_search(5, [&](int v){ return tree.m_verticles[v] > 6; }) << endl;

    cout << "Parent" << endl;
    cout << tree.getParent(3, 1) << endl;
    cout << tree.getParent(3, 2) << endl;
    cout << tree.getParent(3, 29) << endl;

    cout << "Accumulate SubTree" << endl;
    cout << tree.accumulateSubTree(0) << endl;
    cout << tree.accumulateSubTree(1) << endl;
    cout << tree.accumulateSubTree(2) << endl;

    cout << "Accumulate Minimum Length Path" << endl;
    cout << tree.accumulateMinimumLengthPath(0, 3) << endl;
    cout << tree.accumulateMinimumLengthPath(2, 5) << endl;
    cout << tree.accumulateMinimumLengthPath(0, 4) << endl;
    cout << tree.accumulateMinimumLengthPath(3, 5) << endl;

    cout << "Diameter" << endl;
    cout << tree.diameter() << endl;

    /*
       int Q; cin >> Q;
       for (int i = 0; i < Q; i++) {
       int a, b; cin >> a >> b;
       cout << tree.dist(a, b) + 1 << endl;
       }
       */
    return 0;
}
