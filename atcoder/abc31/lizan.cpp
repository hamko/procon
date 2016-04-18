#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int K, N;

    cin >> K >> N;

    vector<string> num(N), goro(N);

    for (int i = 0; i < N; ++i) {
        cin >> num[i] >> goro[i];
    }

    int P = pow(3, K);
    for (int i = 0; i < P; ++i) {
        int tmp = i;
        vector<int> len(K);

        for (int j = 0; j < K; ++j) {
            len[j] = tmp % 3 + 1;
            tmp /= 3;
        }

        bool fail = false;
        for (int j = 0; j < N; ++j) {
            int w = 0;
            for (char c : num[j]) {
                w += len[c - '1'];
            }
            if (w != goro[j].length()) {
                fail = true;
                break;
            }
        }

        if (fail) continue;

        vector<string> ans(K);
        for (int j = 0; j < N; ++j) {
            int w = 0;
            for (char c : num[j]) {
                int idx = c - '1';
                const string &g = goro[j].substr(w, len[idx]);
                w += len[idx];
                if (ans[idx].empty()) {
                    ans[idx] = g;
                } else if (ans[idx] != g) {
                    fail = true;
                    break;
                }
            }
        }

        if (fail) continue;

        for (int j = 0; j < K; ++j) {
            cout << ans[j] << endl;
        }
        break;
    }


    return 0;
}

