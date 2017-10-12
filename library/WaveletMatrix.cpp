// 重要！！！！！！！！！！！！
// 何故か配列じゃないと動かないので、必ず使うときには配列に移してから使うこと！！
// v.data()みたいなのではバグる！！！！！！TODO なおす
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
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); return s; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
template <typename T,typename U> class umap:public std::unordered_map<T,U,myhash::myhash<T>> { public: using MAP=std::unordered_map<T,U,myhash::myhash<T>>; umap():MAP(){MAP::rehash(myhash::Bsizes[rand()%20]);} };    

struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); srand((unsigned int)time(NULL)); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 
#define double long double

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
#define ENABLE_SUM
template<class T, int N, int D> class wavelet {
    int n, zs[D];
    FID<N> dat[D];
public:
#ifdef ENABLE_SUM
    T raw_data[D+1][N] = {};
    T sum_data[D+1][N+1] = {};
    wavelet(int n, T seq[]) : n(n) {
        T l[N] = {}, r[N] = {};
        bool b[N] = {};
        memcpy(raw_data[0], seq, sizeof(T)*n);
        for (int d = 0; d < D; d++) {
            int lh = 0, rh = 0;
            for (int i = 0; i < n; i++) {
                b[i] = (raw_data[d][i]>>(D-d-1))&1;
                if(b[i]) r[rh++] = raw_data[d][i];
                else l[lh++] = raw_data[d][i];
            }
            dat[d] = FID<N>(n,b);
            zs[d] = lh;
            swap(l,raw_data[d+1]);
            memcpy(raw_data[d+1]+lh, r, rh*sizeof(T));
        }
        rep(d, D+1) rep(i, N) sum_data[d][i+1] = sum_data[d][i] + raw_data[d][i];
    }
    // 深さdでの列の[l, r)での累積和を求める
    T getSum(int d, int l, int r) {
        return sum_data[d][r] - sum_data[d][l];
    }
     // get sum of elements in [l,r) in [a,b)
    // O(log m)
    T sum_dfs(int d, int l, int r, T val, T a, T b) {
        // Wavelet Matrixの深さdで、
        // [l, r)が[val, nv) = [val, val+(1ll<<(D-d)))の値域を表現している時、
        // [a, b)の値域のものの和は？

        if(l == r) return 0; // valは無いので0を返す
        if(d == D) return (a <= val and val < b)? (r-l)*val: 0; // 深さDでは全部の値が同じなので、そのままかけて返す

        T nv = 1ULL<<(D-d-1)|val, nnv = ((1ULL<<(D-d-1))-1)|nv;
        if(nnv < a or b <= val) // どんなに1を選んでもaに満たなかったり、すでに最大を超えていたら0
            return 0; 
        if (a <= val and nnv < b) // これからどう選んでも a <= [l, r) < bの場合、累積和を返す
            return getSum(d, l, r); 

        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        return sum_dfs(d+1,l-lc,r-rc,val,a,b)+ sum_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);
    }
    T sum(int l, int r, T a, T b) { return sum_dfs(0,l,r,0,a,b); }
#else 
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
#endif
   void print(void) {
        rep(i, D) cout << zs[i] << " "; cout << endl;
        rep(i, D) dat[i].print();
        /*
        cout << "Raw" << endl;
        rep(d, D+1) { rep(i, N) cout << raw_data[d][i] << " "; cout << endl; }
        cout << "Sum" << endl;
        rep(d, D+1) { rep(i, N+1) cout << sum_data[d][i] << " "; cout << endl; }
        */
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
    int freq_dfs(int d, int l, int r, T val, T a, T b) {
        if(l == r) return 0;
        if(d == D) return (a <= val and val < b)? r-l: 0;
        T nv = 1ULL<<(D-d-1)|val, nnv = ((1ULL<<(D-d-1))-1)|nv;
        if(nnv < a or b <= val) return 0;
        if(a <= val and nnv < b) return r-l;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        return freq_dfs(d+1,l-lc,r-rc,val,a,b)+
            freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);
    }
    int freq(int l, int r, T a, T b) { return freq_dfs(0,l,r,0,a,b); }


    // TODO
    // 普通に
    // https://www.slideshare.net/pfi/ss-15916040
    // rangemaxk, rangemink, prevvalue, nextvalue, intersectを実装するのが良さそう
};


int main(void) {
    {
        cout << "####FID" << endl;
        ll n = 1050;
        bool a[n]; rep(i, n) a[i] = i % 5;
        FID<2000> fid(n, a);
        rep(i, 12) cout << fid.count(1, i) << " "; cout << endl;

        fid.print();
    }
    {
        cout << "####Wavelet" << endl;
        const ll n = 8;
        ll a[n] = {1, 1, 2, 1, 1, 5, 8, 5};
        wavelet<ll, 20/*len*/, 5/*[0, 31)*/> w(n, a);
        w.print();
        cout << "at" << endl;
        rep(i, n) cout << w[i] << " "; cout << endl;
        cout << "count" << endl;
        rep(i, n) cout << w.count(1ll, i) << " "; cout << endl;
        cout << "select" << endl;
        rep(i, n) cout << w.select(1ll, i) << " "; cout << endl;
        cout << "rangemax" << endl;
        cout << w.rangemax(0, n, 2, 7) << endl;
        cout << "max, min" << endl;
        cout << w.max(2, 6) << endl;
        cout << w.min(2, 6) << endl;
        cout << "list maximum" << endl;
        rep(i, n+1) 
            cout << w.list_max(0, n, i) << endl;
        cout << "kth" << endl;
        rep(i, n) cout << w.quantile(0, n, i) << " "; cout << endl;
        cout << "freq" << endl;
        cout << w.freq(0, n, 2, 8) << endl;
        cout << "list_freq" << endl;
        cout << w.list_freq(0, n, 2, 8) << endl;

        cout << "sum" << endl; // ENABLE_SUMのdefineが必要。sumクエリはメモリをO(ND)とかなり使う。
        cout << w.sum(0, n, 2, 7) << endl;
        cout << w.sum(0, n, 2, 8) << endl;
        cout << w.sum(0, n, 2, 9) << endl;

        cout << "get_rect" << endl;
        // TODO
        
    }

    return 0;
}
