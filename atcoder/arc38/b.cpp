#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
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

ll ni, nj; 
vector<string> m;
map<P, ll> memo;
ll rec(ll i, ll j) {
    if (i < 0 || i >= ni || j < 0 || j >= nj || m[i][j] == '#') return 1;
    if (memo.count(P(i, j))) { return memo[P(i, j)]; }
    ll result = 0; // 勝ち1, 負け0
    if (!rec(i+1, j+1)) result = 1;
    if (!rec(i+0, j+1)) result = 1;
    if (!rec(i+1, j+0)) result = 1;

    return memo[P(i, j)] = result;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> ni >> nj;
    m.resize(ni); rep(i, ni) cin >> m[i];

    cout << (rec(0, 0) ? "First" : "Second") << endl;

    return 0;
}
