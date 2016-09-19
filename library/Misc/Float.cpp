#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // 基数：floatは8, doubleは11, long doubleは15
    // つまり、二分探索の打ち切り回数は、2^基数で十分(doubleなら2024回、long doulbleでも32000回)
    cout << sizeof(float) <<  " " << sizeof(double) << " " << sizeof(long double) << endl;
    cout << FLT_MIN << " " << DBL_MIN << " " << LDBL_MIN <<endl;

    //  2進数表示では、floatは23桁、doubleは53桁、long doubleは113桁まで有効
    // 10進数表示では、floatは8桁、doubleは16桁、long doubleは36桁まで有効（丸め誤差で結局精度は落ちるのだが）
    int n = 1, m = 3;
    float a = (float)n / (float)m;
    double b = (double)n / (double)m;
    long double c = (long double)n / (long double)m;
    printf("%.40f\n", a);
    printf("%.40lf\n", b);
    printf("%.40Lf\n", c); // 4倍精度でも40桁いかないので、全部とりあえず40と入れとく
    return 0;
}
