#include <cstdio>
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int a2[] = {0, 1, 0, 2, 0, 1};
int a3[] = {0, 0, 1, 0, 0, 1};
int a5[] = {0, 0, 0, 0, 1, 0};
double dp[100][100][100];

int main() {
    int N; ll D; cin >> N >> D;
    int n2, n3, n5;
    for (n2 = 0; D % 2 == 0; n2++) D /= 2;
    for (n3 = 0; D % 3 == 0; n3++) D /= 3;
    for (n5 = 0; D % 5 == 0; n5++) D /= 5;
    if (D != 1) {
        cout << 0 << endl;
        return 0;
    }
    dp[n2][n3][n5] = 1;
    while (N--) {
        for (int i2 = 0; i2 <= n2; i2++) for (int i3 = 0; i3 <= n3; i3++) for (int i5 = 0; i5 <= n5; i5++) {
            double p = dp[i2][i3][i5];
            dp[i2][i3][i5] = 0;
            for (int k = 0; k < 6; k++) {
                int _i2 = max(0, i2 - a2[k]);
                int _i3 = max(0, i3 - a3[k]);
                int _i5 = max(0, i5 - a5[k]);
                dp[_i2][_i3][_i5] += p / 6;
            }
        }
    }
    printf("%.10f\n", dp[0][0][0]);
}
