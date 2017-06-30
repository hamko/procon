import numpy as np

n = int(input())
a = np.array(list(map(int, input().split())))

ret = 0
i = 0
while i < len(a):
    j = i
    while j < n - 1 and a[j] <= a[j+1]:
        j += 1
    h = i
    while h < n - 1 and a[h] >= a[h+1]:
        h += 1
    i = max(h, j) + 1
    ret += 1

print(ret)
