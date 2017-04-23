import math
import sys
s = int(input())

for t in range(1010, -1, -1): 
    base = 100 ** t
    l = (s * s + base - 1) / base 
    r = ((s + 1) * (s + 1) - 1) / base
    if l <= r:
        print l
        sys.exit()
