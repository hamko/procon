#include "bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)

// ヤコビ記号はnot yet
// メビウスのμ関数not yet
// カーマイケルのλ関数 not yet

class Mod {
    public:
        int num;
        int mod;
        Mod() : Mod(0) {}
        Mod(long long int n) : Mod(n, 1000000007) {}
        Mod(long long int n, int m) { mod = m; num = (n % mod + mod) % mod;}
        Mod(const string &s){ long long int tmp = 0; for(auto &c:s) tmp = (c-'0'+tmp*10) % mod; num = tmp; }
        Mod(int n) : Mod(static_cast<long long int>(n)) {}
        operator int() { return num; }
        void setmod(const int mod) { this->mod = mod; }
};
istream &operator>>(istream &is, Mod &x) { long long int n; is >> n; x = n; return is; }
ostream &operator<<(ostream &o, const Mod &x) { o << x.num; return o; }
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % a.mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((a.mod + a.num - b.num) % a.mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % a.mod); }
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
Mod inv(const Mod a) { return a ^ (a.mod - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }
Mod operator/(const long long int a, const Mod b) { assert(b.num != 0); return Mod(a) * inv(b); }
Mod operator/=(Mod &a, const Mod b) { assert(b.num != 0); return a = a * inv(b); }

// n!と1/n!のテーブルを作る。
// nCrを高速に計算するためのもの。
//
// assertでnを超えていないかをきちんとテストすること。
//
// O(n log mo)
vector<Mod> fact, rfact;
void constructFactorial(const long long n) {
    fact.resize(n);
    rfact.resize(n);
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < n; i++) {
        fact[i] = fact[i-1] * i;
        rfact[i] = Mod(1) / fact[i];
    }
}

// O(1)
Mod nCr(const long long n, const long long r) {
//    assert(n < (long long)fact.size());
    if (n < 0 || r < 0) return 0;
    return fact[n] * rfact[r] * rfact[n-r];
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
// 謎演算
/*************************************/

// gcdは関数__gcdを使いましょう。long long対応している。

// a x + b y = gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

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

/*************************************/
// GF(p)の行列演算
/*************************************/
using number = Mod;
using arr = vector<number>;
using matrix = vector<vector<Mod>>;

ostream &operator<<(ostream &o, const arr &v) { rep(i, v.size()) cout << v[i] << " "; cout << endl; return o; }
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
matrix plus(const matrix &A, const matrix &B) {
    matrix C(A.size(), arr(B[0].size(), 0));
    rep(i, C.size())
        rep(j, C[i].size())
            C[i][j] += A[i][j] + B[i][j];
    return C;
}
// O(n^3 log e)
matrix pow(const matrix &A, int e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
// O(n)
number inner_product(const arr &a, const arr &b) {
    number ans = 0;
    for (int i = 0; i < a.size(); ++i)
        ans += a[i] * b[i];
    return ans;
}
// O(n)
number tr(const matrix &A) {
    number ans = 0;
    for (int i = 0; i < A.size(); ++i)
        ans += A[i][i];
    return ans;
}
// O( n^3 )
// modは素数でなければならない！！
number det(matrix A) {
    int n = A.size();
    assert(n == A[0].size());
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
    assert(A[0][0].mod == 2); 
    
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

    return 0;
}

