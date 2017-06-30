# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy

n, m = map(int, input().split())

if math.fabs(n - m) == 1:
    k = 1
elif n == m:
    k = 2
else:
    k = 0

print(math.factorial(n) * math.factorial(m) * k % 1000000007)
