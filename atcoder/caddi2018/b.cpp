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

ll dp[50][50][50][50];
ll dfs(ll i, ll j, ll h, ll k) {
    if (i == 0 && j == 0 && h == 0 && k == 0) {
        return dp[i][j][h][k] = 1;
    }
    if (dp[i][j][h][k] != 0) {
        return dp[i][j][h][k];
    }
    ll ret = 1; // lose
    if (i && dfs(i-1, j, h, k) == 1) {
        ret = 2;
    }
    if (j && dfs(i, j-1, h, k) == 1) {
        ret = 2;
    }
    if (h && dfs(i, j, h-1, k) == 1) {
        ret = 2;
    }
    if (k && dfs(i, j, h, k-1) == 1) {
        ret = 2;
    }

    if (i && j && dfs(i-1, j-1, h, k) == 1) {
        ret = 2;
    }
    if (j && h && dfs(i, j-1, h-1, k) == 1) {
        ret = 2;
    }
    if (h && i && dfs(i-1, j, h-1, k) == 1) {
        ret = 2;
    }
    if (i && k && dfs(i-1, j, h, k-1) == 1) {
        ret = 2;
    }
    if (j && k && dfs(i, j-1, h, k-1) == 1) {
        ret = 2;
    }
    if (h && k && dfs(i, j, h-1, k-1) == 1) {
        ret = 2;
    }


    if (i && j && h && dfs(i-1, j-1, h-1, k) == 1) {
        ret = 2;
    }
    if (i && j && k && dfs(i-1, j-1, h, k-1) == 1) {
        ret = 2;
    }
    if (i && k && h && dfs(i-1, j, h-1, k-1) == 1) {
        ret = 2;
    }
    if (k && j && h && dfs(i, j-1, h-1, k-1) == 1) {
        ret = 2;
    }

    if (i && k && j && h && dfs(i-1, j-1, h-1, k-1) == 1) {
        ret = 2;
    }
    return dp[i][j][h][k] = ret;
}

ll brutal(ll n, vll a) {
    return dfs(a[0], a[1], a[2], a[3]);
}
ll solver(ll n, vll a) {
    if (n == 1) {
        return (a[0] % 2 ? 2 : 1);
    }
    sort(all(a));
    rep(i, n) {
        if (a[i] % 2 == 1) {
            return 2;
        }
    }
    return 1;

    if (a[0] % 2 == 1) {
        return 2;
    }
    if (a[0] % 2 == 0 &&( (a[0] + a[1]) % 2 == 1)) {
        return 2;
    }
    ll s = 0;
    rep(i, n) {
        s += a[i];
    }
    return (s % 2 ? 2 : 1);
}

int main(void) {
    /*
    ll m = 10;
    dfs(m, m, m);
    rep(i, m) repi(j, i, m) repi(h, j, m) {
        cout << mt(i, j, h) << " " << dp[i][j][h] << endl;
    }
    */


    ll n; cin >> n;
    vll a(n); cin >> a;
    ll solv = solver(n, a);
    /*
    if (n == 4) {
        ll brut = brutal(n, a);
        if (solv != brut) {
            cout << "HIT!!!!!!!!!!!" << endl;
            cout << a << endl;
            cout << solv << " " << brut << endl;
        }
    }
    */
    if (solv == 2) {
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }
    return 0;
}
