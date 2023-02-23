#!/usr/bin/env python3

for a in range(0,4):
    for b in range(0,4):
        if a + b > 1:
            print('Red: ', a, '\tYellow: ', b, '\tBlue:', 8-a-b)
print('----------------------')
for a in range(0,4):
    for b in range(0,4):
        for c in range(2,7):
            if a + b + c == 8:
                print('Red: ', a, '\tYellow: ', b, '\tBlue:', c)
