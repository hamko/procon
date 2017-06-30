s = input()
ret = 0
tmp = 0
for c in s:
    tmp += 1 if c == 'S' else -1
    ret = min(ret, tmp)

print(-ret*2)
