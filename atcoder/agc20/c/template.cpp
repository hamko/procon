#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define all(x) (x).begin(), (x).end()
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
using ll = long long; using vll = vector<ll>; 
int main(void) {
    ll n; cin >> n; vll a(n); cin >> a;
    bitset<4000010> dp; dp[0] = 1; rep(i, n) dp |= (dp << a[i]);
    ll s = accumulate(all(a), 0ll);
    repi(i, s/2+(s&1), 4000010) if (dp[i]) 
        return cout << i << endl, 0;
}
