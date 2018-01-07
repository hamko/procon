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

// [l, r)の値を管理している時の状態をadd, del, outputで管理する。
// add(i)
//      i=l-1かi=rが来る。
//      この後、管理すべき値は[l-1, r)もしくは[l, r+1)になる
// del(i)
//      i=lかi=r-1が来る。
//      この後、管理すべき値は[i+1, r)もしくは[l, r-1)になる
// output()
//      今の時点での管理している値を出力する。

// 以下はDQUERYの実装。
template <typename T, typename OUT>
class MoState {
public:
    ll n; 
    vector<T> a;
    MoState(vector<T>& a_) {
        a = a_;
        n = a.size();

        freq.resize(1e6+10);
    }

    vll freq;
    ll ret = 0;
    void add(ll i) {
        if (freq[a[i]] == 0) ret++;
        freq[a[i]]++;
    }
    void del(ll i) {
        if (freq[a[i]] == 1) ret--;
        freq[a[i]]--;
    }
    OUT output(void) {
        return ret;
    }

};

template <typename T, typename OUT> 
class Mo {
public:
    MoState<T, OUT>* s;
    function<bool(ll, ll)> f = [&](ll i, ll j) -> bool {
        ll bi = l[i] / w;
        ll bj = l[j] / w;
        if (bi != bj) return bi < bj;
        if (r[i] == r[j]) return l[i] < l[j];
        return (bi & 1) ^ (r[i] < r[j]);
    };

    ll q = 0, w = -1; // q: query size, w: query backet width
    vll l, r; // query for [l[i], r[i]), where l.size() == q and r.size() == q
    vll id; // the order of queries
    void setWidth(ll w_) { w = w_; }


    Mo(vector<T>& a_) {
        s = new MoState<T, OUT>(a_);
    }
    void insert(ll li, ll ri) {
        q++;
        l.pb(li);
        r.pb(ri);
    }
    void build(void) {
        assert(q);
        if (w < 0) w = sqrt(q);
        id.resize(q);
        iota(all(id), 0);
        sort(all(id),f);
    }
    
    ll ptr = 0; // 次にprocessが呼ばれた時に行うべきクエリ
    ll now_i = 0, now_j = 0;
    tuple<ll, OUT> process() {
        if (ptr == q) return mt(-1, -1); 
        ll target_i = l[id[ptr]], target_j = r[id[ptr]];
        // ++, --とadd, delの順序が違うのは、半開区間の開閉区間どちらかによる
        while (now_i > target_i) now_i--, s->add(now_i);
        while (now_i < target_i) s->del(now_i), now_i++;
        while (now_j > target_j) now_j--, s->del(now_j);
        while (now_j < target_j) s->add(now_j), now_j++;
        return mt(id[ptr++], s->output());
    }
    
    void print(void) {
        rep(i, q) {
            cout << l[id[i]] << " " << r[id[i]] << endl;
        }
    }
};


int main(int argc, char** argv) {
    ll n; cin >> n;
    vll a(n);
    cin >> a;
    ll q; cin >> q;

//    Mo<ll/*vector<ll>の静的配列に関する*/,
//       ll/*ll(ll l, ll r)のクエリを処理する*/> m(a);
    Mo<ll, ll> m(a);
    
    // 幅はデフォルトではsqrt(q)
    // 調整して設定する場合はsetWidthを使う
    ll w = 90;
    m.setWidth(w);
    rep(_, q) {
        ll l, r; cin >> l >> r; l--;
        // 処理すべき半開区間のクエリを追加する
        m.insert(l, r);
    }
    m.build();

    vll ret(q);
    rep(_, q) {
        ll id, out; tie(id, out) = m.process();
        ret[id] = out;
    }
    rep(_, q) {
        cout << ret[_] << endl;
    }

    return 0;
}
