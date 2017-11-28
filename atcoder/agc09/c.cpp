#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;

template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
static const long long INF = 1e18;
static const long long mo = 1e9+7;

template<class T>
struct SegmentTreeSum {
    int n;
    T inf;
    vector<T> dat;
    SegmentTreeSum(int n_ = 0) : n(n_){
        inf = 0;
        for(n = 1; n < n_; n <<= 1);
        dat.resize(n*2, inf);
    }
    T sum(int v, int w, int l, int r){
        if(r <= l || w == 0) return inf;
        if(r - l == w) return dat[v]; // assert(l == 0 && r == w);
        int m = w/2;
        return (sum(v*2, m, l, min(r,m)) + sum(v*2+1, m, max(0,l-m), r-m)) % mo;
    }
    void assign(int i, const T &x){
        dat[i+=n] = x;
        for(; i!=1; i/=2) dat[i/2] = (dat[i] + dat[i^1]) % mo;
    }
    T sum(int l, int r){ return sum(1,n,l,r); }
    size_t size() const { return n; }
    T operator [] (const int &idx) { return sum(idx, idx + 1); }
};

int main(void) {
    ll n; cin >> n;
    ll x, y; cin >> x >> y; if (x > y) swap(x, y);
    vll a;
    a.pb(-INF);
    rep(i, n) {
        ll tmp; cin >> tmp;
        a.pb(tmp);
    }
    n = a.size();
    SegmentTreeSum<ll> dp(n+1);
    dp.assign(0, 1);

    rep(i, n-2) 
        if (a[i] + x > a[i+2]) 
            return cout << 0 << endl, 0;

    ll j = 0; 
    vll z(n+1), js(n+1);

    // 集めるDP
    repi(i, 2, n+1) {
        if (a[i-1] - a[i-2] < x) 
            z[i] = i - 2;
        else 
            z[i] = z[i-1];

        while (j < i - 1 && a[i-1] - a[j] >= y) {
            j++;
        }
        js[i] = j;

        dp.assign(i-1, dp.sum(z[i-1], js[i]));
    }
    cout << dp.sum(z[n], n+1) << endl;
    return 0;
}
