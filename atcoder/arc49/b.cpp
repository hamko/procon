#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
int n;
int x[1005], y[1005], c[1005];

bool check(double time) {
    double xl = -1e+9, xr = 1e+9, yl = -1e+9, yr = 1e+9;
    rep(i, n) {
        xl = max(xl, x[i] - time / c[i]); 
        xr = min(xr, x[i] + time / c[i]);
        yl = max(yl, y[i] - time / c[i]); 
        yr = min(yr, y[i] + time / c[i]);
    }
    return (xl < xr && yl < yr);
}

int main(void) {
    cin >> n;
    rep(i, n)
        cin >> x[i] >> y[i] >> c[i];

    double l = +1e9, r = 0;
    rep(count, 1000) {
        double mid = (l + r) / 2;
        if (check(mid)) 
            l = mid;
        else 
            r = mid;
    }
    cout << l << endl;

    return 0;
}
