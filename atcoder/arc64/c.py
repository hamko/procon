# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np
import functools
import collections
mo = 1000000007
r = range

n, x = map(int, input().split())
# n行x列の配列を取得
a = np.array(list(map(int, input().split())))

ret = 0
for i in r(1, n):
    for j in r(2):
        if a[i] + a[i-1] > x:
            tmp = min(a[i-j], a[i] + a[i-1] - x)
            ret += tmp
            a[i-j] -= tmp

print(ret)
