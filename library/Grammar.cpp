#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)

int main(void) {
    int n = 100;
    int x = 0, y = 0;

    // ちゃんと両方足される
    x = 0, y = 0;
    rep(i, n) x++, y++;
    cout << x << " " << y << endl;

    // コンパイルエラー
//    x = 0, y = 0;
//    rep(i, n) x++, continue, y++;
//    cout << x << " " << y << endl;

    // コンパイルエラー
//    x = 0, y = 0;
//    rep(i, n) continue, x++, y++;
//    cout << x << " " << y << endl;

    // ちゃんと両方足される
    x = 0, y = 0;
    if (1)
        x++, y++;
    cout << x << " " << y << endl;

    // コンパイルエラー
//    int a[n] = {};
    
    // コンパイルエラーはしないが、uninitialize
    int a[n]; // NG

    // 毎回こうしないといけない
    int a[n]; rep(i, n) a[i] = 0;

    return 0;
}
