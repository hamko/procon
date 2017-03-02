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

// ローリングハッシュ
// 構築 O(n)
// ハッシュ計算 O(1)
// 最長共通Suffix計算 O(log n)
//
// 文字列を、hs[i+1] = hs[i] * b + s[i] (mod m)によってハッシュする。
class RollingHash {
    private:
        vector<long long> mod; // ハッシュなので、複数種類のmodで強化する
        void init() {
            rep(i, 1) 
                mod.push_back(1000000009LL + (i != 0) * (rand() % 100000ll));
        }
        const long long b = 1000000007LL; // 素数が望ましい
        int n;

        // hs: 文字列のローリングハッシュ値
        // hs: hs[i+1] = hs[i] * b + s[i] (mod m)
        // s = "xyzw"
        // ""     hs[0] = 0 
        // "x"    hs[1] = x * b^0 
        // "xy"   hs[2] = x * b^1 + y * b^0
        // "xyz"  hs[3] = x * b^2 + y * b^1 + z * b^0
        // "xyzw" hs[4] = x * b^3 + y * b^2 + z * b^1 + w * b^0
        // "yz"   y * b^1 + z * b^0 = hs[3] - hs[1] * b^2
        vector<vector<long long>> hs;
        // pw: b^n (mod m)
        vector<vector<long long>> pw;

    public:
        // ローリングハッシュ構築
        // O(n)
        RollingHash(const string &s) : n(s.size()) {
            init();
            hs.resize(mod.size()), pw.resize(mod.size());
            for (int m = 0; m < mod.size(); m++) {
                hs[m].assign(n + 1, 0), pw[m].assign(n + 1, 0);
                hs[m][0] = 0, pw[m][0] = 1;
                for (int j = 0; j < n; j++) {
                    pw[m][j + 1] = pw[m][j] * b % mod[m];
                    hs[m][j + 1] = (hs[m][j] * b + s[j]) % mod[m];
                }
            }
        }

        // 部分文字列[l, r)のローリングハッシュ値計算
        // O(1)
        inline long long hash(int l, int r, int m) {
            return ((hs[m][r] - hs[m][l] * pw[m][r - l]) % mod[m] + mod[m]) % mod[m];
        }

        // 文字列の一致判定
        // O(1)
        // l1から始まるk文字の文字列と、l2から始まるk文字の文字列が一致すればtrue
        inline bool match(int l1, int l2, int k) {
            for (int m = 0; m < mod.size(); m++) 
                if (hash(l1, l1 + k, m) != hash(l2, l2 + k, m))
                    return false;
            return true;
        }

        // 最長共通Prefix
        // O(log n)
        // s[i]から始まる文字列と、s[j]から始まる文字列で、連続文字列長を計算
        // ハッシュ値の一致は、1111100000という単調性があるので、二分探索可能
        int lcp(int i, int j) {
            int l = 0, r = min(n - i, n - j) + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                (match(i, j, m) ? l : r) = m;
            }
            return l;
        }
};


int main(void) {
    // Rolling Hash
    {
        string s = "aaabaabaaaaaaaa";
        RollingHash rolling(s);

        vector<P> input = {P(0, 3), P(7, 10), P(2, 4), P(5, 7)};
        rep(i, input.size()) {
            ll l = input[i].fi, r = input[i].se;
            cout << rolling.hash(l, r, 0) << endl; 
        }
    }

    return 0;
}
