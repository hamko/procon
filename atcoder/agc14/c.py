x, y, z = map(int, input().split())

ret = 0
while not(x % 2 == 1 or y % 2 == 1 or z % 2 == 1):
    ret += 1
    x, y, z = y//2+z//2, z//2+x//2, x//2+y//2
    if ret > 10000:
        ret = -1
        break;

print(ret)

