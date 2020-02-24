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
ll ugauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return a/b; else return (a+(a>0?-1:1))/b+1; }
ll lgauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return (a+(a>0?-1:1))/b-1; else return a/b; }
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
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)


ll ret_g = 0;
string ret_s = "aaa";
ll countBrutal(vector<string>& ss, char c1, char c2, char c3) {
    if (c1 < 26) { c1 = 'A' + c1; } else { c1 = 'a' + c1 - 26; }
    if (c2 < 26) { c2 = 'A' + c2; } else { c2 = 'a' + c2 - 26; }
    if (c3 < 26) { c3 = 'A' + c3; } else { c3 = 'a' + c3 - 26; }
    ll ret = 0;
    rep(i, ss.size()) {
        // 残りss.size()-i個
        // 最大ret+ss.size()-i個にしかならない
        if (ret+ss.size()-i<=ret_g) {
            return 0;
        }

        ll tmp = 0;
        for (auto x : ss[i]) {
            if (tmp == 0 && x == c1) {
                tmp++;
            } else if (tmp == 1 && x == c2) {
                tmp++;
            } else if (tmp == 2 && x == c3) {
                ret++;
                goto SKIP;
            } 
        }
        SKIP:;
    }
    return ret;
}

int main(void) {
    ll n; cin >> n;
    vector<string> ss(n); cin >> ss;
    rep(i, n) {
        cout << i << endl;
        rep(j, ss[i].size()) {
            if (ss[i][j] <= 'Z') {
                ss[i][j] -='A';
            } else {
                ss[i][j] -= 'a';
                ss[i][j] += 26;
            }
        }
    }
    vector<deque<vector<ll>>> memo(n);
    rep(i, n) {
        cout << i << endl;
        vll tmp(52, -1);
        memo[i].push_front(tmp);
        for (ll j = ss[i].length()-1; j >= 0; j--) {
            tmp[ss[i][j]] = j;
            memo[i].push_front(tmp);
        }
    }
    rep(c1, 52) {
        rep(c2, 52) rep(c3, 52) {
            cout << mt(c1,c2,c3) << endl;
            ll tmp = 0;
            rep(i, n) {
                ll i1 = memo[i][0][c1];
                if (i1 == -1) continue;
                i1++;
                ll i2 = memo[i][i1][c2];
                if (i2 == -1) continue;
                i2++;
                ll i3 = memo[i][i2][c3];
                if (i3 == -1) continue;
                tmp++;
            }
            if (ret_g < tmp) {
                ret_g = tmp;
                ret_s[0] = c1;
                ret_s[1] = c2;
                ret_s[2] = c3;
            }
        }
    }
    rep(i, 3) {
        if (ret_s[i] < 26) { ret_s[i] = 'A' + ret_s[i]; } else { ret_s[i] = 'a' + ret_s[i] - 26; }
    }
    cout << ret_s << endl;

    return 0;
}
