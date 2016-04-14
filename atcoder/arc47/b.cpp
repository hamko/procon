#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define Min(x) *min_element(all(x))
#define Max(x) *max_element(all(x))
using ll = long long; using vll = vector<ll>; using vi = vector<int>;

int main(void) {
    int N; cin >> N;
    vll x, y; x.reserve(N); y.reserve(N);
    rep(i, N) {
        ll xtmp, ytmp; cin >> xtmp >> ytmp; 
        x.push_back(xtmp-ytmp); y.push_back(xtmp+ytmp);
    }

    ll l = max(Max(x) - Min(x), Max(y) - Min(y));
    vll px = {Min(x) + l / 2, Max(x) - l / 2};
    vll py = {Min(y) + l / 2, Max(y) - l / 2};
    for (ll xc : px) for (ll yc : py) {
        int faf = 1;
        rep(i, N) {
            if (std::abs(xc - x[i]) != l/2 && std::abs(yc - y[i]) != l/2) {
                faf = 0;
                break;
            }
        }
        if (faf) {
            cout << (xc+yc)/2 << " " << (-xc+yc)/2 << endl;
            return 0;
        }
    }

    return 0;
}
