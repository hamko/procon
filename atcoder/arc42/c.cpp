#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define print(v) for(auto x:(v)){cout<<x<<" ";}cout<<endl;
#define printi(b,e) for(auto x=(b); x!=(e); x++)cout<<*x<<" ";cout<<endl;
#define printa(a,n) rep(i,n)cout<<a[i]<<" ";cout<<endl;
#define all(x) x.begin(), x.end()
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define MAX_N 5005
#define MAX_NV 5005
ll v[MAX_N], w[MAX_N];
vector<P> s;
ll dp[2][MAX_NV] = {};
int main(void) 
{
    int n, p; cin >> n >> p;
    s.resize(n);
    rep(i, n) {
        cin >> s[i].second >> s[i].first;
    }
    sort(all(s), [&](const P& a, const P& b){ if (a.first != b.first) return (a.first > b.first); else return (a.second < b.second); });
//    sort(all(s));
    rep(i, n) {
        v[i] = s[i].first;
        w[i] = s[i].second;
//        cout << w[i] << " " << v[i] << endl;
    }

    rep(i, 2) rep(j, MAX_NV) 
        dp[i][j] = 0; 

    ll marr[MAX_N] = {};
    ll prev_max = 0;
    rep(i, n) { 
        int next = (i+1)%2, prev = i%2;
        marr[i] = prev_max+v[i];
        prev_max = 0;
        rep(j, p+1) {
            dp[next][j] = max(dp[prev][j], j-w[i]<0 ? 0 : dp[prev][j-w[i]]+v[i]);
            prev_max = max(prev_max, dp[next][j]);
        }
//        cout << prev_max << "#P" << endl;
    }

    ll m = 0;
    rep(i, p+1) 
        m = max(m, dp[n%2][i]);
    rep(i, n) 
        m = max(m, marr[i]);
//    cout << m << endl;

    return 0;
}

