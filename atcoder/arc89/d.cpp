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

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！
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

// 累積和の計算
// 構築O(n)
// クエリO(1)
const function<bool(ll)> f1_default = [](ll x) { return 1; };
class Sum1d {
public:
    vll data;
    vll sumdata;
    Sum1d(vll& d, function<bool(ll)> f = f1_default) {
        int n = d.size();
        data = d;
        sumdata = vll(n+1, 0);
        rep(i, n) if(f(i)) sumdata[i+1] = data[i];
        rep(i, n) sumdata[i+1] += sumdata[i];
    }
    // [i, j)の小区間の総和 (半開区間)
    ll sum(int i, int j) {
        return sumdata[j]-sumdata[i];
    }
    // [i, i+ilen)の小区間の総和 (半開区間)
    ll suml(int i, int len) {
        return this->sum(i, i+len);
    }
    void print(void) {
        rep(i, sumdata.size()) cout << sumdata[i] << " "; cout << endl;
    }
};

// 二次元累積和の計算
// 構築O(n^2)
// クエリO(1)
const function<bool(ll, ll)> f2_default = [](ll x, ll y) { return 1; };
class Sum2d {
public:
    vector<vll> data;
    vector<vll> sumdata;
    Sum2d(vector<vll>& d, function<bool(ll, ll)> f = f2_default) {
        int n = d.size(), m = d[0].size();
        data = d;
        sumdata = vector<vll>(n+1, vll(m+1, 0));
        rep(i, n) rep(j, m) if(f(i, j)) sumdata[i+1][j+1] = data[i][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i+1][j];
        rep(i, n) rep(j, m) sumdata[i+1][j+1] += sumdata[i][j+1];
//        rep(i, n+1) {{rep(j, m+1) cout << sumdata[i][j] << " "; } cout << endl;}
    }
    // [(i0, j0), (i1, j1))の小区間の総和 (半開区間)
    ll sum(int i0, int j0, int i1, int j1) {
        return sumdata[i1][j1]-sumdata[i1][j0]-sumdata[i0][j1]+sumdata[i0][j0];
    }
    // [(i0, j0), (i1, j1))の小区間の総和 (半開区間)
    ll sum(vll t) {
        return sum(t[0], t[1], t[2], t[3]);
    }
    // [(i, j), (i+ilen, j+jlen))の小区間の総和 (半開区間)
    ll suml(int i, int j, int ilen, int jlen) {
        return this->sum(i, j, i+ilen, j+jlen);
    }
};
ll n, k; 

vvll getRange(ll i, ll j) {
        vvll range;
        repi(dx, -2, 3) {
            repi(dy, -2, 3) if ((dx + dy) % 2 == 0) {
                if (i+dx*k >= 2*k) continue;
                if (j+dy*k >= 2*k) continue;
                if (i+(dx+1)*k <= 0) continue;
                if (j+(dy+1)*k <= 0) continue;
                range.pb((vll){i+dx*k, j+dy*k, i+(dx+1)*k, j+(dy+1)*k});
            }
        }
        for (auto&& s : range) {
            chmax(s[0], 0);
            chmax(s[1], 0);
            chmin(s[2], 2*k);
            chmin(s[3], 2*k);
        }
        cout << range << endl;
        return range;
}
int main(void) {
    cin >> n >> k;
    vll x(n),y(n);
    vector<char> c(n);
    vvll black(2*k, vll(2*k));
    vvll white(2*k, vll(2*k));

    rep(i, n) {
        cin >> x[i] >> y[i] >> c[i];
        x[i] %= 2 * k;
        y[i] %= 2 * k;
        if (c[i] == 'B') 
            black[x[i]][y[i]]++;
        if (c[i] == 'W') 
            white[x[i]][y[i]]++;
    }
    Sum2d sblack(black);
    Sum2d swhite(white);

    ll ret = 0;
    rep(i, 2*k) rep(j, 2*k) {
        ll tmp_b = 0, tmp_w = 0;
        repi(dx, -2, 3) {
            repi(dy, -2, 3) {
                if (i+dx*k >= 2*k) continue;
                if (j+dy*k >= 2*k) continue;
                if (i+(dx+1)*k <= 0) continue;
                if (j+(dy+1)*k <= 0) continue;
                if ((dx+dy)%2 == 0) 
                    tmp_b += sblack.sum( max(0ll, i+dx*k), max(0ll, j+dy*k), min(2*k, i+(dx+1)*k), min(2*k, j+(dy+1)*k));
                else
                    tmp_w += swhite.sum( max(0ll, i+dx*k), max(0ll, j+dy*k), min(2*k, i+(dx+1)*k), min(2*k, j+(dy+1)*k));
            }
        }
        chmax(ret, tmp_b + tmp_w);
    }
    cout << ret << endl;



    return 0;
}
