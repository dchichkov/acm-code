# /usr/bin/python
# -*- coding: utf-8 -*-

import sys
from operator import itemgetter

stdin = sys.stdin


def process(lst):
    a = 0
    b = 0
    while a < len(lst):
        b = a+1
        while b < len(lst):
            if lst[a][0] <= lst[b][0] and lst[a][1] >= lst[b][0]:
                del lst[b]
            else:
                break
        a += 1
    return lst


def main():
    tables = int(stdin.readline())
    for i in range(0, tables):
        num_tables = int(stdin.readline())
        msurments = list()
        for i in range(0, num_tables):
            msur = stdin.readline().split(' ')
            a, b = int(msur[0]), int(msur[1])
            msurments.append((a, b))
        msurments = sorted(msurments, key=itemgetter(0))

        msurments = process(msurments)
        print len(msurments)


if __name__ == '__main__':
    main()
