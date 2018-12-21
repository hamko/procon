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

ll n;
P judge(vll& a, vll& as, ll k, ll l) {
    assert(l >= 2 && l < n-1);
    // a[0, l)をどっかで切ってその差をk以下にできるか？
    
    // a[0, x) > a[x, l)となるような最小のxを求める
    // 1 <= x < l
    // 両端縛りのにぶたん
    ll ng = 0, ok = l;
    while (ok - ng > 1) {
        ll x = (ok + ng) / 2;
        (as[x]-as[0]>as[l]-as[x]?ok:ng)=x;
    }

    // 調べるべきは
    // a[0, x)とa[x, l)の差
    // a[0, x-1), a[x-1, l)の差
    // のmin
    //
    // ただ、x-1>0が必要
    ll ret = INF;
    P p;
    if (ok < l) { // あやしい
        ll tmp = abs((as[ok]-as[0])-(as[l]-as[ok]));
        if (ret > tmp) { 
            ret = tmp;
            p = P(as[ok] - as[0], as[ok] - as[l]);
        }
    }
    if (ok-1>0) {
        ll tmp = abs((as[ok-1]-as[0])-(as[l]-as[ok-1]));
        if (ret > tmp) { 
            ret = tmp;
            p = P(as[ok-1] - as[0], as[ok-1] - as[l]);
        }
    }
    p.fi = abs(p.fi);
    p.se = abs(p.se);
    return p;
}

P judgeB(vll& a, vll& as, ll k, ll l) {
    assert(l >= 2 && l < n-1);
    ll ret = INF;
    P p;
    repi(x, 1, l) {
        // a[0, x), a[x, l)
        ll tmp =abs((as[x]-as[0])-(as[l]-as[x]));
        if (ret > tmp) {
            ret = tmp;
            p = P(as[x]-as[0],as[l]-as[x]);
        }
    }
    p.fi = abs(p.fi);
    p.se = abs(p.se);
//    cout << ret << endl;
    return p;
}

int main(void) {
    cin >> n;
    vll a(n); cin >> a;
    vll ar = a;
    reverse(all(ar));
    vll as(n+1), ars(n+1);
    rep(i, n) as[i+1]=as[i]+a[i], ars[i+1]=ars[i]+ar[i];

    /*
    rep(i, n) {
        ll k = 1, l = 3;
        if (judge(ar, ars, k, l)!=judgeB(ar,ars,k,l)) {
            cout << "HIT"<< endl;
            cout << ar << " " << k << " " << l << " : " << judge(ar, ars, k, l) << " " << judgeB(ar,ars,k,l)<< endl;
        }
    }
    */

    ll ret = INF;
    repi(l, 2, n-1) {
        P s = judge(a, as, -1, l);
        P t = judge(ar, ars, -1, n-l);
//        cout << l << " " << s << " " << t << endl;
        vll hoge = {s.fi, s.se, t.fi, t.se};
        ll tmp = *max_element(all(hoge))-*min_element(all(hoge));
        chmin(ret, tmp);

    }
    cout <<ret << endl;

    /*
    // min, maxをok以下だとするならば作れる
    //
    ll ng = 0, ok = 1e9+10;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        vector<bool> hoge;
        bool f = 0;
        repi(l, 2, n-1) {
            if (judge(a, as, mid, l)&&judge(ar, ars, mid, n-l)) {
                f = 1;
                hoge.pb(f);
            }
        }
        cout << mid << " " << hoge << endl;

        (f ? ok : ng) = mid;
    }
    cout << ok << endl;
    */

    return 0;
}
