#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

// L: Line, S: Segment, P: Point, C: Circle
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std { bool operator < (const P& a, const P& b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); } }
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
struct L : public vector<P> { L(const P &a, const P &b) { push_back(a); push_back(b); } };
int ccw(P a, P b, P c) { b -= a; c -= a; if (cross(b, c) > 0) return +1/*ccw*/; if (cross(b, c) < 0) return -1/*cw*/; if (dot(b, c) < 0) return +2/*c-a-b on line*/; if (norm(b) < norm(c)) return -2/*a-b-c on line*/; return 0; }
bool intersectSS(const L &s, const L &t) { return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0; }

int main(void) {
    double ax, ay, bx, by; cin >> ax >> ay >> bx >> by; L line(P(ax, ay), P(bx, by));

    int n; cin >> n;
    int count = 0;
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    rep(i, n) {
        L edge(P(x[i], y[i]), P(x[(i+1)%n], y[(i+1)%n]));
        if (intersectSS(line, edge))
            count++;
    }

    cout << 1 + (count + 1) / 2 << endl;
        
    return 0;
}
