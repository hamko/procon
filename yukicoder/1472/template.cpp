#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    assert(n >= 2);
    assert(n <= 100000);

    if (n == 2) 
        cout << 1 << endl;
    else if (n == 4) 
        cout << 2 << endl;
    else 
        cout << -1 << endl;
    
    return 0;
}
