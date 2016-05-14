#include <bits/stdc++.h>
using namespace std;

#define int long long
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

signed main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n, x; cin >> n >> x;
    vi x0, x1;
    rep(i, n) {
        int tmp; cin >> tmp;
        if (i < n/2) 
            x0.pb(tmp);
        else
            x1.pb(tmp);
    }

    map<int, int> c0, c1;
    auto f = [](vi& v, map<int, int>& c){
        rep(mask, 1 << v.size()) {
            int tmp = 0;
            rep(i, v.size()) {
                if (mask & (1 << i)) {
                    tmp += v[i];
                }
            }
            c[tmp]++;
        }
    };
    f(x0, c0);
    f(x1, c1);

    int ret = 0;
    for (auto c : c0) {
        if (c1.find(x - c.first) == c1.end())
            continue;
        ret += c.second * c1[x - c.first];
    }
    cout << ret << endl;

    return 0;
}
