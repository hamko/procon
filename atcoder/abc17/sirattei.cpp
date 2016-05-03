#include <bits/stdc++.h>
using namespace std;
 
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FORR(x,arr) for(auto&& x:arr)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define BIT(n) (1LL<<(n))
#define SZ(x) ((int)(x).size())
typedef long long ll;
// -------------------------------------
 
int N, M;
int F[101010];
 
const long long mod = 1000000007;
 
int L[101010];
int S[101010];
int dp[101010];
 
int main() {
      scanf("%d %d", &N, &M);
        REP(i, N) scanf("%d", F+i+1);
         
          dp[0] = 1;
            S[0] = 1;
             
              int l = 0;
                FOR(i, 1, N+1) {
                        int f = F[i];
                            l = max(l, L[f]);
                                //_P("%d,%d,%d,S[%d]=%d,dp[%d]=%d\n", i, f, l, i, S[i], i, dp[i]);
                                dp[i] = S[i-1] - (l ? S[l-1] : 0);
                                    if (dp[i] < 0) dp[i] += mod;
                                        (S[i] = S[i-1] + dp[i]) %= mod;
                                            L[f] = i;
                                              }
                 
                  /*
                       REP(i, N + 1) {
                           _P("dp[%d]: %d\n", i, dp[i]);
                             }
                               REP(i, N + 1) {
                                   _P("S[%d]: %d\n", i, S[i]);
                                     }
                                       */
                 
                  cout << dp[N] << endl;
                   
                    return 0;
}
