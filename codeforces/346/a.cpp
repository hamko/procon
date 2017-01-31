#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;
    cout << 1 + (a + b + n * 1000 - 1) % n << endl;
    return 0;
}
