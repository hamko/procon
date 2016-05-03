#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define print(v) for(auto x:(v)){cout<<x<<" ";}cout<<endl;
#define printi(b,e) for(auto x=(b); x!=(e); x++)cout<<*x<<" ";cout<<endl;
#define printa(a,n) rep(i,n)cout<<a[i]<<" ";cout<<endl;
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ld = long double; 
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

// nCk/2^n
ld f(int n, int k) {
    ld ret = 1;
    int n_ = n;
    rep(i, k) {
        ret *= ((ld)(n-i)/(ld)(i+1));
    }
    rep(j, n) {
        ret /= (ld)2;
    }
    return ret;
}

int main(void) {
    int n, d, x, y; cin >> n >> d >> x >> y;

    if (x % d != 0) { cout << 0 << endl; return 0; } x /= d;
    if (y % d != 0) { cout << 0 << endl; return 0; } y /= d;
    if (((x + y) % 2 + 2) % 2 != n % 2) { cout << 0 << endl; return 0; }

    ld ret = 0;
    rep(a, n + 1) {
        int b = n - a;
        if ((a-x)%2||(b-y)%2||(a<x)||(b<y))
            continue;
        ld p = f(n, a) * f(a, (a-x)/2) * f(b, (b-y)/2);
        ret += p;
    }
    printf("%.40Lf\n", ret);

    return 0;
}
