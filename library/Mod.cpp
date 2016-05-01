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
// a^0 + ... + a^(b-1) (MOD mod), bに対してO((log n)^2)
// condition: mod^mod<LLONG_MAX
Mod combination(const long long n, const long long k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    Mod ret = 1;
    for (int i = 0; i < k; i++) {
        ret *= n - (Mod)i;
        ret /= Mod(i+1);
    }
    return ret;
}
Mod combination3(const long long a, const long long b, const long long c) {
    if (a < 0 || b < 0 || c < 0) return 0;
    return factorial(a+b+c)/factorial(a)/factorial(b)/factorial(c);
}

// ------

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


int main() {
    cout << __gcd(12, 18) << endl;

    cout << ((Mod)2 + (Mod)10) << endl;
    cout << ((Mod)2 ^ 10) << endl;
    cout << ((Mod)3 ^ 1000000) << endl;
    Mod r(1000000), c(1000000);
    cout << r * c + (Mod)1 << endl;
    cout << modpowsum(3, 4) << endl; // 1 + 3 + 9 + 27

    long long   n = 8e18;
    printf("long long x 1= %Ld\n", n);
    printf("long long x 2 = %Ld\n", n*2);
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

