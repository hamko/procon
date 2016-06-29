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
static const long long INF = 2e18;
static const long long mo = 1e9+7;

class point {
public:
    ll x = 0, y = 0, z = 0;
    point() {
        x = 0;
        y = 0;
        z = 0;
    }
    point(ll x_, ll y_, ll z_) {
        x = x_;
        y = y_;
        z = z_;
    }
};
ll manhattan(point& a, point& b) {
    return abs<ll>(a.x - b.x) + abs<ll>(a.y - b.y) + abs<ll>(a.z - b.z);
}
ll getMaxDist(vector<point>& pv, point p) {
    ll ret = 0;
    rep(i, pv.size()) {
        chmax(ret, manhattan(pv[i], p));
    }
    return ret;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll _num; cin >> _num;
    rep(_, _num) {
        ll n; cin >> n;
        vector<point> p(n);
        vector<point> p_conv(n);
        ll xmax = -INF;
        ll ymax = -INF;
        ll zmax = -INF;
        ll xmin = INF;
        ll ymin = INF;
        ll zmin = INF;
        rep(i, n) {
            cin >> p[i].x >> p[i].y >> p[i].z;
            p_conv[i].x = -p[i].x+p[i].y+p[i].z;
            p_conv[i].y = +p[i].x-p[i].y+p[i].z;
            p_conv[i].z = +p[i].x+p[i].y-p[i].z;
            chmax(xmax, p_conv[i].x);
            chmax(ymax, p_conv[i].y);
            chmax(zmax, p_conv[i].z);
            chmin(xmin, p_conv[i].x);
            chmin(ymin, p_conv[i].y);
            chmin(zmin, p_conv[i].z);
        }

        double mx_c = (xmax + xmin) / 2;
        double my_c = (ymax + ymin) / 2;
        double mz_c = (zmax + zmin) / 2;
        ll mx = round((my_c + mz_c) / 2);
        ll my = round((mx_c + mz_c) / 2);
        ll mz = round((mx_c + my_c) / 2);
        /*
        cout << xmax << " " << xmin << endl;
        cout << ymax << " " << ymin << endl;
        cout << zmax << " " << zmin << endl;
        cout << mx_c << " " << my_c << " " << mz_c << endl;
        cout << mx << " " << my << " " << mz << endl;
        */

        ll dmin = INF;
        point dminp;
        for (ll dx = -3; dx <= 3; dx++) 
            for (ll dy = -3; dy <= 3; dy++) 
                for (ll dz = -3; dz <= 3; dz++) {
                    ll tmp = getMaxDist(p, point(mx+dx, my+dy, mz+dz));
                    if (dmin > tmp) {
                        dmin = tmp;
                        dminp = point(mx+dx, my+dy, mz+dz);
                    }
                }
        cout << dminp.x << " " << dminp.y << " " << dminp.z << endl;
        cout << dmin << endl;


        mx = 0;
        my = 0;
        mz = 0;
        ll l = 20;
        dmin = INF;
        for (ll dx = -l; dx <= l; dx++) 
            for (ll dy = -l; dy <= l; dy++) 
                for (ll dz = -l; dz <= l; dz++) {
                    ll tmp = getMaxDist(p, point(mx+dx, my+dy, mz+dz));
                    if (dmin > tmp) {
                        dmin = tmp;
                        dminp = point(mx+dx, my+dy, mz+dz);
                    }
                }
        cout << dminp.x << " " << dminp.y << " " << dminp.z << endl;
        cout << dmin << endl;

    }
    return 0;
}
