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

const int MAXN = 100010;
const ll MOD = 1e9+7;
ll fact[3*MAXN], rfact[3*MAXN];

// extgcd
ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
// mod_inverse
ll mod_inverse(ll a, ll m = MOD) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m+x%m) % m;
}

ll nCr(int n, int r) {
    ll ret = fact[n];
    (ret *= rfact[r]) %= MOD;
    (ret *= rfact[n-r]) %= MOD;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < 3*MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        rfact[i] = mod_inverse(fact[i]);
    }
    int N, M, K;
    cin >> N >> M >> K;
    ll ans = 0;
    int total = N+M+2*K;
    for (int i = 0; i <= K; i++) {
        int yoko = N+2*i;
        int tate = M+2*(K-i);
        ll y = nCr(yoko, i);
        if (i > 0) {
            (y -= nCr(yoko, i-1)) %= MOD;
            if (y < 0) y += MOD;
        }
        ll t = nCr(tate, (K-i));
        if (K-i > 0) {
            (t -= nCr(tate, (K-i)-1)) %= MOD;
            if (t < 0) t += MOD;
        }
        ll plus = (y*t)%MOD;
        (plus *= nCr(total, yoko)) %= MOD;
        cout << y << " " << t << " " << nCr(total, yoko) << endl;
        ans += plus;
    }
    cout << ans%MOD << endl;
    return 0;
}
