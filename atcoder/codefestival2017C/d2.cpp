#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
using ll = int; using vll = vector<ll>; 
static const long long INF = 1e9;

ll d[200010], e[1ll<<26], a[200010];
int main(void) {
    string s; cin >> s;
    ll n = s.length();
    vll cand; cand.push_back(0); rep(i, 26) cand.push_back(1ll<<i);

    rep(i, n) a[i+1] = a[i] ^ (1ll << (s[i] - 'a'));
    repi(i, 1, 200010) d[i] = INF;
    repi(x, 1, 1ll<<26) e[x] = INF;

    repi(i, 1, n+1) {
        for (auto x : cand) chmin(d[i], e[a[i]^x] + 1);
        chmin(e[a[i]], d[i]);
    }

    cout << d[n] << endl;

    return 0;
}
