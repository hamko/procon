#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

int main(void) {
    int n; cin >> n;
    cout << n/2*3+n%2<<endl;
    rep(i, 100000) rep(j, 3) {
        int a = 2*i-j+1+n%2;
        if (1 <=a && a <= n) 
            cout << a << " ";
    }
    cout << endl;
    return 0;
}
