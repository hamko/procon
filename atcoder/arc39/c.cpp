#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define mt make_tuple
using ll = long long; using vll = vector<ll>;

ll conv[256];
vector<ll> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
map<tuple<ll, ll>, tuple<ll, ll>> memo[4];
int main(void) {
    ll n; cin >> n;
    conv['R'] = 1, conv['D'] = 2, conv['L'] = 3;

    tuple<ll, ll> now = mt(0, 0);
    rep(i, n) {
        char c; cin >> c;
        rep(d, 4) if (!memo[d].count(now)) {
            memo[d][now] = mt(get<0>(now)+dx[d], get<1>(now)+dy[d]);
            memo[(d+2)%4][memo[d][now]] = now;
        }
        auto next = memo[conv[c]][now];
        rep(d, 4) 
            memo[(d+2)%4][memo[d][now]] = memo[(d+2)%4][now];
        now = next;
    }
    cout << get<0>(now) << " " << get<1>(now) << endl;

    return 0;
}
