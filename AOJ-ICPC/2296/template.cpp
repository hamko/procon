#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
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
    ll n/*num of city*/, m/*num of item*/, w, t; cin >> n >> m >> w >> t;
    assert(1 <= n && n <= 7);
    assert(1 <= m && m <= 7);

    unordered_map<string, ll> names;
    vll weight(m), p(m); 
    rep(i, m) {
        string s; cin >> s >> weight[i] >> p[i]; 
        names[s] = i;
    }

    vector<P> pos;
    vvll items(n, vll(m, INF));
    rep(i, n) {
        ll l, x, y; cin >> l >> x >> y; pos.pb(P(x, y));
        rep(j, l) {
            string r_str; ll q; cin >> r_str >> q;
            items[i][names[r_str]] = q;
        }
    }
    pos.pb(P(0, 0));

    auto dist = [&](ll i, ll j){ return abs(pos[i].fi - pos[j].fi) + abs(pos[i].se - pos[j].se); };

    ll town_num = pos.size();
    ll tsp[1<<town_num][town_num]; rep(i, 1<<town_num) rep(j, town_num) tsp[i][j] = INF;
    tsp[0][town_num - 1] = 0;
    rep(mask, 1<<town_num) rep(j, town_num) rep(h, town_num) if (!(mask & (1 << h)))
            chmin(tsp[mask | (1 << h)][h], tsp[mask][j] + dist(j, h));

    vll min_time(1<<n);
    rep(mask, 1<<town_num) if (mask & (1 << (town_num-1)))
        min_time[mask & ((1 << (town_num-1)) - 1) ] = tsp[mask][town_num-1];

    vvll cheapest(1<<n, vll(m, INF));
    rep(mask, 1<<n) rep(item, m) rep(city, n) if (mask & (1 << city))
        chmin(cheapest[mask][item], items[city][item]);

    vll profit(1<<n);
    rep(mask, 1<<n) {
        vll value = p; 
        rep(i, m) 
            value[i] -= cheapest[mask][i];
        
        vvll dp(m+1, vll(w+1));
        rep(i, m) rep(j, w+1) {
            dp[i+1][j] = dp[i][j];
            if (j - weight[i] >= 0) 
                chmax(dp[i+1][j], dp[i+1][j-weight[i]] + value[i]);
        }

        profit[mask] = dp[m][w];
    }

    vvll dp((1<<n)+1, vll(t+1));
    rep(i, 1<<n) rep(j, t+1) {
        dp[i+1][j] = dp[i][j];
        if (j - min_time[i] >= 0) 
            chmax(dp[i+1][j], dp[i+1][j-min_time[i]] + profit[i]);
    }
    cout << dp[1<<n][t] << endl;

    return 0;
}
