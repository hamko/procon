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

double cycle_per_sec_local = 3392239873; // local
double cycle_per_sec_tc = 2503473315; // TC
#ifdef LOCAL
double cycle_per_sec = cycle_per_sec_local; // local
double TL = 9.5 * (cycle_per_sec_tc / cycle_per_sec_local);
#else
double cycle_per_sec = cycle_per_sec_local; // TC
#endif
unsigned long long int getCycle()
{
    unsigned int low, high;
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((unsigned long long int)low) | ((unsigned long long int)high << 32);
}
double getTime(unsigned long long int begin_cycle)
{
    return (double)(getCycle() - begin_cycle) / cycle_per_sec;
}


static const long long INF = 1e18;
#define ldout fixed << setprecision(40) 


vll di = {1, 0, -1, 0}, dj = {0, 1, 0, -1};
class ConnectedComponent {
    char b_org[512][512];
    double getPoint(vector<int> p) {
        return getPoint(evaluate(p));
    }
    double getPoint(P x) {
        return 1.*x.se * sqrt(x.fi);
    }
    P evaluate(vector<int>& p) {
        bool used[512][512] = {};
        char mp[512][512];
        rep(i, n) rep(j, n) mp[i][j] = b_org[p[i]][p[j]];
        function<P(ll, ll)> dfs = [&](ll i, ll j) {
            if (i < 0 || i >= n || j < 0 || j >= n || used[i][j] || mp[i][j] == 0) return P(0, 0);
            used[i][j] = 1;
            ll s = 1, ret = mp[i][j];
//            cout << (int)mp[i][j] << " ";
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
//            cout << "BRUTAL" <<endl;
            double point = getPoint(tmp);
            if (opt_point < point) opt_point = point, ret = tmp;
        }
        return ret;
    }
    void print(vector<int> p, bool perm = 1) {
        if (perm) {
            char mp[512][512];
            rep(i, n) rep(j, n) mp[i][j] = b_org[p[i]][p[j]];
            cout << p << " : point " << getPoint(evaluate(p)) << " with " << evaluate(p) << endl;
            rep(i, n) {
                rep(j, n) cout << (int)mp[i][j] << "\t";
                cout << endl;
            }
        } else {
            rep(i, n) {
                rep(j, n) cout << p[i*n+j] << "\t";
                cout << endl;
            }
        }
    }
    void measureCyclePerSec(void) {
        long long y = getCycle();
        double s = sec();
        while (sec() - s < 1);
        cout << getCycle() - y << endl;
    }
    void beCoherent(vector<int> p, vector<int> m) {
            rep(i, n) rep(j, n) assert(b_org[p[i]][p[j]] == m[i*n+j]);
    }
public:
    ll counter1 = 0, counter2 = 0;
    int n;
    char b[512][512];
    vector<int> permute(vector<int> m) {
        unsigned long long int begin_cycle = getCycle();
        init();

        n = (int)sqrt(m.size());
        rep(i, m.size()) {
            b_org[i/n][i%n] = b[i/n][i%n] = m[i];
        }
        vector<int> p(n); rep(i, n) p[i] = i;

        double score = -INF;
        double max_score = -INF;
        vector<int> ret;
        bitset<250000> used;
        ll cyc = 0;

        ll maxi = -1, maxj = -1;
        // 温度は「これくらいならスコアが下がっても許容される度」
        // 温度の1倍下がってもで67%, 3倍下がっても0.5%くらいの確率で遷移する。
//        double startTemp = 500, endTemp = 1; 
        double startTemp = 500, endTemp = 1; 
        if (n < 50) startTemp = 40, endTemp = 0.1;
        double T = TL;
        ll R = 10000;
        double t = 0;
        while (1) { cyc++; 
            t = getTime(begin_cycle);
            if (t > TL) break;
            if (cyc % 1000 == 0) {
                cout << cyc << " " << t << " " << score << "#score" << endl;
            }

            ll uv_len = (t < TL / 5 ? 5 : 1);
            vll uv(2*uv_len);
            rep(i, uv_len) {
                ll u = -1, v = -1;
                while (u == v) u = rand() % n, v = rand() % n;
                rep(j, n) swap(m[u*n+j], m[v*n+j]);
                rep(i, n) swap(m[i*n+u], m[i*n+v]);
                swap(p[u], p[v]);
                uv[2*i] = u, uv[2*i+1] = v;
            }

            // evaluate
            double next_score = -INF;
            used.reset();
            function<void(ll, ll)> f = [&](ll i, ll j) {
                queue<ll> q;
                ll tmp_num = 1;
                double tmp_score = m[i*n+j];
                q.push(i*n+j);
                used[i*n+j] = 1;
//                cout << m[i*n+j] << " ";
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
//                        cout << m[next_ij] << " ";
                    }
                }
//                cout << "#DFS" <<endl;
                tmp_score *= sqrt(tmp_num);
                if (next_score < tmp_score) {
                    next_score = tmp_score;
                    maxi = i, maxj = j;
                }
            };

            // 全更新Greedyを高速化したもの。
            // 以下は、右式を高速化した rep(i, n) rep(j, n) if (!used[i*n+j] && m[i*n+j]) f(i, j);
            if (maxi != -1 && maxj != -1 && m[maxi*n+maxj]) {
                // Greedy with Context-Driven Initialization
                counter1++;
                f(maxi, maxj);
            } else {
                counter2++;
                // Skip Active +0 Greedy
                double skip_threshold = 0.05;
                rep(k, uv_len) {
                    ll u = uv[2*k], v = uv[2*k+1];
                    rep(j, n) {
                        if (1.0*rand()/RAND_MAX < skip_threshold && m[u*n+j] != 0 && m[v*n+j] == 0 && !used[u*n+j]) f(u, j);
                        if (1.0*rand()/RAND_MAX < skip_threshold && m[u*n+j] == 0 && m[v*n+j] != 0 && !used[v*n+j]) f(v, j);
                    }
                    rep(i, n) {
                        if (1.0*rand()/RAND_MAX < skip_threshold && m[i*n+u] != 0 && m[i*n+v] == 0 && !used[i*n+u]) f(i, u);
                        if (1.0*rand()/RAND_MAX < skip_threshold && m[i*n+u] == 0 && m[i*n+v] != 0 && !used[i*n+v]) f(i, v);
                    }
                }
            }

            // ダメなら戻したり焼き鈍したり
            bool FORCE_NEXT = 0;
            if (startTemp > 0) {
                double temp = startTemp + (endTemp - startTemp) * t / T;
                double probability = exp((next_score - score) / temp);
                FORCE_NEXT = probability > (double)(rand() % R) / R + 1e-6;
            }
            if (max_score < next_score) {
                max_score = next_score;
                ret = p;
            }
            if (FORCE_NEXT || score < next_score + 1e-4) {
                score = next_score;
            } else {
                rep(i_, uv_len) {
                    ll i = uv_len - 1 - i_;
                    ll u = uv[2*i], v = uv[2*i+1];
                    rep(j, n) swap(m[u*n+j], m[v*n+j]);
                    rep(i, n) swap(m[i*n+u], m[i*n+v]);
                    swap(p[u], p[v]);
                }
                beCoherent(p, m);
            }
        }

        if (startTemp < 0) {
            cout << "NOT ANNEALING" << endl;
            ret = p;
        }

        cout << counter1 << " " << counter2 << "#counter" << endl;
        cout << cyc << "#final_cycle"<< endl;
//        cout << ret << "#final_perm"<< endl;
        cout << max<double>(max_score, score) << "#final_score"<< endl;
        cout << n << "#board_size" << endl;
        cout << (startTemp > 0 ? 1 : 0) << "#annealing" << endl;

        return ret;
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
