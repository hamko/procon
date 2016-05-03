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

#define m(i,j) m_[i+1][j+1]
#define memo(i,j) memo_[i+1][j+1]
ll si, sj;
ll m_[12][12];
ll memo_[12][12];
ll count(ll i, ll j)
{
    if (!m(i, j) || ~memo(i, j)) return 0;
    memo(i, j) = 1;
    ll ret = 0;
    vll di = {0, 0, 1, -1}, dj = {1, -1, 0, 0};
    rep(d, 4) {
        ret += count(i+di[d], j+dj[d]);
    }
    return ret + 1;
}
void clear_memo(void)
{
    rep(i, 12) rep(j, 12) memo_[i][j] = -1;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll num = 0;
    rep(i, 10) {
        string s; cin >> s;
        rep(j, 10) {
            if (s[j] == 'o') {
                m(i, j) = 1;
                si = i; sj = j;
                num++;
            }
        }
    }
    rep(i, 10) rep(j, 10) {
        if (m(i, j) == 1) continue;
        m(i, j) = 1;
        clear_memo();
        if (count(si, sj) == num+1) {
            cout << "YES" << endl;
            return 0;
        }
        m(i, j) = 0;
    }
    cout << "NO" << endl;
    /*
    clear_memo();
    cout << m(si, sj) << " " << count(si, sj) << endl;
    */
    return 0;
}
