import random
T = 100000
print T
for t in range(T):
    n = random.randint(10, 15)
    m = random.randint(10, 15)
    print n, m, random.randint(1, 1000)
    a = [0]
    for i in range(n):
        a.append(a[-1] + random.randint(1, 10))
    for i in range(n):
        print a[i],
        
    n = m
    a = [0]
    print ""
    for i in range(n):
        a.append(a[-1] + random.randint(1, 10))
    for i in range(n):
        print a[i],
    print ""
        
