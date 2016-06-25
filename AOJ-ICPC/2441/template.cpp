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
static const long long INF = 1e18;
static const long long mo = 1e9+7;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vvll len(20, vll(6));
    vvll len_border(20, vll(6));
    // 15+3i
    rep(i, len.size()) {
        len[i][0] = len[i][1] = len[i][3] = i+1;
        len[i][2] = len[i][4] = 4;
        len[i][5] = 8;
    }
    // 16+3i
    rep(i, len_border.size()) {
        len_border[i][0] = len_border[i][1] = i+1;
        len_border[i][3] = i+2;
        len_border[i][2] = len_border[i][4] = 4;
        len_border[i][5] = 8;
    }
    cout << len << endl;
    cout << len_border << endl;

    // 20
    //
    // 6*1
    // 7
    // 9*0

        

    // TODO 1-3は特殊
    // TODO 3ll
    ll repnum;
    ll repred;
    rep(i, 20) {
        ll lenfrom = ((ll)(pow(10, i))+3); // from 103
        ll lento = ((ll)(pow(10, i+1))-4); // from 996 
        ll lennum = (lento - lenfrom + 1) / 6;
        if (!i) 
            lennum = 1;
        if (n >= lennum * (16 + 3 * i))
            n -= lennum * (16 + 3 * i);
        else {
            ll repnum = n / (16 + 3 * i); 
            ll repred = n % (16 + 3 * i); 
            n -= lennum * (16 + 3 * i);
            break;
        }

        if (n >= (17 + 3 * i))
            n -= (17 + 3 * i);
        else {
        }
    }

    return 0;
}
