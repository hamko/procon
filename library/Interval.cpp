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
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
#define rand randxor
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

// 閉区間なので注意！
//
// (0) 初めは数直線は全て白
// (1) 数直線[l, r]を黒く塗る
// (2) 数直線[l, r]を白く塗る
// (3) 黒く塗られた長さを答える
// (4) 黒く塗られた線の連結成分数を答える
//
// を全てO(log n)以下で行う
template <typename T>
class Interval {
    public:
        set<pair<T, T>> interval; 
        Interval(void) {}

        // 区間[l, r]を追加する
        void add(T l, T r) {
            if (l >= r) return;
            auto it = interval.lower_bound(pair<T, T>(l, -INF));
            while (it != interval.end()) {
                if (!(r < it->se || l > it->fi)) {
                    if (it->se <= l && r <= it->fi) { // ----(--)----
                        return;
                    } else if (it->se <= l && l <= it->fi) { // -----(--    )
                        auto tmp = *it;
                        interval.erase(it);
                        add(tmp.se, r);
                        return;
                    } else if (it->se <= r && r <= it->fi) { // (   --)-----
                        auto tmp = *it; interval.erase(it); tmp.se = l; if (tmp.se < tmp.fi) interval.insert(tmp);
                        return;
                    } else if (l <= it->se && it->fi <= r) { // (  ----  )
                        interval.erase(it);
                        add(l, r);
                        return;
                    } else {
                        assert(0);
                    }
                } else {
                    break;
                }
            }
            interval.insert(pair<T, T>(r, l));
        }

        // 区間[l, r]を消す
        void erase(T l, T r) {
            if (l >= r) return;
            auto it = interval.lower_bound(pair<T, T>(l, -INF));
            while (it != interval.end()) {
                if (it->fi == l) {
                    it++;
                    continue;
                }
                if (!(r < it->se || l > it->fi)) {
                    if (it->se <= l && r <= it->fi) { // ----(--)----
                        auto tmp = *it; T itfi = it->fi; interval.erase(it); tmp.fi = l; if (tmp.se < tmp.fi) interval.insert(tmp);
                        add(r, itfi);
                        return;
                    } else if (it->se <= l && l <= it->fi) { // -----(--    )
                        auto tmp = *it; T itfi = it->fi; interval.erase(it); tmp.fi = l; if (tmp.se < tmp.fi) interval.insert(tmp);
                        erase(itfi, r);
                        return;
                    } else if (it->se <= r && r <= it->fi) { // (   --)-----
                        auto tmp = *it; interval.erase(it); tmp.se = r; if (tmp.se < tmp.fi) interval.insert(tmp);
                        return;
                    } else if (l <= it->se && it->fi <= r) { // (  ----  )
                        T tmp_r = it->fi;
                        interval.erase(it);
                        erase(tmp_r, r);
                        return;
                    } else {
                        assert(0);
                    }
                } else {
                    break;
                }
            }
        }
        // 区間の長さを答える
        T length(void) {
            T ret = 0;
            for (auto x : interval) {
                ret += x.fi - x.se;
            }
            return ret;
        }
        // 区間の数を答える
        int num(void) {
            return interval.size();
        }
        // 点xが区間に含まれるかを判定
        bool contain(T x) {
            auto it = interval.lower_bound(pair<T, T>(x, -INF));
            return it->se <= x && x <= it->fi;
        }

        // デバッグ出力
        void printInterval(void) {
            for (auto x : interval) {
                cout << "[" << x.se << ", " << x.fi << "], ";
            }
            cout << endl;
            T prev = -INF-10;
            for (auto x : interval) {
                assert(prev < x.se);
                assert(x.se < x.fi);
                prev = x.fi;
            }
        }
};


int main(void) {
    {
        Interval<ll> in;
        in.add(1, 9); in.printInterval();
        in.add(1, 13); in.printInterval();
        in.add(12, 15); in.printInterval();
        in.add(3, 13); in.printInterval();
        in.erase(-1, 3); in.printInterval();
        in.erase(13, 17); in.printInterval();
        in.erase(5, 7); in.printInterval();
    }
    {
        Interval<ll> in;
        while (1) {
            ll c; cin >> c;
            ll l, r; cin >> l >> r;
            if (c == 1) 
                in.add(l, r);
            else
                in.erase(l, r);
            in.printInterval();
        }
    }
    return 0;
}
