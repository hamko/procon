#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX_N = (int)1e5 + 5;

int n;
ll h;
ll a[MAX_N], b[MAX_N];

ll ma, mb;
ll thrdmg = 0;
ll attdmg = 0;
ll thrtimes = 0;

int main(void){
  // Here your code !
  scanf("%d %lld", &n, &h);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &a[i], &b[i]);
  }

  sort(b, b + n);
  sort(a, a + n);

  ma = a[n - 1];
  mb = b[n - 1];

  for (int i = 0; i < n; ++i) {
    if (ma < b[i]) {
      thrdmg += b[i];
      thrtimes += 1;
    }

    if (h <= thrdmg) {
      printf("%lld\n", thrtimes);
      return 0;
    }
  }

  attdmg = h - thrdmg;

  if (attdmg < ma) {
    printf("%lld\n", thrtimes + 1);
  }
  else {
    if (attdmg % ma != 0) {
      printf("%lld\n", thrtimes + 1 + (attdmg / ma));
    }
    else {
      printf("%lld\n", thrtimes + (attdmg / ma));
    }
  }

  return 0;
}

