#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
ll ugauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return a/b; else return (a+(a>0?-1:1))/b+1; }
ll lgauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return (a+(a>0?-1:1))/b-1; else return a/b; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

vvll g;
vll memo;
ll dfs(ll i, ll p) {
    if (g[i].size() == 0) return memo[i] = 1;
    ll ret = 0;
    for (auto x : g[i]) {
        ret += dfs(x, i);
    }
    return memo[i] = ret + 1;
}
ll subtree(vll p) {
    ll n = p.size()+1;
    g.resize(n);
    memo.resize(n, -1);
    rep(i, n-1) {
        g[p[i]].pb(i+1);
    }
//    cout << g << endl;
    dfs(0, -1);
    ll ret = accumulate(all(memo), 0ll);
    rep(i, n) {
        assert(memo[i] > 0);
    }
//    cout << memo << endl;
//    cout << ret << endl;
    return ret;
}

int main(void) {
    ll n, s; cin >> n >> s;

    ll x = -1;
    repi(i, 2, n+1) {
        ll l = (i+1ll) * i / 2ll + 2ll * (n - i);
        ll r = (i+1ll) * i / 2ll + 2ll * (n - i) + (n - i) * (i - 2ll);
//        cout << l << " " << r << endl;
        if (l <= s && s <= r) {
            x = i;
        }
    }
    if (x == -1) {
        cout << "No" << endl;
        return 0;
    }

    ll l = (x+1ll) * x / 2ll + 2ll * (n - x);
    ll r = (x+1ll) * x / 2ll + 2ll * (n - x) + (n - x) * (x - 2ll);
    // |a| = n-i, 0 <= a_i < i - 1, sum a = s - lなるものを構成せよ
    vll a(x-1);
    if (x != 2ll) {
//        cout << x << endl;
        ll tmp = s - l;
        ll y = n - x; // y個配る
//        cout <<"#######" << endl;
//        cout << tmp << endl;
//        cout << y << endl;
        ll M = (tmp - 1ll) / (x - 1) + 1ll; // 最大個数
//        cout << M << "M" << endl;
        for (ll i = x - 2; i >= 1; i--) {
            // iを減らすのは最大何個？tmp/i個
            a[i] = min(tmp/i, M);
            y -= a[i];
            tmp -= a[i] * i;
        }
        a[0] = y;

        cout << M<<endl;
        cout << a << endl;
        /*
        rep(i, n-x) {
            a[i] = tmp / (n - x);
        }
        tmp -= tmp / (n - x) * (n - x);
        rep(i, tmp) {
            a[i]++;
        }
        */
        /*
        rep(i, (s - l) / (x - 2ll)) {
            a[i] = x - 2ll;
        }
        if ((s - l) % (x - 2ll)) {
            a[(s - l) / (x - 2ll)] = (s - l) % (x - 2ll);
        }
        */
    } else {
        a[0] = n - 2;
    }

////    cout << a << endl;

    vll p;
    cout << "Yes" << endl;
    rep(i, x-1ll) {
        cout << i + 1ll << " ";
        p.pb(i);
    }
    rep(i, a.size()) {
        rep(j, a[i]) {
            cout << i+1 << " ";
            p.pb(i);
        }
    }
    cout << endl;
    /*
    rep(i, a.size()) {
        cout << a[i] + 1ll << " ";
        p.pb(a[i]);
    }
    cout << endl;
    */

    if (p.size() + 1 != n) {
        cout <<"#########HIT" << endl;
        cout << n << " " << s << endl;
    }
    assert(p.size() + 1ll == n);
    assert(subtree(p) == s);

    return 0;
}
