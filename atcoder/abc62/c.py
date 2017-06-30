# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np

h, w = map(int, input().split())

m = math.inf
m = min(m, (1 if h % 3 else 0) * w)
m = min(m, (1 if w % 3 else 0) * h)
for _ in range(2):
    for i in range(1, h+1):
        v = np.array([i*w, w//2*(h-i), (w-w//2)*(h-i)])
        m = min(m, max(v) - min(v))
    h, w = w, h

print(m)
