#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-5;
#define EQ(a,b) (abs((a)-(b))<EPS)

#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define all(x) begin(x), end(x)
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<string> vs;

map<ll, ll> memo;
ll ret(ll n, ll m, ll p) {
//    cout << p << endl;
    if (memo.count(p)) {
        return memo[p];
    } else if (p % 2 == 0) {
        memo[p] = ((ret(n, m, p / 2) % m) * (ret(n, m, p / 2) % m)) % m;  
        return memo[p];
    } if (p % 2 == 1) {
        memo[p] = ((ret(n, m, p-1) % m) * (ret(n, m, 1) % m)) % m; 
        return memo[p];
    }
}

int main(void) {
    ll n, m, p;
    cin >> n >> m >> p;
    memo[0] = 1;
    memo[1] = n % m;
    cout << ret(n, m, p) << endl;
    return 0;
}
