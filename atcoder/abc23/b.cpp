#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 0 || s[n/2] != 'b') {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != s[0] + ((i + 3 + s[0] - 'a') % 3) - (s[0] - 'a')) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n / 2 << endl;
    return 0;
}
