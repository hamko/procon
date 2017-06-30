# -*- coding: utf-8 -*-
import math
import sys
import itertools
import numpy as np
import functools
import collections
mo = 1000000007
INF = 10**100
r = range

class infix(object):
    def __init__(self, function):
        self.function = function

    def __ror__(self, other):
        self.left = other
        return self

    def __or__(self, other):
        return self.function(self.left, other)

    def __call__(self, value1, value2):
        return self.function(value1, value2)

@infix
def c(f_t_u, f_u_r): return lambda t: f_u_r(f_t_u(t))

class _Ap(object):
    def __rlshift__(self, other):
        self.value = other
        return self

    def __rshift__(self, other):
        return other(self.value)
Ap = _Ap()
a = Ap

#d = {1:2, 3:5, 6:10, 1000043:3814}
#zip(d.keys(), d.values())<<a>>(list |c| sorted |c| reversed |c| list |c| print)

