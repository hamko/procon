#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

static const long long INF = 1e10;

ll BinarySearch(ll rl, ll rr, function<bool(ll)> f) { 
    ll lo = rl-1, ro = rr+1;
    while (ro - lo != 1) {
        ll m = (lo + ro) / 2; 
        (m!=rl-1&&f(m))?ro=m:lo=m; 
    }
    return ro;
}
void BinarySearchInteractive(ll rl, ll rr, function<bool(ll)> f) { 
    while (1) {
        cout << "####" << endl;
        ll tmp; cin >> tmp;
        if (rl > tmp) {cout << "Out of range: too small" << endl; continue; }
        if (rr < tmp) {cout << "Out of range: too large" << endl; continue; }
        ll ret = f(tmp); cout << tmp << " : " << ret << endl;
    }
}

void fair(ll n, ll s) {
    if (s % n == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vll a(n); rep(i, a.size()) cin >> a[i];
    sort(all(a));
    vll s(n+1); rep(i, a.size()) s[i+1] = s[i] + a[i];

    auto f = [&](ll x){
        int i = (upper_bound(all(a), x) - a.begin());
        return s[n] - s[i] - (n - i) * x <= k;
    };
    
    ll x = BinarySearch(0, INF, f);
    int i = (lower_bound(all(a), x) - a.begin());
    ll y = s[n] - s[i] - (n - i) * x;

    auto g = [&](ll x){
        int i = (lower_bound(all(a), x) - a.begin()) - 1;
        if (i == -1) return false;
        return (i+1) * x > s[i+1] + k; // i * xでオーバーフロー
    };
    ll ret = BinarySearch(0, INF, g);
    if (x <= ret) {
        fair(n, s[n]);
        return 0;
    }

    ll ans = x - (ret - 1);
    if (i * ret == s[i] + k) 
        ans--;
    cout << ans << endl;

    return 0;
}
