#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

static const double EPS = 1e-14;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ld a, b; cin >> a >> b; if (a > b) swap(a, b);
    ll n; cin >> n;
    rep(i, n) {
        ld c, d; cin >> c >> d; if (c > d) swap(c, d);
        if (a <= c + EPS && b <= d + EPS) { cout << "YES" << endl; continue; }
        if (a >= c - EPS) { cout << "NO" << endl; continue; }

        ld lo = 0, ro = (ld)M_PI/2; // lが満たさないことを確認！
        rep(j, 200) {
            ld mid = (lo + ro) / 2; 
            (!((ld)b*sin(mid)+(ld)a*cos(mid)<=c+EPS))?ro=mid:lo=mid; 
        }
        cout <<((ld)b*cos(lo)+(ld)a*sin(lo)<=d+EPS?"YES":"NO") << endl;
    }
    return 0;
}
