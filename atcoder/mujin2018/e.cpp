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

int main(void) {
    ll n, m, k; cin >> n >> m >> k;
    string t; cin >> t;
    t = t + t;

    vll nextD(2 * k + 1); nextD[2 * k] = -1; for (int i = 2 * k - 1; i >= 0; i--) { if (t[i] == 'D') nextD[i] = 0; else if (nextD[i+1] != -1) nextD[i] = nextD[i+1] + 1; else nextD[i] = -1; }
    vll nextL(2 * k + 1); nextL[2 * k] = -1; for (int i = 2 * k - 1; i >= 0; i--) { if (t[i] == 'L') nextL[i] = 0; else if (nextL[i+1] != -1) nextL[i] = nextL[i+1] + 1; else nextL[i] = -1; }
    vll nextR(2 * k + 1); nextR[2 * k] = -1; for (int i = 2 * k - 1; i >= 0; i--) { if (t[i] == 'R') nextR[i] = 0; else if (nextR[i+1] != -1) nextR[i] = nextR[i+1] + 1; else nextR[i] = -1; }
    vll nextU(2 * k + 1); nextU[2 * k] = -1; for (int i = 2 * k - 1; i >= 0; i--) { if (t[i] == 'U') nextU[i] = 0; else if (nextU[i+1] != -1) nextU[i] = nextU[i+1] + 1; else nextU[i] = -1; }

    /*
    cout << endl;
    cout << t << endl;
    cout << nextD << endl;
    cout << nextU << endl;
    cout << nextL << endl;
    cout << nextR << endl;
    cout << n << endl;
    */

    vector<string> b(n); rep(i, n) cin >> b[i];

    ll si, sj, gi, gj;
    rep(i, n) rep(j, m) {
        if (b[i][j] == 'S') {
            si = i;
            sj = j;
        }
        if (b[i][j] == 'G') {
            gi = i;
            gj = j;
        }
    }


    ll d[n+1][m+1];
    rep(i, n+1) rep(j, m+1) d[i][j] = INF;
    d[si][sj] = 0;

    priority_queue<vll> q;
    q.push({-d[si][sj], si, sj});

    while (q.size()) {
        auto x = q.top(); q.pop();
        ll cost = -x[0], i = x[1], j = x[2];
//        cout << mt(cost, i, j) << endl;

        // D
        rep(_, 1) {
            vll y = {INF, i+1, j};
            if (i + 1 >= n) break;
            if (b[i+1][j] == '#') break;
            if (nextD[(cost)%k] == -1) break;
//            cout << mt(cost, nextD[(cost)%k]) <<"DOWN"<< endl;
            ll next_cost = cost + nextD[(cost)%k] + 1;
            if (d[i+1][j] <= next_cost) {
                break;
            }
            y[0] = -next_cost;
            chmin(d[i+1][j], next_cost);
            q.push(y);
        }

        // U
        rep(_, 1) {
            vll y = {INF, i-1, j};
            if (i - 1 < 0) break;
            if (b[i-1][j] == '#') break;
            if (nextU[(cost)%k] == -1) break;
            ll next_cost = cost + nextU[(cost)%k] + 1;
            if (d[i-1][j] <= next_cost) {
                break;
            }
            y[0] = -next_cost;
            chmin(d[i-1][j], next_cost);
            q.push(y);
        }

        // R
        rep(_, 1) {
            vll y = {INF, i, j+1};
            if (j + 1 >= m) break;
            if (b[i][j+1] == '#') break;
            if (nextR[(cost)%k] == -1) break;
            ll next_cost = cost + nextR[(cost)%k] + 1;
            if (d[i][j+1] <= next_cost) {
                break;
            }
            y[0] = -next_cost;
            chmin(d[i][j+1], next_cost);
            q.push(y);
        }


        // L
        rep(_, 1) {
            vll y = {INF, i, j-1};
            if (j - 1 < 0) break;
            if (b[i][j-1] == '#') break;
            if (nextL[(cost)%k] == -1) break;
            ll next_cost = cost + nextL[(cost)%k] + 1;
            if (d[i][j-1] <= next_cost) {
                break;
            }
            y[0] = -next_cost;
            chmin(d[i][j-1], next_cost);
            q.push(y);
        }

    }


    /*
    rep(i, n) {
        rep(j, m) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    */

    if (d[gi][gj] == INF) {
        cout << -1 << endl;
    } else {
        cout << d[gi][gj] << endl;
    }


    return 0;
}
