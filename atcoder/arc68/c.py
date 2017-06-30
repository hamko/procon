x = int(input())
print(x // 11 * 2 + (0 if x % 11 == 0 else (1 if x % 11 <= 6 else 2)))
