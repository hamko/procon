#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, a, b; cin >> n >> a >> b;
    if (a == b) {
        if (n % (a + 1) == 0) 
            cout << "Aoki" << endl;
        else 
            cout << "Takahashi" << endl;
    } else if (a > b) {
        cout << "Takahashi" << endl;
    } else {
        if (n <= a) 
            cout << "Takahashi" << endl;
        else 
            cout << "Aoki" << endl;
    }
    return 0;

}
