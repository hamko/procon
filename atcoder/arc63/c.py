# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np
import functools
import collections
mo = 1000000007
r = range

s = input()
ret = 0
for i in range(len(s)-1):
    ret += s[i] != s[i+1]
print(ret)
