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
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

// よく使うセグ木全部盛りあわせ
// 以下を全てO(log n)で行う
//
// - 点代入
// - 範囲代入
// - 範囲加算
// - 範囲sum
// - 範囲min
// - 範囲max
class SegmentTree {
public:
    unordered_map<ll, ll> memo; // memo[i] = j : i = 1e6 * query_id + interval_length, memo[i] = query_val^interval_length

    // 1-indexed tree. parent of i is i/2, children of i are 2i and 2i+1
    // a single node i is represented by val[i+n]
    vll val, val_min, val_max, lazy; // val.size() = lazy.size() = 2 * n
    ll max_n = 1000000;

    ll n;
    SegmentTree (ll n_) {
        n = 1;
        while (!(n_ < n)) {
            n *= 2;
        }
        val.resize(2ll*n, 0);
        val_min.resize(2ll*n, 0);
        val_max.resize(2ll*n, 0);
        lazy.resize(2ll*n, INF);
    }

    // resolve laziness of the node k = [l, r)
    // after the function is done, lazy[k] = nothing and val[k] should be the correct data
    void push(ll k, ll l, ll r) {
        if (lazy[k] == INF) return;
        if (lazy[k] == 0) {
            val[k] = 0;
            val_min[k] = 0;
            val_max[k] = 0;
        } else {
            val[k] += lazy[k] * (r - l);
            val_min[k] += lazy[k];
            val_max[k] += lazy[k];
        }
        if (r - l == 1) {
        } else {
            if (lazy[k] == 0) {
                lazy[2*k+0] = 0;
                lazy[2*k+1] = 0;
            } else {
                if (lazy[2*k+0] == INF) { 
                    lazy[2*k+0] = lazy[k];
                } else if (lazy[2*k+0] == 0) {
                    push(2*k+0, l, (l+r)/2);
                    lazy[2*k+0] = lazy[k];
                } else {
                    lazy[2*k+0] += lazy[k];
                }
                if (lazy[2*k+1] == INF) { 
                    lazy[2*k+1] = lazy[k];
                } else if (lazy[2*k+1] == 0) {
                    push(2*k+1, l, (l+r)/2);
                    lazy[2*k+1] = lazy[k];
                } else {
                    lazy[2*k+1] += lazy[k];
                }
            }
        }
        lazy[k] = INF;
    }

    // get the prod of node k = [l, r) cap [a, b) 
    // after the function is done, lazy[k] = nothing and val[k] should be the correct data
    tuple<ll, ll, ll> get(ll a, ll b, ll k, ll l, ll r) { // k is a node id, representing [l, r)
        push(k, l, r);
        if (b <= l || r <= a) return tuple<ll, ll, ll>(0, INF, -INF); // not relevant, unit value [a, b) [l, r) or [l, r) [a, b)
        if (a <= l && r <= b) return tuple<ll, ll, ll>(val[k], val_min[k], val_max[k]); // selected
        tuple<ll, ll, ll> ret;
        auto L = get(a, b, 2*k+0, l, (l+r)/2);
        auto R = get(a, b, 2*k+1, (l+r)/2, r);
        ::get<0>(ret) = ::get<0>(L) + ::get<0>(R);
        ::get<1>(ret) = ::min(::get<1>(L), ::get<1>(R));
        ::get<2>(ret) = ::max(::get<2>(L), ::get<2>(R));
        return ret;
    }
    tuple<ll, ll, ll> get(ll a, ll b) { // [a, b) is a query interval
        return get(a, b, 1, 0, n);
    }

    // update node k = [l, r) cap [a, b) with query_id
    // after the function is done, lazy[k] = nothing and val[k] should be the correct data <- important!
    void update(ll a, ll b, ll k, ll l, ll r, ll query_mode, ll query_val) {
        push(k, l, r);
        if (b <= l || r <= a) return; // not relevant
        if (a <= l && r <= b) {
            if (query_mode == 0) { // clear
                lazy[k] = 0;
            } else {
                if (lazy[k] != INF) {
                    lazy[k] += query_val;
                } else {
                    lazy[k] = query_val;
                }
            }
            push(k, l, r);
            return;
        } else {
            update(a, b, 2*k+0, l, (l+r)/2, query_mode, query_val);
            update(a, b, 2*k+1, (l+r)/2, r, query_mode, query_val);
            val[k] = val[2*k+0] + val[2*k+1];
            val_min[k] = ::min(val_min[2*k+0], val_min[2*k+1]);
            val_max[k] = ::max(val_max[2*k+0], val_max[2*k+1]);
        }
    }
    // update node k = [l, r) cap [a, b) with (query_id, query_val)
    void update(ll a, ll b, ll query_mode, ll query_val) {
        update(a, b, 1, 0, n, query_mode, query_val);
    }




    // print the whole information of val and lazy
    void print(void) {
        cout << "###########################################" << endl;
        cout << "VAL" << endl;
        {
            ll tmp = 1;
            ll acc = 0;
            repi(i, 1, 2*n) {
                acc++;
                cout << val[i] << " ";
                if (acc >= tmp) {
                    acc = 0;
                    tmp *= 2;
                    cout << endl;
                }
            }
        }
        cout << "LAZY" << endl;
        {
            ll tmp = 1;
            ll acc = 0;
            repi(i, 1, 2*n) {
                acc++;
                if (lazy[i] == INF) {
                cout << "X" << " ";
                } else {
                cout << lazy[i] << " ";
                }
                if (acc >= tmp) {
                    acc = 0;
                    tmp *= 2;
                    cout << endl;
                }
            }
        }
    }

    // ここから下は便利関数
    // s[a, b) = 0
    void clear(ll a, ll b) {
        update(a, b, 0, 0);
    }
    // s[a, b) += x
    void add(ll a, ll b, ll x) {
        update(a, b, 1, x);
    }
    // s[a, b) = x
    void set(ll a, ll b, ll x) {
        clear(a, b);
        update(a, b, 1, x);
    }
    // s[a] = x
    void set(ll a, ll x) {
        clear(a, a+1);
        update(a, a+1, 1, x);
    }
    // return s[i]
    ll get(ll i) {
        return sum(i, i+1);
    }
    // return sum s[a, b)
    ll sum(ll a, ll b) {
        return ::get<0>(get(a, b));
    }
    // return min s[a, b)
    ll min(ll a, ll b) {
        return ::get<1>(get(a, b));
    }
    // return max s[a, b)
    ll max(ll a, ll b) {
        return ::get<2>(get(a, b));
    }
};

void test(void) {
    rep(_, 1000000) {
        ll n = 10000;
        SegmentTree s(n);
        vll a(n);
        rep(i, 100000) {
            ll type = rand() % 3;
            ll l = rand() % n;
            ll r = l + 1 + rand() % (n - l);
            if (type == 0) {
                cout << "clear " << l << " " << r << endl;
                s.update(l, r, 0, 0);
                repi(i, l, r) a[i] = 0;
            } else if (type == 1) {
                ll v = 1 + rand() % 3;
                cout << "add " << l << " " << r << " " << v << endl;
                s.update(l, r, 1, v);
                repi(i, l, r) a[i] += v;
            } else {
                cout << "get " << l << " " << r << endl;
                auto retreal = accumulate(a.begin()+l, a.begin()+r, 0ll);
                auto retreal_min = *min_element(a.begin()+l, a.begin()+r);
                auto retreal_max = *max_element(a.begin()+l, a.begin()+r);
                assert(s.sum(l, r) == retreal);
                assert(s.min(l, r) == retreal_min);
                assert(s.max(l, r) == retreal_max);
            }
        }
    }
}
int main(void) {
    test(); return 0;

    return 0;
}
