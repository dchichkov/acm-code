#!/usr/bin/python3

from calendar import isleap
import sys
stdin = sys.stdin

def main():
    f = 1
    for line in stdin.readlines():
        if f:
            f = not f
        else:
            print()
        year = int(line)
        huluculu = (year%15 == 0)
        bulukulu = (isleap(year) and year % 55 == 0)
        if isleap(year):
            print("This is leap year.")
        if huluculu:
            print("This is huluculu festival year.")
        if bulukulu:
            print("This is bulukulu festival year.")
        if not isleap(year) and not huluculu and not bulukulu:
            print("This is an ordinary year.")

if __name__ == "__main__":
    main()
