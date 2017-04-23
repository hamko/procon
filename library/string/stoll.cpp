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

const ll NO_INPUT = -1;
const ll LEADING_ZERO = -2;
const ll OVERFLOW_DETECTED = -3;
const ll NOT_A_NUMBER = -4;
// stollで、オーバーフローと入力なしとリーディング0を許容しないもの。
ll stoll_no_leading_zero(string s) {
    if (!s.size()) return NO_INPUT;
    if (!all_of(all(s), [&](ll x){return '0'<=x&&x<='9';})) return NOT_A_NUMBER;
    if (s.size() > 1 && s[0] == '0') return LEADING_ZERO;
    if (stod(s) > LLONG_MAX) return OVERFLOW_DETECTED;
    return stoll(s);
}
// stollで、オーバーフローと入力なしを許容しないもの。
ll stoll_permitting_leading_zero(string s) {
    if (!s.size()) return NO_INPUT;
    if (!all_of(all(s), [&](ll x){return '0'<=x&&x<='9';})) return NOT_A_NUMBER;
    if (stod(s) > LLONG_MAX) return OVERFLOW_DETECTED;
    return stoll(s);
}

int main(void) {
    // stoll
    {
        cout << "####" << endl;
        cout << stoll_no_leading_zero("") << endl;
        cout << stoll_no_leading_zero("12a854321") << endl;
        cout << stoll_no_leading_zero("12") << endl;
        cout << stoll_no_leading_zero("012") << endl;
        cout << stoll_no_leading_zero("0") << endl;
        cout << stoll_no_leading_zero("39857893275") << endl;
        cout << stoll_no_leading_zero("9869048328802353780942329058340") << endl;
        cout << stoll("9869048328802353780942329058340") << endl;;
    }

    return 0;
}