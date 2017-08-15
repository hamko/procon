def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    c = a % b
    return gcd(b, c)

p, q = map(int, input().split())
g = gcd(p, q)
p //= g
q //= g
print(p, q)
ret = q
for b in range(1, 40000):
    if b ** 50 * p % q == 0:
        ret = min(ret, b)
print(ret)
