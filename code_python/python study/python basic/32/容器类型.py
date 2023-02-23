def my_fun1():
    x = [5]
    def my_fun2():
        x[0] *= x[0]
        return x[0]
my_fun1()