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
#define MOD ((ll)(1e9+7))

ll m[1010][1010];
ll c[1010][1010];
vector<pair<ll, P>> indice;
int main(void) {
    ll ni, nj; cin >> ni >> nj;

    rep(i, ni) rep(j, nj) {
        cin >> m[i][j];
        indice.pb(make_pair(m[i][j], P(i, j)));
        c[i][j] = 1;
    }
    sort(all(indice));


    for (auto x : indice) {
        int num = x.first;
        int i = x.second.first;
        int j = x.second.second;
        ll di[4] = {1, -1, 0, 0};
        ll dj[4] = {0, 0, 1, -1};
        rep(d, 4) {
            int tmpi = i + di[d];
            int tmpj = j + dj[d];
            if (tmpi < 0 || tmpi >= ni || tmpj < 0 || tmpj >= nj) 
                continue;
            if (m[i][j] > m[tmpi][tmpj])
                (c[i][j] += c[tmpi][tmpj]) %= MOD;
        }
    }

    ll ret = 0;
    rep(i, ni) rep(j, nj) {
        (ret += c[i][j]) %= MOD;
    }
    cout << ret << endl;


    return 0;
}
