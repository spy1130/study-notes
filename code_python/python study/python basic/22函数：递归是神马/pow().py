def power(x,y):
    if y == 1:
        return x
    else:
        return x * power(x,y-1)
x = int(input('请输入x：'))
y = int(input('请输入y：'))
print(power(x,y))
