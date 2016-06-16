#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
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
#define VN(v) # v
#define print(a) cout << a << "#" << VN(a) << endl;
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

ld factorial(ll n) {
    ld ret = 1;
    rep(i, n) {
        ret *= i + 1;
    }
    return ret;
}
ld combination(ll n, ll r) {
    if (n < r || r < 0 || n < 0) 
        return 0;
    ld ret = 1;
    ret *= factorial(n+r);
    ret /= factorial(r);
    ret /= factorial(n-r);
    return ret;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    } 
    vector<vector<ld>> p(n, vector<ld>(n, 0));
    rep(i, n) rep(j, n) cin >> p[i][j];
    if (n == 2) {
        cout << ldout << p[0][1] << endl;
        return 0;
    }

    ld ret = 1;
    rep(i, n-1) {
        ret *= p[0][i+1];
    }
    ret /= n;

    rep(mask, 1ll<<(n-1)) {
        if (!mask) continue;
        ld s = 0;
        rep(i, n-1) {
            if (!(mask & (1ll << i))) continue;
            ld tmp = p[0][i];
            rep(j, n-1) if (i != j) {
                if (!(mask & (1ll << i))) continue;
                tmp *= p[i][j];
            }
            s += tmp;
        }
        rep(i, n-1) {
            if (mask & (1ll << i)) continue;
            s *= p[0][i];
        }
        ret += s / (ld)n / combination(n-1, __builtin_popcount(mask));
    }
    cout << ldout << ret << endl;
    return 0;
}
