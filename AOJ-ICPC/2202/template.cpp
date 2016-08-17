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
    ll n, m, k; cin >> n >> m >> k;
    while (cin >> n >> m >> k && n) {
        struct ship {
            double pos;
            double rem;
            double v;
        };
        struct canal {
            double pos;
            double cap; // capacity [L]
            double f; // up     [L/h]
            double d; // down   [L/h]
            bool ud; // 0: ^_, dir 1: _^

            double height; // height [L], どっちかに振り切れてたら脳内でバンドパス
            ll dir; // 1: up, -1: down
                        // ud=0ではデフォルトdir=1, ud=1ならデフォルト-1
        };
        vector<canal> c(n); 
        rep(i, n) {
            cin >> c[i].pos >> c[i].cap >> c[i].f >> c[i].d >> c[i].ud;
            c[i].dir = 0;
        }

        vector<ship> s(m); 
        rep(i, m) {
            s[i].pos = -i;
            s[i].rem = 0;
            cin >> s[i].v;
        }

        double t = 0;
        while (1) {
            ll dt = 0;
            // 一回では、0個目のshipを動かす
            dt += 1.0 / s[0].v;
            s[0].pos += 1.0;
            // 運河に乗ってたら下に下ろすところまでやる
            rep(i, n) {
                if (c[i].pos == s[0].pos) {
                    canal &tmp = c[i];
                    double rem = 0.0;
                    // 運河を西につける
                    if (tmp.ud == 0) {
                        if (tmp.dir == 1) { // いま上に上がっている
                            rem += max(0.0, tmp.cap - tmp.height) / tmp.f;
                        } else { // いま下に下がっている
                            rem += max(0.0, tmp.height) / tmp.d + tmp.cap / tmp.f;
                        }
                    } else {
                        if (tmp.dir == 1) { // いま上に上がっている
                            rem += max(0.0, tmp.cap - tmp.height) / tmp.f + tmp.cap / tmp.d;
                        } else { // いま下に下がっている
                            rem += max(0.0, tmp.height) / tmp.d;
                        }
                    }
                    // 運河を東につける
                    if (tmp.ud == 0) {
                        rem += tmp.cap / tmp.d;
                    } else {
                        rem += tmp.cap / tmp.f;
                    }
                    tmp.dir = (tmp.ud ? -1 : 1);
                    tmp.height = (tmp.ud ? tmp.cap : 0.0);
                    dt += rem;
                    break;
                }
            }

            // 船と運河を動かす
            repi(i, 1, m) {
            }

            t += dt;
        }
    }
    return 0;
}

