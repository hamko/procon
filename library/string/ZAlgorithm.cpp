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

// Z Algorithm
// オリジナル：各iについて「S と S[i:|S|-1] の最長共通接頭辞の長さ」を計算
// 構築 O(s)
// 0-index LCP O(1)
//
// しかしこれだけで使ってもあまり嬉しくない。
// マッチングする文字列tが一個だけの場合、t+sに対してZ Algorithmを構築することで、
// 各iについて「T と S[i:|S|-1] の最長共通接頭辞の長さ」を計算できる
// 構築 O(s+t)
// 最長共通Suffix計算 O(1)
class ZAlgorithm {
public:
    string s;
    vector<int> z;
    int s_length = 0;
    int t_length = 0;
    bool m_matching_flag = true;
    
    // 構築
    // 事前にsに代入されていることが前提
    //
    // O(|s|)
    void construct(void) {
        ll n = s.size();
        z.assign(n, 0);

        z[0] = n;
        int i = 1, j = 0;
        while (i < n) {
            while (i+j < n && s[j] == s[i+j]) ++j;
            z[i] = j;
            if (j == 0) { ++i; continue;}
            int k = 1;
            while (i+k < n && k+z[k] < j) z[i+k] = z[k], ++k;
            i += k; j -= k;
        }
    }
    // SとS[i:end]のマッチング
    ZAlgorithm(string& s_) : s_length(s_.length()) {
        s = s_;
        construct();
    }
    // TとS[i:end]のマッチング
    ZAlgorithm(string& s_, string& t_) : s_length(s_.length()), t_length(t_.length()) {
        m_matching_flag = true;
        s = t_ + s_;
        construct();
    }
    // SとS[i:end]のマッチング、もしくはTとS[i:end]の最長マッチング数を返す
    ll lcp(ll i) {
        if (!m_matching_flag) {
            return z[i];
        } else {
            return min(z[i + t_length], t_length);
        }
    }
};

int main(void) {
    // ZAlgorithm
    {
        cin.tie(0); ios::sync_with_stdio(false);
        string s = "aaaabssss";
        string t = "abs";
        ZAlgorithm z(s, t);
        rep(i, s.length()) {
            cout << z.lcp(i) << endl;
        }
    }
    return 0;
}
