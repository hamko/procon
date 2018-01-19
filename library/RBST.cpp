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

struct Node {
    ll Value;
    Node *Lch = NULL, *Rch = NULL;
    ll SubTreeSize;

    ll Sum, Min, Max;

    Node(ll V) : Value(V), SubTreeSize(1), Sum(V), Min(V), Max(V) {};
    inline ll size(void) { return SubTreeSize; }
    inline ll getSum(void) { return Sum; }
    inline ll getMin(void) { return Min; }
    inline ll getMax(void) { return Max; }

    inline Node *Update(void)
    {
        SubTreeSize = (Lch?Lch->size():0) + (Rch?Rch->size():0) + 1;
        Sum = (Lch?Lch->getSum():0) + (Rch?Rch->getSum():0) + Value;
        Min = min((Lch?Lch->getMin():+INF), min((Rch?Rch->getMin():+INF), Value));
        Max = max((Lch?Lch->getMax():-INF), max((Rch?Rch->getMax():-INF), Value));
        return this;
    }
};
inline int size(Node* t) { return t ? t->size() : 0; }

// 機能 1ノードの木を返す
// 引数 value: ノードの値
// 戻り値   木の根
inline Node *MakeRoot(ll value)
{
    return new Node(value);
}

// 機能   位置posに新しいノードを挿入(区間反転とかそういうときに使う)
//引数  root: 木の根
//pos: 挿入位置
//value: 挿入ノードの値
//戻り値    新しい木の根
Node *Merge(Node *l, Node *r)
{
    if(l == (Node *)NULL) return r;
    if(r == (Node *)NULL) return l;
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

// pair<Node*, Node*> Split(t, k)
// 機能 木tを [0,k)[k,n)で分割
// 引数 t: 木の根
// k: 分割位置
// 戻り値   分割後の双方の木の根
pair< Node*, Node* > Split(Node *t, ll k) // [0, k), [k, n)
{
    if(t == (Node *)NULL) return make_pair((Node *)NULL, (Node *)NULL);
    if(k <= size(t->Lch)) {
        pair< Node *, Node *> s = Split(t->Lch, k);
        t->Lch = s.second;
        return make_pair(s.first, t->Update());
    } else {
        pair< Node *, Node *> s = Split(t->Rch, k - size(t->Lch) - 1);
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
Node *Insert(Node *root, ll pos, ll value)
{
    Node *p = MakeRoot(value);
    pair< Node *, Node *> s = Split(root, pos);
    return Merge(Merge(s.first, p), s.second);
}

// 機能 pos番目のノードを削除
// 引数 root: 木の根
// pos: 削除位置
// 戻り値   新しい木の根
//
// a
//->a[0, pos) a[pos+1, n)
Node *Erase(Node *root, ll pos)
{
    pair< Node *, Node *> s = Split(root, pos);
    pair< Node *, Node *> t = Split(s.second, 1);
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
ll Lower_Bound(Node *root, ll Value)
{
    if(root == (Node *)NULL) return 0;
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
ll Upper_Bound(Node *root, ll Value)
{
    if(root == (Node *)NULL) return 0;
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
ll rLower_Bound(Node *root, ll Value)
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
ll rUpper_Bound(Node *root, ll Value)
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
Node *Insert(Node *root, ll Value)
{
    return Insert(root, Lower_Bound(root, Value), Value);
} 

ostream &operator<<(ostream &o, const Node* root) {
    if(root == (Node *)NULL) return o;
    o << "(";
    o << root->Lch;
    o << "" << root->Value << "";
    o << root->Rch;
    o << ")";
    return o;
}

// k-th number, sumなど高級な処理ができるset
struct Set {
    Node* s = NULL;
    bool isMultiset;
    Set(bool isMultiset_ = 0) : isMultiset(isMultiset_) { }
    // 集合のサイズ
    // O(1)
    int size(void) {
        return s ? s->size() : 0;
    }
    // vを追加する
    // O(log n)
    void insert(ll v) {
        if (isMultiset == 0 && count(v)) return;
        s = Insert(s, v);
    }
    // vを削除する
    // O(log n)
    void erase(ll v) {
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
    int count(ll v) {
        if (!s) return 0;
        ll pos = Lower_Bound(s, v);

        if (pos == size() || quantile(pos) != v) return 0; // vがない

        ll pos_next = Lower_Bound(s, v+1);
        if (isMultiset) {
            return pos_next - pos;
        } else {
            return 1;
        }
    }
    // 一番小さい値を取得
    // O(log n)
    ll front(void) {
        assert(s);
        auto p = Split(s, 1);
        ll ret = p.fi->Value;
        s = Merge(p.fi, p.se);
        return ret;
    }
    // 一番大きい値を取得
    // O(log n)
    ll back(void) {
        assert(s);
        auto p = Split(s, s->size()-1);
        ll ret = p.se->Value;
        s = Merge(p.fi, p.se);
        return ret;
    }
    // 小さい方からk番目を求める
    // 0-indexed
    // O(log n)
    ll quantile(ll k) { 
        assert(s);
        assert(k < s->size());
        if (k == 0) return front();
        if (k == s->size() - 1) return back();

        auto left = Split(s, k+1);
        auto right = Split(left.fi, k);
        // right.fi     [0, k)
        // right.se     [k, k+1)
        // left.se      [k+1, n)
        ll ret = right.se->Value;
        s = Merge(right.fi, right.se);
        s = Merge(s, left.se);
        return ret;
    }
    ll operator[](int k) { return quantile(k); };
    // 大きい方からk番目を求める
    // 0-indexed
    // O(log n)
    ll rquantile(ll k) { 
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
    ll lower_bound(ll v) { 
        return Lower_Bound(s, v);
    }
    // vより大きい最小の値をもつ位置
    // O(log n)
    ll upper_bound(ll v) { 
        return Upper_Bound(s, v);
    }
    // v以下の最大の値をもつ位置
    // O(log n)
    ll rlower_bound(ll v) { 
        return rLower_Bound(s, v);
    }
    // vより小さい最大の値をもつ位置
    // O(log n)
    ll rupper_bound(ll v) { 
        return rUpper_Bound(s, v);
    }

    // s[l, r)の合計を求める
    // （l番目に小さいものからr番目に小さいものまでを、半開区間で足し合わせる）
    // O(log n)
    ll sum(ll l, ll r) { 
        assert(0<=l&&l<=r&&r<size());
        if (l == r) return 0;
        auto x = Split(s, r);
        auto y = Split(s, l);
        ll ret = y.se->getSum();
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
ostream &operator<<(ostream &o, Set& s) {
    cout << "[";
    rep(i, s.size()) {
        cout << s[i] << (i != s.size() - 1 ? ", " : "");
    }
    cout << "]";
    return o;
}

int main(void) {
    // RBSTの基本操作
    {
        Node* a[10];

        cout << "########" << endl;
        rep(i, 10) a[i] = MakeRoot(i);
        rep(i, 10) cout << a[i] << " "; cout << endl;

        cout << "########" << endl;
        repi(i, 1, 10) 
            a[0] = Merge(a[0], a[i]);
        rep(i, 10) cout << a[i] << endl;

        cout << "######## lower bound" << endl;
        cout << Lower_Bound(a[0], 3) << endl;
        cout << Lower_Bound(a[0], 11) << endl;
        cout << rLower_Bound(a[0], 3) << endl;
        cout << rUpper_Bound(a[0], 3) << endl;
        cout << rUpper_Bound(a[0], -100) << endl;

        cout << "########" << endl;
        cout << a[0]->getSum() << " " << a[0]->getMin() << " " << a[0]->getMax() << endl;

        cout << "########" << endl;
        auto x = Split(a[0], 3);
        cout << x.fi << endl;
        cout << x.se << endl;
    }

    // 多機能set
    {
        Set s;

        s.insert(1);
        s.insert(2);
        s.insert(-100);
        cout << s << endl;

        cout << "# front" << endl;
        cout << s.front() << endl;

        // back
        cout << "# back" << endl;
        cout << s.back() << endl;

        // k-th number
        cout << "# k-th" << endl;
        cout << s.quantile(1) << endl;
        cout << s[1] << endl; // []はquantileと同義

        // pop_front
        cout << "# pop_front" << endl;
        s.pop_front();
        cout << s << endl;

        // pop_back
        cout << "# pop_back" << endl;
        s.pop_back();
        cout << s << endl;
        s.pop_back();
        cout << s << endl;

        // sを作りなおす
        s.clear();
        s.insert(1);
        s.insert(3);
        s.insert(4);
        s.insert(10);
        cout << s << endl;

        // count, lower_bound, upper_bound
        cout << "# count, lower_bound, upper_bound" << endl;
        rep(i, s.size()) cout << s.quantile(i) << " "; cout << endl;
        rep(i, 20) cout << s.lower_bound(i); cout << endl;
        rep(i, 20) cout << s.upper_bound(i); cout << endl; 
        rep(i, 20) cout << s.count(i); cout << endl;
        rep(i, 20) cout << s.rlower_bound(i); cout << endl;
        rep(i, 20) cout << s.rupper_bound(i); cout << endl; 

        // sum
        cout << s.sum(1, 3) << endl; // sum(3, 4)

        // clear
        s.clear();
        cout << s << endl;
    }

    {
        Set s(true);  // multiset
        rep(i, 10) {
            s.insert(i % 4);
        }
        cout << s << endl;
        cout << s.lower_bound(2) << endl;
        cout << s.upper_bound(2) << endl;
        cout << s.count(0) << endl;
        cout << s.count(1) << endl;
        cout << s.count(2) << endl;
        cout << s.count(3) << endl;
        cout << s.sum(4, 9) << endl;
    }

    {
        Set s(false);  // not multiset
        rep(i, 10) {
            s.insert(i % 4);
        }
        cout << s << endl;
        cout << s.lower_bound(2) << endl;
        cout << s.upper_bound(2) << endl;
    }

    return 0;
}
