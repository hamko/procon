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
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
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
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

// 1-index, 閉区間！！！！
// initしてからつかってね
//
// init(n, m)
//      b[n][m]を作成
// qsum(x0, y0, x1, y1) : O(log^2 n)
//      return sum b[x0:x1][y0:y1]
// update(x, y, v) : O(log^2 n)
//      b[x][y] = v
//
const int MAXN = 2000 + 10;
const int MAXM = 2000 + 10;
struct BIT{
    using state = char;
    int n = 0, m = 0;
    state dat[ MAXN ][ MAXM ] = {};
    void init(int n_, int m_) {
        n = n_;
        m = m_;
    }
    void update(int x, int y, int v){
        for(int i = x; i <= n; i += i & -i)
            for(int j = y; j <= m; j += j & -j) 
                dat[ i ][ j ] += v;
    }
    state qsum(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i)
            for(int j = y; j > 0; j -= j & -j)
                res += dat[ i ][ j ];
        return res;
    }
    state qsum(int x0, int y0, int x1, int y1){
        return qsum( x1, y1 ) - qsum( x0 - 1, y1 ) - qsum( x1, y0 - 1 ) + qsum( x0 - 1, y0 - 1 );
    }
    void print(void) {
        cout <<"####"<<endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << (int)qsum(i, j, i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main(void) {
    ll h, w, t, q; cin >> h >> w >> t >> q;
    vvll qs;
    BIT b[2];
    b[0].init(h+5, w+5), b[1].init(h+5, w+5);
    rep(i, q) {
        vll x(6); cin >> x[0] >> x[1] >> x[2] >> x[3];
        if (x[1] == 2)
            cin >> x[4] >> x[5];
        qs.pb(x);
        if (x[1] == 0) {
            vll y = {x[0] + t, 1000, x[2], x[3], 0, 0}; 
            qs.pb(y);
        }
    }
    sort(all(qs));
//    for (auto x : qs) cout << x << endl;

    for (auto x : qs) {
        cout <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout << x << endl;
        if (x[1] == 0) {
            // [0](2, 3)++
            b[0].update(x[2], x[3], 1);
        } else if (x[1] == 1) {
            if (b[1].qsum(x[2], x[3]) >= 1) {
                b[1].update(x[2], x[3], -1);
            }
        } else if (x[1] == 2) {
            cout << (int)b[1].qsum(x[2], x[3], x[4], x[5]) << " " << (int)b[0].qsum(x[2], x[3], x[4], x[5]) << endl;
        } else {
            b[0].update(x[2], x[3], -1);
            b[1].update(x[2], x[3], +1);
        }
        b[0].print();
        b[1].print();
    }

    return 0;
}
