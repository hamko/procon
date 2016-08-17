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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll v, e; cin >> v >> e;
    vector<vector<int>> g(v);
    rep(i, e) {
        ll u, v; cin >> u >> v; u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> used(v, -1);
    vll diff;
    rep(i, v) {
        if (used[i] != -1) continue;
//        cout << used << endl;
        vll counter(2);
        bool contradiction = false;
        function<void(int, int)> f = [&](ll x, ll k){
            if (used[x] != -1) {
                if (used[x] != k % 2) {
                    contradiction = true;
                }
                return;
            }
            used[x] = k % 2;
            counter[k % 2]++;
            for (int next : g[x]) {
//                cout << x << "->" << next << endl;
                f(next, k+1);
            }
        };
        f(i, 0);
        if (contradiction) {
            cout << -1 << endl;
            return 0;
        }
        diff.pb(abs(counter[0] - counter[1]));
    }

//    cout << diff << endl;

    int n = diff.size();
    const ll MAXD = 100010;
    vector<int> dp(MAXD);
    vector<int> dp_next(MAXD);
    dp_next[0] = 1;

    rep(d, n) {
//        cout << d << endl;
        swap(dp, dp_next);
        rep(i, MAXD) {
            dp_next[i] = 0;
        }
        rep(i, MAXD) if (dp[i]) {
            dp_next[i+diff[d]] = 1;
            dp_next[abs(i-diff[d])] = 1;
        }
    }
    /*
    rep(i, MAXD) {
        if (dp_next[i]) {
            cout << i << " ";
        }
    }
        cout << endl;
        */

    rep(i, MAXD) {
        if (dp_next[i]) {
            ll a = (v + i) / 2, b = (v - i) / 2;
//            cout << a << " " << b << endl;
            cout << a * b - e << endl;
            return 0;
        }
    }

    return 0;
}
