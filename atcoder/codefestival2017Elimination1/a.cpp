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
template <typename T>  ostream &operator<<(ostream &o, const multiset<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
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

// sの括弧列の全列挙
// O(2^n), n = 32までは現実的な時間で終わる
// 0 1 // 2 1 // 4 2 // 6 5 // 8 14 // 10 42 // 12 132 // 14 429 // 16 1430 // 18 4862 // 20 16796
// 22 58786 // 24 208012 // 26 742900 // 28 2674440 // 30 9694845 // 32 35357670 // 34 129644790
void numerateParentheses(int n, vector<ll>& q_next) {
    q_next.clear();
    if (n < 0 || n % 2) return;
    vector<ll> q;
    q_next.pb(0);
    ll t = 0;
    while (t < n && !q_next.empty()) {
        q.swap(q_next);
        while (!q.empty()) {
            ll tmp = q.back(); q.pop_back();
            if (__builtin_popcount(tmp) > t / 2) // if 011->2,3/2=1 ->OK, 0011->2, 4/2=2->NG
                q_next.pb(tmp); // Down
            if (__builtin_popcount(tmp) < n / 2)
                q_next.pb(tmp | (1ll << t)); // Up
        }
        t++;
    }
}


int main(void) {
    ll n, q; cin >> n >> q;
    n *= 2;
    vll a(n); cin >> a;
    vll b(n); cin >> b;
    vll d(n); rep(i, n) d[i] = b[i] - a[i];
    ll asum = accumulate(all(a), 0ll);
    multiset<ll> pos, neg;
    repi(i, 1, n-1) {
        (d[i] >= 0 ? pos : neg).insert(d[i]);
    }
    ll possum = 0;
    for (auto x : pos) possum += x;
    rep(_, q) {
        ll p, x, y; cin >> p >> x >> y; p--;
        asum += x - a[p];
        if (!(p == 0 || p == n-1)) {

            if (b[p] - a[p] >= 0) possum -= (b[p] - a[p]);
            auto& target = (b[p] - a[p] >= 0 ? pos : neg);

            target.erase(target.find(b[p] - a[p]));
            (y - x >= 0 ? pos : neg).insert(y - x);
            if (y - x >= 0) possum += y - x;


        }
            a[p] = x;
            b[p] = y;
            d[p] = y - x;

            /*
        cout << asum << endl;
        cout << pos << endl;
        cout << neg << endl;
        cout << possum << endl;
        */
        if (pos.size() % 2 == 0) {
            cout << asum + possum << endl;
        } else {
            cout << max(asum + possum - *pos.begin(), asum + possum + *neg.rbegin()) << endl;
        }
    }

    /*
       const ll n = 8;
       vll p;
       numerateParentheses(n, p);
       set<ll> s;
       for (auto x : p) for (auto y : p) {
       auto tmp = (bitset<n>(x) ^ bitset<n>(y));
       s.insert(tmp.to_ulong());
       cout << tmp << endl;
       }
       cout << s << endl;
       cout << s.size() << endl;
       */

    return 0;
}
