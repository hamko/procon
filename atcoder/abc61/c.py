# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np

n, k = map(int, input().split())
memo = np.zeros(100010, dtype=np.int)

for i in range(n):
    a, b = map(int, input().split())
    memo[a] += b

s = 0
for i in range(len(memo)):
    s += memo[i]
    if k <= s:
        print(i)
        exit()
