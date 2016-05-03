#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using P = pair<ll, ll>;
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
static const long long INF = 1e18;

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
P AXgB(ll a, ll b) {
    if (a == 0) 
        return (0 > b ? P(-INF, INF) : P(INF, -INF));
    else if (a > 0) 
        return P(lgauss(b, a) + 1, INF);
    else
        return P(-INF, ugauss(b, a) - 1);
}
// a*x <= b
P AXleqB(ll a, ll b) { return AXgeqB(-a, -b); }
P AXlB(ll a, ll b) { return AXgB(-a, -b); }
// 数直線のマージ。second-first<0で解なし。
P intersect(P a, P b) { return P(max(a.first, b.first), min(a.second, b.second)); }

int main(void) {
    // 演算"a/b"は、a,bが同符号の時下ガウス記号, a,bがいふ号の時上ガウス記号。
    cout << (3 / 2) << endl;
    cout << (-3 / 2) << endl;
    cout << (-3 / -2) << endl;
    cout << (3 / -2) << endl;
    
    // 上ガウス記号
    cout << "ugauss" << endl;
    cout << ugauss(3, 2) << endl;
    cout << ugauss(-3, 2) << endl;
    cout << ugauss(3, -2) << endl;
    cout << ugauss(-3, -2) << endl;
    cout << ugauss(4, 2) << endl;
    cout << ugauss(-4, 2) << endl;
    cout << ugauss(4, -2) << endl;
    cout << ugauss(-4, -2) << endl;
    cout << ugauss(0, 2) << endl;
    cout << ugauss(0, -2) << endl;

    // 下ガウス記号
    cout << "lgauss" << endl;
    cout << lgauss(3, 2) << endl;
    cout << lgauss(-3, 2) << endl;
    cout << lgauss(3, -2) << endl;
    cout << lgauss(-3, -2) << endl;
    cout << lgauss(4, 2) << endl;
    cout << lgauss(-4, 2) << endl;
    cout << lgauss(4, -2) << endl;
    cout << lgauss(-4, -2) << endl;
    cout << lgauss(0, 2) << endl;
    cout << lgauss(0, -2) << endl;

    // 数直線
    cout << AXgeqB(2, 3) << endl;
    cout << AXgeqB(2, -3) << endl;
    cout << AXgeqB(-2, 3) << endl;
    cout << AXgeqB(-2, -3) << endl;
    cout << AXgeqB(2, 4) << endl;
    cout << AXgeqB(2, -4) << endl;
    cout << AXgeqB(-2, 4) << endl;
    cout << AXgeqB(-2, -4) << endl;

    cout << AXgB(2, 3) << endl;
    cout << AXgB(2, -3) << endl;
    cout << AXgB(-2, 3) << endl;
    cout << AXgB(-2, -3) << endl;
    cout << AXgB(2, 4) << endl;
    cout << AXgB(2, -4) << endl;
    cout << AXgB(-2, 4) << endl;
    cout << AXgB(-2, -4) << endl;


    return 0;
}
