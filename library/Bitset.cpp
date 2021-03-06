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

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
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
void vizGraph(vvll& g, int mode = 0, int directed = 1, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << (directed ? "di" : "") << "graph graph_name {"<<endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << (directed ? " -> " : " -- ") << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

// shiftを捨てることによる爆速bitset
// n=200000, q=200000で1000ms
//
// 速度優先でいろんなチェックとかしていないので注意
// ・ANDなどの二項演算におけるbit& bが自分自身だとバグるので例外処理必須
// ・複数オペレータを入れる場合には、できればなるべく関数を自前実装すること
// 　コンパイラ最適化で早くなる
// 　詳しくはOR_then_clear関数を参照
//
// 範囲AND, OR, XOR, flip, clear
// [l, r)は全て半開区間
// 全部O(n/w)
//
class bit {
    public:
        int len;
        long long* a;
        // i bit目は、a[i>>6]のi&63bit目
        bit(void) {
        }
        bit(int n) {
            resize(n);
        }
        void resize(ll n) {
            len = (n + 64 - 1) / 64;
            a = (long long*)malloc(sizeof(long long) * len);
            rep(i, len) {
                a[i] = 0;
            }
        }
        int count(void) {
            int ret = 0;
            for (int i = 0; i < len; i++) {
                ret += __builtin_popcountll(a[i]);
            }
            return ret;
        }
        // this[i] = b
        void set(int i, bool b) {
            a[i>>6] |= (ll)b << (i & 63);
        }
        // return this[i]
        bool get(int i) const {
            return a[i>>6] & (1ll << (i&63));
        }
        // this[0:n) = 0
        void clear(void) {
            rep(i, len) {
                a[i] = 0;
            }
        }
        // this[l:r) |= b[l:r)
        void OR(bit& b, int l, int r) {
            long long* that = b.a;
            while((l&63) && (l<r)) { 
                a[l>>6] |= that[l>>6] & (1ll<<(l&63)); 
                l++; 
            }
            while(l+64<=r) {
                a[l>>6] |= that[l>>6];
                l+=64;
            }
            while(l<r) {
                a[l>>6] |= that[l>>6] & (1ll<<(l&63)); 
                l++; 
            }
        }
        // this[l:r) &= b[l:r)
        void AND(bit& b, int l, int r) {
            long long* that = b.a;
            while((l&63) && (l<r)) { 
                a[l>>6] &= that[l>>6] & (1ll<<(l&63)); 
                l++; 
            }
            while(l+64<=r) {
                a[l>>6] &= that[l>>6];
                l+=64;
            }
            while(l<r) {
                a[l>>6] &= that[l>>6] & (1ll<<(l&63)); 
                l++; 
            }
        }
        // this[l:r) ^= b[l:r)
        void XOR(bit& b, int l, int r) {
            long long* that = b.a;
            while((l&63) && (l<r)) { 
                a[l>>6] ^= that[l>>6] & (1ll<<(l&63)); 
                l++; 
            }
            while(l+64<=r) {
                a[l>>6] ^= that[l>>6];
                l+=64;
            }
            while(l<r) {
                a[l>>6] ^= that[l>>6] & (1ll<<(l&63)); 
                l++; 
            }
        }
        // this[l:r) = 0
        void clear(int l, int r) {
            while((l&63) && (l<r)) {
                a[l>>6] ^= a[l>>6] & (1ll<<(l&63));
                l++; 
            }
            while(l+64<=r) {
                a[l>>6]=0;
                l+=64;
            }
            while(l<r) {
                a[l>>6] ^= a[l>>6] & (1ll<<(l&63));
                l++; 
            }
        }
        // this[l:r) ~= this[l:r)
        void flip(int l, int r) {
            while((l&63) && (l<r)) {
                a[l>>6] ^= (1ll<<(l&63)); 
                l++; 
            }
            while(l+64<=r) { 
                a[l>>6]=~a[l>>6];
                l+=64; 
            }
            while(l<r) {
                a[l>>6] ^= (1ll<<(l&63));
                l++; 
            }
        }
        // this[l:r) |= b[l:r)
        // b[l:r) = 0
        void OR_then_clear(bit& b, int l, int r) {
            long long* that = b.a;
            while((l&63) && (l<r)) { 
                a[l>>6] |= that[l>>6] & (1ll<<(l&63)); 
                that[l>>6] ^= that[l>>6] & (1ll<<(l&63));
                l++; 
            }
            while(l+64<=r) {
                a[l>>6] |= that[l>>6];
                that[l>>6]=0;
                l+=64;
            }
            while(l<r) {
                a[l>>6] |= that[l>>6] & (1ll<<(l&63)); 
                that[l>>6] ^= that[l>>6] & (1ll<<(l&63));
                l++; 
            }
        }
        const bool operator[](size_t i) const {
            return get(i);
        }
};
ostream& operator<<(ostream& os, const bit& b) {
    for (int i = 0; i < b.len; i++) 
        os << bitset<64>(b.a[b.len - 1 - i]) << endl;;
    return os;
}

int main(void) {
    bit b(100);
    b.set(5, 1);
    b.set(25, 1);
    b.set(99, 1);
    b.set(63, 1);
    b.set(64, 1);
    cout << b << endl;

    cout << b.get(0) << endl;
    cout << b.get(1) << endl;
    cout << b.get(10) << endl;
    cout << b.get(62) << endl;
    cout << b.get(63) << endl;
    cout << b.get(64) << endl;

    bit ones(100);
    rep(i, 100) {
        ones.set(i, 1);
    }

    cout << ones << endl;
//    b.OR(ones, 10, 20);
    b.set(15, 1);
    b.flip(10, 20);
    cout << b << endl;

    

    return 0;
}
