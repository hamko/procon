#include <bits/stdc++.h>
using namespace std;

static const long long INF = 1e18;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    double l, x, y, s, d; cin >> l >> x >> y >> s >> d;

    double vel;
    vel = x + y;
    double m = INF;
    if (vel > 0) {
        double tmp = (d - s >= 0 ? d - s : l + d - s);
        chmin(m, tmp/vel);
    }
    vel = x - y;
    if (vel < 0) {
        double tmp = (d - s <= 0 ? d - s : l - d + s);
        chmin(m, abs(tmp/vel));
    }
    cout << setprecision(40) << m << endl;

    return 0;
}
