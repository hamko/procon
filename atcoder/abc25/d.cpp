#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-14;
static const long long INF = 1e18;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

#define MAX_N (1 << 25)

int a[5][5]; ll dp[MAX_N] = {};
map<int, P> pos; 
set<int> s;
vector<P> npos;

// aのi, j列bitを読む
bool read_bit(int a, int i, int j) { return (a & (1 << (i * 5 + j))); }
void write_bit(int& a, int i, int j, bool b) { 
    if (b) 
        a |= (1 << (i * 5 + j)); 
    else
        a &= ~(1 << (i * 5 + j)); 
}

bool f(int S, int j) {
}

int main(void) {
    // ある数字とその位置
    rep(i, 5) rep(j, 5) { 
        cin >> a[i][j]; 
        if (a[i][j]) 
            pos[a[i][j]] = P(i, j);
    }

    // ない数字群
    rep(i, 25) s.insert(i);
    rep(i, 5) rep(j, 5) s.erase(a[i][j]);
    for(auto x : s) { cout << x << endl; }

    // ない数字群の位置
    rep(i, 5) rep(j, 5) if (!a[i][j]) npos.push_back(P(i, j));
    
    dp[0] = 1;
    rep (S, 1 << 25) {
        rep(j, 25) {
            if (read_bit(S, x, y) || 
                    (x > 0 && x < 4 && (read_bit(S, x - 1, y) && read_bit(S, x + 1, y))) || 
                    (y > 0 && y < 4 && (read_bit(S, x, y - 1) && read_bit(S, x, y + 1)))) {
                continue;
            }
            int Snext = S; write_bit(Snext, x, y, i);
            dp[next][Snext] += dp[i][S];
        }
    }

    return 0;
}
