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

typedef double Double;

int main(void) {
    int m; scanf("%d", &m);
    Double maxerr = -INF;
    rep(i, m) {
        int a, b; scanf("%d%d", &a, &b);
        Double t; scanf("%lf", &t);
//        cout << a << " " << b << " " << t << endl;
        if (!a) {
//            cout << "a=0" << endl;
            printf("%.12f\n", exp(pow(t, 1.0 / b)));
            continue;
        }
        if (!b) {
//            cout << "b=0" << endl;
            printf("%.12f\n", pow(t, 1.0 / a));
            continue;
        }

        Double rl = 1e-12;
        Double rr = 11;
        Double prev_m = 100;
        rep(i, 50) { 
            Double m = (rl + rr) / 2;
            if (abs(prev_m - m) < 1e-10) break;
            (pow(m, a) * pow(log(m), b) - t > 0) ? rr = m : rl = m;
            prev_m = m;
        }
        Double n = rl;
        printf("%.10f\n", n);

//        Double err = pow(n, a) * pow(log(n), b) -  t;
//        cout << err << endl;
    }

    return 0;
}

