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
P c(P x) {
    return P((x.fi+x.se)/2ll, (x.fi-x.se)/2ll);
}

const ll o = 800;
int16_t jsum[2*o][2*o];
ll count(vector<P> p, bool strict = false) {
    map<ll, vll> memo;
    for (auto x : p) {
        ll i = x.fi;
        ll j = x.se;
        memo[i].pb(j);
    }
    for (auto& x : memo) {
        sort(all(x.se));
    }

    rep(i, 2*o) rep(j, 2*o) jsum[i][j] = 0;
    for (auto& x : p) {
        jsum[x.fi+o][x.se+o+1]++;
    }
    rep(i, 2*o) {
        rep(j, 2*o-1) {
            jsum[i][j+1] += jsum[i][j];
        }
    }

    ll ret = 0;
    for (auto& x : memo) {
        ll i = x.fi;
        auto& q = x.se;
        rep(j1, q.size()) repi(j2, j1+1, q.size()) {
            ll l = abs(q[j1] - q[j2]);

            if (strict) {
                ret += jsum[i+l+o][q[j1]+o+1] - jsum[i+l+o][q[j1]+o];
                ret += jsum[i+l+o][q[j2]+o+1] - jsum[i+l+o][q[j2]+o];
                ret += jsum[i-l+o][q[j1]+o+1] - jsum[i-l+o][q[j1]+o];
                ret += jsum[i-l+o][q[j2]+o+1] - jsum[i-l+o][q[j2]+o];
            } else {
                ret += jsum[i+l+o][q[j2]+o+1] - jsum[i+l+o][q[j1]+o];
                ret += jsum[i-l+o][q[j2]+o+1] - jsum[i-l+o][q[j1]+o];
            }
            /*
            ll tmp = 0;
            // (i+l, [q[j1], q[j2]])に含まれる点の数
            for (auto j_plus : memo[i + l]) {
                if (!(q[j1] <= j_plus && j_plus <= q[j2])) continue;
                if (strict && q[j1] < j_plus && j_plus < q[j2]) continue;
                ret++;
                tmp++;
            }
            if (!strict) {
                cout << tmp << " " << jsum[i+l+o][q[j2]+o+1] - jsum[i+l+o][q[j1]+o] << endl;
            }
            */
            /*
            for (auto j_minus : memo[i - l]) if (q[j1] <= j_minus && j_minus <= q[j2]) {
                if (!(q[j1] <= j_minus && j_minus <= q[j2])) continue;
                if (strict && q[j1] < j_minus && j_minus < q[j2]) continue;
                ret++;
            }
            */
        }
    }

//    cout << ret << endl;

    return ret;

}

ll countAll(vector<P> p) {
    ll ret1 = count(p);
//    cout << ret1 << endl;
    rep(i, p.size()) {
        ll x = p[i].fi;
        ll y = p[i].se;
        p[i] = P(y, -x);
    }
    ll ret2 = count(p);
//    cout << ret2 << endl;

    ll ret3 = count(p, true);
//    cout << ret3 << endl;


//    cout << ret1 + ret2 - ret3 << endl;

    return ret1 + ret2 - ret3;
}
bool isOK(P a, P b, P c) {
    ll ab = max(abs(a.fi - b.fi), abs(a.se - b.se));
    ll bc = max(abs(b.fi - c.fi), abs(b.se - c.se));
    ll ca = max(abs(c.fi - a.fi), abs(c.se - a.se));
//    cout << a<<" " << b << " "<< c<<mt(ab,bc,ca)<<endl;
    return ab == bc && bc == ca;
}
ll countBrutal(vector<P> p) {
    ll n = p.size();
    ll ret = 0;
    rep(i, n) repi(j, i+1, n) repi(h, j+1, n) {
        ret += isOK(p[i], p[j], p[h]);
    }
    return ret;
}
int main(void) {
    ll h, w; cin >> h >> w;
    vector<string> b(h);
    rep(i, h) cin >> b[i];
    vector<P> p;
    rep(i, h) rep(j, w) if (b[i][j] == '#') {
        p.pb(P(i+j, i-j));
    }
    cout << p << endl;

    cout << countAll(p) << endl;
//    cout << countBrutal(p) << endl;


    /*
    if (countBrutal(p) != countAll(p)) {
        cout <<"HIT!" << endl;
    }
    */

    return 0;
}
