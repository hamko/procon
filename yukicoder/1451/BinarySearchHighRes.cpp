#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long;  using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

typedef long double Double;

int main(void) {
    int m; scanf("%d", &m);
    rep(i, m) {
        int a, b; scanf("%d%d", &a, &b);
        Double t; scanf("%Lf", &t);
        if (!a) {
            printf("%.12Lf\n", expl(powl(t, 1.0l / b)));
            continue;
        }
        if (!b) {
            printf("%.12Lf\n", powl(t, 1.0l / a));
            continue;
        }

        Double rl = 1e-12;
        Double rr = 11;
        rep(i, 100) { 
            Double m = (rl + rr) / 2.0l;
            (powl(m, a) * powl(log(m), b) - t > 0.0l) ? rr = m : rl = m;
        }
        Double n = rl;
        printf("%.12Lf\n", n);
    }

    return 0;
}

