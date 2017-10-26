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
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

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
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
template <typename T> ostream &operator<<(ostream &o, const priority_queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} o << endl; return o; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define rand randxor

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

#if 1

// Incremental Convex Hull Trick
// N<=1000000に注意
//
// 追加ax+bのaが単調減少 O(1)
// 質問クエリf(x)のxが単調増加 O(1)
namespace CHT{
    using TYPE=long long;
    pair<TYPE,TYPE> mem[1000000];
    template<typename T>
        inline bool is_minimam(T a1,T b1,T a2,T b2,T a3,T b3){return (a2-a1)*(b3-b2)>=(b2-b1)*(a3-a2);}
    template<typename T>
        inline bool is_maximam(T a1,T b1,T a2,T b2,T a3,T b3){return is_minimam(-a1,-b1,-a2,-b2,-a3,-b3);}
    template<typename T>
        inline bool check(pair<T,T> L1,pair<T,T> L2,pair<T,T> L3){
            return is_minimam(L1.first,L1.second,L2.first,L2.second,L3.first,L3.second);
        }
    template<typename T>
        inline T calc(pair<T,T> L,T now){
            return L.first*now+L.second;
        }
};
template<typename T>
ostream& operator<<(ostream& os,pair<T,T> t){
    os <<"("<< t.first << " "<<t.second << ")";
    return os;
}
template<typename T>
class convex_hull_trick{
    pair<T,T> *deque;
    int s,t;
    public:
    convex_hull_trick(pair<T,T> *mem):deque(mem),s(0),t(0){}
    convex_hull_trick():convex_hull_trick(CHT::mem){}
    void add(T a,T b){
        auto L=make_pair(a,b);
        while(s+1<t&&CHT::check(deque[t-2],deque[t-1],L))t--;
        deque[t++]=L;
    }
    T get(T now){
        while(s+1<t&&CHT::calc(deque[s],now)>=CHT::calc(deque[s+1],now))s++;
        return CHT::calc(deque[s],now);
    }
    void pop(){
        while(s+1<t&&CHT::calc(deque[s])>=CHT::calc(deque[s+1]))s++;
    }
};


ll dp[300010];
int main(void) {
    ll n, a, b, w; cin >> n >> a >> b >> w;
    vll d(n); cin >> d;
    repi(i, 1, n+10) dp[i] = INF;
    dp[0] = 2ll*w;

    convex_hull_trick<ll> c;
    // 集めるDP
    repi(i, 1, n+1) {
        /*
        rep(k, i) 
            chmin(dp[i], i*(-2*k*b)+(dp[k]+b*k*k+k*b+2*k*a));
        dp[i] += i*i*b-i*b-2*i*a+2*a+2*d[i-1];
        */
        ll k = i-1;
        c.add(-2*k*b, dp[k]+b*k*k+k*b+2*k*a);
        dp[i] = c.get(i);
        dp[i] += i*i*b-i*b-2*i*a+2*a+2*d[i-1];
    }
    ll ret = INF;
    rep(k, n+1) {
        chmin(ret, dp[n-k]+k*(k+1)*b-k*a*2ll);
    }
    cout << ret / 2 << endl;

    return 0;
}
#else
ll dp[300010];
int main(void) {
    ll n, a, b, w; cin >> n >> a >> b >> w;
    vll d(n); cin >> d;
    repi(i, 1, n+10) dp[i] = INF;
    dp[0] = 2ll*w;

    // 集めるDP
    repi(i, 1, n+1) {
        rep(k, i) {
            chmin(dp[i], dp[i-k-1] + k*(k+1ll)*b-k*a*2ll+d[i-1]*2ll);
        }
    }
    double ret = INF;
    rep(k, n+1) {
        chmin(ret, dp[n-k]+k*(k+1)*b-k*a*2ll);
    }
    cout << ret / 2 << endl;

    return 0;
}

#endif
