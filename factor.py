#!/usr/bin/python3

import sys


if len(sys.argv) != 2:
    print("Usage: factors <file>", file=sys.stderr)
    exit()

file = sys.argv[1]
with open(file) as f:
    for line in f:
        number = int(line)

        if number % 2 == 0:
            print(f"{number}={number // 2}*2")
        elif number % 3 == 0:
            print(f"{number}={number // 3}*3")
        elif number % 5 == 0:
            print(f"{number}={number // 5}*5")
        elif number % 7 == 0:
            print(f"{number}={number // 7}*7")
        else:
            div = 8
            while number % div != 0:
                div += 1
            else:
                print(f"{number}={number // div}*{div}")
