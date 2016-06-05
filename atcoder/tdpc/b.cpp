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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll na, nb; cin >> na >> nb;
    vll va(na); rep(i, va.size()) cin >> va[i];
    vll vb(nb); rep(i, vb.size()) cin >> vb[i];

    // 状態
    // dp[a][b]: 山Aがa個残っており、山Bがb個残っている時の、先手の最大点数
    ll dp[1010][1010]; rep(i, 1010) rep(j, 1010) dp[i][j] = -1;
    // 遷移
    // (na+nb-a-b)%2==0なら、先手の番。どちらかを取ることができる、どっちも取ってみて、先手の点数が高くなる方を選ぶ
    // (na+nb-a-b)%2==1なら、後手の番。どちらかを取ることができる、どっちも取ってみて、先手の点数が低くなる方を選ぶ
    function<ll(ll, ll)> f = [&](ll a, ll b) {
        if (a <= 0 && b <= 0) return 0;

        ll& ret = dp[a][b];
        if (ret >= 0) return (int)ret;

        bool player = (na + nb - a - b) % 2;
        if (player) { // 後手
            ret = INF;
            if(a > 0) chmin(ret, f(a-1, b));
            if(b > 0) chmin(ret, f(a, b-1));
        } else { // 先手
            ret = -1;
            if(a > 0) chmax(ret, f(a-1, b) + va[na-a]);
            if(b > 0) chmax(ret, f(a, b-1) + vb[nb-b]);
        }
        return (int)ret;
    };
    cout << f(na, nb) << endl;
    return 0;
}
