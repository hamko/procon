#include "bits/stdc++.h"
using namespace std;

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }

// 注意！！！！！！！！！！
//
// numは-mo<num<moが保証されるが、マイナスにもなりえる。
// 出力段階できちんと(x+mo)%moとすること。
//
static const long long mo = 1e9+7;
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



int main() {
    cout << __gcd(12, 18) << endl;

    cout << ((Mod)2 + (Mod)10) << endl;
    cout << ((Mod)2 ^ 10ll) << endl;
    cout << ((Mod)3 ^ 1000000ll) << endl;
    Mod r(1000000), c(1000000);
    cout << r * c + (Mod)1 << endl;
    cout << modpowsum(3, 4) << endl; // 1 + 3 + 9 + 27

    long long   n = 8e18;
    printf("long long x 1= %Ld\n", n);
    //    printf("long long x 2 = %Ld\n", n*2); // overflow
    long double m = n;
    printf("long double x 1= %Lf\n", m);
    printf("long double x 2 = %Lf\n", m*2);

    string s = "10000000000000";
    Mod mod_from_str(s);
    cout << mod_from_str << "#from string" << endl;

    cout << "Input also works" << endl;
    Mod input;
    cin >> input; // input 10000000000
    cout << input << endl;

    {
        const int m = 4;
        matrix a = {
            {1, 1, 1, 0},
            {1, 1, 0, 1}, 
            {1, 0, 1, 1},
            {0, 1, 1, 1},
        };
        arr b = {1, 0, 0, 1};

        arr ret(m);
        for (int i = 0; i < m; ++i)
            cout << ret[i] << " ";
        cout << endl;

        cout << a << endl;
        cout << b << endl;
        auto x = solve(a, b);
        cout << x << "#ret" << endl;
        cout << mul(a, x) << endl;
    }

    
    {
        // a x + b y = gcd(a, b)
        // g = gcd(a, b)として、任意の整数kについて(x+k*b/g, y+k*a/g)が必要十分な解空間となる。
        ll a, b;
        ll x, y;
        
        // 2 x + 5 y = 1
        a = 2, b = 5;
        extgcd(a, b, x, y);
        cout << a << " " << x << " + " << b << " " << y << " = " << __gcd(a, b) << endl;

        // 4 x + 10 y = 2
        a = 4, b = 10;
        extgcd(a, b, x, y);
        rep(i, 10) { // 解空間の列挙
            cout << a << " " << x << " + " << b << " " << y << " = " << __gcd(a, b) << endl;
            x += b / __gcd(a, b), y -= a / __gcd(a, b);
        }
    }


    {
        // a x = b (mod m)を解く
        P ret; // ret.fi+k*ret.seが全てxの解である。

        ret = solveLinearEquation(4, 6, 10);
        cout << ret << endl;

        ret = solveLinearEquation(4, 0, 10);
        cout << ret << endl;

        ret = solveLinearEquation(4, 5, 10);
        cout << ret << endl;
    }

    return 0;
}
