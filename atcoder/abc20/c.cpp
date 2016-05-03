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

ll h, w, t; 
ll si, sj, gi, gj;
vector<vector<char>> a;
vector<vector<ll>> s;
ll p;
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
bool is_in_range(ll i, ll j) {
    if (i < 0 || i >= h || j < 0 || j >= w) 
        return false;
    return true;
}
void rec(ll i, ll j) {
    rep(k, 4) {
        if (!is_in_range(i+di[k], j+dj[k])) 
            continue;
        ll cost = 1;
        if (a[i+di[k]][j+dj[k]] == '#')
            cost = p;
        if (s[i+di[k]][j+dj[k]] > s[i][j] + cost) {
            s[i+di[k]][j+dj[k]] = s[i][j] + cost;
            rec(i+di[k], j+dj[k]);
        }
    }
}

bool check(ll p_)
{
    p = p_;
    s = vector<vector<ll>>(h, vector<ll>(w, INF));
    s[si][sj] = 0;
    rec(si, sj);
    return s[gi][gj] <= t;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> h >> w >> t;
    a = vector<vector<char>> (h, vector<char>(w, '.'));
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        if (a[i][j] == 'S') 
            si = i, sj = j;
        if (a[i][j] == 'G') 
            gi = i, gj = j;
    }

    // デバッグはここでチェック関数を確認するといい
    /*
       while (1) {
        ll t; cin >> t; 
        cout << check(t) << endl;
    }
    */

    // 構造は11111000000なら、!check(mid)
    // lは最大の満たさない場所、rは最小の満たす場所。
    ll lo = 1, ro = (ll)4e18; // lが満たさないことを確認！
    while (ro - lo != 1) { 
        ll mid = (lo + ro) / 2; 
        !check(mid)?ro=mid:lo=mid; 
    }
    cout << lo << endl;

    return 0;
}
