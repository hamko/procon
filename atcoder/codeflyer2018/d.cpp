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

int main(void) {
    ll n; cin >> n;
    vll a(n), b(n); cin >> a >> b;
    vll da(100), db(100);
    rep(i, n) {
        rep(d, 62) {
            if (a[i] & (1ll << d)) da[d]++;
            if (b[i] & (1ll << d)) db[d]++;
        }
    }
    rep(d, 100) {
        if (da[d] == 0 && db[d]) {
            cout << "No" << endl;
            return 0;
        }
        if (db[d] == 0 && da[d]) {
            cout << "No" << endl;
            return 0;
        }
    }
    assert(0);
    cout << "Yes" << endl;
    /*
    sort(all(a));
    sort(all(b));
    ll rem = 0; 
    rep(i, n) {
        rem += __builtin_popcount(a[i] ^ b[i]);
    }
    cout << a << endl;
    cout << b << endl;
    cout << rem << endl;
    vector<bool> ret(n);
    while (rem) {
        sort(all(a));
        rep(i, n) if (a[i] != b[i]) {
            cout <<"########"<< endl;
            cout << rem << " " << i << endl;
            cout << a << endl;
            cout << b << endl;
            ll j = i; while (j == i) j = rand() % n;
            ll tmp = a[i] ^ a[j];
//            cout << tmp << " " << a[i] << " " << a[j] << endl;
            if (__builtin_popcount(a[i] ^ a[j] ^ b[i]) < __builtin_popcount(a[i] ^ b[i]) || rand() % 10 == 0) {
                rem -= __builtin_popcount(a[i] ^ b[i]) - __builtin_popcount(a[i] ^ a[j] ^ b[i]);
                a[i] ^= a[j];
            }
        }
    }
    */
    /*
    ll n; cin >> n;
    vector<string> ss;
    rep(i, n) {
        ss.pb(string(1, 'a'+i));
    }
    set<vector<string>> memo;
    vector<vector<string>> s;
    s.pb(ss);
    set<vector<string>> hoge;
    while (1) {
        vector<string> a = s[rand() % s.size()];

        ll i = rand() % (n-1);
        string t = a[i] + a[i+1];
        map<char, ll> freq;
        rep(i, t.size()) {
            freq[t[i]]++;
        }
        string tmp;
        for (auto c : freq) if (c.se % 2) {
            tmp += c.fi;
        }
        a[i+rand()%2] = tmp;
        if (memo.count(a)) {
            continue;
        }
        memo.insert(a);
        s.pb(a);
        if (a[0] == "a"
                || a[0] == "ab"
                || a[0] == "abc"
                || a[0] == "abcd"
                || a[0] == "abcde"
                || a[0] == "abcdef") {
            auto xx = a;
            sort(all(xx));
            if (hoge.count(xx)==0) {
                string y;
                for (auto yy : xx) {
                    y+=yy;
                }
                cout << count(all(y),'a') << " ";
                cout << count(all(y),'b') << " ";
                cout << count(all(y),'c') << " ";
                cout << count(all(y),'d') << " ";
                cout << xx << endl;
                hoge.insert(xx);
            }
        }
    }

    */

    return 0;
}
