#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long; using vll = vector<ll>;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n); rep(i, n) cin >> a[i];

    set<ll> memo;
    ll ret = 0;
    rep(i, n) 
        if (memo.count(a[i])) 
            ret++;
        else 
            memo.insert(a[i]);
    cout << ret << endl;
    
    return 0;
}
