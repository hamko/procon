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

ll n, k; 
vvll p; 
set<ll> alive; 
vll dist1;
vll dist2;
vll dist3;
void visit(ll v, vll& dist) {
    rep(i, p[v].size()) {
        ll ch = p[v][i];
//        cout << v << " " << ch << endl;
        if (!alive.count(ch))
            continue;
        if (dist[ch] >= 0)
            continue;
        dist[ch] = dist[v] + 1;
        visit(ch, dist);
    }
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n >> k;
    p = vvll(n);
    rep(i, n-1) {
        ll u, v; cin >> u >> v; u--; v--;
        p[u].pb(v);
        p[v].pb(u);
    }
    dist1 = vll(n);
    dist2 = vll(n);
    dist3 = vll(n);

    rep(i, n) { alive.insert(i); }

    ll ret = 0;
    while (1) {
        rep(i, n) dist1[i] = -1;
        dist1[*(alive.begin())] = 0;
        visit(*(alive.begin()), dist1);
//        cout << dist1 << endl;
        ll farest = (ll)(max_element(all(dist1)) - dist1.begin());

        rep(i, n) dist2[i] = -1;
        dist2[farest] = 0;
        visit(farest, dist2);
//        cout << dist2 << endl;
        ll farest2 = (ll)(max_element(all(dist2)) - dist2.begin());
        ll Bdist = *max_element(all(dist2)); // Diameter
        if (Bdist <= k) 
            break;
        set<ll> Bv;
        rep(i, n) if (dist2[i] == Bdist) Bv.insert(i);

        rep(i, n) dist3[i] = -1;
        dist3[farest2] = 0;
        visit(farest2, dist3);
//        cout << dist3 << endl;
        ll Adist = *max_element(all(dist3)); // Diameter
        set<ll> Av;
        rep(i, n) if (dist3[i] == Adist) Av.insert(i);


        // Av is small
        if (Av.size() > Bv.size()) {
            for (auto x : Bv) alive.erase(x);
            ret+=Bv.size();
        } else {
            for (auto x : Av) alive.erase(x);
            ret+=Av.size();
        }
    }
    cout << ret << endl;

    return 0;
}
