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

struct UnionFind {
    vector<int> par;
    int cnt;
    UnionFind(int size_) : par(size_, -1), cnt(size_) { }
    void unite(int x, int y){
        if ((x = find(x)) != (y = find(y))) {
            if (par[y] < par[x]) swap(x, y);
            par[x] += par[y]; par[y] = x; cnt--;
        }
    }
    bool same(int x, int y){ return find(x) == find(y); }
    int find(int x){ return par[x] < 0 ? x : par[x] = find(par[x]); }
    int size(int x){ return -par[find(x)]; }
    int size(){ return cnt; }
};

vector<ll> g1, g2, gyear;
vector<ll> qindex, qyear;
static vector<pair<ll, P>> g;
static vector<pair<P, ll>> q;
static vector<ll> ret;

vector<ll> hamko(ll n, ll m, ll qnum) {
    g.clear();
    q.clear();
    ret.clear();

    // year, u, v
    g = vector<pair<ll, pair<ll, ll>>>(m);
    rep(i, m) {
        g[i].se.fi = g1[i] - 1;
        g[i].se.se = g2[i] - 1;
        g[i].fi = gyear[i];
    }
    sort(all(g), greater<pair<ll, P>>());
    //    cout << g << endl;

    q = vector<pair<P, ll>>(qnum);
    ret = vector<ll>(qnum);
    rep(i, qnum) {
        q[i].fi.se = qindex[i] - 1;
        q[i].fi.fi = qyear[i];
        q[i].se = i;
    }
    sort(all(q), greater<pair<P, ll>>());
    //    cout << q << endl;

    UnionFind uf(n);
    ll gi = 0;
    rep(i, qnum) {
        while (1) {
            if (!(gi < m && g[gi].fi > q[i].fi.fi)) 
                break;
            uf.unite(g[gi].se.fi, g[gi].se.se);
            gi++;
        }
        //        cout << i << " " << gi << " : " << uf.size(q[i].fi.se) << endl;
        ret[q[i].se] = uf.size(q[i].fi.se);
    }

    return ret;
}

const int MX = 200005;

struct UF {
    int n;
    vector<int> d;
    UF() {}
    UF(int n):n(n), d(n, -1) {}
    int root(int v) {
        if (d[v] < 0) return v;
        return d[v] = root(d[v]);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (size(x) < size(y)) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    int size(int v) { return -d[root(v)];}
};

vector<ll> snuke(ll n, ll m, ll qnum) {
    vector<vector<P>> e(MX);
    for (int i = 0; i < m; ++i) {
        e[gyear[i]].push_back(P(g1[i]-1,g2[i]-1));
    }
    int q = qnum;
    vector<vector<P>> qs(MX);
    for (int qi = 0; qi < q; ++qi) {
        qs[qyear[qi]].push_back(P(qindex[qi]-1,qi));
    }

    UF t(n);
    vector<ll> ans(q);
    for (int i = MX-1; i >= 0; --i) {
        for (P p : qs[i]) {
            int v = p.first, qi = p.second;
            ans[qi] = t.size(v);
        }
        for (P p : e[i]) {
            int a = p.first, b = p.second;
            t.unite(a,b);
        }
    }
    return ans;
}

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }
int main(void) {
    int seed = 0;

    ll n = 10000;
    ll m = 10000;
    ll q = 1000;

    rep(_, 100000) {
        cout << _ << endl;
        g1.clear(), g2.clear(), gyear.clear();
        qindex.clear(), qyear.clear();
        rep(i, m) {
            ll u, v;
            do {
                u = randr(1, n);
                v = randr(1, n);
            } while (u == v);
            g1.pb(u);
            g2.pb(v);
            gyear.pb(randr(0, 200000));
        }

        rep(i, q) {
            qindex.pb(randr(1, n));
            qyear.pb(randr(0, 200000));
        }
        auto hamko_ret = hamko(n, m, q);
        auto snuke_ret = snuke(n, m, q);
        if (hamko_ret != snuke_ret) {
            cout << "#HIT!!!!!!!!!!!!!!" << endl;
        }
    }

    return 0;
}
