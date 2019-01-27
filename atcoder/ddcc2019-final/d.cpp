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

class data {
public:
    const data operator*(const data& rhs) const;
    uint32_t nd = 0, ni = 0, ns = 0, nc = 0, no = 0;
    uint32_t id_inv = 0;
    uint32_t oc_inv = 0;
    uint32_t ret = 0;
};
const data data::operator*(const data& rhs) const
{
//    cout << "Merge" << endl;
    data tmp;
    tmp.nd = nd + rhs.nd;
    tmp.ni = ni + rhs.ni;
    tmp.ns = ns + rhs.ns;
    tmp.nc = nc + rhs.nc;
    tmp.no = no + rhs.no;

    tmp.id_inv = id_inv + rhs.id_inv + nd * rhs.ni;
    tmp.oc_inv = oc_inv + rhs.oc_inv + nc * rhs.no;
//    cout << mt(oc_inv, nd, ni) << " " << mt(rhs.oc_inv, rhs.nd, rhs.ni) << endl;

    tmp.ret = ret + rhs.ret + oc_inv * rhs.id_inv * rhs.ns + rhs.oc_inv * id_inv * ns;

    return tmp;
}
void print(data x) {
    cout << mt(x.nd, x.ni, x.ns, x.nc, x.no) << " " << mt(x.id_inv, x.oc_inv)  << " " << x.ret << endl;
}

template<class T>
struct SegmentTree {
    int n;
    data e;
    vector<T> dat;
    SegmentTree(int n_ = 0) : n(n_){
        e = data();
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, e);
    }
    T query(int v, int w, int l, int r){
        if(r <= l || w == 0) return e;
        if(r - l == w) {
            /*
            cout << "######" << endl;
            cout << mt(l, r) << endl;
            cout << v << endl;
            print(dat[v]);
            */
//            cout <<"###############" << endl;
//            cout << mt(v, w, l, r) << endl;
//            print(dat[v]);
            return dat[v]; // assert(l == 0 && r == w);
        }
        int m = w/2;

        auto L = query(v*2, m, l, min(r,m));
        auto R = query(v*2+1, m, max(0,l-m), r-m);
//        cout <<"###############" << endl;
//        cout << mt(v, w, l, r) << endl;
//        print(L);
//        print(R);
//        print(L * R);
        return L * R;
    }
    void update(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) {
//            cout << "@@@@@@@@@@@@@@@@@@@@@@" << endl;
//            print(dat[i]);
//            print(dat[i^1]);
            ll p = i / 2;
            dat[p] = dat[2*p] * dat[2*p+1];
            print(dat[p]);
        }
    }
    T query(int l, int r){ return query(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return query(idx, idx + 1); }
};

int main(void) {
    /*
    data L;
    L.nd = L.ni = 1;
    L.id_inv = 1;
    data R;
    R.ns = R.nc = R.no = 1;
    R.oc_inv = 1;

    print(L*R);
    return 0;
    data L;
    L.nc = 1;
    data R;
    R.no = 1;

    print(L*R);
    return 0;
    */
 

    string s; cin >> s;
    ll n = s.length();

    SegmentTree<data> st(n);
    vector<data> d(n);


    rep(i, n) {
        data tmp;
        if (s[i] == 'D') {
            tmp.nd = 1;
        } else if (s[i] == 'I') {
            tmp.ni = 1;
        } else if (s[i] == 'S') {
            tmp.ns = 1;
        } else if (s[i] == 'C') {
            tmp.nc = 1;
        } else if (s[i] == 'O') {
            tmp.no = 1;
        }
        st.update(i, tmp);
        d[i] = tmp;
    }

    {
        auto L = d[5]*d[6]*d[7];
        auto R = d[8]*d[9];
        print(L);
        print(R);
        print(L*R);
    }

    ll q; cin >> q;
    rep(_, q) {
        ll l, r; cin >> l >> r; l--;
//        cout << l << " " << r << endl;
        data ret = st.query(l, r);
        print(ret);
        cout << ret.ret << endl;
    }

    return 0;
}
