#!/usr/bin/python3

import sys

stdin = sys.stdin

def main():
    for line in stdin.readlines():
        num_pages = int(line)
        if (num_pages == 0): break
        total_pages = num_pages
        print("Printing order for {} pages:".format(line[:-1]))
        if (num_pages%4 == 0):
            num_pages = (num_pages//4)
        else:        
            num_pages = (num_pages//4+1)
        page_list = []
        for i in range(1, num_pages*4+1):
            if i > total_pages:
                page_list.append(-1)
            else:
                page_list.append(i)

        left = 0
        right = 1
        pages = []
        for i in range(0, num_pages):
            left = 1 - left
            right = 1 - right
            pagef = [-1, -1]
            pagef[left] = page_list[0]
            pagef[right] = page_list[-1]
            page_list = page_list[1:len(page_list)-1]
            left = 1 - left
            right = 1 - right
            pageb = [-1, -1]
            pageb[left] = page_list[0]
            pageb[right] = page_list[-1]
            page_list = page_list[1:len(page_list)-1]
            pages.append((pagef, pageb))

        for i, a in enumerate(pages, start = 1):
            b = a[0]
            c = a[1]
            print("Sheet {}, front: {}, {}".format(i, b[0] if b[0] != -1 else "Blank",
                                                   b[1] if b[1] != -1 else "Blank"), end = "")
            if (total_pages != 1):
                print()
            
            if c == [-1, -1]: continue
            print("Sheet {}, back : {}, {}".format(i, c[0] if c[0] != -1 else "Blank",
                                                   c[1] if c[1] != -1 else "Blank"), end = "")
            if (i != len(pages)):
                print()
            
            
            

        print()

if __name__ == "__main__":
    main()
