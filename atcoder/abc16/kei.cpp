#include <bits/stdc++.h>

using namespace std;

#define bitcount(n) __builtin_popcount(n)

#define debug(n) cout << (n) << endl;

#define PREC(n) setprecision(n)
#define DOTPREC(n) fixed << setprecision(n)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define rep(i,x) for(int i=0;i<(x);++i)
#define rep1(i,x) for(int i=1;i<=(x);++i)
#define rrep(i,x) for(int i=(x)-1;i>=0;--i)
#define rrep1(i,x) for(int i=(x);i>=1;--i)
#define FOR(i,a,x) for(int i=(a);i<(x);++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define omajinai ios::sync_with_stdio(false); cin.tie(0)

template<typename T> bool chmax(T&a,T b) { if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T&a,T b) { if(a > b) {a = b; return true;} return false;}

const int inf = 1e9;
const ll linf = 3e18;
const double eps = 1e-9;

const ll MOD = 1000000007;

bool intersect(vector<double> &A, vector<double> &B, vector<double> &C, vector<double> &D) {
    if (((A[0] - B[0]) * (C[1] - A[1]) + (A[1] - B[1]) * (A[0] - C[0])) *
            ((A[0] - B[0]) * (D[1] - A[1]) + (A[1] - B[1]) * (A[0] - D[0])) < 0) {
        if (((C[0] - D[0]) * (A[1] - C[1]) + (C[1] - D[1]) * (C[0] - A[0])) *
                ((C[0] - D[0]) * (B[1] - C[1]) + (C[1] - D[1]) * (C[0] - B[0])) < 0) {
            return 1;
        } else {return 0;}
    } else {
        return 0;
    }
}

// L: Line, S: Segment, P: Point, C: Circle
typedef double number;
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> point;
namespace std { bool operator < (const point& a, const point& b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); } }
double cross(const point& a, const point& b) { return imag(conj(a)*b); }
double dot(const point& a, const point& b) { return real(conj(a)*b); }
struct line : public vector<point> { line(const point &a, const point &b) { push_back(a); push_back(b); } };
typedef vector<point> polygon;
struct C { point p; double r; C(const point &p, double r) : p(p), r(r) { } }; 
int ccw(point a, point b, point c) { b -= a; c -= a; if (cross(b, c) > 0) return +1/*ccw*/; if (cross(b, c) < 0) return -1/*cw*/; if (dot(b, c) < 0) return +2/*c-a-b on line*/; if (norm(b) < norm(c)) return -2/*a-b-c on line*/; return 0; }
bool intersectLL(const line &l, const line &m) { return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS /*non-parallel*/ || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS /*same line*/; }
bool intersectLS(const line &l, const line &s) { return cross(l[1]-l[0], s[0]-l[0])/*s[0] is left of l*/* cross(l[1]-l[0], s[1]-l[0])/*s[1] is right of l*/ < EPS; }
bool intersectLpoint(const line &l, const point &p) { return abs(cross(l[1]-p, l[0]-p)) < EPS; }
bool intersectSS(const line &s, const line &t) { return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0; }
bool intersectSpoint(const line &s, const point &p) { return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; /* triangle inequality */ }
point projection(const line &l, const point &p) { double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]); return l[0] + t*(l[0]-l[1]); }
point reflection(const line &l, const point &p) { return p + (point)2 * (projection(l, p) - p); }
double distanceLpoint(const line &l, const point &p) { return abs(p - projection(l, p)); }
double distanceLL(const line &l, const line &m) { return intersectLL(l, m) ? 0 : distanceLpoint(l, m[0]); }
double distanceLS(const line &l, const line &s) { if (intersectLS(l, s)) return 0; return min(distanceLpoint(l, s[0]), distanceLpoint(l, s[1])); }
double distanceSpoint(const line &s, const point &p) { const point r = projection(s, p); if (intersectSpoint(s, r)) return abs(r - p); return min(abs(s[0] - p), abs(s[1] - p)); }
double distanceSS(const line &s, const line &t) { if (intersectSS(s, t)) return 0; return min(min(distanceSpoint(s, t[0]), distanceSpoint(s, t[1])), min(distanceSpoint(t, s[0]), distanceSpoint(t, s[1]))); }
point crosspoint(const line &l, const line &m) { double A = cross(l[1] - l[0], m[1] - m[0]); double B = cross(l[1] - l[0], l[1] - m[0]); if (abs(A) < EPS && abs(B) < EPS) return m[0]; /* same line*/ if (abs(A) < EPS) assert(false); return m[0] + B / A * (m[1] - m[0]); }
#define d(k) (dot(p[k], l[1] - l[0]))
point extreme(const vector<point> &p, const line &l) { int k = 0; for (int i = 1; i < p.size(); ++i) if (d(i) > d(k)) k = i; return p[k]; }
#define prev(P, i) P[(i-1+P.size())%P.size()]
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const polygon& P, const point& p) { bool in = false; for (int i = 0; i < P.size(); ++i) { point a = curr(P,i) - p, b = next(P,i) - p; if (imag(a) > imag(b)) swap(a, b); if (imag(a) <= 0 && 0 < imag(b)) if (cross(a, b) < 0) in = !in; if (cross(a, b) == 0 && dot(a, b) <= 0) return ON; } return in ? IN : OUT; }
number area2(const polygon& P) { number A = 0; for (int i = 0; i < P.size(); ++i) A += cross(curr(P, i), next(P, i)); return A; }
polygon shrink_polygon(const polygon &P, number len) { polygon res; for (int i = 0; i < P.size(); ++i) { point a = prev(P,i), b = curr(P,i), c = next(P,i); point u = (b - a) / abs(b - a); double th = arg((c - b)/ u) * 0.5; res.push_back( b + u * point(-sin(th), cos(th)) * len / cos(th) ); } return res; }
vector<point> convex_hull(vector<point> ps) { int n = ps.size(), k = 0; sort(ps.begin(), ps.end()); vector<point> ch(2*n); for (int i = 0; i < n; ch[k++] = ps[i++]) /* lower-hull */ while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k; for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) /* upper-hull */ while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k; ch.resize(k-1); return ch; } // O(n log n)
bool isconvex(const polygon &P) { for (int i = 0; i < P.size(); ++i) if (ccw(prev(P, i), curr(P, i), next(P, i)) > 0) return false; return true; } // O(n)
polygon convex_cut(const polygon& P, const line& l) { polygon Q; for (int i = 0; i < P.size(); ++i) { point A = curr(P, i), B = next(P, i); if (ccw(l[0], l[1], A) != -1) Q.push_back(A); if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0) Q.push_back(crosspoint(line(A, B), l)); } return Q; } // O(n), 凸多角形をある直線で切断し，その左側だけ残す．


int main() {

    vd A = {1.0, 0}; vd B = {-1.0, 0};
    vd C = {0, 2}; 

    point a = point(1, 0), b = point(-1, 0);
    line Segment1(a, b);
    point c = point(0, 2);

    int n = 10;
    for (double x = -n; x < n; x++) for (double y = -n; y < n; y++) {
        vd D = {x, y};
        bool kei = intersect(A, B, C, D);

        point d = point(x, y);
        line Segment2(c, d);
        bool hamko = intersectSS(Segment1, Segment2);

        if (kei != hamko) {
            cout << x << " " << y << " : " << kei << " " << hamko << endl;
        }
    }

    return 0;
}
