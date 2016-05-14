#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

ld distance(ld x, ld y) {
    return sqrtl(x*x+y*y);
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ld ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    ll n; cin >> n;
    vector<ld> x(n), y(n); rep(i, n) cin >> x[i] >> y[i];
    if (n == 1) {
        cout << setprecision(40) << distance(tx-x[0], ty-y[0]) + min<ld>(distance(ax-x[0], ay-y[0]), distance(bx-x[0], by-y[0])) << endl;;
//        printf("%.40Lf\n", distance(tx-x[0], ty-y[0]) + min<ld>(distance(ax-x[0], ay-y[0]), distance(bx-x[0], by-y[0])));
        return 0;
    }

    // minus is better
    vector<pair<ld, ll>> ad(n), bd(n);
    rep(i, n) {
        ad[i].first = distance(ax-x[i], ay-y[i]) - distance(tx-x[i], ty-y[i]);
        ad[i].second = i;
        bd[i].first = distance(bx-x[i], by-y[i]) - distance(tx-x[i], ty-y[i]);
        bd[i].second = i;
    }
    sort(all(ad)); sort(all(bd));

    ld ret = 0;
    rep(i, n) {
        ret += 2.0l * distance(tx-x[i], ty-y[i]);
    }

    if (ad[0].first < 0 && bd[0].first < 0) {
        if (ad[0].second != bd[0].second) {
            ret += ad[0].first;
            ret += bd[0].first;
        } else {
            ld d = min(
                    ad[0].first + min<ld>(0, bd[1].first),
                    bd[0].first + min<ld>(0, ad[1].first));
            ret += d;
        }
    } else {
        ret += min<ld>(ad[0].first, bd[0].first);
    }
    cout << setprecision(40) << ret << endl;
//    printf("%.40Lf\n", ret);
    return 0;
}
