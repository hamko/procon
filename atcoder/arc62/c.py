n = int(input())

x, y = map(int, input().split())
for i in range(n-1):
    a, b = map(int, input().split())
    k = max((x-1)//a+1, (y-1)//b+1)
    x, y = k * a, k * b
print(x+y)
