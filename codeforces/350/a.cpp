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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    if (n == 1) {
        cout << 0 << " " << 1 << endl;
        return 0;
    }

    int c, r;


    // min
    c = n / 7; r = n % 7;
    cout << 2 * c + min(2, max(r - 5, 0)) << " ";

    // max
    c = (n - 2) / 7; r = (n - 2) % 7;
    cout << 2 + 2 * c + min(2, max(r - 5, 0)) << endl;
    return 0;
}
