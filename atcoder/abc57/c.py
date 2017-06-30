import math

n = int(input())
ret = 10000000000000000
for i in range(1, int(math.sqrt(float(n))+5.0)):
    if n % i:
        continue;
    ret = min(ret, max(int(math.log10(n//i)), int(math.log10(i))) + 1)

print(ret)
