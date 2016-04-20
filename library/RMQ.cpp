#include "bits/stdc++.h"
using namespace std;

// リスト a が与えられる．このとき，自然数 x, y に対して min { a[z] | x ≦ z ≦ y } を答える問題を区間最小値問い合わせ(Range Minimum Query: RMQ)と呼ぶ．
// x, yは両端含むことに注意！！
// これはO(n log n)、だけど最小共通祖先問題に落とすとO(n)で済む。
int *buildRMQ(int *a, int n) {
    int logn = 1;
    for (int k = 1; k < n; k *= 2) ++logn;
    int *r = new int[n * logn];
    int *b = r; copy(a, a+n, b);
    for (int k = 1; k < n; k *= 2) {
        copy(b, b+n, b+n); b += n;
        for (int i = 0; i < n-k; i++) b[i] = min(b[i], b[i+k]);
    }
    return r;
}
// O(log log n)
int minimum(int x, int y, int *rmq, int n) {
    int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k なる最大 k
    s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
    return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}

#define N 100
int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i + i % 5;
    }
    int* rmq = buildRMQ(a, N);
    cout << minimum(25, 30, rmq, N) << endl;
    cout << *min_element(a+25, a+31) << endl;

    return 0;
}
