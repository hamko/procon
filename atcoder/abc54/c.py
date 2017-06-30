# -*- coding: utf-8 -*-
n, m = map(int, input().split())
g = [[] for i in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

def dfs(v):
    if len(v) == n:
        return 1
    ret = 0
    for u in set(g[v[-1]]) - set(v):
        ret += dfs(v + [u])
    return ret

print(dfs([0]))
