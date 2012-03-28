MAX = 1000000
file_  = open('primes_printout.txt', 'w')
primes = []
for i in range(0, MAX):
    primes.append(0)
for i in range(2, MAX):
    if primes[i] == 0:
        for j in range(i+i, MAX, i):
            primes[j] += 1
        primes[i] += 1

file_.write("a[1000000] = {")
for x in range(0, len(primes)):
    file_.write("{0},".format(primes[x]))
file_.write("};\n")
file_.close()
