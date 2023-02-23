#!/usr/bin/env python3
import random

def main():
    target = random.randint(1, 10)
    times  = 2
    while True:
        if times < 0:
            break
        now = int(input('Guess!\n> '))
        if now == target:
            print("Success")
            break
        elif now < target:
            print("too small!")
        elif now > target:
            print("too large")

if __name__ == '__main__':
    main()
