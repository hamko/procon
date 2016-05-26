#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vld = vector<ld>; 

int main(void) {
    ll n; 
    while (cin >> n && n) {
        vld x(n), y(n); rep(i, n) cin >> x[i] >> y[i];
        auto d = [&](ll i, ll j) { return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]); };
        ll ret = 1;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                ld dij = d(i, j);
                if (dij >= 4.0l) continue;
                ld x1 = x[i], y1 = y[i], x0 = x[j], y0 = y[j];
                for (auto dir : {1.0l, -1.0l}) {
                    ld xc = x0 + (x1 - x0) / 2.0l + (-(y1 - y0)) * dir 
                        * sqrtl(1.0l - ((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)) / 4.0l) 
                        / sqrtl((y1 - y0) * (y1 - y0)  + (x1 - x0) * (x1 - x0));
                    ld yc = y0 + (y1 - y0) / 2.0l + (+(x1 - x0)) * dir 
                        * sqrtl(1.0l - ((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)) / 4.0l) 
                        / sqrtl((y1 - y0) * (y1 - y0)  + (x1 - x0) * (x1 - x0));
                    ll m = 2;
                    rep(k, n) {
                        if (k == i || k == j) continue;
                        if ((xc - x[k]) * (xc - x[k]) + (yc - y[k]) * (yc - y[k]) < 1.0l) 
                            m++;
                    }
                    chmax(ret, m);
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}
