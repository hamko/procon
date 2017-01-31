#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
using ld = long double;  using vld = vector<ld>; 
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
string bits_to_string(ll mask, ll n) { string s; rep(i, n) s += '0' + !!(mask & (1ll << i)); return s; }
#define ldout fixed << setprecision(10) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

void print(int i, double ret) {
    cout << "Case #" << i + 1 << ": " << fixed << ret+EPS << endl;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    vll ycands = {4, 6, 8, 10, 12, 20};
    map<ll, int> inv_y;
    rep(i, ycands.size()) {
        inv_y[ycands[i]] = i;
    }
    const ll maxh = 5000;
    double dp[6][30][maxh] = {};
    rep(i, ycands.size()) {
        ll y = ycands[i];
        dp[i][0][0] = 1;
        rep(j, 29) rep(h, maxh-y-1) rep(k, y) {
            dp[i][j+1][h+k+1] += dp[i][j][h] / y;
        }
    }
    ll cyc; cin >> cyc;
    rep(_, cyc) {
        ll hp, sn; cin >> hp >> sn;
        ll ret = 0;
        vector<double> rets;
        rep(i, sn) {
            string spell; cin >> spell;
            int di = spell.find('d');
            int plusi = spell.find('+');
            int minusi = spell.find('-');
            ll num = stoi(spell.substr(0, di));
            ll y_;
            ll bias = 0;
            if (plusi != string::npos) {
                y_ = stoi(spell.substr(di+1, plusi - di));
                bias = stoi(spell.substr(plusi + 1));
            } else if (minusi != string::npos) {
                y_ = stoi(spell.substr(di+1, minusi - di));
                bias = -stoi(spell.substr(minusi + 1));
            } else {
                y_ = stoi(spell.substr(di+1));
            }

            ll y = inv_y[y_];

            double prob = 1;
            rep(h, hp - bias) {
                if (h >= maxh) break;
                prob -= dp[y][num][h];
            }
            rets.pb(prob);
        }
        print(_, *max_element(all(rets)));
    }
    return 0;
}
