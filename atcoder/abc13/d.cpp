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

    ll n, m, d; cin >> n >> m >> d;
    const ll logd = 100;
    vector<vll> f(logd, vll(n));

    vi a(m); rep(i, m) { cin >> a[i]; a[i]--; }
    vi c(n); rep(i, n) c[i] = i;
    rep(i, m) swap(c[a[m-1-i]], c[a[m-1-i]+1]);
    rep(i, n) f[0][i] = c[i];

    rep(i, logd - 1) rep(j, n) {
        f[i+1][j] = f[i][f[i][j]];
    }
    rep(i, n) {
        ll ret = i;
        rep(j, 32) {
            if (!(d & (1 << j)))
                continue;
            ret = f[j][ret];
        }
        cout << ret + 1 << endl;
    }

    return 0;
}
