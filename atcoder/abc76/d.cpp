#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}

const int tres = 4, vres = 4;
vector<int> dp(20010*tres), lim(20010*tres);
int main(void) {
    int n; cin >> n;
    vector<int> t(n), v(n); cin >> t >> v;
    rep(i, n) v[i] *= vres, t[i] *= tres;
    int s = 0;
    rep(i, n) {
        repi(j, s, s+t[i]) 
            lim[j] = v[i];
        s += t[i];
    }
    
    rep(_, 210*vres) repi(i, 1,dp.size()) 
        if (dp[i] <= min({dp[i+1], dp[i-1], lim[i] -1, lim[i-1]-1}))
            dp[i]++;

    double ret = 0;
    rep(i, dp.size()-1) 
        ret += (dp[i] + dp[i+1]) / (double)vres * (1.0 / (double(tres))) / 2.0;

    cout << setprecision(40) << ret << endl;
    return 0;
}
