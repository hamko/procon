#include <bits/stdc++.h>
using namespace std;

// O(n log n)
// int n 配列の長さ．2 のべきでなければならない．
// double theta 回転角．順変換のとき 2.0*PI/n を指定し，逆変換のとき -2.0*PI/n を指定する．
// Complex a[] 変換する配列．結果は in place で変換される．逆変換の場合は結果をさらに 1/n 倍する必要がある．
const double PI = 4.0*atan(1.0);
typedef complex<double> Complex;
const Complex I(0, 1);
void fft(int n, double theta, Complex a[]) {
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            Complex w = exp(i*theta*I);
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                Complex x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta *= 2;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
}

#define rep(i,n) for(int i = 0; i < n; i++)
int main(void) {
    int n = 1 << 3;
    Complex a[n];

    // set 
    a[0] = Complex(1, 0); a[1] = Complex(2, 0); a[2] = Complex(3, 0); a[3] = Complex(4, 0);
    rep(i, n) { cout << "(" << a[i].real() << ", " << a[i].imag() << ") " << endl; } cout << endl;

    // fft
    fft(n, 2.0*PI/n, a);
    rep(i, n) { cout << "(" << a[i].real() << ", " << a[i].imag() << ") " << endl; } cout << endl;

    // inv fft, nで割ることに注意！
    fft(n, -2.0*PI/n, a);
    rep(i, n) a[i] /= n;
    rep(i, n) { cout << "(" << a[i].real() << ", " << a[i].imag() << ") " << endl; } cout << endl;

    return 0;
}

