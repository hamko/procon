#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
#undef M_PI
#define M_PI (acos(-1))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    double d, h, v, e; cin >> d >> h >> v >> e;
    double t = d * d / 4 * M_PI * h;
    if (4 * v / (d * d * M_PI) <= e)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        printf("%.40lf\n", h / (4 * v / (d * d * M_PI) - e));
    }


    return 0;
}
