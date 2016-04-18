#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

#define MAX_N 105


int n, a, b;
vector<vi> c;
vi u, v;

int ret(vector<vi>& c, int np) { 
    int m = 0;

    map<int, int> is_np; // 1でブロック
    rep(i, b) {
        if (np & 1) is_np[u[i]] = 1;
        np >>= 1;
    }

    rep(i, c.size()) {
        if (is_np[i]) {
            continue;
        }
        vi painted(c.size(), 0); painted[i] = 1;
        vi tmp_painted = painted;
        while (1) {
            rep(j, c.size()) rep(h, c.size()) {
                if (painted[j] && c[j][h] && !is_np[h]) {
                    tmp_painted[h] = 1;
                }
            }
            if (painted == tmp_painted) 
                break;
            painted = tmp_painted;
        }
        m = max(m, accumulate(all(painted), 0));
    }
    return m;
}

int main(void) {
    cin >> n >> a; 
    c = vector<vi>(n, vi(n, 0));
    rep(i, a) { int x, y; cin >> x >> y; x--; y--;  c[y][x] = 1; }
    cin >> b;
    u = vi(b), v = vi(b);
    rep(i, b) { int x, y; cin >> x >> y; x--; y--; u[i] = x; v[i] = y; }

    int m = 0;
    rep(i, n) rep(np, 1 << b) {
        vector<vi> c_tmp = c;
        rep(i, b) {
            if ((np & 1) == 0) {
                c_tmp[u[i]][v[i]] = 1;
            }
            np <<= 1;
        }
        rep(di, n) {rep(dj, n) {cout << c_tmp[di][dj] << "\t";} cout << endl;}
        int ans = ret(c_tmp, np);
        cout << ans << "#ans" << endl;
        m = max(m, ans);
    }
    cout << m << endl;

    return 0;
}
