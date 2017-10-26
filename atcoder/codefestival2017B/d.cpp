#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define fi first
#define se second
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

ll n; string s;
int main(void) {
    cin >> n; cin >> s;
    vll a;
    ll i = 0;
    while (i < n) { 
        if (s[i] == '0') {
            if (i < n-1 && s[i+1] == '0') 
                a.pb(0);
            while (s[i] == '0' && i < n) i++;
        } else {
            a.pb(0);
            while (s[i] == '1' && i < n) a.back()++, i++;
        }
    }

    n = a.size();
    // 配るDP
    vector<map<ll, ll>> dp(n+1);
    dp[0][0] = 0;
    rep(i, n) {
        for (auto x : dp[i]) {
            ll p = x.fi, score = x.se;
            if (p > 0 && a[i] > 0) {
                chmax(dp[i+1][a[i]-1], score + p);
                chmax(dp[i+1][0], score + a[i]);
                if (a[i] > 1) chmax(dp[i+1][1], score + a[i] - 1);
            }
            chmax(dp[i+1][a[i]], score);
        }
    }
    ll ret = 0;
    for (auto x : dp[n]) chmax(ret, x.se);
    cout << ret << endl;

    return 0;
}
