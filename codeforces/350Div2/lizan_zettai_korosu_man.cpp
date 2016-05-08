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
    /*
       ll n; cin >> n;
       vll a(n); rep(i, n) { cin >> a[i]; a[i]--; }
       ll m; cin >> m;
       vll b(m); rep(i, m) { cin >> b[i]; b[i]--; }
       vll c(m); rep(i, m) { cin >> c[i]; c[i]--; }
       */
    ll n = 100000;
    vll a(n); rep(i, n) { a[i] = 107897 * (i * 1); }
    ll m = 1;
    vll b(m); b[0] = 1;
    vll c(m); c[0] = 2;

    unordered_map<ll, ll> acount;   
    acount.reserve(n);
    cout << acount.bucket_count() << endl;
    rep(i, n) acount[a[i]]++;

    vector<pair<P, ll>> bccount(m); rep(i, m) { bccount[i] = make_pair( P(acount[b[i]], acount[c[i]]), i); }
    sort(all(bccount), greater<pair<P, ll>>());

    cout << bccount[0].second + 1 << endl;


    return 0;
}


