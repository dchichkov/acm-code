#!/usr/bin/python3

import sys
from datetime import timedelta, time, datetime

stdin = sys.stdin

def main():
    line = stdin.readline()
    numc = int(line)
    for i in range(0, numc):
        time = stdin.readline()
        time = time.split(":")
        a = timedelta(hours = int(time[0]), minutes = int(time[1]))
        b = timedelta(hours = 12, minutes = 0)
        c = datetime(year = 1, day = 1, month = 1)
        c += timedelta(seconds = (b-a).seconds)
        if c.hour == 0 and c.minute == 0:
            print("12:00")
        else:
            print(c.strftime("%I:%M"))

if __name__ == "__main__":
    main()
