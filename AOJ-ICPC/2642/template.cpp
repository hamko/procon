#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, p, q; cin >> n >> p >> q;
    vll c(n); rep(i, c.size()) cin >> c[i];

    vll a(n); rep(i, a.size()) a[i] = c[i] + p * i;
    sort(all(a));

    vll sa(n+1); rep(i, n) sa[i+1] = sa[i] + a[i]; 

    ll sumr = accumulate(all(c), 0ll), ret = sumr;
    rep (k, n+1) 
        chmax(ret, sumr + p * k * (q + k - 1) - sa[k]);

    cout << ret << endl;

    return 0;
}
