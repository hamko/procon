#include <bits/stdc++.h>
using namespace std;

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
Mod factorial(const long long n) {
    if (n < 0) return 0;
    Mod ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
Mod combination3(const long long a, const long long b, const long long c) {
    if (a < 0 || b < 0 || c < 0) return 0;
    return factorial(a+b+c)/factorial(a)/factorial(b)/factorial(c);
}

#define rep(i,n) for(int i = 0; i < n; i++)
Mod solve_simple(Mod r, Mod c, Mod x, Mod y, Mod d, Mod l) {
    return (r-x+(Mod)1) * (c-y+(Mod)1) * combination(x * y, d);
}
 
Mod solve_general(Mod r, Mod c, Mod x, Mod y, Mod d, Mod l) {
    Mod ret = 0;
    rep(i, 1<<4) {
        Mod tmp = 1; if (__builtin_popcount(i) % 2) tmp *= -1;
        int tmpx = x, tmpy = y;
        if (i & (1 << 0)) tmpx--; if (i & (1 << 1)) tmpx--;
        if (i & (1 << 2)) tmpy--; if (i & (1 << 3)) tmpy--;
        if (tmpx<=0 || tmpy<=0) continue;
        tmp *= combination3(d, l, tmpx*tmpy-(int)d-(int)l);
        ret += tmp;
    }
    return (r-x+(Mod)1) * (c-y+(Mod)1) * ret;
}

int main(void) {
    rep(R, 50) {
        rep(C, 50) {
            rep(X, R) {
                rep(Y, C) {
                    rep(D, X*Y) {
                        int L = X*Y - D;
                        if (solve_simple(R, C, X, Y, D, L) != solve_general(R, C, X, Y, D, L)) {
                            cout << R << " " << C << " " << X << " " << Y << " " << D << " " << L << " " << solve_simple(R, C, X, Y, D, L) << " " << solve_general(R, C, X, Y, D, L) << endl;
                        }
                    }
                }

            }
        }
    }

    return 0;
}
