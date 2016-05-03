#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; 

// L: Line, S: Segment, P: Point, C: Circle
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> point;
double dot(const point& a, const point& b) { return real(conj(a)*b); }
struct line : public vector<point> { line(const point &a, const point &b) { push_back(a); push_back(b); } };
bool intersectSpoint(const line &s, const point &p) { return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; /* triangle inequality */ }
point projection(const line &l, const point &p) { double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]); return l[0] + t*(l[0]-l[1]); }
double distanceSpoint(const line &s, const point &p) { const point r = projection(s, p); if (intersectSpoint(s, r)) return abs(r - p); return min(abs(s[0] - p), abs(s[1] - p)); }

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll x, y; cin >> x >> y; point takahashi(x, y);
    ll n; cin >> n;
    double ret = INF;

    vector<point> p(n);
    rep(i, n) {
        ll tmpx, tmpy; cin >> tmpx >> tmpy;
        p[i] = point(tmpx, tmpy);
    }
    rep(i, n) {
        line seg(p[i], p[(i+1)%n]);
        ret = min(ret, distanceSpoint(seg, takahashi));
    }
    printf("%.40lf\n", ret);
        

    return 0;
}
