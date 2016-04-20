#include "bits/stdc++.h"
using namespace std;

// ヤコビ記号はnot yet
// メビウスのμ関数not yet
// カーマイケルのλ関数 not yet

const int mod = 1000000007;
class Mod {
    public:
        int num;
        Mod() : Mod(0) {}
        Mod(long long int n) : num((n % mod + mod) % mod) {}
        Mod(int n) : Mod(static_cast<long long int>(n)) {}
        operator int() { return num; }
};
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
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
Mod operator^(const Mod a, const int n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }
Mod operator/(const long long int a, const Mod b) { assert(b.num != 0); return Mod(a) * inv(b); }
Mod operator/=(Mod &a, const Mod b) { assert(b.num != 0); return a = a * inv(b); }
// a^0 + ... + a^(b-1) (MOD mod), bに対してO((log n)^2)
// condition: mod^mod<LLONG_MAX
Mod modpowsum(const Mod a, const int b) {
    if (b == 0) return 0;
    if (b % 2 == 1) return modpowsum(a, b - 1) * a + Mod(1);
    Mod result = modpowsum(a, b / 2);
    return result * (a ^ (b / 2)) + result;
}

// ------

// gcdは関数__gcdを使いましょう。ll対応している。

// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
      Int g = a; x = 1; y = 0;
        if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
          return g;
}

// 線型連立合同式 a[i] x == b[i] (mod m[i]) (i = 0, ..., n-1) を解く．
bool linearCongruences(const vector<Int> &a,
                               const vector<Int> &b,
                                                      const vector<Int> &m,
                                                                             Int &x, Int &M) {
      int n = a.size();
        x = 0; M = 1;
          REP(i, n) {
                  Int a_ = a[i] % M, b_ = b[i] - a[i] * x, m_ = m[i];
                      Int y, t, g = extgcd(a_, m_, y, t);
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
Int eulerPhi(Int n) {
      static int lookup = 0, p[N], f[N];
        if (!lookup) {
                REP(i,N) p[i] = 1, f[i] = i;
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
    cout << ((Mod)2 ^ 10) << endl;
    cout << ((Mod)3 ^ 1000000) << endl;
    cout << modpowsum(3, 4) << endl; // 1 + 3 + 9 + 27

    long long   n = 8e18;
    printf("long long x 1= %Ld\n", n);
    printf("long long x 2 = %Ld\n", n*2);
    long double m = n;
    printf("long double x 1= %Lf\n", m);
    printf("long double x 2 = %Lf\n", m*2);


    return 0;
}

