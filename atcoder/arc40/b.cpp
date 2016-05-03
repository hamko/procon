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
    ll n, r; string s; cin >> n >> r >> s;

    ll maxi = -1;
    rep(i, s.length()) { if (s[i] == '.') maxi = i; }
    if (maxi == -1) {
        cout << 0 << endl;
        return 0;
    }

    ll ret = 0;
    ll i = 0;
    while (1) {
        if (i > maxi - r) {
            ret++;
            cout << ret << endl;
            return 0;
        } else if (s[i] == '.') {
            ret++;
            rep(j, r) s[i+j] = 'o';
        } else {
            ret++;
            i++;
        }

    }
    return 0;
}
