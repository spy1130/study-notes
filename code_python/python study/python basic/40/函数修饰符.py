class CodeA:
    def foo():
        print("调用静态方法 foo()")

        # 将 foo() 方法设置为静态方法
        foo = staticmethod(foo)

class CodeA:
    @staticmethod
    def foo():
        print("调用静态方法 foo()")

class CodeB:
    def foo(cls):
        print("调用类方法 foo()")

        # 将 foo() 方法设置为类方法
        foo = classmethod(foo)

class CodeB:
    @classmethod
    def foo(cls):
        print("调用类方法 foo()")

def something(self):
    print('spy')

@something
def f():
    print("I love FishC.com!")

# 相当于

def f():
    print("I love FishC.com!")

f = something(f)
