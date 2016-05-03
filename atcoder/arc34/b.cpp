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
#define MAX_N 10

int f(ll x) {
    int ret = 0;
    while(x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;

    /*
    vll b(MAX_N);
    rep(i, MAX_N) b[i] = (ll)pow(10, i) + 1;

    ll m = 0; ll tmp = n; while(tmp) {tmp/=10;m++;}
    vll cand = {m - 2, m - 1};
    vll rets;
    for (auto x : cand) {
        ll tmp = n;
        ll ret = 0;
        for (int i = x; i >= 0; i--) {
            ret += (tmp / b[i]) * (ll)pow(10, i);
            tmp %= b[i];
        }
        if (!tmp)
            rets.push_back(ret);
    }

    cout << rets.size() << endl;
    rep(i, rets.size()) {
        cout << rets[i] << endl;
    }
    */


    vll q;
    for (ll cand = n - 155; cand <= n; cand++) {
        if (cand + f(cand) == n) {
            q.push_back(cand);
        }
    }
    cout << q.size() << endl;
    rep(i, q.size()) {
        cout << q[i] << endl;
    }


    
    return 0;
}
