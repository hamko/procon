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
struct init_{init_(){ gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

ll num = 0;
vector<P> memo;
template<class T>
struct SegmentTreeMin {
    int n;
    T inf;
    vector<T> dat;
    
    SegmentTreeMin(void){}
    SegmentTreeMin(int n_ = 0) : n(n_){
        inf = 0;
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, inf);
    }
    T query(int v, int w, int l, int r){
        if(r <= l || w == 0) return inf;
        if(r - l == w) {
            if (dat[v] % num) {
                memo.pb(P(v, dat[v]));
            }
            return dat[v]; 
        }
        int m = w/2;
        return __gcd(query(v*2, m, l, min(r,m)), query(v*2+1, m, max(0,l-m), r-m));
    }
    void update(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) dat[i/2] = __gcd(dat[i], dat[i^1]);
    }
    T query(int l, int r){ return query(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return query(idx, idx + 1); }
};
SegmentTreeMin<ll> st(1);

bool evaluate(void) {
    while (memo.size()) {
        if (memo.size() > 1) return 0;
        P tmp = memo.back(); memo.pop_back();
        ll v = tmp.fi;
        if (v*2+1>=st.n*2) {
            return 1;
        }
        if (st.dat[v*2] % num) {
            memo.pb(P(v*2, st.dat[v*2]));
        }
        if (st.dat[v*2+1] % num) {
            memo.pb(P(v*2+1, st.dat[v*2+1]));
        }
    }
    return 1;
}

int main(void) {
    int n; input(n);
    st = SegmentTreeMin<ll>(n);
    vll a(n);
    rep(i, n) {
        int x; input(x);
        a[i]= x;
        st.update(i, x);
    }

    int q; input(q);
    rep(_, q) {
        int type; input(type);
        if (type == 1) {
//            cout <<"#############"<<endl;
            int l,r,x; input(l);input(r);input(x);l--;
            num = x;
//            rep(i, n) cout << st[i] << " "; cout << endl;
            memo.clear();
            st.query(l, r);
//            cout << memo << endl;
            bool ret = evaluate();
//            cout << evaluate() << endl;
            cout << (ret ? "YES" : "NO") <<  endl;
        } else {
            int i,y; input(i);input(y);i--;
            st.update(i, y);
        } 
    }

    return 0;
}

/*
vector<int> a(5e5+10);
vector<SegmentTreeMin<int8_t>> sts;
int main(void) {
    constructPrime(100000);
    int n; input(n);
    rep(i, n) {
        int x; input(x);
        a[i]= x;
    }
    rep(i, 1000) {
        cout << i << endl;
        if (isPrime(i)) {
            sts.pb(SegmentTreeMin<int8_t>(n));
        } else {
            sts.pb(SegmentTreeMin<int8_t>(1));
        }
    }


    int q; input(q);
    rep(_, q) {
        int type; input(type);
        if (type == 1) {
            int l,r,x; input(l);input(r);input(x);
        } else {
            int i,y; input(i);input(y);
        } 
    }

    return 0;
}
*/
