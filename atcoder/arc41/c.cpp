#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define print(v) for(auto x:(v)){cout<<x<<" ";}cout<<endl;
#define printi(b,e) for(auto x=(b); x!=(e); x++)cout<<*x<<" ";cout<<endl;
#define printa(a,n) rep(i,n)cout<<a[i]<<" ";cout<<endl;
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    int n; cin >> n;
    map<int, int> m;
    rep(i, n) { int x, y; cin >> x >> y; m[x] = y; }

    return 0;
}
