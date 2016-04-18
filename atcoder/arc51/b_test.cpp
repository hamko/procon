#include <stdio.h>

int counter = 0;
int gcd(int a, int b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    gcd(a, b);
    printf("%d\n", counter);
}
