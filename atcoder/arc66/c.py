# -*- coding: utf-8 -*-
import numpy as np
import collections
mo = 1000000007
r = range

n = int(input())
a = np.array(list(map(int, input().split())))

c = collections.Counter(a.tolist())

if n % 2 == 1 and (0 not in c or c[0] != 1): print(0); exit();

for i in r(n//2):
    x = i * 2 + (1 if n % 2 == 0 else 2)
    if x not in c or c[x] != 2: print(0); exit();

print(2 ** (n//2) % mo)
