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
    int plus = 1, minus = 0;
    int n;
    char c;
    vector<int> dir; dir.push_back(1);
    while (cin >> c) {
        if (c == '+') {
            dir.push_back(1);
            plus++;
        } else if (c == '-') {
            dir.push_back(-1);
            minus++;
        } else if (c == '=') {
            break;
        }
    }
    cin >> n;
    int n_org = n;
    n += minus;
    if (n > plus * n_org) {
        cout << "Impossible" << endl;
        return 0;
    } else {
        cout << "Possible" << endl;
    }

    n -= plus;
    int first = 0;
    for (auto d : dir) {
        if (first && d == 1) cout << " + "; else if (d == -1) cout << " - ";
        first = 1;

        if (d == -1)
            cout << 1;
        else {
            int diff = 0;
            if (n >= n_org - 1) {
                diff = n_org - 1;
            } else {
                diff = n;
            }
            n -= diff;
            cout << 1 + diff;
        }
    }
    cout << " = " << n_org;
    cout << endl;

    return 0;
}
