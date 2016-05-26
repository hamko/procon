#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

using ll = long long; using vll = vector<ll>;

// Point assign
const int N = 1 << 18; // 大きくとってごまかす

ll seg[N * 2]; // 0が総和。実際にはN*2-1は使っていない。

ll merge(ll a, ll b) { // associative op
    return min<ll>(a, b);
}

void update(int k, ll a) {
    k += N - 1;
    seg[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        seg[k] = merge(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
}

int main(void) {
    ll n; cin >> n;
    vll a(n), c(n); rep(i, a.size()-1) cin >> a[i+1] >> c[i+1]; a[0] = 0, c[0] = 0;

    vll g(n);
    g[0] = 0;
    for (int i = 1; i < n; i++) {
        set<ll> m; 
        rep(j, a[i]) 
            m.insert(g[max(0ll, i - j - 1)]);
        int j = 0;
        while (m.count(j)) 
            g[i] = j+++1; 
    }

    ll ret = 0;
    for (int i = 0; i < n; i++) 
        ret ^= (c[i] % 2) * g[i];

    cout << (ret ? "First" : "Second") << endl;
    return 0;
}
