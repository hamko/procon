#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
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

static const long long INF = 1e18;
static const long long mo = 1e9+7;

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
Mod operator^(const Mod a, const long long n) {
    if (n == 0) return Mod(1);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}

/*************************************/
// 以下、modは素数でなくてはならない！
/*************************************/
Mod inv(const Mod a) { return a ^ (a.mod - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }
Mod operator/(const long long int a, const Mod b) { assert(b.num != 0); return Mod(a) * inv(b); }
Mod operator/=(Mod &a, const Mod b) { assert(b.num != 0); return a = a * inv(b); }

// n!と1/n!のテーブルを作る。
// nCrを高速に計算するためには、n以上を指定する。
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
Mod nCr(const long long n, const long long r) {
//    assert(n < (long long)fact.size());
    if (n < 0 || r < 0) return 0;
    return fact[n] * rfact[r] * rfact[n-r];
}
// n*mの盤面を左下から右上に行く場合の数
Mod nBm(const long long n, const long long m) {
    if (n < 0 || m < 0) return 0;
    return nCr(n + m, n);
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m, p; cin >> n >> m >> p;
    constructFactorial(300000);
    Mod ret = 0;
    rep(k, p+1) {
        vector<P> cands = {P(n, k), P(m, p - k)};
        Mod tmp = 1;
        for (auto x : cands) {
            tmp *= nBm(x.se + x.fi, x.se) - nBm(x.se + x.fi + 1, x.se - 1);
        }
        tmp *= nBm(cands[0].fi + cands[0].se * 2, cands[1].fi + cands[1].se * 2);
        ret += tmp;
    }
    cout << ret << endl;

    return 0;
}
