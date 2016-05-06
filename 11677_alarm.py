#!/usr/bin/python3

import sys
from datetime import datetime, timedelta

stdin = sys.stdin

def main():
    for line in stdin.readlines():
        line = line.split(" ")
        h1, m1 = int(line[0]), int(line[1])
        h2, m2 = int(line[2]), int(line[3])

        if (h1 == 0 and m1 == 0 and h2 == 0 and m2 == 0):
            break

        a = datetime.now()
        b = datetime.now()
        a = a.replace(hour=h1, minute=m1, second=0)
        b = b.replace(hour=h2, minute=m2, second=0)

        if (b < a):
            b += timedelta(days=1)
        c = b - a
        print(int(c.seconds/60))
            

if __name__ == "__main__":
    main()
