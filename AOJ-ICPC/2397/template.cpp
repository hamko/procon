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

class Mod {
    public:
        int num;
        int mod;
        Mod() : Mod(0) {}
        Mod(long long int n) : Mod(n, 1000000009) {}
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
// 構築付なし累乗
//
// O(n^3 log e)
matrix pow(const matrix &A, long long e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
// 構築付き累乗
//
// powA: A^2^i
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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll w, h, n;
    ll counter = 0;
    while (cin >> w >> h >> n && w) {
        counter++;
 
        map<ll, vll> obj;
        rep(i, n) {  
            ll x, y; cin >> x >> y; 
            obj[y].pb(x);
        }
        ll index = 1;
        matrix A = zero(w);
        rep(i, w) 
            for (int j = -1; j <= 1; j++) 
                if (i + j >= 0 && i + j < w)
                    A[i][i+j] = 1;

//        pow(long long e, const vector<matrix>& powA) { // powA[0]がA
        vector<matrix> powA;
//        cerr << "constructing..." << endl;
        construct_powA(A, 2 * h, powA);
//        cerr << "constructed" << endl;
//        cout << powA << endl;

        arr a(w);
        rep(i, w)
            a[i] = 0;
        a[0] = 1;
        
//        matrix ret = identity(w);
        while (index != h) {
//            cerr << index << "/" << h << endl;
            auto next_obj = obj.upper_bound(index);
            if (next_obj != obj.end()) {
                matrix Aobj = A;
                for (auto x : next_obj->se) {
                    rep(i, w) {
                        Aobj[x-1][i] = 0;
                    }
                }

//                matrix A_e = pow(A, next_obj->fi - index - 1);
//                cerr << ".";
//                matrix A_e = pow(powA, next_obj->fi - index - 1);
                a = powmul(powA, next_obj->fi - index - 1, a);
//                cerr << ".";
//                a = mul(A_e, a);
//                cerr << ".";
                a = mul(Aobj, a);
//                cerr << ".";
//                cerr << "end" << endl;

                index = next_obj->fi;
            } else {
//                matrix A_e = pow(A, h - index);
                matrix A_e = pow(powA, h - index);
                a = mul(A_e, a);
                index = h;
            }
//            cout << index << "#index" << endl;
//              cout << mul(ret, a) << endl;
//            cout << "#ret" << endl;
//            cout << ret << endl;
        }
//        a = mul(ret, a);
        cout << "Case " << counter << ": " << a[w-1] << endl;
    }
    return 0;
}
