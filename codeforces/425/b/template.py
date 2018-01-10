import re
s = input()
t = input()
n = int(input())
ns = "Z"
for c in range(26):
    if s.find(chr(c+ord('a'))) == -1:
        ns += chr(c+ord('a'))

reg = t
reg = reg.replace('?', '[' + s + ']')
reg = reg.replace('*', '[' + ns + ']*')

a = re.compile(reg)

for i in range(n):
    p=input()
    m = a.match(p)
    if m != None and m.end()-m.start() == len(p):
        print("YES")
    else:
        print("NO")
