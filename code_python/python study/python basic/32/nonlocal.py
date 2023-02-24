def my_fun1():
    x = 5
    def my_fun2():
        nonlocal x
        x *= x
        return x
    return my_fun2()
    
my_fun1()