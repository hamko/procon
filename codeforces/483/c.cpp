#include <stdio.h>

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define ll unsigned long long

ll input(void){ ll v=0;char c=0;ll p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！

ll gcd(ll u, ll v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}
char solve(ll q, ll b) {
    ll counter = 0;
    while (1) {
        ll g = gcd(q, b);
        if (g == 1) break;
        counter++;
        q /= g;
    }
    if (q == 1) {
        return 0;
    } else {
        return 1;
    }
}
#ifdef _WIN32
#define scanfll(x) scanf("%I64u", &x)
#else
#define scanfll(x) scanf("%llu", &x)
#endif

int main(void) {
    ll m; scanfll(m);
    rep(_, m) {
        ll p,q,b;
        scanfll(p);
        scanfll(q);
        scanfll(b);
        ll g = gcd(p, q);
        p /= g;
        q /= g;
        if (q == 1) {
            printf("Finite\n");
            continue;
        }
        if (b == 2) {
            if (__builtin_popcountll(q) == 1) {
                printf("Finite\n");
            } else {
                printf("Infinite\n");
            }
            continue;
        }
        if (!solve(q, b)) {
            printf("Finite\n");
        }  else {
            printf("Infinite\n");
        }
    }

    return 0;
}
