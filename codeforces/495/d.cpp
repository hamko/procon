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

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！
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
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)
ll f(ll t) {
    ll ret = 0;
    repi(i, 1, t) {
        if (t % i) continue;
        ll n = i, m = t / i;
        if (n > m) break;
        ret += n;
    }
    return ret * t;
}

int main(void) {
    ll t; cin >> t;
    vll a(t); cin >> a;
    ll M = 0;
    rep(i, t) {
        chmax(M, a[i]);
    }
    int16_t freq[(ll)1e6+10];
    rep(i, M+1) {
        freq[i] = 0;
    }
    rep(i, t) {
        freq[a[i]]++;
    }
    if (freq[0] != 1) {
        cout << -1 << endl;
        return 0;
    }
    if (!(freq[M] == 1 || freq[M] == 2 || freq[M] == 4)) {
        cout << -1 << endl;
        return 0;
    }

    vll cands;
    repi(i, 1, t) {
        if (t % i) continue;
        ll n = i, m = t / i;
        if (n > m) break;
        cands.pb(i);
    }
    random_shuffle(all(cands));

    int16_t freq_org[(ll)1e6+10];
    rep(i, M+1) freq_org[i] = freq[i];
    function<void(ll, ll, ll, ll)> guess = [&](ll n, ll m, ll i0, ll j0) {
        rep(i, n) rep(j, m) {
            if ((--freq[abs(i-i0)+abs(j-j0)]) < 0) {
                rep(h, M+1) freq[h] = freq_org[h];
                return;
            }
        }
        // success
        cout << n << " " << m << endl;
        cout << i0 + 1 << " " << j0 + 1 << endl;
        exit(0);
    };

    for (auto n : cands) {
        if (sec() > 1.9) {
            cout << -1 << endl;
            return 0;
        }
        ll m = t / n;

        if (freq[M] == 4) {
            if (n % 2 == 0 || m % 2 == 0) {
                continue;
            } else {
                guess(n,m, n/2, m/2);
            }
        } else if (freq[M] == 2) {
            if (n % 2 == 1 || m % 2 == 1) {
                if (n % 2 == 1) rep(i, (m+1)/2) guess(n, m, n / 2, i);
                if (m % 2 == 1) rep(i, (n+1)/2) guess(n, m, i, m / 2);
            } else {
                continue;
            }
        } else {  // 1
            ll i0 = 0, j0 = (m-1)-(M-(n-1));
            while (j0 >= 0 && i0 < n) {
                if (i0 < (n+1)/2 && j0 < (m+1)/2) guess(n, m, i0, j0);
                j0--, i0++;
            }
        }

    }
    cout << -1 << endl;
    return 0;


    /*
       cout << f(997200) << endl;
       return 0;
       ll ret = 0;
       repi(i_, 1, 1e6+1) {
        ll i = 1e6+1-i_;
        ll tmp = f(i);
        if (ret < tmp) {
            ret = tmp;
            cout << i << " " << ret << endl;
        }
    }
    */
    

    return 0;
}
