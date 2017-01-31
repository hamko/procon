import sys

def helper(list, x, y):
    if x == 1:
        #print list
        return list
    l = [0]*(2*len(list)-1)
    for i in range(1, len(list)):
        for j in range(1, len(list)):
            l[i+j] = list[i]*list[j] + l[i+j]
    if x%2 == 0:
        return helper(l, x/2, y)
    else:
        l1 = helper(l, x/2, y)
        l2 = [0]*(len(list)+len(l1)-1)
        for i in range(1, len(list)):
            for j in range(1, len(l1)):
                l2[i+j] = list[i]*l1[j] + l2[i+j]
        #rint l2
        return l2
def solve(target, x, y):
    if target < x or target > x*y:
        return 0.0
    list = [1.0/float(y) for i in range(0, y+1)]
    list[0] = 0.0
    #rint list
    l = helper(list, x, y)
    return sum(l[target:])


f = open('fighting_the_zombie.txt', 'r')
t = int(f.readline())
for i in range(1, t+1):
    h, s = map(int, f.readline().split())
    spell = f.readline().split()
    eps = 1e-06
    ans = 0.0
    for sp in spell:
        x, tmp = sp.strip().split('d')
        if '-' in tmp:
            y, z = map(int, tmp.split('-'))
            z = -z
        elif '+' in tmp:
            y, z = map(int, tmp.split('+'))
        else:
            y = int(tmp)
            z = 0
        x = int(x)
        target = h-z
        local = solve(target, x, y)
        #print local
        if local - ans > eps:
            ans = local
    sys.stdout.write("Case #"+str(i)+": "+str(ans)+'\n')
