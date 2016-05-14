#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<string> a(n); rep(i, a.size()) cin >> a[i];
    rep(i, a.size()) reverse(all(a[i]));
    sort(all(a));
    rep(i, a.size()) reverse(all(a[i]));
    rep(i, a.size()) cout << a[i] << endl;
    return 0;
}
