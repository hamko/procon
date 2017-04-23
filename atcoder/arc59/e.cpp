#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;

struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); }} init__;

static const long long mo = 1e9+7;

int main(void) {
    ll n, c; cin >> n >> c;
    vll a(n), b(n); rep(i, n) cin >> a[i]; rep(i, n) cin >> b[i];
    ll M = 410;
    vvll dp(M, vll(M));
    vvll jk(M, vll(M, 1)); // j^k
    rep(j, M) rep(k, M-1) {
        (jk[j][k+1] = j * jk[j][k]) %= mo;
    }

    vvll jksum(M, vll(M)); // \sum_{x \in [0, k)} j^x 
    rep(k, M) rep(j, M-1) {
        (jksum[j+1][k] = jk[j][k] + jksum[j][k]) %= mo;
    }

    // \sum_{j \in [l, r]} j^k = jksum[r+1][k] - jksum[l][k];
    auto f = [&](ll i, ll k) {
        return (jksum[b[i]+1][k] - jksum[a[i]][k] + mo) % mo;
    };

    dp[0][0] = 1;
    repi(alpha, 1, n+1)  rep(beta, c+1) rep(k, beta+1) 
        (dp[alpha][beta] += f(alpha-1, k) * dp[alpha-1][beta - k]) %= mo;

    cout << (dp[n][c] + mo) % mo << endl;

    return 0;
}
