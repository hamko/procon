#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

typedef pair<double, double> P;
P intersect(P a, P b) { return P(max(a.first, b.first), min(a.second, b.second)); }

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll a, b, n; cin >> a >> b >> n;
    if (a > b) swap(a, b);
    double ba = atan2(b, a); // atan(6/1)
    double ab = atan2(a, b); // atan(1/6)
    double q = sqrt(a*a+b*b);
    rep(i, n) {
        double c, d; cin >> c >> d;
        if (c > d) swap(c, d);
        double cq = asin((double)c/q);
        double dq = asin((double)d/q);
        if (a <= c && b <= d) 
            cout << "YES" << endl;
        else if (asin(cq)-ba < (M_PI - asin(dq)) - ab) {
            cout << cq << " " << dq << " " << ab << " " << ba << endl;
            cout << "YES" << endl;
        } else 
            cout << "NO" << endl;
    }
    return 0;
}
