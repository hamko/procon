#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
ll ugauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return a/b; else return (a+(a>0?-1:1))/b+1; }
ll lgauss(ll a, ll b) { if (!a) return 0; if (a>0^b>0) return (a+(a>0?-1:1))/b-1; else return a/b; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
size_t random_seed; struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

// データ型T, 単位元T0, 可換二項演算子opが与えられた時、
//
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
        T S = T0;
        for (j; j >= 0; j = (j & (j + 1)) - 1)  // jは、C->B->7と遷移する。0からCをカバーするための数字列の添字へ飛ぶ
            S = op(S, x[j]); 
        return S;
    }

    // 更新クエリ: #kにaを演算する
    // O(log n)
    void update(int k, T a) {
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

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while(k) {
		if(k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<1000000007> mint;
typedef vector<mint> vmint;
ostream &operator<<(ostream &o, const mint v) {  o << v.x; return o; }



int main(void) {
    ll d, f, t, n; cin >> d >> f >> t >> n;
    vll a;
    a.pb(0);
    rep(i, n) {
        ll x; cin >> x; a.pb(x);
    }
    n = a.size();

    fenwick_tree<mint> b(100010);
    
// 0-indexed, sumは閉区間なので注意！！
//        f.update(i, i);
// cout << f.query(0, n-1) << endl;  

    vector<mint> dp(n);
    b.update(0, mint(1));
    rep(i, n) {
//        cout << "#############" << endl;
        dp[i] = b.query(100010) - (i > 0 ? b.query(i) : mint(0));
//        cout << dp[i] << endl;
        // dp[j] += 2^k dp[i] 
        ll k_l = upper_bound(all(a), a[i]) - a.begin();
        ll k_r = upper_bound(all(a), a[i] + (f - t)) - a.begin();
        ll k = k_r - k_l;
//        cout << mt(k_l, k_r) << endl;
        mint tmp = (mint(2) ^ k) * dp[i]; 

        // j in [l, r)
        ll l = upper_bound(all(a), a[i]+(f-t)) - a.begin();
        ll r = upper_bound(all(a), a[i] + f) - a.begin();
//        cout << mt(l, r) << endl;
        if (l >= r) continue; 

        b.update(r, tmp);
        b.update(l, -tmp);
    }
//    cout << dp << endl;


    mint ret = 0;
    rep(i, n) if (d - f <= a[i]) {
        ll k_l = upper_bound(all(a), a[i]) - a.begin();
        ll k_r = upper_bound(all(a), a[i] + (f - t)) - a.begin();
        ll k = k_r - k_l;
        ret += (mint(2) ^ k) * dp[i];
    }
    cout << ret << endl;
    return 0;
}
