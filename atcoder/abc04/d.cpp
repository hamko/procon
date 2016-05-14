#include <bits/stdc++.h>
using namespace std;

#define int long long
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

#define f(x) ((x)*(x+1)/2)

// [s, e]とxの距離
int dist(int x, int s, int e) {
    if (s <= x && x <= e) {
        return f(x-s)+f(e-x);
    } else if (s > x) {
        return f(e-x)-f(s-x-1);
    } else {
        return f(x-s)-f(x-e-1);
    }
}
signed main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int r, g, b; cin >> r >> g >> b;
    int ret = INF;
    int gsize = 300;
    int brsize = 300;
    for (int gi = -gsize; gi <= gsize; gi++) {
//        cout << gi << endl;
        // [gi, gi+g-1]
        for (int bi = gi+g; bi <= gi+g+brsize; bi++) {
            // [bi, bi+b-1]
            for (int ri = gi-r; ri >= gi-r-brsize; ri--) {
                // [ri, ri+r-1]
                int tmp = 0;
                tmp += dist(0, gi, gi+g-1);
                tmp += dist(+100, bi, bi+b-1);
                tmp += dist(-100, ri, ri+r-1);
                chmin(ret, tmp);
            }
        }
    }
    cout << ret << endl;
    return 0;
}
