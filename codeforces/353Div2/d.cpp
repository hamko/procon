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
    vll a(n); rep(i, a.size()) cin >> a[i];

    map<ll, ll> memo;
    map<ll, ll> m;
    map<ll, ll, greater<ll>> M;
    M[a[0]] = a[0];
    m[a[0]] = a[0];
    for (int i = 1; i < n; i++) {
        auto l = m.upper_bound(a[i]);
        auto r = M.upper_bound(a[i]);

        if (r != M.end()) {
            memo[a[i]] = r->second;
            M.erase(r);
        } else {
            memo[a[i]] = l->second;
            m.erase(l);
        }
        M[a[i]] = a[i];
        m[a[i]] = a[i];
    }

    for (int i = 1; i < n; i++) {
        if (i != 1)  cout << " ";
        cout << memo[a[i]];
    }
    cout << endl;

    return 0;
}