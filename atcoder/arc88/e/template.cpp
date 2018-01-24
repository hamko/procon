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

// Point Assign Range Sum
template<class T>
struct SegmentTreeSum {
    int n;
    T inf;
    vector<T> dat;
    SegmentTreeSum(int n_ = 0) : n(n_){
        inf = 0;
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, inf);
    }
    T sum(int v, int w, int l, int r){
        if(r <= l || w == 0) return inf;
        if(r - l == w) return dat[v]; // assert(l == 0 && r == w);
        int m = w/2;
        return (sum(v*2, m, l, min(r,m)) + sum(v*2+1, m, max(0,l-m), r-m));
    }
    void assign(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) dat[i/2] = dat[i] + dat[i^1];
    }
    T sum(int l, int r){ return sum(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return sum(idx, idx + 1); }
};

ll solve(string s1, string s2) {
//    cout << s1 << " " << s2 << endl;
    ll ret = 0;
    vvll f(256);
    rep(i, s1.size()) {
        f[s1[i]].pb(i);
    }
    vll id;
    vll fr(256);
    rep(i, s2.size()) {
        id.pb(f[s2[i]][fr[s2[i]]]);
        fr[s2[i]]++;
    }
//    cout << id << endl;

    SegmentTreeSum<ll> st(id.size());
    rep(i, id.size()) {
        st.assign(id[i], 1);
        ret += id[i] - st.sum(0, id[i]);
    }

    return ret;
}

int main(void) {
    string s; cin >> s;
    ll n = s.length();
    vvll freq(256);
    rep(i, n) {
        freq[s[i]].pb(i);
    }
    ll oddnum = 0;
    rep(i, 256) {
        oddnum += freq[i].size() % 2;
    }
    if (oddnum > 1) {
        cout << -1 << endl;
        return 0;
    }

    string s1, s2;
    string label(s.size(), 'H');
    vll f(256);
    rep(i, n) {
        if (freq[s[i]].size() % 2 == 0) {
            if (f[s[i]] < freq[s[i]].size() / 2) {
                s1 += s[i];
                label[i] = '1';
            } else {
                s2 += s[i];
                label[i] = '2';
            } 
        } else {
            if (f[s[i]] < freq[s[i]].size() / 2) {
                s1 += s[i];
                label[i] = '1';
            } else if (f[s[i]] > freq[s[i]].size() / 2) {
                s2 += s[i];
                label[i] = '2';
            }
        }
        f[s[i]]++;
    }
    string label_ordered(s.size(), 'H');
    rep(i, s.size()/2)
        label_ordered[i] = '1';
    rep(i, s.size()/2)
        label_ordered[s.size()-1-i] = '2';

//    cout << s1 << " " << s2 << endl;
    reverse(all(s1));
    ll r1 = solve(s1, s2);
    ll r2 = solve(label, label_ordered);

    cout << r1 + r2 << endl;


    return 0;
}
