#! /usr/bin/python
# -*- coding: utf-8 -*-

import sys
import math


STDIN = sys.stdin


class TooLongException(Exception):
    pass


def convert(num, basefrom, baseto):
    """
    Num is in base basefrom, so convert it to baseto
    """
    hexbase = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7,
               '8': 8, '9': 9, 'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14,
               'F': 15}
    hexto = '0123456789ABCDEF'
    internum = 0
    ans = ''
    exp = 0

    for i in num[::-1]:
        internum += hexbase[i] * math.pow(basefrom, exp)
        exp += 1

    internum = int(internum)
    while internum > 0:
        ans += hexto[internum % baseto]
        internum /= baseto

    if len(ans) > 7:
        raise TooLongException
    return ans[::-1]


def main():
    a = STDIN.readline()
    while a:
        a = [x for x in a.split(' ') if x is not '']
        num, basefrom, baseto = a
        try:
            print convert(num, int(basefrom), int(baseto)).rjust(7)
        except TooLongException:
            print("ERROR").rjust(7)
        a = STDIN.readline()


if __name__ == '__main__':
    main()
