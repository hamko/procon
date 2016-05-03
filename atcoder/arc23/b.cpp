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
    ll r, c, d; cin >> r >> c >> d;
    vector<vll> m(r, vll(c));
    // i r
    // j c
    rep(i, r) rep(j, c) { cin >> m[i][j]; }

    ll ret = 0;
    rep(i, r) rep(j, c) {
        if ((i + j) % 2 != d % 2 || i + j > d) 
            continue;
        ret = max(ret, m[i][j]);
    }
    cout << ret << endl;
    return 0;
}
