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
#define MAX_N 100005

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;

    vll x(n);
    map<ll, int> xinv; 
    rep(i, n) { 
        cin >> x[i];
        xinv[x[i]] = i + 1;
    }
    priority_queue<ll> q;
    rep(i, k) 
        q.push(x[i]);

    cout << xinv[q.top()] << endl;
    for (int i = k; i < n; i++) {
        if (x[i] < q.top()) {
            q.pop(), q.push(x[i]);
        }

        cout << xinv[q.top()] << endl;
    }


    return 0;
}
