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
static const long long mo = 1e9+7;
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll hn, wn, n; cin >> hn >> wn >> n;
    vll h(n), w(n), x(n); rep(i, n) cin >> h[i] >> w[i] >> x[i];
    bool m[hn][wn]; rep(i, hn) rep(j, wn) m[i][j] = false;

    rep(i, n) {
        int j;
        for (j = hn - h[i]; j >= 0; j--) {
            bool tef = 0;
            for (int k = x[i]; k < x[i] + w[i]; k++) {
                if (m[j][k])
                    tef = 1;
            }
            if (tef) 
                break;
        }
        j++;
        for (int l = j; l < j + h[i]; l++) {
            for (int k = x[i]; k < x[i] + w[i]; k++) {
                m[l][k] = true;
            }
        }

    }
    rep(i, hn) { 
        rep(j, wn) {
            cout << (m[hn-i-1][j] ? '#' : '.');
        }
        cout << endl;
    }

    return 0;
}
