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
    ll n; cin >> n;
    vll a(n); rep(i, n) { cin >> a[i]; }
    vll b(n, 0); b[0] = a[0]; rep(i, n-1) { b[i+1] = b[i] + a[i+1]; }

    ll sum = 0;
    ll maxi = 0;
    rep(i, n) {
        sum += a[i];
        maxi = max(maxi, a[i]);
    }
    cout << sum << endl;

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    cout << max((ll)0, maxi - (sum - maxi)) << endl;


    return 0;
}
