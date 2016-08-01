#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

struct verticle {
    double theta;
    ll x, y;
    bitset<4> pattern;
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll hn, wn; cin >> hn >> wn;
    vector<string> b(hn); rep(i, hn) cin >> b[i]; reverse(all(b));

    vector<verticle> vs;
    rep(h, hn+1) rep(w, wn+1) if (h || w) {
        verticle v;
        v.x = h;
        v.y = w;
        v.theta = atan2(h, w);

        // 10 
        // 23
        auto f = [&](ll h, ll w){ return h >= 0 && w >= 0 && h < hn && w < wn; };
        v.pattern[2] = f(h, w-1) && b[h][w-1] == '#';
        v.pattern[0] = f(h-1, w) && b[h-1][w] == '#';
        v.pattern[1] = f(h-1, w-1) && b[h-1][w-1] == '#';
        v.pattern[3] = f(h, w) && b[h][w] == '#'; 
        vs.pb(v);
    }
    sort(all(vs), [](const verticle& a, const verticle& b){ return a.theta < b.theta; });

    ll ret = 0;
    ll cut = 0;
    ll i = 0;
    while (i < vs.size()) {
        double th = vs[i].theta;
        vector<verticle> p;
        while (i < vs.size() && vs[i].theta < th + EPS) {
            p.pb(vs[i]);
            i++;
        }

        rep(j, p.size()) {
            // +1
            if (!p[j].pattern[0] && !p[j].pattern[1] && p[j].pattern[2] && !p[j].pattern[3]) cut++;
            if (p[j].pattern[0] && p[j].pattern[1] && !p[j].pattern[2] && p[j].pattern[3]) cut++;
            // -1
            if (p[j].pattern[0] && !p[j].pattern[1] && !p[j].pattern[2] && !p[j].pattern[3]) cut--;
            if (!p[j].pattern[0] && p[j].pattern[1] && p[j].pattern[2] && p[j].pattern[3]) cut--;
        }
        chmax(ret, cut); 
    }
    cout << ret + 1 << endl;
    return 0;
}
