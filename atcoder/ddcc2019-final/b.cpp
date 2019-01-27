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



ll n, k, rem;
vll a;
ll count(ll l, ll m, ll r) {
    ll x = r - m; // 大きい方
    ll y = m - l; // 小さい方
    ll ret = 0;
    rep(i, x) {
        ret += max(min(y, y-k+1+i), 0ll);
    }
    return ret;
}
void dfs(ll l, ll r) {
    if (r - l <= 1) return;
    ll m = (l + r) / 2;
    // [l, m) [m, r)
    
    ll ret = count(l, m, r);
    cout << mt(l,  m,r) << endl;
    cout << ret << endl;
    if (ret <= rem) {
        rem -= ret;
        // aをrotate
        vll b;
        repi(i, m, r) {
            b.pb(i);
        }
        repi(i, l, m) {
            b.pb(i);
        }
        rep(i, r - l) {
            a[l+i] = b[i];
        }
        if (rem == 0) {
            rep(i, n) {
                cout << a[i] << " ";
            }
            cout << endl;
            exit(0);
        }
    }
    dfs(l, m);
    dfs(m, r);
}
int main(void) {
    cin >> n >> k >> rem;

    vll a(n);
    ll len = 0;
    ll x = n-1;
    set<ll> memo;
    rep(i, n) {
        memo.insert(i);
    }
    ll filled = -1;
    rep(i, n) {
        a[i] = min(x, rem + (k - 1));
        rem -= max(0ll, a[i] - (k - 1));
        memo.erase(a[i]);
//        cout << mt(a[i], rem) << endl;
        if (rem == 0) {
            filled = i;
            break;
        }
        x = a[i] - 1;
    }
    if (rem == 0) {
        //    cout << filled << endl;
        ll i = 0;
        for (auto x : memo) {
            a[filled+1+i] = x;
            i++;
        }
        rep(i, n) {
            cout << a[i] + 1 << " ";
        }
        cout << endl;
        exit(0);
    } else {
    cout << "No Luck" << endl;
    }

    /*
    rep(i, n) {
        a[i] = i;
    }

    priority_queue<vll> q;
    q.push({n, 0, n});
    while (q.size()) {
        cout << q << endl;
        auto x = q.top();
        q.pop();
        ll len = x[0];
        ll l = x[1];
        ll r = x[2];
        if (len == 1) break;
        ll M = -INF;
        ll Mi = -1;
        // [0, len)
        // [0, m) [m, n)
        // 1 <= m < n-1
        repi(m, 1, len-1) {
            ll tmp = count(0, m, len);
            if (tmp <= rem) {
                Mi = m;
                chmax(M, tmp);
            }
        }

        if (M != -INF) {
            rem -= M;
            // aをrotate
            vll b;
            repi(i, Mi, r) {
                b.pb(i);
            }
            repi(i, l, Mi) {
                b.pb(i);
            }
            rep(i, r - l) {
                a[l+i] = b[i];
            }
            if (rem == 0) {
                rep(i, n) {
                    cout << a[i] << " ";
                }
                cout << endl;
                exit(0);
            }
            q.push({Mi - l, l, Mi});
            q.push({r - Mi, Mi, r});
        }
    }
    //    dfs(0, n);
    cout << "No Luck" << endl;
    */


    return 0;
}
