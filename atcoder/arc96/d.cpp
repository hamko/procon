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

template<class T>
struct SegmentTreeMax {
    int n;
    T inf;
    vector<T> dat;
    SegmentTreeMax(int n_ = 0) : n(n_){
        inf = numeric_limits<T>::min();
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, inf);
    }
    T query(int v, int w, int l, int r){
        if(r <= l || w == 0) return inf;
        if(r - l == w) return dat[v]; // assert(l == 0 && r == w);
        int m = w/2;
        return max(query(v*2, m, l, min(r,m)), query(v*2+1, m, max(0,l-m), r-m));
    }
    void update(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) dat[i/2] = max(dat[i], dat[i^1]);
    }
    T query(int l, int r){ return query(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return query(idx, idx + 1); }
    void print(void) {
        rep(i, n) {
            cout << query(i, i + 1) << " ";
        }
        cout << endl;
    }
};

int main(void) {
    ll n,c; cin >> n>>c;;
    vll x(n),v(n);
    rep(i, n) {
        cin >> x[i]>>v[i];
    }
    ll ret = 0;
    rep(_, 2) {
//        cout << "############"<< endl;
//        cout << x << endl;
//        cout << v << endl;
        vll vp(n), vm(n);
        rep(i, n) {
            vp[i] =v[i];
            vm[i] =v[n-1-i];
        }
        vll vps(n+1), vms(n+1);
        rep(i, n) {
            vps[i+1]=vps[i]+vp[i];
            vms[i+1]=vms[i]+vm[i];
        }
//        cout << vms << endl;
        rep(i, n) {
            vps[i+1]-=x[i];
            vms[i+1]-=(c-x[n-1-i]);
        }
        // vps[i] = 時計回りにi個取ったときの最大利得
//        cout << vps << endl;
//        cout << vms << endl;
        SegmentTreeMax<ll> vps_max(n+1);
        SegmentTreeMax<ll> vms_max(n+1);
        rep(i, n+1) {
            vps_max.update(i, vps[i]);
            vms_max.update(i, vms[i]);
        }
        rep(i, n+1) {
            ll tmp = vps_max.query(0, i+1) + vms_max.query(0, n-i+1) - (i > 0 ? x[i-1] : 0);
//            cout << i << " " <<vps_max.query(0, i+1) << " " << vms_max.query(0, n-i+1) << " " << (i > 0 ? x[i-1] : 0) << " : " << tmp << endl;
            chmax(ret, tmp);
        }

        vll nx(n);
        rep(i, n) nx[n-i-1] = c-x[i];
        x=nx;
        reverse(all(v));
    }
    cout << ret << endl;

    return 0;
}
