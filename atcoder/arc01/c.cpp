#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define VN(v) # v
#define print(a) cout << a << "#" << VN(a) << endl;
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

bool check(vector<P>& s) {
    rep(i, s.size()) for (int j = i+1; j < s.size(); j++) {
        if (s[i].fi == s[j].fi) return 0; 
        if (s[i].se == s[j].se) return 0; 
        if (s[i].fi + s[i].se == s[j].fi + s[j].se) return 0; 
        if (s[i].fi - s[i].se == s[j].fi - s[j].se) return 0; 
    }
    return 1;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n = 8;
    vector<string> b(n);
    rep(i, n) cin >> b[i];
    vector<P> s;
    rep(i, n) rep(j, n) 
        if (b[i][j] == 'Q')
            s.pb(P(i, j));

    vector<vector<P>> q;
    vector<vector<P>> q_next; q_next.pb(s);
    rep(_, 5) {
        swap(q, q_next); 
        while (q.size()) {
            vector<P> t = q.back();
            rep(i, n) rep(j, n) if (find(all(t), P(i, j)) == t.end()) {
                t.pb(P(i, j));
                if (check(t)) {
                    q_next.pb(t);
                }
                t.pop_back();
            }

            q.pop_back();
        }
    }

    if (!q_next.size()) {
        cout << "No Answer" << endl;
        return 0;
    }
    rep(i, n) {
        rep(j, n) 
            if (find(all(q_next[0]), P(i, j)) == q_next[0].end())
                cout << '.';
            else 
                cout << 'Q';
        cout << endl;
    }

    return 0;
}
