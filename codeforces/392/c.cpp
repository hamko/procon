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
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

ll calc(ll a, ll b, ll k) {
    return 1 + (k - a - 1) / b;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m, k, x, y; cin >> n >> m >> k >> x >> y; x--; y--;
    if (n * m == k) {
        cout << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    } else if (n * m > k) {
        cout << 1 << " " << 0 << " " << (x * m + y <= k ? 1 : 0) << endl;
        return 0;
    } else if (n == 1 && m == 1) {
        cout << k << " " << k << " " << k << endl;
        return 0;
    } else if (n == 1) {
        if (k % m == 0) {
            cout << k / m << " " << k / m << " " << k / m << endl;
        } else {
            cout << k / m + 1<< " " << k / m  << " " << k / m + (x < k % m ? 1 : 0) << endl;
        }
        return 0;
    }

    ll Max = 1ll + calc(n*m, (n-1ll)*m, k);
//    cout << n * m << " " << (n-1ll) * m << endl;
    ll Min = calc(n*m+-1ll, 2ll*(n-1)*m, k);
//    cout << n*m+-1ll <<  " " << 2ll*(n-1)*m << endl;

    ll pos = 0;
    if (k <= n * m) {
        pos = (x * m + y <= k ? 1 : 0);
    } else {
        k -= n * m;
        pos++;

        ll loop = k / ((n - 1) * m); 
        ll rem = k - (n - 1) * m * loop;

        ll l_loop = loop / 2;
        ll u_loop = (loop+1) / 2;

        bool dir, UPPER = true, LOWER = false;
        dir = (u_loop > l_loop ? LOWER : UPPER);
        /*
        cout << l_loop << " " << u_loop << endl;
        cout << dir << "#dir" << endl;
        cout << rem << "#rem" << endl;
        */

        if (y == 0) {
            pos = 1 + u_loop;
        } else if (y == n - 1) {
            pos = 1 + l_loop;
        } else {
            pos = 1 + u_loop + l_loop;
        }
//        cout << pos << " " << "pos" << endl;

        if (rem) {
            if (dir == LOWER && x >= 1) {
                pos += (x * m + y < (m + rem) ? 1 : 0);
//                cout << x * m + y << " " << m + rem << endl;
            } else if (dir == UPPER && x < n - 1) {
                ll rx = rem / m;
                ll ry = rem - rx * m;
                rx++;
//                cout << rx << " " << ry << endl;
                if (n - rx <= x) 
                    pos++;
                else if (n - rx - 1 == x && y < ry)
                    pos++;
            }
//            cout << (x * m + y) << " " << n * m - (m + rem) << endl;
        }
    }

    cout << Max << " " << Min << " " << pos << endl;

    return 0;
}
