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
double TL = 11; // pgついていないなら8s
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
    char b_org[512][512]; // オリジナルの盤面
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
    int cyc = 0;            // 今のループ番号
    int n;                  // 横幅

    /****** 現在の盤面情報 ******/
    char m[512*512] = {};   // 今の盤面
    int p[512] = {};        // 今のperm
    bitset<250000> used;    // 今の盤面の最大連結成分mask
    int maxi, maxj;         // 今の盤面での最大連結成分の座標の一例
    double score = -INF;    // 今のループのスコア
    int num = -1;           // 今のループでの最大連結成分のサイズ

    /****** 温度 ******/
    double max_score = -INF; // 最高スコア
    int max_num = -1;       // 最高スコア時の
    int ret[512];           // 最高スコア時のperm


    /****** 温度 ******/
    double startTemp = -1, endTemp = -1;
    double endAnnealingTime = TL; // 温度の終端時刻。温度は線形に落ちる
    double t = 0; // 温度
    
    void printBoard(void) { rep(i, n) { rep(j, n) if (xy(i, j) >= 0) cout << (int)xy(i, j); else cout << (char)('A'-xy(i, j)-1); cout << endl; } }
    void printUsed(void) { rep(i, n) { rep(j, n) if (!used[i*n+j]) cout << "_"; else if (xy(i, j) >= 0) cout << (int)xy(i, j); else cout << (char)('A'-xy(i, j)-1); cout << endl; } }

    int countEdges(void) {
        int counter = 0;
        rep(i, n-1) rep(j, n) if (!!xy(i, j) && !!xy(i+1, j)) counter++;
        rep(j, n-1) rep(i, n) if (!!xy(i, j) && !!xy(i, j+1)) counter++;
        return counter;
    }

    void init_p(void) {
        // 総和が大きいものを内側へ
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

        // 連結辺が多くなるように何回か入れ替えておく
        rep(_, 0) {
//            cout << countEdges() << "#count edges" << endl;
            int u = -1, v = -1;
            while (u == v || u == maxi || v == maxi || u == maxj || v == maxj) u = rand() % n, v = rand() % n;
            if (predict(u, v) > 0) {
                swap_rc(u, v);
//                printBoard();
            }
        }
    }
    void init_maxij(void) {
        {
            double max_connection = -INF;
            rep(i, n) rep(j, n) if (xy(i, j) && !used[i*n+j]) {
                int tmp_maxi, tmp_maxj, tmp_num; double tmp_score; 
                tie(tmp_score, tmp_num, tmp_maxi, tmp_maxj) = evaluate(i, j, true);
                if (max_connection < tmp_score) 
                    max_connection = tmp_score, maxi = tmp_maxi, maxj = tmp_maxj;
            }
            used.reset();
            tie(score, num, maxi, maxj) = evaluate(maxi, maxj, false);
            /*
            printBoard();
            printUsed();
            cout << maxi << " " << maxj << "$max" << endl;
            cout << num << "#initial_num" << endl;
            */
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

    // usedを副作用で変更する
    tuple<double, int, int, int> evaluate(int i, int j, bool enableConnectivity = 0) {
        if (!xy(i, j)) return mt(-INF, -1, -1, -1);
        double ret_score = -INF; int ret_num = -1, ret_maxi = -1, ret_maxj = -1;

        // evaluate
        queue<P> q;
        int tmp_num = 1;
        double tmp_score = enableConnectivity ? !!xy(i, j) : xy(i, j);
        q.emplace(i, j);
        used[i*n+j] = 1;
        while (q.size()) {
            int ni, nj; tie(ni, nj) = q.front(); q.pop();
            rep(d, 4) {
                ni += di[d], nj += dj[d];
                int next_ij = ni*n+nj;
                if (xy(ni, nj) && !used[next_ij]) {
                    q.emplace(ni, nj);
                    used[next_ij] = 1;
                    tmp_num++;
                    tmp_score += enableConnectivity ? !!xy(ni, nj) : xy(ni, nj);
                }
                ni -= di[d], nj -= dj[d];
            }
        }
        if (!enableConnectivity)
            tmp_score *= sqrt(tmp_num);
        if (ret_score < tmp_score) {
            ret_score = tmp_score;
            ret_num = tmp_num;
            ret_maxi = i, ret_maxj = j;
        }
        return mt(ret_score, ret_num, ret_maxi, ret_maxj);
    }

    void swap_rc(int u, int v) {
        rep(j, n) swap(xy(u, j), xy(v, j));
        rep(i, n) swap(xy(i, u), xy(i, v));
        swap(p[u], p[v]);
    }

    // eは得点の微分
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

    // u,vを入れ替えて、どれくらい連結スコアが増えるか？
    double predict(int u, int v) {
        // Prediction
        double pred = 0;
        rep(i, n) {
            if (!!xy(i, u) < !!xy(i, v)) {
                pred += !!xy(i, u-1) + !!xy(i, u+1);
                pred -= !!xy(i, v-1) + !!xy(i, v+1);
            } else if (!!xy(i, u) > !!xy(i, v)) {
                pred -= !!xy(i, u-1) + !!xy(i, u+1);
                pred += !!xy(i, v-1) + !!xy(i, v+1);
            }
            if (!!xy(u, i) < !!xy(v, i)) {
                pred += !!xy(u-1, i) + !!xy(u+1, i);
                pred -= !!xy(v-1, i) + !!xy(v+1, i);
            } else if (!!xy(u, i) > !!xy(v, i)) {
                pred -= !!xy(u-1, i) + !!xy(u+1, i);
                pred += !!xy(v-1, i) + !!xy(v+1, i);
            }
        }
        return pred;
    }
    // u,vを入れ替えて、どれくらい連結辺が増えるか？
    double predictNum(int u, int v) {
        // Prediction
        double pred = 0;
        rep(i, n) {
            if (used[i*n+u] < used[i*n+v]) {
                pred += !!xy(i, u-1) + !!xy(i, u+1);
                pred -= !!xy(i, v-1) + !!xy(i, v+1);
            } else if (used[i*n+u] > used[i*n+v]) {
                pred -= !!xy(i, u-1) + !!xy(i, u+1);
                pred += !!xy(i, v-1) + !!xy(i, v+1);
            }
            if (used[u*n+i] < used[v*n+i]) {
                pred += !!xy(u-1, i) + !!xy(u+1, i);
                pred -= !!xy(v-1, i) + !!xy(v+1, i);
            } else if (used[u*n+i] > used[v*n+i]) {
                pred -= !!xy(u-1, i) + !!xy(u+1, i);
                pred += !!xy(v-1, i) + !!xy(v+1, i);
            }
        }
        return pred;
    }


    P getQuery(void) {
        int u = -1, v = -1;
        int trialNum = 2; // 1で、普通に生成する。
        rep(_, trialNum) {
            while (u == v || u == maxi || v == maxi || u == maxj || v == maxj) u = rand() % n, v = rand() % n;
            if (trialNum == 1 || num < 8 * n) break;

            double cutThres500 = -50; // 連結スコア
            double cutThres50  = -50; // 連結スコア
            double thres = cutThres50 + (cutThres500 - cutThres50) * (1.0*n) / (500-50);
            if (predict(u, v) > thres) 
                break;
        }
        return P(u, v);
    }

    vector<int> permute(vector<int> m_) {
        unsigned long long int begin_cycle = getCycle();
        init();

        n = (int)sqrt(m_.size());
        rep(i, 512) rep(j, 512) 
            indice[i][j] = (i+0)*(n+1)+(j+0);
        rep(i, n*n) 
            b_org[i/n][i%n] = m_[i];
        rep(i, n) rep(j, n) xy(i, j) = m_[i*n+j];

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

            int u, v; tie(u, v) = getQuery();
            swap_rc(u, v);
            int prev_maxi = maxi, prev_maxj = maxj;

            double next_score = -INF;
            int next_num = -1;

            // Evaluation
            used.reset();
            tie(next_score, next_num, maxi, maxj) = evaluate(maxi, maxj);

            // 最高スコアを更新したら、取っておく
            if (max_score < next_score) {
                max_score = next_score;
                max_num = next_num;
                rep(i, n) ret[i] = p[i];
            }

            // 焼き鈍しの確率計算
            if (getForceNext(next_score - score) || score < next_score - 1e-4) {
                score = next_score;
            } else { // 戻す
                swap_rc(u, v);
                maxi = prev_maxi, maxj = prev_maxj;
            }

            if (cyc % 1000 == 0) {
//                cout << cyc << " " << t << " " << max_score << " " << max_num<< "#score" << endl;
//                printBoard();
//                printUsed();
//               cout << cyc << " " << t << " " << score << " " << next_num<< "#score" << endl;
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
