#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
static const long long INF = 1e18;

string a, b;
vll bs;
ll n;
vll rpos, lpos;
void constructPos(void) {
    repi(i, 1, 6*n) 
        chmin(lpos[i%n], b[i%n] == '1' ? 0 : lpos[(i-1)%n] + 1);
    for (ll i = 6*n; i>=1; i--) 
        chmin(rpos[i%n], b[i%n] == '1' ? 0 : rpos[(i+1)%n] + 1);
}

// 右にd回移動する時、何回移動しなければならないか
ll calc(ll d) {
    ll flips = 0;
    vector<P> lr;
    rep(i, n) {
        if (a[i] != b[i+d]) {
            flips++;
            // b[i, i+d]に1がないといけない, b[i, i+d+1)に1がないといけない
            if (bs[i+d+1] - bs[i]) {
                // 1があるのでどうでもいい
                continue;
            } else {
                // 1がないので左右どちらかに寄り道しないといけない
                lr.pb(P(lpos[i], rpos[(i+d)%n])); 
            }
        }
    }
    if (!lr.size())
        return d + flips;

    sort(all(lr));
    vll rmax(lr.size()+1, -INF); // max r[i, r.size())
    for (ll i = lr.size()-1; i >= 0; i--) 
        rmax[i] = max(rmax[i+1], lr[i].se);

    ll ret = INF;
    rep(i, lr.size()+1) {
        if (!i) 
            chmin(ret, rmax[0]);
        else if (i == lr.size())
            chmin(ret, lr[lr.size()-1].fi);
        else
            chmin(ret, lr[i-1].fi + rmax[i]);
    }

    return d + flips + ret * 2;
}

ll solve(void) {
    rpos = lpos = vll(n, INF);
    bs = vll(b.size()+1);
    rep(i, b.size()) bs[i+1] = bs[i] + b[i] - '0'; 

    ll ret = INF;
    constructPos();
    rep(i, rpos.size()) { assert(rpos[i] != INF); }
    rep(i, lpos.size()) { assert(lpos[i] != INF); }
    rep(d, 2*n) chmin(ret, calc(d));

    return ret;
}

int main(void) {
    cin >> a >> b;
    n = a.size();
    ll af = 1, bf = 1;
    rep(i, n) af &= a[i] == '0', bf &= b[i] == '0';
    if (bf == 1) {
        if (af == 1) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    a += a; a += a;
    b += b; b += b;

    ll ret = INF;
    chmin(ret, solve());
    reverse(all(a));
    reverse(all(b));
    chmin(ret, solve());
    
    cout << ret << endl;

    return 0;
}
