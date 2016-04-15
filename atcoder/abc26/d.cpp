#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
using ld = double; // long doubleにしてみたけど、WAは治らず
int main(void) {
    ld a, b, c; cin >> a >> b >> c;
    ld l = 0, r = 1e6; 
    rep(cyc, 1000) { // 100000にしてみたけど、WAは治らず
        ld t = (l + r) / 2;
        if (a * t + b * sin(c * t * M_PI) > 100)
            r = t;
        else 
            l = t;
    }

    printf("%.40lf\n", l); // WAの原因はこれ。%.10lfではダメ！四倍精度のlong doubleでも40が限度なので、適当に40と入れとく
    return 0;
}
