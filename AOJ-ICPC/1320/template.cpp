#include <bits/stdc++.h>
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

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
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
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n;
    while (cin >> n && n) {
        vector<string> tmp(n);
        rep(i, n) 
            cin >> tmp[i];
        vll eliminate(n);
        rep(i, n) rep(j, n) if (i != j) 
            if (tmp[i].find(tmp[j]) != string::npos)
                eliminate[j] = 1;
        
        vector<string> names;
        rep(i, n) 
            if (!eliminate[i])
                names.pb(tmp[i]);
        if (names.size() == 1) {
            cout << names[0].length() << endl;
            continue;
        }

        map<P, ll> match_length;
        rep(i, names.size()) rep(j, names.size()) if (i != j) {
            match_length[P(i, j)] = 0;
            for (int l = 1; l < min(names[i].length(), names[j].length()); l++) {
                bool faf = 1;
                rep(k, l) 
                    if (names[i][names[i].length()-l+k] != names[j][k]) 
                        faf = 0;
                if (faf)
                    chmax(match_length[P(i, j)], l);
            }
        }
        for (auto&& x : match_length) 
            x.se = names[x.fi.se].length() - x.se;
            
        ll dp[1ll << 15][15] = {};
        rep(i, 1ll<<15) rep(j, 15)
            dp[i][j] = INF;
        rep(i, names.size()) 
            dp[1ll<<i][i] = names[i].length();

        rep(mask, 1ll << names.size()) 
            rep(curr, names.size()) 
                if (mask && dp[mask][curr] != INF) 
                    rep(i, names.size()) 
                        if ((mask & (1ll << i)) == 0) 
                            chmin(dp[mask | (1ll << i)][i], dp[mask][curr] + match_length[P(curr, i)]);

        ll ret = INF;
        rep(i, names.size())  
            chmin(ret, dp[(1ll << names.size())-1][i]);

        cout << ret << endl;
    }
    return 0;
}
