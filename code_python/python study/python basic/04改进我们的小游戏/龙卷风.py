temp = input('请输入一个整数:')
number = int(temp)
while number:
    i = number - 1
    while i:
        print(' ', end = '')
        i=i-1
    j = number
    while j:
        print('*', end = '')
        j =j-1
    print()
    number = number - 1
