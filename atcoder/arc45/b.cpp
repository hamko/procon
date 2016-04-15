#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9+10;

#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) begin(x), end(x)
using ll = long long; using vll = vector<ll>; using vi = vector<int>;
typedef pair<int, int> P;

#define MAX_N 300005
#define MAX_M 100005

int main(void) {
    int n, m; cin >> n >> m;
    vi a(n+1, 0), s(m), t(m);
    a[0] = -1; a[n] = 1;
    rep(i, m) {
        int stmp, ttmp; cin >> stmp >> ttmp; stmp--; ttmp--;
        a[stmp]++; a[ttmp+1]--;
        s[i] = stmp; t[i] = ttmp+1;
    }
    vector<P> r;
    P rtmp;
    for (int i = 1; i < n+1; i++) {
        a[i] += a[i-1];
        if (a[i] > 0 && a[i-1] == 0)
            rtmp.first = i;
        if (a[i] == 0 && a[i-1] > 0) {
            rtmp.second = i;
            r.push_back(rtmp);
        }
    }
    auto comp = greater<P>();
    sort(all(r), comp);

    vi ans;
    rep(i, m) {
        auto it = upper_bound(all(r), P(s[i], INF), comp);
        if (it == r.end())
            continue;
        P cand = *it;
        if (t[i] <= cand.second) 
            ans.push_back(i);
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i] + 1 << endl;
    }

    
    return 0;
}
