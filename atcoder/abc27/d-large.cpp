#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

#define rep(i,n) for(int i = 0; i < n; i++)
#define MAX_N 100005

int main(void) {
    string S; cin >> S;
    vector<int> p(S.length(), 0);
    for (int i = S.length() - 1; i >= 0; i--) {
        if (i != S.length() - 1)
            p[i] += p[i+1];
        if (S[i] == '+')
            p[i]++;
        else if (S[i] == '-')
            p[i]--;
    }
    vector<int> ps; ps.reserve(MAX_N);
    rep(i, p.size()) {
        if (S[i] != 'M') continue;
        ps.push_back(p[i]);
    }
    sort(ps.begin(), ps.end());
    cout << -accumulate(ps.begin(), ps.begin()+ps.size()/2, 0)+accumulate(ps.begin()+ps.size()/2, ps.end(), 0) << endl;


    return 0;
}
