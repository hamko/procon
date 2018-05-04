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

// Strict LIS
ll LISa(vector<ll> a) {
    // dp[i][len] = [0, i]のから取れる長さlenのLISを想定した時、その最後の要素として考えられる最小の値
    // iはdpテーブルを使い回している
    vll dp; dp.reserve(100000);
    rep(i, a.size()) {
        auto it = lower_bound(all(dp), a[i]);
        if (it == dp.end()) 
            dp.pb(a[i]);
        else
            *it = a[i];
    }
    return dp.size();
}
// Strict LIS
ll LISd(vector<ll> b) {
    vector<ll> a = b;
    rep(i, a.size()) {
        a[i] *= -1;
    }
    // dp[i][len] = [0, i]のから取れる長さlenのLISを想定した時、その最後の要素として考えられる最小の値
    // iはdpテーブルを使い回している
    vll dp; dp.reserve(100000);
    rep(i, a.size()) {
        auto it = lower_bound(all(dp), a[i]);
        if (it == dp.end()) 
            dp.pb(a[i]);
        else
            *it = a[i];
    }
    return dp.size();
}

vvll used;
void brutal(ll n) {
    used=vvll(n+1,vll(n+1));
    vll id(n);
    map<P, vll> memo;
    rep(i, n) {
        id[i] = 1+i;
    }
    do {
        chmax(memo[P(LISa(id),LISd(id))], id);
    } while (next_permutation(all(id)));
    for (auto x : memo) {
        used[x.fi.fi][x.fi.se] = 1;
        if (x.fi.fi >= x.fi.se)
            cout << x.fi << " " << x.se << endl;
    }
    rep(i, n+1) {
        rep(j,n+1){
            cout << used[i][j];
        }
        cout << endl;
    }

}

vll solve(ll n, ll a, ll b) {
    if (a+b>n+1) {
        return {-1};
    }
    bool swapped = 0;
    if (b > a) swap(a, b), swapped = 1;

    ll b0 = (n + a - 1) / a;
    ll rem = (n % a == 0 ? a : n % a);
    vll r;
    for (ll i = n; rem; i--, rem--) {
        r.pb(i);
    }
    reverse(all(r));
    if (b - b0 < 0) {
        return {-1};
    }
    if (b-b0+1 > r.size()) {
        return {-1};
    }
    reverse(r.begin(), r.begin()+b-b0+1);
    vll ret;
    rep(i, r.size()) {
        ret.pb(r[i]);
    }
    rep(i, b0-1) {
        rep(j, a) {
            ret.pb((b0-2-i)*a+j+1);
        }
    }

    if (swapped) {
        rep(i, ret.size()) {
            ret[i] = n+1-ret[i];
        }
        swap(a, b);
    }

    if (LISa(ret) != a || LISd(ret) != b) {
        cout << "##########################################" << endl;
        cout << n << " " << a << " " << b << endl;
    }
    return ret;
}

int main(void) {
    ll n,a,b;cin>>n>>a>>b;
    if (a+b>n+1) return cout << -1 << endl, 0;
    if (a*b<n) return cout << -1 << endl, 0;
    vll ret; 
    vll tmp;
    rep(j, b) {
        tmp.pb(1+j);
    }
    rep(j, tmp.size()) ret.pb(tmp[tmp.size()-1-j]);


    n -= a + b - 1;
    rep(i, a-1) {
        vll tmp;
        tmp.pb(1+b*(i+1));
        if (n) {
            rep(j, b-1) {
                if (n) {
                    tmp.pb(1+b*(i+1)+(j+1));
                    n--;
                }
            }
        }
        rep(j, tmp.size()) ret.pb(tmp[tmp.size()-1-j]);
    }
//    cout << ret << endl;
    vll t = ret;
    sort(all(t));
    map<ll, ll> memo;
    rep(i, t.size()) {
        memo[t[i]] = i;
    }
    rep(i, ret.size()) {
        cout << memo[ret[i]] + 1<< " ";
    }
    cout << endl;

    if (LISa(ret)  != a || LISd(ret) != b) {
        cout << "#HIT "<< endl;
        cout << a << " " << b << endl;
        cout << ret << endl;
    }


    /*
       auto ret = solve(n, a, b);
       cout << ret << endl;
       brutal(n);
       repi(i, 1, n+1)repi(j,1,n+1) {
       if ((used[i][j] == 0) ^ (solve(n, i, j)[0] == -1)) {
       cout << "#HIT" << endl;
       cout << n << " " << i << " " << j << endl;
       cout << used[i][j] << " " << solve(n, i, j)<< "#exists" << endl;

       }
       }
       */
    return 0;
}
