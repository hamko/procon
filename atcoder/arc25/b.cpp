#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    vector<vll> b(n+1, vll(m+1, 0));
    vector<vll> w(n+1, vll(m+1, 0));
    rep(i, n) rep(j, m) if ((i + j) % 2 == 0) cin >> b[i+1][j+1]; else cin >> w[i+1][j+1];
    rep(i, n) rep(j, m) b[i+1][j+1] += b[i+1][j];
    rep(i, n) rep(j, m) b[i+1][j+1] += b[i][j+1];
    rep(i, n) rep(j, m) w[i+1][j+1] += w[i+1][j];
    rep(i, n) rep(j, m) w[i+1][j+1] += w[i][j+1];

    ll ret = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 1; k < n - i + 1; k++) for (int l = 1; l < m - j + 1; l++) {
        ll wsum = w[i+k][j+l]-w[i+k][j]-w[i][j+l]+w[i][j];
        ll bsum = b[i+k][j+l]-b[i+k][j]-b[i][j+l]+b[i][j];
        if (wsum == bsum) 
            ret = max(ret, (ll)k * l);
    }
    cout << ret << endl;



    return 0;
}
