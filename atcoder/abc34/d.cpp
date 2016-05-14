#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

ll k, n; 
vll p, w;
bool check(double x) {
    vector<double> s(n);
    rep(i, n) {
        s[i] = w[i] * (p[i] - x);
    }
    sort(all(s), greater<double>());
    double ret = 0;
    rep(i, min(k, n)) ret += s[i];
    return ret >= 0;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
//    cin >> k >> n;
    cin >> n >> k; p.resize(n); w.resize(n);
    rep(i, n) cin >> w[i] >> p[i];

    double lo = 0, ro = 101; // lが満たさないことを確認！
    rep(_, 100) {
        double mid = (lo + ro) / 2; 
        !check(mid)?ro=mid:lo=mid; 
    }
    printf("%.40lf\n", ro);
    
    return 0;
}
