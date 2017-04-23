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

int main(void) {
    ll _; cin >> _;
    rep(__, _) {
        ll r, c; cin >> r >> c;
        vector<string> ret;
        map<char, P> memo;
        rep(i, r) {
            string tmp; cin >> tmp;
            ret.pb(tmp);
            rep(j, c) if (tmp[j] != '?') {
                memo[tmp[j]] = P(i, j);
            }
        }

        map<tuple<ll, ll, ll, ll>, ll> cmemo;
        function<ll(ll, ll, ll, ll)> 
            countAlphabets = [&](ll i1, ll i2, ll j1, ll j2) {
            if (cmemo.count(mt(i1, i2, j1, j2))) return cmemo[mt(i1, i2, j1, j2)];
            if (i1 < 0) return -1ll; if (i2 < 0) return -1ll;
            if (j1 < 0) return -1ll; if (j2 < 0) return -1ll;
            if (i1 > r - 1) return -1ll; if (i2 > r - 1) return -1ll;
            if (j1 > c - 1) return -1ll; if (j2 > c - 1) return -1ll;
            vll counter(256);
            repi(i, i1, i2+1) repi(j, j1, j2+1) if (ret[i][j] != '?')
                counter[ret[i][j]]++;
            return cmemo[mt(i1, i2, j1, j2)] = accumulate(all(counter), 0ll);
        };
        
        for (auto pos : memo) {
            char x = pos.fi; ll i = pos.se.fi, j = pos.se.se;
            ll max_area = 1;
            ll mi1 = i;
            ll mi2 = i;
            ll mj1 = j;
            ll mj2 = j;
            rep(i1, r+5) rep(i2, r+5) rep(j1, c+5) rep(j2, c+5) {
                if (i1 <= i && i <= i2 && j1 <= j && j <= j2) {
                if (i1 <= i2 && j1 <= j2 && 
                        i1 >= 0 && i2 >= 0 && j1 >= 0 && j2 >= 0 && 
                        i1 < r && i2 < r && j1 < c && j2 < c) {
                    if (countAlphabets(i1, i2, j1, j2) == 1) {
                        if (max_area < (i2 - i1 + 1) * (j2 - j1 + 1)) {
                            max_area = (i2 - i1 + 1) * (j2 - j1 + 1);
                            mi1 = i1;
                            mi2 = i2;
                            mj1 = j1;
                            mj2 = j2;
                        }
                    }
                }
                }
            }
                
            repi(ii, mi1, mi2+1) repi(jj, mj1, mj2+1) {
                if (ret[ii][jj] != x)
                    assert(ret[ii][jj] == '?');
                ret[ii][jj] = x;
            }
        }

        ll faf = 0; rep(i, r) rep(j, c) faf |= (ret[i][j] == '?');
        assert(!faf);

        cout << "Case #" << __+1 << ":" << endl;
        rep(i, r) {
            cout << ret[i] << endl;
        }
    }
    return 0;
}
