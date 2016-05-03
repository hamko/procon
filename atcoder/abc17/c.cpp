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
    vector<P> range(n); 
    vector<ll> score(n);
    rep(i, n) {
        cin >> range[i].first >> range[i].second >> score[i];
        range[i].first--; range[i].second--;
    }

    // かぶってないなら全部でOK
    vector<ll> imos(m+1);
    rep(i, n) {
        imos[range[i].first] += score[i];
        imos[range[i].second+1] -= score[i];
    }
    rep(i, m) 
        imos[i+1] += imos[i];

    cout << accumulate(all(score), (ll)0) - *min_element(begin(imos), end(imos)-1) << endl;

    return 0;
}
