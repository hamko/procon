#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;
typedef pair<ll, int> LP;

#define MAX_N 100005
const ll MOD = (1e9+7);

// a^b (MOD mod)
// bに対してO(log n)
ll modpow(ll a, ll b, ll mod) {
    ll ret = 1;
    for (; b > 0; a = a * a % mod, b /= 2) if (b & 1) ret = ret * a % mod;
    return ret;
}

int n; ll A, B;
bool start_loop(vector<ll>& a) {
    bool faf = 1;
    rep(i, a.size()) rep(j, a.size()) {
        if (!((double)a[i] - (double)a[j] / A > 0)) {
            faf = 0;
            break;
        }
    }
    return faf;
}
int main(void) {
    cin >> n >> A >> B;
    vector<ll> a; rep(i, n) {ll tmp; cin >> tmp; a.push_back(tmp); }
    vector<ll> a_org = a;
    if (A == 1) {
        sort(all(a));
        rep(i, a.size()) {
            cout << a[i] << endl;
        }
        return 0;
    }
    
    int count = 0;
    while (1) {
//        rep(i, a.size()) cout << a[i] << " "; cout << endl;
        count++;
        auto it = min_element(all(a));
        (*it) *= A;
        if (count >= B) { //  < ?
            sort(all(a));
            rep(i, n) cout << a[i] % MOD << endl;
            return 0;
        }
        if (start_loop(a)) {
            break;
        }
    }
    int I = (B - count) % n;

    vector<LP> b;
    rep(i, a.size()) {
        b.push_back(LP(a[i], i));
    }
    sort(all(b));
    rep(i, a.size()) {
        int index = (I + i) % n;
        if (I + i < n) 
            cout << ((b[index].first%MOD)*modpow(A, (B-count)/n+0, MOD)) % MOD << endl;
        else
            cout << ((b[index].first%MOD)*modpow(A, (B-count)/n+1, MOD)) % MOD << endl;
    }



    return 0;
}
