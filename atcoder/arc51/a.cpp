#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

#define MAX_N 100005

int main(void) {
    int k; cin >> k; 
    ll a[100]; a[0]=0;a[1]=1;
    rep(i, 50) a[i+2]=a[i+1]+a[i];
    cout << a[k+2] << " " << a[k+1] << endl;
    return 0;
}
