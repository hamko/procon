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
    ll n; cin >> n;
    vll s(n), c(n); rep(i, s.size()) cin >> s[i] >> c[i];
    set<P> memo;
    set<P, greater<P>> memo_rev;
    vector<ll> ret(n);
    rep(i, n) {
        cout << memo << endl;
        for (auto x : memo_rev) { cout << x << " "; } cout << endl;
        ll start_point = s[i];

        ll pos = s[i]; // 塗ろうとしている位置
        ll cost = c[i];
        vector<set<P>::iterator> to_erase;
        vector<set<P, greater<P>>::iterator> to_erase_rev;
        while (cost) {
            // pos以上の最小の終端位置
            auto l = upper_bound(all(memo), P(pos, -1));
            // pos以下の最大の終端位置
            auto r = upper_bound(all(memo_rev), P(pos, INF));

            cout << pos << " " << cost << endl;
            cout << (l == memo.end() ? P(-1, -1) : *l) << "#l" << endl;
            cout << (r == memo_rev.end() ? P(-1, -1) : *r) << "#r" << endl;

            if (l == memo.end() && r == memo_rev.end()) {
                pos += cost;
                cost = 0;
            } else if (l != r) {
                auto next_r = memo.upper_bound(P(pos, -1));
                if (next_r != memo.end() && next_r->fi <= pos + cost) {
                    to_erase.pb(next_r);
                    to_erase_rev.pb(memo_rev.find(*next_r));
                    ll used_cost = next_r->fi - pos;
                    cost -= used_cost;
                    pos += used_cost;
                } else {
                    memo.insert(P(pos, pos+cost-1));
                    memo_rev.insert(P(pos, pos+cost-1));
                    pos += cost;
                    cost = 0;
                }
            } else {
                pos = l->se + 1; 
            }
        }
        for (auto x : to_erase) {
            memo.erase(x);
        }
        memo.insert(P(start_point, pos-1));
        ret[i] = pos-1;
    }

    rep(i, n) {
        cout << ret[i] << endl;
    }
    return 0;
}
