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

vll a, b;
ll n, k;
bool check(ll p)
{
    ll sum = 0;
    rep(i, n) {
        sum += n - (ll)(lower_bound(all(b), p / a[i], greater<ll>()) - b.begin()); // OK?
//        cout << a[i] << " " << p / a[i] << " " <<  (ll)(lower_bound(all(b), p / a[i], greater<ll>()) - b.begin()) << endl;
    }
    return sum < k;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n >> k;
    a = vll(n), b = vll(n); 
    rep(i, n) cin >> a[i]; 
    rep(i, n) cin >> b[i]; 
    sort(all(a)); sort(all(b), greater<ll>());

    // デバッグはここでチェック関数を確認するといい
    /*
    while (1) {
        ll t; cin >> t; 
        cout << check(t) << endl;
    }
    */

    // 構造は11111000000なら、!check(mid)
    // lは最大の満たさない場所、rは最小の満たす場所。
    ll lo = 0, ro = (ll)4e18; // lが満たさないことを確認！
    while (ro - lo != 1) { 
        ll mid = (lo + ro) / 2; 
        !check(mid)?ro=mid:lo=mid; 
    }
    cout << ro << endl;

    return 0;
}
