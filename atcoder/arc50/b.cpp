#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<ll, ll> P;
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
static const long long INF = 2e18;

// [a/b]_l 下ガウス記号。要するに普通のガウス記号。
// a/bが下ガウス記号なのはa, bが同符号またはaが0の時だけ。
ll lgauss(ll a, ll b) { 
    if (!a) return 0;
    if (a>0^b>0) 
        return (a+(a>0?-1:1))/b-1;
    else
        return a/b;
    
}

// [a/b]_u 上ガウス記号
ll ugauss(ll a, ll b) { 
    if (!a) return 0;
    if (a>0^b>0) 
        return a/b;
    else
        return (a+(a>0?-1:1))/b+1;
    
}

// a*x >= b
// 閉区間なので注意！
P AXgeqB(ll a, ll b) {
    if (a == 0) 
        return (0 >= b ? P(-INF, INF) : P(INF, -INF));
    else if (a > 0) 
        return P(ugauss(b, a), INF);
    else
        return P(-INF, lgauss(b, a));
}
// a*x <= b
P AXleqB(ll a, ll b) { return AXgeqB(-a, -b); }
// 数直線のマージ。second-first<0で解なし。
P intersect(P a, P b) { return P(max(a.first, b.first), min(a.second, b.second)); }

ll r, b, x, y;
bool check(ll t)
{
    if (t < 0) return false;

    P bmin = AXgeqB(1, 0);
//    P s = AXgeqB(x - 1, t * x - r);
//    P s = AXgeqB(x - 1, t * x - r);
    P s = P(ceill(((ld)t * (ld)x - (ld)r) / ((ld)x - (ld)1) - (ld)1e-14), INF);
    P p = AXleqB(y - 1, b - t);
    P u = AXleqB(1, t);
    P m = intersect(s, intersect(p, intersect(u, bmin)));
//    cout << t << " " << s << " " << p << " " << u << ":" <<m<< endl;

    return m.first <= m.second;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> r >> b >> x >> y;
    /*
    while (1) {
        ll t; cin >> t; 
        cout << check(t) << endl;
    }
    */
    ll lo = 0, ro = (ll)INF;
    while (ro - lo != 1) {
        ll mid = (ro + lo) / 2;
        if (!check(mid))
            ro = mid;
        else 
            lo = mid;
    }
    cout << lo << endl;

    return 0;
}
