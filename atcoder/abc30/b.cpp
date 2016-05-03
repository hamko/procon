#include <bits/stdc++.h>
using namespace std;

typedef complex<double> P;
int main(void) {
    int a, b; cin >> a >> b;
    printf("%.40lf\n", abs(arg(polar(1.0, M_PI*2*a/12+M_PI*2/12*b/60) / polar(1.0, M_PI*2*b/60)))/M_PI*180);

    return 0;
}
