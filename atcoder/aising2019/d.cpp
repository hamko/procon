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
ll ugauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return a/b; else return (a+(a>0?-1:1))/b+1; }
ll lgauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return (a+(a>0?-1:1))/b-1; else return a/b; }
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
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
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
    // a以上b未満の値の個数を求める
    // O(log n)
    ll rangefreq(ll a, ll b) { 
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
    // a以上b未満の値の個数を求める
    // O(log n)
    ll rangesum(ll a, ll b) { 
        auto l = Lower_Bound(s, a);
        auto r = Lower_Bound(s, b);
        if (l == r) return 0;
        auto x = Split(s, r);
        auto y = Split(x.fi, l);
        ll ret = y.se->getSum();
        s = Merge(y.fi, y.se);
        s = Merge(s, x.se);

        return ret;
    }


    // s[l, r)の合計を求める
    // （l番目に小さいものからr番目に小さいものまでを、半開区間で足し合わせる）
    // O(log n)
    ll rangesum_id(ll l, ll r) { 
        assert(0<=l&&l<=r&&r<size());
        if (l == r) return 0;
        auto x = Split(s, r);
        auto y = Split(x.fi, l);
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
Node* node[100010];

ll brutal(ll n, vll& a, ll x) {
    vll used(n);
    rep(i, n) {
        ll turn = i%2;
        if (turn == 0) {
            rep(jrev, n) {
                ll j = n - jrev - 1;
                if (used[j] == 0) {
                    used[j] = 1;
                    break;
                }
            } 
        } else {
            ll m = INF;
            ll mi = 0;
            rep(j, n) if (used[j] == 0) {
                if (m > abs(a[j] - x)) {
                    m = abs(a[j] - x);
                    mi = j;
                }
            }
            used[mi] = -1;
        }
    }
    ll ret = 0;
    rep(i, n) {
        if (used[i] == 1) {
            ret += a[i];
        }
    }
    return ret;
}
int main(void) {
    ll n, q; cin >> n >> q;
    vll a(n); cin >> a;
    vll aeven(n+1); 
    rep(i, n) aeven[i+1] = aeven[i] + (i % 2 == 0 ? a[i] : 0ll);
    vll aodd(n+1);
    rep(i, n) aodd[i+1] = aodd[i] + (i % 2 == 1 ? a[i] : 0ll);


    Set s;
    rep(i, n) s.insert(a[i]);
    rep(_, q) {
        ll x; cin >> x;
        ll ng = -1, ok = 1.1e9;
        ll aoki = -1, takahashi = -1;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2ll;
            ll s = lower_bound(all(a), x + mid) - a.begin();
            ll t = lower_bound(all(a), x - mid) - a.begin();
            aoki = s - t;
            takahashi = n - s;
//            aoki = s.rangefreq(x - mid, x + mid);
//            takahashi = s.rangefreq(x + mid, 2e9);
            if (aoki >= takahashi - 1) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        aoki = s.rangefreq(x - ok, x + ok);
        takahashi = s.rangefreq(x + ok, 2e9);
        if (aoki > takahashi) {
            ll ng = -1, ok = 1.1e9;
            while (ok - ng > 1) {
                ll mid = (ok + ng) / 2ll;

                ll s = lower_bound(all(a), x + mid + 1) - a.begin();
                ll t = lower_bound(all(a), x - mid) - a.begin();
                aoki = s - t;
                takahashi = n - s;
                if (aoki >= takahashi - 1) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }


        }
        /*
           rep(i, n) {
           if (x - ok <= a[i] && a[i] < x + ok) {
           cout << -1 << " ";
           } else if (x + ok <= a[i]) {
           cout << 1 << " ";
           } else {
           cout << 0 << " ";
           }
           }
           cout << endl;
           */
        ll ret = s.rangesum(x + ok, 2e9);
        ll rem = n - takahashi - aoki;
        /*
           cout << ret << endl;
           cout << rem << endl;
           */
        if ((rem + (takahashi - aoki)) % 2 == 1) {
            ret += aeven[rem];
        } else {
            ret += aodd[rem];
        }
        cout << ret << endl;
        /*
           if (brutal(n, a, x) != ret) {
           cout << "##########" << endl;
           cout << n << " " << a << endl;
           cout << x << endl;
           cout << brutal(n, a, x) << " " << ret << endl;
           }
           */
    }



    // ll rangefreq(ll a, ll b) { 

    return 0;
}
