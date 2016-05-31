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

// 尺取り法
// O(n)
// l, rの次の状態が存在するなら、次の状態に移ってtrue
// 存在しないならfalse
bool next_shakutoration(ll n, ll& l, ll& r, function<ll(ll, ll)> f, function<bool(ll, ll, ll)> g) {
    again:
    if (l >= n) return 0;
    r = max<ll>(r, l);
    while (1) {
        if (++r >= n + 1) {
            l++, r = 0;
            goto again;
        }
        if (g(l, r, f(l, r))) 
            return true;
    }
    return true;
}



int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    vll a = {1, 2, 3, 4, 2, 6}; 
    map<P, ll> memo;
    function<ll(ll, ll)> f = [&](ll l, ll r) {
        ll ret = 0; // 空区間
        if (memo.count(P(l, r-1)))  // 共通のlで、1つ前のrが存在
            ret = memo[P(l, r-1)] + a[r-1];
        memo[P(l, r)] = ret;
        return ret;
    };
    function<bool(ll, ll, ll)> g = [&](ll l, ll r, ll isum) { return (isum > 6); };

    ll l = 0, r = 0;
    while (next_shakutoration(a.size(), l, r, f, g)) {
        cout << l << " " << r << endl;
    }

    return 0;
}
