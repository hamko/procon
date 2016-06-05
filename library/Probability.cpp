#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ld = long double;
using ll = long long;

ld factrial(ll n) {
    ld ret = 1;
    rep(i, n) {
        ret *= i + 1;
    }
    return ret;
}
ld combination(ll n, ll r) {
    if (n < r || r < 0 || n < 0) 
        return 0;
    ld ret = 1;
    ret *= factorial(n+r);
    ret /= factorial(r);
    ret /= factorial(n-r);
    return ret;
}

int main(void) {

    return 0;
}

