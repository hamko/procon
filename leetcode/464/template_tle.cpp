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
#define ZERO(a) memset(a,0,sizeof(a))
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define exists find_if
#define forall all_of

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;
#define ldout fixed << setprecision(40) 

class Solution {
    unordered_map<int, bool> dp[301];
    public:
        ll max_m;
        // mask, dが勝ち状態なら1, dが負け状態なら0
        bool dfs(ll mask, ll d) {
            if (d <= 0) return 0;
            if (dp[d].count(mask)) {
                return dp[d][mask];
            }
            dp[d][mask] = 0;

            rep(i, max_m) if ((mask & (1ll << i)) == 0) {
                if (d <= i + 1) {
                    return dp[d][mask] = 1;
                }
            }
            // 遷移先に負け状態が一つでもあれば勝ち
            ll f = 0;
            rep(i, max_m) if ((mask & (1ll << i)) == 0) {
                f |= !dfs(mask | (1ll << i), d - (i + 1));
            }
            return dp[d][mask] = f;
        }
        bool canIWin(int m, int d) { // m <= 20, d <= 300
            if (d == 0) return 1;
            max_m = m;
            return dfs(0, d);
        }
};

int main(void) {
    ll m, d; cin >> m >> d;
    Solution s;
    cout << s.canIWin(m, d) << endl;

    return 0;
}
