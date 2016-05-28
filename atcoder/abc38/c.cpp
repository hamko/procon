#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

int main(void) {
    ll n; cin >> n;
    vll a(n); rep(i, a.size()) cin >> a[i];
    ll ret = 0;
    int j = 1;
    rep(i, n) {
        j = max<ll>(j, i+1);
        while (j < n && a[j-1] < a[j]) 
            j++;
        ret+=(j-i);
    }
    cout << ret << endl;

    return 0;
}
