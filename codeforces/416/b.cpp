#pragma GCC optimize ("O3") // 最適化レベルの変更 O0〜O3 などを指定
#pragma GCC target ("avx") // ターゲットの変更 sse4, avx, avx2 など
#include <stdio.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define pb push_back
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
int a[10003];
int arev[10003];

int main(void) {
    int n, m; scanf("%d%d",&n,&m);
    rep(_, n) 
        scanf("%d",&a[_]), arev[a[_]] = _;

    rep(_, m) {
        int l, r, k;
        scanf("%d%d%d",&l,&r,&k); l--, r--, k--;
        int counter = 0;
        repi(i, l, r+1) {
            counter += a[i] < a[k];
        }
        if (k == l + counter) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
