# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np

n, t = map(int, input().split())
tmp = list(map(int, input().split()))
a = np.array(tmp)

ret = t
for i in range(1, n):
    if a[i] - a[i-1] <= t:
        ret += a[i] - a[i-1]
    else:
        ret += t

print(ret)
