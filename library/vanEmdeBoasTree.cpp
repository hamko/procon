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


// http://natsugiri.hatenablog.com/entry/2016/10/12/021502
// Ordered Setだからすごい！！

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// VEB
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
struct VEB_BASE {
    static const unsigned long long INVALID = ~0;

    unsigned long long mi, ma;

    VEB_BASE() : mi(INVALID), ma(0) { }

    inline unsigned long long min() const { return mi; }

    inline unsigned long long max() const { return mi <= ma? ma: INVALID; }

    inline bool empty() const { return ma < mi; }
};

// van Emde Boas Tree 2P-bit (upper P-bit and lower P-bit, 0 ~ 2^(2P)-1);
template<const unsigned long long P> struct VEB_NODE : VEB_BASE { 
    typedef VEB_NODE<(P>>1)> Child;

    long long ch_len;
    Child aux, *ch;

    VEB_NODE() : VEB_BASE(), ch_len(0), aux(), ch(NULL) { }

    VEB_NODE(long long n_) : VEB_BASE(), ch_len(0), aux(), ch(NULL) {
	long long r = n_ & ((1ull<<P) - 1ull);
	ch_len = (n_ >> P) + (bool)r;
	ch = new Child[ch_len];
	if (r) {
	    for (long long i=0; i<ch_len-1; i++) ch[i] = Child(1ull << P);
	    ch[ch_len-1] = Child(r);
	} else {
	    for (long long i=0; i<ch_len; i++) ch[i] = Child(1ull << P);
	}
	aux = Child(ch_len);
    }

    unsigned long long next(unsigned long long u) const {
	if (ma <= u) return INVALID;
	if (u < mi) return mi;
	unsigned long long hi = u >> P, lo = u & ((1ull << P) - 1ull);
	if (lo < ch[hi].ma) return (hi << P) | ch[hi].next(lo);
	hi = aux.next(hi);
	return (hi << P) | ch[hi].mi;
    }

    unsigned long long prev(unsigned long long u) const {
	if (u <= mi) return INVALID;
	if (ma < u) return ma;
	unsigned long long hi = u >> P, lo = u & ((1ull << P) - 1ull);
	if (ch[hi].mi < lo) return (hi << P) | ch[hi].prev(lo);
	hi = aux.prev(hi);
	return hi == INVALID? mi: (hi << P) | ch[hi].ma;
    }

    bool find(unsigned long long u) const {
	return !empty() && (u == min() || ch[u >> P].find(u & ((1ull << P) - 1ull)));
    }

    bool insert(unsigned long long u) {
	if (empty()) {
	    mi = ma = u;
	    return true;
	}
	if (u < mi) swap(mi, u);
	if (mi < u) {
	    unsigned long long hi = u >> P, lo = u & ((1ull << P) - 1ull);
	    if (ma < u) ma = u;
	    if (ch[hi].empty()) aux.insert(hi);
	    return ch[hi].insert(lo);
	}
	return false;
    }

    bool erase(unsigned long long u) {
	if (empty()) {
	    return false;
	} else if (mi == u) {
	    if (ma == u) {
		mi = INVALID; ma = 0;
		return true;
	    } else {
		mi = u = (aux.mi << P) | ch[aux.mi].mi;
	    }
	}
	if (ch[u >> P].erase(u & ((1ull << P) - 1ull))) {
	    if (ch[u >> P].empty()) aux.erase(u >> P);
	    if (ma == u) {
		if (aux.empty()) ma = mi;
		else ma = (aux.ma << P) | ch[aux.ma].ma;
	    }
	    return true;
	} else {
	    return false;
	}
    }

    void clear() {
	if (ch) {
	    for (long long i=0; i<ch_len; i++) ch[i].clear();
	    aux.clear();
	    delete[] ch; ch = NULL;
	}
    }
};

// vEB 6-bit (0 ~ 63);
template<> struct VEB_NODE<3> : VEB_BASE {
    unsigned long long mask;

    VEB_NODE() : VEB_BASE(), mask(0) { }

    VEB_NODE(long long n_) : VEB_BASE(), mask(0) { }

    static inline unsigned long long ctz(unsigned long long u) {
#ifdef __GNUC__
	return __builtin_ctzll(u);
#else
//	When __builtin_ctzll is not defined;
	unsigned long long n = 0;
	if ((u & 0x00000000FFFFFFFFULL) == 0) { u >>= 32; n += 32; }
	if ((u & 0x000000000000FFFFULL) == 0) { u >>= 16; n += 16; }
	if ((u & 0x00000000000000FFULL) == 0) { u >>=  8; n +=  8; }
	if ((u & 0x000000000000000FULL) == 0) { u >>=  4; n +=  4; }
	static const unsigned long long ctz_4bit[16] = { 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, };
	return n + ctz_4bit[u & 0xFULL]; // if u == 0: return 64;
#endif
    }
    
    static inline unsigned long long lg(unsigned long long u) {
#ifdef __GNUC__
	return __lg(u);
#else
//	When __builtin_clzll and __lg are not defined;
	unsigned long long n = 0;
	if (u & 0xFFFFFFFF00000000ULL) { u >>= 32; n += 32; }
	if (u & 0x00000000FFFF0000ULL) { u >>= 16; n += 16; }
	if (u & 0x000000000000FF00ULL) { u >>=  8; n +=  8; }
	if (u & 0x00000000000000F0ULL) { u >>=  4; n +=  4; }
	static const unsigned long long lg_4bit[16] = { 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, };
	return n + lg_4bit[u]; // if u == 0: return 0;
#endif
    }

    unsigned long long next(unsigned long long u) const {
	if (ma <= u) return INVALID; // empty or ma <= u;
	if (u < mi) return mi;
	return ctz(mask & ~((1ULL << (u+1)) - 1));
    }

    unsigned long long prev(unsigned long long u) const {
	if (u <= mi) return INVALID; // empty or u <= mi;
	if (ma < u) return ma;
	unsigned long long k = mask & ((1ULL << u) - 1);
	return k? lg(k): mi;
    }

    bool find(unsigned long long u) const {
	return !empty() && (min() == u || (mask & (1ULL << u)));
    }

    bool insert(unsigned long long u) {
	if (empty()) {
	    mi = ma = u;
	    return true;
	}
	if (u < mi) swap(mi, u);
	if (mi < u) {
	    if (ma < u) ma = u;
	    if (mask & (1ULL << u)) return false;
	    mask |= 1ULL << u;
	    return true;
	}
	return false;
    }

    bool erase(unsigned long long u) {
	if (mi == u) {
	    if (ma == u) {
		mi = INVALID; ma = 0;
		return true;
	    }
	    mi = ctz(mask); mask &= ~(1ULL << mi);
	    return true;
	} else if (u == ma) {
	    mask &= ~(1ULL << u);
	    if (mask) ma = lg(mask);
	    else ma = mi;
	    return true;
	} else if (mi < u) { // if mi < u < ma;
	    if (mask & (1ULL << u)) {
		mask &= ~(1ULL << u);
		return true;
	    }
	}
	return false;
    }

    void clear() { // has nothing to clear;
    }
};

// vEB 24-bit;
typedef VEB_NODE<12> VEB;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// VEB
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main() {
    {
        VEB veb(100);

        veb.insert(3); 
        cout << "inserted " << 3 << endl;
        veb.insert(5); 
        cout << "inserted " << 5 << endl;
        veb.insert(8); 
        cout << "inserted " << 8 << endl;
        veb.insert(13);
        cout << "inserted " << 13 << endl;

        if (!veb.empty()) puts("not empty");

        if (veb.find(3)) puts("I have 3.");

        if (veb.next(4) != veb.INVALID)
            cout << "next 4" << veb.next(4) << endl;
        if (veb.next(5) != veb.INVALID) 
            cout << "next 5" << veb.next(5) << endl;

        if (veb.prev(4) != veb.INVALID) 
            cout << "prev 4" << veb.prev(4) << endl;
        if (veb.prev(3) == veb.INVALID)
            cout << "prev 3 is INVALID" << endl;

        veb.erase(3);
        puts("erase(3)");

        if (veb.min() != veb.INVALID && veb.max() != veb.INVALID)
            cout << "min : " << veb.min() << ", max " << veb.max() << endl;

        unsigned long long u = veb.min();
        while (u != veb.INVALID) {
            cout << "I have " << u << endl;
            u = veb.next(u);
        }

        veb.clear();
    }

    {
        ll n = 1ll<<25; // VEB_NODE<M>, n <= 1ll << (2*M) !!!!!!!!!!!!!!!!
#if 1
        cout << "veb" << endl;
        VEB_NODE<24> veb(n);
        rep(i, n)
            veb.insert(i);
#else
        cout << "s" << endl;
        unordered_set<int> s;
        rep(i, n) 
            s.insert(i);
#endif
    }

    return 0;
}
