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

#define MAX_N 2005

map<P, ll> memo;
ll get_memo(int w, int h) {
    if (memo(P(w, h))) {
        return memo(P(w, h));
    }

    ll ret = 
    memo(P(w, h));

}

int W, H, Q;
vector<ll> a;
vector<ll> b;
int main(void) {
    cin >> W >> H;
    rep(i, W) { ll tmp; cin >> tmp; a.push_back(tmp); }
    rep(i, H) { ll tmp; cin >> tmp; b.push_back(tmp); }

    ll asum[MAX_N];
    rep(w, W) {
        asum[w] += a[w];
        if (w > 0) 
            asum[w] += asum[w-1];
    };
    ll table[MAX_N][MAX_N];
    rep(w, W) rep(h, H) {
        table[w][h] = w * b[h] + asum[w];
    }

    cin >> Q;
    rep(query, Q) {
        int w, h; cin >> w >> h;
        
    }

    return 0;
}
