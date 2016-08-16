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
    double w, h; ll n;
    while (cin >> w >> h >> n && n) {
        struct point { 
            double x, y; 
            point(double x_, double y_) {
                x = x_, y = y_; 
            } 
            point(void) {
                x = y = 0; 
            }
        };
        vector<point> p(2*n);
        rep(i, 2*n) {
            cin >> p[i].x >> p[i].y;
        }

        vector<double> event_point;
        event_point.pb(0);
        event_point.pb(h);
        rep(i, p.size()) { 
            point target = p[i];
            rep(j, p.size()) if (i < j) {
                if (target.x != p[j].x) {
                    double x1 = target.x;
                    double y1 = target.y;
                    double x2 = p[j].x;
                    double y2 = p[j].y;
                    double y0 = (-x2*y1+x1*y2)/(x1-x2);
                    if (0 <= y0 && y0 <= h)
                        event_point.pb(y0);
                }
            }
        }
        { 
            point target(w, h);
            rep(j, p.size()) {
                if (target.x != p[j].x) {
                    double x1 = target.x;
                    double y1 = target.y;
                    double x2 = p[j].x;
                    double y2 = p[j].y;
                    double y0 = (-x2*y1+x1*y2)/(x1-x2);
                    if (0 <= y0 && y0 <= h)
                        event_point.pb(y0);
                }
            }
        }
        { 
            point target(w, 0);
            rep(j, p.size()) {
                if (target.x != p[j].x) {
                    double x1 = target.x;
                    double y1 = target.y;
                    double x2 = p[j].x;
                    double y2 = p[j].y;
                    double y0 = (-x2*y1+x1*y2)/(x1-x2);
                    if (0 <= y0 && y0 <= h)
                        event_point.pb(y0);
                }
            }
        }
 
        sort(all(event_point));

        double ret = 0.0;
        rep(i, event_point.size()-1) {
            double d = event_point[i+1] - event_point[i];
            if (abs(d) < EPS) 
                continue;
            double h0 = (event_point[i] + event_point[i+1]) / 2.0;
            vector<pair<double, int>> angles;
            rep(j, p.size()) {
                angles.pb(mp(atan2(p[j].y-h0, p[j].x), j));
            }
            sort(all(angles));
            double x1 = p[angles[p.size()/2].se].x; // 上
            double y1 = p[angles[p.size()/2].se].y;
            double x2 = p[angles[p.size()/2-1].se].x; // 下
            double y2 = p[angles[p.size()/2-1].se].y;

            double l1 = h0 + (y1 - h0) / x1 * w;
            double l2 = h0 + (y2 - h0) / x2 * w;

            chmin(l1, h);
            chmin(l2, h);
            chmax(l1, 0);
            chmax(l2, 0);
            ret += (l1 - l2) * d;
        }

        cout << ldout << ret / h / h << endl;
    }


    return 0;
}
