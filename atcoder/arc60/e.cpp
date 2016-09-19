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

const ll MAX_BITS = 20;
void solve(vvll& d, ll a, ll b) {
    ll ret = 0;
    for (ll bit = MAX_BITS - 1; bit >= 0; bit--) {
        ll next_a = d[bit][a];
        if (next_a < b) {
            ret += (1ll << bit);
            a = next_a;
        }
    }
    cout << ret + 1<< endl;
}
void solve_rev(vvll& d, ll a, ll b) {
    ll ret = 0;
    for (ll bit = MAX_BITS - 1; bit >= 0; bit--) {
        ll next_a = d[bit][a];
        if (next_a > b) {
            ret += (1ll << bit);
            a = next_a;
        }
    }
    cout << ret + 1<< endl;
}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> x(n); 
    rep(i, n) {
        cin >> x[i];
    }
    ll l; cin >> l;

    const ll MAX_BITS = 20;
    vvll d(MAX_BITS+1, vll(n+1, n-1));
    rep(i, n) {
        ll tmp = (ll)(lower_bound(all(x), x[i] + l) - x.begin());
        if (x[tmp] == x[i] + l) 
            d[0][i] = tmp;
        else 
            d[0][i] = tmp-1;
    }
    rep(bit, MAX_BITS) rep(i, n) {
        d[bit+1][i] = d[bit][d[bit][i]];
    }

    vvll d_rev(MAX_BITS+1, vll(n+1, 0));
    rep(i, n) {
        ll tmp = (ll)(lower_bound(all(x), x[i] - l) - x.begin());
        d_rev[0][i] = tmp;
    }
    rep(bit, MAX_BITS) rep(i, n) {
        d_rev[bit+1][i] = d_rev[bit][d_rev[bit][i]];
    }

    cout << "#d" << endl;
    cout << d << endl;
    cout << "#d_rev" << endl;
    cout << d_rev << endl;

    ll q; cin >> q;
    vector<P> query; 
    rep(i, q) {
        ll tmpa, tmpb; cin >> tmpa >> tmpb; tmpa--; tmpb--;
        query.pb(P(tmpa, tmpb));
    }
    
    rep(i, q) {
        if (query[i].fi < query[i].se) {
            solve(d, query[i].fi, query[i].se);
        } else {
            solve_rev(d_rev, query[i].fi, query[i].se);
        }
    }
    
    return 0;
}
