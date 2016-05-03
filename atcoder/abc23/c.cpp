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
    ll r, c, k; cin >> r >> c >> k;
    ll n; cin >> n;
    vll x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i]; x[i]--; y[i]--;
    }

    vector<ll> xc(r), yc(c);
    rep(i, n) { xc[x[i]]++; yc[y[i]]++; }
    map<int, int> xcc, ycc;
    for (auto x_ : xc) { xcc[x_]++; }
    for (auto y_ : yc) { ycc[y_]++; }
    /*
    for (auto x_ : xc) { cout << x_ << " "; } cout << "xc" << endl;
    for (auto y_ : yc) { cout << y_ << " "; } cout << "yc"  << endl;
    for (auto x_ : xcc) { cout << x_ << " "; } cout << "xcc"  << endl;
    for (auto y_ : ycc) { cout << y_ << " "; } cout << "ycc"  << endl;
    */

    ll ret = 0;
    rep(i, k+1) {
    //    cout << xcc[i] << " " << ycc[k-i] << "#summing" << endl;;
        ret += xcc[i] * ycc[k-i];
    }
    //cout << ret << endl;

    rep(i, n) {
        if (xc[x[i]] + yc[y[i]] == k + 1) 
            ret++;
        if (xc[x[i]] + yc[y[i]] == k) 
            ret--;
    }
    cout << ret << endl;

    return 0;
}
