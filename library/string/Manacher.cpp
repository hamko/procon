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

class manacher {
public: 
    string s; // 元の入力文字列
    vll r; // a$b$c$aのように$で区切った文字列msに対して、ms[i]を中心とした最大半径
    vll pal; // s[i/2]を中心とした回文半径。abbaなら1012101

    // [l, r)が回文ならば1
    // 空文字列や、l>rではtrueを返す
    //
    // O(1)
    bool isPalindrome(ll l, ll r) {
        if (r - l <= 0) return 1;
        if ((r - l) % 2 == 0) {
            return (r - l) / 2 <= pal[l + r - 1];
        } else {
            return (r - l + 1) / 2 <= pal[l + r - 1];
        }
    }

    // O(n)
    manacher(string raw_s) : s(raw_s) {
        ll n = raw_s.size()*2-1;
        r.resize(n);
        pal.resize(n);

        // 偶数長の回文を扱うためにダミー文字を挿入
        string ms(n, '$'); 
        rep(i, raw_s.size()) ms[2*i] = s[i];

        // manacher
        int i = 0, j = 0;
        while (i < n) {
            while(i-j >= 0 && i+j < n && ms[i-j] == ms[i+j]) ++j;
            r[i] = j;
            int k = 1;
            while(i-k >= 0 && i+k < n && k+r[i-k] < j) r[i+k] = r[i-k], ++k;
            i += k; j -= k;
        }

        // 半径を計算
        rep(i, pal.size()) pal[i] = (r[i] + (i % 2 == 0)) / 2;
    }
};

int main(void) {
    string s = "abbab";
    manacher m(s); 
    cout << s << endl;

    ll n = s.size();
    rep(i, n) {
        rep(j, n+1) {
            if (i < j) 
                cout << m.isPalindrome(i, j);
            else 
                cout << '#';

        }
        cout << endl;
    }

    return 0;
}
