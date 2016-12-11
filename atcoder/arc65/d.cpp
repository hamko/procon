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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
using ld = long double;  using vld = vector<ld>; 
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
string bits_to_string(ll mask, ll n) { string s; rep(i, n) s += '0' + !!(mask & (1ll << i)); return s; }
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    // x, yをマージ
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    // x, yが同じ集合なら1
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    // xの根を探す。同じ集合なら同じ根が帰る
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    // xが含まれる集合の大きさを返す
    int size(int x) {
        return -data[root(x)];
    }
    // 分離されている集合の数を返す
    int setNum(void) {
        map<int, int> c;
        rep(i, data.size()) {
            c[root(i)]++;
        }
        return c.size();
    }
    // O(n)
    // 集合ごとに全部の要素を出力
    map<int, set<int>> c;
    void getUnionList(void) {
        for (int i = 0; i < data.size(); i++) 
            c[root(i)].insert(i);
    }
    /*
    void print(void) {
        auto c = getUnionList();
        for (auto x : c) {
            for (auto y : x) 
                cout << y << " ";
            cout << endl;
        }
    }
    */
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, k, l; cin >> n >> k >> l;
    vector<ll> p(k), q(k); rep(i, k) { cin >> p[i] >> q[i]; p[i]--, q[i]--; }
    vector<ll> r(l), s(l); rep(i, l) { cin >> r[i] >> s[i]; r[i]--, s[i]--; }
//    cout << r << " " << s << endl;

    vector<int> ret(n);
    UnionFind uf(n);
    rep(i, k) {
        uf.unite(p[i], q[i]);
    }
    uf.getUnionList();

    map<int/*root*/, set<int>> connected;
    rep(i, l) {
        if (uf.root(r[i]) != uf.root(s[i])) continue;
        connected[uf.root(r[i])].insert(i);
    }
    for (auto&& x : connected) {
        cout << x.fi << " " << x.se << "#connected"  << endl;
    }

    for (auto&& x : uf.c) {
        if (!connected.count(x.fi)) continue;
        cout << x.fi << "#root " << endl;
        cout << x.se << "#set " << endl;

        unordered_map<int, int> inv; // 何番目の都市がtrの何番目か
        unordered_map<int, int> fow; // trの何番目が何番目の都市か
        ll j = 0;
        for (auto&& y : connected[x.fi]) {
//            cout << y << " " << r[y] << " " << s[y] << endl;
            if (!inv.count(r[y])) {
//                cout << r[y] << "#added r" << endl; 
                inv[r[y]] = j; fow[j] = r[y]; j++; 
            }
            if (!inv.count(s[y])) {
//                cout << s[y] << "#added s" << endl; 
                inv[s[y]] = j; fow[j] = s[y]; j++; 
            }
        }
        /*
        cout << inv << endl;
        cout << fow << endl;
        cout << j << endl;
        */
        UnionFind tr(j);
        for (auto&& y : connected[x.fi]) {
            tr.unite(inv[r[y]], inv[s[y]]);
        }
        rep(i, j) {
            ret[fow[i]] = tr.size(i);
        }
    }

    rep(i, n) {
        assert(ret[i] <= n);
        assert(ret[i] <= k + 1);
        assert(ret[i] <= l + 1);
//        cout << (ret[i] == 0 ? 1 : ret[i]) << " ";
        cout << (ret[i] == 0 ? 1 : ret[i]) << " ";
    }
    cout << endl;

    return 0;
}
