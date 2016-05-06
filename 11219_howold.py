#!/usr/bin/python3

import sys
from datetime import datetime, timedelta
from calendar import isleap
#from dateutil.relativedelta import relativedelta

stdin = sys.stdin

def main():
    line = stdin.readline()
    num_tc = int(line)
    i = 1
    for _ in range(0, num_tc):
        stdin.readline() #get the next blank line
        current_date = stdin.readline() 
        date_of_birth = stdin.readline()

        current_date = current_date.split("/")
        date_of_birth = date_of_birth.split("/")

        current_date = datetime(int(current_date[2]), int(current_date[1]), int(current_date[0]))
        #print(current_date.date().isoformat())
        date_of_birth = datetime(int(date_of_birth[2]), int(date_of_birth[1]), int(date_of_birth[0]))
        date_of_birth_original = date_of_birth
        #print(date_of_birth.date().isoformat())
        are_equal = (current_date == date_of_birth)
        #date_of_birth -= timedelta(days=1)
        while (date_of_birth.year != current_date.year):
            if (date_of_birth.year > current_date.year): break
            if isleap(date_of_birth.year):
                current_date = current_date - timedelta(days=1)

            try:
                date_of_birth = date_of_birth.replace(year = date_of_birth.year+1)
            except ValueError:
                date_of_birth = date_of_birth.replace(year = date_of_birth.year+1, day = 28,
                                                      month = 2)
        if (isleap(current_date.year) and current_date.month >= 3):
            current_date = current_date - timedelta(days=1)
        years = (current_date - date_of_birth_original)
        print("Case #{}: ".format(i), end = "")

        #print(years, end = " ")
        years = years.days / 365
        #years = relativedelta(current_date, date_of_birth).years
        #print(years)
        if are_equal:
            print("0")
        elif years < 0:
            print("Invalid birth date")
        elif years >= 131:
            print("Check birth date")
        else:
            print(int(years))


        i += 1
                                          


if __name__ == "__main__":
    main()
