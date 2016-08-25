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

// 整数二分探索
// O(log(range))
// f: 単調増加関数. 000111, 111111, 000000を許容する（11110000で探索したい場合は、自分でfを反転すること）
// 閉区間[rl, rr]から単調関数fを満たす最小の数を返す。
// 全て1なら0を返す（定義通り）、全て0ならrr+1を返す（異常検出用）！
ll BinarySearch(ll rl, ll rr, function<bool(ll)> f) { 
    ll lo = rl-1, ro = rr+1;
    while (ro - lo != 1) {
        ll m = (lo + ro) / 2; 
        ((m!=rl-1&&f(m))?ro:lo)=m; 
    }
    return ro;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll a00, a01, a10, a11; cin >> a00 >> a01 >> a10 >> a11;

    auto f0 = [&](ll x) { return x * x - x - 2 * a00 >= 0; };
    auto f1 = [&](ll x) { return x * x - x - 2 * a11 >= 0; };
    ll a0 = BinarySearch(0, 1000010, f0);
    ll a1 = BinarySearch(0, 1000010, f1);
    ll n = a0 + a1;
//    cout << a0 << " " << a1 << endl;

    if (a0 * (a0 - 1ll) / 2ll != a00) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a1 * (a1 - 1ll) / 2ll != a11) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a0 == 0 && a1 == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (a0 == 0 && a01 + a10 != n) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a0 == 0 && a01 + a10 == n) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a1 == 0 && a01 + a10 != n) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (n * (n - 1) / 2 != a00 + a01 + a10 + a11) {
        cout << n << endl;
        cerr << "test" << endl;
        cout << "Impossible" << endl;
        return 0;
    }
    vll a(a1+1);
    ll rem = a10;
    ll sum = 0;
    for (ll i = a1; i > 0; i--) {
        a[i] = rem / i;
        rem -= a[i] * i;
        sum += a[i];
    }
    a[0] = a0 - sum;
//    cout << a << endl;
    rep(i, a.size()) {
        rep(j, a[i]) {
            cout << '0';
        }
        if (i != a.size() - 1) 
            cout << '1';
    }
    cout << endl;

    return 0;
}
