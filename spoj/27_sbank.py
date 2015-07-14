#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import operator

def main():
    stdin = sys.stdin
    num_tests = int(stdin.readline())
    for i in range(0, num_tests):
        num_acc = int(stdin.readline())
        dct = {}
        #print num_acc
        for j in range(0, num_acc):
            acc = stdin.readline()[:-1]
            #print "acc = ", acc
            if acc not in dct:
                dct[acc] = 1
            else:
                dct[acc] += 1
            
        sorted_dct = sorted(dct.items(), key=operator.itemgetter(0))
        for key, val in sorted_dct:
            print key + str(val)

        stdin.readline()
        print

if __name__ == "__main__":
    main()
