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

    int n, m, d; cin >> n >> m >> d;
    vi a(m); rep(i, m) { cin >> a[i]; a[i]--; }

    vi c(n); rep(i, n) c[i] = i;
    rep(i, m) swap(c[a[i]], c[a[i+1]]);

    // カラー毎にvectorに突っ込んで検索が必要だったかな…間に合わなそうだったらそうしよう
    vi done(n, -1);
    int color = 0;
    while (1) {
        int index;
        for (index = 0; index < n; index++) 
            if (done[index] == -1) 
                break;
        if (index == n)
            break;
     
        rep(i, n) {
            done[index] = color;
            index = c[index];
        }
        color++;
    }

    vi count(color, 0);
    rep(i, n) {
        count[done[i]]++;
    }

    rep(i, n) {
        int r = d % count[done[i]]; 
        int index = i;
        rep(j, r) index = c[index];
        cout << index + 1 << endl;
    }

    return 0;
}
