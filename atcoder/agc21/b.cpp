#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)

// L: Line, S: Segment, P: Point, C: Circle
typedef double number;
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


int main(void) {
    ll n; cin >> n;
    vector<point> ps;
    map<point, ll> id;
    rep(i, n) {
        ll x, y; cin >> x >> y;
        ps.pb(point(x, y));
        id[point(x, y)] = i;
    }
    vector<point> ch = convex_hull(ps);
    double cx = 0, cy = 0;
    for (auto x : ch) {
        cx += real(x);
        cy += imag(x);
//        cout << real(x) << " " << imag(x) << endl;;
    }
    cx /= ch.size();
    cy /= ch.size();

    vector<vector<double>> angles;
//    cout << cx << " " << cy << "#c"<<endl;
    for (point p : ch) {
        double x = real(p) - cx;
        double y = imag(p) - cy;
        angles.pb({atan2(y, x), x+cx, y+cy, (double)id[p]});
    }
    sort(all(angles));
//    cout << angles << endl;
    vector<vector<double>> theta;
    rep(i, angles.size()) {
        double px = angles[(i+1)%angles.size()][1] - angles[i][1];
        double py = angles[(i+1)%angles.size()][2] - angles[i][2];
        theta.pb({atan2(-px, py)*360/2/M_PI, angles[i][3]});
    }
//    cout << theta << endl;

    double s = 360;
    vector<double> ret(n);
    rep(i, theta.size()) {
        double now = theta[i][0];
        double prev = theta[(theta.size()+i-1)%theta.size()][0];
        double dtheta = now - prev;
        if (prev > now) {
            dtheta = 360.+now-prev;
        }
        double tmp = dtheta/ s;
        while (dtheta > 360) dtheta -= 360;
        while (dtheta < 0) dtheta += 360;
        ret[theta[i][1]] = tmp;
    }
    rep(i, n) {
        cout <<ldout<< ret[i] << endl;
    }

    return 0;
}
