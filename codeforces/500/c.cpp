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

// (i個見て)
// j個山にしていて、jで山にしていて(l), 最後を消している(h)時の最小
ll dp[5010][2][2] = {};
ll dp_next[5010][2][2] = {};
vll solve(ll n, vll a) {
//    cout << a << endl;


    rep(j, 5010) rep(l, 2) rep(h, 2) dp[j][l][h] = INF;
    dp[0][0][0] = 0;
    if (a[0] < a[1] && a[1] > a[2]) 
        chmin(dp[1][1][0], 0);
    else 
        chmin(dp[1][1][0], max(0ll, a[0] - a[1] + 1ll) + max(0ll, a[2] - a[1] + 1ll));

    rep(j, 5010) rep(l, 2) rep(h, 2) if (dp[j][l][h] != INF) cout << mt(0, j, l, h) << " " << (dp[j][l][h]) << endl;

    // dp[j個][真ん中下げて][左さげて]
    rep(i, n-3) {
        rep(j, 5010) rep(l, 2) rep(h, 2) dp_next[j][l][h] = INF;
        rep(j, 5005) rep(l, 2) rep(h, 2) {
            if (l == 1 && h == 0) {
                chmin(dp_next[j][0][1], dp[j][1][0]);
            } else {
                chmin(dp_next[j][0][0], dp[j][l][h]);
                ll mid = a[i+2];
                if (l)
                    chmin(mid, a[i+1] - 1);
                ll prev = a[i+1];
                if (h)
                    chmin(prev, (a[i+0] - 1));
                //                if (prev >= mid) continue;
                ll cost = max(0ll, prev - mid + 1ll) + max(0ll, a[i+3] - mid + 1ll);
                if (!(a[i+3]>=mid && l && h))
                    chmin(dp_next[j+1][a[i+3]>=mid][0], dp[j][l][h] + cost);
            }
        }
        swap(dp, dp_next);
        rep(j, 5010) rep(l, 2) rep(h, 2) if (dp[j][l][h] != INF) cout << mt(i+1, j, l, h) << " " << (dp[j][l][h]) << endl;
    }
    vll ans;
    repi(j, 1, (n-1)/2+1) {
        ll ret = INF;
        rep(l, 2) rep(h, 2) {
            chmin(ret, dp[j][l][h]);
        }
        ans.pb(ret);
    }
    return ans;
}

vll brutal(ll n, vll a_) {
    n -= 2;
    vll a(n);
    rep(i, n) {
        a[i] = a_[i+1];
    }

    vll ans;
//    cout << n << endl;
//    cout << a << endl;
    repi(k, 1, (n-1)/2+1+1) {
//        cout << "HIT" << endl;
        vll tmp(n);
        rep(i, k) {
            tmp[i] = 1;
        }
        sort(all(tmp));
        ll ret = INF;
        do {
//            cout << tmp << endl;
            bool f = 0;
            rep(i, n-1) {
                if (tmp[i] == 1 && tmp[i+1] == 1) {
                    f = 1;
                    break;
                }
            }
            if (f) continue;
            vll b = a;
            rep(i, n) if (tmp[i]) {
                if (i-1>=0) 
                    chmin(b[i-1], a[i]-1);
                if (i+1<n) 
                    chmin(b[i+1], a[i]-1);
            }
//            cout << b << " $#"<< endl;
            chmin(ret, accumulate(all(a), 0ll) - accumulate(all(b), 0ll));
        } while (next_permutation(all(tmp)));
        ans.pb(ret);
    }
    return ans;
}
int main(void) {
    ll n; cin >> n;
    vll a(n+2, -INF);
    rep(i, n) {
        cin >> a[i+1];
    }
    n += 2;

    vll s = solve(n, a);
    vll b = brutal(n, a);
    if (s != b) {
        cout << a << endl;
        cout << s << " " << b << endl;
    }

    return 0;
}
