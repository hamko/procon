#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 1000

// [a/b]_u 上ガウス記号
ll ugauss(ll a, ll b) { 
    if (!a) return 0;
    if (a>0^b>0) 
        return a/b;
    else
        return (a+(a>0?-1:1))/b+1;
    
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll _; cin >> _ >> _;
    string s, t; cin >> s >> t;
    vll sc(MAX_N, 0), tc(MAX_N, 0);
    rep(i, s.length()) { sc[s[i]]++; }
    rep(i, t.length()) { tc[t[i]]++; }
    ll ret = 0;
    rep(i, MAX_N) {
        if (!sc[i])
            continue;
        if (!tc[i]) {
            cout << -1 << endl;
            return 0;
        }
        ret = max(ret, ugauss(sc[i], tc[i]));
    }
    cout << ret << endl;

    return 0;
}
