#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int par[100010], w[100010];
int root(int i) { if (par[i] < 0) return i; return root(par[i]); }
int sum(int i) { if (par[i] < 0) return 0; return sum(par[i]) + w[i]; }
// w[r] - w[l] = d
void unite(int l, int r, int d) {
    int lr = root(l), rr = root(r);
    if (lr == rr) {
        if (sum(rr) - sum(lr) != d + sum(r) - sum(l)) 
            cout << "No" << endl, exit(0);
    } else {
        if (-par[lr] < -par[rr]) swap(l, r), swap(lr, rr), d *= -1;
        par[lr] += par[rr], par[rr] = lr;
        w[rr] = -(d + sum(r) - sum(l));
    }
}

int main(void) {
    int n,m;cin>>n>>m;
    rep(i, n) par[i] = -1;
    rep(i, m) {
        int l, r, c; cin >> l >> r >> c; l--, r--;
        unite(l, r, c);
    }
    cout << "Yes" << endl;

    return 0;
}
