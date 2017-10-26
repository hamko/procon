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

ll flip(ll mask, ll i) {
    if (mask & (1ll << i)) {
        mask = (~mask) | (1ll << i);
        mask = ~mask;
    } else {
        mask |= (1ll << i);
    }
    return mask;
}
const ll w = 26;
ll solveDP(string s, bool fast = 1) {
    /*
    if (fast) {
        string t;
        rep(i, s.length()) {
            if (s[i] == s[i+1]) {
                i++;
            } else {
                t += s[i];
            }
        }
        swap(s, t);
    }
    */

    ll n = s.length();
    if (n <= 1) {
        return 1;
    }

    vvll a(w, vll(n+1));
    rep(c, w) {
        rep(i, n) {
            a[c][i+1] = a[c][i] + (s[i] == 'a'+c);
        }
    }

    unordered_map<ll, ll> memo;
    vll masks(n+1);
    ll mask = 0;
    memo[mask] = 0;
    rep(i, n) {
        mask = flip(mask, s[i] - 'a');
        masks[i+1] = mask;
        if (!memo.count(mask)) {
            memo[mask] = i + 1;
        }
//        cout <<i+1<<" " << bits_to_string( mask,w) << "#mask"<<endl;
    }

//    cout << s << endl;
    vll dp(n+1, INF);
    dp[0] = 0;
    repi(i, 1, n+1) {
        ll mask = masks[i];
//        cout << "##############"<<endl;
//        cout << i << " " << bits_to_string(mask,w) <<"Target"<< endl;
        if (memo.count(mask)) {
            ll prev = memo[mask];
            if (prev < i) { // ?
//                cout << prev << " " << bits_to_string(mask, w) << endl;;
                chmin(dp[i], dp[prev] + 1);
            }
        }
        chmin(dp[i], dp[i-1] + 1);
        rep(c, w) {
            ll new_mask = flip(mask, c);
            if (memo.count(new_mask)) {
                ll prev = memo[new_mask];
                if (prev < i) { // ?
//                cout << prev << " " << bits_to_string(new_mask, w) << endl;;
                    chmin(dp[i], dp[prev] + 1);
                }
            }
        }
//        cout << dp[i] << endl;
    }
    return dp[n];
}

ll solve(string s, ll fast = 1) {
    /*
    if (fast) {
        string t;
        rep(i, s.length()) {
            if (s[i] == s[i+1]) {
                i++;
            } else {
                t += s[i];
            }
        }
        swap(s, t);
    }
    */

    ll n = s.length();
    if (n <= 1) {
        return 1;
    }

    vvll a(w, vll(n+1));
    rep(c, w) {
        rep(i, n) {
            a[c][i+1] = a[c][i] + (s[i] == 'a'+c);
        }
    }

    vll dp(n+1, INF);
    vll A(n+1, INF);
    vvll test(n+1, vll(n+1, 2));
    dp[0] = 0;
    repi(i, 1, n+1) {
        rep(j, i) {
            ll counter = 0;
            rep(c, w) {
                counter += (a[c][i] - a[c][j]) % 2 == 1;
            }
            ll f = 0;
            if (counter > 1) {
                test[i][j] = 0;
                f = 1;
            } else {
                test[i][j] = 1;
            }

            if (f)
                continue;
            if (dp[i] > dp[j] + 1) {
                A[i] = j;
                dp[i] = dp[j] + 1;
            }
        }
    }
    return dp[n];
}

int main(void) {
    string s; cin >> s;

    ll dp = solveDP(s);
    cout << dp << endl;
    /*
    ll ret = solve(s);
    cout << ret << endl;
    assert(dp == ret);
    */

    return 0;
}
