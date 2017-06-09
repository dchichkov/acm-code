#/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def main():
    num_cases = int(sys.stdin.readline())
    for i in range(0, num_cases):
        n1, n2 = sys.stdin.readline().split(' ')
        print int(n1) * int(n2)
        


if __name__ == '__main__':
    main()
