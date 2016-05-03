#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)

int main(void)
{
    int n = 100000;
    int q = 100000;
    cin >> n >> q;
    cout << n << endl;

    rep(i, n-1) {
        cout << (i+1) << " " << (i+2) << endl;
    }

    cout << q << endl;
    rep(i, q) {
        cout << (rand() % n) + 1 << " " << (rand() % n) + 1 << endl;
    }
    

    return 0;
}

