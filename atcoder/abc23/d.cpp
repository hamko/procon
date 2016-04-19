#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
static const long long INF = 1e18;

#define MAX_N 100005
int n, h[MAX_N], s[MAX_N];
ll tmp[MAX_N];
bool check(ll p) 
{
    rep(i, n) {
        if (p < h[i]) return false;
        tmp[i] = (p - h[i]) / s[i];
    }
    sort(tmp, tmp+n);
    rep(i, n) if (tmp[i] < i) return false;
    return true;
}

int main(void) {
    cin >> n; rep(i, n) cin >> h[i] >> s[i];
    ll l = -1, r = INF;
    while (r - l != 1) {
        ll mid = (l + r) / 2;
        if (!check(mid)) l = mid; else r = mid;
    }

    cout << r << endl;

    return 0;
}
