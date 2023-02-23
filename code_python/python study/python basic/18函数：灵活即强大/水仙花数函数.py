def number():
    for a in range(1,10):
        for b in range(0,10):
            for c in range(0, 10):
                num = a * 100 + b * 10 + c
                if a ** 3 + b ** 3 + c ** 3 == num:
                    print(num,end=' ')
print('所有水仙花数分别是：',end='')
number()