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

// データ型T, 単位元T0, 二項演算子opが与えられた時、
// 点更新opをO(log n)、0-indexの範囲sum(int j)をO(log n)で実現
// もしopに逆演算が定義できるならば、i-indexの範囲sum(int i, int j)が実現可能。

// 0-indexed, sumは閉区間なので注意！！

void printBit(int a) {cout << a << " "; for(; a > 0; a >>= 1) cout << (a & 1); cout << "#bit" << endl;}
template <class T>
struct fenwick_tree {
    /**********************/
    // 実装箇所
    /**********************/
    T T0 = 0;
    T op(T a, T b) { return a + b; }
    /**********************/
    // 実装終わり
    /**********************/

    // xのデータ構造。op=+, invop=1, T=int, T0=0の場合
    // iが最右添字な数字列をs[i]として、x[i] = s[i]の総和 (例: i=5, s[i]="45", x[i]=9)
    // 0123456789ABCDEF
    // 01234567--------
    // 0123----89AB----
    // 01--23--89--CD--
    // 0-2-4-6-8-A-C-E-
    int n_org;
    vector<T> x;
    fenwick_tree(int n_)  { 
        n_org = n_;
        int n = 1; while (n <= n_) n *= 2;
        x = vector<T>(n, T0);
    }

    // 範囲クエリ: [0, j]のreduceを行う。閉区間に注意
    // O(log n)
    T query(int j) {
        if (j < 0)
            return T0;
        T S = T0;
        for (; j >= 0; j = (j & (j + 1)) - 1)  // jは、C->B->7と遷移する。0からCをカバーするための数字列の添字へ飛ぶ
            S = op(S, x[j]); 
        return S;
    }

    // 更新クエリ: #kにaを右から演算する
    // O(log n)
    void update(int k, T a) {
        if (k < 0)
            return;
        for (; k < x.size(); k |= k+1) // kは、C->D->Fと遷移する。Cをカバーする数字列全てに飛ぶ
            x[k] = op(x[k], a); 
    }

    // #kにアクセスする
    // O(log n)
    T access(int k) {
        return query(k) - (k ? query(k-1) : 0);
    }
    void print(void) {
        for (int i = 0; i < n_org; i++) 
            cout << access(i) << " ";
        cout << endl;
    }
    void print_raw(void) {
        for (int i = 0; i < x.size(); i++) 
            cout << x[i] << " ";
        cout << endl;
    }
};


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll a, b, mo;
    while (cin >> a >> b >> mo && a && b && mo) {
        ll n = b - a + 1;
        vector<string> w(n); rep(i, n) w[i] = to_string(a+i);
        sort(all(w));
        vll lex(n); rep(i, n) lex[i] = stoi(w[i]) - a;

        fenwick_tree<ll> dp(n);
        rep(i, n) 
            dp.update(lex[i], (dp.query(lex[i]-1)+1)%mo);
        
        cout << dp.query(n-1) % mo << endl;
    }
    return 0;
}
