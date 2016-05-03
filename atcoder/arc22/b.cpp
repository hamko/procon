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

ll n;
vll a;
bool check(ll l) // l個切り出せるなら1
{
    if (l > n) return false;

    unordered_map<ll, int> s;
    rep(i, l) 
        s[a[i]]++;
    if (s.size() == l)
        return true;
    rep(i, n-l) {
        s[a[i]]--; if (!s[a[i]]) s.erase(a[i]);
        s[a[i+l]]++;
        if (s.size() == l)
            return true;
    }
    return false;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    n; cin >> n;
    a = vll(n); rep(i, n) cin >> a[i];

    // デバッグはここでチェック関数を確認するといい
    /*
    while (1) {
    ll t; cin >> t; 
    cout << check(t) << endl;
    }
    */

    // 構造は11111000000なら、!check(mid)
    // lは最大の満たさない場所、rは最小の満たす場所。
    ll lo = 1, ro = n+1; // lが満たさないことを確認！
    while (ro - lo != 1) { 
        ll mid = (lo + ro) / 2; 
        // check関数が単純ならここに書いてもいいが、デバッグしにくくなるので関数は分けるべき
        !check(mid)?ro=mid:lo=mid; 
    }
    cout << lo << endl;

    return 0;
}
