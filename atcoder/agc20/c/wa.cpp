#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define ll int

double dp[(ll)(4e6+5000)];
int main(void) {
    ll n; cin >> n;
    ll a[2010]; 
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 4e6+10; j>=0; j--) {
            dp[j+a[i]] += dp[j];
        }
    }
    ll x = 0;
    double target = pow(2, n-1);
//    cout << target << endl;
    ll ret = -1;
    for (int i = 1; i < 4e6+10; i++) {
        x += dp[i];
        if (x >= target) {
            ret = i;
            break;
        }
//        cout << x << " " << target << endl; 
    }

    /*
    rep(i, 4e6+10) if (dp[i] != 0) {
        cout << i << " " <<dp[i] << endl;
    }
    */

    cout << ret << endl;
    return 0;
}
