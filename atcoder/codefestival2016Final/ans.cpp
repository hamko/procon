#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
 
using ll = long long; using vll = vector<ll>; using vvll = vector<vll>;
static const long long INF = 1e18;
 
int main(void) {
    ll n, a; cin >> n >> a; assert(n<=1e6&&a<=1e6);
    vll dp(4*n, INF); // dp[i] = ちょうどi枚用意するための最小時間
    dp[0] = 0, dp[1] = 1;
 
    // 配るDP
    repi(i, 1, dp.size()) {
        chmin(dp[i+1], dp[i] + 1);
        for (ll j = 1; j * i < dp.size(); j++) {
            chmin(dp[j*i], dp[i] + a + j);
        }
    }
    ll ret = INF;
    repi(i, n, dp.size()) 
        chmin(ret, dp[i]);
    cout << ret << endl;
 
    return 0;
}
