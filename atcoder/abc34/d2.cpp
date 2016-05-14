#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
using ll = long long; using ld = long double; using vll = vector<ll>; using vld = vector<ld>;

// 浮動小数点二分探索
ld BinarySearchReal(ld rl, ld rr, function<bool(ld)> f) { 
    rep(i, 200) { ld m = (rl + rr) / 2; f(m)?rr=m:rl=m; }
    return rl;
}

int main(void) {
    ll k, n; cin >> n >> k; 
    vll p(n), w(n); rep(i, n) cin >> w[i] >> p[i];

    auto f = [&](ld x){
        vld s(n); rep(i, n) s[i] = w[i] * (p[i] - x);
        sort(all(s), greater<ld>());
        return accumulate(s.begin(), s.begin()+min(k, n), 0.0l) <= 0;
    };
    cout << setprecision(40) << BinarySearchReal(0, 100, f) << endl;

    return 0;
}
