# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np
import functools
import string

ret = {}
n = int(input())
for i in range(n):
    s = input()
    d = {x : s.count(x) for x in s}
    for c in  string.ascii_lowercase:
        if c in d:
            continue
        d[c] = 0

    for c in d:
        if c in ret:
            ret[c] = min(ret[c], d[c])
        else:
            ret[c] = d[c]

s = ''
for c in ret:
    s += c * ret[c]
print(''.join(sorted(s)))
