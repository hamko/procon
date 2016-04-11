#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
int n;
int x[1005], y[1005], c[1005];

bool check(double time, int* d) {
    double l = -1e+9, r = 1e+9;
    rep(i, n) {
        double nl = d[i] - time / c[i];
        double nr = d[i] + time / c[i];
        if (r < nl) return false;
        if (l > nr) return false;
        l = max(l, nl);
        r = min(r, nr);
    }
    return true;
}

double retmin(int* d)
{
    // 0000000000000000000111111
    double l = +1e9, r = 0;
    rep(count, 1000) {
        double mid = (l + r) / 2;
        if (check(mid, d)) 
            l = mid;
        else 
            r = mid;
    }
    return l;
}

int main(void) {
    cin >> n;
    rep(i, n)
        cin >> x[i] >> y[i] >> c[i];
//    cout << min(retmin(x), retmin(y)) << endl;
    return 0;
}
