# -*- coding: utf-8 -*-
n, m = map(int, input().split())
ret = min(n, m//2)
n -= ret; m -= ret * 2
print(ret + m // 4)
