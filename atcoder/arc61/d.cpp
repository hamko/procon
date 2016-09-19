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
    ll h, w, n; cin >> h >> w >> n;
    vll ret(10);
    ret[0] = (h - 2) * (w - 2);

    map<P, ll> board;
    function<vll(ll, ll)> f = [&](ll a, ll b) {
        vll counter(10);
        for (ll dx = -2; dx <= 0; dx++) {
            for (ll dy = -2; dy <= 0; dy++) {
                if (a + dx < 0 || b + dy < 0) continue;
                if (a + dx + 3 > h || b + dy + 3 > w) continue;
//                cout << (a + dx) << " " << (b + dy) << endl;
                ll tmp = 0;
                for (ll xi = a + dx; xi < a + dx + 3; xi++) {
                    for (ll yi = b + dy; yi < b + dy + 3; yi++) {
//                        cout << P(xi, yi) << " ";
                        tmp += board[P(xi, yi)];
                    }
                }
//                cout << "#" << tmp<< endl;
                counter[tmp]++;
            }
        }
        return counter;
    };

    /*
    while (1) {
        ll a, b; cin >> a >> b; a--, b--;
        board[P(a, b)] = 1;
        vll curr_counter = f(a, b);
        cout << a << " " << b << " " << curr_counter << endl;
    }
    */
    rep(i, n) {
        ll a, b; cin >> a >> b; a--, b--;
        vll prev_counter = f(a, b);
        rep(j, 10) {
            ret[j] -= prev_counter[j];
        }
        rep(j, 9) {
            ret[j+1] += prev_counter[j];
        }
        board[P(a, b)] = 1;
    }
    rep(i, 10) {
        cout << ret[i] << endl;
    }
    return 0;
}
