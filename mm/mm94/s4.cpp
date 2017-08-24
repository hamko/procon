#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
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

using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; 
using P = pair<int, int>;
using Pos = complex<double>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(int input, int n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }

size_t random_seed; namespace std { using argument_type = pair<int, int>; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<int>{}(x.fi); seed ^= (hash<int>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
template <typename T,typename U> class umap:public std::unordered_map<T,U,myhash::myhash<T>> { public: using MAP=std::unordered_map<T,U,myhash::myhash<T>>; umap():MAP(){MAP::rehash(myhash::Bsizes[rand()%20]);} };    

struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
void init(void) {
    gettimeofday(&start, NULL); 
    srand((unsigned int)time(NULL)); 
    random_seed = RAND_MAX / 2 + rand() / 2; 
}

#ifdef LOCAL
double cycle_per_sec = 3392239873; // local
double TL = 11; // pgã¤ãã¦ããªããªã8s
#else
double cycle_per_sec = 2503473315; // TC
double TL = 9.5;
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

//#define xy(i, j) (m[(i+1)*(n+2)+(j+1)])
#define xy(i, j) (m[indice[(i+1)][(j+1)]])

int indice[512][512];
static const long long INF = 1e9;
#define ldout fixed << setprecision(40) 

char di[4] = {1, 0, -1, 0};
char dj[4] = {0, 1, 0, -1};
class ConnectedComponent {
    char b_org[512][512];
    double getPoint(vector<int> p) {
        return getPoint(evaluate(p));
    }
    double getPoint(pair<int, int> x) {
        return 1.*x.se * sqrt(x.fi);
    }
    pair<int, int> evaluate(vector<int>& p) {
        bool used[512][512] = {};
        char mp[512][512];
        rep(i, n) rep(j, n) mp[i][j] = b_org[p[i]][p[j]];
        function<pair<int, int>(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= n || j < 0 || j >= n || used[i][j] || mp[i][j] == 0) return pair<int, int>(0, 0);
            used[i][j] = 1;
            int s = 1, ret = mp[i][j];
            rep(d, 4) {
                auto tmp = dfs(i+di[d], j+dj[d]);
                s += tmp.fi, ret += tmp.se;
            }
            return P(s, ret);
        };
        double opt_point = -INF;
        pair<int, int> ret = P(-1, -1);
        rep(i, n) rep(j, n) { 
            auto tmp = dfs(i, j);
            double point = getPoint(tmp);
            if (opt_point < point) opt_point = point, ret = tmp;
        }
        return ret;
    }
    void print(bool perm = 1) {
        if (perm) {
            char mp[512][512];
            rep(i, n) rep(j, n) mp[i][j] = b_org[p[i]][p[j]];
//            cout << p << " : point " << getPoint(evaluate(p)) << " with " << evaluate(p) << endl;
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
    void assertCoherence(vector<int> p, vector<int> m) {
        rep(i, n) rep(j, n) assert(b_org[p[i]][p[j]] == m[i*n+j]);
    }
public:
    int n;
    char b[512][512] = {};
    char m[512*512] = {};
    int p[512] = {};

    double score = -INF;
    double max_score = -INF;
    int max_num = -1;
    int ret[512];
    int cyc = 0;
    int maxi, maxj;

    double startTemp = -1, endTemp = -1;
    double endAnnealingTime = TL; // æ¸©åº¦ã®çµç«¯æå»ãæ¸©åº¦ã¯ç·å½¢ã«è½ã¡ã
    double t = 0; // æ¸©åº¦

    void init_p(void) {
        rep(i, n) p[i] = i;
        vector<P> sums(n);
//        rep(i, n) rep(j, n) sums[i].fi += !!m[i*n+j] + !!m[j*n+i], sums[i].se = i;
        rep(i, n) rep(j, n) sums[i].fi += xy(i, j) + xy(j, i), sums[i].se = i;
        sort(all(sums));
        int id = n / 2 + 1;
        int d = 0;
        rep(i, n) {
            id += (i % 2 ? -d : d);
            d++;
            p[id-1] = sums[i].se;
        }
        rep(i, n) rep(j, n) xy(i, j) = b_org[p[i]][p[j]];
    }
    void init_maxij(void) {
        maxi = n/2, maxj = n/2+1;
        int x = INF;
        // ãªãã¹ãåå´ï¼é£çµæåãå¤§ãããã®ãä½¿ã
        rep(i, n) rep(j, n) if (i != j && xy(i, j)>0){
            int tmp = abs(i-n/2)+abs(j-n/2);
            if (x > tmp) 
                x = tmp, maxi = i, maxj = j;
        }
    }
    void setTemp(void) {
        if (n < 50) 
            startTemp = 100, endTemp = 0.1;
        else if (n < 100) 
            startTemp = 400, endTemp = 0.1;
        else 
            startTemp = 200, endTemp = 1; 
    }
    /*
    pair<double, int> evaluateSmall(int i, int j) {
        if (!xy(i, j)) return mp(-1, -1);
        int next_num = -1;
        double next_score = -INF;
        bitset<40000> used;

        // evaluate
        queue<P> q;
        int tmp_num = 1;
        double tmp_score = xy(i, j);
        q.emplace(i, j);
        used[i*n+j] = 1;
        while (q.size()) {
            int ni, nj;
            tie(ni, nj) = q.front(); q.pop();
            rep(d, 4) {
                ni += di[d], nj += dj[d];
                int next_ij = ni*n+nj;
                if (xy(ni, nj) && !used[next_ij]) {
                    q.emplace(ni, nj);
                    used[next_ij] = 1;
                    tmp_num++;
                    tmp_score += xy(ni, nj);
                }
                ni -= di[d], nj -= dj[d];
            }
        }
        tmp_score *= sqrt(tmp_num);
        if (next_score < tmp_score) {
            next_score = tmp_score;
            next_num = tmp_num;
            maxi = i, maxj = j;
        }
        return mp(tmp_score, next_num);
    }
    pair<double, int> evaluateMedium(int i, int j) {
        if (!xy(i, j)) return mp(-1, -1);
        int next_num = -1;
        double next_score = -INF;
        bitset<100000> used;

        // evaluate
        queue<P> q;
        int tmp_num = 1;
        double tmp_score = xy(i, j);
        q.emplace(i, j);
        used[i*n+j] = 1;
        while (q.size()) {
            int ni, nj;
            tie(ni, nj) = q.front(); q.pop();
            rep(d, 4) {
                ni += di[d], nj += dj[d];
                int next_ij = ni*n+nj;
                if (xy(ni, nj) && !used[next_ij]) {
                    q.emplace(ni, nj);
                    used[next_ij] = 1;
                    tmp_num++;
                    tmp_score += xy(ni, nj);
                }
                ni -= di[d], nj -= dj[d];
            }
        }
        tmp_score *= sqrt(tmp_num);
        if (next_score < tmp_score) {
            next_score = tmp_score;
            next_num = tmp_num;
            maxi = i, maxj = j;
        }
        return mp(tmp_score, next_num);
    }
    */
    pair<double, int> evaluate(int i, int j) {
        if (!xy(i, j)) return mp(-1, -1);
        int next_num = -1;
        double next_score = -INF;
        bitset<250000> used;

        // evaluate
        queue<P> q;
        int tmp_num = 1;
        double tmp_score = xy(i, j);
        q.emplace(i, j);
        used[i*n+j] = 1;
        while (q.size()) {
            int ni, nj;
            tie(ni, nj) = q.front(); q.pop();
            rep(d, 4) {
                ni += di[d], nj += dj[d];
                int next_ij = ni*n+nj;
                if (xy(ni, nj) && !used[next_ij]) {
                    q.emplace(ni, nj);
                    used[next_ij] = 1;
                    tmp_num++;
                    tmp_score += xy(ni, nj);
                }
                ni -= di[d], nj -= dj[d];
            }
        }
        tmp_score *= sqrt(tmp_num);
        if (next_score < tmp_score) {
            next_score = tmp_score;
            next_num = tmp_num;
            maxi = i, maxj = j;
        }
        return mp(tmp_score, next_num);
    }

    void swap_rc(int u, int v) {
        rep(j, n) swap(xy(u, j), xy(v, j));
        rep(i, n) swap(xy(i, u), xy(i, v));
        swap(p[u], p[v]);
    }

    // eã¯å¾ç¹ã®å¾®å
    bool getForceNext(double e) {
        bool FORCE_NEXT = 0;
        if (startTemp > 0) {
            double temp;
            if (t < endAnnealingTime) 
                temp = startTemp + (endTemp - startTemp) * t / endAnnealingTime;
            else 
                temp = endTemp;

            double probability = exp(e / temp);
            const int R = 10000;
            FORCE_NEXT = probability > (double)(rand() % R) / R + 1e-6;
        }
        return FORCE_NEXT;
    }

    vector<int> permute(vector<int> m_) {
        unsigned long long int begin_cycle = getCycle();
        init();

        n = (int)sqrt(m_.size());
        rep(i, 512) rep(j, 512) 
            indice[i][j] = (i+0)*(n+1)+(j+0);
        rep(i, n*n) 
            b_org[i/n][i%n] = b[i/n][i%n] = m_[i];
        rep(i, n) rep(j, n) xy(i, j) = m_[i*n+j];

//        repi(i, -1, n+2) { repi(j, -1, n+2) cout << (int)xy(i, j) << " "; cout << endl; }

        init_p();
        init_maxij();

        setTemp();
        while (1) { cyc++; 
            t = getTime(begin_cycle);
            if (t > TL) break;

            const int MAXD = 5;
            char dirs[MAXD]; rep(_, MAXD) dirs[_] = rand() % 4;
            for (int d : dirs) {
                int tmpi = maxi + (int)di[d], tmpj = maxj + (int)dj[d];
                if (xy(tmpi, tmpj)) 
                    maxi = tmpi, maxj = tmpj;
            }
//            repi(i, -1, n+2) { repi(j, -1, n+2) cout << (int)xy(i, j) << " "; cout << endl; }

            int u = -1, v = -1;
            while (u == v || u == maxi || v == maxi || u == maxj || v == maxj) u = rand() % n, v = rand() % n;
            swap_rc(u, v);
            int prev_maxi = maxi, prev_maxj = maxj;

            double next_score = -INF;
            int next_num = -1;

            // Evaluation
            /*
            if (n*n <= 40000) 
                tie(next_score, next_num) = evaluateSmall(maxi, maxj);
            else if (n*n <= 100000) 
                tie(next_score, next_num) = evaluateMedium(maxi, maxj);
            else 
            */
                tie(next_score, next_num) = evaluate(maxi, maxj);

            // æé«ã¹ã³ã¢ãæ´æ°ããããåã£ã¦ãã
            if (max_score < next_score) {
                max_score = next_score;
                max_num = next_num;
                rep(i, n) ret[i] = p[i];
            }

            // ç¼ãéãã®ç¢ºçè¨ç®
            if (getForceNext(next_score - score) || score < next_score - 1e-4) {
                score = next_score;
            } else { // æ»ã
                swap_rc(u, v);
                maxi = prev_maxi, maxj = prev_maxj;
            }

            if (cyc % 1000 == 0) {
//                                cout << cyc << " " << t << " " << max_score << " " << max_num<< "#score" << endl;
                //                cout << cyc << " " << t << " " << score << " " << next_num<< "#score" << endl;
            }
        }

        if (startTemp < 0) {
            rep(i, n) ret[i] = p[i];
        }

        cout << max<double>(max_score, score) << "#final_score"<< endl;
        cout << cyc << "#final_cycle"<< endl;
        /*
        cout << ret << "#final_perm"<< endl;
        cout << n << "#board_size" << endl;
        cout << (startTemp > 0 ? 1 : 0) << "#annealing" << endl;
        cout << maxi << " " << maxj << "#const_ij" << endl;
        */

        vector<int> ans(n);
        rep(i, n) ans[i] = p[i];
        return ans;
    }   
};  


int main(int argc, char** argv) {
    if (argc > 1) {
        TL = stod(argv[1]);
    }

    ios::sync_with_stdio(false); cin.tie(0); 
    int n; cin >> n;
    vector<int> m(n*n); 
    rep(i, n*n)
        cin >> m[i];
    ConnectedComponent solution;
    cout << solution.permute(m) << endl;

    return 0;
}
