# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np

n = int(input())

a = np.arange(10)
print(np.where(a * (a + 1) // 2 >= n)[0][0])
