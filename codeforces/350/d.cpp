#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define push_back pb
#define all(x) x.begin(), x.end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005


ll n, k;
vll a, b;
bool check(ll p)
{
    vll c = a;
    rep(i, n) c[i] *= p;
//    cout << c << endl;

    ll l = k;
    rep(i, n) {
        l -= max((ll)0, c[i] - b[i]);
        if (l < 0) 
            return true;
    }
    return l < 0;
}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n), b.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    // デバッグはここでチェック関数を確認するといい
    /*
    while (1) {
        ll t; cin >> t; 
        cout << check(t) << endl;
    }
    */

    ll lo = 0, ro = (ll)2e9+100;
    while (ro - lo != 1) { 
        ll mid = (lo + ro) / 2; 
        // check関数が単純ならここに書いてもいいが、デバッグしにくくなるので関数は分けるべき
        check(mid)?ro=mid:lo=mid; 
    }
    cout << lo << endl;

    return 0;
}
