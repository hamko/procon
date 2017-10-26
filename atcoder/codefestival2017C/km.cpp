#include "bits/stdc++.h"
using namespace std;

#define MAX 200002

char buf[MAX];

string s;
int n;

int dp[1 << 26];

int main() {
    scanf("%s", buf);
    s = buf;
    memset(dp, -1, sizeof(dp));
    int cur = 0;
    dp[0] = 0;
    int las = 0;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        cur ^= (1 << id);
        int nex = INT_MAX;
        if (dp[cur] != -1) {
            nex = min(nex, dp[cur]);
        }
        for (int j = 0; j < 26; j++) {
            int go = cur;
            go ^= (1 << j);
            if (dp[go] != -1) {
                nex = min(nex, dp[go]);
            }
        }
        if (nex != INT_MAX) {
            if (dp[cur] == -1 || dp[cur] > nex + 1) {
                dp[cur] = nex + 1;
            }
            las = nex + 1;
        }
    }
    cout << las << endl;
    return 0;
}
