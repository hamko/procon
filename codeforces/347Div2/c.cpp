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

#define MAX_N 100005

int main(void) {
    int n; cin >> n; 
    rep(i, n) {
        string s; cin >> s;
        s = s.substr(4, s.length() - 4);
        int a = stoi(s);
        int ret = 1989;
        rep(j, s.length() - 1) {
            cout << pow(10, j + 1) << "pow" << endl;
            ret += pow(10, j + 1);
        }
        ret += (a+1)%(int)pow(10, s.length());
        cout << ret << endl;
    }
    return 0;
}
