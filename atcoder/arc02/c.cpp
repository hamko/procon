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
static const long long mo = 1e9+7;

typedef double Weight;
const Weight INF = 2e9;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

// Floyd Warshall
// O(V^3)
void shortestPathFW(const Matrix &g, Matrix &dist) {
    ll n = g.size();
    dist = g;
    rep(k, n) rep(i, n) rep(j, n) 
        if (dist[i][j] > dist[i][k] * dist[k][j]) 
            dist[i][j] = dist[i][k] * dist[k][j];
}
void initFW(Matrix& m, ll n){
    m = Matrix(n, Array(n, INF));
    rep(i, n) m[i][i] = 1;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<string> s(n); vll a(n); vector<string> t(n); 
    rep(i, n) cin >> s[i] >> a[i] >> t[i];

    map<string, ll> al;
    rep(i, n) {
        ll tmp;
        tmp = al.size(); if (!al.count(s[i])) al[s[i]] = tmp;
        tmp = al.size(); if (!al.count(t[i])) al[t[i]] = tmp;
    }

    map<ll, string> alinv;
    for (auto x : al) 
        alinv[x.se] = x.fi;
    
    Matrix g;
    initFW(g, al.size());
    rep(i, n) {
        g[al[s[i]]][al[t[i]]] = a[i];
        g[al[t[i]]][al[s[i]]] = 1.0/a[i];
    }

    Matrix dist;
    shortestPathFW(g, dist);

    double ret = 0; ll reti = 0, retj = 0;
    rep(i, al.size()) rep(j, al.size()) if (dist[i][j] != INF) {
        if (ret < dist[i][j]) {
            ret = dist[i][j], reti = i, retj = j;
        }
    }
    cout << 1 << alinv[reti] << "=" << (ll)(round(ret)) << alinv[retj] << endl;
    return 0;
}
