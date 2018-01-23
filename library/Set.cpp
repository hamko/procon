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
#define INF (ll)1e18
#define mo  (ll)(1e9+7)


uint64_t xor128(void) { 
    static uint64_t x = 123456789;
    static uint64_t y = 362436069;
    static uint64_t z = 521288629;
    static uint64_t w = 88675123; 
    uint64_t t;

    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

template <typename T>
struct Node {
    T Value;
    Node<T> *Lch = NULL, *Rch = NULL;
    ll SubTreeSize;

    Node(T V) : Value(V), SubTreeSize(1) {};
    inline ll size(void) { return SubTreeSize; }

    inline Node *Update(void)
    {
        SubTreeSize = (Lch?Lch->size():0) + (Rch?Rch->size():0) + 1;
        return this;
    }
};

template <typename T>
int size(Node<T>* t) { return t ? t->size() : 0; }

// 機能 1ノードの木を返す
// 引数 value: ノードの値
// 戻り値   木の根
template <typename T>
Node<T> *MakeRoot(T value)
{
    return new Node<T>(value);
}

// 機能   位置posに新しいノードを挿入(区間反転とかそういうときに使う)
//引数  root: 木の根
//pos: 挿入位置
//value: 挿入ノードの値
//戻り値    新しい木の根

template <typename T>
Node<T> *Merge(Node<T> *l, Node<T> *r)
{
    if(l == (Node<T> *)NULL) return r;
    if(r == (Node<T> *)NULL) return l;
    ll Left  = l->SubTreeSize;
    ll Right = r->SubTreeSize;
    if(xor128() % (Left + Right) < Left) {
        l->Rch = Merge(l->Rch, r);
        return l->Update();
    } else {
        r->Lch = Merge(l, r->Lch);
        return r->Update();
    }
}

// pair<Node<T>*, Node<T>*> Split(t, k)
// 機能 木tを [0,k)[k,n)で分割
// 引数 t: 木の根
// k: 分割位置
// 戻り値   分割後の双方の木の根
template <typename T>
pair< Node<T>*, Node<T>* > Split(Node<T> *t, ll k) // [0, k), [k, n)
{
    if(t == (Node<T> *)NULL) return make_pair((Node<T> *)NULL, (Node<T> *)NULL);
    if(k <= size(t->Lch)) {
        pair< Node<T> *, Node<T> *> s = Split(t->Lch, k);
        t->Lch = s.second;
        return make_pair(s.first, t->Update());
    } else {
        pair< Node<T> *, Node<T> *> s = Split(t->Rch, k - size(t->Lch) - 1);
        t->Rch = s.first;
        return make_pair(t->Update(), s.second);
    }
}

// 機能 位置posに新しいノードを挿入(区間反転とかそういうときに使う)
// 引数 root: 木の根
// pos: 挿入位置
// value: 挿入ノードの値
// 戻り値   新しい木の根
//
// a 
//->a[0, root) value a[root, n)
template <typename T>
Node<T> *Insert(Node<T> *root, ll pos, T value)
{
    Node<T> *p = MakeRoot(value);
    pair< Node<T> *, Node<T> *> s = Split(root, pos);
    return Merge(Merge(s.first, p), s.second);
}

// 機能 pos番目のノードを削除
// 引数 root: 木の根
// pos: 削除位置
// 戻り値   新しい木の根
//
// a
//->a[0, pos) a[pos+1, n)
template <typename T>
Node<T> *Erase(Node<T> *root, ll pos)
{
    pair< Node<T> *, Node<T> *> s = Split(root, pos);
    pair< Node<T> *, Node<T> *> t = Split(s.second, 1);
    delete t.first;
    return Merge(s.first, t.second);
}

// 機能 value 以上の最左位置を返す
//      もしそのようなものがなかった場合、rootのサイズを返す
// 引数 root: 木の根
// value: 検索値
// 戻り値   位置
//
// 列が単調になっている必要がある
template <typename T>
ll Lower_Bound(Node<T> *root, T Value)
{
    if(root == (Node<T> *)NULL) return 0;
    if(Value <= root->Value) return Lower_Bound(root->Lch, Value);
    return Lower_Bound(root->Rch, Value) + size(root->Lch) + 1;
}

// 機能 value より大きいものの最左位置を返す
//      もしそのようなものがなかった場合、0を返すので、あとで0以上かをチェック
// 引数 root: 木の根
// value: 検索値
// 戻り値   位置
//
// 列が単調になっている必要がある
template <typename T>
ll Upper_Bound(Node<T> *root, T Value)
{
    if(root == (Node<T> *)NULL) return 0;
    if(Value < root->Value) return Upper_Bound(root->Lch, Value);
    return Upper_Bound(root->Rch, Value) + size(root->Lch) + 1;
}

// 機能 value 以下の最右位置を返す
//      もしそのようなものがなかった場合、-1を返す
// 引数 root: 木の根
// value: 検索値
// 戻り値   位置
//
// 列が単調になっている必要がある
template <typename T>
ll rLower_Bound(Node<T> *root, T Value)
{
    ll ret = Upper_Bound(root, Value) - 1;
    return ret;
}

// 機能 value より小さいものの最右位置を返す
//      もしそのようなものがなかった場合、-1を返す
// 引数 root: 木の根
// value: 検索値
// 戻り値   位置
//
// 列が単調になっている必要がある
template <typename T>
ll rUpper_Bound(Node<T> *root, T Value)
{
    ll ret = Lower_Bound(root, Value) - 1;
    return ret;
}



// 機能 木に値 value のノードを挿入(setsetみたいに使いたいときに使う)
// 引数 root: 木の根
// value: 挿入値
// 戻り値   新しい木の根
//
// これのみを使っていると、列が単調になる
template <typename T>
Node<T> *Insert(Node<T> *root, T Value)
{
    return Insert(root, Lower_Bound(root, Value), Value);
} 

template <typename T>
ostream &operator<<(ostream &o, const Node<T>* root) {
    if(root == (Node<T> *)NULL) return o;
    o << "(";
    o << root->Lch;
    o << "" << root->Value << "";
    o << root->Rch;
    o << ")";
    return o;
}

// k-th numberなど高級な処理ができるset
template <typename T>
class Set {
public:
    Node<T>* s = NULL;
    bool isMultiset;
    Set(bool isMultiset_ = 0) : isMultiset(isMultiset_) { }
    // 集合のサイズ
    // O(1)
    int size(void) {
        return s ? s->size() : 0;
    }
    // vを追加する
    // O(log n)
    void insert(T v) {
        if (isMultiset == 0 && count(v)) return;
        s = Insert(s, v);
    }
    // vを削除する
    // O(log n)
    void erase(T v) {
        ll pos = Lower_Bound(s, v);
        if (pos == size() || quantile(pos) != v) assert(0); // 無いものは消せない

        s = Erase(s, pos);
    }
    // k番目に小さい値を削除する
    // O(log n)
    void erasePos(ll k) {
        assert(s);
        assert(k < size());
        s = Erase(s, k);
    }
    // vが何個setに入っているか？
    // O(log n)
    int count(T v) {
        if (!s) return 0;
        ll pos = Lower_Bound(s, v);

        if (pos == size() || quantile(pos) != v) return 0; // vがない

        ll pos_next = Upper_Bound(s, v);
        if (isMultiset) {
            return pos_next - pos;
        } else {
            return 1;
        }
    }
    // 一番小さい値を取得
    // O(log n)
    T front(void) {
        assert(s);
        auto p = Split(s, 1);
        T ret = p.fi->Value;
        s = Merge(p.fi, p.se);
        return ret;
    }
    // 一番大きい値を取得
    // O(log n)
    T back(void) {
        assert(s);
        auto p = Split(s, s->size()-1);
        T ret = p.se->Value;
        s = Merge(p.fi, p.se);
        return ret;
    }
    // 小さい方からk番目を求める
    // 0-indexed
    // O(log n)
    T quantile(ll k) { 
        assert(s);
        assert(k < s->size());
        if (k == 0) return front();
        if (k == s->size() - 1) return back();

        auto left = Split(s, k+1);
        auto right = Split(left.fi, k);
        // right.fi     [0, k)
        // right.se     [k, k+1)
        // left.se      [k+1, n)
        T ret = right.se->Value;
        s = Merge(right.fi, right.se);
        s = Merge(s, left.se);
        return ret;
    }
    T operator[](int k) { return quantile(k); };
    // 大きい方からk番目を求める
    // 0-indexed
    // O(log n)
    T rquantile(ll k) { 
        assert(s);
        assert(k < s->size());
        return quantile(s->size() - 1 - k);
    }
    // 一番小さい要素を削除
    // O(log n)
    void pop_front(void) {
        assert(s);
        s = Erase(s, 0);
    }
    // 一番大きい要素を削除
    // O(log n)
    void pop_back(void) {
        assert(s);
        s = Erase(s, s->size()-1);
    }
    // v以上の最小の値をもつ位置
    // O(log n)
    ll lower_bound(T v) { 
        return Lower_Bound(s, v);
    }
    // vより大きい最小の値をもつ位置
    // O(log n)
    ll upper_bound(T v) { 
        return Upper_Bound(s, v);
    }
    // v以下の最大の値をもつ位置
    // O(log n)
    ll rlower_bound(T v) { 
        return rLower_Bound(s, v);
    }
    // vより小さい最大の値をもつ位置
    // O(log n)
    ll rupper_bound(T v) { 
        return rUpper_Bound(s, v);
    }
    // a以上b未満の値の個数を求める
    // O(log n)
    ll rangefreq(T a, T b) { 
        auto l = Lower_Bound(s, a);
        auto r = Lower_Bound(s, b);
        if (l == r) return 0;
        auto x = Split(s, r);
        auto y = Split(x.fi, l);
        ll ret = ::size(y.se);
        s = Merge(y.fi, y.se);
        s = Merge(s, x.se);

        return ret;
    }

    // 全要素を削除する
    // O(n log n)
    void clear(void) {
        while (size()) pop_back();
    }
};
template <typename T>
ostream &operator<<(ostream &o, Set<T>& s) {
    cout << "[";
    rep(i, s.size()) {
        cout << s[i] << (i != s.size() - 1 ? ", " : "");
    }
    cout << "]";
    return o;
}


// 完全動的quantile, rangefreq, rangesum
// O(log^2 n)

int main(void) {
    // 雑抽象化平衡二分木
    {
        Set<P> s;
        s.insert(P(1, 2));
        s.insert(P(3, -2));
        s.insert(P(5, 8));
        s.insert(P(2, 9));
        s.insert(P(1, 3));
        cout << s << endl;
    }

    return 0;
}
