#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)

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
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator^(const Mod a, const int n) { if (n == 0) return Mod(1); Mod res = (a * a) ^ (n / 2); if (n % 2) res = res * a; return res; }
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }


int main(void) {
    int A, B, C; cin >> A >> B >> C;
    Mod a(A), b(B), c(C);
    swap(b, c), cout << b * (c - a) / (a * c + a * b - b * c) << " ";
    swap(b, c), cout << b * (c - a) / (a * c + a * b - b * c);
    cout << endl;
    
    return 0;
}
