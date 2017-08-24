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

#define red cout << "\x1b[31m"
#define green cout << "\x1b[32m"
#define blue cout << "\x1b[34m"
#define bgblue cout << "\x1b[41m"
#define bgdefault cout << "\x1b[49m"
#define yellow cout << "\x1b[33m"
#define black cout << "\x1b[0m" // ããã©ã«ãã«æ»ã
#define clear_disp system("clear")

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

typedef struct evaluation_info_ {
    double score = -INF;
    int num = -1;
    int maxi = -1, maxj = -1;
    int li = INF, lj = INF, ri = -INF, rj = -INF;
} evaluation_info;

std::ostream& operator<<(std::ostream& os, const evaluation_info& v)
{
    return os << v.score << " " << v.num << " " << v.maxi << " " << v.maxj << " " << P(v.li, v.ri) << " " << P(v.lj , v.rj);
}

char di[4] = {1, 0, -1, 0};
char dj[4] = {0, 1, 0, -1};
class ConnectedComponent {
    char b_org[512][512]; // ãªãªã¸ãã«ã®ç¤é¢
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
    int cyc = 0;            // ä»ã®ã«ã¼ãçªå·
    int n;                  // æ¨ªå¹

    /****** ç¾å¨ã®ç¤é¢æå ± ******/
    char m[512*512] = {};   // ä»ã®ç¤é¢
    int p[512] = {};        // ä»ã®perm
    bitset<250000> used;    // ä»ã®ç¤é¢ã®æå¤§é£çµæåmask
    bitset<250000> pused;   // ç´åã®ç¤é¢ã®æå¤§é£çµæåmask
    evaluation_info peval;

    /****** æ¸©åº¦ ******/
    evaluation_info ret_eval;
    int ret[512];           // æé«ã¹ã³ã¢æã®perm


    /****** æ¸©åº¦ ******/
    double startTemp = -1, endTemp = -1;
    double endAnnealingTime = TL; // æ¸©åº¦ã®çµç«¯æå»ãæ¸©åº¦ã¯ç·å½¢ã«è½ã¡ã
    double t = 0; // æ¸©åº¦
    
    void printBoardRaw(void) { rep(i, n) { rep(j, n) if (xy(i, j) >= 0) cout << (int)xy(i, j); else cout << (char)('A'-xy(i, j)-1); cout << endl; } }
    void printUsedRaw(void) { rep(i, n) { rep(j, n) if (!used[i*n+j]) cout << "_"; else if (xy(i, j) >= 0) cout << (int)xy(i, j); else cout << (char)('A'-xy(i, j)); cout << endl; } }
    void printBoard(int u = -1, int v = -1) {
        rep(i, n) {
            rep(j, n) {

                if (used[i*n+j]) bgblue;
                if (xy(i, j) == 0) {
                    if (v >= 0 && (i == u || i == v || j == u || j == v) ) {
                        green; 
                        cout << "*";
                        black;
                    } else {
                        cout << "_";
                    }
                } else if (xy(i, j) >= 0) {
                    cout << (int)xy(i, j);
                } else {
                    blue;
                    cout << -(int)xy(i, j);
                    black;
                }
                if (used[i*n+j]) bgdefault;
            }
            cout << endl; 
        } 
        rep(i, n) rep(j, n){
            if (used[i*n+j]) assert(xy(i, j));
        }
    }
    void printPBoard(int u = -1, int v = -1) {
        rep(i, n) {
            rep(j, n) {
                if (pused[i*n+j]) bgblue;
                if (xy(i, j) == 0) {
                    if (v >= 0 && (i == u || i == v || j == u || j == v) ) {
                        green; 
                        cout << "*";
                        black;
                    } else {
                        cout << "_";
                    }
                } else if (xy(i, j) >= 0) {
                    cout << (int)xy(i, j);
                } else {
                    blue;
                    cout << -(int)xy(i, j);
                    black;
                }
                if (pused[i*n+j]) bgdefault;
            }
            cout << endl; 
        } 
        rep(i, n) rep(j, n){
            if (pused[i*n+j]) assert(xy(i, j));
        }
    }

    void printUsed(int u = -1, int v = -1) {
        rep(i, n) {
            rep(j, n) {
                if (v >= 0 && (i == u || i == v || j == u || j == v) ) {
                    if (used[i*n+j] && xy(i, j) > 0) {
                        cout << (int)xy(i, j);
                    } else if (used[i*n+j] && xy(i, j) < 0) {
                        blue;
                        cout << -(int)xy(i, j);
                        black;
                    } else if (xy(i, j) == 0) {
                        red; 
                        cout << "*";
                        black;
                    } else if (!used[i*n+j] && !xy(i, j)) {
                        red; 
                        cout << "*";
                        black;
                    } else if (!used[i*n+j] && xy(i, j)) {
                        red; 
                        cout << "@";
                        black;
                    } else {
                        assert(1);
                    }

                } else {
                    if (!used[i*n+j]) {
                        cout << "_";
                    } else if (xy(i, j) >= 0) {
                        cout << (int)xy(i, j);
                    } else {
                        blue;
                        cout << -(int)xy(i, j);
                        black;
                    }
                }
            }
            cout << endl;
        } 
    }
    void init_p(void) {
        // ç·åãå¤§ãããã®ãåå´ã¸
        rep(i, n) p[i] = i;
        vector<P> sums(n);
        rep(i, n) rep(j, n) sums[i].fi += !!xy(i, j) + !!xy(j, i), sums[i].se = i; 
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
        peval.maxi = n/2, peval.maxj = n/2+1;
        int x = INF;
        // ãªãã¹ãåå´ï¼é£çµæåãå¤§ãããã®ãä½¿ã
        rep(i, n) rep(j, n) if (i != j && xy(i, j)>0){
            int tmp = abs(i-n/2)+abs(j-n/2);
            if (x > tmp) {
                x = tmp, peval.maxi = i, peval.maxj = j;
                peval.li = i, peval.ri = i;
                peval.lj = j, peval.rj = j;
            }
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

    // usedãå¯ä½ç¨ã§å¤æ´ãã
    evaluation_info evaluate(int i, int j) {
        evaluation_info ei; 
        if (!xy(i, j)) return ei;

        ei.maxi = i, ei.maxj = j;

        queue<P> q;
        ei.num = 1;
        ei.score = xy(i, j);
        q.emplace(i, j);
        used[i*n+j] = 1;
        while (q.size()) {
            int ni, nj; tie(ni, nj) = q.front(); q.pop();
            chmin(ei.li, ni); chmin(ei.lj, nj); chmax(ei.ri, ni); chmax(ei.rj, nj);
            rep(d, 4) {
                ni += di[d], nj += dj[d];
                int next_ij = ni*n+nj;
                if (xy(ni, nj) && !used[next_ij]) {
                    q.emplace(ni, nj);
                    used[next_ij] = 1;
                    ei.num++;
                    ei.score += xy(ni, nj);
                }
                ni -= di[d], nj -= dj[d];
            }
        }
        ei.score *= sqrt(ei.num);
        return ei;
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

    int best_u = -1, best_v = -1, best_maxi = -1, best_maxj = -1; evaluation_info best_eval; set<P> memo;
    bool isDuplicateUV(int u, int v) {
        if (memo.count(P(u, v))) { 
            return false;
        }
        return true;
    }
    bool isValidUV(int u, int v, int maxi, int maxj) {
        if (u == v) return false;
        if (u == maxi || v == maxi || u == maxj || v == maxj) {
            return false;
        }
        assert(peval.li <= maxi && maxi <= peval.ri);
        assert(peval.lj <= maxj && maxj <= peval.rj);
        if (abs(peval.li) != INF) {
            bool tef = 0;
            if (peval.li - 1 <= u && u <= peval.ri + 1) tef = 1;
            if (peval.li - 1 <= v && v <= peval.ri + 1) tef = 1;
            if (peval.lj - 1 <= u && u <= peval.rj + 1) tef = 1;
            if (peval.lj - 1 <= v && v <= peval.rj + 1) tef = 1;
            if (tef == 0) return false;
        }
        return true;
    }
    // 1æ¢ç´¢ã¹ãããã§ãæ­£ããããã¤åãu, vãåºããªããã¨ã¾ã§ä¿è¨¼ãã
    // insertã¯é¢æ°å¤ã§è¡ãã
    tuple<int, int> generateUV(int maxi, int maxj) {
        int u = -1, v = -1;
        vector<int> ps;
        /*
        if (t < TL * 1) 
            ps = {1, 0, 10, 0};
        else if (t < TL * 0.8) 
            ps = {10, 0, 0, 0};
        else 
            ps = {0, 10, 0, 0};
            */
            ps = {10, 0, 0, 0};
        rep(i, ps.size()-1) ps[i+1] += ps[i];
        int P = ps.back();

        while (!isValidUV(u, v, maxi, maxj) || !isDuplicateUV(u, v)) {
            int p = rand() % P;
            if (p < ps[0]) {
                tie(u, v) = proposeUVrandom(maxi, maxj);
            } else if (p < ps[1]) {
                tie(u, v) = proposeUVdist(maxi, maxj);
            } else if (p < ps[2]) {
                tie(u, v) = proposeUVCorder(maxi, maxj);
            } else {
                tie(u, v) = proposeUVCorderExternal(maxi, maxj);
            }
        }

        return mt(u, v);
    }
    tuple<int, int> proposeUVrandom(int maxi, int maxj) {
        return mt(rand() % n, rand() % n);
    }
    tuple<int, int> proposeUVdist(int maxi, int maxj) {
        int dist = rand() % 3 + 1;
        int u = rand() % (n - dist);
        return mt(u, u+dist);
    }
    tuple<int, int> proposeUVCorder(int maxi, int maxj) {
        vector<int> cand = {peval.ri, peval.rj, peval.li, peval.lj};
        int u = cand[rand()%4];
        return mt(u, rand() % n);
    }
    tuple<int, int> proposeUVCorderExternal(int maxi, int maxj) {
        vector<int> cand = {peval.ri, peval.rj, peval.li, peval.lj};
        int u = cand[rand()%4];
        if (rand() % 2) {
            int x = *min_element(all(cand));
            return mt(u, rand() % (x + 1));
        } else { 
            int x = *max_element(all(cand));
            return mt(u, min<int>(x + (rand() % (n-x)), n-1));
        }
    }

    vector<int> permute(vector<int> m_) {
        unsigned long long int begin_cycle = getCycle();
        init();

        n = (int)sqrt(m_.size());
        rep(i, 512) rep(j, 512) 
            indice[i][j] = (i+0)*(n+1)+(j+0);
        rep(i, n*n) 
            b_org[i/n][i%n] = m_[i];
        rep(i, n) rep(j, n) xy(i, j)= m_[i*n+j];

        init_p();
        init_maxij();
        peval = evaluate(peval.maxi, peval.maxj);

        setTemp();

        while (1) { cyc++; 
            t = getTime(begin_cycle);
            if (t > TL) break;

            int u = -1, v = -1, maxi = peval.maxi, maxj = peval.maxj;

            const int MAXD = 5;
            char dirs[MAXD]; rep(_, MAXD) dirs[_] = rand() % 4;
            for (int d : dirs) {
                int tmpi = maxi + (int)di[d], tmpj = maxj + (int)dj[d];
                if (xy(tmpi, tmpj)) 
                    maxi = tmpi, maxj = tmpj;
            }

            // TODO ä½ç³»çã«u, vãçæã§ããããã«
            tie(u, v) = generateUV(maxi, maxj);
            if (best_u == -1 || best_v == -1) best_u = u, best_v = v;
            if (memo.size() > n*n/4) {
                u = best_u, v = best_v, maxi = best_maxi, maxj = best_maxi;
            }
            assert(isValidUV(u, v, maxi, maxj));
            memo.insert(P(u, v));

            assert(peval.li <= maxi && maxi <= peval.ri);
            assert(peval.lj <= maxj && maxj <= peval.rj);
            
            evaluation_info eval;
            swap_rc(u, v);
            used.reset();
            eval = evaluate(maxi, maxj);
//            printBoard();
            assert(eval.li <= eval.maxi && eval.maxi <= eval.ri);
            assert(eval.lj <= eval.maxj && eval.maxj <= eval.rj);
            if (best_eval.score < eval.score) {
                best_eval = eval;
                best_u = u, best_v = v, best_maxi = maxi, best_maxj = maxj;
            }

            // æé«ã¹ã³ã¢ãæ´æ°ããããåã£ã¦ãã
            if (ret_eval.score < eval.score) {
                ret_eval = eval;
                rep(i, n) ret[i] = p[i];
                /*
                clear_disp;
                cout << "######################################"<< endl;
                printBoard(u, v);
                */
            }

            // ç¼ãéãã®ç¢ºçè¨ç®
            bool FORCE_NEXT = memo.size() > n*n/4 || getForceNext(eval.score - peval.score);
            if (FORCE_NEXT || peval.score < eval.score - 1e-4) {
                peval = eval;
                pused = used;
                best_u = -1, best_v = -1, best_maxi = -1, best_maxj = -1; best_eval = evaluation_info(); memo.clear();

            } else { // æ»ã
                swap_rc(u, v);
            }

            if (cyc % 1000 == 0) {
//                cout << cyc << " " << t << " " << ret_eval.score << " " << ret_eval.num << "#score" << endl;
//                cout << peval.ri - peval.li << " " << peval.rj - peval.lj << endl;
            }
        }

        cout << ret_eval.score << "#final_score"<< endl;
        cout << cyc << "#final_cycle"<< endl;
        /*
           cout << ret << "#final_perm"<< endl;
           cout << n << "#board_size" << endl;
           cout << (startTemp > 0 ? 1 : 0) << "#annealing" << endl;
           cout << maxi << " " << maxj << "#const_ij" << endl;
           */

        vector<int> ans(n);
        rep(i, n) ans[i] = ret[i];
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
