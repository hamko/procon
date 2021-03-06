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
void init(void) {
    gettimeofday(&start, NULL); 
    srand((unsigned int)time(NULL)); 
    random_seed = RAND_MAX / 2 + rand() / 2; 
}

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

#define DEBUG 

double TL = 2;


typedef struct data_ {
    vll m; // TODO 本当はグローバルメモリのBFSしたい
    vll p;
    P info;
    double score;

    // TODO 良い特徴があればここに入れて比較関数を何とかする
    bool operator<( const data_& right ) const {
        return score > right.score;
    }
} data;

vll di = {1, 0, -1, 0}, dj = {0, 1, 0, -1};
class ConnectedComponent {
    public:
    int n;
    char b[512][512];
    double getPoint(P x) {
        return 1.*x.se * sqrt(x.fi);
    }
    P evaluate(vll& p) {
        bool used[512][512] = {};
        char mp[512][512];
        rep(i, n) rep(j, n) mp[i][j] = b[p[i]][p[j]];
        function<P(ll, ll)> dfs = [&](ll i, ll j) {
            if (i < 0 || i >= n || j < 0 || j >= n || used[i][j] || mp[i][j] == 0) return P(0, 0);
            used[i][j] = 1;
            ll s = 1, ret = mp[i][j];
            rep(d, 4) {
                auto tmp = dfs(i+di[d], j+dj[d]);
                s += tmp.fi, ret += tmp.se;
            }
            return P(s, ret);
        };
        double opt_point = -INF;
        P ret = P(-1, -1);
        rep(i, n) rep(j, n) { 
            auto tmp = dfs(i, j);
            double point = getPoint(tmp);
            if (opt_point < point) opt_point = point, ret = tmp;
        }
        return ret;
    }
    void print(vll& p) {
#ifdef DEBUG 
        char mp[512][512];
        rep(i, n) rep(j, n) mp[i][j] = b[p[i]][p[j]];
        cout << p << " : point " << getPoint(evaluate(p)) << " with " << evaluate(p) << endl;
        rep(i, n) {
            rep(j, n) cout << (int)mp[i][j] << "\t";
            cout << endl;
        }
#endif
    }
    data randomTransite(data x) {
        ll u = -1, v = -1;
        while (u == v) u = rand() % n, v = rand() % n;

        ll ui = -1, vi = -1;
        rep(i, n) if (x.p[i] == u) ui = i; else if (x.p[i] == v) vi = i;
        swap(x.p[ui], x.p[vi]);

        rep(j, n) swap(x.m[u*n+j], x.m[v*n+j]); // TODO この情報使ってないじゃん！！dataを入力するタイプの評価関数が必要（高速化のために）
        rep(i, n) swap(x.m[i*n+u], x.m[i*n+v]);

        x.info = evaluate(x.p);
        x.score = getPoint(x.info);

        return x;
    }
    vector<int> permute(vector<int> m) {
        init();
        n = (int)sqrt(m.size());
        rep(i, m.size()) {
            b[i/n][i%n] = m[i];
        }
        vector<int> p(n); rep(i, n) p[i] = i;

        double score = -INF;
        bitset<250000> used;
        ll cyc = 0;
        while (1) { cyc++; 
            if (cyc % 1 == 0) {
                cout << cyc << " " << sec() << " " << score << endl;
//                cout << p << endl;
            }
            if (cyc % 1 == 0 && sec() > TL) { // cyc % 10 == 0は、あまりいっぱいsec()を呼ばないため
                break;
            }

            ll u = -1, v = -1;
            while (u == v) u = rand() % n, v = rand() % n;
            rep(j, n) swap(m[u*n+j], m[v*n+j]);
            rep(i, n) swap(m[i*n+u], m[i*n+v]);
            {
                ll ui = -1, vi = -1;
                rep(i, n) if (p[i] == u) ui = i; else if (p[i] == v) vi = i; 
                swap(p[ui], p[vi]);
            }


            // evaluate
            double next_score = -INF;
            queue<ll> q;
            used.reset();
            function<void(ll, ll)> f = [&](ll i, ll j) {
                ll tmp_num = 1;
                double tmp_score = m[i*n+j];
                q.push(i*n+j);
                used[i*n+j] = 1;
                while (q.size()) {
                    ll curr_ij = q.front(); q.pop();
                    rep(d, di.size()) {
                        ll ni = curr_ij/n+di[d];
                        ll nj = curr_ij%n+dj[d];
                        ll next_ij = curr_ij+di[d]*n+dj[d];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= n || used[next_ij]) continue;
                        if (!m[next_ij]) continue;
                        q.push(next_ij);
                        used[next_ij] = 1;
                        tmp_num++;
                        tmp_score += m[next_ij];
                    }
                }
                chmax(next_score, tmp_score * sqrt(tmp_num));
            };

            // u, v +- 1だけで良くない？もしそれでmaxが変わるとしたら、影響したところだけだし
#if 1
            repi(i, max<ll>(0ll, u-1), min<ll>(n-1, u+1+1)) rep(j, n) if (!used[i*n+j] && m[i*n+j]) f(i, j);
            repi(i, max<ll>(0ll, v-1), min<ll>(n-1, v+1+1)) rep(j, n) if (!used[i*n+j] && m[i*n+j]) f(i, j);
            repi(j, max<ll>(0ll, u-1), min<ll>(n-1, u+1+1)) rep(i, n) if (!used[i*n+j] && m[i*n+j]) f(i, j);
            repi(j, max<ll>(0ll, v-1), min<ll>(n-1, v+1+1)) rep(i, n) if (!used[i*n+j] && m[i*n+j]) f(i, j);
#else
            rep(i, n) rep(j, n) if (!used[i*n+j] && m[i*n+j]) f(i, j);
#endif

            // ダメなら戻す
            if (score > next_score) {
                rep(j, n) swap(m[u*n+j], m[v*n+j]);
                rep(i, n) swap(m[i*n+u], m[i*n+v]);
            } else {
                score = next_score;
            }

        }

        cout << cyc << " " << score << endl;
        return p;
    }   
};  



int main(int argc, char** argv) {
    if (argc > 1) {
        TL = stod(argv[1]);
    }

    ios::sync_with_stdio(false); cin.tie(0); 
    ll n; cin >> n;
    vector<int> m(n*n); 
    rep(i, n*n)
        cin >> m[i];
    ConnectedComponent solution;
    cout << solution.permute(m) << endl;

    return 0;
}
