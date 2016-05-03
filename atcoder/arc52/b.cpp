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
    ll n, q; cin >> n >> q;
    vector<ld> x(n), r(n), h(n);
    rep(i, n) cin >> x[i] >> r[i] >> h[i];
    rep(i, q) { 
        ld a, b; cin >> a >> b;
        ld ret = 0;
        rep(i, n) {
            ld ah = (ld) (h[i] - (a - x[i])) * r[i] / h[i];
            ld bh = (ld) (h[i] - (b - x[i])) * r[i] / h[i];
            ah = min(ah, (ld)r[i]);
            bh = min(bh, (ld)r[i]);
            ah = max(ah, (ld)0);
            bh = max(bh, (ld)0);
            ld hd = h[i] * (ah-bh) / r[i];

            ret += M_PI / 3 * (ah*ah+ah*bh+bh*bh) * hd;
        }
        printf("%.40Lf\n", ret);
    }

    return 0;
}
