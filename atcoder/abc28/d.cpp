#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K; cin >> N >> K;
    double a = (double)1/N, b = (double)(N-K)/N, c = (double)(K-1)/N;
    printf("%.12lf\n", a*a*a+3*a*a*(b+c)+6*a*b*c);
    return 0;
}
