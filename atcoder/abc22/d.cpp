#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Max(x) *max_element(all(x))
using ld = long double;

int main(void) {
    int n; cin >> n;
    vector<ld> ax(n), ay(n); rep(i, n) cin >> ax[i] >> ay[i];
    vector<ld> bx(n), by(n); rep(i, n) cin >> bx[i] >> by[i];
    
    ld cx = accumulate(all(bx), (ld)0) / n, cy = accumulate(all(by), (ld)0) / n;
    ld dx = cx - accumulate(all(ax), (ld)0) / n;
    ld dy = cy - accumulate(all(ay), (ld)0) / n;
    transform(all(ax), begin(ax), [&](const ld& x){return x + dx;});
    transform(all(ay), begin(ay), [&](const ld& y){return y + dy;});

    vector<ld> da(n), db(n);
    auto dist = [&](const ld& x, const ld& y){return sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));};
    transform(all(ax), begin(ay), begin(da), dist);
    transform(all(bx), begin(by), begin(db), dist);

    printf("%.40Lf\n", Max(db) / Max(da));

    return 0;
}
