# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np
import functools
mo = 1000000007
r = range

n = int(input())

primes = set()
for i in r(2, 1000):
    for p in primes:
        if i % p == 0:
            break
    else:
        primes.add(i)

d = {}
for i in r(2, n+1):
    x = i
    while x != 1:
        for p in primes:
            if x % p != 0:
                continue;
            x //= p
            if p not in d:
                d[p] = 0
            d[p] += 1
            break

ret = 1
for i in d.values():
    ret *= (i+1)
    ret %= mo

print(ret)
