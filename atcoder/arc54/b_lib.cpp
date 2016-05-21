#include <bits/stdc++.h>
using namespace std;
using ld = long double;

template<class Function>
ld ternarySearch(ld l, ld r, Function f){
    for (int i = 0; i < 200; i++){
        ld a = (l + l + r) / 3;
        ld b = (l + r + r) / 3;
        (f(a) > f(b)) ? l = a : r = b;
    }
    return f(l);
}

int main(void) {
    ld p; cin >> p;
    cout << ternarySearch(0, 1e18, [&](ld x) { return x + pow(2, -x/1.5) * p;}) << endl;;
    return 0;
}
