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
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using Pos = complex<double>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
struct ci : public iterator<forward_iterator_tag, ll> { ll n; ci(const ll n) : n(n) { } bool operator==(const ci& x) { return n == x.n; } bool operator!=(const ci& x) { return !(*this == x); } ci &operator++() { n++; return *this; } ll operator*() const { return n; } };

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
template <typename T,typename U> class umap:public std::unordered_map<T,U,myhash::myhash<T>> { public: using MAP=std::unordered_map<T,U,myhash::myhash<T>>; umap():MAP(){MAP::rehash(myhash::Bsizes[rand()%20]);} };    

struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); srand((unsigned int)time(NULL)); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40)


#define PTHREAD
 
#if defined(_WIN32)
extern "C" {
    void* __stdcall LoadLibraryA(const char *name);
    void* __stdcall GetProcAddress(void *handle, const char *name);
}
struct DynamicLibrary {
    DynamicLibrary(const char *name) { _handle = LoadLibraryA(name); }
    void *get(const char *name) const { void *p = GetProcAddress(_handle, name); if(!p) cerr << "can't find: " << name << endl, abort(); return p; }
    void *_handle;
#ifndef PTHREAD
} gmp("mpir.dll");
#else
} libpthread("Pthread.dll");
#endif
#else
extern "C" {
    void* __libc_dlopen_mode(const char *x, int y);
    void* __libc_dlsym(void *x, const char *y);
}
struct DynamicLibrary {
    DynamicLibrary(const char *name) { _handle = __libc_dlopen_mode(name, 2); }
    void *get(const char *name) const { void *p = __libc_dlsym(_handle, name); if(!p) cerr << "can't find: " << name << endl, abort(); return p; }
    void *_handle;
#ifndef PTHREAD
} gmp("/usr/lib/x86_64-linux-gnu/libgmp.so.10");	// hamko
#else
} libpthread("/lib/x86_64-linux-gnu/libpthread.so.0");	// hamko
//} libpthread("/usr/lib64/libpthread.so.0");	// yukicoder
#endif
#endif
 
#define EXPAND_MACRO_TO_STR_2(a) #a
#define EXPAND_MACRO_TO_STR(a) EXPAND_MACRO_TO_STR_2(a)
 
#ifndef PTHREAD
#include <gmp.h>
#define D(name) const auto my_##name = (decltype(::name)*)gmp.get(EXPAND_MACRO_TO_STR(name))
D(mpz_init_set_str);
D(mpz_popcount);
#else
#define D(name) const auto my_##name = (decltype(::name)*)libpthread.get(EXPAND_MACRO_TO_STR(name))
D(pthread_create);
D(pthread_join);
D(pthread_mutex_lock);
D(pthread_mutex_unlock);
#endif
 
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
 
int flag=1;
int balance=10000;
int cash=0;
 
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
 
function<void(ll)> parallel_rep_solve;
vll parallel_rep_range;
void* parallel_rep_helper(void* arg) {
    //    cout << (*(ll*)arg) << endl;
    ll l = parallel_rep_range[0 + *(ll*)arg];
    ll r = parallel_rep_range[1 + *(ll*)arg];
    free(arg);
    //    cout << l << " " << r << "#thread" << endl;
    repi(j, l, r)
        parallel_rep_solve(j);
    return NULL;
}
void parallel_rep(int n, function<void(ll)> f, ll thnum = 50) {
    if (thnum == 1) { rep(i, n) f(i); return; } // やりたいこと
 
    parallel_rep_solve = f;
    parallel_rep_range.resize(thnum);
    rep(i, thnum) parallel_rep_range[i] = i * n / thnum;
    parallel_rep_range.pb(n);
    //    cout << parallel_rep_range << endl;
    vector<pthread_t> t(thnum);
    rep(i, thnum) {
        ll* i_pointer = (ll*)malloc(sizeof(ll));
        *i_pointer = i;
        my_pthread_create(&t[i], NULL, parallel_rep_helper, i_pointer);
    }
    rep(i, thnum) {
        my_pthread_join(t[i], NULL);
    }
}
 
//------------------
 
 

int main(void) {
    string s; cin >> s; 
    string s_org = s;

    rep(i, s.length()) {
        rep(ci, 26) if (s_org[i] != 'a' + ci) {
            char c = 'a' + ci;
            s = s_org;
            s[i] = c;
            ll faf = 1;
            rep(i, s.length()) {
                faf &= (s[i] == s[s.length()-i-1]);
            }
            if (faf) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
