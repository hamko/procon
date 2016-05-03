#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i == j) return i; else return ((ll)rand() * rand()) % (j - i) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

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
Mod modpowsum(const Mod a, const int b) {
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

ll hamko(ll n, vector<ll>& a) {
    if (a[0] != 0) {
        return 0;
    }
    rep(i, n) { 
        if (i == 0) continue;
        if (a[i] == 0) {
            return 0;
        }
    }
    sort(all(a));
    rep(i, n-1) { 
        if (a[i+1] - a[i] != 0 && a[i+1] - a[i] != 1) {
            return 0;
        }
    }

    ll m = Max(a);

    unordered_map<int, ll> c;
    rep(i, n) { c[a[i]]++; }
    ll maxc = 0;
    rep(i, m) {
        maxc = max(maxc, c[i]);
        if (!c[i]) {
            return 0;
        }
    }

    Mod ret = 1;
    rep(i, m) {
        ret *= ((Mod)2^((ll)c[i+1]*((ll)c[i+1]-1)/2)) * ((((Mod)2^c[i])-(Mod)1)^c[i+1]); 
        cout << ret<< "#hamko" << endl;
    }
    return ret;
}
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
 
const ll mod = 1e9+7;

inline ll pow(ll p, ll n){
    ll res = 1;
    while(n){
        if(n&1) (res *= p) %= mod;
        p = p*p % mod;
        n >>= 1;
    }
    return res;
}

ll Darsein(ll n, vector<ll>& a){
    if(a[0] != 0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    vector<ll> cnt(n);
    ll max_d = 0;
    rep(i,n){
        cnt[a[i]]++;
        max_d = max(max_d, a[i]);
    }

    ll ans = (cnt[0]==1 && cnt[1]) ? pow(2,(cnt[1]*(cnt[1]-1)/2)) : 0;
    cout << "pow : 2^" <<  ((cnt[1]*(cnt[1]-1)/2)) << " = " << ans << "#D" << endl;
    for(int d=1;d<max_d;d++){
        ll a = cnt[d], b = cnt[d+1];

        ll p1 = ((ll)pow(2,a) + mod - 1) % mod;
        ( ans *= pow(p1,b) ) %= mod;
        ( ans *= pow(2,(b*(b-1))/2) ) %= mod;
    }
    return ans;
}


int main(void)
{
//    int seed; cin >> seed; srand(seed);

    int count = 0;
    int th = 100;
    /*
    while (1) {
        count++; 
        if (count % th == 0) 
            th *= 2, cout << count << endl;
        
        ll n = randr(1, (ll)10);
        ll max = 2;
        vector<ll> a(n);
        rep(i, n)
            a[i] = randr(1, max);
        a[0] = 0;
        if (hamko(n, a) != Darsein(n, a)) {
            cout << n << endl;
            rep(i, n)
                cout << a[i] << " ";
            cout << endl;
            cout << hamko(n, a) << " " <<  Darsein(n, a) <<"#"<< endl;
        }
    }
    */

    ll n = 10;
    vector<ll> a(n, 1); a[0] = 0;
    if (hamko(n, a) != Darsein(n, a)) {
        cout << n << endl;
        rep(i, n)
            cout << a[i] << " ";
        cout << endl;
        cout << hamko(n, a) << " " <<  Darsein(n, a) <<"#"<< endl;
    }

    return 0;
}

