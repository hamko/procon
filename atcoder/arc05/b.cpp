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

ll si, sj; 
string d;
ll di, dj;
vector<string> m;
map<P, ll> memo;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> sj >> si; sj--; si--;

    cin >> d;
    rep(i, d.length()) {
        if (d[i] == 'L') dj = -1;
        if (d[i] == 'R') dj = 1;
        if (d[i] == 'U') di = -1;
        if (d[i] == 'D') di = 1;
    }

    m.resize(9); rep(i, 9) cin >> m[i];

    rep(i, 4) {
        if (si+di>=9) di*=-1;
        if (si+di<0) di*=-1;
        if (sj+dj>=9) dj*=-1;
        if (sj+dj<0) dj*=-1;
        cout << m[si][sj];
        si+=di;
        sj+=dj;
    }
    cout << endl;

    return 0;
}
