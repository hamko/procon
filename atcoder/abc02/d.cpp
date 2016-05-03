#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    map<P, ll> memo;
    rep(i, m) {
        P tmp; cin >> tmp.first >> tmp.second; tmp.first--; tmp.second--;
        memo[tmp] = 1;
        swap(tmp.first, tmp.second); 
        memo[tmp] = 1;
    }

    ll ret = 0;
    rep(s, 1 << n) {
        rep(i, n) for (int j = i+1; j < n; j++) 
            if ((s & (1 << i)) && (s & (1 << j)) && !memo[P(i, j)]) 
                goto no;
        ret = max(ret, (ll)__builtin_popcount(s));
        no:;
    }

    cout << ret << endl;
    return 0;
}
