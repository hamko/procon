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

// 平衡2D KDTree
//
// 木だが，回転操作は難しく、ゼロからバランスしたものを作るのはわりと楽なので、
// スケープゴート木（Scapegoat Tree）チックな平衡のとり方をする
// Overmars(1983)に載っている内容なので，歴史的にはScapegoat Tree(Andersson(1989), Galperin-Rivest(1993)) より古い
//
// 普通の平衡二分探索木は回転操作やマージ基準で平衡を保つものだけど，
// スケープゴート木は「平衡状態（log(木のサイズ)≒木の高さ）でなくなったら，ぶっ壊して再構築する」
// というアグレッシブな平衡化手法（rebuild）
//
// 平衡化を後回しにして要素の追加と削除をする。
const int D = 2;
struct kdTree {
    int removed = 0;
    int valid_size = 0;
    struct Node {
        int x, y;
        bool removed;
        Node *ch[2];
        int size, ht;
        Node(int x, int y) : x(x), y(y), removed(false) { ch[0] = ch[1] = 0; }
    } *r;

    kdTree(void) { r = NULL; }
    kdTree(int p[][2], int n) : removed(0) {
        Node *node[n];
        for (int i = 0; i < n; ++i) 
            node[i] = new Node(p[i][0], p[i][1]);
        r = build(node, node+n, 0);
    }

    // 注意！！このsizeはremovedを考慮していない！！
    // 実際のサイズを知りたいならば、valid_sizeをみること。
    int size(Node *t) { return t ? t->size : 0; }

    int ht(Node *t) { return t ? t->ht : 0; }
    Node *update(Node *t) {
        if (!t) return t;
        t->size = 1 + size(t->ch[0]) + size(t->ch[1]);
        t->ht = 1 + max(ht(t->ch[0]), ht(t->ch[1]));
        return t;
    }
    struct Compare {
        int d;
        Compare(int d) : d(d) { }
        bool operator()(Node *i, Node *j) {
            return d == 0 ? (i->x < j->x) : (i->y < j->y);
        }
    };
    Node *build(Node **b, Node **e, int d) {
        if (e - b <= 0) return 0;
        Node **m = b + (e - b) / 2;
        nth_element(b, m, e, Compare(d)); 
        (*m)->ch[0] = build(b, m, (d+1)%D);
        (*m)->ch[1] = build(m+1, e, (d+1)%D);
        return update(*m);
    }
    Node **flatten(Node *r, Node **buf) {
        if (!r) return buf;
        buf = flatten(r->ch[0], buf);
        if (!r->removed) *(buf++) = r;
        return flatten(r->ch[1], buf);
    }
    Node *rebuild(Node *r, int d) {
        Node *b[size(r)], **e = flatten(r, b);
        removed -= size(r) - (e - b);
        return build(b, e, d);
    }
    
    // 注意！こっちを直接叩くとvalid_sizeが更新できなくなるので、使わないこと！
    Node *insert(Node *t, Node *p, int d) {
        if (!t) return update(p);
        int b = !Compare(d)(p, t); 
        t->ch[b] = insert(t->ch[b], p, (d+1)%D);
        t = update(t);
        if (3 * log(size(t)) < ht(t)) t = rebuild(t, d);
        return t;
    }
    // (x, y)を追加する。
    // O(log n)
    void insert(int x, int y) { r = insert(r, new Node(x,y), 0); valid_size++; }

    Node *find(Node *t, Node *p, int d) {
        if (!t) return 0;
        Node *f = 0;
        if (!t->removed && t->x == p->x && t->y == p->y) f = t;
        if (!f && !Compare(d)(p,t)) f = find(t->ch[1], p, (d+1)%D);
        if (!f && !Compare(d)(t,p)) f = find(t->ch[0], p, (d+1)%D);
        return f;
    }
    // (x, y)があれば、そのノードを返す。なければNULLを返す
    // O(log n)
    Node *find(int x, int y) { 
        Node n(x, y); 
        return find(r, &n, 0); 
    }

    // fのノードを削除する、が、リビルドはしない。fがなければ何もしない。
    // すでに消されたfが入力されることもある。
    void remove_without_rebuild(Node *f) { 
        if (!f || f->removed) return;
        f->removed = true;
        ++removed;
        valid_size--;
    }
    // 平衡がある程度崩れていたら再構築する
    void conditional_rebuild(void) { 
        if (!r) return;
        if (removed*2 > r->size) r = rebuild(r, 0);
    }
    // fのノードを削除するして、必要ならばリビルドはしない。fがなければ何もしない。
    // すでに消されたfが入力されることもある。
    void remove(Node *f) { 
        if (!f) return;
        remove_without_rebuild(f);
        conditional_rebuild();
    }
    // (x, y)を削除する。
    // O(log n) amortized
    void remove(int x, int y) { 
        Node *f = find(x, y);
        remove(f);
    }

    // 閉区間[ld, ru]の点を全削除する
    // O(K log n) amortized Kは削除点数
    void range_remove(const P ld, const P ru) { 
        vector<Node*> to_delete;
        search(ld, ru, to_delete);
        for (auto x : to_delete) {
            remove_without_rebuild(x);
        }
        conditional_rebuild();
    }

    // 閉区間[ld, ru]の点を全列挙し、outに副作用で返す
    // O(log n + K) Kは全列挙結果数
    void search(const P &ld, const P &ru, vector<Node*>& out) {
        out.clear();
        Node n_ld(ld.fi, ld.se);
        Node n_ru(ru.fi, ru.se);
        search(r, 0, &n_ld, &n_ru, out);
    }
    void search(Node *t, int d, Node* n_ld, Node* n_ru, vector<Node*>& out) {
        if (t == NULL) return;
        if (n_ld->x <= t->x && t->x <= n_ru->x && n_ld->y <= t->y && t->y <= n_ru->y) 
            out.push_back(t);
        if (!Compare(d)(t,n_ld)) search(t->ch[0], !d, n_ld, n_ru, out);
        if (!Compare(d)(n_ru,t)) search(t->ch[1], !d, n_ld, n_ru, out);
    }
    // これが直感的な範囲検索
    void search(const P &ld, const P &ru, vector<P>& out) {
        out.clear();
        vector<Node*> ret;
        search(ld, ru, ret);
        out.resize(ret.size());
        rep(i, ret.size()) {
            out[i] = P(ret[i]->x, ret[i]->y);
        } 
    }

    void print_rec(Node* n) {
        if (!n) return;
        if (!n->removed) 
            cout << "(" << n->x << ", "  << n->y << "), ";
            
        print_rec(n->ch[0]);
        print_rec(n->ch[1]);
    }
    void print(void) {
        print_rec(r);
        cout << endl;
    }
};


int main(void) {
    kdTree kd;

    kd.insert(0, 1);
    kd.insert(2, 4);
    kd.insert(8, 5);
    kd.insert(7, 2);
    cout << kd.valid_size << endl;
    cout << !!kd.find(8, 5) << endl;
    cout << !!kd.find(8, 5) << endl;

    cout << !!kd.find(2, 4) << endl;
    kd.remove(2, 4);
    cout << !!kd.find(2, 4) << endl;

    vector<P> out;
    P ld = P(0, 1), ru = P(7, 7);
    kd.search(ld, ru, out);
    cout << out << endl;
    return 0;
}
