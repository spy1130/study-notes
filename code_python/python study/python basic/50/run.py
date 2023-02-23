import Const as c

c.NAME ='Spy'
print(c.NAME)

try:
    #尝试修改变量
    c.NAME = 'SPYY'
except TypeError as Err:
    print(Err)

try:
    #变量名需大写
    c.name = 'Spy'
except TypeError as Err:
    print(Err)
