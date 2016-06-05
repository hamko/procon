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
#define VN(v) # v
#define print(a) cout << a << "#" << VN(a) << endl;
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

// dp[i][n2][n3][n5]
// 状態: i個サイコロを振った時、2がn2, 3がn3, 5がn5個出てくる確率
#define n2max 60
#define n3max 40
#define n5max 30
ld dp[2][n2max+10][n3max+10][n5max+10] = {};
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, d; cin >> n >> d;
    ll nd2 = 0, nd3 = 0, nd5 = 0;
    while (d % 2 == 0) d /= 2, nd2++;
    while (d % 3 == 0) d /= 3, nd3++;
    while (d % 5 == 0) d /= 5, nd5++;
    if (d != 1) {
        cout << "0" << endl;
        return 0;
    }

    ld ret = 0;
    dp[0][0][0][0] = 1;
    rep(i, n) {
        ll prev = i % 2; ll next = (i + 1) % 2;
        rep(n2, n2max+10) rep(n3, n3max+10) rep(n5, n5max+10) 
            dp[next][n2][n3][n5] = 0;
        /*
        rep(n2, n2max+10) rep(n3, n3max+10) rep(n5, n5max+10) {
            if (n2 >= nd2 && n3 >= nd3 && n5 >= nd5) {
                ret += dp[prev][n2][n3][n5];
                dp[prev][n2][n3][n5] = 0;
            }
        }
        */

        rep(n2, n2max) rep(n3, n3max) rep(n5, n5max) {
            if (!dp[prev][n2][n3][n5]) 
                continue;
            ld p = dp[prev][n2][n3][n5];
            // 遷移: 次にサイコロを振って、出る目の素因数に配分
            dp[next][n2+0][n3+0][n5+0] += p;
            dp[next][n2+1][n3+0][n5+0] += p;
            dp[next][n2+0][n3+1][n5+0] += p;
            dp[next][n2+2][n3+0][n5+0] += p;
            dp[next][n2+0][n3+0][n5+1] += p;
            dp[next][n2+1][n3+1][n5+0] += p;
        }
    }
    
    rep(n2, n2max) rep(n3, n3max) rep(n5, n5max) {
        if (n2 < nd2 || n3 < nd3 || n5 < nd5) 
            continue;
        ret += dp[n%2][n2][n3][n5];
    }
    rep(i, n) 
        ret /= 6;
    cout << ldout << ret << endl;

    return 0;
}
