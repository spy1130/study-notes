class Nstr(int):
    def __new__(cls,arg=0):
        if isinstance(arg,str):#函数来判断一个对象是否是一个已知的类型
            total = 0
            for each in arg:
                total += ord(each)#它以一个字符（长度为1的字符串）作为参数，返回对应的 ASCII 数值
            arg = total
        return int.__new__(cls,arg)
a = Nstr('SPYY')
b = Nstr('spy')
print(a+b)
print(a*b)