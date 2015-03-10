a = []

for i in range(0, 30):
    a.append(2**i)
    for j in range(0, 30):
        a.append(3**j)
        a.append(2**i*3**j)
        for k in range(0, 30):
            a.append(5**k)
            a.append(3**j*5**k)
            a.append(2**i*3**j*5**k)

b = sorted(set(a))
print len(b)
print b[1499]
