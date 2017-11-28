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
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
string bits_to_string(ll input, ll n=64) { string s; rep(i, n) s += '0' + !!(input & (1ll << i)); reverse(all(s)); return s; }
template <typename T> ostream &operator<<(ostream &o, const priority_queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} o << endl; return o; }

template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }

size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
namespace myhash{ const int Bsizes[]={3,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81}; const int xor_nums[]={0x100007d1,0x5ff049c9,0x14560859,0x07087fef,0x3e277d49,0x4dba1f17,0x709c5988,0x05904258,0x1aa71872,0x238819b3,0x7b002bb7,0x1cf91302,0x0012290a,0x1083576b,0x76473e49,0x3d86295b,0x20536814,0x08634f4d,0x115405e8,0x0e6359f2}; const int hash_key=xor_nums[rand()%20]; const int mod_key=xor_nums[rand()%20]; template <typename T> struct myhash{ std::size_t operator()(const T& val) const { return (hash<T>{}(val)%mod_key)^hash_key; } }; };
template <typename T> class uset:public std::unordered_set<T,myhash::myhash<T>> { using SET=std::unordered_set<T,myhash::myhash<T>>; public: uset():SET(){SET::rehash(myhash::Bsizes[rand()%20]);} };
uint32_t randxor() { static uint32_t x=1+(uint32_t)random_seed,y=362436069,z=521288629,w=88675123; uint32_t t; t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); }
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ gettimeofday(&start, NULL); ios::sync_with_stdio(false); cin.tie(0); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define rand randxor

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

class Mod {
    public:
        int num;
        Mod() : Mod(0) {}
        Mod(long long int n) : num(n) {n%=mo;}
        Mod(const string &s){ long long int tmp = 0; for(auto &c:s) tmp = (c-'0'+tmp*10) % mo; num = tmp; }
        Mod(int n) : Mod(static_cast<long long int>(n)) {}
        operator int() { return num; }
};
istream &operator>>(istream &is, Mod &x) { long long int n; is >> n; x = n; return is; }
ostream &operator<<(ostream &o, const Mod &x) { o << x.num; return o; }
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mo); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mo + a.num - b.num) % mo); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mo); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod factorial(const long long n) {
    if (n < 0) return 0;
    Mod ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
Mod operator^(const Mod a, const long long n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod modpowsum(const Mod a, const long long b) {
    if (b == 0) return 0;
    if (b % 2 == 1) return modpowsum(a, b - 1) * a + Mod(1);
    Mod result = modpowsum(a, b / 2);
    return result * (a ^ (b / 2)) + result;
}


/*************************************/
// 以下、modは素数でなくてはならない！
/*************************************/
Mod inv(const Mod a) { return a ^ (mo - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }
Mod operator/(const long long int a, const Mod b) { assert(b.num != 0); return Mod(a) * inv(b); }
Mod operator/=(Mod &a, const Mod b) { assert(b.num != 0); return a = a * inv(b); }

// n!と1/n!のテーブルを作る。
// nCrを高速に計算するためのもの。
//
// O(n + log mo)
vector<Mod> fact, rfact;
void constructFactorial(const long long n) {
    fact.resize(n);
    rfact.resize(n);
    fact[0] = rfact[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        fact[i+1] = fact[i] * (i+1);
    }
    rfact[n-1] = Mod(1) / fact[n-1]; 
    for (int i = n - 1; i >= 1; i--) 
        rfact[i-1] = rfact[i] * i; // ((n-1)!)^-1 = (n!)^-1 * n
}

// O(1)
// constructFactorialしておけば、n, r=1e7くらいまではいけます
Mod nCr(const long long n, const long long r) {
    if (n < 0 || r < 0) return 0;
    return fact[n] * rfact[r] * rfact[n-r];
}

// O(r.size())
// sum(r)! / r[0]! / r[1]! / ...
Mod nCr(const vector<long long> r) {
    ll sum = accumulate(all(r), 0ll);
    Mod ret = fact[sum];
    rep(i, r.size()) 
        ret *= rfact[r[i]];
    return ret;
}

// O(k log mo) 
Mod nCrWithoutConstruction(const long long n, const long long k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    Mod ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= n - (Mod)i;
        ret /= Mod(i+1);
    }
    return ret;
}
// n*mの盤面を左下から右上に行く場合の数
// O(1)
Mod nBm(const long long n, const long long m) {
    if (n < 0 || m < 0) return 0;
    return nCr(n + m, n);
}



/*************************************/
// GF(p)の行列演算
/*************************************/
using number = Mod;
using arr = vector<number>;
using matrix = vector<vector<Mod>>;

ostream &operator<<(ostream &o, const arr &v) { rep(i, v.size()) cout << v[i] << " "; return o; }
ostream &operator<<(ostream &o, const matrix &v) { rep(i, v.size()) cout << v[i]; return o; }

matrix zero(int n) { return matrix(n, arr(n, 0)); } // O(n^2)
matrix identity(int n) { matrix A(n, arr(n, 0)); rep(i, n) A[i][i] = 1; return A; } // O(n^2)
// O(n^2)
arr mul(const matrix &A, const arr &x) { 
    arr y(A.size(), 0); 
    rep(i, A.size()) rep(j, A[0].size()) y[i] += A[i][j] * x[j]; 
    return y; 
} 
// O(n^3)
matrix mul(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    rep(i, C.size())
        rep(j, C[i].size())
        rep(k, A[i].size())
        C[i][j] += A[i][k] * B[k][j];
    return C;
}
// O(n^2)
matrix plu(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    rep(i, C.size())
        rep(j, C[i].size())
            C[i][j] += A[i][j] + B[i][j];
    return C;
}
// O(n^2)
arr plu(const arr &A, const arr &B) {
    arr C(A.size());
    rep(i, A.size())
        C[i] += A[i] + B[i];
    return C;
}
// 構築なし累乗
// return A^e
//
// O(n^3 log e)
matrix pow(const matrix &A, long long e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
// 構築付き累乗
//
// return powA: A^2^i
// O(n^3 log e)
matrix pow(const vector<matrix>& powA, long long e) { // powA[0]がA
//    cout << powA[0] << "^" << e <<endl;
    if (e <= 0) return identity(powA[0].size());
    matrix ret = identity(powA[0].size());
    rep(i, powA.size()) if (e & (1ll << i)) {
        ret = mul(ret, powA[i]);
    }
    return ret;
}
arr powmul(const vector<matrix>& powA, long long e, arr& a) { // powA[0]がA
//    cout << powA[0] << "^" << e <<endl;
    if (e <= 0) return a;
    arr ret = a;
    rep(i, powA.size()) if (e & (1ll << i)) {
        ret = mul(powA[i], ret);
    }
    return ret;
}

// Aを最大e乗まで計算するためのpowAを構築する。
// powAは副作用で返す
//
// O(n^3 log e)
void construct_powA(const matrix &A, long long e, vector<matrix>& powA) {
    powA.clear();
    powA.pb(A);
    for (int i = 1; (1ll << i) < e; i++) {
        powA.pb(mul(powA[i-1], powA[i-1]));
    }
}

// O(n)
number inner_product(const arr &a, const arr &b) {
    number ans = 0;
    for (int i = 0; i < (int)a.size(); ++i)
        ans += a[i] * b[i];
    return ans;
}
// O(n)
number tr(const matrix &A) {
    number ans = 0;
    for (int i = 0; i < (int)A.size(); ++i)
        ans += A[i][i];
    return ans;
}
// O( n^3 )
// modは素数でなければならない！！
number det(matrix A) {
    int n = A.size();
    assert(n == (int)A[0].size());
    number ans = 1;
    for (int i = 0; i < n; i++) {
        int pivot = -1;
        for (int j = i; j < n; j++)
            if (A[j][i]) {
                pivot = j;
                break;
            }
        if (pivot == -1) return 0;
        if (i != pivot) {
            swap(A[i], A[pivot]);
            ans *= -1;
        }
        number tmpinv = inv(A[i][i]);
        for (int j = i + 1; j < n; j++) {
            number c = A[j][i] * tmpinv;
            for (int k = i; k < n; k++) {
                A[j][k] = (A[j][k] - c * A[i][k]);
            }
        }
        ans *= A[i][i];
    }
    return ans;
}

// O( n^3 ).
// int rank(matrix A) はまだ

// O( n^3 ).
// modが2の時だけ使える演算
#define FOR(x,to) for(x=0;x<(to);x++) // repに変えちゃダメ。xがint xになると動かない
int gf2_rank(matrix A) { /* input */
    if (!A.size() || (A.size() && A[0].size())) return 0;
    int n = A.size();
    assert(mo == 2); 
    
    int i,j,k;
    FOR(i,n) {
        int be=i,mi=n+1;
        for(j=i;j<n;j++) {
            FOR(k,n) if(A[j][k]) break;
            if(k<mi) be=j,mi=k;
        }
        if(mi>=n) break;
        FOR(j,n) swap(A[i][j],A[be][j]);

        FOR(j,n) if(i!=j&&A[j][mi]) {
            FOR(k,n) A[j][k] += A[i][k]; // ^=のつもり
        }
    }
    return i;
}

// input : a, b
// output : x, y  s.t. ax + by = （符号付き）gcd(a, b)
int extGcd( int a, int b, int& x, int& y ) {
  if ( b == 0 ) {
    x = 1; y = 0; return a;
  }
  int g = extGcd( b, a % b, y, x );
  y -= (a / b) * x;
  return g;
}

// xn = 1 (mod p)
int invMod(int n, int p) {
  int x, y, g = extGcd ( n, p, x, y );
  if (g == 1) return x;
  else if (g == -1) return -x;
  else return 0; // gcd(n, p) != 1，解なし
}


// 有限体上の線型方程式系 Ax = b (mod q)を解く
// a = [A | b]: m × n の係数行列
// x: 解を記録するベクトル
// 計算量： O(min(m, n) * m * n)
bool gauss(matrix a, arr& x, int m, int n, int q) {
  int rank = 0;
  vll pivot(n);
  // 前進消去
  for (int i = 0, j = 0; i < m && j < n-1; ++j) {
    int p = -1;
    Mod tmp = 0;

    // ピボットを探す
    for (int k = i; p < 0 && k < m; ++k) {
      if (a[k][j] != 0) p = k;  // 有限体上なので非零で十分
    }
    // ランク落ち対策
    if (p == -1) continue;
    // 第i行と第p行を入れ替える
    for (int k = j; k < n; ++k)
      tmp = a[i][k], a[i][k] = a[p][k], a[p][k] = tmp;
    // 第i行を使って掃き出す
    for (int k = i+1; k < m; ++k) {
      tmp = - a[k][j] * invMod(a[i][j], q) % q;
      for (int l = j; l < n; ++l)
        a[k][l] += tmp * a[i][l];
    }
    // 第i行を正規化： a[i][j] = 1 にする
    tmp = invMod(a[i][j], q);
    for (int k = j; k < n; ++k)
      a[i][k] = a[i][k] * tmp % q;
    pivot[i++] = j, rank++;
  }
  // 解の存在のチェック
  for (int i = rank; i < m; ++i)
    if (a[i][n-1] != 0) return false;
  // 解をxに代入（後退代入）
  for (int i = 0; i < rank; ++i)
    x[i] = a[i][n-1];
  for (int i = rank-1; i >= 0; --i) {
    for (int j = pivot[i] + 1; j < n-1; ++j)
      x[i] -= a[i][j] * x[j];
//    x[i] -= x[i] / q * q, x[i] = (x[i] + q) % q;  // 0 <= x[i] < q に調整
  }
  rep(i, x.size()) x[i] += Mod(0);
  return true;
}
arr solve(matrix a, arr b) {
    int m = a.size();
    arr ret(a.size());
    rep(i, a.size()) {
        a[i].pb(b[i]);
    }
    gauss(a, ret, m, m+1, mo);
    return ret;
}

// a x + b y = gcd(a, b)なるx, yを一つ探す。
//
// g = gcd(a, b)として、
// 任意の整数kについて(x+k*b/g, y+k*a/g)が必要十分な解空間となる。
long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

// a x = b (mod m)を解く
// これはa x + m k = bなるxの全列挙に他ならない。
//
// bがgcd(a, m)で割り切れないならば、
// 解なしである。
// 
// 割り切れるならば
// すなわち、extgcd(a, m, x, k), x *= b / gcd(a, m), k *= b / gcd(a, m)で解ける。
// 任意の整数nについて、x+n*m/gcd(a, m)が解である。
//
// ret.fi, ret.seに対して、
// (1) ret.fi+k*ret.seが任意の解で、ret.fiは最小非負解
// (2) ret.fiが-1だと解なし
P solveLinearEquation(ll a, ll b, ll m) {
    if (b % __gcd(a, m) != 0) {
        return P(-1, -1);
    } else {
        ll x, k;
        extgcd(a, m, x, k), x *= b / __gcd(a, m), k *= b / __gcd(a, m);
        P ret = P(x, m / __gcd(a, m));
        ret.fi %= ret.se;
        ret.fi += ret.se;
        ret.fi %= ret.se;
        return ret;
    }
}

/*************************************/
// 謎演算
/*************************************/



// 線型連立合同式 a[i] x == b[i] (mod m[i]) (i = 0, ..., n-1) を解く．
bool linearCongruences(const vector<long long> &a,
        const vector<long long> &b,
        const vector<long long> &m,
        long long &x, long long &M) {
    int n = a.size();
    x = 0; M = 1;
    rep(i, n) {
        long long a_ = a[i] % M, b_ = b[i] - a[i] * x, m_ = m[i];
        long long y, t, g = extgcd(a_, m_, y, t);
        if (b_ % g) return false;
        b_ /= g; m_ /= g;
        x += M * (y * b_ % m_);
        M *= m_;
    }
    x = (x + M) % M;
    return true;
}

// オイラーのφ関数
// LookUp Version
const int N = 1000000;
long long eulerPhi(long long n) {
    static int lookup = 0, p[N], f[N];
    if (!lookup) {
        rep(i,N) p[i] = 1, f[i] = i;
        for (int i = 2; i < N; ++i) {
            if (p[i]) {
                f[i] -= f[i] / i;
                for (int j = i+i; j < N; j+=i)
                    p[j] = 0, f[j] -= f[j] / i;
            }
        }
        lookup = 1;
    }
    return f[n];
}


//vector<Mod> fact, rfact;
ll n;
vll a;
Mod f(void) {
    Mod ret = 1;
    ret *= fact[n-2];
    rep(i, n) {
        ret *= rfact[a[i]-1];
    }
    return ret;
}

// ちょうどi個を見終えて、残りがsで、現在の配列がaである場合。
ll c = 0;
void f(vll& x) {
    rep(i, x.size()) if (x[i] == 0) return;
    cout << x << endl;
    
}
void dfs(ll s, ll i, vll& a, const vll& amax, const int target_sum, vll& amaxsum) {
    if (amaxsum.back() - amaxsum[i] < s) return; // 枝刈り
    if (s && i == a.size()) return;
    if (!s) {
//        assert(accumulate(a.begin(), a.end(), 0ll) == target_sum);
        c++;
        f(a);
        return;
    }
    rep(j, min(s, amax[i])+1) {
        a[i] = j;
        dfs(s-j, i+1, a, amax, target_sum, amaxsum);
        a[i] = 0;
    }
}
void start_dfs(const vll amax, const int target_sum) {
    c = 0;
    ll s = target_sum; vll a(amax.size()); 
    vll amaxsum(amax.size()+1);
    rep(i, amax.size()) amaxsum[i+1] = amaxsum[i] + amax[i];
    dfs(s, 0, a, amax, target_sum, amaxsum);
}


int main(void) {
    cin >> n;
    a = vll(n); cin >> a;

    vll lim;
    rep(i, n) lim.pb(n+1);
    start_dfs(lim, 2*n);
    return 0;
}
