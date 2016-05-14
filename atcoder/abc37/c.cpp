#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        a[i] = x;
    }
    for (ll i = 1; i <= n; i++) {
        a[i] = a[i] + a[i-1];
    }
//    cout << a << endl;

    ll ret = 0;
    rep(i, n-k+1) {
        if (i){
            ret += a[i+k] - a[i];
//            cerr << a[i+k] - a[i] << endl;
        }else{
//            cerr << a[k] << endl;
            ret += a[k];
        }

    }
    cout << ret << endl;


    return 0;
}
