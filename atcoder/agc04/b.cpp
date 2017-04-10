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

// スパーステーブル
// 構築O(n log n)
// クエリO(log (log n))
//
// rmq(i, j)    [i, j)の最小値・最大値を求める
struct SparseTable {
    // 構築時データ
    vector<ll> val;
    
    // max_flag==trueならRange Maximum Query
    // デフォルトMinimum
    bool max_flag;

    // table[i][j]: [i, i+2^j)の最小値を取る添字
    vector<vector<ll>> table;

    inline ll MSB(ll x) { return x>0?31-__builtin_clz(x):-1; }
    SparseTable(void){}
    SparseTable(const vector<ll> a, bool max_flag_ = false) : val(a), max_flag(max_flag_) {
        ll n = a.size(), ln = MSB(n);
        table = vector<vector<ll>>(n, vector<ll>(ln + 1,0));
        rep(i,n)
            table[i][0] = i;

        ll k = 1;
        rep(j, ln) {
            rep(i, n){
                ll id1 = table[i][j], id2 = (i+k<n)?table[i+k][j]:id1;
                table[i][j+1] = (max_flag ? (val[id1]>=val[id2]) : (val[id1]<=val[id2]))?id1:id2;
            }
            k <<= 1;
        }
    }

    inline ll rmqi(ll l, ll r){
        ll ln = MSB(r-l);
        ll id1 = table[l][ln], id2 = table[r-(1<<ln)][ln];
        return (max_flag ? (val[id1]>=val[id2]) : (val[id1]<=val[id2]))?id1:id2;
    }

    inline ll rmq(ll l, ll r){ 
        if (l >= r) return max_flag ? 0 : INF;
        return val[rmqi(l,r)]; 
    }
};


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n; ll t; cin >> t;
    vll a(n); rep(i, a.size()) cin >> a[i];

    vll aaa; rep(_, 3) rep(i, n) aaa.pb(a[i]);
    SparseTable st(aaa);

    ll ret = INF;
    rep(k, n) {
        vll s(n, INF);
        rep(i, n) 
            s[i] = st.rmq(i-k+n, i+1+n);
        chmin(ret, accumulate(all(s), 0ll) + k * t);
    }
    cout << ret << endl;
    return 0;
}
