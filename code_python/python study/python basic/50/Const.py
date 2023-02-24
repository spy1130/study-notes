#该模块用于让 python 支持常量操作
class Const:
    def __setattr__(self, name, value):#当实例对象属性被修改时
        if name in self.__dict__:#检查该属性是否存在
            raise TypeError('常量名无法改变！')#当程序出现错误，python会自动引发异常，也可以通过raise显示地引发异常。一旦执行了raise语句，raise后面的语句将不能执行

        if not name.isupper():#检测字符串中所有的字母是否都为大写。
            raise TypeError('常量名必须由大写字母组成！')

        self.__dict__[name]= value

import sys
sys.modules[__name__] = Const()#这儿使用了sys.modules向系统字典中注入了一个Const对象从而实现了在执行import const时实际获取了一个Const实例的功能
#sys.modules是一个全局字典，该字典是python启动后就加载在内存中。每当程序员导入新的模块，sys.modules都将记录这些模块
#在作为独立程序运行的时候，__name__ 属性的值是 '__main__'，而作为模块导入的时候，这个值就是该模块的名字了