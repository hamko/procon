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
    vll ret(6, 0);
    rep(i, n) {
        double a_, b_; cin >> a_ >> b_;
        ll a = round(a_*10), b = round(b_*10);
        if (a > b) swap(a, b); // a < bにする
        if (b >= 350) ret[0]++;
        if (b >= 300 && b < 350) ret[1]++;
        if (b >= 250 && b < 300) ret[2]++;
        if (a >= 250) ret[3]++;
        if (a < 0 && b >= 0) ret[4]++;
        if (b < 0) ret[5]++;
    }
    rep(i, 6) 
        cout << ret[i] << " ";
    cout << endl;

    return 0;
}
