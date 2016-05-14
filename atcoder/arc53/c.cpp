#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vld = vector<ld>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<P> a(n); rep(i, a.size()) { 
        ll x, y; cin >> x >> y;
        a[i].first = x;
        a[i].second = x - y;
    }

    vector<P> aneg, apos;
    rep(i, a.size()) 
        (a[i].second < 0 ? aneg : apos).pb(a[i]);

    sort(all(aneg));
    ll y = 0, ym = 0; 
    rep(i, aneg.size()) {
        chmax(ym, y + aneg[i].first);
        y += aneg[i].second;
    }

    sort(all(apos), greater<P>());
    rep(i, apos.size()) {
        chmax(ym, y + apos[i].first);
        y += apos[i].second;
    }

    cout << ym << endl;


    return 0;
}
