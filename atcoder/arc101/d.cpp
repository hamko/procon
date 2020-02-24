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


/*****************/
// Dictionary
/*****************/
// Nはバケット数
template<int N> class FID {
    static const int bucket = 512, block = 16;
    // 整数iのpopcountをO(1)で求めるためのテーブル
    // popcount[i] = __builtin_popcount(i), i<65536
    static char popcount[];

    // B[i]: s[0:512*i)のビット1の総数
    int n, B[N/bucket+10];
    // bs[i]: s[16*i:16*(i+1)]のビット列そのもの
    unsigned short bs[N/block+10] = {};

    // b[i]: s[i/32*512:i/32*512+i%32*32)のビット1の総数 
    // bs[i]を512bitずつリセットしながら、累積和を取ってる感じ。
    unsigned short b[N/block+10] = {};

public:
    FID(){}
    FID(int n, bool s[]) : n(n) {
        if(!popcount[1]) for (int i = 0; i < (1<<block); i++) popcount[i] = __builtin_popcount(i);

        bs[0] = B[0] = b[0] = 0;
        for (int i = 0; i < n; i++) {
            if(i%block == 0) {
                bs[i/block+1] = 0;
                if(i%bucket == 0) {
                    B[i/bucket+1] = B[i/bucket];
                    b[i/block+1] = b[i/block] = 0;
                }
                else b[i/block+1] = b[i/block];
            }
            bs[i/block]   |= short(s[i])<<(i%block);
            b[i/block+1]  += s[i];
            B[i/bucket+1] += s[i];
        }
        if(n%bucket == 0) b[n/block] = 0;
    }

    // number of val in [0,r), O(1)
    // 大ブロックの累積和(512bit)+中ブロックの累積和(16bit)+「余り分に適切なbitmaskをかけてpopcount」
    int count(bool val, int r) { return val? B[r/bucket]+b[r/block]+popcount[bs[r/block]&((1<<(r%block))-1)]: r-count(1,r); }
    // number of val in [l,r), O(1)
    int count(bool val, int l, int r) { return count(val,r)-count(val,l); }

    // position of ith in val, 0-indexed, O(log n)
    // 範囲外を示していたら-1を返す
    int select(bool val, int i) {
        if(i < 0 or count(val,n) <= i) return -1;
        i++;
        int lb = 0, ub = n, md;
        while(ub-lb>1) {
            md = (lb+ub)>>1;
            if(count(val,md) >= i) ub = md;
            else lb = md;
        }
        return ub-1;
    }
    int select(bool val, int i, int l) { return select(val,i+count(val,l)); }
    bool operator[](int i) { return bs[i/block]>>(i%block)&1; }

    void print(void) {
        /*
        rep(i, 1+(N-1)/bucket) {
            cout << B[i] << " ";
        }
        cout << endl;
        rep(i, 1+(N-1)/block) {
            cout << b[i] << " ";
        }
        cout << endl;
        */
        rep(i, 1+(N-1)/block) {
            cout << bits_to_string(bs[i], (i != (N-1)/block ? 16 : N - (N-1)/block*block)) << " ";
        }
        cout << endl;
    }
};
template<int N> char FID<N>::popcount[1<<FID<N>::block];

/*****************/
// Wavelet Matrix
/*****************/
// 長さNで、値域[0, m=2^D)の整数を管理する
//#define ENABLE_SUM
template<class T, int N, int D> class wavelet {
    int n, zs[D];
    FID<N> dat[D];
public:
    wavelet(int n, T seq[]) : n(n) {
        T f[N], l[N], r[N];
        bool b[N];
        memcpy(f, seq, sizeof(T)*n);
        for (int d = 0; d < D; d++) {
            int lh = 0, rh = 0;
            for (int i = 0; i < n; i++) {
                bool k = (f[i]>>(D-d-1))&1;
                if(k) r[rh++] = f[i];
                else l[lh++] = f[i];
                b[i] = k;
            }
            dat[d] = FID<N>(n,b);
            zs[d] = lh;
            swap(l,f);
            memcpy(f+lh, r, rh*sizeof(T));
        }
    }
   void print(void) {
        rep(i, D) cout << zs[i] << " "; cout << endl;
        rep(i, D) dat[i].print();
    }

    // get, []: i番目の要素
    // O(1)
    T get(int i) {
        T ret = 0;
        bool b;
        for (int d = 0; d < D; d++) {
            ret <<= 1;
            b = dat[d][i];
            ret |= b;
            i = dat[d].count(b,i)+b*zs[d];
        }
        return ret;
    }
    T operator[](int i) { return get(i); }

    // rank: 区間[0,r)にあるvalの個数
    // O(log m)
    int count(T val, int l, int r) {
        for (int d = 0; d < D; d++) {
            // ここで[l, r)にxのd桁目までが全て入っていることを保証(d>0)
            bool b = (val>>(D-d-1))&1;
            l = dat[d].count(b,l)+b*zs[d];
            r = dat[d].count(b,r)+b*zs[d];
        }
        return r-l;
    }
    int count(T val, int r) { return count(val,0,r); }

    // select: i番目のvalの位置
    // O(log m log log m)
    int select(T val, int k) {
        int ls[D], rs[D], l = 0, r = n;
        for (int d = 0; d < D; d++) {
            ls[d] = l; rs[d] = r;
            bool b = val>>(D-d-1)&1;
            l = dat[d].count(b,l)+b*zs[d];
            r = dat[d].count(b,r)+b*zs[d];
        }
        for (int d = D-1; d >= 0; d--) {
            bool b = val>>(D-d-1)&1;
            k = dat[d].select(b,k,ls[d]);
            if(k >= rs[d] or k < 0) return -1;
            k -= ls[d];
        }
        return k;
    }
    int select(T val, int k, int l) { return select(val,k+count(val,l)); }

    // maximum: 区間[l,r)で大きい順にk個
    // O(k log m)
    void list_max_dfs(int d, int l, int r, int &k, T val, vector<T> &vs) {
        if(l >= r or !k) return;
        if(d == D) {
            while(l++ < r and k > 0) vs.push_back(val), k--;
            return;
        }
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        // if min, change this order
        list_max_dfs(d+1, lc+zs[d], rc+zs[d], k, 1ULL<<(D-d-1)|val,vs);
        list_max_dfs(d+1, l-lc, r-rc, k, val, vs);
    }
    vector<T> list_max(int l, int r, int k) {
        if (r-l < k) k = r-l;
        if(k < 0) return {};
        vector<T> ret;
        list_max_dfs(0,l,r,k,0,ret);
        return ret;
    }

    // 添字[l, r)の要素で、値が[a, b)のもののうち最大値を求める
    // valは上からd bit決めて他0を埋めた時の値。
    //
    // O(log m)
    T rangemax_dfs(int d, int l, int r, T val, T a, T b) {
        if(r-l <= 0 or val >= b) return -1;
        if(d == D) return val>=a? val: -1;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        T ret = rangemax_dfs(d+1, lc+zs[d], rc+zs[d], 1ULL<<(D-d-1)|val, a, b);
        if(~ret) return ret; // 1側を見て見つかったならそれに越したことはない
        return rangemax_dfs(d+1, l-lc, r-rc, val, a, b); // なければ0側を見る
    }
    T rangemax(int l, int r, T a, T b) { return rangemax_dfs(0,l,r,0,a,b); }

    // k is 0-indexed!!!!
    // quantile: 区間[l,r)でk番目に大きい数
    // O(log m)
    T quantile(int l, int r, int k) {
        if(r-l <= k or k < 0) return -1;
        T ret = 0;
        for (int d = 0; d < D; d++) {
            int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
            // lc - rc = [l, r)で立っている1の数
            if(rc-lc > k) { // 1の数にkが収まっていれば
                l = lc+zs[d], r = rc+zs[d]; // 1側に遷移
                ret |= 1ULL<<(D-d-1);
            } else { // 0側ならば
                k -= rc-lc; // 1側にあった数だけkを削って次へ
                l -= lc, r -= rc;
            }
        }
        return ret;
    }
    T min(int l, int r) { return quantile(l, r, 0); }
    T max(int l, int r) { return quantile(l, r, r-l-1); }

    // freq_list: 区間[l,r)で値が[lb,ub)になる値とその出現回数の組のリスト
    // O(k log m), kはヒット数
    void list_freq_dfs(int d, int l, int r, T val, T a, T b, vector<pair<T,int>> &vs) {
        if(val >= b or r-l <= 0) return;
        if(d == D) {
            if(a <= val) vs.push_back(make_pair(val,r-l));
            return;
        }
        T nv = val|(1LL<<(D-d-1)), nnv = nv|(((1LL<<(D-d-1))-1));
        if(nnv < a) return;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        list_freq_dfs(d+1,l-lc,r-rc,val,a,b,vs);
        list_freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b,vs);
    }
    vector<pair<T,int>> list_freq(int l, int r, T a, T b) {
        vector<pair<T,int>> ret;
        list_freq_dfs(0,l,r,0,a,b,ret);
        return ret;
    }

    // get_rect: 区間[l,r)で値が[lb,ub)になる要素の位置とその値の組(つまり矩形内にある点の座標)のリスト
    // O(k log m), kはヒット数
    vector<pair<int,T>> get_rect(int l, int r, T a, T b) {
        vector<pair<T,int>> res = list_freq(l,r,a,b);
        vector<pair<int,T>> ret;
        for(auto &e: res)
            for (int i = 0; i < e.second; i++)
                ret.push_back(make_pair(select(e.first,i,l), e.first));
        return ret;
    }

    // number of elements in [l,r) in [a,b)
    // O(log m)
    ll freq_dfs(int d, int l, int r, T val, T a, T b) {
        if(l == r) return 0;
        if(d == D) return (a <= val and val < b)? r-l: 0;
        T nv = 1ULL<<(D-d-1)|val, nnv = ((1ULL<<(D-d-1))-1)|nv;
        if(nnv < a or b <= val) return 0;
        if(a <= val and nnv < b) return r-l;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        return freq_dfs(d+1,l-lc,r-rc,val,a,b)+
            freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);
    }
    ll freq(int l, int r, T a, T b) { return freq_dfs(0,l,r,0,a,b); }


    // TODO
    // 普通に
    // https://www.slideshare.net/pfi/ss-15916040
    // rangemaxk, rangemink, prevvalue, nextvalue, intersectを実装するのが良さそう
};


// データ型T, 単位元T0, 可換二項演算子opが与えられた時、
//
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

    // 範囲クエリ: [0, j]のreduceを行う。閉区間に注意
    // O(log n)
    T query(int j) {
        T S = T0;
        for (j; j >= 0; j = (j & (j + 1)) - 1)  // jは、C->B->7と遷移する。0からCをカバーするための数字列の添字へ飛ぶ
            S = op(S, x[j]); 
        return S;
    }

    // 更新クエリ: #kにaを演算する
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
// 数列aの中で、全ての(i, j)ペア（ただしi<j）のうち、
// a[i] <= a[j]なる個数を数え上げる
//
// オーバーフロー対策はされていないので、必ず確認すること
//
// O(n log n)
ll countLR(vll a) {
    ll n = a.size();
    vector<P> ai(n);
    rep(i, n) {
        ai[i] = P(a[i], i);
    }
    sort(all(ai));

    fenwick_tree<ll> c(n);
    ll ret = 0;
    rep(i, n) {
        ret += c.query(ai[i].se-1); // オーバーフロー注意！！
        c.update(ai[i].se, 1);
    }

    return ret;
}



int main(void) {
    ll n; cin >> n;
    vll x(n); cin >> x;

    ll ng = 0, ok = 2e9;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;

        vll a(n); rep(i, n) a[i] = x[i] <= mid;
        vll as(n+1); rep(i, n) as[i+1] = as[i] + a[i];
        vll b(n+1); rep(i, n+1) b[i] = 0;  rep(i, n+1) b[i] = 2ll * as[i] - i;
        rep(i, n+1) b[i] += 100010;
        /*
        wavelet<ll, 100010, 30> w(n+1, b);
        ll cnt = 0;
        rep(i, n) {
            cnt += w.freq(i+1, n+1, b[i]+1, 1e7);
        }
//        cout << cnt << endl;
        */
        fenwick_tree<ll> c(300030);
        ll cnt = 0;
        rep(i, n+1) {
            cnt += c.query(b[i] - 1);
            c.update(b[i], 1);
        }

        if (cnt >= n*(n+1ll)/2ll/2ll+1) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
}
