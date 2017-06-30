# -*- coding: utf-8 -*-
import numpy as np

def mapper(x): 
    if x >= 3200:
        return -1;
    else:
        return x // 400

n = input()
stage = np.array(list(map(int, input().split())))

r = np.count_nonzero(np.vectorize(mapper)(stage) == -1)
s = len(set(np.vectorize(mapper)(stage).tolist())-set([-1]))

print(max(s,1), s+r)
